/*
 *  city_money_dlg_layout.h
 *  aCountry
 *
 *  Created by Василий on 27.07.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *	TODO: add item buttons, add bucks, and coins images

 */

#ifndef __SQC_CITY_MONEY_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_MONEY_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	namespace money_dlg_layout {

        //============================== Window =============================

                
		// The Window Background
		
		
		static const layout_alignment com_dlg_align( layout_halignment_center | layout_valignment_top );

       
        static const dialog_layout dlg_bg(
			com_dlg_align,
			dialog_sizes(layout_size( 480, 320 ),
						 layout_size( 960, 640 ),
						 layout_size( 676, 472 ))
		);
        
        //shadow
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -0.75, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;

     
		/// separator
		static const vertical_separator_layout separator( 
															layout_alignment( layout_halignment_center ),
															separator_offsets( 1, 2, 4) );
		
		static const city_horizontal_clear_separator_layout separator_h1( 
															 layout_alignment( layout_valignment_center ),
															 separator_offsets( -37, -37*2, -60) );
		static const city_horizontal_clear_separator_layout separator_h2( 
															  layout_alignment( layout_valignment_center ),
															  separator_offsets( 40 ,40*2, 60) );
        
		//===================== titles ===============================
		// Caption for bucks 
		static const layout_string_resource caption_layout_bucks( "*CityGetMoreMegabucks", "Get more megabucks" );
		static const layout_string_resource caption_layout_coins( "*CityGetMoreCoins", "Get more coins" );
		/*
        static const label_layout caption_layout_bucks(
            layout_alignment( layout_halignment_left | layout_valignment_top ),
            layout_string_resource( "*CityGetMoreMegabucks", "Get more megabucks" ), 
            layout_white_color,
            layout_label_draw_flags(
                                  surf::draw_string_alignment_center|
                                  surf::draw_string_valignment_center ),
            title_font,
            label_rects(
            	layout_rect( 84, title_y[0], 190, title_h[0] ),
				layout_rect( 2*84, title_y[1], 2*190, title_h[1] ),
				layout_rect( 106, title_y[2], 285, title_h[2] )
			) ,
			title_shadow
        );*/
		
        // Caption for coins 
        /*static const label_layout caption_layout_coins(
            layout_alignment( layout_halignment_right | layout_valignment_top ),
            layout_string_resource( "*CityGetMoreCoins", "Get more coins" ), 
            layout_white_color,
            layout_label_draw_flags(
                                  surf::draw_string_alignment_center|
                                  surf::draw_string_valignment_center ),
            title_font,
            label_rects(
            	layout_rect( 40, title_y[0], 150, title_h[0] ),
				layout_rect( 2*40, title_y[1], 2*150, title_h[1] ),
				layout_rect( 70, title_y[2], 212, title_h[2] )
            ) ,
			title_shadow
        );*/
		//===================== /titles ====================================
		

		
        //============================== The cell =============================
        
        // button caption draw flags
		static const layout_label_draw_flags cell_caption_draw_flags(
                       surf::draw_string_alignment_center |
                       surf::draw_string_valignment_center|
                       surf::draw_string_single_line      |  
                       surf::draw_string_truncation_tail );

        // Button and Caption alignments
        static const layout_alignment button_alignment( top_layout_alignment );
        static const layout_alignment caption_alignment( top_layout_alignment );

		static const font_layout buy_button_label_font (
        	layout_font_name( "Arial-BoldMT.otf" ),  //Arial
            layout_font_sizes( 12, 2*12, 14 ) );

	    static const layout_points first_cell_offset( 
			layout_point( 14, 30 ),
            layout_point( 2*14, 2*30 ),
            layout_point( 30, 30 )
        );
        
        static const layout_rects cell_rects(
            layout_rect( 0, 0, 227, 78 ),
            layout_rect( 0, 0, 2*227, 2*78 ),
            layout_rect( 0, 0, 310, 125 ) );


		static const label_layout alot_layout(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			common_resources::string_text_buy,
			layout_color(90/255.0, 184/255.0, 5/255.0, 1),
			cell_caption_draw_flags,
            font_layout (
            	layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                layout_font_sizes( 14, 14*2, 22 )
            ),
			label_rects(
        		layout_rect( 9, 15, 54, 15 ),
        		layout_rect( 2*9, 2*15, 2*54, 2*15 ),
        		layout_rect( 16, 32, 84, 22 )
            )
        );
                         
		static const layout_rects item_background_rect (
        	layout_rect( 5, 5, 60, 64 ),
        	layout_rect( 10, 10, 64*2, 68*2 ),
        	layout_rect( 15, 20, 88, 93 )
        );

		// Layout alignment by cell_rects
		static const label_layout descr_layout(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			layout_string_resource(
				 layout_resource_id( "" ),
				 layout_string( "" )
        	),
			layout_black_color,
			cell_caption_draw_flags,
            font_layout (
            	layout_font_name( "Arial.otf" ), //Arial
                layout_font_sizes( 12, 2*12, 14 )
            ),
			label_rects(
        		layout_rect( 66, 22, 76, 30 ),
        		layout_rect( 2*66, 2*22, 2*76, 2*30 ),
        		layout_rect( 108, 46, 102, 35 ) 
            ) 
        );

		static const layout_rects buy_rect (
        	layout_rect( 141, 17,  82, 41 ),
        	layout_rect( 2*141, 2*17, 2*82, 2*41 ),
        	layout_rect( 220, 50, 80, 41 )
        );

		// Layout alignment by cell_rects
		
		static const city_buy_button_layout buy_button( 
            layout_alignment( bottom_layout_alignment ),
			buy_rect
        );

		// Layout alignment by cell_rects
		static const label_layout buy_caption(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			common_resources::string_text_buy,
			layout_white_color,
			cell_caption_draw_flags,
			buy_button_label_font,
			buy_rect,
            shadow
        );

		// Layout alignment by cell_rects
		static const sqc_shop_item_button_layout
        	item_background_button( 
            	bottom_layout_alignment,
                item_background_rect
            );
            
        // Layout alignment by item_background_button
        static const image_layout
        coins_image(
            layout_alignment( layout_halignment_center |
                            layout_valignment_center ),
            image_names( "add_coins_icon", "add_coins_icon@2x", "add_coins_icon_iPad" ),
            image_rects( 
                layout_rect( 0, 10, 34, 30 ),
                layout_rect( 0, 20, 68, 60 ),
                layout_rect( 0, 15, 48, 44 ) ) );

        // Layout by item_background_button
        static const image_layout
        bucks_image(
            layout_alignment( layout_halignment_center |
                            layout_valignment_center ),
            image_names( "add_bucks_icon", "add_bucks_icon@2x", "add_bucks_icon_iPad" ),
            image_rects( 
                layout_rect( 0, 10, 34, 30),
                layout_rect( 0, 20, 68, 60),
                layout_rect( 0, 15, 48, 44 ) ) );


   
        
        
	};
};

END_NAMESPACE_SQC_FRAMEWORK

#endif