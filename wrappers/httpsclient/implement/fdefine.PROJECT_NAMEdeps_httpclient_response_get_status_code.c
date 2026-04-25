//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_response_get_status_code_ctxt_implementation)
#define horizondeps_httpclient_response_get_status_code_ctxt_implementation
int horizondeps_httpclient_response_get_status_code_ctxt(void *ctxt, horizondeps_response *response) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    return BearHttpsResponse_get_status_code(resp);
}
#endif

