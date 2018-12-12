/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SELECT_NETWORK_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_SELECT_NETWORK_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	namespace select_network_dlg {
    
        
        static const int dlg_w[] = { 480, 960, 957 };
        static const int dlg_h[] = { 320, 640, 432 };
        
		// SocNetSelectionController
		static const dialog_layout background(
			layout_alignment( layout_halignment_center | 
							 layout_valignment_center ),
			dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
						  layout_size( dlg_w[1], dlg_h[1] ),
						  layout_size( dlg_w[2], dlg_h[2] ) ) );
        
        /////////////////////////////////////////////////////////////
		// description font
		static const font_layout description_font (
						  layout_font_name( "Arial-MT.otf" ),//ArialMT
						  layout_font_sizes( 13, 2*13, 24 ) );
		
		// description draw flags
		static const layout_label_draw_flags description_draw_flags(
						   surf::draw_string_alignment_left |
                           surf::draw_string_multi_line |
						   surf::draw_string_truncation_tail );

        static const int descr_x[]  = { 30, 2*25, 55 };
        static const int descr_w[]  = { dlg_w[0] - 2*descr_x[0],
                                        dlg_w[1] - 2*descr_x[1],
                                        dlg_w[2] - 2*descr_x[2] };
        static const int descr_h[]  = { 30, 2*30, 50 };
        static const int descr_y[] = {  215, 2*220, 280 };
        
        
        //shadow
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -0.75, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        
		// description label
		static const label_layout
		description_label(
                        bottom_layout_alignment,
                        layout_string_resource(
                            layout_resource_id( "*SocNetChoiceDescription" ),
                            layout_string( "Connect to one of the social nets and get the opportunity to send and receive gifts, visit friends' cities." ) ),
                        layout_white_color,
                        description_draw_flags,
                        description_font,
                        label_rects( 
                            layout_rect( descr_x[0], descr_y[0], descr_w[0], descr_h[0] ),
                            layout_rect( descr_x[1], descr_y[1], descr_w[1], descr_h[1] ),
                            layout_rect( descr_x[2], descr_y[2], descr_w[2], descr_h[2] ) ),
                            shadow );

        /////////////////////////////////////////////////////////////
        // network spinboard
        static const int spinb_x[]  = { 22, 2*20, 32 };
        static const int spinb_top[]  = { 5 + descr_y[0], 
                                          2*5 +descr_y[1], 
                                          10 + descr_y[2] };
        static const int spinb_bottom[]  = { 28, 2*28, 50 };//    static int height[] = { 19, 38, 29 };
        
        static const int spinb_w[]  = { dlg_w[0] - 2 * spinb_x[0], 
                                        dlg_w[1] - 2 * spinb_x[1], 
                                        dlg_w[2] - 2 * spinb_x[2] };
        static const int spinb_h[]  = { spinb_top[0] - spinb_bottom[0], 
                                        spinb_top[1] - spinb_bottom[1], 
                                        spinb_top[2] - spinb_bottom[2] };
        
        // spinboard layout
        static const spinboard_layout
        networks_spinboard( 
            bottom_layout_alignment,
            spinboard_rects( 
                           layout_rect( spinb_x[0], spinb_bottom[0], spinb_w[0], spinb_h[0] ),
                           layout_rect( spinb_x[1], spinb_bottom[1], spinb_w[1], spinb_h[1] ),
                           layout_rect( spinb_x[2], spinb_bottom[2], spinb_w[2], spinb_h[2] ) ) ,
						   milk::milk_spinboard_themed_left_right);
        
        
		// spinboard pager
		static const int pager_width[]  = { 22*5.5, 230, 150 };
		static const int pager_height[]  = { 28, 28*2, 48 };
		static const spinboard_pager_layout
		networks_spinboard_pager( 
							 bottom_layout_alignment,
							 spinboard_rects( 
											 layout_rect( spinb_x[0]+(spinb_w[0]-pager_width[0])/2, spinb_bottom[0]-pager_height[0], pager_width[0], pager_height[0] ),
											 layout_rect( spinb_x[1]+(spinb_w[1]-pager_width[1])/2, spinb_bottom[1]-pager_height[1], pager_width[1], pager_height[1] ),
											 layout_rect( spinb_x[2]+(spinb_w[2]-pager_width[2])/2, spinb_bottom[2]-pager_height[2], pager_width[2], pager_height[2] ) ) );
        /////////////////////////////////////////////////////////////
        // spinboard cell
        static const image_rects // layout by spinboard cell
        spinboard_cell_background_btn_rect( 
                layout_rect( 0, 50, 117, 122 ),
                layout_rect( 0, 2*50, 234, 238 ),
                layout_rect( 0, 50, 155, 182 ) );
        
        static const image_rects // layout by spinboard cell background_btn
        spinboard_cell_network_img_rect( 
                layout_rect( 0, 0, 60, 60 ),
                layout_rect( 0, 0, 2*60, 2*60 ),
                layout_rect( 0, 0, 68, 68 ) );
        
        static const label_rects // layout by spinboard cell
        spinboard_cell_network_caption_rect ( 
                    layout_rect( 0, 30, 0, 20 ),
                    layout_rect( 0, 2*30, 0, 2*20 ),
                    layout_rect( 0, 30, 0, 50 ) );

        static const label_rects // layout by spinboard cell
        spinboard_cell_current_network_caption_rect (
                    layout_rect( 0, 14, 0, 20 ),
                    layout_rect( 0, 2*14, 0, 2*20 ),
                    layout_rect( 0, 5, 0, 30 ) );
        
      	
        // spinboard cell background
		static const sqc_shop_item_button_layout
		spinboard_cell_background_btn( // layout by spinboard cell
            layout_alignment( layout_halignment_center |
                          layout_valignment_bottom),
            spinboard_cell_background_btn_rect );

        // spinboard cell network image
		static const image_layout 
		spinboard_cell_network_img( // layout by spinboard background button
            layout_alignment( layout_halignment_center |
                           layout_valignment_center),
            image_names( "", "", "" ), 
            spinboard_cell_network_img_rect );
		
		
        // spinboard cell network caption font
		static const font_layout 
        spinboard_cell_network_caption_font( 
                 layout_font_name( "Arial-MT.otf" ), //ArialMT
                 layout_font_sizes( 12, 2*12, 18 ) );

        // spinboard cell current network caption font
		static const font_layout 
        spinboard_cell_current_network_caption_font( 
                layout_font_name( "Arial-MT.otf" ), //ArialMT
                layout_font_sizes( 12, 2*12, 15 ) );
		
        // spinboard cell network caption
		static const label_layout
        spinboard_cell_network_caption( // layout by spinboard cell
                 layout_alignment( layout_halignment_fill |
                               layout_valignment_bottom),
                 layout_string_resource(
                        layout_resource_id( "" ),
                        layout_string( "" ) ),
                 layout_white_color,
                 layout_label_draw_flags(
                        surf::draw_string_alignment_center|
                        surf::draw_string_valignment_bottom),
                 spinboard_cell_network_caption_font,
                 spinboard_cell_network_caption_rect,
                 shadow );
        

        // spinboard cell current network caption
		static const label_layout
        spinboard_cell_current_network_caption( // layout by spinboard cell
            layout_alignment( layout_halignment_fill |
                           layout_valignment_bottom),
            layout_string_resource(
                  layout_resource_id( "" ),
                  layout_string( "" ) ),
            layout_white_color,
            layout_label_draw_flags(
                   surf::draw_string_alignment_center|
                   surf::draw_string_valignment_bottom),
            spinboard_cell_current_network_caption_font,
            spinboard_cell_current_network_caption_rect,
            shadow );
            
        static const vertical_separator_layout spinboard_cell_separator( 
                                layout_alignment( layout_halignment_right ),
                                                  separator_offsets( 0,0,0) );
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SELECT_NETWORK_DLG_LAYOUT_H_INCLUDED__


