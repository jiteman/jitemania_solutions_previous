for too slow git:
cmder/vednor/clink.lua

---
-- Get the status of working dir
-- @return {bool}
---
local function get_git_status()
    --- local file = io.popen("git --no-optional-locks status --porcelain 2>nul")
	local file = io.popen("git --ignore-submodules --no-optional-locks status --porcelain 2>nul")
    for line in file:lines() do
        file:close()
        return false
    end
    file:close()

    return true
end

---
-- Gets the conflict status
-- @return {bool} indicating true for conflict, false for no conflicts
---
function get_git_conflict()
    --- local file = io.popen("git diff --ignore-submodules --name-only --diff-filter=U 2>nul")
	local file = io.popen("git diff --ignore-submodules --name-only --diff-filter=U 2>nul")
    for line in file:lines() do
        file:close()
        return true;
    end
    file:close()
    return false
end
