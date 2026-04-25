//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_set_header_ctxt_implementation)
#define horizondeps_httpclient_set_header_ctxt_implementation
void horizondeps_httpclient_set_header_ctxt(void *ctxt, horizondeps_request *client, const char *key, const char *value) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    BearHttpsRequest_add_header(request, key, value);
}
#endif

