# Database Storage Mode

This document describes the on-disk storage layout used by PROJECT_NAME when operating in **local box** mode. It serves as the authoritative reference for how key-value data is persisted, indexed, and managed at the filesystem level.

---

## Table of Contents

1. [Overview](#overview)
2. [Directory Layout](#directory-layout)
3. [Key Hashing](#key-hashing)
4. [File Descriptions](#file-descriptions)
5. [Concrete Example](#concrete-example)
6. [Protocols](#protocols)
   - [Creating an Item](#protocol-create-item)
   - [Reading an Item](#protocol-read-item)
   - [Updating an Item](#protocol-update-item)
   - [Deleting an Item by Key](#protocol-delete-item-by-key)
   - [Deleting an Item by Index](#protocol-delete-item-by-index)
   - [Iterating Over All Keys](#protocol-iterate-keys)
7. [Index Compaction](#index-compaction)
8. [Chunked I/O and the Storage Layer](#chunked-io-and-the-storage-layer)
9. [Concurrency and File Locking](#concurrency-and-file-locking)
10. [Error Scenarios](#error-scenarios)
11. [Design Rationale](#design-rationale)

---

## Overview

PROJECT_NAME uses a **filesystem-backed key-value store** where each box maps directly to a directory on disk. Every key-value pair is stored as a set of individual files under a deterministic directory path derived from the key's hash. An auxiliary index provides O(1) positional access to entries by their insertion order.

This design prioritizes **simplicity**, **portability**, and **transparency** — the entire database can be inspected, backed up, or migrated using standard filesystem tools.

---

## Directory Layout

```
database/
├── size.txt                        # Total number of stored items
├── index/
│   ├── 0.txt                       # Maps index 0 → <keyhash>
│   ├── 1.txt                       # Maps index 1 → <keyhash>
│   └── ...
└── itens/
    └── <keyhash>/
        ├── data                    # Raw value payload (binary-safe)
        ├── key_value               # Original key (binary-safe)
        └── index.txt               # Back-reference to the index position
```

### Schema Summary

| Path                                  | Content              | Purpose                                          |
|---------------------------------------|----------------------|--------------------------------------------------|
| `database/size.txt`                   | Integer (text)       | Total number of stored items.                    |
| `database/index/<N>.txt`              | `<keyhash>` (text)   | Forward index: maps position `N` to a key hash.  |
| `database/itens/<keyhash>/data`       | Raw bytes            | The stored value for this key.                   |
| `database/itens/<keyhash>/key_value`  | Raw bytes            | The original key bytes.                          |
| `database/itens/<keyhash>/index.txt`  | Integer (text)       | Back-reference: the index position of this item. |

---

## Key Hashing

When a key is stored, its raw byte content is passed through a deterministic hash function to produce a **keyhash** — a filesystem-safe string that uniquely identifies the key. This hash is used as the directory name under `database/itens/`.

**Properties of the hash function:**

- **Deterministic:** The same key bytes always produce the same hash.
- **Collision-resistant:** Distinct keys produce distinct hashes with high probability.
- **Filesystem-safe:** The output contains only characters valid in directory names across all supported platforms.

> **Note:** The hash is an internal detail. Callers interact exclusively with raw keys through the API; the hash is never exposed.

---

## File Descriptions

### `database/size.txt`

Stores the current total number of items as a plain-text integer. This file is the **synchronization point** for concurrent operations — it must be locked before any modification to the item count.

### `database/index/<N>.txt`

Each file in the `index/` directory represents one positional slot. The filename `<N>` is a zero-based integer index, and the file content is the `<keyhash>` of the item occupying that position. This provides:

- **O(1) positional access** to any item by index.
- **Sequential enumeration** of all stored keys.

### `database/itens/<keyhash>/`

Each item directory contains three files:

| File         | Format     | Description                                                    |
|--------------|------------|----------------------------------------------------------------|
| `data`       | Raw binary | The value payload. Supports arbitrary binary content.          |
| `key_value`  | Raw binary | The original key. Preserved verbatim for key retrieval.        |
| `index.txt`  | Plain text | The integer index position, used during deletion compaction.   |

---

## Concrete Example

Consider a box with two items: a `username` key mapped to `mateus` and a `password` key mapped to `12345`.

```
database/
├── size.txt                → "2"
├── index/
│   ├── 0.txt               → "hash_a"
│   └── 1.txt               → "hash_b"
└── itens/
    ├── hash_a/
    │   ├── data             → "mateus"
    │   ├── key_value        → "username"
    │   └── index.txt        → "0"
    └── hash_b/
        ├── data             → "12345"
        ├── key_value        → "password"
        └── index.txt        → "1"
```

| Index | Key Hash | Key        | Value    |
|-------|----------|------------|----------|
| 0     | `hash_a` | `username` | `mateus` |
| 1     | `hash_b` | `password` | `12345`  |

---

## Protocols

### Protocol: Create Item

Inserts a new key-value pair into the box.

**Steps:**

1. Compute the `<keyhash>` from the key bytes.
2. Create the directory `database/itens/<keyhash>/`.
3. Write the original key to `database/itens/<keyhash>/key_value`.
4. Write the value payload to `database/itens/<keyhash>/data`.
5. **Lock** `database/size.txt`.
6. Read the current size `N` from `database/size.txt`.
7. Increment the size: write `N + 1` to `database/size.txt`.
8. **Unlock** `database/size.txt`.
9. Write the index back-reference `N` to `database/itens/<keyhash>/index.txt`.
10. Create the forward index file `database/index/<N>.txt` containing `<keyhash>`.

**Atomicity note:** The lock on `size.txt` (steps 5–8) ensures that concurrent insertions receive unique, non-colliding index positions.

---

### Protocol: Read Item

Retrieves the value associated with a key.

**Steps:**

1. Compute the `<keyhash>` from the key bytes.
2. Verify that the directory `database/itens/<keyhash>/` exists. If not, the key does not exist — return an error.
3. Read the contents of `database/itens/<keyhash>/data` (optionally with offset and length parameters for partial reads).
4. Return the data to the caller.

**Partial reads:** When a caller specifies an `offset` and `size_to_read`, only the corresponding byte range within the `data` file is read. This enables efficient streaming of large values without loading the entire payload into memory.

---

### Protocol: Update Item

Overwrites the value associated with an existing key.

**Steps:**

1. Compute the `<keyhash>` from the key bytes.
2. Verify that the directory `database/itens/<keyhash>/` exists. If not, fall through to the [Create Item](#protocol-create-item) protocol.
3. Overwrite the contents of `database/itens/<keyhash>/data` with the new value.

**Note:** The key, index position, and forward index entry remain unchanged. Only the `data` file is modified. This is functionally equivalent to a write operation on an existing key.

---

### Protocol: Delete Item by Key

Removes a key-value pair and compacts the index to maintain a contiguous sequence.

**Steps:**

1. Compute the `<keyhash>` from the key bytes.
2. Read the index position `I` from `database/itens/<keyhash>/index.txt`.
3. Delete the entire directory `database/itens/<keyhash>/`.
4. Delete the forward index file `database/index/<I>.txt`.
5. **Lock** `database/size.txt`.
6. Read the current size `N` from `database/size.txt`.
7. Decrement the size: write `N - 1` to `database/size.txt`.
8. **Unlock** `database/size.txt`.
9. **If `I` is not the last index** (i.e., `I ≠ N - 1`):
   - Rename `database/index/<N-1>.txt` → `database/index/<I>.txt`.
   - Read the `<last_keyhash>` from the (now moved) `database/index/<I>.txt`.
   - Update `database/itens/<last_keyhash>/index.txt` to contain `I`.

> **Why compaction?** Without step 9, deletion would leave gaps in the index sequence (e.g., indices `0, 2, 3` after deleting index `1`). By swapping the last item into the vacated slot, the index remains a dense, zero-based sequence — enabling O(1) enumeration and size-based bounds checking.

---

### Protocol: Delete Item by Index

Removes the item at a specific index position.

**Steps:**

1. Read the `<keyhash>` from `database/index/<I>.txt`.
2. Proceed with the [Delete Item by Key](#protocol-delete-item-by-key) protocol using the resolved `<keyhash>`.

---

### Protocol: Iterate Keys

Enumerates all stored keys in index order.

**Steps:**

1. Read the total item count `N` from `database/size.txt`.
2. For each index `i` from `0` to `N - 1`:
   1. Read the `<keyhash>` from `database/index/<i>.txt`.
   2. Read the original key from `database/itens/<keyhash>/key_value`.
   3. Yield the key (and optionally its size) to the caller.
3. Terminate when `i ≥ N`.

**API mapping:** This protocol backs the `PROJECT_NAME_box_get_key_by_index` and `PROJECT_NAME_box_get_key_size_by_index` functions documented in the [API Usage](api_usage.md) reference.

---

## Index Compaction

The index compaction strategy (used during deletion) follows a **swap-with-last** approach:

```
Before deleting index 1 (size = 4):

  index/0.txt → hash_a
  index/1.txt → hash_b    ← to be deleted
  index/2.txt → hash_c
  index/3.txt → hash_d    ← last item

After deletion (size = 3):

  index/0.txt → hash_a
  index/1.txt → hash_d    ← moved from position 3
  index/2.txt → hash_c

  itens/hash_d/index.txt  → "1"  ← updated back-reference
```

**Characteristics:**

- **O(1) compaction:** Only two files are renamed and one back-reference is updated, regardless of the total item count.
- **Order is not preserved:** The swap may change the relative order of items. If stable ordering is required, the caller must maintain an external sort.
- **Idempotent size tracking:** The `size.txt` file always reflects the exact number of valid index entries.

---

## Chunked I/O and the Storage Layer

The API supports **chunked writes** (`PROJECT_NAME_box_write_data_chunk`) and **offset-based reads** (`PROJECT_NAME_box_read_data`). These operations map directly to file I/O on the `data` file:

| API Operation                             | Storage-Layer Action                                                     |
|-------------------------------------------|--------------------------------------------------------------------------|
| `PROJECT_NAME_box_write_data`             | Overwrites the entire `database/itens/<keyhash>/data` file.              |
| `PROJECT_NAME_box_write_data_chunk`       | Seeks to `offset` in `data` and writes `chunk_size` bytes.              |
| `PROJECT_NAME_box_read_data`              | Seeks to `offset` in `data` and reads up to `size_to_read` bytes.       |
| `PROJECT_NAME_box_get_data_size`          | Returns the file size of `database/itens/<keyhash>/data`.                |

**Chunked write workflow:**

```
File state:  [.................]  (empty or existing data)

Chunk 1 (offset=0, size=3):   [ABC...............]
Chunk 2 (offset=3, size=3):   [ABCDEF............]
Chunk 3 (offset=6, size=5):   [ABCDEFGHIJK.......]
...
```

Each chunk is written independently at the specified byte offset, allowing the caller to stream large payloads without buffering the entire value in memory.

---

## Concurrency and File Locking

The `database/size.txt` file acts as the **critical section** for all operations that modify the item count (create and delete). The locking protocol is as follows:

1. **Acquire an exclusive lock** on `database/size.txt` before reading or modifying the count.
2. Perform the read-modify-write cycle on the size value.
3. **Release the lock** after the write is complete.

**Scope of the lock:**

| Operation             | Lock Required? | Reason                                               |
|-----------------------|----------------|------------------------------------------------------|
| Create item           | Yes            | Must atomically assign a unique index position.      |
| Delete item           | Yes            | Must atomically decrement size and compact the index. |
| Read item             | No             | Reads from a stable `<keyhash>` directory.           |
| Update item (data)    | No             | Overwrites only the `data` file; no index mutation.  |
| Query data size       | No             | Reads file metadata only.                            |
| Iterate keys          | No*            | Reads a snapshot of the index.                       |

> \* Iteration is not locked. If items are concurrently added or deleted during iteration, the caller may observe partial results. For consistent snapshots, the caller should implement external synchronization.

---

## Error Scenarios

| Scenario                                  | Behavior                                                                                    |
|-------------------------------------------|---------------------------------------------------------------------------------------------|
| Key does not exist (read/delete)          | The `<keyhash>` directory is absent. Returns an error via `PROJECT_NAME_box_is_error`.       |
| Disk full (write/create)                  | The write operation fails. The error state is set on the box handle.                        |
| Corrupted `size.txt`                      | The size file contains a non-integer value. Behavior is undefined; manual recovery required. |
| Missing index file                        | An index slot references a non-existent `<keyhash>`. Indicates data corruption.             |
| Concurrent lock contention                | The requesting operation blocks until the lock on `size.txt` is released.                   |
| Partial chunk write failure               | The `data` file may contain partially written content. The error state is set on the box.   |

---

## Design Rationale

### Why a filesystem-based store?

- **Zero external dependencies:** No database engine, server process, or runtime library is required beyond standard POSIX file operations.
- **Inspectability:** Every record is a plain file that can be examined with standard tools (`cat`, `ls`, `hexdump`).
- **Portability:** The storage format is platform-agnostic and can be copied across systems.
- **Simplicity:** The implementation requires only basic file I/O — no B-trees, WALs, or memory-mapped regions.

### Why a separate index directory?

The `index/` directory provides **positional access** without scanning the `itens/` directory. This enables:

- Deterministic key enumeration in O(N) time.
- O(1) access to any item by position.
- Efficient deletion via swap-with-last compaction.

### Why store the key in `key_value`?

Since the `<keyhash>` is a one-way transformation, the original key bytes must be preserved to support key retrieval during iteration (`PROJECT_NAME_box_get_key_by_index`).

### Why lock only `size.txt`?

The `size.txt` file is the **single source of truth** for the item count. By locking only this file, the system minimizes lock contention — individual item reads and writes proceed without synchronization, as each item resides in its own isolated directory.
