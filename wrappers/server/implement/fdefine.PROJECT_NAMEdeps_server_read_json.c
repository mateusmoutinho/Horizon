//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_read_json_ctxt_implementation)
#define PROJECT_NAMEdeps_server_read_json_ctxt_implementation
const void *PROJECT_NAMEdeps_server_read_json_ctxt(void *ctxt, PROJECT_NAMEdeps_server_request *request, long size) {
    return (const void *)CWebHttpRequest_read_cJSON((CwebHttpRequest *)request, size);
}
#endif
