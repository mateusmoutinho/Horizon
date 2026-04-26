--- sample of writing unique primary key 
Horizon.write_unique_pk({
    box=global.box,
    target="users",
    primary_keys={"email","usernames"},
    values = {
        email= "mateusmoutinho@gmail.com",
        usernames="mateusmoutinho",
        password="aaaa"
    }
})


--- sample of retriving by primary key 
local result = Horizon.retrive_unique_pk({
    box=global.box,
    target="users",
    primary_keys={"email"},
    values = {
        email= "mateusmoutinho@gmail.com",
    },
    retrive_values={"email","usernames","password"}
})
-- returns like 
result = {
    {
        email= "mateusmoutinho@gmail.com",
        usernames="mateusmoutinho",
        password="aaaa"
    }
}