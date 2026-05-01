//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_add_null_to_object_ctxt_implementation)
#define PROJECT_NAMEdeps_json_add_null_to_object_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_add_null_to_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key) {
    return (PROJECT_NAMEdeps_json *)cJSON_AddNullToObject((cJSON *)object, key);
}
#endif
