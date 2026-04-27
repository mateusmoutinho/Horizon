//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_get_header_value_ctxt_implementation)
#define PROJECT_NAMEdeps_server_get_header_value_ctxt_implementation
const char *PROJECT_NAMEdeps_server_get_header_value_ctxt(void *ctxt, const void *request, int index) {
    CwebHttpRequest *req = (CwebHttpRequest *)request;
    if (index < 0 || index >= req->headers->size) return NULL;
    return req->headers->keys_vals[index]->value;
}
#endif
