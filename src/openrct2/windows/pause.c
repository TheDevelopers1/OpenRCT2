#pragma region Copyright (c) 2014-2016 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#include "../localisation/localisation.h"
#include "../sprites.h"
#include "../interface/themes.h"
#include "../interface/widget.h"
#include "../interface/window.h"

enum WINDOW_PAUSE_WIDGET_IDX {
	WIDX_BACKGROUND,
	WIDX_TITLE,
	WIDX_CLOSE,
};

rct_widget window_pause_widgets[] = {
	{ WWT_FRAME,			0,	0,			199,	0,		200,	0xFFFFFFFF,								STR_NONE },				// panel / background
	{ WWT_CAPTION,			0,	1,			198,	1,		14,		STR_ROLLERCOASTER_TYCOON_2,				STR_WINDOW_TITLE_TIP },	// title bar
	{ WIDGETS_END },
};

static void window_pause_mouseup(rct_window *w, sint32 widgetIndex);
static void window_pause_paint(rct_window *w, rct_drawpixelinfo *dpi);

static rct_window_event_list window_pause_events = {
	NULL,
	window_pause_mouseup,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	window_pause_paint,
	NULL
};

/**
 *
 *  rct2: 0x0066D2AC
 */
void window_pause_open()
{
	rct_window* window;
	
	// Check if window is already open
	window = window_bring_to_front_by_class(WC_PAUSE);
	if (window != NULL)
		return;
	
	window = window_create_centred(
								   200,
								   100,
								   &window_pause_events,
								   WC_PAUSE,
								   0
								   );
	window->widgets = window_pause_widgets;
	window->enabled_widgets = (1 << WIDX_CLOSE);
	
	window_init_scroll_widgets(window);
	window->colours[0] = COLOUR_LIGHT_BLUE;
	window->colours[1] = COLOUR_LIGHT_BLUE;
	window->colours[2] = COLOUR_LIGHT_BLUE;
}

/**
 *
 *  rct2: 0x0066D4D5
 */
static void window_pause_mouseup(rct_window *w, sint32 widgetIndex)
{
	switch (widgetIndex) {
		case WIDX_CLOSE:
			window_close(w);
			break;
	}
}

/**
 *
 *  rct2: 0x0066D321
 */
static void window_pause_paint(rct_window *w, rct_drawpixelinfo *dpi)
{
	sint32 x, y;
	
	window_draw_widgets(w, dpi);
	
	x = w->x + 100;
	y = w->y + 45;
	
	
	gfx_draw_string_centred(dpi, STR_PAUSE, x, y, COLOUR_BLACK, NULL);
	
}
