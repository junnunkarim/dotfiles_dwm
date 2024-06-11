package.path = package.path .. ";" .. os.getenv("HOME") .. "/.config/dwm/luastatus/colorscheme/?.lua"
local color = require("color")

local time = string.format(
	"%s",
	os.date(
		color.sep .. color.time_ic_fg .. color.time_ic_bg .. " 󰥔 " .. color.time_fg .. color.time_bg .. " %I:%M %p "
	)
) -- time

local date = string.format(
	"%s",
	os.date(
		color.sep .. color.date_ic_fg .. color.date_ic_bg .. "  " .. color.date_fg .. color.date_bg .. " %a, %d %b "
	)
) --date

widget = {
	plugin = "timer",
	cb = function()
		return { time, date }
	end,
}
