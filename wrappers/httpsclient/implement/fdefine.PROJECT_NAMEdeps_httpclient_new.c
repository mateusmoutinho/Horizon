//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_new_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_new_ctxt_implementation
PROJECT_NAMEdeps_request *PROJECT_NAMEdeps_httpclient_new_ctxt(void *ctxt, const char *url) {
    return (PROJECT_NAMEdeps_request *)newBearHttpsRequest(url);
}
#endif

