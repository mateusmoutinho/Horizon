//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_delete_item_from_object_ctxt_implementation)
#define PROJECT_NAMEdeps_json_delete_item_from_object_ctxt_implementation
int PROJECT_NAMEdeps_json_delete_item_from_object_ctxt(void *ctxt, PROJECT_NAMEdeps_json *object, const char *key) {
    if (!cJSON_HasObjectItem((cJSON *)object, key)) return 0;
    cJSON_DeleteItemFromObject((cJSON *)object, key);
    return 1;
}
#endif
