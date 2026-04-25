//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_set_body_ctxt_implementation)
#define horizondeps_httpclient_set_body_ctxt_implementation
void horizondeps_httpclient_set_body_ctxt(void *ctxt, horizondeps_request *client, unsigned char *content, long size) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    BearHttpsRequest_send_any(request, content, size);
}
#endif

