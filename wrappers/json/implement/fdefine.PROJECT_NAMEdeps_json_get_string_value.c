//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_get_string_value_ctxt_implementation)
#define PROJECT_NAMEdeps_json_get_string_value_ctxt_implementation
char *PROJECT_NAMEdeps_json_get_string_value_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item) {
    return cJSON_GetStringValue((const cJSON *)item);
}
#endif
