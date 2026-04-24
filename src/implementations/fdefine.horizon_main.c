//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../src/imports/imports.global.h"
//silver_chain_scope_end



int horizon_main_ctxt(void *ctxt, int argc, char** argv){
    horizondeps_printf(ctxt, "Hello, World!\n");
    return 0;
}


int horizon_main(int argc, char** argv){
    return horizon_main_ctxt(horizon_ctxt, argc, argv);
}

