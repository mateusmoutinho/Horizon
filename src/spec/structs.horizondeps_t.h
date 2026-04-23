
struct horizondeps_t {
    void *(*malloc)(void *ctxt, long size);
    void (*free)(void *ctxt, void *ptr);
    


    
    void *ctxt;
};