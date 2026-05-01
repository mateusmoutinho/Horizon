//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_duplicate_ctxt_implementation)
#define PROJECT_NAMEdeps_json_duplicate_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_duplicate_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *item, int recurse) {
    return (PROJECT_NAMEdeps_json *)cJSON_Duplicate((const cJSON *)item, recurse);
}
#endif
