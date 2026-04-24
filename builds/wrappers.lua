
function Build_wrapper(wrapper_name)
    

    local pure = darwin.camalgamator.generate_amalgamation_with_callback(
        "wrappers/" .. wrapper_name .. ".c",
        function(import, path) return 'dont-include' end
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
    darwin.dtw.write_file("release/" .. wrapper_name .. "_pure.c", pure)
    darwin.dtw.write_file("release/" .. wrapper_name .. "_with_headers.c", with_headders)
    darwin.dtw.write_file("release/" .. wrapper_name .. "_full.c", full)
end




function Wrappers()


    Build_wrapper("BearHttpsClient")
    Build_wrapper("CArgvParse")
    Build_wrapper("CWebStudio")
    Build_wrapper("std")

    --std full is equal to std with_headers so we remove it
    darwin.dtw.remove_any("release/std_full.c")

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
