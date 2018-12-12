/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_item_buttons.h"
#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK
  
//
// sqc_shop_item_cell
//

sqc_item_button_base::sqc_item_button_base(
    milk::milk_widget_ptr p,
    const sqc_theme_button_layout& button_layout,
    const label_layout& label_layout )
    : milk::milk_widget( p )
    , m_button_layout( button_layout )
    , m_label_layout( label_layout ) {
}

sqc_item_button_base::~sqc_item_button_base() {
}

void sqc_item_button_base::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx,
    milk::milk_callback callback ) {
    
    sqc_window_factory& factory = framework().windows_factory();
    
    milk::milk_theme_button_ptr	ptr_btn = 
    factory.create_button( window_ctx, shared_from_this(), m_button_layout );
    
    if ( ptr_btn ) {
        ptr_btn->set_action( callback );
    }
    
    factory.create_label( window_ctx, shared_from_this(), m_label_layout );
}


END_NAMESPACE_SQC_FRAMEWORK