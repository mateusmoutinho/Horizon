//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_set_response_content_ctxt_implementation)
#define PROJECT_NAMEdeps_server_set_response_content_ctxt_implementation
void PROJECT_NAMEdeps_server_set_response_content_ctxt(void *ctxt, PROJECT_NAMEdeps_server_response *response, const unsigned char *content, long content_size) {
    CwebHttpResponse_set_content((CwebHttpResponse *)response, (unsigned char *)content, content_size);
}
#endif
