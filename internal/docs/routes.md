these documentation cover the routes of the project

### Write Item

POST /write-data

Headers:

password: <root_password>
keyhash: <key_hash>

Body: 
<data_to_be_stored>


POST: /write-key-value

Headers:

password: <root_password>
keyhash: <key_hash>

Body: 
<key-value>


### Write Item Chunked

POST /write-data-chunk

Headers:

password: <root_password>
keyhash: <key_hash>
offset: <offset>
size: <chunk_size>

Body: 
<data_chunk_to_be_stored>


### Read Item

GET /read-data

Headers:

password: <root_password>
keyhash: <key_hash>
offset: <offset>
size: <size_to_read>


## Delete Item

DELETE /delete-data

Headers:

password: <root_password>
keyhash: <key_hash>

