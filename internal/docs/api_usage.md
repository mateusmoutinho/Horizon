these documentation covers the api usage of the project 

## creating a bucket:
a Bucket can be local or remote, for a remote, you need to provide the url and the password 

### Remote Bucket
```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new( "http://localhost:8080", "password");
```

### Local Bucket
```c
PROJECT_NAME_bucket *bucket = PROJECT_NAME_bucket_new( "./local_bucket");
```

## The Bucket Key Value Model

