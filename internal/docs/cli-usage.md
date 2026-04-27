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


### Write File 

```bash
PROJECT_NAME write-data --password <password> --key-hash <keyhash> 
--keyvalue <keyvalue>  --content <content>
```
