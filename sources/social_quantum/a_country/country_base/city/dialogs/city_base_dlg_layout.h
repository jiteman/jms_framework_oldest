#pragma once

#include "framework/sqc_framework_defs.h"
#include "framework/layout/sqc_layout_defs.h"
#include "framework/dialogs/sqc_base_dialog_layout.h"
#include "framework/layout/sqc_common_resources.h"
#include "city_theme_elements.h"


NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	
	static const surf::surf_val content_offset_top[] = { 50,50*2,70 }; 
	static const surf::surf_val content_offset_lr[] = { 7,7*2,25 };
	static const surf::surf_val content_offset_btm[] = { 7,7*2,20 };

	
	static const image_button_layout close_button( 
						layout_alignment( layout_halignment_right |
										layout_valignment_top) ,
						image_names( "message_close_shop_0", 
									 "message_close_shop_0@2x", 
									 "close_button_ipad_0" ), 
						image_pressed_names( "message_close_shop_1",
										   "message_close_shop_1@2x",
										   "close_button_ipad_1" ),
						image_rects( layout_rect( 3, 3, 39, 40 ),
									 layout_rect( 6, 6, 79, 80 ),
									 layout_rect( 4, 4, 49, 49 ) ) );
	
	static const layout_rects	close_button_bg(layout_rect( 0, 0, 39+5*2, 40+5*2 ),
												layout_rect( 0, 0, 79+10*2, 80+10*2 ),
												layout_rect( 0, 0, 49+7*2, 49+7*2 ));
	
	static const image_button_layout back_button(
					   layout_alignment( layout_halignment_left |
									   layout_valignment_top) ,
					   image_names( "back_button_shop_0", 
	 							    "back_button_shop_0@2x", 
								    "back_button_ipad_0" ), 
						image_pressed_names( "back_button_shop_1",
											"back_button_shop_1@2x",
											"back_button_ipad_1" ),
						image_rects( layout_rect( 3, 3, 76, 40 ),
									 layout_rect( 6, 6, 152, 80 ),
									 layout_rect( 4, 4, 90, 49 ) ) );

	static const layout_rects	 back_button_bg(layout_rect( 0, 0, 76+5*2, 40+5*2 ),
												layout_rect( 0, 0, 152+10*2, 80+10*2 ),
												layout_rect( 0, 0, 90+7*2, 49+7*2 ));
                                     
    static const image_button_layout next_button(
                                                 layout_alignment( layout_halignment_left |
                                                                   layout_valignment_top) ,
                                                 image_names( "next_0", 
                                                              "next_0@2x", 
                                                              "next_iPad_0" ), 
                                                 image_pressed_names( "next_1",
                                                                      "next_1@2x",
                                                                      "next_iPad_1" ),
                                                 image_rects( layout_rect( 401, 3, 76, 40 ),
                                                              layout_rect( 802, 6, 152, 80 ),
                                                              layout_rect( 524, 6, 90, 49 ) ) );
	
    static const font_layout next_button_font (
                                               layout_font_name( "Arial-BoldMT.otf" ), //boldSystemFont
                                               layout_font_sizes( 16, 2*16, 22 ) );
	
    
    static const label_layout next_button_caption(
                                                  layout_alignment( layout_halignment_left | 
                                                                   layout_valignment_top ),
                                                  layout_string_resource(
                                                                         layout_resource_id( "*CityNextButtonText" ),
                                                                         layout_string( "Next" ) ),
                                                  layout_white_color,
                                                  layout_label_draw_flags(
                                                                          surf::draw_string_alignment_left|
                                                                          surf::draw_string_valignment_center),
                                                  next_button_font,
                                                  label_rects( layout_rect( 424, 8+2,  76-25,  40-5-5 ),
                                                              layout_rect(  848, 16+3, 152-50, 80-10-10 ),
                                                              layout_rect(  545, 12+2, 90-25,  49-8-8 ) ) );
                                                              
    static const layout_rects	next_button_bg(layout_rect( 0, 0, 76-25+5*2, 40-5-5+5*2 ),
												layout_rect( 0, 0, 152-50+10*2, 80-10-10+10*2 ),
												layout_rect( 0, 0, 90-25+7*2, 49-8-8+7*2 ));
	
	static const font_layout back_button_font (
						layout_font_name( "Arial-BoldMT.otf" ), //boldSystemFont
						layout_font_sizes( 16, 2*16, 18 ) );
                        
	
	static const label_layout back_button_caption(
						layout_alignment( layout_halignment_center | 
										layout_valignment_center ),
						common_resources::string_message_back,
						layout_white_color,
						layout_label_draw_flags(
							surf::draw_string_alignment_center|
							surf::draw_string_valignment_center),
						back_button_font,
						label_rects( layout_rect( 5, 0, 50, 20 ),
									 layout_rect( 10, 0, 100, 40 ),
									 layout_rect( 8, 0, 70, 30 ) ) );

	
	
	

	
	namespace message_box {

		static const dialog_layout background(
            layout_alignment( layout_halignment_center |
                          layout_valignment_center ),
            dialog_sizes( layout_size( 240, 77 ), 
                       layout_size( 480, 154 ),
                       layout_size( 298, 77 ) ) );
        
        static const font_layout title_font(
            layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
            layout_font_sizes( 17, 2*17, 24 ) );

        static const font_layout text_font(
            layout_font_name( "Arial-MT.otf" ), //ArialMT
            layout_font_sizes( 15, 2*15, 18 ) );

        static const font_layout button_font(
            layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
            layout_font_sizes( 17, 2*17, 22 ) );
        
        static const label_layout title(
                    layout_alignment( layout_halignment_fill |
                        layout_valignment_top ),
                    layout_string_resource(
                        layout_resource_id( "" ),
                        layout_string( "" ) ),
                    layout_white_color,
                    layout_label_draw_flags(
                        surf::draw_string_alignment_center|
                        surf::draw_string_valignment_top|
                        surf::draw_string_single_line ),
                    title_font,
                    label_rects( 
                        layout_rect( 0, 10, 0, 0 ),
                        layout_rect( 0, 20, 0, 0 ),
                        layout_rect( 0, 10, 0, 0 ) ) );

        static const label_layout text(
                    layout_alignment( layout_halignment_fill |
                        layout_valignment_top ),
                    layout_string_resource(
                        layout_resource_id( "" ),
                        layout_string( "" ) ),
                    layout_white_color,
                    layout_label_draw_flags(
                        surf::draw_string_alignment_center|
                        surf::draw_string_valignment_top|
                        surf::draw_string_multi_line ),
                    text_font,
                    label_rects( 
                        layout_rect( 20, 0, 0, 0 ), // x - left and right offset
                        layout_rect( 2*20, 0, 0, 0 ),
                        layout_rect( 30, 0, 0, 0 ) ) );
                        
        
        static const city_green_button_layout def_button(
                    layout_alignment( layout_halignment_center |
                             layout_valignment_bottom),
                    image_rects( 
                         layout_rect( 0, 0, 0, 24 ), 
                         layout_rect( 0, 0, 0, 48 ), // cy - streched!!!
                         layout_rect( 0, 0, 0, 40 ) ) );
        

        static const label_layout def_button_text( // allign by button
                        layout_alignment( layout_halignment_fill |
                               layout_valignment_fill ),
                        layout_string_resource(
                                      layout_resource_id( "" ),
                                      layout_string( "" ) ),
                        layout_white_color,
                        layout_label_draw_flags(
                                       surf::draw_string_alignment_center|
                                       surf::draw_string_valignment_center|
                                       surf::draw_string_single_line ),
                        text_font,
                        label_rects( 
                           layout_rect( 0, 0, 0, 0 ),
                           layout_rect( 0, 0, 0, 0 ),
                           layout_rect( 0, 0, 0, 0 ) ) );
                           
                           
                           
		static const message_box_anchor anchors[message_box_anchor_count_of] = {
        	layout_points(// message_box_top_title_offset
            	layout_point( 0, 20 ), 
                layout_point( 0, 2*20 ), 
                layout_point( 0, 20 ) ), 
            layout_points( // message_box_top_text_offset
                layout_point( 0, 20 ),
                layout_point( 0, 2*20 ), 
                layout_point( 0, 30 ) ), 
            layout_points( // message_box_top_button_offset
                layout_point( 0, 20 ), 
                layout_point( 0, 2*20 ), 
                layout_point( 0, 30 ) ), 
            layout_points( // message_box_bottom_button_offset
                layout_point( 0, 15 ), 
                layout_point( 0, 2*15 ), 
                layout_point( 0, 20 ) )
            };

        
        static const layout_vals min_button_width(
	        layout_val( 100 ),
            layout_val( 2*100 ),
            layout_val( 150 ) );
            
        static const layout_vals button_text_offset_min(
            layout_val( 30 ),
            layout_val( 2*30 ),
            layout_val( 50 ) );

    };
};

END_NAMESPACE_SQC_FRAMEWORK
