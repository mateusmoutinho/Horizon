//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_set_response_header_ctxt_implementation)
#define PROJECT_NAMEdeps_server_set_response_header_ctxt_implementation
void PROJECT_NAMEdeps_server_set_response_header_ctxt(void *ctxt, PROJECT_NAMEdeps_server_response *response, const char *key, const char *value) {
    CwebHttpResponse_add_header((CwebHttpResponse *)response, key, value);
}
#endif
