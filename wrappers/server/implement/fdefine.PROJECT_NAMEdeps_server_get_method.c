//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_get_method_ctxt_implementation)
#define PROJECT_NAMEdeps_server_get_method_ctxt_implementation
const char *PROJECT_NAMEdeps_server_get_method_ctxt(void *ctxt, PROJECT_NAMEdeps_server_request *request) {
    return ((CwebHttpRequest *)request)->method;
}
#endif
