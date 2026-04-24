function amalgamation()
  


end

darwin.add_recipe({
    inputs = {
        "src",
        "dependencies",
        "wrappers"
    },
    outs= {
       
    },
    name="amalgamation",
    description = "Amalgamate source files",
    requires = {
       "silver_chain"
    },
    callback = amalgamation
})
