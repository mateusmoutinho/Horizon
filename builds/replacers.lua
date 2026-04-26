
function build_docs()


    local internal_files = darwin.dtw.list_files_recursively("internal")

    for i=1,#internal_files do

        local current_file = internal_files[i]
        
        local content = darwin.dtw.load_file("internal/" .. current_file)
        -- aply the replacers var 
        for key, value in pairs(REPLCERS) do
            content = string.gsub(content, key, value)
        end
        
        darwin.dtw.write_file(current_file, content)
    end
end


darwin.add_recipe({
    inputs = {
        "replacers"
    },
    outs = {},
    name = "generate-docs",
    description = "Generate documentation files",
    callback = build_docs
})
