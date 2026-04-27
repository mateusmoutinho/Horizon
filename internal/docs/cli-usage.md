These documentation covers the CLI usage of PROJECT_NAME.

## Start Server

```bash
PROJECT_NAME start-server --password <password> --port <port> --database-path <database-path> --internal-database-path <internal-database-path>
```

| Parameter  | Type           | Description                                |
|------------|----------------|--------------------------------------------|
| `password` | `const char *` | Root password for the server.              |
| `port`     | `const char *` | Port number for the server.                |
| `database-path` | `const char *` | Path to the database file.                 |
| `internal-database-path` | `const char *` | Path to the internal database file. |

---

## Write Data

Stores raw data associated with a given key.

```bash
PROJECT_NAME write-data --url <url> --password <password> --keyvalue <keyvalue> --content <content> [--content-file <path>]
```

| Parameter      | Type           | Required | Description                                              |
|----------------|----------------|----------|----------------------------------------------------------|
| `url`          | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                     |
| `password`     | `const char *` | Yes      | Root password for authentication.                        |
| `keyvalue`     | `const char *` | Yes      | Key string; the CLI computes its hash internally.        |
| `content`      | `const char *` | No       | Raw data content to store (inline).                      |
| `content-file` | `const char *` | No       | Path to a file whose contents will be stored as the data.|

> Either `--content` or `--content-file` must be provided.

---

## Write Data Chunk

Writes a chunk of data at a specified byte offset, enabling incremental or resumable uploads.

```bash
PROJECT_NAME write-data-chunk --url <url> --password <password> --keyvalue <keyvalue> --offset <offset> --size <size> --content <content> [--content-file <path>]
```

| Parameter      | Type           | Required | Description                                              |
|----------------|----------------|----------|----------------------------------------------------------|
| `url`          | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                     |
| `password`     | `const char *` | Yes      | Root password for authentication.                        |
| `keyvalue`     | `const char *` | Yes      | Key string; the CLI computes its hash internally.        |
| `offset`       | `long`         | Yes      | Byte offset at which the chunk should be written.        |
| `size`         | `long`         | Yes      | Size of the chunk in bytes.                              |
| `content`      | `const char *` | No       | Binary data chunk to write (inline).                     |
| `content-file` | `const char *` | No       | Path to a file whose contents will be written as the chunk.|

> Either `--content` or `--content-file` must be provided.

---

## Write Items

Writes multiple items in a single request.

```bash
PROJECT_NAME write-items --url <url> --password <password> --json <json>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `json`     | `const char *` | JSON payload containing the items to write.         |

**JSON Format:**

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

| Format | Description                 |
|--------|-----------------------------|
| `b64`  | Base64-encoded binary data. |
| `txt`  | Plain UTF-8 text data.      |

---

## Read Data

Reads the entire raw data associated with a given key.

```bash
PROJECT_NAME read-data --url <url> --password <password> --keyvalue <keyvalue> [--out <path>]
```

| Parameter  | Type           | Required | Description                                         |
|------------|----------------|----------|-----------------------------------------------------|
| `url`      | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Yes      | Root password for authentication.                   |
| `keyvalue` | `const char *` | Yes      | Key string; the CLI computes its hash internally.   |
| `out`      | `const char *` | No       | Path to a file where the response will be saved.    |

---

## Read Key-Value

Reads the key-value string associated with a given key.

```bash
PROJECT_NAME read-key-value --url <url> --password <password> --keyvalue <keyvalue> [--out <path>]
```

| Parameter  | Type           | Required | Description                                         |
|------------|----------------|----------|-----------------------------------------------------|
| `url`      | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Yes      | Root password for authentication.                   |
| `keyvalue` | `const char *` | Yes      | Key string; the CLI computes its hash internally.   |
| `out`      | `const char *` | No       | Path to a file where the response will be saved.    |

---

## Read Data Chunk

Reads a portion of data associated with a given key.

```bash
PROJECT_NAME read-data-chunk --url <url> --password <password> --keyvalue <keyvalue> --offset <offset> --size <size> [--out <path>]
```

| Parameter  | Type           | Required | Description                                         |
|------------|----------------|----------|-----------------------------------------------------|
| `url`      | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Yes      | Root password for authentication.                   |
| `keyvalue` | `const char *` | Yes      | Key string; the CLI computes its hash internally.   |
| `offset`   | `long`         | Yes      | Byte offset from which to begin reading.            |
| `size`     | `long`         | Yes      | Number of bytes to read.                            |
| `out`      | `const char *` | No       | Path to a file where the response will be saved.    |

---

## Read Items

Reads multiple items in a single request.

```bash
PROJECT_NAME read-items --url <url> --password <password> --json <json> [--out <path>]
```

| Parameter  | Type           | Required | Description                                         |
|------------|----------------|----------|-----------------------------------------------------|
| `url`      | `const char *` | Yes      | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Yes      | Root password for authentication.                   |
| `json`     | `const char *` | Yes      | JSON payload listing the key hashes to read.        |
| `out`      | `const char *` | No       | Path to a file where the response will be saved.    |

**JSON Format:**

```json
{
  "items": [
    "keyhash_1",
    "keyhash_2",
    "keyhash_n"
  ]
}
```

---

## Get Data Size

Returns the total size in bytes of the value associated with a given key.

```bash
PROJECT_NAME get-data-size --url <url> --password <password> --keyvalue <keyvalue>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `keyvalue` | `const char *` | Key string; the CLI computes its hash internally.   |

---

## Delete Data

Permanently removes the data associated with a given key.

```bash
PROJECT_NAME delete-data --url <url> --password <password> --keyvalue <keyvalue>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `keyvalue` | `const char *` | Key string; the CLI computes its hash internally.   |

---

## Delete Items

Permanently removes multiple items in a single request.

```bash
PROJECT_NAME delete-items --url <url> --password <password> --json <json>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `json`     | `const char *` | JSON payload listing the key hashes to delete.      |

**JSON Format:**

```json
{
  "items": [
    "keyhash_1",
    "keyhash_2",
    "keyhash_n"
  ]
}
```

---

## Database Size

Returns the total number of items stored in the database.

```bash
PROJECT_NAME database-size --url <url> --password <password>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |

---

## Keyhash by Index

Retrieves the key hash at a specific index position.

```bash
PROJECT_NAME keyhash-by-index --url <url> --password <password> --index <index>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `index`    | `long`         | Zero-based index of the key hash to retrieve.       |

---

## Keyhashes Range

Returns a list of key hashes between a range of indices.

```bash
PROJECT_NAME keyhashes-range --url <url> --password <password> --start <start> --end <end>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `start`    | `long`         | Start index of the range (inclusive).               |
| `end`      | `long`         | End index of the range (exclusive).                 |

---

## Key-Values Range

Returns a list of key-value strings between a range of indices.

```bash
PROJECT_NAME key-values-range --url <url> --password <password> --start <start> --end <end>
```

| Parameter  | Type           | Description                                         |
|------------|----------------|-----------------------------------------------------|
| `url`      | `const char *` | Base URL of the PROJECT_NAME server.                |
| `password` | `const char *` | Root password for authentication.                   |
| `start`    | `long`         | Start index of the range (inclusive).               |
| `end`      | `long`         | End index of the range (exclusive).                 |
