/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_BUILDING_BASE_CELL_LAYOUT_H_INCLUDED__
#define __SQC_SHOP_BUILDING_BASE_CELL_LAYOUT_H_INCLUDED__

#include "sqc_item_price_widget_layout.h"
#include "sqc_item_buttons_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace shop_building_base_cell {
	
    // spinboard cell background
    
    static const int backing_w[] = { 133, 266, 155 };
    static const int backing_h[] = { 82, 162, 112 };

    static const int ctrls_offset[] = { 6, 2*6, 7 };
    
    static const sqc_shop_item_button_layout
    cell_background_btn( // layout by spinboard cell
        layout_alignment( layout_halignment_center |
                      layout_valignment_bottom),
        image_rects( layout_rect( 0, 42, backing_w[0], backing_h[0] ),
                     layout_rect( 0, 2*42, backing_w[1], backing_h[1] ),
                     layout_rect( 0, 70, backing_w[2], backing_h[2] ) ) );
    
    static const layout_alignment // layout by background image
    properties_layout( layout_halignment_center |
                       layout_valignment_center);
    
    static const layout_rects
    properties_rects( layout_rect( 0, 0, backing_w[0], backing_h[0] ),
                layout_rect( 0, 0, backing_w[1], backing_h[1] ),
                layout_rect( 0, 0, backing_w[2], backing_h[2] ) );
    
    
    // spinboard cell item image alignment
    static const layout_alignment
    cell_item_image_alignment( layout_halignment_center |
                              layout_valignment_center);
    
    // spinboard cell item image rect
    static const image_rects
    cell_item_image_rects(
                          layout_rect( 0, 0, 60, 60 ),
                          layout_rect( 0, 0, 2*60, 2*60 ),
                          layout_rect( 0, 0, 68, 68 ) );
    
    // spinboard cell item name font
    static const font_layout 
    cell_item_name_font( 
        layout_font_name( "Arial.otf" ), //Arial
        layout_font_sizes( 12, 2*12, 18 ) );

    // spinboard cell item name
    static const label_layout
    cell_item_name_label( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                 layout_valignment_bottom ),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        cell_item_name_font,
        label_rects(
             layout_rect( ctrls_offset[0], 123, backing_w[0], 28 ),
             layout_rect( ctrls_offset[1], 2*123, backing_w[1], 2*28 ),
             layout_rect( ctrls_offset[2], 200, backing_w[2], 60 ) ) );

    
    // error font
    static const font_layout 
    cell_error_font( 
                    layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                    layout_font_sizes( 12, 2*12, 12 ) ); 
    
    //////////////////////////////////////////////////////////
    //  error label
    
    // spinboard cell error label
    static const label_layout
    cell_error_label( // layout by spinboard cell
        layout_alignment( layout_halignment_fill |
                     layout_valignment_bottom ),
        layout_string_resource( "", "" ),
        layout_black_color,
        draw_flags_hcenter_vcenter,
        cell_error_font,
        label_rects(
                 layout_rect( 0, 0, 0, 24 ),
                 layout_rect( 0, 0, 0, 48 ),
                 layout_rect( 0, 0, 0, 30 ) ) );
    
    static const image_layout 
    cell_error_image( // layout by spinboard cell
        layout_alignment( layout_halignment_center |
                        layout_valignment_center),
        image_names( "lock",
                    "lock",
                    "lock" ),
        image_rects( 
            layout_rect( 0, 0, 33, 39 ),
            layout_rect( 0, 0, 33, 39 ),
            layout_rect( 0, 0, 33, 39 ) ) );
    

    
    /////////////////////////////////////////////////////////////////////////////
    // price in coins and bucks
    static const layout_alignment
    price_widget_alignment( layout_halignment_left |
                                layout_valignment_bottom);

    static const layout_rects
    price_widget_rects( 
                layout_rect( ctrls_offset[0], 26, item_price_widget::width[0], item_price_widget::height[0] ),
                layout_rect( ctrls_offset[1], 2*26, item_price_widget::width[1], item_price_widget::height[1] ),
                layout_rect( ctrls_offset[2], 40, item_price_widget::width[2], item_price_widget::height[2] ) );
    
    /////////////////////////////////////////////////////////////////////////////
    // buy and gift buttons
    
    // static const int ctrls_offset[] = { 6, 2*6, 7 };
    
    static const int buy_buttons_y[] = { 0, 0, 0 };
    
    static const layout_rects
    ask_button_rect( layout_rect( ctrls_offset[0], buy_buttons_y[0], item_buttons::width[0], item_buttons::height[0] ),
                    layout_rect( ctrls_offset[1], buy_buttons_y[1], item_buttons::width[1], item_buttons::height[1] ),
                    layout_rect( ctrls_offset[2], buy_buttons_y[2], item_buttons::width[2], item_buttons::height[2] ) );
    
    static const layout_rects
    buy_button_rect( layout_rect( ctrls_offset[0], buy_buttons_y[0], item_buttons::width[0], item_buttons::height[0] ),
                     layout_rect( ctrls_offset[1], buy_buttons_y[1], item_buttons::width[1], item_buttons::height[1] ),
                     layout_rect( ctrls_offset[2], buy_buttons_y[2], item_buttons::width[2], item_buttons::height[2] ) );
    
    static const layout_rects
    buy_center_button_rect( layout_rect( 0, buy_buttons_y[0], item_buttons::width[0], item_buttons::height[0] ),
                           layout_rect( 0, buy_buttons_y[1], item_buttons::width[1], item_buttons::height[1] ),
                           layout_rect( 0, buy_buttons_y[2], item_buttons::width[2], item_buttons::height[2] ) );
    
    static const layout_alignment
    ask_button_alignment( layout_halignment_left |
                        layout_valignment_bottom );
    
    static const layout_alignment
    buy_button_alignment( layout_halignment_right |
                         layout_valignment_bottom );
    
    static const layout_alignment
    buy_button_center_alignment( layout_halignment_center |
                               layout_valignment_bottom );
    
    ///////////////////////////////////////////////////////////////////////
    // spinboard cell separator
    static const vertical_separator_layout spinboard_cell_separator( 
                                                                    layout_alignment( layout_halignment_right ),
																	separator_offsets( 0,0,0) );
  
    
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_BUILDING_BASE_CELL_LAYOUT_H_INCLUDED__


