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
    local horizon_lib_full = darwin.camalgamator.generate_amalgamation("amalgamation/HorizonLib_full.c")
    local horizon_lib_headers = darwin.camalgamator.generate_amalgamation("amalgamation/HorizonLib.h")
    local horizon_lib_pure = darwin.camalgamator.generate_amalgamation("amalgamation/HorizonLib_pure.c")
    
    local horizon_main = darwin.camalgamator.generate_amalgamation("amalgamation/main.c")
    
    darwin.dtw.write_file("release/HorizonLib_full.c", horizon_lib_full)
    darwin.dtw.write_file("release/HorizonLib.h", horizon_lib_headers)
    darwin.dtw.write_file("release/HorizonLib_pure.c", horizon_lib_pure)
    darwin.dtw.write_file("release/cli.c", horizon_main)

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
