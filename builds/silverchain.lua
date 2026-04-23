function silver_chain_organize()



    darwin.silverchain.generate({
        src = "src",
        project_short_cut = PROJECT_NAME,
        tags = { 
------------------DECLARATIONS-------------------------------------------
            "typedef",
            "fdeclare", 
------------------IMPLEMENTATIONS-------------------------------------------
            "struct", 
            "fdefine"

    }})
    darwin.silverchain.generate({
        src = "wrappers",
        project_short_cut = PROJECT_NAME,
        tags = { 
------------------DECLARATIONS-------------------------------------------
            "depdeclae", 
            "fdeclare", 
------------------IMPLEMENTATIONS-------------------------------------------
            "depdefine",
            "fdefine"

    }})


end 

darwin.add_recipe({
    inputs={
        "src",
        "dependencies"
    },
    outs= {
        "src/fdeclare.all.h"
    },
    name="silver_chain_organize",
    description = "Organize source files using SilverChain",
    callback = silver_chain_organize
})