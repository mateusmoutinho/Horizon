//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_create_bool_ctxt_implementation)
#define PROJECT_NAMEdeps_json_create_bool_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_create_bool_ctxt(void *ctxt, int boolean) {
    return (PROJECT_NAMEdeps_json *)cJSON_CreateBool(boolean);
}
#endif
