//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_set_max_redirections_ctxt_implementation)
#define horizondeps_httpclient_set_max_redirections_ctxt_implementation
void horizondeps_httpclient_set_max_redirections_ctxt(void *ctxt, horizondeps_request *client, int max_redirections) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    request->max_redirections = max_redirections;
}
#endif

