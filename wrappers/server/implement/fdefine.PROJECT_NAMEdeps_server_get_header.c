//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_get_header_ctxt_implementation)
#define PROJECT_NAMEdeps_server_get_header_ctxt_implementation
const char *PROJECT_NAMEdeps_server_get_header_ctxt(void *ctxt, const void *request, const char *key) {
    return CwebHttpRequest_get_header((CwebHttpRequest *)request, key);
}
#endif
