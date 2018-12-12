/*
 *  city_bubble.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_bubble.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

static const font_layout title_font_ (
									 layout_font_name( "Arial-BoldMT.otf" ), //
									 layout_font_sizes( 11, 2*11, 13 ) );
static const font_layout text_font_ (
									 layout_font_name( "Arial.otf" ), //
									 layout_font_sizes( 11, 2*11, 13 ) );

static const surf::surf_color fontColor(1,1,1,1);
static const surf::surf_color shadowColor(13.0/255, 104.0/255, 181.0/255, 255.0/255);

static const sqc_bubble_font_layout title_font = {
	title_font_,
	fontColor,
	layout_sizes( layout_size(-1,1),layout_size(-2,2),layout_size(-1,1) ),
	shadowColor,
	surf::draw_string_alignment_center|
	surf::draw_string_valignment_center|
	surf::draw_string_draw_shadow_enabled |
	surf::draw_string_truncation_disabled|
	surf::draw_string_multi_line
};

static const sqc_bubble_font_layout text_font = {
	text_font_,
	fontColor,
	layout_sizes( layout_size(-1,1),layout_size(-2,2),layout_size(-1,1) ),
	shadowColor,
	surf::draw_string_alignment_center|
	surf::draw_string_valignment_center|
	surf::draw_string_draw_shadow_enabled |
	surf::draw_string_truncation_disabled|
	surf::draw_string_multi_line
};

static const sqc_bubble_layout layout = {
	layout_vals(126,126*2,134),
	layout_vals(32,64,32),
	title_font,
	layout_sizes(surf::surf_size(10,10),surf::surf_size(20,20),surf::surf_size(12,12)), 
	{
		layout_vals(2,4,2),
		text_font,
		image_names("bubble_button", "bubble_button@2x", "bubble_button_ipad"),
	}
};






sqc_city_bubble::sqc_city_bubble( milk::milk_widget_ptr parent ) : sqc_bubble( parent , layout)
{
}


END_NAMESPACE_SQC_FRAMEWORK
