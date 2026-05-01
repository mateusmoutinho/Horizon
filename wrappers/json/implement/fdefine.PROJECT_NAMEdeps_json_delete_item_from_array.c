//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_delete_item_from_array_ctxt_implementation)
#define PROJECT_NAMEdeps_json_delete_item_from_array_ctxt_implementation
void PROJECT_NAMEdeps_json_delete_item_from_array_ctxt(void *ctxt, PROJECT_NAMEdeps_json *array, int index) {
    cJSON_DeleteItemFromArray((cJSON *)array, index);
}
#endif
