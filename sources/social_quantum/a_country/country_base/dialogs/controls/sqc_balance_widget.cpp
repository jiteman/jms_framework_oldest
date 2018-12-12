/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_balance_widget.h"
#include "sqc_balance_widget_layout.h"
#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_balance_widget
//
sqc_balance_widget::sqc_balance_widget( 
    milk::milk_widget_ptr p )
    : milk::milk_widget( p) {
        
    //layout_controls();
}

sqc_balance_widget::~sqc_balance_widget() {
}

void sqc_balance_widget::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx ) {
    
    sqc_window_factory& factory = framework().windows_factory();
    
    using namespace layout::balance_widget;
    
    // create coins and bucks
    {
        milk::milk_image_ptr ptr_image = 
        factory.create_image( window_ctx, shared_from_this(), coins_and_bucks_backing_image );
        
        factory.create_image( window_ctx, ptr_image, coins_image );
        factory.create_image( window_ctx, ptr_image, bucks_image );
        
        m_coins_label = 
        factory.create_label( window_ctx, ptr_image, coins_label );

        m_bucks_label = 
        factory.create_label( window_ctx, ptr_image, bucks_label );
    }
}	

void sqc_balance_widget::update_coins( int coins ) {
    if ( m_coins_label ) {
        m_coins_label->set_caption( 
            coins > 999999 ? framework().formats().format_digit_compact( coins ) : framework().formats().format_digit_grouping( coins ) 
        );
    }
}

void sqc_balance_widget::update_bucks( int bucks ) {
    if ( m_bucks_label ) {
        m_bucks_label->set_caption( 
            framework().formats().format_digit_grouping( bucks ) );
    }
}




END_NAMESPACE_SQC_FRAMEWORK