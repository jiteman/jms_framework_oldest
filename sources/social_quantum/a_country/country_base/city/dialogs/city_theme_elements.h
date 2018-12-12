/*
 *  city_theme_elements.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/9/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CITY_THEME_ELEMENTS_H_INCLUDED
#define CITY_THEME_ELEMENTS_H_INCLUDED

#include "framework/sqc_framework_defs.h"
#include "country_base/dialogs/controls/sqc_theme_elements.h"

NAMESPACE_SQC_FRAMEWORK

/// BUTTONS
enum city_theme_button_type {
	city_theme_button_buy = sqc_theme_button_buy,
	city_theme_button_gift = sqc_theme_button_gift,
    city_theme_button_sell = sqc_theme_button_sell, 
    city_theme_button_received = sqc_theme_button_received,
	city_theme_button_buy_gray = sqc_theme_button_buy_gray,
	city_theme_button_gift_gray = sqc_theme_button_gift_gray,
	city_theme_button_tab = sqc_theme_button_game_specific_first,
};

class city_theme_button_layout : public sqc_theme_button_layout {
public:
	city_theme_button_layout( const layout_alignment& alignment, 
							 const city_theme_button_type type,
							 const label_rects& rects )
	: sqc_theme_button_layout( alignment, static_cast<sqc_theme_button_type> (type),rects ) {
	}
};

class city_tab_button_layout : public city_theme_button_layout {
public:
	city_tab_button_layout( const layout_alignment& alignment, 
							 const label_rects& rects )
	: city_theme_button_layout( alignment, city_theme_button_tab,rects ) {
	}
	explicit city_tab_button_layout( const label_layout& label )
	: city_theme_button_layout( label.alignment(), city_theme_button_tab, label.rects() ) {
	}
};

class city_buy_button_layout : public city_theme_button_layout {
public:
	city_buy_button_layout( const layout_alignment& alignment, 
						   const image_rects& rects )
	: city_theme_button_layout( alignment, city_theme_button_buy,rects ) {
	}
};

typedef city_buy_button_layout city_green_button_layout;


/// SEPARATORS
enum city_separator_types {
	city_separator_type_clear_corners = milk::milk_separator_type_game_specific_first
};
class city_vertical_clear_separator_layout : public vertical_separator_layout {
public:
	city_vertical_clear_separator_layout( const layout_alignment& alignment,
									const separator_offsets& x,
									const separator_offsets& top = separator_offsets(0,0,0),
									const separator_offsets& bottom = separator_offsets(0,0,0) )
	: vertical_separator_layout( alignment,x,top,bottom) {
		m_type = milk::milk_separator_type(city_separator_type_clear_corners);
	}
};
class city_horizontal_clear_separator_layout : public horizontal_separator_layout {
public:
	city_horizontal_clear_separator_layout( const layout_alignment& alignment,
									  const separator_offsets& y,
									  const separator_offsets& left = separator_offsets(0,0,0),
									  const separator_offsets& right = separator_offsets(0,0,0) )
	: horizontal_separator_layout( alignment,y,left,right) {
		m_type = milk::milk_separator_type(city_separator_type_clear_corners);
	}
};

/// dialogs
enum city_dialog_type {
	city_dialog_type_congratulation = milk::milk_dialog_type_game_specific_first
};


END_NAMESPACE_SQC_FRAMEWORK

#endif /*CITY_THEME_ELEMENTS_H_INCLUDED*/
