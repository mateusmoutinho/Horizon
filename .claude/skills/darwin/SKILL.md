---
name: darwin-build
description: Author, extend, and debug Darwin build blueprints — Lua-based build recipes for C/C++ projects that produce amalgamations, cross-platform binaries, and OS packages (.deb, .rpm, Windows .exe). Use whenever the user works with a `darwinconf.lua`, files under a `builds/` directory, recipes registered via `darwin.add_recipe`, containerized builds driven by `darwin.ship`, amalgamation generation via `darwin.silverchain`, or asks how to add a new build target, wire up dependencies between recipes, or invoke `darwin run_blueprint`. Also use when the user mentions Darwin, OUIsolutions' build tool, or any `.lua` file that calls the `darwin.*` API.
---

# Darwin Build System

Darwin is a Lua-driven build orchestrator from OUIsolutions. It works by reading a top-level `darwinconf.lua`, loading every `.lua` file under `builds/` as a **blueprint**, and executing **recipes** that are registered with `darwin.add_recipe`. Each recipe declares its inputs, outputs, and dependencies, so Darwin can resolve order and skip work when outputs are up to date — similar in spirit to `make`, but the rules are written in Lua and can drive Docker/Podman containers directly.

This skill covers how to author blueprints and use the `darwin.*` API. It does **not** cover any specific project's global variables or domain conventions — those live in the project's own `darwinconf.lua`.

## Project layout

A Darwin-managed project typically looks like this:

```
project/
├── darwinconf.lua        # entry point: sets globals, loads blueprints
└── builds/               # one .lua file per recipe (convention, not required)
    ├── amalgamation_build.lua
    ├── alpine_static_build.lua
    ├── debian_static_build.lua
    └── ...
```

`darwinconf.lua` runs first. It is the right place to define project-wide constants (project name, version, maintainer, container provider, etc.) and to `dofile` or otherwise load the blueprints under `builds/`. Every blueprint file registers one or more recipes via `darwin.add_recipe`.

## The CLI

Users invoke Darwin from the project root:

```bash
darwin --version                          # check install (need v0.20.0+)
darwin list                               # list all registered recipes
darwin run_blueprint --target all         # build every recipe
darwin run_blueprint --target <recipe>    # build one recipe (and its requires)
```

`--target all` asks Darwin to run every registered recipe, respecting `requires`. `--target <name>` runs that recipe plus anything it transitively requires.

If a user reports "darwin: command not found" or a version mismatch, the canonical install pattern is:

```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/<version>/darwin.c -o darwin.c \
  && gcc darwin.c -o darwin.out \
  && sudo mv darwin.out /usr/local/bin/darwin \
  && rm darwin.c
```

## Authoring a recipe

Every recipe is a Lua function plus a registration call. The minimal shape:

```lua
function my_recipe()
    -- do the work here
    os.execute("mkdir -p release")
    os.execute("gcc src/main.c -o release/app")
end

darwin.add_recipe({
    name        = "my_recipe",
    description = "short human-readable summary shown by `darwin list`",
    requires    = { "other_recipe" },                 -- optional: dependencies
    inputs      = { "src/main.c" },                   -- files/dirs that trigger rebuild
    outs        = { "release/app" },                  -- files Darwin expects to exist after
    callback    = my_recipe,                          -- the function above
})
```

### Field-by-field

- **`name`** (string, required) — unique identifier, used with `--target`.
- **`description`** (string) — shown by `darwin list`. Keep it one line.
- **`requires`** (table of strings) — names of recipes that must succeed first. Darwin runs them in order and shares no implicit state between them beyond the filesystem.
- **`inputs`** (table of strings) — paths Darwin watches to decide whether the recipe is stale. Can be files *or* directories; directories are treated recursively.
- **`outs`** (table of strings) — paths the recipe promises to produce. Darwin uses these for up-to-date checks and for downstream recipes to consume.
- **`callback`** (function, required) — the body of the recipe. Any Lua is legal; prefer the `darwin.*` helpers below over hand-rolling shell.

### Rules of thumb

- One recipe = one artifact (or one tightly coupled group). Don't bundle unrelated steps.
- Declare `requires` whenever a recipe reads a file produced by another recipe. Missing `requires` causes non-deterministic failures when users run a single target.
- Always list everything the recipe consumes in `inputs` — including source directories like `csrc/`, `luasrc/`, `assets/`. Missing inputs = stale caches.
- Always list every file the recipe produces in `outs`. Missing outs = Darwin thinks the work wasn't done and reruns it every invocation.
- Create output directories explicitly (`os.execute("mkdir -p release")` or `darwin.dtw.write_file` which auto-creates parents). Don't assume they exist.

## The `darwin.*` API

Everything below is available inside a recipe callback (and inside `darwinconf.lua`).

### `darwin.add_recipe(spec)`

Registers a recipe. Called once per recipe, usually at the bottom of a blueprint file. See shape above.

### `darwin.create_project(name) → project`

Creates an amalgamation project object. Used to bundle Lua + C sources into a single-file C amalgamation — the core of the "vibecoding" / Silverchain workflow. Returns a project handle with these methods:

- `project.add_lua_code(string)` — append raw Lua source.
- `project.add_lua_file(path)` — append the contents of a Lua file.
- `project.add_c_file(path, include_in_amalgamation?)` — add a C file; pass `true` to embed it into the generated amalgamation.
- `project.embed_global(name, value)` — embed a string as a Lua global accessible at runtime (good for loading text assets like help files).
- `project.load_lib_from_c(symbol, lua_module_name)` — expose a C-defined Lua module under `lua_module_name`, backed by the C symbol `symbol`.
- `project.c_external_code` — array of raw C strings prepended before amalgamation. Useful for `#define` flags.
- `project.generate_c_file({ output = path, include_lua_cembed = bool })` — write the final amalgamated C file.

Typical pattern (wrapping Lua library code inside a named closure so it becomes a table you assign to a global):

```lua
project.add_lua_code("mylib = function()\n")
project.add_lua_file("dependencies/mylib.lua")
project.add_lua_code("end\n")
project.add_lua_code("mylib = mylib()\n")
```

This gives you `mylib.*` in the runtime without polluting the global namespace with every internal symbol the library defines.

### `darwin.silverchain.generate(spec)`

Scans a C source tree and emits the combined headers/definitions that the amalgamation relies on. Inputs:

- `src` — the C source directory.
- `project_short_cut` — a short project prefix used in generated symbol names.
- `tags` — ordered list of `//weave:`-style tags to collect and emit. Common tags, in the order they should appear in output: `dep_declare`, `macros`, `types`, `consts`, `fdeclare`, `globals`, `fdefine`.

Run this **before** `darwin.create_project(...).generate_c_file(...)` — the generator writes files that the amalgamation includes.

### `darwin.ship` — containerized builds

`darwin.ship` runs commands inside Docker or Podman containers. This is how Darwin produces reproducible static binaries, cross-compiles for Windows, and builds distro packages.

```lua
local image = darwin.ship.create_machine("alpine:latest")
image.provider = CONTANIZER          -- "docker" or "podman"; typically a project-wide global
image.add_comptime_command("apk update")
image.add_comptime_command("apk add --no-cache gcc musl-dev")

image.start({
    volumes = {
        { "./release", "/release" },     -- { host_path, container_path }
    },
    command = "gcc --static /release/amalgamation.c -o /release/app",
})
```

Key points:

- `create_machine(image)` — any image pullable by the provider (`alpine:latest`, `debian:latest`, `fedora:latest`, `ubuntu:22.04`, ...).
- `image.provider` — choose the runtime. Leave this configurable via a global so users on podman-only systems can switch without editing every blueprint.
- `add_comptime_command(cmd)` — runs during image preparation (build-time layer). Install compilers, fetch tools, etc. These are cached.
- `start({ volumes, command })` — mounts volumes and runs `command`. Volumes are `{host, container}` pairs. `command` runs in `/bin/sh -c`, so you can chain with `&&`.

**Cross-compilation** is just a matter of installing the right toolchain via `add_comptime_command` and invoking it. For 32-bit Windows from a Debian container: `apt-get -y install mingw-w64` and then `i686-w64-mingw32-gcc`. Don't forget platform-specific link flags (e.g. `-lws2_32` for Winsock).

**Packaging** (`.deb`, `.rpm`) follows the same pattern: stage files in a cache directory on the host, mount it into a container that has the packaging tools, and run `dpkg-deb --build` or `rpmbuild -ba`.

### `darwin.dtw` — filesystem helpers

`dtw` is a cross-platform file/path toolkit. Prefer it over raw shell for portability.

- `darwin.dtw.load_file(path) → string` — read a file into a Lua string.
- `darwin.dtw.write_file(path, content)` — write a string to a file, creating parent directories as needed.
- `darwin.dtw.copy_any_overwriting(src, dst)` — copy a file or directory, overwriting the destination. Parent dirs are created.
- `darwin.dtw.list_files_recursively(dir, include_subdirs?) → table` — list files under `dir`. Pass `true` to recurse.
- `darwin.dtw.ends_with(str, suffix) → bool` — string suffix check; handy for filtering output lists (e.g. "only the `.rpm`").

Typical staging pattern (mirrors the `.deb`/`.rpm` recipes):

```lua
darwin.dtw.write_file(".cache/debian/project/DEBIAN/control", control_text)
darwin.dtw.copy_any_overwriting(
    "release/app.out",
    ".cache/debian/project/usr/local/bin/app"
)
```

## Patterns and idioms

### Wiring a multi-stage pipeline

Let the `requires` graph do the work. A common shape for a C project:

```
amalgamation  →  alpine_static_build  →  debian_static_build
                                      →  rpm_static_build
              →  windowsi32_build
              →  local_linux_build
```

Each downstream recipe lists its immediate predecessor in `requires`. Users running `darwin run_blueprint --target rpm_static_build` get `amalgamation` → `alpine_static_build` → `rpm_static_build` for free.

### Parameterizing with globals

Blueprints read globals set in `darwinconf.lua` (project name, version, maintainer, container provider, language flavor, etc.). Keep blueprints generic — they should reference globals, not hardcode values. When authoring a new blueprint, if you need a new knob, add it to `darwinconf.lua` rather than baking a literal into the recipe.

### String templating for spec files

`.deb` control files, `.rpm` spec files, systemd units, and similar artifacts are just text. Write them as Lua long-strings with `PLACEHOLDER` tokens and substitute with `string.gsub`:

```lua
local spec = [[
Name:    PROJECT_NAME
Version: VERSION
...
]]
spec = string.gsub(spec, "PROJECT_NAME", PROJECT_NAME)
spec = string.gsub(spec, "VERSION", VERSION)
darwin.dtw.write_file(".cache/rpm/SPECS/project.spec", spec)
```

Keep the template visually aligned with the real file format; it makes review much easier.

### Picking the compiler dynamically

For projects that can build as either C or C++, branch on a global rather than duplicating the recipe:

```lua
local compiler = "gcc"
if LANGUAGE == "cpp" then
    compiler = "g++"
end
```

The same trick works for MinGW toolchains (`i686-w64-mingw32-gcc` vs `-g++`) and clang variants.

### Recovering artifacts from container output dirs

Containers often write to a directory that contains more than the one file you want (`RPMS/x86_64/...`, `dist/*.whl`, etc.). Walk the output with `list_files_recursively` and filter with `ends_with`:

```lua
local files = darwin.dtw.list_files_recursively(".cache/rpm/RPMS", true)
for _, file in ipairs(files) do
    if darwin.dtw.ends_with(file, ".rpm") then
        darwin.dtw.copy_any_overwriting(file, "release/app.rpm")
        break
    end
end
```

## Debugging blueprints

- **Recipe doesn't show in `darwin list`** — the blueprint file isn't being loaded (check `darwinconf.lua`), or `darwin.add_recipe` wasn't called, or the file has a Lua syntax error that silently aborts loading. Run `lua builds/yourfile.lua` directly to surface syntax errors.
- **Recipe reruns every time even when nothing changed** — `outs` is missing an entry, or an out is written to a different path than declared.
- **Recipe silently uses a stale input** — `inputs` is missing a directory that was edited. Add it.
- **"file not found" inside a container** — the volume mount is wrong. Remember `start.volumes` takes `{host, container}` pairs and the `command` sees only the container paths.
- **Container command fails with exit code but no clear error** — `command` runs in `sh -c`, so a failing `&&`-chained step aborts silently from Darwin's perspective. Split the command, or echo checkpoints.
- **Cross-compiled binary won't link** — missing platform libraries. Windows needs `-lws2_32` for sockets; static musl builds may need `-static-libgcc -static-libstdc++` for C++.

## Checklist before committing a new blueprint

1. `name`, `description`, `callback` all set.
2. Every file read in the callback is listed in `inputs` (or produced by a recipe in `requires`).
3. Every file written by the callback is listed in `outs`.
4. Output parent directories are created before writing.
5. Container volumes use absolute-inside, relative-outside paths that actually exist.
6. No project-specific literals that should live in `darwinconf.lua` globals.
7. `darwin list` shows the recipe and `darwin run_blueprint --target <name>` completes end-to-end from a clean checkout.