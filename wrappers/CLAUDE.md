
# Wrappers

## Purpose
Wrappers integrate "impure" functions into the project. Each directory within `wrappers/` represents a specific library ported to the main library.

## Directory Structure
- `wrappers/<name>/`: Root for a specific wrapper.
- `wrappers/<name>/fdeclare.prototype.h`: Function prototypes (create ONLY if strictly necessary).
- `wrappers/<name>/imports/`: Wrapper imports (managed by SilverChain, DO NOT modify).
- `wrappers/<name>/implement/`: Function implementations (one `.c` file per function).
- `wrappers/<name>/includes/`: Header files (create ONLY if strictly necessary).
- `wrappers/<name>/includes/depdeclare.includes.h`: Includes the library's `.h` files.
- `wrappers/<name>/includes/depdefine.includes.c`: Includes the library's `.c` files.

## Build Process
Built automatically via SilverChain (see `builds/wrappers.lua`). 
Outputs generated:
- `release/Horizon_wrapper_<name>_full.c`: Concatenated file containing all function implementations.
- `src/deps/fdeclare.<name>.h`: Function prototypes exposed for use in the pure parts of the project.


## Ctx Pattern
Every function **must** have `void *ctxt` as its first argument. No non-ctx version is allowed.

example:
```c
#if !defined(horizondeps_malloc_ctxt_implementation)
#define horizondeps_malloc_ctxt_implementation

void * horizondeps_malloc_ctxt(void *ctxt, long size){
    return malloc(size);
}
#endif
```

## Fragment definition Pattern 
each function definition (writed in `wrappers/<name>/implement/`) must have a `#if !defined(...` block arround it, the name of the macro must follow the pattern `horizondeps_<function_name>_ctxt_implementation`.


## Fragment Prototypes Pattern
each fragment prototype (writed in `wrappers/<name>/fdeclare.prototype.h`) must have a `#if !defined(...` block arround it, the name of the macro must follow the pattern `horizondeps_<function_name>_ctxt_prototype`.


