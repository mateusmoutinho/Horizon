//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_compare_ctxt_implementation)
#define PROJECT_NAMEdeps_json_compare_ctxt_implementation
int PROJECT_NAMEdeps_json_compare_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *a, const PROJECT_NAMEdeps_json *b, int case_sensitive) {
    return cJSON_Compare((const cJSON *)a, (const cJSON *)b, case_sensitive);
}
#endif
