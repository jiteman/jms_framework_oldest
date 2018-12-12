/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_LOGIN_PROGRESS_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_LOGIN_PROGRESS_DLG_LAYOUT_H_INCLUDED__

#include "city_base_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
	
	// login progress dialog
	namespace login_progress_dlg {
    
		static const dialog_backgrounds backgrounds( "en.lproj/Default-Landscape", 
													"en.lproj/Default-Landscape",
													"en.lproj/Default-Landscape" );
		
		static const dialog_layout dialog(
			layout_alignment( layout_halignment_center | 
							 layout_valignment_center ),
			dialog_sizes( layout_size( 480, 320 ),
						  layout_size( 960, 640 ),
						  layout_size( 1024, 768 ) ) );

        static const layout_alignment progress_indicator_alignment( 
        				layout_halignment_center|layout_valignment_bottom );

        static const image_rects progress_indicator_rect( 
        						  layout_rect( 0, 20, 134, 14 ),
                                  layout_rect( 0, 2*20, 268, 28 ),
                                  layout_rect( 0, 50, 298, 30 ) );
		
		static const image_layout progress_indicator0( 
             progress_indicator_alignment,
             image_names( "startup_progress_bar_0", 
             			  "startup_progress_bar_0@2x", 
                          "startup_progress_bar_0_ipad" ),
             progress_indicator_rect );
             
		static const image_layout progress_indicator1( 
             progress_indicator_alignment,
             image_names( "startup_progress_bar_1", 
             			  "startup_progress_bar_1@2x", 
                          "startup_progress_bar_1_ipad" ),
             progress_indicator_rect );
             
		static const image_layout progress_indicator2( 
             progress_indicator_alignment,
             image_names( "startup_progress_bar_2", 
             			  "startup_progress_bar_2@2x", 
                          "startup_progress_bar_2_ipad" ),
             progress_indicator_rect );
             
		static const image_layout progress_indicator3( 
             progress_indicator_alignment,
             image_names( "startup_progress_bar_3", 
             			  "startup_progress_bar_3@2x", 
                          "startup_progress_bar_3_ipad" ),
             progress_indicator_rect );
        
	}
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_LOGIN_PROGRESS_DLG_LAYOUT_H_INCLUDED__


