/*
 *  city_friends_panel_dlg_layout.h
 *  aCountry
 *
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_FRIENDS_PANEL_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_FRIENDS_PANEL_DLG_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {

	namespace friends_panel {

        static const layout_rects
        rct_main(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 4, 4, 0, 112 ) );

        // relation main rect
        static const layout_point pt_current_user( 8, 13 );
        
		static const slice_offsets
        ofs_bg_slice (
			// left, top, right, bottom, flag
            slice_offset(0,0,0,0, surf::tile_flag_none),
            slice_offset(0,0,0,0, surf::tile_flag_none),
            slice_offset(171, 0, 19, 0, surf::tile_flag_none) );

		static const spinboard_layout
        lt_spinboard(
        	layout_alignment(layout_halignment_left | layout_valignment_bottom),
			layout_rects(
				layout_rect( 0, 0, 0, 0 ),
				layout_rect( 0, 0, 0, 0 ),
				layout_rect( 
                	ofs_bg_slice.at(sqc_theme_large).offset_left,			// x
                    14,														// y
                    0, 														// cx
                    rct_main.at(sqc_theme_large).cy 						// cy
                )
            )
		);

        static const slice_image_layout
        slc_background(
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names(
                "",
                "",
                "friends_panel_ipad"
            ),
            ofs_bg_slice,
            rct_main
        );
	
        static const image_names
        nm_cell(
            "",
            "",
            "friends_panel_cell_ipad");
            
        static const image_layout
        img_cell(
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			nm_cell,
            layout_rects(
            	layout_rect( 0, 0, 0, 0 ),
                layout_rect( 0, 0, 0, 0 ),
                layout_rect( 0, 0, 75, 91 )
            )
        );

        static const label_layout 
        lbl_name (
            layout_alignment( layout_halignment_fill | layout_valignment_bottom ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center | surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ),
				layout_font_sizes( 12, 2*12, 16 )
            ),
            label_rects(
            	layout_rect( 0, 0, 0, 0 ) ,
                layout_rect( 0, 0, 0, 0 ) ,
				layout_rect( 0, 5, 0, 13 ) 
            ) 
        );

        static const image_button_layout
        img_add_friends(
			layout_alignment( layout_halignment_center | layout_valignment_center ) ,
            image_names(
				"", "", "friends_panel_add_ipad" ), 
            
            image_pressed_names(
            	"", "", "friends_panel_add_selected_ipad" ),

            image_rects( layout_rect( 0, 0, 0, 0 ),
                         layout_rect( 0, 0, 0, 0 ),
                         layout_rect( 0, 0, 66, 83 ) ) );
        
        static const image_layout
        img_level(
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names(
                "",
                "",
                "icon_level_star"
            ),
            layout_rects(
                layout_rect( 0, 0, 0, 0 ),
                layout_rect( 0, 0, 0, 0 ),
                layout_rect( 55, 73, 26, 25 )
            )
        );

        static const label_layout 
        lbl_level (
            layout_alignment( layout_halignment_fill | layout_valignment_bottom ),
            layout_string_resource( "", "" ), 
            layout_white_color,
            layout_label_draw_flags(
                surf::draw_string_alignment_center | surf::draw_string_valignment_center ),
			font_layout (
				layout_font_name( "Arial.otf" ),
				layout_font_sizes( 6, 6*2, 9 )
            ),
            label_rects(
            	layout_rect( 0, 0, 0, 0 ) ,
                layout_rect( 0, 0, 0, 0 ) ,
				layout_rect( 0, 5, 0, 13 ) 
            ) 
        );

		static const image_layout
        img_test(
            layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names(
                "message_close_shop_0",
                "message_close_shop_0",
                "message_close_shop_0"
            ),
            layout_rects(
                layout_rect( 0, 0, 0, 0 ),
                layout_rect( 0, 0, 0, 0 ),
                layout_rect( 5, 22, 60, 60 )
            )
        );

        static const image_button_layout
        img_selected_cell(
			layout_alignment( layout_halignment_center | layout_valignment_center ) ,
            image_names(
				"", "", "" ), 
            
            image_pressed_names(
            	"", "", "friends_panel_cell_selected_ipad" ),

            image_rects( layout_rect( 0, 0, 0, 0 ),
                         layout_rect( 0, 0, 0, 0 ),
                         layout_rect( 0, 0, 75, 91 ) ) );
                         
        static const layout_rects
        rct_current(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 8, 13, 75, 91 ) );

        static const layout_rects
        rct_btnmode(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 49, 23 ) );

		static const image_button_layout
		btn_hide(
			layout_alignment( layout_halignment_center | layout_valignment_bottom ) ,
			image_names(
				"", "", "friends_panel_hide_ipad" ), 
            
            image_pressed_names(
            	"", "", "friends_panel_hide_1_ipad" ),

			rct_btnmode );

		static const image_button_layout
		btn_show(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ) ,
			image_names(
				"", "", "guiButtonFriends_iPad" ), 
            
            image_pressed_names(
            	"", "", "guiButtonFriendsOn_iPad" ),

            rct_btnmode );
        
    };

};

END_NAMESPACE_SQC_FRAMEWORK

#endif
