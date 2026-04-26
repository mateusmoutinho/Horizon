# API Usage

This document provides a comprehensive reference for the PROJECT_NAME client API. It covers box initialization, key-value data operations, chunked I/O, and key enumeration.

---

## Table of Contents

1. [box Initialization](#box-initialization)
2. [Writing Data](#writing-data)
3. [Chunked Write](#chunked-write)
4. [Deleting Data](#deleting-data)
5. [Reading Data](#reading-data)
6. [Querying Data Size](#querying-data-size)
7. [Full Data Retrieval](#full-data-retrieval)
8. [Iterating Over Keys](#iterating-over-keys)

---

## box Initialization

A `PROJECT_NAME_box` represents a connection handle to a data store. It can target either a **remote** server (via HTTP) or a **local** directory on disk.

### Remote box

Connects to a running PROJECT_NAME server instance. Requires the server URL and an authentication password.

```c
PROJECT_NAME_box *box = PROJECT_NAME_box_new("http://localhost:8080", "password");
```

| Parameter  | Type           | Description                                      |
|------------|----------------|--------------------------------------------------|
| `url`      | `const char *` | Base URL of the remote PROJECT_NAME server.      |
| `password` | `const char *` | Authentication credential for the server.        |

### Local box

Opens (or creates) a box backed by a local directory. No network connection is required.

```c
PROJECT_NAME_box *box = PROJECT_NAME_box_new("./local_box");
```

| Parameter | Type           | Description                                       |
|-----------|----------------|----------------------------------------------------|
| `path`    | `const char *` | Filesystem path to the local box directory.     |

---

## Writing Data

Stores a value under a given key. Both the key and data are treated as raw byte buffers, allowing storage of arbitrary binary content.

```c
PROJECT_NAME_box_write_data(box,key, key_size,data, data_size);
```

| Parameter      | Type                         | Description                                |
|----------------|------------------------------|--------------------------------------------|
| `box`       | `PROJECT_NAME_box *`      | Target box handle.                      |
| `key`          | `const unsigned  char *`     | Pointer to the key buffer.                 |
| `key_size`     | `long`                       | Length of the key buffer in bytes.         |
| `data`         | `const unsigned  char *`     | Pointer to the data to be stored.          |
| `data_size`    | `long`                       | Length of the data buffer in bytes.        |

---

## Chunked Write

For large payloads, data can be written incrementally using offset-based chunks. Each call appends or overwrites a segment of the value at the specified byte offset.

```c

unsigned char *key = "my_key";
long key_size = strlen(key);
unsigned char *data = "Hello World";

long total_size = strlen(data);
long CHUNK_SIZE = 3;

for (long offset = 0; offset < total_size; offset += CHUNK_SIZE) {
    PROJECT_NAME_box_write_data_chunk(box, key, key_size, offset, data + offset, CHUNK_SIZE);
}
```

| Parameter    | Type               | Description                                     |
|--------------|--------------------|-------------------------------------------------|
| `box`     | `PROJECT_NAME_box *` | Target box handle.                      |
| `key`        | `unsigned char *`  | Pointer to the key buffer.                      |
| `key_size`   | `long`             | Length of the key buffer in bytes.               |
| `offset`     | `int`              | Byte offset within the value to begin writing.   |
| `data`       | `unsigned char *`  | Pointer to the chunk data.                       |
| `chunk_size` | `int`              | Number of bytes to write in this chunk.          |

---

## Deleting Data

Removes a key and its associated value from the box.

```c
PROJECT_NAME_box_delete_data(box, key, key_size);
```

| Parameter  | Type               | Description                                |
|------------|--------------------|--------------------------------------------|
| `box`   | `PROJECT_NAME_box *` | Target box handle.               |
| `key`      | `unsigned char *`  | Pointer to the key buffer.                |
| `key_size` | `long`             | Length of the key buffer in bytes.         |

---

## Reading Data

Reads a portion of the stored value into a caller-provided buffer. Supports offset-based partial reads for efficient streaming of large values.

```c
const char *key = "my_key";
long key_size = strlen(key);

unsigned char buffer[256] = {0};
long offset = 0;
long size_to_read = sizeof(buffer);

long bytes_read = PROJECT_NAME_box_read_data(
    box,
    (unsigned char *)key, key_size,
    offset, size_to_read,
    buffer
);
```

| Parameter      | Type               | Description                                          |
|----------------|------------------  |------------------------------------------------------|
| `box`       | `PROJECT_NAME_box *` | Target box handle.                           |
| `key`          | `unsigned char *`  | Pointer to the key buffer.                           |
| `key_size`     | `long`             | Length of the key buffer in bytes.                    |
| `offset`       | `long`             | Byte offset to start reading from.                   |
| `size_to_read` | `long`             | Maximum number of bytes to read.                     |
| `buffer`       | `unsigned char *`  | Destination buffer for the read data.                |

**Returns:** `long` — The number of bytes actually read into the buffer.

---

## Querying Data Size

Returns the total size (in bytes) of the value associated with a key. Useful for allocating appropriately sized buffers before reading.

```c
const char *key = "my_key";
long key_size = strlen(key);

long data_size = PROJECT_NAME_box_get_data_size(
    box,
    (unsigned char *)key, key_size
);
```

| Parameter  | Type                     | Description                                |
|------------|--------------------------|--------------------------------------------|
| `box`   | `PROJECT_NAME_box *`  | Target box handle.               |
| `key`      | `const unsigned char *`  | Pointer to the key buffer.                |
| `key_size` | `long`                   | Length of the key buffer in bytes.         |

**Returns:** `long` — Size of the stored value in bytes.

---

## Full Data Retrieval

Combines size querying and reading to retrieve the complete value for a key. The caller is responsible for freeing the allocated buffer.

```c
const char *key = "my_key";
long key_size = strlen(key);

// Query the total size of the stored value
long data_size = PROJECT_NAME_box_get_data_size(
    box,
    (unsigned char *)key, key_size
);

// Allocate a buffer and read the entire value
unsigned char *data = malloc(data_size);
PROJECT_NAME_box_read_data(
    box,
    (unsigned char *)key, key_size,
    0, data_size,
    data
);

// ... use data ...

free(data);
```

---

## Iterating Over Keys

Enumerates all keys stored in a box. Keys are accessed sequentially by index. The iteration terminates when `PROJECT_NAME_box_get_key_size_by_index` returns `-1`, indicating no more keys are available.

```c
int key_index = 0;

while (1) {
    long key_size = PROJECT_NAME_box_get_key_size_by_index(box, key_index);
    if (key_size == -1) {
        break; // No more keys
    }

    unsigned char key[key_size];
    PROJECT_NAME_box_get_key_by_index(box, key_index, key);

    printf("Key[%d]: %.*s\n", key_index, (int)key_size, key);
    key_index++;
}
```

| Function                                        | Description                                              |
|-------------------------------------------------|----------------------------------------------------------|
| `PROJECT_NAME_box_get_key_size_by_index`     | Returns the byte length of the key at the given index, or `-1` if the index is out of range. |
| `PROJECT_NAME_box_get_key_by_index`          | Copies the key at the given index into the provided buffer. |


## Error handling 
what ever action you do, can result to a error, that can be checked: 

```c 
// call any function from above, for example: 
PROJECT_NAME_box_write_data(box,key, key_sizeq,data, data_size);
if(PROJECT_NAME_box_is_error(box)) {
    const char *msg = PROJECT_NAME_box_get_error_message(box);
    int code = PROJECT_NAME_box_get_error_code(box);
    printf("Error %d: %s\n", code, msg);
    PROJECT_NAME_box_clear_error(box);
}


```
## box free

when you finish with the box, you need to free it:

```c 
PROJECT_NAME_box_free(box);
```


