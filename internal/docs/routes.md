# Horizon API Routes Reference

This document describes the HTTP routes exposed by the PROJECT_NAME server. All routes require authentication via request headers unless otherwise noted.

---

## Authentication

Every request must include the following authentication headers:

| Header     | Description                                      |
|------------|--------------------------------------------------|
| `password` | The root password configured for the server.     |
| `keyhash`  | The hashed key identifying the target data item. |

---

## Single-Item Operations

### Write Item

Stores raw data associated with a given key.

```
POST /write-data
```

**Headers**

| Header     | Required | Description                         |
|------------|----------|-------------------------------------|
| `password` | Yes      | Root password.                      |
| `keyhash`  | Yes      | Key hash of the item to write.      |

**Body**

The raw data to be stored (plain bytes or text).

---

### Write Key-Value Item

Stores a key-value pair associated with a given key.

```
POST /write-key-value
```

**Headers**

| Header     | Required | Description                              |
|------------|----------|------------------------------------------|
| `password` | Yes      | Root password.                           |
| `keyhash`  | Yes      | Key hash of the key-value item to write. |

**Body**

The key-value data to be stored.

---

### Write Item (Chunked)

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

### Read Item

Reads a portion of data associated with a given key.

```
GET /read-data
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

**Response**

Returns the data size as a plain-text integer.

---

## Key Enumeration Operations

### Get Key Size by Index

Returns the byte length of the key stored at a given index position. Returns `-1` if the index is out of range (i.e., no more keys exist), which serves as the standard loop-termination signal.

```
GET /get-key-size-by-index
```

**Headers**

| Header     | Required | Description                                          |
|------------|----------|------------------------------------------------------|
| `password` | Yes      | Root password.                                       |
| `index`    | Yes      | Zero-based index position of the key to query.       |

**Response**

Returns the key size as a plain-text integer, or `-1` if the index is out of range.

---

### Get Key by Index

Retrieves the raw key bytes stored at a given index position.

```
GET /get-key-by-index
```

**Headers**

| Header     | Required | Description                                          |
|------------|----------|------------------------------------------------------|
| `password` | Yes      | Root password.                                       |
| `index`    | Yes      | Zero-based index position of the key to retrieve.    |

**Response**

Returns the raw key bytes. The caller should first query the key size via `GET /get-key-size-by-index` to know how many bytes to expect.

---

## Batch Operations

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

### Read Multiple Items

Retrieves multiple items in a single request by providing a list of key hashes.

```
GET /read-items
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

Returns each requested item with its key hash, format, and data payload.

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
