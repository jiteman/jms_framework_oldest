/*
*  city_taxadmin_settings_dlg.h
*  aCountry dialog layout
*
*  Created by Bacil on 15.08.2011.
*  Copyright 2011 Social Quantum. All rights reserved.
*
*/

#ifndef __SQC_CITY_TAXADMIN_SETTINGS_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_TAXADMIN_SETTINGS_DLG_LAYOUT_H_INCLUDED__

#include "city/dialogs/city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	namespace taxadmin_settings_dlg {

        


        static const dialog_layout
        background(
            layout_alignment( layout_halignment_center | 
                             layout_valignment_center ),
            dialog_sizes(
				layout_size( 480, 320 ),
				layout_size( 960, 640 ),
				layout_size( 676, 460 ) ) );
        
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -0.75, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        
        
        
		static const layout_string_resource dialog_title( "*TaxationOfficeTitle", "Tax administration" );
       
        
        static const image_layout
        img_icon(
            layout_alignment( layout_halignment_left | layout_valignment_bottom),
			image_names("tax_office_icon", "tax_office_icon@2x", "tax_office_icon_ipad"),
			image_rects(
                layout_rect( 16, 168, 85, 87 ),
                layout_rect( 2*16, 2*168, 2*85, 2*87 ),
                layout_rect( 44, 216, 155, 157 ) 
            ) );
            
        static const label_layout 
        lbl_description (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "*TaxationOfficeDescription", "Tax administration" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ),
				layout_font_sizes( 16, 2*16, 22 )
            ),
            label_rects(
				layout_rect( 117, 224, 296, 14 ),
				layout_rect( 2*117, 2*224, 2*296, 2*14 ),
				layout_rect( 217, 331, 211, 21 )
            ),
            shadow
        );

        static const label_layout 
        lbl_population_value (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "*PopulationLimitLabel", "Population limit: %d" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial-BoldMT.otf" ),
				layout_font_sizes( 15, 2*15, 24 )
            ),
            label_rects(
				layout_rect( 161, 176, 279, 18 ),
				layout_rect( 2*161, 2*176, 2*279, 2*18 ),
				layout_rect( 270, 232, 340, 35 )
            ),
            shadow 
        );
        
        static const int labels_up[3] = {130, 130*2, 176};
        static const int labels_bottom[3] = {92, 92*2, 84};
        
        static const label_layout 
        lbl_slider_value (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left |
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial-BoldMT.otf" ),
				layout_font_sizes( 15, 2*15, 24 )
            ),
            label_rects(
                layout_rect( 65, 136, 38, 18 ),
                layout_rect( 2*65, 2*136, 2*38, 2*18 ),
                layout_rect( 0, 0, 0, 0 )
            ) 
        );

        static const layout_rects
        rct_slider(
            layout_rect( 61, 110, 348, 30 ),
            layout_rect( 2*61, 2*110, 2*348, 2*30 ),
            layout_rect( 102, 125, 476, 37 )
        );
        
        static const layout_alignment
        	alg_slider ( layout_halignment_left | layout_valignment_bottom );
        
		static const image_layout
		img_big_coins( 
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names( "tax_big_coins_icon", 
             			  "tax_big_coins_icon@2x", 
                          "tax_big_coins_icon_ipad" ),
			layout_rects(
                layout_rect( 441, 136, 22, 28 ),
                layout_rect( 2*441, 2*136, 2*22, 2*28 ),
                layout_rect( 605, 176, 40, 40 )
			) );

		static const image_layout
		img_small_coins( 
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names( "tax_small_coins_icon", 
             			  "tax_small_coins_icon@2x", 
                          "tax_small_coins_icon_ipad" ),
			layout_rects(
                layout_rect( 21, 136, 22, 28 ),
                layout_rect( 2*21, 2*136, 2*22, 2*28 ),
                layout_rect( 44, 176, 40, 40 )
			) );

		static const image_layout
		img_high_population( 
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names( "tax_high_population_icon", 
                         "tax_high_population_icon@2x", 
                         "tax_high_population_icon_ipad" ),
			layout_rects(
                layout_rect( 21, 92, 30, 28 ),
                layout_rect( 2*21, 2*92, 2*30, 2*28 ),
                layout_rect( 34, 80, 55, 50 )
			) );

		static const image_layout
		img_low_population( 
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names( "tax_low_population_icon", 
                         "tax_low_population_icon@2x", 
                         "tax_low_population_icon_ipad" ),
			layout_rects(
                layout_rect( 441, 92, 30, 28 ),
                layout_rect( 2*441, 2*92, 2*30, 2*28 ),
                layout_rect( 597, 80, 55, 50 )
			) );
        	
        static const layout_string_resource
        str_pop_limit( "*PopulationLimitLabel", "Population limit: %.0f" );
        
        static const layout_rects 
        rct_ok (
            layout_rect( 208, 40, 64, 24 ),
            layout_rect( 2*208, 2*40, 2*64, 2*24 ),
            layout_rect( 300, 37, 80, 31 )
        );

        static const city_green_button_layout
        btn_ok( 
            layout_alignment( layout_halignment_left |
                          layout_valignment_bottom),
            rct_ok
        );

        static const label_layout 
        lbl_ok (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "*CityOKButton", "OK" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial-BoldMT.otf" ),
				layout_font_sizes( 12, 2*12, 14 )
            ),
            rct_ok,
            shadow
        );
        
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif
