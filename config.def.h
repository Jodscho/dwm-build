/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 15;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int user_bh            = 30;
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad            = 0;       /* vertical padding of bar */
static const int sidepad            = 0;       /* horizontal padding of bar */
//static const int vertpad            = 10;       /* vertical padding of bar */
//static const int sidepad            = 15;       /* horizontal padding of bar */
static const char *fonts[]          = { "DejaVuSansMono-Bold:size=10" };
static const char dmenufont[]       = "DejaVuSansMono-Bold:size=10";
//static const char bg[]       = "#222222";
static const char col_bg[]       = "#222222";
static const char col_border_active[]        = "#e7bd92";
static const char col_fg[]       = "#e18d30";
static const char color_location[] = "/home/jonathan/.config/colors/colors";

static char color0[] = "#151219";
static char color1[] = "#675F58";
static char color2[] = "#6E6F6C";
static char color3[] = "#8A7565";
static char color4[] = "#7D827E";
static char color5[] = "#968A76";
static char color6[] = "#C8A378";
static char color7[] = "#c5c3bc";
static char color8[] = "#898883";
static char color9[] = "#675F58";
static char color10[] = "#6E6F6C";
static char color11[] = "#8A7565";
static char color12[] = "#7D827E";
static char color13[] = "#968A76";
static char color14[] = "#C8A378";
static char color15[] = "#c5c3bc";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = {color7, color0, color0 },
	[SchemeSel]  = { color1, color0,  color1  },
    [SchemeStatus]  = { color7, color0,  "#000000"  },
    // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel]  = { color7, color0,  "#000000"  },
    // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { color2, color0,  "#000000"  },
    // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { color7, color0,  "#000000"  },
    // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { color7, color0,  "#000000"  },
    // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
static const char *tags[] = { "1", "2", "", "", "", "", "7", "8", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,       1,           -1 },
	{ "firefox",  NULL,       NULL,       1 << 8,       0,      0,           -1 },
	{ "st-256color",  NULL,       "helper_notes.sh",       0,       1,        1,           -1 },
	{ "TelegramDesktop",  NULL,    NULL,       1 << 2,       1,        1,           -1 },
	{ "st-256color",  "st-256color",    "ranger",       1 << 5,       0,        0,           -1 },
	{ "Thunderbird",  NULL,    NULL,       1 << 3,       1,        1,           -1 },
	{ "st-256color",  "st-256color",    "cmus",       1 << 4,       1,        1,           -1 },
	{ "flameshot",  "flameshot", NULL,       0,       0,        1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

//static const Layout layouts[] = {
//	/* symbol     arrange function */
//	{ "[]=",      tile },    /* first entry is default */
//	{ "><>",      NULL },    /* no layout function means floating behavior */
//	{ "[M]",      monocle },
//};
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "| ",      tile },    /* first entry is default */
	{ "| ",      NULL },    /* no layout function means floating behavior */
	{ "| ",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };

#include "movestack.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

