//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_set_max_redirections_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_set_max_redirections_ctxt_implementation
void PROJECT_NAMEdeps_httpclient_set_max_redirections_ctxt(void *ctxt, PROJECT_NAMEdeps_request *client, int max_redirections) {
    BearHttpsRequest *request = (BearHttpsRequest *)client;
    request->max_redirections = max_redirections;
}
#endif

