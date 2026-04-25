//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/httpsclient/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_httpclient_response_get_header_value_by_key_ctxt_implementation)
#define PROJECT_NAMEdeps_httpclient_response_get_header_value_by_key_ctxt_implementation
const char *PROJECT_NAMEdeps_httpclient_response_get_header_value_by_key_ctxt(void *ctxt, PROJECT_NAMEdeps_response *response, const char *key) {
    BearHttpsResponse *resp = (BearHttpsResponse *)response;
    return BearHttpsResponse_get_header_value_by_key(resp, key);
}
#endif

