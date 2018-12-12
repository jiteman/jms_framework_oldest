/*
 *  city_select_construction_cell.cpp
 *  aCountry
 *
 *  Created by paul on 10/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_select_construction_cell.h"
#include "city_select_construction_cell_layout.h"
#include "city/city_framework.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_construction_item_cell
//

city_select_construction_cell::city_select_construction_cell(
    milk::milk_widget_ptr p, sqc_construction_ptr construction )
    : milk::milk_widget( p ), m_construction(construction) {
}

city_select_construction_cell::~city_select_construction_cell() {
}

void city_select_construction_cell::set_apply_callbacks( 
	cell_apply_callback cb ) {
    m_apply_callback  = cb;
}

void city_select_construction_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx ) {
    
    if ( !window_ctx ) {
        sqc_assert( false );
        return;
    }
    
    if ( !m_construction ) {
        sqc_assert( false );
        return;
    }
    
    sqc_window_factory& factory = framework().windows_factory();

    using namespace city_dlg_layout::select_construction_cell;
    
    milk::milk_widget_ptr ptr_cell = shared_from_this();
    surf::surf_rect rc_cell = ptr_cell->get_rect();

    milk::milk_callback cb_apply = std::tr1::bind( &city_select_construction_cell::on_apply_pressed, this );
    
    // create background image
    milk::milk_theme_button_ptr ptr_backing;
    {
        ptr_backing = 
        factory.create_button( window_ctx, ptr_cell, 
                                            cell_background_btn );
        
        
        // set action for this button
        ptr_backing->set_action( cb_apply );
    }
    
    // create item image
    {
    	sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       window_ctx, ptr_backing,
                                                       cell_item_image_rects,
                                                       cell_item_image_alignment );
        
        if ( ptr_image ) {
            ptr_image->set_texture( m_construction->image_name() );
        }
    }
    
    
    // create item name label
    {
        // create label by layout
        milk::milk_label_ptr name_label = 
	        factory.create_label( window_ctx, ptr_cell, cell_item_name_label );
        name_label->set_caption( m_construction->name() );
    }

    
    // create apply button
    {
        sqc_item_button_apply_ptr ptr_button = factory.create_child<sqc_item_button_apply>( 
                                               window_ctx, 
                                               ptr_cell, 
                                               apply_button_rect,
                                               apply_button_center_alignment );
        ptr_button->layout_controls( window_ctx, cb_apply );
    }
    
    
    // create separator
    factory.create_separator( window_ctx, shared_from_this(), spinboard_cell_separator );

}

void city_select_construction_cell::on_apply_pressed() {
	if ( m_apply_callback && m_construction ) {
    	m_apply_callback( m_construction );
    }
}

END_NAMESPACE_SQC_FRAMEWORK