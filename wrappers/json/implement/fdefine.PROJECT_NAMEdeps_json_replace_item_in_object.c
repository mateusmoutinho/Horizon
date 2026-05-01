//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_replace_item_in_object_ctxt_implementation)
#define PROJECT_NAMEdeps_json_replace_item_in_object_ctxt_implementation
int PROJECT_NAMEdeps_json_replace_item_in_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key, PROJECT_NAMEdeps_json *newitem) {
    return cJSON_ReplaceItemInObject((cJSON *)object, key, (cJSON *)newitem);
}
#endif
