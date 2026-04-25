
function Build_wrapper(wrapper_name)

    darwin.silverchain.generate({
        src = "wrappers/" .. wrapper_name,
        project_short_cut = PROJECT_NAME.."_"..wrapper_name,
        tags = { 
------------------DECLARATIONS-------------------------------------------
         
            "typedef",
            "macro",
            "fdeclare", 
------------------IMPLEMENTATIONS-------------------------------------------
            
            "depdeclare",
            "struct", 
            "fdefine",
            "depdefine"

    }})



    local headers_pure = darwin.camalgamator.generate_amalgamation(
        "wrappers/" .. wrapper_name .. "/imports/imports.fdeclare.h"
    )
    darwin.dtw.write_file("src/deps/fdeclare." .. wrapper_name .. ".h", headers_pure)


    local pure = darwin.camalgamator.generate_amalgamation_with_callback(
        "wrappers/" .. wrapper_name .. "/imports/imports.fdefine.h",
        function(import, name) 
           
            if darwin.dtw.ends_with(name, "depdeclare.includes.h") then
                return 'dont-include'
            end
            if darwin.dtw.ends_with(name, "depdefine.includes.c") then
                return 'dont-include'
            end
            return 'include-once'

         end
    )


    
    local with_headders =  darwin.camalgamator.generate_amalgamation(
        "wrappers/" .. wrapper_name .. "/imports/imports.fdefine.h"
    )


    local full = darwin.camalgamator.generate_amalgamation(
        "wrappers/" .. wrapper_name .. "/imports/imports.depdefine.h"
    )
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_pure.c", pure)
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_with_headers.c", with_headders)
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_full.c", full)

end




function Wrappers()
    local wrapper_imports = ""
    local wrappers = darwin.dtw.list_dirs("wrappers")
    for i=1,#wrappers do
        local current_wrapper = wrappers[i]
        -- replace "/" for "" in current_wrapper
        current_wrapper = string.gsub(current_wrapper, "/", "")
        wrapper_imports = wrapper_imports .. "#include \"../wrappers/" .. current_wrapper.. "/imports/imports.depdefine.h\"\n"
        Build_wrapper(current_wrapper)
    end
    darwin.dtw.write_file("amalgamations/wrapper_imports.h", wrapper_imports)
end


darwin.add_recipe({
    inputs = {
        "src",
        "dependencies",
        "wrappers"
    },
    outs = {},
    name = "wrappers",
    description = "Wrapper source files",
    callback = Wrappers
})
