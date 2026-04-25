//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_set_header_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_set_header_ctxt_implementation
void PROJECT_NAMEdeps_httpclient_set_header_ctxt(void *ctxt, PROJECT_NAMEdeps_request *client, const char *key, const char *value) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    BearHttpsRequest_add_header(request, key, value);
}
#endif

