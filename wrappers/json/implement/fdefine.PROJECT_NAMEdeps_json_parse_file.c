//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../../../wrappers/json/imports/imports.depdeclare.h"
//silver_chain_scope_end

#if !defined(PROJECT_NAMEdeps_json_parse_file_ctxt_implementation)
#define PROJECT_NAMEdeps_json_parse_file_ctxt_implementation
PROJECT_NAMEdeps_json *PROJECT_NAMEdeps_json_parse_file_ctxt(void *ctxt, const char *filepath) {
    FILE *f = fopen(filepath, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = (char *)malloc(size + 1);
    if (!buf) { fclose(f); return NULL; }
    fread(buf, 1, size, f);
    fclose(f);
    buf[size] = '\0';
    PROJECT_NAMEdeps_json *result = (PROJECT_NAMEdeps_json *)cJSON_Parse(buf);
    free(buf);
    return result;
}
#endif
