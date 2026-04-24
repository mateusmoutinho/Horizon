function silver_chain_organize()



    darwin.silverchain.generate({
        src = "src",
        project_short_cut = PROJECT_NAME,
        tags = { 
------------------DECLARATIONS-------------------------------------------
            "typedef",
            "macro",
            "fdeclare", 
------------------IMPLEMENTATIONS-------------------------------------------
            "struct", 
            "fdefine"

    }})
  

end 

darwin.add_recipe({
    inputs = {
        "src",
        "dependencies",
        "wrappers"
    },
    outs= { },
    name="silver_chain",
    description = "Organize source files using SilverChain",
    callback = silver_chain_organize
})