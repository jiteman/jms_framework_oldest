/*
 *  sqc_theme_elements.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/23/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_THEME_ELEMENTS_H_INCLUDED
#define SQC_THEME_ELEMENTS_H_INCLUDED

#include "framework/sqc_framework_defs.h"
#include "milk/milk_defs.h"

NAMESPACE_SQC_FRAMEWORK

enum sqc_theme_button_type {
	sqc_theme_button_buy = milk::theme_button_game_specific_first,
	sqc_theme_button_buy_gray,
	sqc_theme_button_gift,
	sqc_theme_button_gift_gray,
	sqc_theme_button_add_coins,
	sqc_theme_button_shop_item,
    sqc_theme_button_sell,
    sqc_theme_button_sell_gray,
    sqc_theme_button_received,
    sqc_theme_button_ask, // to do
    sqc_theme_button_apply,
	sqc_theme_button_game_specific_first	///< always last element
};

class sqc_theme_button_layout : public theme_button_layout {
public:
	sqc_theme_button_layout( const layout_alignment& alignment, 
							 const sqc_theme_button_type type,
							 const label_rects& rects )
	: theme_button_layout( alignment, static_cast<milk::theme_button_type> (type),rects ) {
	}
};

class sqc_shop_item_button_layout : public theme_button_layout {
public:
	sqc_shop_item_button_layout( const layout_alignment& alignment, 
							const label_rects& rects )
	: theme_button_layout( alignment, static_cast<milk::theme_button_type> (sqc_theme_button_shop_item),rects ) {
	}
};

enum sqc_bevel_type {
	sqc_bevel_type_shop_item = milk::milk_bevel_type_game_specific_first,	///< bevel for shop item
	sqc_bevel_type_game_specific_first
};

class sqc_shop_item_bevel_layout : public base_bevel_layout {
public:
	sqc_shop_item_bevel_layout( const layout_alignment& alignment,
							  const bevel_rects& rects )
	: base_bevel_layout( alignment,rects, milk::milk_bevel_type(sqc_bevel_type_shop_item) ) {
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif /*SQC_THEME_ELEMENTS_H_INCLUDED*/