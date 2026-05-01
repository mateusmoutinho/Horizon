//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_save_file_ctxt_implementation)
#define PROJECT_NAMEdeps_json_save_file_ctxt_implementation
int PROJECT_NAMEdeps_json_save_file_ctxt(void *ctxt, const PROJECT_NAMEdeps_json *json, const char *filepath) {
    char *str = cJSON_Print((const cJSON *)json);
    if (!str) return 0;
    FILE *f = fopen(filepath, "wb");
    if (!f) { cJSON_free(str); return 0; }
    fputs(str, f);
    fclose(f);
    cJSON_free(str);
    return 1;
}
#endif
