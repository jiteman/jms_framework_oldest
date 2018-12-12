/*
 *  city_buy_management_layout.h
 *  aCountry
 *
 *  Created by Василий on 04.08.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __SQC_CITY_BUY_MANAGEMENT_LAYOUT_H_INCLUDED__
#define __SQC_CITY_BUY_MANAGEMENT_LAYOUT_H_INCLUDED__

#include "city/dialogs/city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	namespace buy_management_dlg {
	    
        static const dialog_layout background(
            layout_alignment( layout_halignment_center | 
                             layout_valignment_center ),
            dialog_sizes(
				layout_size( 480, 320 ),
				layout_size( 960, 640 ),
				layout_size( 676, 406 ) ) );
        
        
			
        static const label_rects item_rects(
			//width 117, 234, 155
            //without cell_item_name_label see sqc_shop_item_cell_layout.h
            layout_rect( 10, 25, 140, 260 ),
            layout_rect( 2*10, 2*25, 2*140, 2*300 ),
            layout_rect( 30, 15, 155, 300 )
		); 


        static const layout_resource_id management_title_ids( "" );
        //layout_string( "" )
        
        
        //shadow
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -0.75, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        
        
		static label_layout cityhall_header(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			layout_string_resource(
				 layout_resource_id( "" ),
				 layout_string( "" )
        	),
			layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
            font_layout(
            	layout_font_name( "Arial-BoldMT.otf" ), //ArialBT
            	layout_font_sizes( 15, 2*15, 18 )
            ),
            label_rects(
            	layout_rect( 188, 194, 270, 42 ),
				layout_rect( 2*188, 2*194, 2*270, 2*42 ),
				layout_rect( 238, 274, 373, 31 )
            ),
            shadow
        );

		static const label_layout cityhall_descr(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			layout_string_resource(
				 layout_resource_id( "" ),
				 layout_string( "" )
        	),
			layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left |
                surf::draw_string_valignment_top ),
            font_layout(
            	layout_font_name( "Arial.otf" ), //ArialBT
            	layout_font_sizes( 12, 2*15, 18 )
            ),
            label_rects(
            	layout_rect( 188, 116, 270, 73 ),
				layout_rect( 2*188, 2*116, 2*270, 2*73 ),
				layout_rect( 238, 186, 373, 42 )
            ),
            shadow
        );


		

		static const image_button_layout add_coins_button( 
			layout_alignment( layout_halignment_left | layout_valignment_bottom),
			image_names(
            	"add_coins_button_0",
				"add_coins_button_0@2x",
                "add_coins_button_ipad_0"
            ), 
			image_pressed_names(
            	"add_coins_button_1",
				"add_coins_button_1@2x",
                "add_coins_button_ipad_1"
            ),
			image_rects(
            	layout_rect( 265, 271, 165, 40 ),
				layout_rect( 2*265, 2*271, 2*165, 2*40 ),
				layout_rect( 411, 348, 199, 48 )
            )
        );

		static const label_layout add_coins_caption(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			common_resources::string_title_add_coins,
			layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center|
                surf::draw_string_valignment_center ),
            font_layout(
            	layout_font_name( "Arial-BoldMT.otf" ), //ArialBT
            	layout_font_sizes( 14, 2*14, 18 )
            ),
            label_rects(
            	layout_rect( 265+36, 271, 165-36, 40 ),
				layout_rect( 2*(265+36), 2*271, 2*(165-36), 2*40 ),
				layout_rect( 411+41, 348, 199-41, 48  )
            ) 
        );

    }
}


END_NAMESPACE_SQC_FRAMEWORK

#endif