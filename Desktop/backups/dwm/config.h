/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */

/* default gaps */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */

/* systray options */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;           /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int showsystray        = 1;     /* 0 means no systray */

/* status bar option */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */

/* fonst for status bar and dmenu */
static const char *fonts[]          = { "Maple Mono NF:size=11" };
static const char dmenufont[]       = "Maple Mono NF:style=Italic:size=11";

/* color options for different stuff */
static char normbgcolor[]           = "#222222";
static char normbordercolor[]       = "#444444";
static char normfgcolor[]           = "#bbbbbb";
static char selfgcolor[]            = "#eeeeee";
static char selbordercolor[]        = "#005577";
static char selbgcolor[]            = "#005577";
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },

//	bar colors
//			{foreground,background,not used but cannot be empty}
       [SchemeStatus]  = { normfgcolor, normbgcolor,  "#000000"  }, // Statusbar right
       [SchemeTagsSel]  = { selfgcolor, selbgcolor,  "#000000"  }, // Tagbar left selected
       [SchemeTagsNorm]  = { normfgcolor, normbgcolor,  "#000000"  }, // Tagbar left unselected
       [SchemeInfoSel]  = { selfgcolor, selbgcolor,  "#000000"  }, // infobar middle  selected
       [SchemeInfoNorm]  = { normfgcolor, normbgcolor,  "#000000"  }, // infobar middle  unselected
};

void
togglesystray(const Arg *arg){
		showsystray=showsystray^0;
}

/* autostart but coll, Im not using xinitrc or startx but rather ly lmao */
static const char *const autostart[] = {
       "picom", NULL,
       "wal", "-i", "wha.png", NULL,
	   "keepassxc", NULL,
       "nm-applet", NULL,
       "snixembed", NULL,
       "safeeyes", NULL,
	   "mpd", NULL,
	   "mpDris2", NULL,
       NULL /* terminate */
};


/* tags */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* rules for specific windows, useful for smooth workflows */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c" /* vanity gaps is very useful if you like various layouts */

static const Layout layouts[] = {
	/* symbol     arrange function */
    /* first entry is default */
 	{ " ",      spiral },
 	{ "󱥦 ",     dwindle },
	{ " ",      tile },    
 	{ "󱢡 ",      deck },
 	{ "󰋁 ",      nrowgrid },
	{ " ",      monocle },
 	{ " ",      bstack },
 	{ "󰛻 ",      bstackhoriz },
 	{ "󱇙 ",      grid },
 	{ " ",      horizgrid },
 	{ "󰝘 ",      gaplessgrid },
 	{ " ",      centeredmaster },
 	{ "󱇜 ",      centeredfloatingmaster },
 	{ " ",      NULL },    /* no layout function means floating behavior */
 	{ NULL,       NULL },
};

/* mod key definition */
#define MODKEY Mod4Mask

/* order that are repeated for every tag key,. useful macro */
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* actually dwmblocks-async that's cool */
#define STATUSBAR "dwmblocks"

/* commands */
/* demnu commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };

/*mpdcontrol can be achieved withouth patches if using certain clients but this is more flexible */
#include "mpdcontrol.c"

/* movestacks gives you more control over the stack and works with every layout, but you can choose not to use it */
#include "movestack.c"

/*key definitions */
static const Key keys[] = {
	/* modifier                     key        function        argument */
		/* command and app launch keys */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY, 	                	XK_Return, spawn,          {.v = (const char*[]){"kitty", NULL }} },
	{ MODKEY, 	                	XK_n, 	   spawn,          {.v = (const char*[]){"librewolf", NULL }} },
	{ MODKEY|ShiftMask, 	       	XK_t, 	   togglesystray,  {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },

	/* stack and master areas manipulation, useful for tiled and deck manipulation */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	/* gaps control useful for certain workflows */
	{ MODKEY|ControlMask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|ControlMask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|ControlMask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|ControlMask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|ControlMask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	/* shift for kill client was annoying */
	{ MODKEY,             			XK_q,      killclient,     {0} },

	/* layout manipulation */
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,						XK_f,	   togglefullscreen, {0} },

	/* Monitor manipulation with xinerama */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* xrdb patch and reaload */
	{ MODKEY,                       XK_F5,     xrdb,           {.v = NULL } },

	/* Universal tags viewing and manipulation you can even put a window accross every tag */
	{ MODKEY,                       XK_Tab,    view,           {0} },

	/* Especific tag viewing, done through the definition above */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* restart and quit options */
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_c,      quit,           {1} }, 

	/* music manipulation from keyboard, is cool */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
		/* tag manipulation through key+mouse combo and status bar*/
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },

	/* client windows manipulation using keyboard+mouse useful for arpid floating and zooming */
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },

	/* dwmblocks for the status bar, the cool part */
    { ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
    { ClkStatusText,        MODKEY,         Button2,        sigstatusbar,   {.i = 6} },
    { ClkStatusText,        MODKEY,         Button1,        sigstatusbar,   {.i = 7} },
    { ClkStatusText,        MODKEY,         Button3,        sigstatusbar,   {.i = 8} },
};

