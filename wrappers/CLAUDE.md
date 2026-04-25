
### Wrappers purpose

the wrapper its a way to add "impure" functions to the project 
each dir inside wrappers/ it's a "library" that its ported to the lib 

### Wrappers Structure

```
wrappers/
wrappers/<wrapper-name>/                                      # standard c library    
wrappers/<wrapper-name>/fdeclare.prototype.h                    # Function prototypes (don't create it unless its necessary for some reason)
wrappers/<wrapper-name>/imports/                                # imports of the wrapper (defined on SilverChain and donnt need to be touched)
wrappers/<wrapper-name>/implement/                             # Function implementations (each function its in its own file)
wrappers/<wrapper-name>/implement/<wrapper-function>.c        # Function prototypes 
wrappers/<wrapper-name>/includes/                              # Header files (don't create them unless its necessary for some reason)
wrappers/<wrapper-name>/includes/depdeclare.includes.h         # includes the .h of the lib 
wrappers/<wrapper-name>/includes/depdefine.includes.c          # includes the .c of the lib 
```

### Build of wrappers

the build its done automaticly by the silverchain and you can check it on [wrappers.lua](/builds/wrappers.lua)
it generates the following files:


- release/Horizon_wrapper_<<wrapper-name>>_full.c # a big file with all the function implementations
- src/deps/fdeclare.<<wrapper-name>>.h            # function prototypes of the wrapper that can be used by the pure part of the project 


