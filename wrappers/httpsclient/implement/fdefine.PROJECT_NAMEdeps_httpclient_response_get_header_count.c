//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_response_get_header_count_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_response_get_header_count_ctxt_implementation
int PROJECT_NAMEdeps_httpclient_response_get_header_count_ctxt(void *ctxt, PROJECT_NAMEdeps_response *response) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    return BearHttpsResponse_get_headers_size(resp);
}
#endif

