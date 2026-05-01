//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_get_object_item_ctxt_implementation)
#define PROJECT_NAMEdeps_json_get_object_item_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_object_item_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *object, const char *key) {
    return (PROJECT_NAMEdeps_json *)cJSON_GetObjectItem((const cJSON *)object, key);
}
#endif
