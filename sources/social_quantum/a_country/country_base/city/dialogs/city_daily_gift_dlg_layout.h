/*
 *  city_daily_gift_dlg_layout.h
 *  aCountry
 * 
 *  Created by Ivan Konnov on 22.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_DAILY_GIFT_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_DAILY_GIFT_DLG_LAYOUT_H_INCLUDED__

//#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK
 
namespace city_dlg_layout {
       namespace daily_gift_layout {
            
       //metrics for layout
       static const int dlg_w[] = { 480, 960, 593 };
       static const int dlg_h[] = { 320, 640, 431 };
       
       static const int day_offset_x[] = { 54, 108, 64 };            
                    
       static const dialog_layout background(
                                    layout_alignment( layout_halignment_center | layout_valignment_center ),
                                    /*dialog_backgrounds( "bg_daily",
                                                        "bg_daily@2x",
                                                        "bg_daily_ipad" ),*/
                                    dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                  layout_size( dlg_w[1], dlg_h[1] ),
                                                  layout_size( dlg_w[2], dlg_h[2] ) ) );
                                                   
        
        /*
         *  FONTS
         */
          
       static const font_layout 
                     font_label( 
                        layout_font_name( "Arial-BoldMT.otf" ), 
                        layout_font_sizes( 18, 36, 24 ) ); //(белый)
                          
       static const font_layout 
               font_coins_count( 
                        layout_font_name( "Arial-BoldMT.otf" ),
                        layout_font_sizes( 25, 50, 40 ) ); // color = ed2224
                      
       static const font_layout 
                 font_week_gift( 
                        layout_font_name( "Arial-BoldMT.otf" ),
                        layout_font_sizes( 18, 36, 25 ) ); // черный 
                             
       static const font_layout 
                  font_message( 
                        layout_font_name( "Arial.otf" ), 
                        layout_font_sizes( 15, 30, 18 ) ); // черный 
                          
       static const font_layout 
              font_bucks_count( 
                        layout_font_name( "Arial-BoldMT.otf" ),
                        layout_font_sizes( 40, 80, 60 ) ); // black
                        
      static const font_layout 
              font_equal( 
                        layout_font_name( "Arial.otf" ),
                        layout_font_sizes( 30, 60, 60 ) ); // black
                        
                          
      static const font_layout 
                font_megabacks( 
                        layout_font_name( "Arial.otf" ),
                        layout_font_sizes( 17, 34, 20 ) ); // black                                     
                                                
    
        /*
         *  RECTS
         */
    
       //-- Label rects
       
       static const layout_rects rect_day_gift (
                                        layout_rect( 0,  34,  200, 25 ),
                                        layout_rect( 0,  68,  400, 50 ),
                                        layout_rect( 0,  58,  260, 35 ));     
                                             
       static const layout_rects rect_week_gift (
                                        layout_rect( 0,  114,  200, 19 ),
                                        layout_rect( 0,  228,  400, 36 ),
                                        layout_rect( 0,  148,  300, 25 ));  
                                                 
       static const layout_rects rect_coins_count (
                                        layout_rect( 0,   93,  60, 28 ),
                                        layout_rect( 0,  188, 120, 50 ),
                                        layout_rect( 0,  123,  90, 40 ));    
                                                 
       static const layout_rects rect_message (
                                        layout_rect( 0,   76,  450, 34 ),
                                        layout_rect( 0,  152,  900, 68 ),
                                        layout_rect( 0,  100,  480, 46 ));  
                                                 
       static const layout_rects rect_bucks_count (
                                        layout_rect( 100,  28,  48, 40 ),
                                        layout_rect( 200,  56,  96, 80 ),
                                        layout_rect( 120,  34,  70, 60 ));  
                                        
       static const layout_rects rect_equal (
                                        layout_rect( 145,  28,  35, 40 ),
                                        layout_rect( 290,  56,  90, 80 ),
                                        layout_rect( 175,  34,  70, 60 ));  
                                                 
       static const layout_rects rect_megabucks (
                                        layout_rect( 20,  25,  95, 17 ),
                                        layout_rect( 40,  50, 190, 34 ),
                                        layout_rect( 26,  34, 110, 20 ));
             
       //-- Images Rects                                                                              
                                             
       static const image_rects rect_suitcase (
                                        layout_rect( 0,  8, 276, 175),
                                        layout_rect( 0, 16, 552, 350),
                                        layout_rect( 0, 18, 367, 232 ));
                                                
       static const image_rects rect_panel (
                                        layout_rect( 0, 11, 455, 150),
                                        layout_rect( 0, 22, 909, 300),
                                        layout_rect( 0, 24, 546, 179 ));

       static const image_rects rect_days (
                                        layout_rect( 15,   8, 438, 138),
                                        layout_rect( 30,  16, 876, 276),
                                        layout_rect( 24,  13, 508, 132));
                                        
       static const image_rects rect_icon_check (
                                        layout_rect( 50,  45, 19, 19 ),
                                        layout_rect( 100, 90, 38, 38 ),
                                        layout_rect( 76,  55, 24, 24 )); 
       
       /*
        *  STRINGS
        */
                                          
       static const layout_string_resource
           string_daily_gift( "*CityDailyGiftMessageString", "Daily gift" );
                
       static const layout_string_resource
           string_week_gift( "*CityWeeklyGiftMessageString", "Weekly gift" );
           
       static const layout_string_resource
           string_coins_count( "", "%d" );
           
       static const layout_string_resource
           string_message( "*CityComeBack5DaysMessageString", 
                           "Come back for 5 consecutive days and you get a super prize!" );
           
       //static const layout_string_resource
         //  string_bucks_count( "", " = %d" );
       static const layout_string_resource
           string_equal( "", "=" );  
        
       static const layout_string_resource
           string_bucks_count( "", "%d" );

               
       /*
        *   LAYOUTS
        */
        
       //-- shadow
       static const layout_points shadow_offsets( layout_point( 0.5, -1 ),
                                                  layout_point( 1, -2 ),
                                                  layout_point( 0.75, -1 ));
           
       static const shadow_layout shadow(layout_white_color, shadow_offsets) ;
       //--
       
       static const label_layout
               label_day_gift(
                    layout_alignment( layout_halignment_center |
                                      layout_valignment_top ),
                    string_daily_gift,
                    layout_white_color,
                    draw_flags_hcenter_vcenter,
                    font_label,
                    rect_day_gift);
                    
        static const label_layout
           label_week_gift(
                 layout_alignment( layout_halignment_center |
                                   layout_valignment_bottom ),
                 string_week_gift,
                 layout_black_color,
                 draw_flags_hcenter_vcenter,
                 font_week_gift,
                 rect_week_gift,
                 shadow);
                 
        static const label_layout
           label_coins_count(
                 layout_alignment( layout_halignment_center |
                                   layout_valignment_top ),
                 string_coins_count,
                 layout_red_color,
                 draw_flags_hcenter_vcenter,
                 font_coins_count,
                 rect_coins_count);
                 
        static const label_layout
           label_message(
                 layout_alignment( layout_halignment_center |
                                   layout_valignment_bottom ),
                 string_message,
                 layout_black_color,
                 draw_flags_hcenter_vcenter,
                 font_message,
                 rect_message,
                 shadow);
                 
        static const label_layout
           label_bucks_count(
                 layout_alignment( layout_halignment_right |
                                   layout_valignment_bottom ),
                 string_bucks_count,
                 layout_black_color,
                 draw_flags_hcenter_vcenter,
                 font_bucks_count,
                 rect_bucks_count,
                 shadow);
                 
        static const label_layout
           label_equal(
                       layout_alignment( layout_halignment_right |
                                         layout_valignment_bottom ),
                       layout_string_resource(
                                              layout_resource_id( "d" ),
                                              layout_string( "=" ) ),
                       layout_black_color,
                       draw_flags_hright_vcenter,
                       font_equal,
                       rect_equal,
                       shadow);
                 
                 
                 
        static const label_layout
           label_megabucks(
                 layout_alignment( layout_halignment_right |
                                   layout_valignment_bottom ),
                 common_resources::string_message_megabucks,
                 layout_black_color,
                 draw_flags_hcenter_vcenter,
                 font_megabacks,
                 rect_megabucks,
                 shadow);
                    
       /*
        *    IMAGES
        */
       
        // suitcase
        static const image_layout suitcase_img(
                                            layout_alignment_center_top,
                                            image_names(
                                                        "image_suitcase",
                                                        "image_suitcase@2x",
                                                        "image_suitcase_ipad"),
                                            rect_suitcase);
                                               
        static const image_layout panel_img(
                                            layout_alignment_center_bottom,
                                            image_names(
                                                        "bg_items",
                                                        "bg_items@2x",
                                                        "bg_items_ipad"),
                                            rect_panel);
                                                       
       static const image_layout days_img(                                             
                                          layout_alignment_bottom,
                                          image_names(
                                                      "image_all_days",
                                                      "image_all_days@2x",
                                                      "image_all_days_ipad"),
                                          rect_days);
                                          
       static const image_layout icon_check_img(                                             
                                          layout_alignment_left_bottom,
                                          image_names(
                                                      "icon_check_day",
                                                      "icon_check_day@2x",
                                                      "icon_check_day_ipad"),
                                          rect_icon_check);

        

        }//end: daily_gift
    }//end: city_dlg_layout
    
END_NAMESPACE_SQC_FRAMEWORK
 
#endif
