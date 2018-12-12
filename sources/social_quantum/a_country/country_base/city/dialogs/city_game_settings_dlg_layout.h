/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_GAME_SETTINGS_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_GAME_SETTINGS_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	// game settings dialog
	namespace game_setting_dlg {
		// SettingsViewController
		static const dialog_layout background(
			layout_alignment( layout_halignment_center | 
							 layout_valignment_center ),
			dialog_sizes( layout_size( 480, 320 ),
						  layout_size( 960, 640 ),
						  layout_size( 593, 414 ) ) );
		
		
		// separtors
		static const vertical_separator_layout separator_v1( 
															layout_alignment( layout_halignment_left ),
															separator_offsets( 343-content_offset_lr[0],
																			  2*343-content_offset_lr[1],
																			  427-content_offset_lr[2]) );
		
		// dialog title
		static const layout_string_resource dialog_title(
            layout_resource_id( "*SettingsWindowTitle" ),
            layout_string( "Settings" ) );
        
		// caption font
		static const font_layout caption_font (
						  layout_font_name( "Arial-MT.otf" ),//ArialMT
						  layout_font_sizes( 15, 2*15, 22 ) );
		
		// caption draw flags
		static const layout_label_draw_flags caption_draw_flags(
						   surf::draw_string_alignment_left|
						   surf::draw_string_valignment_center|
						   surf::draw_string_single_line|
						   surf::draw_string_truncation_tail );
		
		// label x, width and height
		static const int label_x[]			= { 27, 2*27, 43 };
		static const int label_offset[]		= {  -1, -2*1, -2 };
		static const int label_w[]			= { 220, 2*220, 300 };
		static const int label_h[]			= { 30, 2*30, 30 };

		// switch x, width and height
		static const int switch_x[]			= { 229, 2*229, 319 };
		static const int switch_w[]			= { 94, 2*94, 94 };
		static const int switch_h[]			= { 27, 2*27, 27 };
		
		// controls y position
		static const int anim_y[]			= { 68, 2*68, 90 };
		static const int sound_y[]			= { 108, 2*108, 141 };
		static const int music_y[]			= { 149, 2*149, 193 };
		static const int contr_y[]			= { 189, 2*189, 244 };
		static const int popul_y[]			= { 230, 2*230, 295 };
		static const int tax_y[]			= { 270, 2*270, 348 };
		
        //shadow
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                   layout_point( -1, 2 ),
                                                   layout_point( -0.75, 1 ));
                                                     
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        
		// animation
		static const label_layout
		animation_label(
			top_layout_alignment,
			layout_string_resource(
				 layout_resource_id( "*SettingsAnimationDescription" ),
				 layout_string( "Enable Animation:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], anim_y[0] + label_offset[0], label_w[0], label_h[0] ),
					     layout_rect( label_x[1], anim_y[1] + label_offset[1], label_w[1], label_h[1] ),
					     layout_rect( label_x[2], anim_y[2] + label_offset[1], label_w[2], label_h[2] ) ),
            shadow );

		static const switch_button_layout
		animation_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], anim_y[0], switch_w[0], switch_h[0] ),
					     layout_rect( switch_x[1], anim_y[1], switch_w[1], switch_h[1] ),
					     layout_rect( switch_x[2], anim_y[2], switch_w[2], switch_h[2] ) ) );
		
		// sound
		static const label_layout
		sound_label(
			top_layout_alignment,
			layout_string_resource(
				 layout_resource_id( "*SettingsSoundDescription" ),
				 layout_string( "Enable Sound:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], sound_y[0] + label_offset[0], label_w[0], label_h[0] ),
					     layout_rect( label_x[1], sound_y[1] + label_offset[1], label_w[1], label_h[1] ),
					     layout_rect( label_x[2], sound_y[2] + label_offset[2], label_w[2], label_h[2] ) ),
            shadow );
		
		static const switch_button_layout
		sound_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], sound_y[0], switch_w[0], switch_h[0] ),
					     layout_rect( switch_x[1], sound_y[1], switch_w[1], switch_h[1] ),
					     layout_rect( switch_x[2], sound_y[2], switch_w[2], switch_h[2] ) ) );
		
		// music
		static const label_layout
		music_label(
			top_layout_alignment,
			layout_string_resource(
				 layout_resource_id( "*SettingsMusicDescription" ),
				 layout_string( "Enable Music:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], music_y[0] + label_offset[0], label_w[0], label_h[0] ),
					     layout_rect( label_x[1], music_y[1] + label_offset[1], label_w[1], label_h[1] ),
					     layout_rect( label_x[2], music_y[2] + label_offset[2], label_w[2], label_h[2] ) ),
            shadow);
		
		static const switch_button_layout
		music_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], music_y[0], switch_w[0], switch_h[0] ),
		    			 layout_rect( switch_x[1], music_y[1], switch_w[1], switch_h[1] ),
						 layout_rect( switch_x[2], music_y[2], switch_w[2], switch_h[2] ) ) );
		
		
		// contracts notifications
		static const label_layout
		contracts_label(
			top_layout_alignment,
			layout_string_resource(
				 layout_resource_id( "*SettingsConNotificationsDescription" ),
				 layout_string( "Contract Notifications:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], contr_y[0] + label_offset[0], label_w[0], label_h[0] ),
					     layout_rect( label_x[1], contr_y[1] + label_offset[1], label_w[1], label_h[1] ),
					     layout_rect( label_x[2], contr_y[2] + label_offset[2], label_w[2], label_h[2] ) ),
            shadow);
		
		static const switch_button_layout
		contracts_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], contr_y[0], switch_w[0], switch_h[0] ),
					     layout_rect( switch_x[1], contr_y[1], switch_w[1], switch_h[1] ),
					     layout_rect( switch_x[2], contr_y[2], switch_w[2], switch_h[2] ) ) );
		
		// population notifications
		static const label_layout
		population_label(
			top_layout_alignment,
			layout_string_resource(
				 layout_resource_id( "*SettingsPopNotificationsDescription" ),
				 layout_string( "Population Notifications:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], popul_y[0] + label_offset[0], label_w[0], label_h[0] ),
					     layout_rect( label_x[1], popul_y[1] + label_offset[1], label_w[1], label_h[1] ),
					     layout_rect( label_x[2], popul_y[2] + label_offset[2], label_w[2], label_h[2] ) ),
            shadow );
		
		static const switch_button_layout
		population_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], popul_y[0], switch_w[0], switch_h[0] ),
					     layout_rect( switch_x[1], popul_y[1], switch_w[1], switch_h[1] ),
					     layout_rect( switch_x[2], popul_y[2], switch_w[2], switch_h[2] ) ) );

		// tax notifications
		static const
		label_layout tax_label(
			top_layout_alignment,
			layout_string_resource(
				layout_resource_id( "*SettingsTaxNotificationsDescription" ),
				layout_string( "Tax Notifications:" ) ),
			layout_white_color,
			caption_draw_flags,
			caption_font,
			label_rects( layout_rect( label_x[0], tax_y[0] + label_offset[0], label_w[0], label_h[0] ),
				         layout_rect( label_x[1], tax_y[1] + label_offset[1], label_w[1], label_h[1] ),
				         layout_rect( label_x[2], tax_y[2] + label_offset[2], label_w[2], label_h[2] ) ),
            shadow );
		
		static const switch_button_layout
		tax_button( 
			top_layout_alignment,
			image_rects( layout_rect( switch_x[0], tax_y[0], switch_w[0], switch_h[0] ),
					     layout_rect( switch_x[1], tax_y[1], switch_w[1], switch_h[1] ),
					     layout_rect( switch_x[2], tax_y[2], switch_w[2], switch_h[2] ) ) );
		
		
		//
		// change social network
		//
		
		// change network button
		static const image_rects
		change_network_rect( 
					layout_rect( 375, 189, 64, 24 ),
					layout_rect( 2*375, 2*189, 130, 48 ),
					layout_rect( 463, 239, 78, 30 ) );
		
		static const city_green_button_layout 
		change_network_btn(
					 layout_alignment( layout_halignment_left |
									 layout_valignment_top) ,
					 change_network_rect );
		
		
		static const font_layout change_network_caption_font(
				   layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
				   layout_font_sizes( 14, 2*14, 14 ) );
		
		static const label_layout change_network_caption(
					layout_alignment( layout_halignment_left | 
							layout_valignment_top ),
					layout_string_resource(
							layout_resource_id( "*CityChangeButton" ),
							layout_string( "Change" ) ),
					layout_white_color,
					layout_label_draw_flags(
							surf::draw_string_alignment_center|
							surf::draw_string_valignment_center),
					change_network_caption_font,
					change_network_rect,
                    shadow );

		// change network descr
		static const font_layout change_network_descr_font(
					 layout_font_name( "Arial-MT.otf" ), //ArialMT
					 layout_font_sizes( 13, 2*13, 18 ) );
		
		static const label_layout change_network_descr(
					layout_alignment( 
							layout_halignment_left | 
							layout_valignment_top ),
					layout_string_resource(
							layout_resource_id( "*SettingsNetworkDescription" ),
							layout_string( "Change Network" ) ),
					layout_white_color,
					layout_label_draw_flags(
							surf::draw_string_alignment_center|
							surf::draw_string_valignment_center),
					change_network_descr_font,
					image_rects( layout_rect( 345, 152, 124, 30 ),
								 layout_rect( 2*345, 2*152, 2*124, 2*30 ),
								 layout_rect( 439, 202, 124, 30 ) ),
                    shadow );
		
		
		// network background button
		static const image_rects
		network_background_btn_rect( 
					layout_rect( 364, 68, 85, 87 ),
					layout_rect( 2*364, 2*68, 168, 173 ),
					layout_rect( 447, 91, 108, 112 ) );
		
		static const sqc_shop_item_button_layout 
		network_background_btn(
		   layout_alignment( layout_halignment_left |
						   layout_valignment_top) ,
							network_background_btn_rect );
		
        // current network button
        static const image_rects
        current_network_image_rect( 
            layout_rect( 0, 0, 60, 60 ),
            layout_rect( 0, 0, 2*60, 2*60 ),
            layout_rect( 0, 0, 68, 68 ) );
        
        static const image_layout 
		current_network_image( // layout by background button
           layout_alignment( layout_halignment_center |
                           layout_valignment_center),
           image_names( "", "", "" ), 
           current_network_image_rect );
        
    	
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_GAME_SETTINGS_DLG_LAYOUT_H_INCLUDED__


