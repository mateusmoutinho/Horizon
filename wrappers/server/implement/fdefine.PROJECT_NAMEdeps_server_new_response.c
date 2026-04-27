//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_new_response_ctxt_implementation)
#define PROJECT_NAMEdeps_server_new_response_ctxt_implementation
PROJECT_NAMEdeps_server_response *PROJECT_NAMEdeps_server_new_response_ctxt(void *ctxt) {
    return (PROJECT_NAMEdeps_server_response *)newCwebHttpResponse();
}
#endif
