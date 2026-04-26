
database storage pattern:

Struct: 
database/
database/size.txt -> the size of total itens
database/index/
database/index/<index>.txt -> <keyhash> 
database/itens
database/itens/<keyhash>/
database/itens/<keyhash>/data -> <data> 
database/itens/<keyhash>/key_value -> <keyvalue> 
database/itens/<keyhash>/index.txt -> <index>


sample:

database/
database/size.txt -> 2
database/index/
database/index/0 -> hash_a
database/index/1 -> hash_b
database/itens
database/itens/hash_a/
database/itens/hash_a/data -> mateus
database/itens/hash_a/keyvalue -> username
database/itens/hash_a/index.txt -> 0
database/itens/hash_b/
database/itens/hash_b/data -> 12345
database/itens/hash_b/keyvalue -> password
database/itens/hash_b/index.txt -> 1

## protocol to create a new item:
1. calc the hash of the key.
2. create a new folder in the database/itens folder with the hash of the key.
3. write the key value in the database/itens/<keyhash>/keyvalue file.
4. write the data in the database/itens/<keyhash>/data file.
5. lock the file database/size.txt.
6. increment the value in database/size.txt by 1.
7. unlock the file database/size.txt.
8. create the database/index/<index>.txt file with the hash of the key.


## protocol to delete an by key 
1. calc the hash of the key.
2. retrive the index from the database/itens/<keyhash>/index.txt file.
3. delete the database/itens/<keyhash> folder.
4. delete the database/index/<index>.txt file.
5. lock the file database/size.txt.
6. decrement the value in database/size.txt by 1.
7. unlock the file database/size.txt.
8. rename the last database/index/<last_item> with the current index to be deleted. (if the index to be deleted is not the last one).
9. rename the database/itens/<last_item>/index.txt with the current index to be deleted. (if the index to be deleted is not the last one).



