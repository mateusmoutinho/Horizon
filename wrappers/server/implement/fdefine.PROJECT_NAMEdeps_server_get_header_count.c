//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_get_header_count_ctxt_implementation)
#define PROJECT_NAMEdeps_server_get_header_count_ctxt_implementation
int PROJECT_NAMEdeps_server_get_header_count_ctxt(void *ctxt, const void *request) {
    return ((CwebHttpRequest *)request)->headers->size;
}
#endif
