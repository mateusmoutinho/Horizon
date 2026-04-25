//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/std/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_malloc_ctxt_implementation)
#define horizondeps_malloc_ctxt_implementation

void * horizondeps_malloc_ctxt(void *ctxt, long size){
    return malloc(size);
}
#endif
#if !defined(horizondeps_malloc_implementation)
#define horizondeps_malloc_implementation

void * horizondeps_malloc(long size){
    return malloc(size);
}
#endif



