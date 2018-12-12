/*
 *  city_buy_building_base.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_buy_building_base_dlg.h"
#include "../city_framework.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"


NAMESPACE_SQC_FRAMEWORK

//
// city_buy_building_base_dlg implementation
//

// initialization 
void city_buy_building_base_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_buy_building_base_dlg::on_init_dialog" );
    
	sqc_dialog_with_close::on_init_dialog();
    
	sqc_window_factory& factory = framework().windows_factory();

	using namespace city_dlg_layout::buy_building_base_dlg;
	
	// create dialog title
	{
		set_caption( get_dialog_title() );
	}
	
	create_separator( shared_from_this(),separator_h1);
	// create item bevel
	factory.create_bevel( m_window_ctx, shared_from_this(), item_bevel );
	
    // create category image
    {
        sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       m_window_ctx, shared_from_this(),
                                                       category_item_image_rects,
                                                       category_item_image_alignment );
        
        if ( ptr_image ) {
            ptr_image->set_texture( get_category_image() );
        }
    }
        
    // create category description
    {
        milk::milk_label_ptr  ptr_label = 
        factory.create_label( m_window_ctx, shared_from_this(), descr_label );
                                          
        ptr_label->set_caption( get_category_descr() );
        
        // shadow
        typedef surf::surf_size	sz;
        surf::surf_size surf_sizes [] = { sz( -0.5, 1 ), sz( -1, 2 ), sz( -0.75, 1 )};
                                          
        ptr_label->set_shadow_color(surf::surf_color(1,1,1,1));
        ptr_label->set_shadow_size(surf_sizes[factory.get_theme_size()]);
        ptr_label->set_draw_shadow_enabled(true);
    }
    
    
    //create spinboard
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           construction_spinboard, 
                                           this );
	/// create pager
    factory.create_spinboard_pager( m_window_ctx, shared_from_this(), m_spinboard,  construction_spinboard_pager );   
    // set cell count
    m_cell_count = ( ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 );
    m_spinboard->set_visible_count( m_cell_count );
}	

bool city_buy_building_base_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
	sqc_window_factory& factory = framework().windows_factory();
	static const int offsets[] = {20,20*2,28};
	a.bevel_bottom = offsets[factory.get_theme_size()]-city_dlg_layout::content_offset_btm[factory.get_theme_size()];
    
	return sqc_dialog_with_close::get_dialog_init_arg(a);
}

END_NAMESPACE_SQC_FRAMEWORK