//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_new_ctxt_implementation)
#define horizondeps_httpclient_new_ctxt_implementation
horizondeps_request *horizondeps_httpclient_new_ctxt(void *ctxt, const char *url) {
    return (horizondeps_request *)newBearHttpsRequest(url);
}
#endif

