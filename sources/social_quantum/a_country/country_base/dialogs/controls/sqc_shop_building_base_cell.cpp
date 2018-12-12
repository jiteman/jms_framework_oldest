/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_shop_building_base_cell.h"
#include "sqc_shop_building_base_cell_layout.h"
#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_construction_item_cell
//

sqc_shop_building_base_cell::sqc_shop_building_base_cell(
    milk::milk_widget_ptr p, sqc_string object_type )
    : milk::milk_widget( p ), m_object_type(object_type) {
}

sqc_shop_building_base_cell::~sqc_shop_building_base_cell() {
}

void sqc_shop_building_base_cell::set_callbacks( 
    cell_buy_callback  buy_callback,
    cell_ask_callback  ask_callback ) {
    m_buy_callback  = buy_callback;
    m_ask_callback = ask_callback;
}

void sqc_shop_building_base_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx, bool draw_separator  ) {
    
    if ( !window_ctx ) {
        sqc_assert( false );
        return;
    }
    
    sqc_shop_building_base_item_ptr ptr_build_item = get_building_item();
    if ( !ptr_build_item ) {
        sqc_assert( false );
        return;
    }
    
    sqc_window_factory& factory = framework().windows_factory();

    using namespace layout::shop_building_base_cell;
    
    milk::milk_widget_ptr ptr_cell = shared_from_this();
    surf::surf_rect rc_cell = ptr_cell->get_rect();
    
    // transparent part
    m_transparent_layer = 
	ptr_cell->create_child<milk::milk_widget>( rc_cell );
    
    milk::milk_callback cb_buy = std::tr1::bind( &sqc_shop_building_base_cell::on_buy_pressed, this );
    milk::milk_callback cb_ask = std::tr1::bind( &sqc_shop_building_base_cell::on_ask_pressed, this );
    
    // create background image
    {
        milk::milk_theme_button_ptr ptr_backing = 
        factory.create_button( window_ctx, m_transparent_layer, 
                                            cell_background_btn );
        
        
        // set action for this button
        //if ( m_buy_callback ) {
            ptr_backing->set_action( cb_buy );
        //}
        
        
        m_transparent_backing_layer = ptr_backing;
        
        // create non transparent backing layer
        surf::surf_rect rect_backing = m_transparent_backing_layer->get_rect();
        m_non_transparent_backing_layer = 
 		shared_from_this()->create_child<milk::milk_widget>( rect_backing );
    }
    
    // create item image
    {
    	sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       window_ctx, m_transparent_backing_layer,
                                                       cell_item_image_rects,
                                                       cell_item_image_alignment );
        
        if ( ptr_image ) {
            ptr_image->set_texture( ptr_build_item->image_name() );
        }
    }
    
    
    // create item name label
    {
        // create label by layout
        m_name_label = 
        factory.create_label( window_ctx, m_transparent_layer, cell_item_name_label );
        m_name_label->set_caption( ptr_build_item->name() );
    }

    sqc_shop_item_show_mask show_mask = ptr_build_item->show_mask();
    
    // create price widget
    {
        
        m_price_widget = factory.create_child<sqc_item_price_widget>( 
                                              window_ctx, 
                                              m_transparent_layer, 
                                              price_widget_rects,
                                              price_widget_alignment );
        
        if ( sqc_shop_item_show_price_in_coins & show_mask ) {
            m_price_widget->set_price_in_coins( window_ctx, ptr_build_item->price_in_coins() );
        }
        
        if (sqc_shop_item_show_price_in_megabucks & show_mask) {
            m_price_widget->set_price_in_megabucks( window_ctx, ptr_build_item->price_in_megabucks() );
        }
    }

    // create properties widget
    {
        m_properties = factory.create_child<sqc_item_property_widget>( 
                                   window_ctx, 
                                   m_transparent_backing_layer, 
                                   properties_rects,
                                   properties_layout );

        sqc_item_properties prop;
        m_properties->fill_item_properties_from_shop_item( ptr_build_item, prop );
        m_properties->layout_controls( window_ctx, prop );
    }
    
    // has error
    if ( sqc_shop_item_show_error & show_mask ) {
        factory.create_image( window_ctx, ptr_cell, cell_error_image );

        // create error label
        m_error_label = 
        factory.create_label( window_ctx, ptr_cell, cell_error_label );
        m_error_label->set_caption( ptr_build_item->get_buy_error() );
        
        // and disable transparent part
        disable_transparent_layer();
    } 
    
    // create ask and buy buttons
    {
        bool can_ask = ptr_build_item->is_button_visible( shop_action_ask );
        
        // buy button
        if ( ptr_build_item->is_button_visible( shop_action_buy ) ) {
            
            const layout_rects& buy_rects = 
            ( can_ask ? buy_button_rect : buy_center_button_rect );

            const layout_alignment& buy_alig = 
            ( can_ask ? buy_button_alignment : buy_button_center_alignment );
            
            m_buy_button = factory.create_child<sqc_item_button_buy>( 
                                                   window_ctx, 
                                                   m_transparent_layer, 
                                                   buy_rects,
                                                   buy_alig );
            m_buy_button->layout_controls( window_ctx, cb_buy );
        }
        
        // create gift button
        if ( can_ask ) {

            m_ask_button = factory.create_child<sqc_item_button_ask>( 
                                                 window_ctx, 
                                                 m_transparent_layer, 
                                                 ask_button_rect,
                                                 ask_button_alignment );
            m_ask_button->layout_controls( window_ctx, cb_ask );
        }
    }
    
    
    // create separator
    if(draw_separator)
        factory.create_separator( window_ctx, shared_from_this(), spinboard_cell_separator );

}

void sqc_shop_building_base_cell::disable_transparent_layer() {
    
    sqc_assert( m_transparent_layer );
    if ( !m_transparent_layer ) {
        return;
    }
    // and disable transparent part
    m_transparent_layer->set_alpha( 0.3 );

}

void sqc_shop_building_base_cell::on_buy_pressed() {
	if ( m_buy_callback ) {
    	m_buy_callback( m_object_type );
    }
}

void sqc_shop_building_base_cell::on_ask_pressed() {
	if ( m_ask_callback ) {
    	m_ask_callback( m_object_type );
    }
}


END_NAMESPACE_SQC_FRAMEWORK