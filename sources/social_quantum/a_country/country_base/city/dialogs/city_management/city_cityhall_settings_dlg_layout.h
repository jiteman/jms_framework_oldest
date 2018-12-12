/*
 *  city_cityhall_hire_dlg_layout.h
 *  aCountry
 *
 *  Created by Василий on 09.08.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_CITYHALL_SETTINGS_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_CITYHALL_SETTINGS_DLG_LAYOUT_H_INCLUDED__

#include "city/dialogs/city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	namespace cityhall_settings_dlg {

        static const dialog_layout background(
            layout_alignment( layout_halignment_center | 
                             layout_valignment_center ),
            dialog_sizes(
				layout_size( 480, 320 ),
				layout_size( 960, 640 ),
				layout_size( 676, 406 ) ) );

        //shadow
        static const layout_points shadow_offsets( layout_point( -0.5, 01 ),
                                                  layout_point( -1, 2 ),
                                                  layout_point( -0.75, 1 ));
        
        static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
        

		// separtors
		static const city_horizontal_clear_separator_layout separator_h1( 
															 layout_alignment( layout_valignment_top ),
															 separator_offsets( 70,70*2,80) );
		static const city_horizontal_clear_separator_layout separator_h2( 
																		 layout_alignment( layout_valignment_top ),
																		 separator_offsets( 190,190*2,230) );
		static const city_vertical_clear_separator_layout separator_v( 
															layout_alignment( layout_halignment_center ),
															separator_offsets( 0,0,0),
															separator_offsets( 70,70*2,78),
															separator_offsets( 51,51*2,83) );
		
		static const layout_string_resource dialog_title(
				 layout_resource_id( "*CityHall" ),
				 layout_string( "City Hall" ));
        
  

        static const label_layout 
        lbl_common_header (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "*CityHallInfo", 
            	"City Hall allow you to hire your friends as Tax agents or \
Administrators officails and you ability to automate process of tax collection and population census" ), 

            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ),	//Arial
				layout_font_sizes( 12, 2*12, 16 )
            ),
            label_rects(
				layout_rect( 21, 217, 439, 30 ),
				layout_rect( 2*21, 2*217, 2*439, 2*30 ),
				layout_rect( 42, 274, 591, 40 )
            ),
            shadow
        );

        static const label_layout 
        lbl_budget (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "*CityHallBudjet", "Budget" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial-BoldMT.otf" ),	//Arial
				layout_font_sizes( 14, 2*14, 18 )
            ),
            label_rects(
				layout_rect( 71, 53, 168, 17 ),
				layout_rect( 2*71, 2*53, 2*168, 2*17 ),
				layout_rect( 119, 63, 211, 21 )
            ),
            shadow 
        );
        
        
        static const layout_string_resource 
        res_operation( "*CityHallOperation", "You have %d operation available" );
        
        static const label_layout 
        lbl_operation (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            res_operation,
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ),	//Arial
				layout_font_sizes( 11, 2*11, 16 )
            ),
            label_rects(
				layout_rect( 71, 40, 170, 12 ),
				layout_rect( 2*71, 2*40, 2*170, 2*12 ),
				layout_rect( 119, 42, 270, 21 )
            ),
            shadow 
        );
        
        static const city_green_button_layout
        btn_refill( 
            layout_alignment( layout_halignment_left |
                          layout_valignment_bottom),
            image_rects( 
            	layout_rect( 252, 40, 85, 24 ),
                layout_rect( 2*252, 2*40, 2*85, 2*24 ),
                layout_rect( 398, 47, 95, 30 ) 
            ) );

		static const label_layout 
        lbl_refill(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			layout_string_resource( "*CityHallRefil", "Refill" ),
			layout_white_color,
            layout_label_draw_flags(
				surf::draw_string_alignment_center | 
                surf::draw_string_valignment_center 
            ),
			font_layout (
            	layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                layout_font_sizes( 12, 12*2, 14 )
            ),
			label_rects(
            	layout_rect( 0, 0, 85, 24 ),
                layout_rect( 0, 0, 2*85, 2*24 ),
                layout_rect( 0, 0, 95, 30 ) 
            ),
            shadow 
        );

		static const image_button_layout
        btn_coins( 
			layout_alignment( layout_halignment_right | layout_valignment_bottom),
			image_names(
            	"add_coins_small_button_0",
				"add_coins_small_button_0@2x",
                "add_coins_button_ipad_0"
            ), 
			image_pressed_names(
            	"add_coins_small_button_1",
				"add_coins_small_button_1@2x",
                "add_coins_button_ipad_1"
            ),
			image_rects(
            	layout_rect(  50, 271, 116, 40 ),
				layout_rect( 100, 2*271, 2*116, 2*40 ),
				layout_rect( 72, 348, 199, 48 )
            )
        );
        
        static const image_layout
        image_budget( 
                  layout_alignment( layout_halignment_left | layout_valignment_bottom),
                  image_names(
                              "icon_budget",
                              "icon_budget@2x",
                              "icon_budget_ipad"
                              ), 
                  image_rects(
                              layout_rect(  20,   36, 41, 41 ),
                              layout_rect(  40,   72, 82, 82 ),
                              layout_rect(  50,   40, 54, 54 )
                              )
                  );

		static const label_layout
        lbl_coins(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			common_resources::string_title_add_coins,
			layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
            font_layout(
            	layout_font_name( "Arial-BoldMT.otf" ), //ArialBT
            	layout_font_sizes( 14, 2*14, 18 )
            ),
            label_rects(
            	layout_rect( 40, 0, 70, 40 ),
				layout_rect( 2*40, 0, 2*70, 2*40 ),
				layout_rect( 40, 0, 155, 48  )
            ),
            shadow 
        );

		////////////////////////////// Agents //////////////////////
        static const layout_rects
        rct_fiscal_agent (
            layout_rect( 21, 94, 218, 87 ),
            layout_rect( 2*21, 2*94, 2*218, 2*87 ),
            layout_rect( 42, 120, 288, 122 )
		);
        
        static const layout_rects
        rct_municipality_officer (
            layout_rect( 252, 94, 218, 87 ),
            layout_rect( 2*252, 2*94, 2*218, 2*87 ),
            layout_rect( 355, 120, 288, 122 )
		);

		////////////////////////////// Agent's componets //////////////////////
        static const image_layout
        img_pers_avatar(
            layout_alignment( layout_halignment_center | layout_valignment_center),
			image_names("", "", ""),
			image_rects(
                layout_rect( 0, 0, 45, 61 ),
                layout_rect( 0, 0, 45, 61 ),
                layout_rect( 0, 0, 45, 61 ) 
            ) );

        static const sqc_shop_item_button_layout
        btn_pers_bg( 
            layout_alignment( layout_halignment_left |
                          layout_valignment_bottom),
            image_rects( layout_rect( 0, 0, 86, 87 ),
                         layout_rect( 0, 0, 2*86, 2*87 ),
                         layout_rect( 0, 0, 117, 122 ) ));
        
		static const image_layout
        img_pers_tax_agent(
            layout_alignment( layout_halignment_center | layout_valignment_center),
			image_names( "", "", "" ),
			image_rects(
                layout_rect( 0, 0, 45, 90 ),
                layout_rect( 0, 0, 76, 90 ),
                layout_rect( 0, 0, 76, 90 ) ) );

		static const image_layout
        img_municipality_oficer (
            layout_alignment( layout_halignment_center | layout_valignment_center),
			image_names(
            	"municipality_officer_icon",
            	"municipality_officer_icon@2x",
				"municipality_officer_icon_ipad"
            ),
			image_rects(
                layout_rect( 0, 0, 42, 61 ),
                layout_rect( 0, 0, 42, 61 ),
                layout_rect( 0, 0, 42, 61 ) ) );


        static const label_layout 
        lbl_pers_name (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial-BoldMT.otf" ),	//Arial
				layout_font_sizes( 12, 2*12, 14 )
            ),
            label_rects(
				layout_rect( 97, 56, 113, 31 ),
				layout_rect( 2*97, 2*56, 2*113, 2*31 ),
				layout_rect( 135, 94, 153, 23 )
            ),
            shadow 
        );

        static const label_layout 
        lbl_pers_descr (
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left|
                surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ), //Arial
				layout_font_sizes( 12, 2*12, 16 )
            ),
            label_rects(
				layout_rect( 97, 42, 113, 14 ),
				layout_rect( 2*97, 2*42, 2*113, 2*14 ),
				layout_rect( 135, 49, 153, 23 )
            ),
            shadow 
        );

        static const city_buy_button_layout
        btn_pers_action( 
            layout_alignment( layout_halignment_left |
                          layout_valignment_bottom),
            image_rects( 
            	layout_rect( 97, 0, 64, 24 ),
                layout_rect( 2*97, 0, 2*64, 2*24 ),
                layout_rect( 135, 0, 78, 30 ) 
            ));

		static const label_layout 
        lbl_pers_action(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			layout_string_resource( "", "" ),
			layout_white_color,
            layout_label_draw_flags(
				surf::draw_string_alignment_center | 
                surf::draw_string_valignment_center 
            ),
			font_layout (
            	layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
                layout_font_sizes( 12, 12*2, 14 )
            ),
			label_rects(
            	layout_rect( 97, 0, 64, 24 ),
                layout_rect( 2*97, 0, 2*64, 2*24 ),
                layout_rect( 135, 0, 78, 30 ) 
            ),
            shadow 
        );

		static const image_names no_one_hired_icon(
            	"default_avatar",
            	"default_avatar",
				"default_avatar" );

		static const image_names fiscal_agent_icon(
            	"tax_agent_icon",
            	"tax_agent_icon@2x",
				"tax_agent_icon_ipad" );

		static const image_names municipality_officer_icon(
            	"municipality_officer_icon",
            	"municipality_officer_icon@2x",
				"municipality_officer_icon_ipad" );

	}
}

        
END_NAMESPACE_SQC_FRAMEWORK

#endif
