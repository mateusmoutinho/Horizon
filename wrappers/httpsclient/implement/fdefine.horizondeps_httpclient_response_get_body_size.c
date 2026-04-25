//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_response_get_body_size_ctxt_implementation)
#define horizondeps_httpclient_response_get_body_size_ctxt_implementation
long horizondeps_httpclient_response_get_body_size_ctxt(void *ctxt, horizondeps_response *response) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    return (long)BearHttpsResponse_get_body_size(resp);
}
#endif

