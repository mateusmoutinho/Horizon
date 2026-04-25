//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../src/imports/imports.fdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAME_main_ctxt_implementation)
#define PROJECT_NAME_main_ctxt_implementation
int PROJECT_NAME_main_ctxt(void *ctxt, int argc, char** argv){
    PROJECT_NAMEdeps_printf_ctxt(ctxt, "Hello, World!\n");
    return 0;
}
#endif 

#if !defined(PROJECT_NAME_main_implementation)
#define PROJECT_NAME_main_implementation
int PROJECT_NAME_main(int argc, char** argv){
    return PROJECT_NAME_main_ctxt(PROJECT_NAME_ctxt, argc, argv);
}
#endif

