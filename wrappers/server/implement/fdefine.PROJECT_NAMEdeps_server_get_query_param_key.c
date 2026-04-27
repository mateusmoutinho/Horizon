//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_get_query_param_key_ctxt_implementation)
#define PROJECT_NAMEdeps_server_get_query_param_key_ctxt_implementation
const char *PROJECT_NAMEdeps_server_get_query_param_key_ctxt(void *ctxt, PROJECT_NAMEdeps_server_request *request, int index) {
    CwebHttpRequest *req = (CwebHttpRequest *)request;
    if (index < 0 || index >= req->params->size) return NULL;
    return req->params->keys_vals[index]->key;
}
#endif
