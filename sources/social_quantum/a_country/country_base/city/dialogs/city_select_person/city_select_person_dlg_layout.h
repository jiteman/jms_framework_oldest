/*
 *  city_select_person_dlg_layout.h
 *  aCountry
 *
 *  Created by Василий on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SELECT_PERSON_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_SELECT_PERSON_DLG_LAYOUT_H_INCLUDED__

#include "../city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	namespace select_person {

		static const layout_string_resource dialog_title( "*CommonFriends", "Friends" );
        static const int dlg_w[] = {480,960,957};
		static const int dlg_h[] = {320,640,493};
        static const dialog_layout background(
        	layout_alignment( layout_halignment_center | layout_valignment_center ),
        	dialog_sizes(
            	layout_size( dlg_w[0], dlg_h[0] ),
            	layout_size( dlg_w[1], dlg_h[1] ),
            	layout_size( dlg_w[2], dlg_h[2] ) )
        );
        
		
        
        static const sqc_shop_item_button_layout
        btn_pers_bg( 
            layout_alignment( layout_halignment_center | layout_valignment_bottom),
            image_rects(
            	layout_rect( 0, 42, 117, 119 ),
                layout_rect( 0, 2*56, 2*117, 2*119 ),
				layout_rect( 0, 70, 155, 155 ) 
            )
        );

		// network spinboard
        static const int spinb_x[]  = { 22, 2*20, 32  };
        static const int spinb_top[]  = { 
			dlg_h[0]-64, 
			dlg_h[1]-64*2, 
			dlg_h[2]-80 };
        static const int spinb_bottom[]  = { 28+28, 2*28+14*2, 50+24 };//    static int height[] = { 19, 38, 29 };
        
        static const int spinb_w[]  = { dlg_w[0] - 2 * spinb_x[0], 
			dlg_w[1] - 2 * spinb_x[1], 
			dlg_w[2] - 2 * spinb_x[2] };
        static const int spinb_h[]  = { spinb_top[0] - spinb_bottom[0], 
			spinb_top[1] - spinb_bottom[1], 
			spinb_top[2] - spinb_bottom[2] };
        
        // spinboard layout
        static const spinboard_layout
        spinboard( 
						   layout_halignment_left | layout_valignment_bottom,
						   spinboard_rects( 
										   layout_rect( spinb_x[0], spinb_bottom[0], spinb_w[0], spinb_h[0] ),
										   layout_rect( spinb_x[1], spinb_bottom[1], spinb_w[1], spinb_h[1] ),
										   layout_rect( spinb_x[2], spinb_bottom[2], spinb_w[2], spinb_h[2] ) ) ,
						   milk::milk_spinboard_themed_left_right);
		
      
		// spinboard pager
		static const int pager_width[]  = { 22*5.5, 230, 150 };
		static const int pager_height[]  = { 28, 28*2, 48 };
		static const int pager_offset[]  = { 28, 14*2, 24 };
		static const spinboard_pager_layout
		spinboard_pager( 
								 bottom_layout_alignment,
								 spinboard_rects( 
												 layout_rect( spinb_x[0]+(spinb_w[0]-pager_width[0])/2, spinb_bottom[0]-pager_height[0]-pager_offset[0], pager_width[0], pager_height[0] ),
												 layout_rect( spinb_x[1]+(spinb_w[1]-pager_width[1])/2, spinb_bottom[1]-pager_height[1]-pager_offset[1], pager_width[1], pager_height[1] ),
												 layout_rect( spinb_x[2]+(spinb_w[2]-pager_width[2])/2, spinb_bottom[2]-pager_height[2]-pager_offset[2], pager_width[2], pager_height[2] ) ) );
		
		/// separator from theme
		static const vertical_separator_layout spinboard_cell_separator( 
																			  layout_alignment( layout_halignment_right ),
																			  separator_offsets( 0,0,0) );
		
        // perhaps, avatars will be different for different platforms
        static const layout_rects rct_ava(
            layout_rect( 0, 0, 70, 70 ),
            layout_rect( 0, 0, 2*70, 2*70 ),
            layout_rect( 0, 0, 90, 90 )
        );

        static const label_layout 
        lbl_pers_name (
            layout_alignment( layout_halignment_fill | layout_valignment_top ),
            layout_string_resource( "*UserName", "User name" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center |
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ), //Arial
				layout_font_sizes( 12, 2*12, 16 )
            ),
            label_rects(
				layout_rect( 0, 20, 0, 13 ),
				layout_rect( 0, 2*20, 0, 2*13 ),
				layout_rect( 0, 15, 0, 23 )
            ) 
        );
		
		static const image_layout
        img_asterisk (
            layout_alignment( layout_halignment_left | layout_valignment_top),
			image_names(
            	"exp_star",
            	"exp_star@2x",
				"exp_star"
            ),
			image_rects(
                layout_rect( 80, 6, 30, 30 ),
                layout_rect( 2*80, 2*6, 59, 56 ),
                layout_rect( 109, 13, 30, 30 ) ) );

        static const label_layout 
        lbl_pers_level (
            layout_alignment( layout_halignment_left | layout_valignment_top ),
            layout_string_resource( "*Userlevel", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center |
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ), //Arial
				layout_font_sizes( 8, 2*8, 9 )
            ),
            label_rects(
				layout_rect( 7, 10, 18, 13 ),
				layout_rect( 2*5, 2*10, 2*18, 2*13 ),
				layout_rect( 8, 8, 17, 14 )
            ) 
        );
        
        static const city_green_button_layout
        btn_hire(
			layout_alignment( layout_halignment_center | layout_valignment_bottom ),
            image_rects(
            	layout_rect( 0, 0, 85, 23 ),
                layout_rect( 0, 0, 2*85, 2*23 ),
				layout_rect( 0, 15, 95, 30 ) 
            )
        );
        static const label_layout 
        lbl_hire (
            layout_alignment( layout_halignment_fill | layout_valignment_fill ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center | surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ), //Arial
				layout_font_sizes( 12, 2*12, 16 )
            ),
            label_rects(
            	layout_rect( 0, 0, 0, 0 ) ,
                layout_rect( 0, 0, 0, 0 ) ,
				layout_rect( 0, 0, 0, 0 ) 
            ) 
        );
        
        



	}
}



END_NAMESPACE_SQC_FRAMEWORK

#endif
