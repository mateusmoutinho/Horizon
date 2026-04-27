# PROJECT_NAME API Routes Reference

This document describes the HTTP routes exposed by the PROJECT_NAME server. All routes require authentication via request headers unless otherwise noted.

---

## Authentication

Every request must include the following authentication headers:

| Header     | Description                                      |
|------------|--------------------------------------------------|
| `password` | The root password configured for the server.     |
| `keyhash`  | The hashed key identifying the target data item. |

---


### Write Item

Stores raw data associated with a given key.

```
POST /write-data
```

**Headers**

| Header           | Required | Description                                                                 |
|------------------|----------|-----------------------------------------------------------------------------|
| `password`       | Yes      | Root password.                                                              |
| `keyhash`        | Yes      | Key hash of the item to write.                                              |

**Body**

The raw data to be stored (plain bytes or text).

---

### Write Key-Value Item

Stores a key-value pair associated with a given key.

```
POST /write-key-value
```

**Headers**

| Header           | Required | Description                                                                 |
|------------------|----------|-----------------------------------------------------------------------------|
| `password`       | Yes      | Root password.                                                              |
| `keyhash`        | Yes      | Key hash of the key-value item to write.                                    |

**Body**

The key-value data to be stored.

---

### Write Data (Chunked)

Writes a chunk of data at a specified offset, enabling incremental or resumable uploads.

```
POST /write-data-chunk
```

**Headers**

| Header     | Required | Description                                          |
|------------|----------|------------------------------------------------------|
| `password` | Yes      | Root password.                                       |
| `keyhash`  | Yes      | Key hash of the item to write.                       |
| `offset`   | Yes      | Byte offset at which the chunk should be written.    |
| `size`     | Yes      | Size of the chunk in bytes.                          |

**Body**

The binary data chunk to be stored at the specified offset.

---



### Write Multiple Items

Writes multiple items in a single request. Each item specifies its own key hash, data format, and payload.

```
POST /write-items
```

**Headers**

| Header     | Required | Description    |
|------------|----------|----------------|
| `password` | Yes      | Root password. |

**Body**

```json
{
  "items": [
    {
      "keyhash": "<key_hash>",
      "format": "b64",
      "data": "<base64_encoded_data>"
    },
    {
      "keyhash": "<key_hash>",
      "format": "txt",
      "data": "<plain_text_data>"
    }
  ]
}
```

**Supported Formats**

| Format | Description                  |
|--------|------------------------------|
| `b64`  | Base64-encoded binary data.  |
| `txt`  | Plain UTF-8 text data.       |

---


### Read Key-Value

Reads the key-value associated with a given key-value key.

```
GET /read-key-value
```

**Headers**

| Header     | Required | Description                                        |
|------------|----------|----------------------------------------------------|
| `password` | Yes      | Root password.                                     |
| `keyhash`  | Yes      | Key hash of the item to read.                      |

**Response**

Returns the key-value data.

---

### Read Data

Reads the entire data associated with a given data-key.

```
GET /read-data
```

**Headers**

| Header     | Required | Description                         |
|------------|----------|-------------------------------------|
| `password` | Yes      | Root password.                      |
| `keyhash`  | Yes      | Key hash of the item to read.       |

**Response**

Returns the raw data slice.

---

### Read Data (Chunked)

Reads a portion of data associated with a given data-key.

```
GET /read-data-chunk
```

**Headers**

| Header     | Required | Description                                        |
|------------|----------|----------------------------------------------------|
| `password` | Yes      | Root password.                                     |
| `keyhash`  | Yes      | Key hash of the item to read.                      |
| `offset`   | Yes      | Byte offset from which to begin reading.           |
| `size`     | Yes      | Number of bytes to read.                           |

**Response**

Returns the raw data slice defined by `offset` and `size`.

---

### Read Multiple Items

Reads multiple items in a single request. Each item is identified by its key hash, and the response returns their corresponding data in the same order.

```
POST /read-items
```

**Headers**

| Header     | Required | Description    |
|------------|----------|----------------|
| `password` | Yes      | Root password. |

**Body**

```json
{
  "items": [
    "keyhash_1",
    "keyhash_2",
    "keyhash_n"
  ]
}
```

**Response**

```json
{
  "items": [
    {
      "keyhash": "<key_hash>",
      "format": "b64",
      "data": "<base64_encoded_data>"
    },
    {
      "keyhash": "<key_hash>",
      "format": "txt",
      "data": "<plain_text_data>"
    }
  ]
}
```

**Supported Formats**

| Format | Description                  |
|--------|------------------------------|
| `b64`  | Base64-encoded binary data.  |
| `txt`  | Plain UTF-8 text data.       |

---


### Get Item Data Size

Returns the total size in bytes of the value associated with a given key. Useful for allocating buffers before a read.

```
GET /get-data-size
```

**Headers**

| Header     | Required | Description                         |
|------------|----------|-------------------------------------|
| `password` | Yes      | Root password.                      |
| `keyhash`  | Yes      | Key hash of the item to query.      |


### Delete Item

Permanently removes the data associated with a given key.

```
DELETE /delete-data
```

**Headers**

| Header     | Required | Description                          |
|------------|----------|--------------------------------------|
| `password` | Yes      | Root password.                       |
| `keyhash`  | Yes      | Key hash of the item to delete.      |

---


**Response**

Returns the data size as a plain-text integer.

---


### Delete Multiple Items

Permanently removes multiple items in a single request by providing a list of key hashes.

```
DELETE /delete-items
```

**Headers**

| Header     | Required | Description    |
|------------|----------|----------------|
| `password` | Yes      | Root password. |

**Body**

```json
{
  "items": [
    "keyhash_1",
    "keyhash_2",
    "keyhash_n"
  ]
}
```
