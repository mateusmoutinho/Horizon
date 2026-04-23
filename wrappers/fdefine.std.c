//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "imports/imports.fdeclare.h"




//silver_chain_scope_end

void * horizondeps_malloc(void *ctxt, long size){
    return malloc(size);
}
void horizondeps_free(void *ctxt, void *ptr){
    free(ptr);
}
int horizondeps_printf(void *ctxt, const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    int ret = vprintf(fmt, args);
    va_end(args);
    return ret;
}


