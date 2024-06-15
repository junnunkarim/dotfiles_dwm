/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
/* This allows the bar border size to be explicitly set separately from borderpx.
 * If left as 0 then it will default to the borderpx value of the monitor and will
 * automatically update with setborderpx. */
static const unsigned int barborderpx    = 0;  /* border pixel of bar */
static const unsigned int snap           = 32;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const char autostartblocksh[]     = "autostart_blocking.sh";
static const char autostartsh[]          = "autostart.sh";
static const char dwmdir[]               = "scripts";
static const char localshare[]           = ".config/dwm";
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const char buttonbar[]            = "󰕰";
static const unsigned int systrayspacing = 10;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */
static const unsigned int ulinepad = 6;         /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;     /* thickness / height of the underline */
static const unsigned int ulinevoffset = 0;     /* how far above the bottom of the bar the line should appear */
static const int ulineall = 0;                  /* 1 to show underline on all tags, 0 for just the active ones */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_LARGER_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_BOTTOM_BAR_SLIM;
static const int quit_empty_window_count = 1;   /* only allow dwm to quit if no (<= count) windows are open */
static const char *fonts[]               = {
	"Iosevka Term:style=medium:size=15",
	"Iosevka Nerd Font Mono:style=medium:size=24",
};
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static char scratchselfgcolor[]          = "#FFF7D4";
static char scratchselbgcolor[]          = "#77547E";
static char scratchselbordercolor[]      = "#894B9F";
static char scratchselfloatcolor[]       = "#894B9F";

static char scratchnormfgcolor[]         = "#FFF7D4";
static char scratchnormbgcolor[]         = "#664C67";
static char scratchnormbordercolor[]     = "#77547E";
static char scratchnormfloatcolor[]      = "#77547E";

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },
	[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
};

static const char *scratch_term[] = {"s", "konsole", "--name", "scratch_term", NULL};
static const char *scratch_pass[] = {"w", "keepassxc", NULL};
static const char *scratch_top[] = {"t", "kitty", "--class", "scratch_top", "-e", "btop", NULL};


/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "", "󰅨", "󰉋", "", "", "", "󰍡", "󰊖", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)

	//RULE(.class = "Alacritty", .isfloating = 0)
	RULE(.class = "konsole", .isfloating = 1)
	RULE(.class = "Gpick", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Lxappearance", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Xfce-polkit", .isfloating = 1, .iscentered = 1)
	RULE(.class = "Protonvpn", .isfloating = 1)
	RULE(.class = "KeePassXC", .isfloating = 1, .iscentered = 1)

	RULE(.class = "kitty", .tags = 1 << 0, .switchtag = 1) // tag-1
	RULE(.class = "term_top", .tags = 1 << 0, .switchtag = 1) // tag-1
	RULE(.class = "Alacritty", .tags = 1 << 0, .switchtag = 1) // tag-1
	RULE(.class = "st-256color", .tags = 1 << 0, .switchtag = 1) // tag-1
	RULE(.class = "org.wezfurlong.wezterm", .tags = 1 << 0, .switchtag = 1) // tag-1

	RULE(.class = "Geany", .tags = 1 << 1, .switchtag = 1)
	RULE(.class = "code-oss", .tags = 1 << 1, .switchtag = 1)
	RULE(.class = "Emacs", .tags = 1 << 1, .switchtag = 1)
	RULE(.class = "term_nvim", .tags = 1 << 1, .switchtag = 1)
	RULE(.class = "jetbrains-idea-ce", .tags = 1 << 1, .switchtag = 1, .iscentered = 1)
	RULE(.class = "jetbrains-pycharm", .tags = 1 << 1, .switchtag = 1, .iscentered = 1)
	RULE(.class = "jetbrains-dataspell", .tags = 1 << 1, .switchtag = 1, .iscentered = 1)

	RULE(.class = "Thunar", .tags = 1 << 2, .switchtag = 1, .iscentered = 1) // tag-3
	RULE(.class = "Pcmanfm", .tags = 1 << 2, .switchtag = 1) // tag-3
	RULE(.class = "term_felix", .tags = 1 << 2, .switchtag = 1) // tag-3
	RULE(.class = "qBittorrent", .tags = 1 << 2, .switchtag = 1)

	RULE(.class = "Chromium", .tags = 1 << 3, .switchtag = 1, .iscentered = 1) // tag-4
	RULE(.class = "firefox", .tags = 1 << 3, .switchtag = 1, .iscentered = 1)
	RULE(.class = "Nyxt", .tags = 1 << 3, .switchtag = 1) // tag-4
	RULE(.class = "Vieb", .tags = 1 << 3, .switchtag = 1)

	RULE(.class = "Gimp", .tags = 1 << 4, .switchtag = 1, .isfloating = 1, .iscentered = 1) // tag-5
	RULE(.class = "obs", .tags = 1 << 4, .switchtag = 1, .iscentered = 1)
	RULE(.class = "vlc", .tags = 1 << 4, .switchtag = 1)
	RULE(.class = "mpv", .tags = 1 << 4, .switchtag = 1)

	RULE(.class = "calibre", .tags = 1 << 5, .switchtag = 1) // tag-6
	RULE(.class = "Zathura", .tags = 1 << 5, .switchtag = 1) // tag-6
	RULE(.class = "sioyek", .tags = 1 << 5, .switchtag = 1) // tag-6
	RULE(.class = "DesktopEditors", .tags = 1 << 5, .switchtag = 1) // tag-6

	RULE(.class = "KotatogramDesktop", .tags = 1 << 6, .switchtag = 1) // tag-7
	RULE(.class = "TelegramDesktop", .tags = 1 << 6, .switchtag = 1) // tag-7
	
	RULE(.class = "Ryujinx", .tags = 1 << 7, .switchtag = 1, .isfloating = 1) // tag-8
	RULE(.class = "yuzu", .tags = 1 << 7, .switchtag = 1, .isfloating = 1) // tag-8
	RULE(.class = "retroarch", .tags = 1 << 7, .switchtag = 1, .isfloating = 0) // tag-8

	RULE(.class = "GParted", .tags = 1 << 8, .switchtag = 1, .isfloating = 1, .iscentered = 1) // tag-9
	RULE(.class = "lxappearance", .tags = 1 << 8, .switchtag = 1, .isfloating = 1, .iscentered = 1) // tag-9
	RULE(.class = "Virt-manager", .tags = 1 << 8, .switchtag = 1, .isfloating = 1, .iscentered = 1) // tag-9
	RULE(.class = "Xfce4-power-manager-settings", .tags = 1 << 8, .switchtag = 1, .isfloating = 1, .iscentered = 1)

  // scratchpads
	RULE(.instance = "scratch_term", .scratchkey = 's', .isfloating = 1, .iscentered = 1)
	RULE(.instance = "keepassxc", .scratchkey = 'w', .isfloating = 1, .iscentered = 1)
	RULE(.instance = "scratch_top", .scratchkey = 't', .isfloating = 1, .iscentered = 1)

};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{  0,        0,     BAR_ALIGN_LEFT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status2d,           draw_status2d,          click_status2d,          NULL,                    "status2d" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[M]",    monocle },
	{ "",      tile },    /* first entry is default */
	{ "[D]",    deck },
	{ "",      bstack },
	{ "󰾍",      horizgrid },
	{ "",      centeredfloatingmaster },
	{ "",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      combotag,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_Tab,   ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = INC(-1) } }, \
  /* 
	{ MOD, XK_s,     ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_w,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_e,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_a,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_z,     ACTION##stack, {.i = -1 } },
  */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static const char *dmenucmd[] = {
// 	"dmenu_run",
// 	"-fn", dmenufont,
// 	"-nb", normbgcolor,
// 	"-nf", normfgcolor,
// 	"-sb", selbgcolor,
// 	"-sf", selfgcolor,
// 	NULL
// };

// commands to execute
static const char *termcmd[]  = { "kitty", NULL };
static const char *network_manager_cmd[]  = { "networkmanager_dmenu", NULL };
static const char *lock_cmd[]  = { "betterlockscreen", "-l", NULL };

static const char *popup_colorscheme_changer_cmd[]  = { ".bin/window_manager/change_colorscheme.py", "-w", "dwm", "-m", "dmenu", NULL };
static const char *keybindings_cmd[]  = { ".config/dwm/scripts/keymaps", NULL };
static const char *powermenu_cmd[]  = { ".bin/window_manager/popup_powermenu.py", "-w", "dwm", "-m", "dmenu", NULL };
static const char *popup_launcher_cmd[]  = { ".bin/window_manager/popup_launcher.py", "-w", "dwm", "-m", "dmenu", NULL };
static const char *popup_clip_cmd[]  = { ".bin/window_manager/popup_clipboard.py", "-w", "dwm", "-m", "dmenu", NULL };
static const char *rofi_calc_cmd[]  = { ".config/dwm/scripts/rofi_calc", NULL };
static const char *rofi_emoji_cmd[]  = { ".config/dwm/scripts/rofi_emoji", NULL };
static const char *rofi_buku_cmd[]  = { ".config/dwm/scripts/rofi_buku", NULL };

static const char *file_cmd[]  = { "thunar", NULL };
static const char *firefox_cmd[]  = { "firefox", NULL };
static const char *chromium_cmd[]  = { "chromium", NULL };

static const char *file_cli_cmd[]  = { "kitty", "--class", "term_felix", "-e", "fx", NULL };
static const char *nvim_cmd[]  = { "kitty", "--class", "term_nvim", "-e", "nvim", NULL };

// for special keyboard keys
#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key            function                argument */
  //--------------------------------------------------------------//
 //---------- Other programs or scripts (super + ctrl) ----------//
  { MODKEY | ControlMask,         XK_r,          spawn,                  SHCMD("redshift -P -O 5000") }, //desc: turn on bluelight filter (low)
  { MODKEY | ControlMask,         XK_n,          spawn,                  SHCMD("redshift -x") }, //desc: turn off bluelight filter
  { MODKEY | ControlMask,         XK_v,          spawn,                  SHCMD("redshift -P -O 3500") }, //desc: turn off bluelight filter (high)
  { MODKEY | ControlMask,         XK_p,          spawn,                  SHCMD("picom") }, //desc: turn on compositor (picom)
  { MODKEY | ControlMask,         XK_u,          spawn,                  SHCMD("pkill picom") }, //desc: turn off compositor (picom)
  { MODKEY | ControlMask,         XK_g,          spawn,                  SHCMD("gpick -p") }, //desc: open color picker (gpick)
 
   //------------------------------------------------//
  //---------- Applications (super + alt) ----------//
  { MODKEY | ALTKEY,              XK_t,          spawn,                  {.v = file_cmd } }, //desc: open file manager (thunar)
  { MODKEY | ALTKEY,              XK_f,          spawn,                  {.v = file_cli_cmd } }, //desc: open cli file manager (felix)
  { MODKEY | ALTKEY,              XK_b,          spawn,                  {.v = chromium_cmd } }, //desc: open browser (chromium)
  { MODKEY | ALTKEY,              XK_e,          spawn,                  {.v = firefox_cmd } }, //desc: open browser (firefox)
  { MODKEY | ALTKEY,              XK_v,          spawn,                  {.v = nvim_cmd } }, //desc: open code editor (neovim)

  { 0,                            XK_Print,      spawn,                  SHCMD("flameshot full -p $HOME/Pictures/SS/") }, //desc: take fullscreen screenshot
  { MODKEY,                       XK_Print,      spawn,                  SHCMD("flameshot gui") }, //desc: open screenshot selection gui (flameshot)
  { ALTKEY,                       XK_Print,      spawn,                  SHCMD("flameshot full -d 5000 -p $HOME/Pictures/SS/") }, //desc: take fullscreen screenshot after 5 sec
  { ShiftMask,                    XK_Print,      spawn,                  SHCMD("flameshot full -d 10000 -p $HOME/Pictures/SS/") }, //desc: take fullscreen screenshot after 10 sec

  { 0,              XF86XK_MonBrightnessDown,    spawn,                  SHCMD("brightnessctl -d \"intel_backlight\" set 2%-") },
  { MODKEY,                       XK_F1,         spawn,                  SHCMD("brightnessctl -d \"intel_backlight\" set 2%-") }, //desc: decrease brightness
  { 0,              XF86XK_MonBrightnessUp,      spawn,                  SHCMD("brightnessctl -d \"intel_backlight\" set +2%") },
  { MODKEY,                       XK_F2,         spawn,                  SHCMD("brightnessctl -d \"intel_backlight\" set +2%") }, //desc: increase brightness

  { 0,              XF86XK_AudioLowerVolume,     spawn,                  SHCMD("pulsemixer --change-volume -5 --max-volume 100") },
  { 0,              XF86XK_AudioRaiseVolume,     spawn,                  SHCMD("pulsemixer --change-volume +5 --max-volume 100") },
  { 0,              XF86XK_AudioMute,            spawn,                  SHCMD("pulsemixer --toggle-mute") },
  { MODKEY,                       XK_F5,         spawn,                  SHCMD("pulsemixer --change-volume -5 --max-volume 100") }, //desc: decrease volume (system)
  { MODKEY,                       XK_F6,         spawn,                  SHCMD("pulsemixer --change-volume +5 --max-volume 100") }, //desc: increase volume (system)
  { MODKEY,                       XK_F7,         spawn,                  SHCMD("pulsemixer --toggle-mute") }, //desc: mute system volume

  { MODKEY,                       XK_F9,         spawn,                  SHCMD("nmcli radio all on && notify-send \"Turned on wifi\"") }, //desc: turn on wifi
  { MODKEY,                       XK_F10,        spawn,                  SHCMD("nmcli radio all off && notify-send \"Turned off wifi\"") }, //desc: turn off wifi

   //--------------------------------------------------------------//
  //---------- System shortcuts (super / super + shift) ----------//
	{ MODKEY,                       XK_Return,     spawn,                  {.v = termcmd } }, //desc: open terminal
	{ MODKEY,                       XK_l,          spawn,                  {.v = lock_cmd } }, //desc: lock screen
	{ MODKEY,                       XK_n,          spawn,                  {.v = network_manager_cmd } }, //desc: open network manager (dmenu)

	// { MODKEY | ShiftMask,           XK_Return,     spawn,                  {.v = scratchpad_cmd } },
	// { MODKEY | ShiftMask,           XK_BackSpace,  spawn,                  {.v = scratchpad_pass_cmd } },
	{ MODKEY,                       XK_t,          spawn,                  {.v = popup_colorscheme_changer_cmd } }, //desc: open colorscheme menu (dmenu)
	{ MODKEY,                       XK_k,          spawn,                  {.v = keybindings_cmd } }, //desc: show all keybindings (dmenu)
	{ MODKEY,                       XK_x,          spawn,                  {.v = powermenu_cmd } }, //desc: open powermenu (dmenu)
	{ MODKEY,                       XK_d,          spawn,                  {.v = popup_launcher_cmd } }, //desc: open application launcher (dmenu)
	{ MODKEY,                       XK_r,          spawn,                  {.v = rofi_calc_cmd } }, //desc: open calculator (dmenu)
	{ MODKEY,                       XK_h,          spawn,                  {.v = popup_clip_cmd } }, //desc: open clipboard (dmenu)
	{ MODKEY,                       XK_e,          spawn,                  {.v = rofi_emoji_cmd } }, //desc: show all emoji (dmenu)
	{ MODKEY,                       XK_m,          spawn,                  {.v = rofi_buku_cmd } }, //desc: open bookmark manager (dmenu) (buku)

	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY|ShiftMask,             XK_b,          toggletopbar,           {0} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },

	// { MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	// { MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_Left,       setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_Right,      setmfact,               {.f = +0.05} },

	{ MODKEY,                       XK_0,          togglegaps,             {0} },
	// { MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	// { MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },

	// sets ALTKEY as modifier instead of MODKEY in Stacker function
  // allows cycling through focus using ALTKEY
	STACKKEYS(ALTKEY,                              focus)
  // allows moving through clients using ALTKEY
	STACKKEYS(ALTKEY|ShiftMask,                    push)
	{ MODKEY,                       XK_Tab,        shiftviewclients,       { .i = +1 } },
	{ MODKEY,                       XK_grave,      shiftviewclients,       { .i = -1 } },

	{ MODKEY,                       XK_i,          showhideclient,         {0} },

	{ MODKEY,                       XK_c,          killclient,             {0} },
  // quit dwm
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
  // restart dwm
	{ MODKEY|ShiftMask,             XK_r,          quit,                   {1} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },

	{ MODKEY|ShiftMask,             XK_f,          togglefloating,         {0} },

	{ MODKEY|ShiftMask,             XK_Return,     togglescratch,          {.v = scratch_term } },
	{ MODKEY|ShiftMask,             XK_BackSpace,  togglescratch,          {.v = scratch_pass } },
	{ MODKEY|ShiftMask,             XK_h,          togglescratch,          {.v = scratch_top } },
	// { MODKEY|ControlMask,           XK_grave,      setscratch,             {.v = scratchpadcmd } },
	// { MODKEY|ShiftMask,             XK_grave,      removescratch,          {.v = scratchpadcmd } },

	{ MODKEY,                       XK_f,          togglefullscreen,       {0} },

	// { MODKEY,                       XK_Tab,        view,                   {0} },

	// { MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	// { MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	// { MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	// { MODKEY,                       XK_space,      setlayout,              {0} },

	// { MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },

  // multi-monitor related
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },

	{ MODKEY|ShiftMask|ControlMask, XK_space,      cyclelayout,            {.i = -1 } },
	{ MODKEY|ControlMask,           XK_space,      cyclelayout,            {.i = +1 } },

	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkButton,            0,                   Button1,        spawn,          {.v = popup_launcher_cmd } },

	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },

	{ ClkWinTitle,          0,                   Button1,        showhideclient, {0} },
	{ ClkWinTitle,          0,                   Button3,        togglewin,      {0} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },

	{ ClkStatusText,        0,                   Button1,        spawn,          {.v = powermenu_cmd } },
	/* placemouse options, choose which feels more natural:
	 *    0 - tiled position is relative to mouse cursor
	 *    1 - tiled postiion is relative to window center
	 *    2 - mouse pointer warps to window center
	 *
	 * The moveorplace uses movemouse or placemouse depending on the floating state
	 * of the selected client. Set up individual keybindings for the two if you want
	 * to control these separately (i.e. to retain the feature to move a tiled window
	 * into a floating position).
	 */
	{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = 0} },
	{ 2,            xrdb,           {.v = 0} },
};
