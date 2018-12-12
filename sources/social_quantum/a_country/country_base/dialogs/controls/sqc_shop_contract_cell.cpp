/*
 *  city_shop_contract_cell.cpp
 *  aCountry
 *
 *  Created by Maxim Korolkov on 06.09.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#include "sqc_shop_contract_cell.h"
#include "sqc_shop_contract_cell_layout.h"
#include "framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_item_cell
//

sqc_shop_contract_cell::sqc_shop_contract_cell(
    milk::milk_widget_ptr p,
    sqc_shop_contract_item_ptr ptr_contract )
    : milk::milk_widget( p )
    , m_ptr_contract( ptr_contract ) {
}

sqc_shop_contract_cell::~sqc_shop_contract_cell() {
}

void sqc_shop_contract_cell::set_callbacks( cell_buy_callback buy_callback ) {
    m_buy_callback  = buy_callback;
}

void sqc_shop_contract_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx, 
    int current_level,
    bool draw_separator ) {

    if ( !window_ctx ) {
        sqc_assert( false );
        return;
    }
    
    if ( !m_ptr_contract ) {
        sqc_assert( false );
        return;
    }
    
    m_object_type = m_ptr_contract->object_type();
    sqc_assert( m_object_type.size() );
    
    sqc_shop_item_show_mask show_mask = m_ptr_contract->show_mask();
    
    sqc_window_factory& factory = framework().windows_factory();

    using namespace layout::shop_contract_cell;

    milk::milk_widget_ptr ptr_cell = shared_from_this();
    surf::surf_rect rc_cell = ptr_cell->get_rect();

    // transparent part
    milk::milk_widget_ptr	ptr_transparent_layer = 
	ptr_cell->create_child<milk::milk_widget>( rc_cell );

    
    milk::milk_callback cb_buy = 
        std::tr1::bind( &sqc_shop_contract_cell::on_buy_pressed, this );
    
    // create background image
    milk::milk_theme_button_ptr	ptr_transparent_backing_layer;
    milk::milk_widget_ptr ptr_non_transparent_backing_layer;
    {
        ptr_transparent_backing_layer = 
        factory.create_button( window_ctx, ptr_transparent_layer, cell_background_btn );
        
        // set action for this button
        //if ( m_buy_callback ) {
            ptr_transparent_backing_layer->set_action( cb_buy );
        //}
        
        
        // create non transparent backing layer
        surf::surf_rect rect_backing = ptr_transparent_backing_layer->get_rect();
        ptr_non_transparent_backing_layer =
 		shared_from_this()->create_child<milk::milk_widget>( rect_backing );
        
    }
        
    // create item image
    {
    	sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       window_ctx, ptr_transparent_backing_layer,
                                                       cell_item_image_rects,
                                                       cell_item_image_alignment );
        
        if ( ptr_image ) {
            ptr_image->set_texture( m_ptr_contract->image_name() );
        }
    }
    
    
    // create item name label
    {
        if (m_ptr_contract->name().size() > 0) 
        {
            // create label by layout
            m_name_label = 
            factory.create_label( window_ctx, ptr_transparent_layer, cell_item_name_label );
            m_name_label->set_caption( m_ptr_contract->name() );
        }
    }
    
    
    // create price in coins or bucks or megabucks
    {
        m_price_widget = factory.create_child<sqc_item_price_widget>( 
                                              window_ctx,
                                              ptr_transparent_layer, 
                                              price_widget_rects,
                                              price_widget_alignment );
        
        if ( sqc_shop_item_show_price_in_coins & show_mask ) {
            m_price_widget->set_price_in_coins( window_ctx, m_ptr_contract->price_in_coins() );
        }
        
        if ( sqc_shop_item_show_price_in_megabucks & show_mask ) {
            m_price_widget->set_price_in_megabucks( window_ctx, m_ptr_contract->price_in_megabucks() );
        }
    }

    // create properties widget
    {
        m_properties = factory.create_child<sqc_item_property_widget>( 
                                   window_ctx,
                                   ptr_transparent_backing_layer, 
                                   properties_rects,
                                   properties_layout );
        
        sqc_item_properties prop;
        m_properties->fill_item_properties_from_shop_item( m_ptr_contract, prop );
        m_properties->layout_controls( window_ctx, prop );
    }
    
    // TODO: HACK!!!
    int item_level = m_ptr_contract->required_level();
    if ( current_level && item_level && current_level < item_level ) {
    	sqc_stringstream out;
        out << "Required level " << item_level;
	    m_ptr_contract->set_buy_error( out.str() );
        show_mask |= sqc_shop_item_show_error;
    }
    
    // has error
    if ( sqc_shop_item_show_error & show_mask ) {
        factory.create_image( window_ctx, ptr_non_transparent_backing_layer, cell_error_image );

        // create error label
        m_error_label = 
        factory.create_label( window_ctx, ptr_cell, cell_error_label );
        m_error_label->set_caption( m_ptr_contract->get_buy_error() );
        
        // and disable transparent part
        ptr_transparent_layer->set_alpha( 0.3 );
        
    } 
    // create buy and gift buttons
    if ( ! (sqc_shop_item_show_error & show_mask ) )
    {
        bool show_gift = m_ptr_contract->is_button_visible( shop_action_gift );
        
        // buy button
        if ( m_ptr_contract->is_button_visible( shop_action_buy ) ) {
            
            const layout_rects& buy_rects = 
                ( show_gift ? buy_button_rect : buy_center_button_rect );

            const layout_alignment& buy_alig = 
                ( show_gift ? buy_button_alignment : buy_button_center_alignment );
        
            if( m_ptr_contract->is_button_disable( shop_action_buy ) ) {
                m_buy_button = factory.create_child<sqc_item_button_buy_gray>( 
                                                    window_ctx,
                                                    ptr_transparent_layer, 
                                                    buy_rects,
                                                    buy_alig );
            } else {
                m_buy_button = factory.create_child<sqc_item_button_buy>( 
                                                    window_ctx,
                                                    ptr_transparent_layer, 
                                                    buy_rects,
                                                    buy_alig );
            }
                
            m_buy_button->layout_controls( window_ctx, cb_buy );
        }
            
}
    
    // create separator
    if (draw_separator) {
        factory.create_separator( window_ctx, ptr_cell, spinboard_cell_separator );
    }
    
}

void sqc_shop_contract_cell::on_buy_pressed() {
	if ( m_buy_callback ) {
    	m_buy_callback( m_object_type );
    }
}

END_NAMESPACE_SQC_FRAMEWORK