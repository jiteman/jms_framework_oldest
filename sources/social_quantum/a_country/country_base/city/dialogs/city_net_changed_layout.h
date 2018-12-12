/*
 *  city_net_changed_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 21.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_NET_CHANGED_LAYOUT_H_INCLUDED__
#define __SQC_CITY_NET_CHANGED_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout
{
    namespace net_changed_layout
    {
        //metrics for layout
        static const int dlg_w[] = { 480, 960, 679 };
        static const int dlg_h[] = { 320, 640, 429 };
    
        static const dialog_layout background(
                                              layout_alignment( layout_halignment_center | layout_valignment_center ),
                                              dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                           layout_size( dlg_w[1], dlg_h[1] ),
                                                           layout_size( dlg_w[2], dlg_h[2] ) ) );
    
        
        //
        // Shadow
        //
        static const layout_points shadow_offsets( layout_point( -0.5, 1 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -1, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        
        //
        // Fonts
        //
        
        // Lower message have the same fonts
        static const font_layout 
        font_upper_message( 
                         layout_font_name( "Arial-BoldMT.otf" ),
                         layout_font_sizes( 16, 32, 18 ) );
                         
        static const font_layout 
        font_step_message( 
                           layout_font_name( "Arial.otf" ),
                           layout_font_sizes( 14, 22, 16 ) );
                           
        static const font_layout 
        font_step_number( 
                          layout_font_name( "Arial-BoldMT.otf" ),
                          layout_font_sizes( 48, 90, 80 ) );
                          
        // color for step number 
        static const layout_color
        	layout_step_color( 0., 0., 0., 0.3 );
        
        //
        // Rects
        //
                                                
        static const image_rects rect_enter_image (
                                                layout_rect( 0,  80, 418, 131),
                                                layout_rect( 0, 160, 838, 262),
                                                layout_rect( 0, 100, 570, 176 ));
                                                
        static const image_rects rect_upper_message (
                                                 layout_rect( 0,  65, 400, 18),
                                                 layout_rect( 0, 130, 800, 36),
                                                 layout_rect( 0,  90, 600, 26 ));
                                                 
        static const image_rects rect_lower_message (
                                                     layout_rect( 35,  85, 400, 18),
                                                     layout_rect( 70, 170, 800, 36),
                                                     layout_rect( 50, 115, 600, 26 ));
                                                     
        static const image_rects rect_step_message_1 (
                                                     layout_rect( 80,  18, 100, 58),
                                                     layout_rect( 160, 36, 200, 116),
                                                     layout_rect( 120,  26, 150, 80 ));
                                                     
        static const image_rects rect_step_message_2 (
                                                      layout_rect( 230,  18, 100, 58),
                                                      layout_rect( 460,  36, 200, 116),
                                                      layout_rect( 340,  26, 150, 80 ));
                                                      
        static const image_rects rect_step_message_3 (
                                                      layout_rect( 375,  18,  100, 54),
                                                      layout_rect( 750,  36,  200, 110),
                                                      layout_rect( 537,   26, 120, 80 ));
        
        //-- separator rects
        static const image_rects rect_separator (
                                                 layout_rect( 0,  0,  2, 61),
                                                 layout_rect( 0,  0,  4, 123),
                                                 layout_rect( 0,  0,  4, 79 ));
                                                                                                                          
        static const image_rects rect_parent_separator_1 (
                                                   layout_rect( 70,  8, 2, 61),
                                                   layout_rect( 140, 16, 4, 123),
                                                   layout_rect( 110, 12, 4, 79 ));
        
        static const image_rects rect_parent_separator_2 (
                                                   layout_rect( 220,  8, 2, 61),
                                                   layout_rect( 440, 16, 4, 123),
                                                   layout_rect( 330, 12, 4, 79 ));
        
        static const image_rects rect_parent_separator_3 (
                                                   layout_rect( 365,  8, 2, 61),
                                                   layout_rect( 730, 16, 4, 123),
                                                   layout_rect( 530, 12, 4, 79 ));
        
        static const image_rects separator_rects [] = { rect_parent_separator_1,
                                                        rect_parent_separator_2,
                                                        rect_parent_separator_3 };
        //--
        
        
        //-- label steps                                              
        static const image_rects rect_step_1 (
                                              layout_rect( 10,  9,  50, 60),
                                              layout_rect( 20, 16, 100, 123),
                                              layout_rect( 15, 13,  75, 79 ));
        
        static const image_rects rect_step_2 (
                                              layout_rect( 160,  9,  50,  60),
                                              layout_rect( 320, 16, 100, 123),
                                              layout_rect( 240, 13,  75,  79 ));
        
        static const image_rects rect_step_3 (
                                              layout_rect( 305,  9,  50, 60),
                                              layout_rect( 610, 16, 100, 123),
                                              layout_rect( 455, 13,  75, 79 ));
        
        static const image_rects step_rects [] = { rect_step_1,
                                                   rect_step_2,
                                                   rect_step_3 };
        //--
        
        //
        // String
        //
        
        static const layout_string_resource
        string_enter_caption( "*CityEnterCaption", "Information" );
        
        static const layout_string_resource
        string_enter_upper_message( "*CityEnterUpperMessage", "You already have a City at %s" );
        
        static const layout_string_resource
        string_enter_lower_message( "*CityEnterLowerMessage", "To return to the local City:" );
        
        static const layout_string_resource
        string_enter_step_1( "*CityEnterStep1", "Enter \"Options\" menu" );
        
        static const layout_string_resource
        string_enter_step_2( "*CityEnterStep2", "Select \"Change Game Network\"" );
        
        static const layout_string_resource
        string_enter_step_3( "*CityEnterStep3", "Select \n \"Local City\"" );
        
        static const layout_string_resource
        string_step_number( "", "%i" );
        
        //
        // Image
        //
                                               
        static const image_layout enter_image_img(
                                               layout_alignment_center_top,
                                               image_names(
                                                           "city_enter_image",
                                                           "city_enter_image@2x",
                                                           "city_enter_image_ipad"),
                                               rect_enter_image);
                                               
        static const image_layout separator_img(
                                               layout_alignment_left_bottom,
                                               image_names(
                                                           "city_enter_separator",
                                                           "city_enter_separator@2x",
                                                           "city_enter_separator_ipad"),
                                               rect_separator);
                                               
        //
        // LAYOUTS
        //
        
        static const label_layout
        label_upper_message(
                          layout_alignment( layout_halignment_center |
                                           layout_valignment_top ),
                          string_enter_upper_message,
                          layout_white_color,
                          draw_flags_hcenter_vcenter,
                          font_upper_message,
                          rect_upper_message,
                          shadow);
                          
        static const label_layout
        label_lower_message(
                            layout_alignment( layout_halignment_left |
                                              layout_valignment_bottom ),
                            string_enter_lower_message,
                            layout_white_color,
                            draw_flags_hleft_vcenter,
                            font_upper_message,
                            rect_lower_message,
                            shadow);
                            
        static const label_layout
        label_enter_step_1(
                            layout_alignment( layout_halignment_left |
                                             layout_valignment_bottom ),
                            string_enter_step_1,
                            layout_white_color,
                            draw_flags_hleft_vcenter,
                            font_step_message,
                            rect_step_message_1,
                            shadow);
                            
        static const label_layout
        label_enter_step_2(
                            layout_alignment( layout_halignment_left |
                                             layout_valignment_bottom ),
                            string_enter_step_2,
                            layout_white_color,
                            draw_flags_hleft_vcenter,
                            font_step_message,
                            rect_step_message_2,
                            shadow);
                            
        static const label_layout
        label_enter_step_3(
                            layout_alignment( layout_halignment_left |
                                             layout_valignment_bottom ),
                            string_enter_step_3,
                            layout_white_color,
                            draw_flags_hleft_vcenter,
                            font_step_message,
                            rect_step_message_3,
                            shadow);
                            
        static const label_layout
        label_step_number(
                 layout_alignment( layout_halignment_left |
                                   layout_valignment_bottom ),
                 string_step_number,
                 layout_step_color,
                 draw_flags_hcenter_vcenter,
                 font_step_number,
                 step_rects[0]);
    }
}

END_NAMESPACE_SQC_FRAMEWORK

#endif