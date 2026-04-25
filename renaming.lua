local files = dtw.list_files_recursively("src",true) 
for i = 1, #files do
    local file = files[i] 
    local path = dtw.newPath(file)
    local dir = path.get_dir()
    local name = path.get_name()
    local new_name = string.gsub(name, "horizon", "PROJECT_NAME")
    local new_path = dir .. "/" .. new_name
    dtw.move_any_overwriting(file, new_path)
    -- path.move(new_path)
end