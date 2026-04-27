//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/server/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_server_send_json_ctxt_implementation)
#define PROJECT_NAMEdeps_server_send_json_ctxt_implementation
const void *PROJECT_NAMEdeps_server_send_json_ctxt(void *ctxt, const void *json, int status_code) {
    return cweb_send_cJSON((cJSON *)json, status_code);
}
#endif
