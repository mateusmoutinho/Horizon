//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../src/imports/imports.fdeclare.h"
//silver_chain_scope_end

#if !defined(horizon_main_ctxt_implementation)
#define horizon_main_ctxt_implementation
int horizon_main_ctxt(void *ctxt, int argc, char** argv){
    horizondeps_printf_ctxt(ctxt, "Hello, World!\n");
    return 0;
}
#endif 

#if !defined(horizon_main_implementation)
#define horizon_main_implementation
int horizon_main(int argc, char** argv){
    return horizon_main_ctxt(horizon_ctxt, argc, argv);
}
#endif

