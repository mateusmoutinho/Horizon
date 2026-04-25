function amalgamation()
   
       darwin.silverchain.generate({
        src = "src",
        project_short_cut = PROJECT_NAME,
        tags = { 
------------------DECLARATIONS-------------------------------------------
            "typedef",
            "macro",
            "global",
            "fdeclare", 
------------------IMPLEMENTATIONS-------------------------------------------
            "struct", 
            "fdefine"

    }})
    local amalgamations = darwin.dtw.list_files("amalgamations")
    for i=1,#amalgamations do
        local result = darwin.camalgamator.generate_amalgamation("amalgamations/" .. amalgamations[i])
        darwin.dtw.write_file("release/" .. amalgamations[i], result)
    end
    

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
    },
    callback = amalgamation
})
