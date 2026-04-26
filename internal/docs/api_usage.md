these documentation covers the api usage of the project 

## creating a bucket:
a Bucket can be local or remote, for a remote, you need to provide the url and the password 

### Remote Bucket
```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new( "http://localhost:8080", "password");
```

### Local Bucket
```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new( "./local_bucket");
```

## The Bucket Key Value Model
all data, are stored in a key value mechanism:

```c 
PROJECT_NAME_bucket_write_data(bucket, key_size, key, data_size, data_pointer);
```
you also can write the data, by chunk,where data_index is the index of of the data you want store
for example, you want to store the data "Hello World", you can do this in one go, or in chunks 
if its chunk: 

```c 
unsigned char *data = "Hello World";
int chunk_size = 3;
int offset = 0;
while (offset < strlen(data)) {
    PROJECT_NAME_bucket_write_data_chunk(bucket, key, key_size,offset, data + offset, chunk_size);
    offset += chunk_size;
}
```
## to delete
```c 
PROJECT_NAME_bucket_delete_data(bucket, key, key_size);
```
## to read
```c 
const char *key =  "mateus";
long key_size = strlen(key);
unsigned char data_buffer[30] = {0};
long int offset = 0;
long int size_to_read = 30;
long int size_readed = PROJECT_NAME_bucket_read_data(bucket, (unsigned char *)key, key_size,offset, size_to_read, data_buffer);
```
