//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_delete_ctxt_implementation)
#define PROJECT_NAMEdeps_json_delete_ctxt_implementation
void PROJECT_NAMEdeps_json_delete_ctxt(void *ctxt, PROJECT_NAMEdeps_json *json) {
    cJSON_Delete((cJSON *)json);
}
#endif
