
/*
*  sqc_slider.h
*  aCountry dialog layout
*
*  Created by Bacil on 16.08.2011.
*  Copyright 2011 Social Quantum. All rights reserved.
*
*/

#ifndef __SQC_SQC_SLIDER_LAYOUT_H_INCLUDED__
#define __SQC_SQC_SLIDER_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout {
	namespace slider {

		static int gutter_height[3] = {12, 24, 18};
        static int gutter_x_margins[3] = {12, 21, 16};
        
        static const image_button_layout
        ibt_slpin(
            layout_alignment( layout_halignment_left | layout_valignment_bottom),
            image_names("tax_pin_slider", "tax_pin_slider@2x", "tax_pin_slider_ipad"),
            image_names("tax_pin_slider", "tax_pin_slider@2x", "tax_pin_slider_ipad"),
            image_rects(
                layout_rect( 0, 0, 21, 21 ),
                layout_rect( 0, 0, 42, 42 ),
                layout_rect( 0, 0, 33, 24) 
            ) );
	
        static const image_names
        img_gutter(
            "tax_slider_back",
            "tax_slider_back@2x",
            "tax_slider_back_ipad"
        );
        
        static const slice_offsets 
        offs_gutter(
            slice_offset(8, 0, 9, 0, surf::tile_flag_none),
            slice_offset(17, 0, 17, 0, surf::tile_flag_horz),
            slice_offset(12, 0, 13, 0, surf::tile_flag_horz)
        );
        
        static const slice_image_layout
        slc_gutter(
			layout_alignment( layout_halignment_left | layout_valignment_bottom ),
			img_gutter,
			offs_gutter,
           	image_rects(
            	layout_rect( 65, 131, 348, 12 ),
				layout_rect( 0, 0, 66, 24 ),
				layout_rect( 0, 0, 33, 24 ) )
        );

    
    }
}
END_NAMESPACE_SQC_FRAMEWORK

#endif
