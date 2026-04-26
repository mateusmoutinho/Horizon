# API Usage

This document provides a comprehensive reference for the PROJECT_NAME client API. It covers bucket initialization, key-value data operations, chunked I/O, and key enumeration.

---

## Table of Contents

1. [Bucket Initialization](#bucket-initialization)
2. [Writing Data](#writing-data)
3. [Chunked Write](#chunked-write)
4. [Deleting Data](#deleting-data)
5. [Reading Data](#reading-data)
6. [Querying Data Size](#querying-data-size)
7. [Full Data Retrieval](#full-data-retrieval)
8. [Iterating Over Keys](#iterating-over-keys)

---

## Bucket Initialization

A `PROJECT_NAME_bucket` represents a connection handle to a data store. It can target either a **remote** server (via HTTP) or a **local** directory on disk.

### Remote Bucket

Connects to a running PROJECT_NAME server instance. Requires the server URL and an authentication password.

```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new("http://localhost:8080", "password");
```

| Parameter  | Type           | Description                                      |
|------------|----------------|--------------------------------------------------|
| `url`      | `const char *` | Base URL of the remote PROJECT_NAME server.      |
| `password` | `const char *` | Authentication credential for the server.        |

### Local Bucket

Opens (or creates) a bucket backed by a local directory. No network connection is required.

```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new("./local_bucket");
```

| Parameter | Type           | Description                                       |
|-----------|----------------|----------------------------------------------------|
| `path`    | `const char *` | Filesystem path to the local bucket directory.     |

---

## Writing Data

Stores a value under a given key. Both the key and data are treated as raw byte buffers, allowing storage of arbitrary binary content.

```c
PROJECT_NAME_bucket_write_data(bucket,key, key_sizeq,data, data_size);
```

| Parameter      | Type                         | Description                                |
|----------------|------------------------------|--------------------------------------------|
| `bucket`       | `PROJECT_NAME_bucket *`      | Target bucket handle.                      |
| `key`          | `const unsigned  char *`     | Pointer to the key buffer.                 |
| `key_size`     | `long`                       | Length of the key buffer in bytes.         |
| `data`         | `const unsigned  char *`     | Pointer to the data to be stored.          |
| `data_size`    | `long`                       | Length of the data buffer in bytes.        |

---

## Chunked Write

For large payloads, data can be written incrementally using offset-based chunks. Each call appends or overwrites a segment of the value at the specified byte offset.

```c
unsigned char *data = "Hello World";
long total_size = strlen(data);
int chunk_size = 3;
int offset = 0;

while (offset < total_size) {
    int current_chunk = (offset + chunk_size > total_size) ? (total_size - offset) : chunk_size;
    PROJECT_NAME_bucket_write_data_chunk(bucket, key, key_size, offset, data + offset, current_chunk);
    offset += current_chunk;
}
```

| Parameter    | Type               | Description                                     |
|--------------|--------------------|-------------------------------------------------|
| `bucket`     | `PROJECT_NAME_bucket *` | Target bucket handle.                      |
| `key`        | `unsigned char *`  | Pointer to the key buffer.                      |
| `key_size`   | `long`             | Length of the key buffer in bytes.               |
| `offset`     | `int`              | Byte offset within the value to begin writing.   |
| `data`       | `unsigned char *`  | Pointer to the chunk data.                       |
| `chunk_size` | `int`              | Number of bytes to write in this chunk.          |

---

## Deleting Data

Removes a key and its associated value from the bucket.

```c
PROJECT_NAME_bucket_delete_data(bucket, key, key_size);
```

| Parameter  | Type               | Description                                |
|------------|--------------------|--------------------------------------------|
| `bucket`   | `PROJECT_NAME_bucket *` | Target bucket handle.               |
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

long bytes_read = PROJECT_NAME_bucket_read_data(
    bucket,
    (unsigned char *)key, key_size,
    offset, size_to_read,
    buffer
);
```

| Parameter      | Type               | Description                                          |
|----------------|------------------  |------------------------------------------------------|
| `bucket`       | `PROJECT_NAME_bucket *` | Target bucket handle.                           |
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

long data_size = PROJECT_NAME_bucket_get_data_size(
    bucket,
    (unsigned char *)key, key_size
);
```

| Parameter  | Type               | Description                                |
|------------|--------------------|--------------------------------------------|
| `bucket`   | `PROJECT_NAME_bucket *` | Target bucket handle.               |
| `key`      | `unsigned char *`  | Pointer to the key buffer.                |
| `key_size` | `long`             | Length of the key buffer in bytes.         |

**Returns:** `long` — Size of the stored value in bytes.

---

## Full Data Retrieval

Combines size querying and reading to retrieve the complete value for a key. The caller is responsible for freeing the allocated buffer.

```c
const char *key = "my_key";
long key_size = strlen(key);

// Query the total size of the stored value
long data_size = PROJECT_NAME_bucket_get_data_size(
    bucket,
    (unsigned char *)key, key_size
);

// Allocate a buffer and read the entire value
unsigned char *data = malloc(data_size);
PROJECT_NAME_bucket_read_data(
    bucket,
    (unsigned char *)key, key_size,
    0, data_size,
    data
);

// ... use data ...

free(data);
```

---

## Iterating Over Keys

Enumerates all keys stored in a bucket. Keys are accessed sequentially by index. The iteration terminates when `PROJECT_NAME_bucket_get_key_size_by_index` returns `-1`, indicating no more keys are available.

```c
int key_index = 0;

while (1) {
    long key_size = PROJECT_NAME_bucket_get_key_size_by_index(bucket, key_index);
    if (key_size == -1) {
        break; // No more keys
    }

    unsigned char key[key_size];
    PROJECT_NAME_bucket_get_key_by_index(bucket, key_index, key);

    printf("Key[%d]: %.*s\n", key_index, (int)key_size, key);
    key_index++;
}
```

| Function                                        | Description                                              |
|-------------------------------------------------|----------------------------------------------------------|
| `PROJECT_NAME_bucket_get_key_size_by_index`     | Returns the byte length of the key at the given index, or `-1` if the index is out of range. |
| `PROJECT_NAME_bucket_get_key_by_index`          | Copies the key at the given index into the provided buffer. |


