/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SHOP_CATEGORIES_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_SHOP_CATEGORIES_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	// shop categories dialog
	namespace shop_categories_dlg {
		// CityShopViewController
		static const dialog_layout background(
			layout_alignment( layout_halignment_center | 
							 layout_valignment_center ),
			dialog_sizes( layout_size( 480, 320 ), 
						  layout_size( 960, 640 ),
						  layout_size( 957, 523 ) ) );
		// separtors
		static const horizontal_separator_layout separator_h( 
			layout_alignment( layout_valignment_center ),
			separator_offsets( 0,0,0) );
		static const vertical_separator_layout separator_v1( 
			layout_alignment( layout_halignment_center ),
			separator_offsets( -115,-115*2,-229) );
		static const vertical_separator_layout separator_v2( 
			layout_alignment( layout_halignment_center ),
			separator_offsets( 0,0,0) );
		static const vertical_separator_layout separator_v3( 
			layout_alignment( layout_halignment_center ),
			separator_offsets( 115,115*2,229) );
		// dialog title
		static const layout_string_resource dialog_title(
							layout_resource_id( "*CityShopCategories" ),
							layout_string( "Shop Categories" ) );


		// cell caption font
		static const font_layout cell_caption_font (
                      layout_font_name( "Arial.otf" ),//Arial
                      layout_font_sizes( 12, 2*12, 22 ) );
        
		// button caption draw flags
		static const layout_label_draw_flags cell_caption_draw_flags(
                       surf::draw_string_alignment_center|
                       surf::draw_string_valignment_center|
                       surf::draw_string_single_line|
                       surf::draw_string_truncation_tail );
        
        // button and caption alignment 
        static const layout_alignment cell_button_layout_alignment( top_layout_alignment );
        static const layout_alignment cell_caption_layout_alignment( top_layout_alignment );
        // caption color
        static const layout_color cell_caption_color( layout_white_color );

        
        static const layout_points first_cell_center( 
                        layout_point( 69, 120 ),
                        layout_point( 2*69, 2*120 ),
                        layout_point( 145, 200 ) );
        
        static const layout_points cells_offset(
                        layout_point( 115, 130 ),
                        layout_point( 2*115, 2*130 ),
                        layout_point( 229, 217 ) );
        
        // own cell rects (aligned by cell)
        static const layout_rects cell_rects(
                    layout_rect( 0, 0, 110, 120 ),
                    layout_rect( 0, 0, 2*110, 2*120 ),
                    layout_rect( 0, 0, 220, 240 ) );

        // button rects (aligned by cell)
        static const image_rects cell_button_rects(
                    layout_rect( 11, 5, 85, 87 ),
                    layout_rect( 2*11, 2*5, 2*85, 2*87 ),
                    layout_rect( 22, 10, 155, 156 ) );
        
        // cell caption rects (aligned by cell)
        static const label_rects cell_caption_rects(
                    layout_rect( 4, 96, 100, 20 ),
                    layout_rect( 2*4, 2*96, 2*100, 2*20 ),
                    layout_rect( 0, 163, 199, 40 ) );

        
        // houses button and caption
		static const image_button_layout houses_button( 
                    cell_button_layout_alignment,
                    image_names( "01_item_0", 
                                  "01_item_0@2x", 
                                  "01_item_ipad_0" ), 
                    image_pressed_names( "01_item_1",
                                        "01_item_1@2x",
                                        "01_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout houses_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_houses,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );

        // factories button and caption
		static const image_button_layout factories_button( 
                    cell_button_layout_alignment,
                    image_names( "02_item_0", 
                               "02_item_0@2x", 
                               "02_item_ipad_0" ), 
                    image_pressed_names( "02_item_1",
                                     "02_item_1@2x",
                                     "02_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout factories_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_factories,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        // leisures button and caption
		static const image_button_layout leisures_button( 
                    cell_button_layout_alignment,
                    image_names( "03_item_0", 
                             "03_item_0@2x", 
                             "03_item_ipad_0" ), 
                    image_pressed_names( "03_item_1",
                                   "03_item_1@2x",
                                   "03_item_ipad_1" ),
                    cell_button_rects );
                                                         
		static const label_layout leisures_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_leisures,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        // terrains button and caption
		static const image_button_layout terrains_button( 
                    cell_button_layout_alignment,
                    image_names( "04_item_0", 
                             "04_item_0@2x", 
                             "04_item_ipad_0" ), 
                    image_pressed_names( "04_item_1",
                                   "04_item_1@2x",
                                   "04_item_ipad_1" ),
                    cell_button_rects );
                                                         
		static const label_layout terrains_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_terrains,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        // power button and caption
		static const image_button_layout power_button( 
                    cell_button_layout_alignment,
                    image_names( "05_item_0", 
                              "05_item_0@2x", 
                              "05_item_ipad_0" ), 
                    image_pressed_names( "05_item_1",
                                    "05_item_1@2x",
                                    "05_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout power_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_power,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        // roads button and caption
		static const image_button_layout roads_button( 
                    cell_button_layout_alignment,
                    image_names( "06_item_0", 
                              "06_item_0@2x", 
                              "06_item_ipad_0" ), 
                    image_pressed_names( "06_item_1",
                                    "06_item_1@2x",
                                    "06_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout roads_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_roads,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        // materials button and caption
		static const image_button_layout materials_button( 
                    cell_button_layout_alignment,
                    image_names( "07_item_0", 
                              "07_item_0@2x", 
                              "07_item_ipad_0" ), 
                    image_pressed_names( "07_item_1",
                                    "07_item_1@2x",
                                    "07_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout materials_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_title_materials,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );

        // expansions button and caption
		static const image_button_layout expansions_button( 
                    cell_button_layout_alignment,
                    image_names( "08_item_0", 
                               "08_item_0@2x", 
                               "08_item_ipad_0" ), 
                    image_pressed_names( "08_item_1",
                                     "08_item_1@2x",
                                     "08_item_ipad_1" ),
                    cell_button_rects );
		
		static const label_layout expans_caption(
                    cell_caption_layout_alignment,
                    common_resources::string_message_shop_expand,
                    cell_caption_color,
                    cell_caption_draw_flags,
                    cell_caption_font,
                    cell_caption_rects );
        
        static const image_button_layout btn_add_coins( 
			layout_alignment( layout_halignment_left | layout_valignment_top ),
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
            	layout_rect( 307, 9, 116, 40 ),
				layout_rect( 2*307, 2*9, 2*116, 2*40 ),
				layout_rect( 692, 12, 198, 46 )
            )
        );

		static const label_layout add_coins_caption(
			layout_alignment( layout_halignment_fill | layout_valignment_fill ),
            common_resources::string_title_add_coins,
			layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_left |
                surf::draw_string_valignment_center ),
            font_layout(
            	layout_font_name( "Arial-BoldMT.otf" ), //ArialBT
            	layout_font_sizes( 14, 2*14, 18 )
            ),
            label_rects(
            	layout_rect( 40, 5, 0, 0 ),
				layout_rect( 2*40, 2*10, 0, 0 ),
				layout_rect( 40, 10, 0, 0  )
            ) 
        );    
        
        static const image_button_layout btn_find( 
             layout_alignment( layout_halignment_left | layout_valignment_top ),
             image_names(
                         "icon_search_market_normal",
                         "icon_search_market_normal@2x",
                         "icon_search_market_normal_ipad"), 
             image_pressed_names(
                                 "icon_search_market_selected",
                                 "icon_search_market_selected@2x",
                                 "icon_search_market_selected_ipad"), 
            image_rects(
                        layout_rect( 262, 9, 41, 40 ),
                        layout_rect( 2*262, 2*9,82, 80 ),
                        layout_rect( 636, 12, 44, 46 )));             
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SHOP_CATEGORIES_DLG_LAYOUT_H_INCLUDED__


