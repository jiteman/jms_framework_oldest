/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_BUY_BUILDING_BASE_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_BUY_BUILDING_BASE_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout { namespace buy_building_base_dlg {
	
    static const int dlg_w[] = { 480, 960, 955 };
    static const int dlg_h[] = { 320, 640, 569 };
    
    // CityShopSBItemsViewController 
    static const dialog_layout background(
        layout_alignment( layout_halignment_center | 
                         layout_valignment_center ),
        dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                   layout_size( dlg_w[1], dlg_h[1] ),
                   layout_size( dlg_w[2], dlg_h[2] ) ) );

	
    

  	
    //////////////////////////////////////////////////////////
    // category image
    static const layout_alignment
    category_item_image_alignment( layout_halignment_left |
                                  layout_valignment_top |
                                  layout_valignment_no_height);
    
    static const image_rects
    category_item_image_rects(
                              layout_rect( 20, 130, 120, 60 ),
                              layout_rect( 2*20, 2*130, 2*120, 2*60 ),
                              layout_rect( 60, 180, 120, 60 )  );
	
	
    /*
    static const image_layout
    category_image(
        layout_alignment( layout_halignment_left |
                        layout_valignment_top |
                        layout_valignment_no_height ),
        image_names( "", "", "" ),
        image_rects( 
            layout_rect( 20, 130, 120, 60 ),
            layout_rect( 2*20, 2*130, 2*120, 2*60 ),
            layout_rect( 60, 180, 120, 60 ) ) );
    */
    //////////////////////////////////////////////////////////
    // category description
    static const font_layout 
    descr_label_font( 
           layout_font_name( "Arial.otf" ), //Arial
           layout_font_sizes( 11, 2*11, 18 ) );
    
    static const label_layout
    descr_label(
                layout_alignment( layout_halignment_left |
                                /*layout_valignment_top |*/
                                layout_valignment_center ),
                layout_string_resource( "", "" ),
                layout_black_color,
                draw_flags_hleft_vtop,
                descr_label_font,
                label_rects( layout_rect( 150,  50, 310, 50 ),
                            layout_rect(  300, 100, 2*310, 2*50 ),
                            layout_rect(  200, 100, 680, 110 ) ) );
                
    
    //////////////////////////////////////////////////////////
    // shop spinboard
    static const int spinb_x[]  = { 13, 2*13, 30 };
    static const int spinb_top[]  = { 175, 2*175, 310 };
    static const int spinb_bottom[]  = { 24, 2*24, 35 };
    
    static const int spinb_w[]  = { dlg_w[0] - 2 * spinb_x[0], 
                                    dlg_w[1] - 2 * spinb_x[1], 
                                    dlg_w[2] - 2 * spinb_x[2] };
    static const int spinb_h[]  = { spinb_top[0] - spinb_bottom[0], 
                                    spinb_top[1] - spinb_bottom[1], 
                                    spinb_top[2] - spinb_bottom[2] };
    
    // spinboard layout
    static const spinboard_layout
    construction_spinboard( 
        bottom_layout_alignment,
        spinboard_rects( 
            layout_rect( spinb_x[0], spinb_bottom[0], spinb_w[0], spinb_h[0] ),
            layout_rect( spinb_x[1], spinb_bottom[1], spinb_w[1], spinb_h[1] ),
            layout_rect( spinb_x[2], spinb_bottom[2], spinb_w[2], spinb_h[2] ) ));
	
	
	// spinboard pager
	static const int pager_width[]  = { 22*5.5, 230, 150 };
	static const int pager_height[]  = { 24, 24*2, 36 };
	static const spinboard_pager_layout
	construction_spinboard_pager( 
							 bottom_layout_alignment,
							 spinboard_rects( 
											 layout_rect( spinb_x[0]+(spinb_w[0]-pager_width[0])/2, spinb_bottom[0]-pager_height[0], pager_width[0], pager_height[0] ),
											 layout_rect( spinb_x[1]+(spinb_w[1]-pager_width[1])/2, spinb_bottom[1]-pager_height[1], pager_width[1], pager_height[1] ),
											 layout_rect( spinb_x[2]+(spinb_w[2]-pager_width[2])/2, spinb_bottom[2]-pager_height[2], pager_width[2], pager_height[2] ) ) );
	
	
	static const int borders[] = { 7,7*2,12 };
	static const sqc_shop_item_bevel_layout item_bevel( layout_halignment_left |
													   layout_valignment_top,  apply_layout_ofssets(background.sizes(),
																									layout_rects(layout_rect( content_offset_lr[0]+borders[0], content_offset_top[0]+borders[0], content_offset_lr[0]+borders[0], content_offset_btm[0]+spinb_h[0]+borders[0]*3 ),
																												 layout_rect( content_offset_lr[1]+borders[1], content_offset_top[1]+borders[1], content_offset_lr[1]+borders[1], content_offset_btm[1]+spinb_h[1]+borders[1]*3 ),
																												 layout_rect( content_offset_lr[2]+borders[2], content_offset_top[2]+borders[2], content_offset_lr[2]+borders[2], content_offset_btm[2]+spinb_h[2]+borders[2]*3 ) )) );
	
    static const city_horizontal_clear_separator_layout separator_h1( 
																	 layout_alignment( layout_valignment_bottom ),
																	 separator_offsets( spinb_h[0]+borders[0]*2-8,spinb_h[1]+borders[1]*2,spinb_h[2]+borders[2]*2) );
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_BUY_CONSTRUCTION_DLG_LAYOUT_H_INCLUDED__


