//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_send_any_ctxt_implementation)
#define PROJECT_NAMEdeps_server_send_any_ctxt_implementation
const void *PROJECT_NAMEdeps_server_send_any_ctxt(void *ctxt, const unsigned char *content, long content_size, const char *content_type, int status_code) {
    return (void *)cweb_send_any(content_type, content_size, (unsigned char *)content, status_code);
}
#endif
