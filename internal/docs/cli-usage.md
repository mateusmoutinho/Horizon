These documentation covers the CLI usage of PROJECT_NAME.

## Start Server

```bash
PROJECT_NAME start-server --password <password> --port <port> --database-path <database-path> --internal-database-path <internal-database-path>
```

| Parameter  | Type     | Description                                |
|------------|----------|--------------------------------------------|
| `password` | `string` | Root password for the server.              |
| `port`     | `string` | Port number for the server.                |
| `database-path` | `string` | Path to the database file.            |
| `internal-database-path` | `string` | Path to the internal database file. |

---

## Write Data

Stores raw data associated with a given key.

```bash
PROJECT_NAME write-data [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue> --content <content> [--content-file <path>]
```

| Parameter       | Type     | Required                        | Description                                               |
|-----------------|----------|---------------------------------|-----------------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                      |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                         |
| `database-path` | `string` | No                              | Path to the local database file for direct access.        |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.         |
| `content`       | `string` | No                              | Raw data content to store (inline).                       |
| `content-file`  | `string` | No                              | Path to a file whose contents will be stored as the data. |

> Either `--database-path` or both `--url` and `--password` must be provided.
> Either `--content` or `--content-file` must be provided.

---

## Write Data Chunk

Writes a chunk of data at a specified byte offset, enabling incremental or resumable uploads.

```bash
PROJECT_NAME write-data-chunk [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue> --offset <offset> --size <size> --content <content> [--content-file <path>]
```

| Parameter       | Type     | Required                        | Description                                                |
|-----------------|----------|---------------------------------|------------------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                       |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                          |
| `database-path` | `string` | No                              | Path to the local database file for direct access.         |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.          |
| `offset`        | `long`   | Yes                             | Byte offset at which the chunk should be written.          |
| `size`          | `long`   | Yes                             | Size of the chunk in bytes.                                |
| `content`       | `string` | No                              | Binary data chunk to write (inline).                       |
| `content-file`  | `string` | No                              | Path to a file whose contents will be written as the chunk.|

> Either `--database-path` or both `--url` and `--password` must be provided.
> Either `--content` or `--content-file` must be provided.

---

## Write Items

Writes multiple items in a single request.

```bash
PROJECT_NAME write-items [--url <url> --password <password>] [--database-path <path>] --json <json>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `json`          | `string` | Yes                             | JSON payload containing the items to write.         |

> Either `--database-path` or both `--url` and `--password` must be provided.

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
PROJECT_NAME read-data [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue> [--out <path>]
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.   |
| `out`           | `string` | No                              | Path to a file where the response will be saved.    |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Read Key-Value

Reads the key-value string associated with a given key.

```bash
PROJECT_NAME read-key-value [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue> [--out <path>]
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.   |
| `out`           | `string` | No                              | Path to a file where the response will be saved.    |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Read Data Chunk

Reads a portion of data associated with a given key.

```bash
PROJECT_NAME read-data-chunk [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue> --offset <offset> --size <size> [--out <path>]
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.   |
| `offset`        | `long`   | Yes                             | Byte offset from which to begin reading.            |
| `size`          | `long`   | Yes                             | Number of bytes to read.                            |
| `out`           | `string` | No                              | Path to a file where the response will be saved.    |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Read Items

Reads multiple items in a single request.

```bash
PROJECT_NAME read-items [--url <url> --password <password>] [--database-path <path>] --json <json> [--out <path>]
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `json`          | `string` | Yes                             | JSON payload listing the key hashes to read.        |
| `out`           | `string` | No                              | Path to a file where the response will be saved.    |

> Either `--database-path` or both `--url` and `--password` must be provided.

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
PROJECT_NAME get-data-size [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.   |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Delete Data

Permanently removes the data associated with a given key.

```bash
PROJECT_NAME delete-data [--url <url> --password <password>] [--database-path <path>] --keyvalue <keyvalue>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `keyvalue`      | `string` | Yes                             | Key string; the CLI computes its hash internally.   |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Delete Items

Permanently removes multiple items in a single request.

```bash
PROJECT_NAME delete-items [--url <url> --password <password>] [--database-path <path>] --json <json>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `json`          | `string` | Yes                             | JSON payload listing the key hashes to delete.      |

> Either `--database-path` or both `--url` and `--password` must be provided.

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
PROJECT_NAME database-size [--url <url> --password <password>] [--database-path <path>]
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Keyhash by Index

Retrieves the key hash at a specific index position.

```bash
PROJECT_NAME keyhash-by-index [--url <url> --password <password>] [--database-path <path>] --index <index>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `index`         | `long`   | Yes                             | Zero-based index of the key hash to retrieve.       |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Keyhashes Range

Returns a list of key hashes between a range of indices.

```bash
PROJECT_NAME keyhashes-range [--url <url> --password <password>] [--database-path <path>] --start <start> --end <end>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `start`         | `long`   | Yes                             | Start index of the range (inclusive).               |
| `end`           | `long`   | Yes                             | End index of the range (exclusive).                 |

> Either `--database-path` or both `--url` and `--password` must be provided.

---

## Key-Values Range

Returns a list of key-value strings between a range of indices.

```bash
PROJECT_NAME key-values-range [--url <url> --password <password>] [--database-path <path>] --start <start> --end <end>
```

| Parameter       | Type     | Required                        | Description                                         |
|-----------------|----------|---------------------------------|-----------------------------------------------------|
| `url`           | `string` | Yes (if no `--database-path`)   | Base URL of the PROJECT_NAME server.                |
| `password`      | `string` | Yes (if no `--database-path`)   | Root password for authentication.                   |
| `database-path` | `string` | No                              | Path to the local database file for direct access.  |
| `start`         | `long`   | Yes                             | Start index of the range (inclusive).               |
| `end`           | `long`   | Yes                             | End index of the range (exclusive).                 |

> Either `--database-path` or both `--url` and `--password` must be provided.
