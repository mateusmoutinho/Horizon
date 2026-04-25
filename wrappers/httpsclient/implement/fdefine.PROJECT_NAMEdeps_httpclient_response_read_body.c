//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(horizondeps_httpclient_response_read_body_ctxt_implementation)
#define horizondeps_httpclient_response_read_body_ctxt_implementation
const unsigned char *horizondeps_httpclient_response_read_body_ctxt(void *ctxt, horizondeps_response *response, long *size) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    const unsigned char *body = BearHttpsResponse_read_body(resp);
    *size = BearHttpsResponse_get_body_size(resp);
    return body;
}
#endif

