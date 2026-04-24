
function Build_wrapper(wrapper_name)
    

    local pure = darwin.camalgamator.generate_amalgamation_with_callback(
        "wrappers/" .. wrapper_name .. ".c",
        function(import, path) return 'dont-include' end
    )
    darwin.dtw.write_file("release/" .. wrapper_name .. "_pure.c", pure)
end




function Wrappers()


    Build_wrapper("BearHttpsClient")
    Build_wrapper("CArgvParse")
    Build_wrapper("CWebStudio")

    

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
