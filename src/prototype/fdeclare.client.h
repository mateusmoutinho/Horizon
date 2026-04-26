//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.global.h"
//silver_chain_scope_end


PROJECT_NAMEbox * PROJECT_NAME_new_local_box_ctx(void *ctx,const char *path);

PROJECT_NAMEbox * PROJECT_NAME_new_remote_box_ctx(void *ctx,const char *url,const char *password);

void PROJECT_NAMEbox_write_data_block_ctx(
    void *ctx,
    PROJECT_NAMEbox *box,
    const unsigned char *key,
    long key_size,
    const unsigned char *data, long data_size
);

long PROJECT_NAMEbox_get_data_size_ctx(
    void *ctx,
    PROJECT_NAMEbox *box,
    const unsigned char *key,
    long key_size
);


long  PROJECT_NAMEbox_read_data_block_ctx(
    void *ctx,
    PROJECT_NAMEbox *box,
    const unsigned char *key,
    long key_size,
    unsigned char **data_buffer,
    long *data_buffer_size
);

//---------------------------- ITERATORS ------------------------
// 
void PROJECT_NAMEbox_get_key_by_index_ctx(
    PROJECT_NAMEbox *box,
    long key_index,
    unsigned char **buffer_key,
    long *buffer_key_size,
    long max_key_size
);




