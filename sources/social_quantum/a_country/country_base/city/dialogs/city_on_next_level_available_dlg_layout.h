/*
 *  city_on_next_level_available_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 12.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */
 
#ifndef __SQC_CITY_ON_NEXT_LEVEL_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_ON_NEXT_LEVEL_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"
#include "../../country_base/dialogs/controls/sqc_balance_widget_layout.h"

NAMESPACE_SQC_FRAMEWORK


namespace city_dlg_layout
{
    namespace next_level_available
    {
    
        //metrics for layout
        static const sqc_int dlg_w[] = { 480, 960, 619 };
        static const sqc_int dlg_h[] = { 320, 640, 589 };
        
        // spinboard layout
        static const sqc_int spinb_x[]  = { 22, 2*20, 32 };
        static const sqc_int spinb_top[]  = { 240-30, 2*240-60, 420 };
        static const sqc_int spinb_bottom[] = { 19, 2*19, 46 };
        static const sqc_int spinb_height[] = {  spinb_top[0] - spinb_bottom[0],
            spinb_top[1] - spinb_bottom[1], 
            spinb_top[2] - spinb_bottom[2] };
        
        static const sqc_int spinb_width[]  = { dlg_w[0] - 2 * spinb_x[0], 
            dlg_w[1] - 2 * spinb_x[1], 
            dlg_w[2] - 2 * spinb_x[2] };
            
        // shop spinboard
        static const sqc_dword cell_count = 3;
        
        static  dialog_layout background(
                                              layout_alignment( layout_halignment_center | layout_valignment_center ),
                                              /*dialog_backgrounds( "level_up_back_1",
                                                                  "level_up_back_1@2x",
                                                                  "next_level_back_ipad" ),*/
                                              dialog_sizes( layout_size(  dlg_w[0], dlg_h[0] ),
                                                            layout_size(  dlg_w[1], dlg_h[1] ),
                                                            layout_size(  dlg_w[2], dlg_h[2] ) ) );
                                                           
        static const spinboard_layout   on_next_level_spinboard_layout( 
                                        bottom_layout_alignment,
                                        spinboard_rects( 
                                                 layout_rect( spinb_x[0],     spinb_bottom[0],
                                                              spinb_width[0], spinb_height[0] ),
                                                 layout_rect( spinb_x[1],     spinb_bottom[1],
                                                              spinb_width[1], spinb_height[1] ),
                                                 layout_rect( spinb_x[2],     spinb_bottom[2],
                                                              spinb_width[2], spinb_height[2] ) ),
																	   milk::milk_spinboard_themed_left_right);
		
		// spinboard pager
		static const int pager_width[]  = { 22*5.5, 230, 150 };
		static const int pager_y[]  = { -5, -5*2, 10 };
		static const int pager_height[]  = { 12, 12*2, 32 };
		static const spinboard_pager_layout
		on_next_level_spinboard_pager( 
								 bottom_layout_alignment,
								 spinboard_rects( 
												 layout_rect( spinb_x[0]+(spinb_width[0]-pager_width[0])/2, spinb_bottom[0]-pager_height[0]-pager_y[0], pager_width[0], pager_height[0] ),
												 layout_rect( spinb_x[1]+(spinb_width[1]-pager_width[1])/2, spinb_bottom[1]-pager_height[1]-pager_y[1], pager_width[1], pager_height[1] ),
												 layout_rect( spinb_x[2]+(spinb_width[2]-pager_width[2])/2, spinb_bottom[2]-pager_height[2]-pager_y[2], pager_width[2], pager_height[2] ) ) );
                                                              
                                                                        
        static const font_layout 
        label_font( 
                   layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                   layout_font_sizes( 14, 2*14, 20 ) );
                   
        static const layout_rects label_rect (
                                              layout_rect( 120, 240,  250, 40 ),
                                              layout_rect( 240, 454,  500, 80 ),
                                              layout_rect( 145, 415,  342, 50 ) );  
                                              
        static const label_layout
        label(
              layout_alignment( layout_halignment_right |
                                layout_valignment_bottom ),
              layout_string_resource( "*CityLevelUpNextLevelObjects", "These objects will be \n available to you on the next level:" ),
              layout_white_color,
              draw_flags_hcenter_vcenter,
              label_font,
              label_rect);
    
    }// END: next_level_available
    
    
}// END: city_dlg_layout


END_NAMESPACE_SQC_FRAMEWORK

#endif