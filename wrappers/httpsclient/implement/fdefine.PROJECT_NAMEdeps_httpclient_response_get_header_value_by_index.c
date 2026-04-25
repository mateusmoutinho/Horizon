//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_response_get_header_value_by_index_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_response_get_header_value_by_index_ctxt_implementation
const char *PROJECT_NAMEdeps_httpclient_response_get_header_value_by_index_ctxt(void *ctxt, PROJECT_NAMEdeps_response *response, int index) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    return BearHttpsResponse_get_header_value_by_index(resp, index);
}
#endif

