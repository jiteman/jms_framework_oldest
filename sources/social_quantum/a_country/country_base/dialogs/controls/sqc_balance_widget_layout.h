/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_BALANCE_WIDGET_LAYOUT_H_INCLUDED__
#define __SQC_BALANCE_WIDGET_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace balance_widget {
	
    static int width[] = { 144, 287, 213 };
    static int height[] = { 19, 38, 29 };
        
    // bucks and coins labels font
    static const font_layout 
    bucks_and_coins_label_font( 
        layout_font_name( "Arial.otf" ), //Arial
        layout_font_sizes( 12, 2*12, 18 ) ); 
    
        
    static const image_rects
    coins_and_bucks_backing_rects( 
          layout_rect( 0, 0, width[0], height[0] ),
          layout_rect( 0, 0, width[1], height[1] ),
          layout_rect( 0, 0, width[2], height[2] ) );

    static const image_layout
    coins_and_bucks_backing_image(
        layout_alignment( layout_halignment_right |
                     layout_valignment_bottom),
        image_names( "balance_back",
                 "balance_back@2x",
                 "balance_back_ipad" ),
        coins_and_bucks_backing_rects );

    // coins image // layout by coins_and_bucks_backing
    static const int coins_image_offset[] = { 5, 2*5, 7 };
    static const int coins_image_w[] = { 15, 29, 20 };
    static const int coins_image_h[] = { 15, 24, 21 };
    
    static const int coins_label_offset[] = { 5, 2*5, 7 };
    static const int coins_label_x[] = {
        coins_image_offset[0] + coins_image_w[0] + coins_label_offset[0],
        coins_image_offset[1] + coins_image_w[1] + coins_label_offset[1],
        coins_image_offset[2] + coins_image_w[2] + coins_label_offset[2]
    };
    static const int coins_label_w[] = {
        width[0]/2 - coins_label_x[0]-2,
        width[1]/2 - coins_label_x[1]-2,
        width[2]/2 - coins_label_x[2]-2
    };
    
    static const image_rects
    coins_image_rects( 
        layout_rect( coins_image_offset[0], 0, coins_image_w[0], coins_image_h[0] ),
        layout_rect( coins_image_offset[1], 0, coins_image_w[1], coins_image_h[1] ),
        layout_rect( coins_image_offset[2], 0, coins_image_w[2], coins_image_h[2] ) );
    
    static const image_rects
    coins_label_rects( 
        layout_rect( coins_label_x[0], 0, coins_label_w[0], height[0] ),
        layout_rect( coins_label_x[1], 0, coins_label_w[1], height[1] ),
        layout_rect( coins_label_x[2], 0, coins_label_w[2], height[2] ) );
    
    static const image_layout
    coins_image(
        layout_alignment( layout_halignment_left |
                      layout_valignment_center ),
        image_names( "price_coin_icon",
                  "price_coin_icon@2x",
                  "price_coins_icon_ipad" ),
        coins_image_rects );

    static const label_layout
    coins_label( // layout by coins_and_bucks_backing
        layout_alignment( layout_halignment_left |
                     layout_valignment_bottom),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hleft_vcenter,
        bucks_and_coins_label_font,
        coins_label_rects );
    
    
    // bucks image // layout by coins_and_bucks_backing
    static const int bucks_image_w[] = { 15, 30, 23 };
    static const int bucks_image_h[] = { 13, 26, 20 };
    static const int bucks_image_x[] = { width[0]/2, 
                                         width[1]/2,
                                         width[2]/2 };
    
    static const int bucks_label_offset[] = { 5, 2*5, 7 };
    static const int bucks_label_x[] = {
        width[0]/2 + bucks_image_w[0] + bucks_label_offset[0],
        width[1]/2 + bucks_image_w[1] + bucks_label_offset[1],
        width[2]/2 + bucks_image_w[2] + bucks_label_offset[2]
    };
    static const int bucks_label_w[] = {
        width[0] - bucks_label_x[0]-2,
        width[1] - bucks_label_x[1]-2,
        width[2] - bucks_label_x[2]-2
    };
    
    static const image_rects
    bucks_image_rects( 
        layout_rect( bucks_image_x[0], 0, bucks_image_w[0], bucks_image_h[0] ),
        layout_rect( bucks_image_x[1], 0, bucks_image_w[1], bucks_image_h[1] ),
        layout_rect( bucks_image_x[2], 0, bucks_image_w[2], bucks_image_h[2] ) );

    static const image_rects
    bucks_label_rects( 
        layout_rect( bucks_label_x[0], 0, bucks_label_w[0], height[0] ),
        layout_rect( bucks_label_x[1], 0, bucks_label_w[1], height[1] ),
        layout_rect( bucks_label_x[2], 0, bucks_label_w[2], height[2] ) );
    
    static const image_layout
    bucks_image(
        layout_alignment( layout_halignment_left |
                      layout_valignment_center ),
        image_names( "icon_megabucks",
                    "icon_megabucks@2x",
                    "icon_megabucks_ipad" ),
        bucks_image_rects );

    static const label_layout
    bucks_label( // layout by coins_and_bucks_backing
        layout_alignment( layout_halignment_left |
                        layout_valignment_bottom),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hleft_vcenter,
        bucks_and_coins_label_font,
        bucks_label_rects );
        

}};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_BALANCE_WIDGET_LAYOUT_H_INCLUDED__


