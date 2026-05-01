//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_get_object_size_ctxt_implementation)
#define PROJECT_NAMEdeps_json_get_object_size_ctxt_implementation
int PROJECT_NAMEdeps_json_get_object_size_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *object) {
    int count = 0;
    const cJSON *child = ((const cJSON *)object)->child;
    while (child) { count++; child = child->next; }
    return count;
}
#endif
