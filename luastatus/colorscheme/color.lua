package.path = package.path .. ";" .. os.getenv("HOME") .. "/.config/dwm/luastatus/colorscheme/?.lua"

local color = require("gruvbox")

return color
