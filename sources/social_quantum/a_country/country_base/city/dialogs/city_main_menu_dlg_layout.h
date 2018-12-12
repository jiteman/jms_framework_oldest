/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_MAIN_MENU_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_MAIN_MENU_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	// main menu dialog
	namespace main_menu_dlg {
		// iCityMenuViewController
		static const dialog_layout background(
			layout_alignment( layout_halignment_center | 
							 layout_valignment_center ),
			dialog_sizes( layout_size( 480, 320 ), 
						  layout_size( 960, 640 ),
						  layout_size( 957, 523 ) ) );
		
		// dialog title
		static const layout_string_resource dialog_title(
							layout_resource_id( "*CityMainMenuTitle" ),
							layout_string( "Megapolis" ) );
        

		// button caption font
		static const font_layout button_caption_font (
						 layout_font_name( "Arial-MT.otf" ),//ArialMT
						 layout_font_sizes( 13, 2*13, 22 ) );

		// button cption draw flags
		static const layout_label_draw_flags button_caption_draw_flags(
								surf::draw_string_alignment_center|
								surf::draw_string_single_line|
								surf::draw_string_truncation_tail );
		
		// tax_admin
		static const image_button_layout tax_admin_button( 
						  top_layout_alignment,
						  image_names( "01_main_item_0", 
									  "01_main_item_0@2x", 
									  "01_main_item_0_ipad" ), 
						  image_pressed_names( "01_main_item_1",
											"01_main_item_1@2x",
											"01_main_item_1_ipad" ),
						  image_rects( layout_rect( 25, 66, 84, 86 ),
									  layout_rect( 2*25, 2*66, 168, 171 ),
									  layout_rect( 57, 92, 155, 156 ) ) );
		
		
		static const label_layout tax_admin_label(
						  top_layout_alignment,
						  layout_string_resource(
									 layout_resource_id( "*CityMenuTaxItem" ),
									 layout_string( "Tax Admin" ) ),
						  layout_white_color,
						  button_caption_draw_flags,
						  button_caption_font,
						  label_rects( layout_rect( 25, 66+86+3, 84, 20 ),
									  layout_rect( 2*25, 2*66+171+6, 168, 40 ),
									  layout_rect( 57, 92+156+6, 155, 40 ) ) );
		// help
		static const image_button_layout help_button( 
						  top_layout_alignment,
						  image_names( "icon_help_normal", 
									  "icon_help_normal@2x", 
									  "icon_help_normal_ipad" ), 
						  image_pressed_names( "icon_help_selected",
											"icon_help_selected@2x",
											"icon_help_selected_ipad" ),
						  image_rects( layout_rect( 370, 195, 84, 86 ),
									  layout_rect( 2*370, 2*195, 168, 171 ),
									  layout_rect( 744, 307, 155, 156 ) ) );
		
		static const label_layout help_label(
						 top_layout_alignment,
						 layout_string_resource(
								layout_resource_id( "*CityMenuHelpItem" ),
								layout_string( "Help" ) ),
						 layout_white_color,
						 button_caption_draw_flags,
						 button_caption_font,
						 image_rects( layout_rect( 370,  195+86+3, 84, 20 ),
									 layout_rect( 2*370, 2*195+171+6, 168, 40 ),
									 layout_rect( 744,   307+156, 155, 40 ) ) );
		
		// settings
		static const image_button_layout settings_button( 
						 top_layout_alignment,
						 image_names( "icon_setting_normal", 
									 "icon_setting_normal@2x", 
									 "icon_setting_normal_ipad" ), 
						 image_pressed_names( "icon_setting_selected",
										   "icon_setting_selected@2x",
										   "icon_setting_selected_ipad" ),
						 image_rects( layout_rect( 370, 66, 84, 86 ),
									layout_rect( 2*370, 2*66, 168, 171 ),
									layout_rect( 744, 92, 155, 156 ) ) );
		
		static const label_layout settings_label(
						 top_layout_alignment,
						 layout_string_resource(
									layout_resource_id( "*CityMenuSettingsItem" ),
									layout_string( "Settings" ) ),
						 layout_white_color,
						 button_caption_draw_flags,
						 button_caption_font,
						 image_rects( layout_rect( 370, 66+86+3, 84, 20 ),
									 layout_rect( 2*370, 2*66+171+6, 168, 40 ),
									 layout_rect( 744, 92+156+6, 155, 40 ) ) );
                                     
        // social network
		static const image_button_layout social_button( 
                                                       top_layout_alignment,
                                                       image_names( "icon_social_normal", 
                                                                    "icon_social_normal@2x", 
                                                                    "icon_social_normal_ipad" ), 
                                                       image_pressed_names( "icon_social_selected",
                                                                            "icon_social_selected@2x",
                                                                            "icon_social_selected_ipad" ),
                                                       image_rects( layout_rect( 255, 66, 84, 86 ),
                                                                    layout_rect( 2*255, 2*66, 168, 171 ),
                                                                    layout_rect( 515, 92, 155, 156 ) ) );
		
		static const label_layout social_label(
                                               top_layout_alignment,
                                               layout_string_resource(
                                                                      layout_resource_id( "*CityMenuSocNetItem" ),
                                                                      layout_string( "Change network" ) ),
                                               layout_white_color,
                                               button_caption_draw_flags,
                                               button_caption_font,
                                               image_rects( layout_rect( 255, 66+86+3, 84, 20 ),
                                                            layout_rect( 2*255, 2*66+171+6, 168, 40 ),
                                                            layout_rect( 515, 92+156+6, 155, 40 ) ) );
        
		
		// city_hall
		static const image_button_layout city_hall_button( 
						 top_layout_alignment,
						 image_names( "05_main_item_0", 
									 "05_main_item_0@2x", 
									 "05_main_item_0_ipad" ), 
						 image_pressed_names( "05_main_item_1",
										   "05_main_item_1@2x",
										   "05_main_item_1_ipad" ),
						 image_rects( layout_rect( 25, 195, 84, 86 ),
									 layout_rect( 2*25, 2*195, 168, 171 ),
									 layout_rect( 57, 307, 155, 156 ) ) );
		
		static const label_layout city_hall_label(
						top_layout_alignment,
						layout_string_resource(
							layout_resource_id( "*CityMenuCityHallItem" ),
							layout_string( "City Hall" ) ),
						layout_white_color,
						button_caption_draw_flags,
						button_caption_font,
					  image_rects( layout_rect( 25, 195+86+3, 84, 20 ),
								  layout_rect( 2*25, 2*195+171+6, 168, 40 ),
								  layout_rect( 57, 307+156+6, 155, 40 ) ) );
		
		// bucks
		static const image_button_layout add_bucks_button( 
						  top_layout_alignment,
						  image_names( "06_main_item_0", 
									  "06_main_item_0@2x", 
									  "06_main_item_0_ipad" ), 
						  image_pressed_names( "06_main_item_1",
											"06_main_item_1@2x",
											"06_main_item_1_ipad" ),
                                                          image_rects( layout_rect( 140, 66, 84, 86 ),
                                                                      layout_rect( 2*140, 2*66, 168, 171 ),
                                                                      layout_rect( 286, 92, 155, 156 ) ) );
		
		static const label_layout add_bucks_label(
						  top_layout_alignment,
						  layout_string_resource(
								layout_resource_id( "*CityMenuBucksItems" ),
								layout_string( "+ Bucks" ) ),
						  layout_white_color,
						  button_caption_draw_flags,
						  button_caption_font,
                          						  image_rects( layout_rect( 140, 66+86+3, 84, 20 ),
                                                              layout_rect( 2*140, 2*66+171+6, 168, 40 ),
                                                              layout_rect( 286, 92+156+6, 155, 40 ) ) );
		
		// bucks separator        
        static const vertical_separator_layout separator_v1( 
                                                         layout_alignment( layout_halignment_left ),
                                                         separator_offsets( 118,236,224) );
                                                         
        static const vertical_separator_layout separator_v2( 
                                                         layout_alignment( layout_halignment_center ),
                                                         separator_offsets( 0,0,0) );
                                                         
        static const vertical_separator_layout separator_v3( 
                                                         layout_alignment( layout_halignment_right ),
                                                         separator_offsets( 118,236,224) );
                                                         
        static const city_horizontal_clear_separator_layout separator_h1( 
                                                                         layout_alignment( layout_valignment_center ),
                                                                         separator_offsets( 0 , 0, 0),
                                                                         separator_offsets( 346 ,692, 680));
                                                                         
        static const city_horizontal_clear_separator_layout separator_h2( 
                                                                         layout_alignment( layout_valignment_center ),
                                                                         separator_offsets( 0 , 0, 0),
                                                                         separator_offsets( 0 , 0, 0),
                                                                         separator_offsets( 230 ,462, 450));
				
		// coins
		static const image_button_layout add_coins_button( 
						  top_layout_alignment,
						  image_names( "07_main_item_0", 
									  "07_main_item_0@2x", 
									  "07_main_item_0_ipad" ), 
						  image_pressed_names( "07_main_item_1",
											"07_main_item_1@2x",
											"07_main_item_1_ipad" ),
						  image_rects( layout_rect( 140, 195, 84, 86 ),
									  layout_rect( 2*140, 2*195, 168, 171 ),
									  layout_rect( 286, 307, 155, 156 ) ) );
		
		static const label_layout add_coins_label(
						  top_layout_alignment,
						  layout_string_resource(
								layout_resource_id( "*CityMenuCoinsItem" ),
								layout_string( "+ Coins" ) ),
						  layout_white_color,
						  button_caption_draw_flags,
						  button_caption_font,
						  image_rects( layout_rect( 140, 195+86+3, 84, 20 ),
									  layout_rect( 2*140, 2*195+171+6, 168, 40 ),
									  layout_rect( 286, 307+156+6, 155, 40 ) ) );
		
	}
	

	
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_MAIN_MENU_DLG_LAYOUT_H_INCLUDED__


