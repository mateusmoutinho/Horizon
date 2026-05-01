//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_get_array_item_ctxt_implementation)
#define PROJECT_NAMEdeps_json_get_array_item_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_get_array_item_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *array, int index) {
    return (PROJECT_NAMEdeps_json *)cJSON_GetArrayItem((const cJSON *)array, index);
}
#endif
