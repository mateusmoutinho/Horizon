
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
        "wrappers/" .. wrapper_name .. "imports/fdefine.h",
        function(import, path) 

            print(import, path)

         end
    )


    
    local with_headders = darwin.camalgamator.generate_amalgamation_with_callback(
        "wrappers/" .. wrapper_name .. ".c",
        function(import, path)
            if darwin.dtw.ends_with(path,".h") then
                return 'include-once' 
            end
            return 'dont-include'
         end
    )
    local full = darwin.camalgamator.generate_amalgamation(
        "wrappers/" .. wrapper_name .. ".c"
    )
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_pure.c", pure)
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_with_headers.c", with_headders)
    darwin.dtw.write_file("release/Horizon_wrapper_" .. wrapper_name .. "_full.c", full)

end




function Wrappers()
    Build_wrapper("std")

    Build_wrapper("BearHttpsClient")
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
