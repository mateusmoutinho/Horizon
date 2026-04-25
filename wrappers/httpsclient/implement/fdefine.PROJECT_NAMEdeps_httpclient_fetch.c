//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_fetch_ctxt_implementation)
#define horizondeps_httpclient_fetch_ctxt_implementation
horizondeps_response *horizondeps_httpclient_fetch_ctxt(void *ctxt, horizondeps_request *client) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    return (horizondeps_response *)BearHttpsRequest_fetch(request);
}
#endif

