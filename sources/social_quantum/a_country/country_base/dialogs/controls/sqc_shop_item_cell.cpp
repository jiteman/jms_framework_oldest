/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_shop_item_cell.h"
#include "sqc_shop_item_cell_layout.h"
#include "framework/sqc_framework.h"
#include "country_base/sqc_framework_base.h"
#include "../../../../common/framework/layout/sqc_common_resources.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_item_cell
//

sqc_shop_item_cell::sqc_shop_item_cell(
    milk::milk_widget_ptr p,
    sqc_shop_category_item_ptr ptr_item,
    sqc_shop_target shop_target )
    : milk::milk_widget( p )
    , m_ptr_shop_item( ptr_item )
    , m_shop_target( shop_target ) {
}

sqc_shop_item_cell::~sqc_shop_item_cell() {
}

void sqc_shop_item_cell::set_buy_callback( cell_buy_callback cb ) {
    m_buy_callback  = cb;
}

void sqc_shop_item_cell::set_gift_callback( cell_buy_callback cb ) {
    m_gift_callback = cb;
}

void sqc_shop_item_cell::set_sell_callback( cell_buy_callback cb ) {
    m_sell_callback  = cb;
}

void sqc_shop_item_cell::set_receive_callback( cell_buy_callback cb ) {
    m_receive_callback = cb;
}

void sqc_shop_item_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx,
    int current_level,
    bool draw_separator ) {

    if ( !window_ctx ) {
        sqc_assert( false );
        return;
    }
    
    if ( !m_ptr_shop_item ) {
        sqc_assert( false );
        return;
    }
    
    m_object_type = m_ptr_shop_item->object_type();
    sqc_assert( m_object_type.size() );
    
    sqc_shop_item_show_mask show_mask = m_ptr_shop_item->show_mask();
    
    sqc_window_factory& factory = framework().windows_factory();

    using namespace layout::shop_item_cell;

    milk::milk_widget_ptr ptr_cell = shared_from_this();
    surf::surf_rect rc_cell = ptr_cell->get_rect();

    // transparent part
    milk::milk_widget_ptr	ptr_transparent_layer = 
	ptr_cell->create_child<milk::milk_widget>( rc_cell );

    // create background image
    milk::milk_theme_button_ptr	ptr_transparent_backing_layer;
    milk::milk_widget_ptr ptr_non_transparent_backing_layer;
    {
        ptr_transparent_backing_layer = 
        factory.create_button( window_ctx, ptr_transparent_layer, cell_background_btn );
        
        // set action for this button
        //if ( m_buy_callback ) {
        //    ptr_transparent_backing_layer->set_action( cb_buy );
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
            ptr_image->set_texture( m_ptr_shop_item->image_name() );
        }
    }
    
	// create image for in/out gifts    
    if ( received_gift_target == m_shop_target || 
    		wishes_target  == m_shop_target ) {
            
        sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       window_ctx, ptr_transparent_layer,
                                                       cell_item_gift_in_out_rects,
                                                       cell_item_gift_in_out_image_alignment );
                                                       
		if ( received_gift_target == m_shop_target ) {
            if ( ptr_image ){
                ptr_image->set_texture(gift_in_image_names.at(factory.get_theme_size()));
            }
        } else if ( wishes_target == m_shop_target ) {
            if ( ptr_image ) {
                ptr_image->set_texture(gift_out_image_names.at(factory.get_theme_size()));
            }
        }
    }
    

    // create item name label
    {
        if (m_ptr_shop_item->name().size() > 0) 
        {
            // create label by layout
            m_name_label = 
            factory.create_label( window_ctx, ptr_transparent_layer, cell_item_name_label );
            m_name_label->set_caption( m_ptr_shop_item->name() );
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
            m_price_widget->set_price_in_coins( window_ctx, m_ptr_shop_item->price_in_coins() );
        }
        
        if (sqc_shop_item_show_price_in_megabucks & show_mask) {
            m_price_widget->set_price_in_megabucks( window_ctx, m_ptr_shop_item->price_in_megabucks() );
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
        m_properties->fill_item_properties_from_shop_item( m_ptr_shop_item, prop );
        m_properties->layout_controls( window_ctx, prop );
    }
    
    int item_level = m_ptr_shop_item->required_level();
    if ( current_level && item_level && current_level < item_level ) {
    	sqc_stringstream out;
        out << "Required level " << item_level;
	    m_ptr_shop_item->set_buy_error( out.str() );
        show_mask |= sqc_shop_item_show_error;
    }
    
    // has error
    if ( sqc_shop_item_show_error & show_mask ) {
        factory.create_image( window_ctx, ptr_non_transparent_backing_layer, cell_error_image );

        // create error label
        m_error_label = 
       		factory.create_label( window_ctx, ptr_cell, cell_error_label );
        	m_error_label->set_caption( m_ptr_shop_item->get_buy_error() );
        
        // and disable transparent part
        ptr_transparent_layer->set_alpha( 0.3 );
    } 
    
    
    if ( ! (sqc_shop_item_show_error & show_mask ) ) {
    
    	typedef std::vector<sqc_shop_action>	available_action_vector;
    	available_action_vector	actions;
        
        for ( int idx = 0; idx < shop_action_countof; idx++ ) {
        	sqc_shop_action action = (sqc_shop_action)idx;
        	if ( m_ptr_shop_item->is_button_visible( action ) ) {
            	actions.push_back( action );
            }
        }
        
		// no more 2 buttons
        sqc_assert( actions.size() <= 2 );
        
        sqc_shop_action* action0 = 0;
        sqc_shop_action* action1 = 0;
        
        if ( actions.size() >= 1 ) {
        	action0 = &actions[0];
            if ( actions.size() >= 2 ) {
                action1 = &actions[1];
            }
        }
        
        if ( action0 && action1 ) {
        	create_action_button( window_ctx, 
                                  ptr_transparent_layer, 
            					  *action0, 
                                  m_ptr_shop_item->is_button_disable(*action0), 
                                  action_position_left );
            create_action_button( window_ctx, 
                                  ptr_transparent_layer,
                                  *action1,
                                  m_ptr_shop_item->is_button_disable(*action1), 
                                  action_position_right );
        } else if ( action0 ) {
        	create_action_button( window_ctx, 
                                  ptr_transparent_layer,
                                  *action0,
                                  m_ptr_shop_item->is_button_disable(*action0), 
                                  action_position_center );
        }
        
    }// End: if ( ! (sqc_shop_item_show_error & show_mask ) )

    // create separator
    if (draw_separator) {
        factory.create_separator(window_ctx, ptr_cell, spinboard_cell_separator_theme );
    }
    
}

sqc_item_button_ptr sqc_shop_item_cell::create_action_button(
	sqc_window_factory_ctx_ptr window_ctx,
    milk::milk_widget_ptr parent,
    const sqc_shop_action action, 
    const bool disabled,
    const action_position position ) {
    
    if ( !window_ctx || !parent ) {
    	sqc_assert( false );
        return sqc_item_button_ptr();
    }
    
    using namespace layout::shop_item_cell;
    
    //
    //	determine rect and alignment
    //
    const layout_alignment& align = 
    	( position == action_position_center ? center_button_alignment : 
        		( position == action_position_left ? left_button_alignment : right_button_alignment ) ) ;
        
    const layout_rects& rect = 
    	( position == action_position_center ? center_button_rect : 
        		( position == action_position_left ? left_button_rect : right_button_rect ) ) ;

	sqc_window_factory& factory = framework().windows_factory();

	sqc_item_button_ptr ptr_button;
    milk::milk_callback cb;
    
    
    //
    //	create corresponding button instance
    //
	if ( shop_action_buy == action ) {
    	
        //-- custom position for buy button
        const layout_alignment& buy_align =  
            (position != action_position_center ? right_button_alignment : align);
            
        const layout_rects& buy_rect =     
            (position != action_position_center ? right_button_rect : rect);
        //--
        
        if ( disabled ) {
        	ptr_button = factory.create_child<sqc_item_button_buy_gray>( window_ctx, parent, buy_rect, buy_align );
        } else {
        	ptr_button = factory.create_child<sqc_item_button_buy>( window_ctx, parent, buy_rect, buy_align );
        }
        cb = std::tr1::bind( &sqc_shop_item_cell::on_buy_pressed, this );
        
    } else if ( shop_action_gift == action ) {

        //-- custom position for gift button
        const layout_alignment& gift_align =  
            (position != action_position_center ? left_button_alignment : align);
        
        const layout_rects& gift_rect =     
            (position != action_position_center ? left_button_rect : rect);
        //--
        
        
		if ( disabled ) {
	        ptr_button = factory.create_child<sqc_item_button_gift>( window_ctx, parent, gift_rect, gift_align );
        } else {    
        	ptr_button = factory.create_child<sqc_item_button_gift>( window_ctx, parent, gift_rect, gift_align ); 
        }
    	cb = std::tr1::bind( &sqc_shop_item_cell::on_gift_pressed, this );
        
    } else if ( shop_action_sell == action ) {
    
    	if ( disabled ) {
	        ptr_button = factory.create_child<sqc_item_button_sell_gray>( window_ctx, parent, rect, align );
        } else {
        	ptr_button = factory.create_child<sqc_item_button_sell>( window_ctx, parent, rect, align );
        }
    	cb = std::tr1::bind( &sqc_shop_item_cell::on_sell_pressed, this );
        
    } else if ( shop_action_receive == action ) {
    
        if ( disabled ) {
	        ptr_button = factory.create_child<sqc_item_button_sell_gray>( window_ctx, parent, rect, align );
        } else {
        	ptr_button =  factory.create_child<sqc_item_button_received>( window_ctx, parent, rect, align );
        }
    	cb = std::tr1::bind( &sqc_shop_item_cell::on_received_pressed, this );
        
    } else {
		sqc_assert( false );
	}

    if ( ptr_button ) {
    	ptr_button->layout_controls( window_ctx, cb );
    }
    
    return ptr_button;
}

bool sqc_shop_item_cell::preprocess_action( 
	const sqc_shop_action action ) {
    
    if ( !m_ptr_shop_item ) {
    	sqc_assert( 0 );
        return false;
    }
    
    sqc_shop_error error = m_ptr_shop_item->get_shop_error( action );
    if ( is_success_shop_action( error ) ) {
    	return true;
    }
    
    sqc_string str_error = country_framework().shop().get_shop_error_descr( error );
    
    
    sqc_message_box_params params;
    params.dlg_title	= "Error";
    params.dlg_text		= str_error;
    params.button_text	= "OK";

    country_framework().ui().show_message_box( params );
    
    return false;
}

void sqc_shop_item_cell::on_buy_pressed() {
	if ( !preprocess_action( shop_action_buy ) ) {
    	return;
    }
    
	if ( m_buy_callback ) {
    	m_buy_callback( m_object_type );
    }
}

void sqc_shop_item_cell::on_gift_pressed() {
	if ( !preprocess_action( shop_action_gift ) ) {
    	return;
    }

	if ( m_gift_callback ) {
    	m_gift_callback( m_object_type );
    }
}

void sqc_shop_item_cell::on_sell_pressed() {
	if ( !preprocess_action( shop_action_sell ) ) {
    	return;
    }

	if ( m_sell_callback ) {
    	m_sell_callback( m_object_type );
    }
}

void sqc_shop_item_cell::on_received_pressed() {
	if ( !preprocess_action( shop_action_receive ) ) {
    	return;
    }

	if ( m_receive_callback ) {
    	m_receive_callback( m_object_type );
    }
}

END_NAMESPACE_SQC_FRAMEWORK