
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>



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


