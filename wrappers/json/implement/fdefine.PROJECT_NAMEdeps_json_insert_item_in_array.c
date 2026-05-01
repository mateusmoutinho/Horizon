//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_insert_item_in_array_ctxt_implementation)
#define PROJECT_NAMEdeps_json_insert_item_in_array_ctxt_implementation
int PROJECT_NAMEdeps_json_insert_item_in_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, int index, PROJECT_NAMEdeps_json *item) {
    return cJSON_InsertItemInArray((cJSON *)array, index, (cJSON *)item);
}
#endif
