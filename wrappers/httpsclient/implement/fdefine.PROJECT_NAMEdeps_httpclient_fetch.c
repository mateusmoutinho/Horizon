//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_fetch_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_fetch_ctxt_implementation
PROJECT_NAMEdeps_response *PROJECT_NAMEdeps_httpclient_fetch_ctxt(void *ctxt, PROJECT_NAMEdeps_request *client) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    return (PROJECT_NAMEdeps_response *)BearHttpsRequest_fetch(request);
}
#endif

