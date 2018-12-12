/*
 *  city_level_up_dlg_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 08.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */


#ifndef __SQC_CITY_LEVEL_UP_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_LEVEL_UP_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"
#include "../../country_base/dialogs/controls/sqc_balance_widget_layout.h"

NAMESPACE_SQC_FRAMEWORK


namespace city_dlg_layout
{
    namespace level_up_dlg
    {
        //metrics for layout
        static const sqc_int dlg_w[] = { 480, 960, 619 };
        static const sqc_int dlg_h[] = { 320, 640, 619 };
        
        // spinboard layout
        static const sqc_int spinb_x[]    = { 22, 2*20, 32 };
        static const sqc_int spinb_top[]  = { 205, 2*205, 340 };
        static const sqc_int spinb_bottom[] = { 17, 2*17, 46 };
        static const sqc_int spinb_height[] = {  spinb_top[0] - spinb_bottom[0], // = 180
            spinb_top[1] - spinb_bottom[1], 
            spinb_top[2] - spinb_bottom[2] };
        
        static const sqc_int spinb_width[]  = { dlg_w[0] - 2 * spinb_x[0], 
            dlg_w[1] - 2 * spinb_x[1], 
            dlg_w[2] - 2 * spinb_x[2] };
        
        // shop spinboard
        static const sqc_dword cell_count = 3;
        
		static const dialog_backgrounds backgrounds( "level_up_back_nowall", 
						   "level_up_back_nowall@2x", 
						   "level_up_back_iPad_nowall" );
        static const dialog_layout dialog(
                                      layout_alignment( layout_halignment_center | layout_valignment_center ),
                                      dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                   layout_size(  dlg_w[1], dlg_h[1] ),
                                                   layout_size(  dlg_w[2], dlg_h[2] ) ) );
                                                   
        static const image_layout hat(
                                      top_layout_alignment,
                                      image_names(
                                                  "","","level_up_head_ipad"),
                                      image_rects(
                                                  layout_rect( 0, 0, 0, 0 ),
                                                  layout_rect( 0, 0, 0, 0 ),
                                                  layout_rect( 60, 50, 505, 186 )));
        
        static const spinboard_layout level_up_spinboard_layout( 
                                        bottom_layout_alignment,
                                        spinboard_rects( 
                                                        layout_rect( spinb_x[0], spinb_bottom[0],
                                                                     spinb_width[0], spinb_height[0] ),
                                                        layout_rect( spinb_x[1], spinb_bottom[1],
                                                                     spinb_width[1], spinb_height[1] ),
                                                        layout_rect( spinb_x[2], spinb_bottom[2],
                                                                     spinb_width[2], spinb_height[2] ) ) ,
																milk::milk_spinboard_themed_left_right); 
		
		// spinboard pager
		static const int pager_width[]  = { 22*5.5, 230, 150 };
		static const int pager_y[]  = { 0, 0, 10 };
		static const int pager_height[]  = { 12, 12*2, 32 };
		static const spinboard_pager_layout
		level_up_spinboard_pager( 
							 bottom_layout_alignment,
							 spinboard_rects( 
											 layout_rect( spinb_x[0]+(spinb_width[0]-pager_width[0])/2, spinb_bottom[0]-pager_height[0]-pager_y[0], pager_width[0], pager_height[0] ),
											 layout_rect( spinb_x[1]+(spinb_width[1]-pager_width[1])/2, spinb_bottom[1]-pager_height[1]-pager_y[1], pager_width[1], pager_height[1] ),
											 layout_rect( spinb_x[2]+(spinb_width[2]-pager_width[2])/2, spinb_bottom[2]-pager_height[2]-pager_y[2], pager_width[2], pager_height[2] ) ) );
                                                            
        static const font_layout 
        label_font( 
                   layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                   layout_font_sizes( 12, 2*12, 18 ) );
                   
        static const font_layout 
        label_level_up_font( 
                   layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                   layout_font_sizes( 26, 2*26, 38 ) );    
            

        static const layout_rects label_rect (
                                              layout_rect( 67,  223,   174, 40 ),
                                              layout_rect( 134, 446, 2*174, 80 ),
                                              layout_rect( 63,  388,   490, 40 ) );     // надпись
        
        static const layout_rects label_Level_up_rect (
                                              layout_rect( 150,  247,   50,  40 ),
                                              layout_rect( 300,  490,  100, 80 ),
                                              layout_rect( 267,  440,   80,  50 ) );    // цифры       
        
                                  
        static const layout_string_resource
        label_with_string( "*CityLevelUpWithItemsString", "You receive %d and %d bucks. Now available: " );
        
  
        static const label_layout
        label(
              layout_alignment( layout_halignment_right |
                                layout_valignment_bottom ),
              label_with_string,
              layout_white_color,
              draw_flags_hcenter_vcenter,
              label_font,
              label_rect);
              
        static const layout_string_resource
        label_level( "*CityLevelUpLevel", "%d" );
              
        static const label_layout
        label_level_up(
              layout_alignment( layout_halignment_left |
                               layout_valignment_bottom ),
              label_level,
              layout_red_color,
              draw_flags_hcenter_vcenter,
              label_level_up_font,
              label_Level_up_rect);
                                                                
                                                          
    }//END: namespace level_up
}//END: namespace city_dlg_layout   

END_NAMESPACE_SQC_FRAMEWORK
              
#endif