/*
 *  city_shop_contract_cell_layout.h
 *  aCountry
 *
 *  Created by Maxim Korolkov on 06.09.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_CONTRACT_CELL_LAYOUT_H_INCLUDED__
#define __SQC_SHOP_CONTRACT_CELL_LAYOUT_H_INCLUDED__

#include "sqc_item_price_widget_layout.h"
#include "sqc_item_buttons_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace shop_contract_cell {
	
    // spinboard cell background
    
    static const int backing_w[] = { 117, 234, 155 };
    static const int backing_h[] = { 117, 234, 182 };
    
    static const int text_offset_x[] = { 16, 2*16, 10 };

    static const sqc_shop_item_button_layout
    cell_background_btn( // layout by spinboard cell
        layout_alignment( layout_halignment_center |
                      layout_valignment_bottom),
        image_rects( layout_rect( 0, 65, backing_w[0], backing_h[0] ),
                     layout_rect( 0, 2*65, backing_w[1], backing_h[1] ),
                     layout_rect( 0, 90, backing_w[2], backing_h[2] ) ) );
    
    static const layout_alignment
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
    				 layout_rect( 0, 0, 80, 60 ),
                     layout_rect( 0, 0, 2*80, 2*60 ),
                     layout_rect( 0, 0, 90, 68 ) );
    
    // spinboard cell item name font
    static const font_layout 
    cell_item_name_font( 
        layout_font_name( "Arial.otf" ), //ArialMT
        layout_font_sizes( 12, 2*12, 18 ) );

    // spinboard cell coins and bucks font
    static const font_layout 
    cell_error_font( 
                    layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                    layout_font_sizes( 12, 2*12, 12 ) ); 
    
    // spinboard cell item name
    static const label_layout
    cell_item_name_label( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom ),
        layout_string_resource( "", "" ),
        layout_white_color,
        surf::draw_string_alignment_center|
        surf::draw_string_valignment_bottom|
        surf::draw_string_truncation_tail|
        surf::draw_string_multi_line,
        cell_item_name_font,
        label_rects(
            layout_rect( text_offset_x[0], 190, backing_w[0], 40 ),
            layout_rect( text_offset_x[1], 2*190, backing_w[1], 2*40 ),
            layout_rect( text_offset_x[2], 290, backing_w[2], 50 ) ) );

    
    //////////////////////////////////////////////////////////
    //  error label
    
    // spinboard cell error label
    static const label_layout
    cell_error_label( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                     layout_valignment_bottom ),
        layout_string_resource( "", "" ),
        layout_black_color,
        draw_flags_hcenter_vcenter,
        cell_error_font,
        label_rects(
                 layout_rect( text_offset_x[0], 10, backing_w[0], 30 ),
                 layout_rect( text_offset_x[1], 2*10, backing_w[1], 2*30 ),
                 layout_rect( text_offset_x[2], 15, backing_w[2], 40 ) ) );
    
    static const image_layout 
    cell_error_image( // layout by spinboard background image
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
                layout_rect( 10, 40, item_price_widget::width[0], item_price_widget::height[0] ),
                layout_rect( 2*10, 2*40, item_price_widget::width[1], item_price_widget::height[1] ),
                layout_rect( 10, 65 , item_price_widget::width[2], item_price_widget::height[2] ) );
    
    /////////////////////////////////////////////////////////////////////////////
    // buy and gift buttons
    
    static const int buy_buttons_x[] = { 5, 2*5, 7 };
    static const int buy_buttons_y[] = { 10, 2*10, 15 };

    
    static const layout_rects
    buy_button_rect( layout_rect( buy_buttons_x[0], buy_buttons_y[0], item_buttons::width[0], item_buttons::height[0] ),
                    layout_rect( buy_buttons_x[1], buy_buttons_y[1], item_buttons::width[1], item_buttons::height[1] ),
                    layout_rect( buy_buttons_x[2], buy_buttons_y[2], item_buttons::width[2], item_buttons::height[2] ) );

    
    static const layout_rects
    buy_center_button_rect( layout_rect( buy_buttons_x[0], buy_buttons_y[0], item_buttons::width[0], item_buttons::height[0] ),
                           layout_rect( buy_buttons_x[1], buy_buttons_y[1], item_buttons::width[1], item_buttons::height[1] ),
                           layout_rect( buy_buttons_x[2], buy_buttons_y[2], item_buttons::width[2], item_buttons::height[2] ) );
    
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

#endif//__SQC_SHOP_CONTRACT_CELL_LAYOUT_H_INCLUDED__


