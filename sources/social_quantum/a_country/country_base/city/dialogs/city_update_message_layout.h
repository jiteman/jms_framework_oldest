/*
 *  city_update_message_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 24.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */


#ifndef __SQC_CITY_UPDATE_MESSAGE_LAYOUT_H_INCLUDED__
#define __SQC_CITY_UPDATE_MESSAGE_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout
{
    namespace city_update_message_layout
    {
        //metrics for layout
        static const int dlg_w[] = { 480, 960, 611 };
        static const int dlg_h[] = { 320, 640, 617 };
        
        //-- metrics for spinboard
        static const sqc_int spinb_x[]      = { 22, 2*20, 32 };
        static const sqc_int spinb_top[]    = { 240-30, 2*240-60, 420 };
        static const sqc_int spinb_bottom[] = { 17, 2*17, 40 };
        static const sqc_int spinb_height[] = {  spinb_top[0] - spinb_bottom[0],
                                                 spinb_top[1] - spinb_bottom[1], 
                                                 spinb_top[2] - spinb_bottom[2] - 100 };
            
        static const sqc_int spinb_width[]  = { dlg_w[0] - 2 * spinb_x[0], 
                                                dlg_w[1] - 2 * spinb_x[1], 
                                                dlg_w[2] - 2 * spinb_x[2] };
        //--
            
        static const spinboard_layout
        layout_spinboard( 
                          bottom_layout_alignment,
                          spinboard_rects( 
                                          layout_rect( spinb_x[0],     spinb_bottom[0],
                                                       spinb_width[0], spinb_height[0] ),
                                          layout_rect( spinb_x[1],     spinb_bottom[1],
                                                       spinb_width[1], spinb_height[1] ),
                                          layout_rect( spinb_x[2],     spinb_bottom[2],
                                                       spinb_width[2], spinb_height[2] ) ),
                          milk::milk_spinboard_themed_left_right);
            
		static const dialog_backgrounds backgrounds( "updates_window_back",
								 "updates_window_back@2x",
								 "" );
        // background layout
        static const dialog_layout dialog(
                                              layout_alignment( layout_halignment_center | layout_valignment_center ),
                                              
                                              dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                           layout_size( dlg_w[1], dlg_h[1] ),
                                                           layout_size( dlg_w[2], dlg_h[2] ) ) );
        
        // title rect
        static const image_rects rect_title (
                                              layout_rect( 137,  31, 250,  57),
                                              layout_rect( 274,  62, 500, 114),
                                              layout_rect( 213, 230, 310,  40 ));
        // image rect for iPad                                      
        static const image_rects rect_image (
                                             layout_rect( 0,  0,    0,   0),
                                             layout_rect( 0,  0,    0,   0),
                                             layout_rect( 0, 78,  553, 208 ));
        // title rect for iPad specific
        static const image_rects rect_title_ipad (
                                             layout_rect(  0,  0,   0,   0),
                                             layout_rect(  0,  0,   0,   0),
                                             layout_rect( 50, 23, 510,  40 ));    
                                             
        // title font                                                                                    
        static const font_layout 
        font_title( 
                   layout_font_name( "Arial-BoldMT.otf" ),
                   layout_font_sizes( 22, 44, 14 ) );
                   
        // title font for iPad specific                                                                                     
        static const font_layout 
        font_title_ipad( 
                   layout_font_name( "Arial-BoldMT.otf" ),
                   layout_font_sizes( 0, 0, 24 ) );
                     
        // title string for iPhone
        static const layout_string_resource
        string_title( "*CityUpdateMassageDescription", " New objects in  game available:" );
        
        
        // title string for iPad
        static const layout_string_resource
        string_title_ipad( "*UIUpdateMessageTitle", " About update" );
        
        // title layout (label)
        static const label_layout
        label_title(
                   layout_alignment( layout_halignment_left |
                                     layout_valignment_top ),
                            string_title,
                            layout_white_color,
                            draw_flags_hleft_vcenter,
                            font_title,
                            rect_title);
                            
        // title layout (iPad specific)
        static const label_layout
        label_title_ipad(
                    layout_alignment( layout_halignment_left |
                                      layout_valignment_top ),
                    string_title_ipad,
                    layout_white_color,
                    draw_flags_hcenter_vcenter,
                    font_title_ipad,
                    rect_title_ipad);
                    
        // iPad image layout         
        static const image_layout
        update_img(
                   layout_alignment_center_top,
                   image_names(
                               "",
                               "",
                               "updates_pic"),
                   rect_image);
                   
                   
        // spinboard pager           
        static const int pager_width[]  = { 22*5.5, 230, 150 };
        static const int pager_height[] = { 38,      53,  48 };
        
        static const spinboard_pager_layout
        spinboard_pager( 
                        layout_alignment_center_bottom,
                        spinboard_rects( 
                                        layout_rect( 0, 0, pager_width[0], pager_height[0] ),
                                        layout_rect( 0, 0, pager_width[1], pager_height[1] ),
                                        layout_rect( 0, -5, pager_width[2], pager_height[2] ) ) );
    }
}

END_NAMESPACE_SQC_FRAMEWORK

#endif