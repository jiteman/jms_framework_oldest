/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_BUTTONS_LAYOUT_H_INCLUDED__
#define __SQC_ITEM_BUTTONS_LAYOUT_H_INCLUDED__

#include "sqc_theme_elements.h"
#include "../../../../common/framework/layout/sqc_common_resources.h"

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace item_buttons {
	
    static const int width[] = { 64, 130, 78 };
    static const int height[] = { 24, 48, 30 };
    
    // button font
    static const font_layout 
    button_font( 
        layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
        layout_font_sizes( 12, 2*12, 14 ) ); 
    

	/// @todo why is there ?
    static const image_rects
    buy_button_rect( layout_rect( 0, 0, 64, 24 ),
                    layout_rect( 0, 0, 130, 48 ),
                    layout_rect( 0, 0, 78, 30 ) );
                    
                    
    static const image_rects
    sell_button_rect( layout_rect( 0, 0, 64, 24 ),
                    layout_rect( 0, 0, 130, 48 ),
                    layout_rect( 0, 0, 78, 30 ) );
                    
                    
    static const image_rects
    received_button_rect( layout_rect( 0, 0, 64, 24 ),
                     layout_rect( 0, 0, 130, 48 ),
                     layout_rect( 0, 0, 78, 30 ) );
                    
                    
    static const image_rects
    gift_button_rect( layout_rect( 0, 0, 64, 24 ),
                     layout_rect( 0, 0, 130, 48 ),
                     layout_rect( 0, 0, 78, 30 ) );
                     
    static const image_rects
    ask_button_rect( layout_rect( 0, 0, 64, 24 ),
                     layout_rect( 0, 0, 130, 48 ),
                     layout_rect( 0, 0, 78, 30 ) );
    
    
	static const image_rects
    buy_button_text_rect( layout_rect( 0, 2, 64, 24-2 ),
                    layout_rect( 0, 4, 130, 48-4 ),
                    layout_rect( 0, 4, 78, 30-4 ) );
                    
    static const image_rects
    sell_button_text_rect( layout_rect( 0, 2, 64, 24-2 ),
                           layout_rect( 0, 4, 130, 48-4 ),
                           layout_rect( 0, 4, 78, 30-4 ) );
                    
    
    static const image_rects
    gift_button_text_rect( layout_rect( 0, 2, 64, 24-2 ),
                     layout_rect( 0, 4, 130, 48-4 ),
                     layout_rect( 0, 4, 78, 30-4 ) );
                     
    static const image_rects
    ask_button_text_rect( layout_rect( 0, 2, 64, 24-2 ),
                          layout_rect( 0, 4, 130, 48-4 ),
                          layout_rect( 0, 4, 78, 30-4 ) );
                     
    static const image_rects
    received_button_text_rect( layout_rect( 0, 2, 64, 24-2 ),
                              layout_rect( 0, 4, 130, 48-4 ),
                              layout_rect( 0, 4, 78, 30-4 ) );
	
    
    static const layout_alignment 
    button_alignment( layout_halignment_left |
                     layout_valignment_bottom);
    
    // to do
    static const layout_points shadow_offsets( layout_point( -0.5, 1 ),
                                              layout_point( -1, 2 ),
                                              layout_point( -0.75, 1 ));
    
    static const shadow_layout shadow(layout_black_color, shadow_offsets);
    //
    
    /////////////////////////////////////////////////////////
    // buy button
    static const sqc_theme_button_layout
    buy_button(
        button_alignment,
		sqc_theme_button_buy,
        buy_button_rect );
    
    static const label_layout
    buy_button_label(
        button_alignment,
        common_resources::string_text_buy,                                        
        layout_white_color,
        draw_flags_hcenter_vcenter,
        button_font,
        buy_button_text_rect,
        shadow);
        
    /////////////////////////////////////////////////////////
    // sell button
    static const sqc_theme_button_layout
    sell_button(
               button_alignment,
               sqc_theme_button_sell,
               sell_button_rect );
    
    static const label_layout
    sell_button_label(
                     button_alignment,
                     layout_string_resource(
                                            layout_resource_id( "*CommonGiftSellButtonText" ),
                                            layout_string( "Sell" ) ),                                        
                     layout_white_color,
                     draw_flags_hcenter_vcenter,
                     button_font,
                     sell_button_text_rect,
                     shadow );
    
    /////////////////////////////////////////////////////////
    // buy gray button
    static const sqc_theme_button_layout
    buy_gray_button(
               button_alignment,
               sqc_theme_button_buy_gray,
               buy_button_rect );
               
    /////////////////////////////////////////////////////////
    // sell gray button
    static const sqc_theme_button_layout
    sell_gray_button(
                    button_alignment,
                    sqc_theme_button_sell_gray,
                    sell_button_rect );
    

    
    /////////////////////////////////////////////////////////
    // gift button
    static const sqc_theme_button_layout
    gift_button(
        button_alignment,
        sqc_theme_button_gift,
        gift_button_rect );
    
    static const label_layout
    gift_button_label(
        button_alignment,
        common_resources::string_text_gift,                                        
        layout_white_color,
        draw_flags_hcenter_vcenter,
        button_font,
        gift_button_text_rect,
        shadow );
        
    /////////////////////////////////////////////////////////
    // received button
    static const sqc_theme_button_layout
    received_button(
                button_alignment,
                sqc_theme_button_received,
                received_button_rect );
    
    static const label_layout
    received_button_label(
                      button_alignment,
                      layout_string_resource(
                                             layout_resource_id( "*CommonGiftAcceptButtonText" ),
                                             layout_string( "Accept" ) ),                                        
                      layout_white_color,
                      draw_flags_hcenter_vcenter,
                      button_font,
                      received_button_text_rect,
                      shadow );

    /////////////////////////////////////////////////////////
    // ask button
    static const sqc_theme_button_layout
    ask_button(
        button_alignment,
        sqc_theme_button_gift,
        ask_button_rect );
    
    static const label_layout
    ask_button_label(
        button_alignment,
        layout_string_resource(
             layout_resource_id( "*CommonAskButtonText" ),
             layout_string( "Ask" ) ),                                        
        layout_white_color,
        draw_flags_hcenter_vcenter,
        button_font,
        ask_button_text_rect,
        shadow);
        
    /////////////////////////////////////////////////////////
    // apply button
    static const sqc_theme_button_layout
    apply_button(
                 button_alignment,
                 sqc_theme_button_apply,
                 gift_button_rect );

    static const label_layout
    apply_button_label(
                       button_alignment,
                       layout_string_resource(
                                             layout_resource_id( "*CommonUseButtonText" ),
                                             layout_string( "Apply" ) ),                                        
                       layout_white_color,
                       draw_flags_hcenter_vcenter,
                       button_font,
                       gift_button_text_rect,
                       shadow );
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_BUTTONS_LAYOUT_H_INCLUDED__
