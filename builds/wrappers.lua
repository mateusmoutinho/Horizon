function build_wrapper(wrapper_name)


    local hide_import = "#define PRIVATE_HORIZON_HIDE_IMPORTS"

    local wrapper_source = darwin.dtw.load_file("wrappers/" .. wrapper_name .. ".c")
    wrapper_source = hide_import.."\n"..wrapper_source
    darwin.dtw.write_file("release/" .. wrapper_name .. "_pure.c",wrapper_source)


    local lib_declare = darwin.dtw.load_file("dependencies/" .. wrapper_name .. ".h")
    local wrapper_with_header = lib_declare.. "\n".. wrapper_source 
    darwin.dtw.write_file("release/" .. wrapper_name .. "_with_headers.h", wrapper_with_header)


    local lib_one = darwin.dtw.load_file("dependencies/" .. wrapper_name .. "one.c")
    local wrapper_one = lib_one.. "\n".. wrapper_source 
    darwin.dtw.write_file("release/" .. wrapper_name .. "_one.c", wrapper_one)

end

function wrappers()


    build_wrapper("BearHttpsClient")
    build_wrapper("CArgvParse")
    build_wrapper("CWebStudio")
    darwin.dtw.copy_any_overwriting("wrapers/std.c", "release/std.c")
    

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
    callback = wrappers
})
