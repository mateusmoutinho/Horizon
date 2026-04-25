//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/std/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_free_ctxt_implementation)
#define PROJECT_NAMEdeps_free_ctxt_implementation
void PROJECT_NAMEdeps_free_ctxt(void *ctxt, void *ptr){
    free(ptr);
}
#endif
