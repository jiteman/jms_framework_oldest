/*
 *  city_shop_contracts_dlg_layout.h
 *  aCountry
 *
 *  Created by Maxim Korolkov on 06.09.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SHOP_CONTRACTS_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_SHOP_CONTRACTS_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"
#include "../../country_base/dialogs/controls/sqc_balance_widget_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace city_shop_contracts_dlg_layout {
	
	// shop contracts dialog
    static const int dlg_w[] = { 480, 960, 957 };
    static const int dlg_h[] = { 320, 640, 493 };

    // CityShopSBItemsViewController 
    static const dialog_layout background(
        layout_alignment( layout_halignment_center | 
                         layout_valignment_center ),
        dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                   layout_size( dlg_w[1], dlg_h[1] ),
                   layout_size( dlg_w[2], dlg_h[2] ) ) );

	
    // shop spinboard
    static const int spinb_x[]  = { 22, 2*20, 32 };
    static const int spinb_top[]  = { 270, 2*270, 420 };
    static const int spinb_bottom[] = { 33, 58, 51 };
    static const int spinb_height[] = { spinb_top[0] - spinb_bottom[0],
        spinb_top[1] - spinb_bottom[1], 
        spinb_top[2] - spinb_bottom[2] };

    static const int spinb_width[]  = { dlg_w[0] - 2 * spinb_x[0], 
                                    dlg_w[1] - 2 * spinb_x[1], 
                                    dlg_w[2] - 2 * spinb_x[2] };

    // spinboard layout
    static const spinboard_layout
    shop_spinboard( 
        bottom_layout_alignment,
        spinboard_rects( 
            layout_rect( spinb_x[0], spinb_bottom[0], spinb_width[0], spinb_height[0] ),
            layout_rect( spinb_x[1], spinb_bottom[1], spinb_width[1], spinb_height[1] ),
						layout_rect( spinb_x[2], spinb_bottom[2], spinb_width[2], spinb_height[2] ) ) ,
				   milk::milk_spinboard_themed_left_right |
				   milk::milk_spinboard_themed_pages);
	
	// spinboard pager
	static const int pager_x[]  = { 52, 117, 32 };
	static const int pager_width[]  = { 22*5.5, 230, 150 };
    static const int pager_height[]  = { 38, 53, 48 };
    static const spinboard_pager_layout
    shop_spinboard_pager( 
						 bottom_layout_alignment,
						 spinboard_rects( 
										 layout_rect( spinb_x[0]+pager_x[0], spinb_bottom[0]-pager_height[0], pager_width[0], pager_height[0] ),
										 layout_rect( spinb_x[1]+pager_x[1], spinb_bottom[1]-pager_height[1], pager_width[1], pager_height[1] ),
										 layout_rect( spinb_x[2]+pager_x[2], spinb_bottom[2]-pager_height[2], pager_width[2], pager_height[2] ) ) );
    // balance label font
    static const font_layout 
    balance_label_font( 
        layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
        layout_font_sizes( 12, 2*12, 20 ) ); 

    ///////////////////////////////////////////////////////////////////////
    // balance, coins and bucks

    static const image_rects
    balance_widget_rects( 
          layout_rect( 5, 5, balance_widget::width[0], balance_widget::height[0] ),
          layout_rect( 2*5, 2*5, balance_widget::width[1], balance_widget::height[1] ),
          layout_rect( 7, 7, balance_widget::width[2], balance_widget::height[2] ) );

    static const layout_alignment
    balance_widget_alignment( layout_halignment_right |
                             layout_valignment_bottom);

    // shift rects left
    static const layout_rects
    balance_label_transforms( 
        layout_rect( 10 + balance_widget::width[0], 0, 0, 0 ),
        layout_rect( 2*10 + balance_widget::width[1], 0, 0, 0 ),
        layout_rect( 7 + balance_widget::width[2], 0, 0, 0 ) );

    static const label_layout
    balance_label(
        layout_alignment( layout_halignment_right |
                      layout_valignment_bottom ),
        common_resources::string_text_balance,
        layout_white_color,
        draw_flags_hright_vcenter,
        balance_label_font,
        transform_layout_rects( balance_widget_rects, balance_label_transforms ) );

}};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SHOP_CONTRACTS_DLG_LAYOUT_H_INCLUDED__


