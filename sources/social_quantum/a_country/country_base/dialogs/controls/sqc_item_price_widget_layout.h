/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_PRICE_WIDGET_LAYOUT_H_INCLUDED__
#define __SQC_ITEM_PRICE_WIDGET_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace item_price_widget {
	
    static const int height[] = { 17, 33, 23 };
    static const int width[] = { 120, 2*120, 150 };
    
    // spinboard cell coins and bucks font
    static const font_layout 
    cell_price_font( 
         layout_font_name( "Arial.otf" ), //ARIAL
         layout_font_sizes( 12, 2*12, 18 ) ); 
    
    // offset from left
    static int label_offset[] = {20, 2*20, 30 };

    // spinboard cell coins image
    static const image_layout
    cell_price_in_coins_image( // layout by spinboard cell
         layout_alignment( layout_halignment_left |
                         layout_valignment_bottom),
         image_names( "price_coin_icon",
                     "price_coin_icon@2x",
                     "price_coins_icon_ipad" ),
         image_rects( 
                     layout_rect( 0, 0, 15, 15 ),
                     layout_rect( 0, 0, 29, 24 ),
                     layout_rect( 0, 0, 20, 20 ) ) );

    static const label_layout
    cell_price_in_coins_label( //layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        layout_string_resource( "", "" ),                                        
        layout_white_color,
        draw_flags_hleft_vcenter,
        cell_price_font,
        label_rects( 
            layout_rect( label_offset[0], 0, width[0] - label_offset[0], 15 ),
            layout_rect( label_offset[1], 0, width[1] - label_offset[1], 24 ),
            layout_rect( label_offset[2], 0, width[2] - label_offset[2], 20 ) ) );


    // spinboard cell bucks image
    static const image_layout
    cell_price_in_bucks_image( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        image_names( "price_bucks_icon",
                   "price_bucks_icon@2x",
                   "price_bucks_icon_ipad" ),
        image_rects( 
                   layout_rect( 0, 0, 11, 17 ),
                   layout_rect( 0, 0, 21, 33 ),
                   layout_rect( 0, 0, 16, 23 ) ) );
    
    static const label_layout
    cell_price_in_bucks_label( //layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hleft_vcenter,
        cell_price_font,
        label_rects( 
                   layout_rect( label_offset[0], 0, width[0] - label_offset[0], 17 ),
                   layout_rect( label_offset[1], 0, width[1] - label_offset[1], 33 ),
                   layout_rect( label_offset[2], 0, width[2] - label_offset[2], 23 ) ) );
    
    // spinboard cell megabucks image
    static const image_layout
    cell_price_in_megabucks_image( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        image_names( "price_megabucks_icon",
                     "price_megabucks_icon@2x",
                     "price_megabucks_icon_ipad" ),
        image_rects( 
                   layout_rect( 0, 0, 15, 13 ),
                   layout_rect( 0, 0, 30, 26 ),
                   layout_rect( 0, 0, 23, 20 ) ) );
    
    static const label_layout
    cell_price_in_megabucks_label( //layout by spinboard cell
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hleft_vcenter,
        cell_price_font,
        label_rects( 
                   layout_rect( label_offset[0], 0, width[0] - label_offset[0], 13 ),
                   layout_rect( label_offset[1], 0, width[1] - label_offset[1], 26 ),
                   layout_rect( label_offset[2], 0, width[2] - label_offset[2], 20 ) ) );
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_PRICE_WIDGET_LAYOUT_H_INCLUDED__


