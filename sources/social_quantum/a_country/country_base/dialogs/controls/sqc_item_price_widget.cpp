/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_item_price_widget.h"
#include "sqc_item_price_widget_layout.h"
#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_item_price_widget
//

sqc_item_price_widget::sqc_item_price_widget(
    milk::milk_widget_ptr p) 
    : milk::milk_widget( p ) {
}

sqc_item_price_widget::~sqc_item_price_widget() {
}

void sqc_item_price_widget::set_price_in_coins( 
    sqc_window_factory_ctx_ptr window_ctx,
    int coins ) {
    
    layout_controls( window_ctx, price_in_coins );
    if ( m_coins_label ) {
        set_label_int_value( m_coins_label, coins );
    } else {
        sqc_assert( false );
    }
}

/*
void sqc_item_price_widget::set_price_in_bucks( 
    sqc_window_factory_ctx_ptr window_ctx, 
    int bucks ) {
    
    layout_controls( window_ctx, price_in_bucks );
    if ( m_bucks_label ) {
        set_label_int_value( m_bucks_label, bucks );
    } else {
        sqc_assert( false );
    }
}*/

void sqc_item_price_widget::set_price_in_megabucks( 
    sqc_window_factory_ctx_ptr window_ctx, 
    int megabucks ) {
    
    layout_controls( window_ctx, price_in_megabucks );
    if ( m_megabucks_label ) {
        set_label_int_value( m_megabucks_label, megabucks );
    } else {
        sqc_assert( false );
    }
}

void sqc_item_price_widget::layout_controls( 
    sqc_window_factory_ctx_ptr window_ctx,
    price_in_t price_in ) {
    
    sqc_window_factory& factory = framework().windows_factory();

    using namespace layout::item_price_widget;
    
    // create price in coins
    if ( price_in_coins == price_in ) {
        factory.create_image( window_ctx, shared_from_this(), cell_price_in_coins_image );
       
        m_coins_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_price_in_coins_label );
    } else 
    /*if ( price_in_bucks == price_in ) {
        factory.create_image( window_ctx, shared_from_this(), cell_price_in_bucks_image );

        m_bucks_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_price_in_bucks_label );
    } else */ 
    if ( price_in_megabucks == price_in ) {
        factory.create_image( window_ctx, shared_from_this(), cell_price_in_megabucks_image );

        m_megabucks_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_price_in_megabucks_label );
    }
}

void sqc_item_price_widget::set_label_int_value(
    milk::milk_label_ptr ptr_label,
    int value ) {
    if ( !ptr_label ) {
        return;
    }
    sqc_string str_value = framework().formats().format_digit_grouping( value );
    ptr_label->set_caption( str_value );
}


END_NAMESPACE_SQC_FRAMEWORK