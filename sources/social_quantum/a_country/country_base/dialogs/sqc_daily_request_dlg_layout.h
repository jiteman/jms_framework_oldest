/*
 *  sqc_daily_request_dlg_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 28.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

//#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace daily_request_layout
{
        //metrics for layout
        static const sqc::sqc_int dlg_w[] = { 480, 960, 957 };
        static const sqc::sqc_int dlg_h[] = { 320, 640, 493 };
        
        // spinboard layout
        static const sqc::sqc_int spinb_x[]    = { 20, 2*10, 25 };
        static const sqc::sqc_int spinb_top[]  = { 264, 2*264, 420 };
        static const sqc::sqc_int spinb_bottom[] = { 35, 2*35, 60 };
        static const sqc::sqc_int spinb_height[] =
                                        {  spinb_top[0] - spinb_bottom[0], // = 180
                                           spinb_top[1] - spinb_bottom[1], 
                                           spinb_top[2] - spinb_bottom[2] };
        
        static const sqc::sqc_int spinb_width[]  = 
                                        { dlg_w[0] - 2 * spinb_x[0], 
                                          dlg_w[1] - 2 * spinb_x[1], 
                                          dlg_w[2] - 2 * spinb_x[2] };
        
        // shop spinboard
        static const sqc::framework::dialog_layout background(
                                              layout_alignment( layout_halignment_center | layout_valignment_center ),
                                              dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                           layout_size(  dlg_w[1], dlg_h[1] ),
                                                           layout_size(  dlg_w[2], dlg_h[2] ) ) );
                                                           
        static const spinboard_layout   daily_request_spinboard_layout( 
                                                    bottom_layout_alignment,
                                                    spinboard_rects( 
                                                                    layout_rect( spinb_x[0],     spinb_bottom[0],
                                                                                 spinb_width[0], spinb_height[0] ),
                                                                    layout_rect( spinb_x[1],     spinb_bottom[1],
                                                                                 spinb_width[1], spinb_height[1] ),
                                                                    layout_rect( spinb_x[2],     spinb_bottom[2],
                                                                                 spinb_width[2], spinb_height[2] ) ) );
                                                                                 

    static const bevel_offsets shift_rect( bevel_offset(   26,   4,   365, 264 ),
                                           bevel_offset( 2*26, 2*4, 2*365, 2*264 ),
                                           bevel_offset(  176, 420,   342, 56 ) );
                                            
    static const bevel_offsets offset_bevel ( bevel_offset( 4,  52, 4,  29 ),
                                              bevel_offset( 8, 104, 8,  58 ),
                                              bevel_offset( 7,  70, 7,  50 ));
    
    /*                                                                                
    static const layout_string_resource
                 string_message_count( "*SimpleMessageTitle", "Message" );
     */
                 
    static const font_layout 
                    font_message_count( 
                                       layout_font_name( "Arial-BoldMT.otf" ),
                                       layout_font_sizes( 17, 2*17, 20 ) );
                                       
    static const layout_rects rect_message_count(
                                                 layout_rect( 304, 268, 145, 43 ),
                                                 layout_rect( 2*304, 2*268, 2*145, 2*43 ),
                                                 layout_rect( 568, 420, 342, 56 ) );
                 
    static const label_layout
                            layout_message_count(
                                 layout_alignment( layout_halignment_right |
                                                   layout_valignment_bottom ),
                                  common_resources::string_title_message,
                                  layout_white_color,
                                  draw_flags_hcenter_vcenter,
                                  font_message_count,
                                  rect_message_count);
                                  
    static const content_scroll_bevel_layout bevel (background, offset_bevel);
    
} // End:  daily_request

END_NAMESPACE_SQC_FRAMEWORK
