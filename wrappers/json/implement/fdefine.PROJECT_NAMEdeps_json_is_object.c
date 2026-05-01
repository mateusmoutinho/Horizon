//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_is_object_ctxt_implementation)
#define PROJECT_NAMEdeps_json_is_object_ctxt_implementation
int PROJECT_NAMEdeps_json_is_object_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item) {
    return cJSON_IsObject((const cJSON *)item);
}
#endif
