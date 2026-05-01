//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_free_string_ctxt_implementation)
#define PROJECT_NAMEdeps_json_free_string_ctxt_implementation
void PROJECT_NAMEdeps_json_free_string_ctxt(void *ctxt, char *str) {
    cJSON_free(str);
}
#endif
