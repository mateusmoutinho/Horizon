//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_send_text_ctxt_implementation)
#define PROJECT_NAMEdeps_server_send_text_ctxt_implementation
PROJECT_NAMEdeps_server_response *PROJECT_NAMEdeps_server_send_text_ctxt(void *ctxt, const char *text, const char *content_type, int status_code) {
    return (PROJECT_NAMEdeps_server_response *)cweb_send_any(content_type, strlen(text), (unsigned char *)text, status_code);
}
#endif
