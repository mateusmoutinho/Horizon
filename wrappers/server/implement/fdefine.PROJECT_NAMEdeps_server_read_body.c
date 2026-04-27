//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_read_body_ctxt_implementation)
#define PROJECT_NAMEdeps_server_read_body_ctxt_implementation
const unsigned char *PROJECT_NAMEdeps_server_read_body_ctxt(void *ctxt, const void *request, long size, long *read_size) {
    CwebHttpRequest *req = (CwebHttpRequest *)request;
    unsigned char *body = CwebHttpRequest_read_content(req, size);
    *read_size = req->content_length;
    return (const unsigned char *)body;
}
#endif
