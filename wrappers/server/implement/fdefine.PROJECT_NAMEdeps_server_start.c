//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_start_ctxt_implementation)
#define PROJECT_NAMEdeps_server_start_ctxt_implementation

void *(*PROJECT_NAMEdeps_server_global_handler)(void *, void *) = NULL;
void *PROJECT_NAMEdeps_server_global_props = NULL;
int PROJECT_NAMEdeps_server_global_firmware_mode = 0;

static CwebHttpResponse *PROJECT_NAMEdeps_server_internal_handler(CwebHttpRequest *request) {
    if (PROJECT_NAMEdeps_server_global_handler) {
        void *response = PROJECT_NAMEdeps_server_global_handler((void *)request, PROJECT_NAMEdeps_server_global_props);
        return (CwebHttpResponse *)response;
    }
    return NULL;
}

int PROJECT_NAMEdeps_server_start_ctxt(void *ctxt, int port, void *(*handler)(void *, void *), void *props, int single_process) {
    PROJECT_NAMEdeps_server_global_handler = handler;
    PROJECT_NAMEdeps_server_global_props = props;
    if (PROJECT_NAMEdeps_server_global_firmware_mode) return 0;
    CwebServer server = newCwebSever(port, PROJECT_NAMEdeps_server_internal_handler);
    server.use_static = false;
    #if !defined(_WIN32) && !defined(_WIN64)
        server.single_process = single_process;
    #endif
    CwebServer_start(&server);
    return 0;
}
#endif
