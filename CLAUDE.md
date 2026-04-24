## project overwiew
Horizon horizontal scale database based on http requisitions

### Build Requirements
Requires [darwin](https://github.com/OUIsolutions/Darwin) v0.20.0+. Check with:
```bash
darwin --version
```
Install darwin:
```bash
curl -L https://github.com/OUIsolutions/Darwin/releases/download/0.20.0/darwin.c -o darwin.c && gcc darwin.c -o darwin.out && sudo mv darwin.out /usr/local/bin/darwin && rm darwin.c
```

### Build
List available recipes (located in `builds`):
```bash
darwin list
```
Build all:
```bash
darwin run_blueprint --target all
```
Build a specific recipe:
```bash
darwin run_blueprint --target <recipe_name>
```
### Build Process
the build process start by interpreting the [darwinconf.lua](darwinconf.lua)
After reading the darwinconf it loads all the blueprints located at [builds](builds/) dir 

