/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_shop_construction_cell.h"
#include "sqc_shop_construction_cell_layout.h"
#include "sqc_shop_building_base_cell_layout.h"

#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_construction_cell
//

sqc_shop_construction_cell::sqc_shop_construction_cell(
    milk::milk_widget_ptr p,
    sqc_shop_construction_item_ptr ptr_item )
    : sqc_shop_building_base_cell( p, ptr_item->object_type() )
    , m_ptr_item( ptr_item ) {
}

sqc_shop_construction_cell::~sqc_shop_construction_cell() {
}

void sqc_shop_construction_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx, bool draw_separator ) {
    
    sqc_shop_building_base_cell::layout_controls( window_ctx, draw_separator );

    if ( !m_ptr_item ||
        !m_transparent_layer || 
        !m_transparent_backing_layer || 
        !m_non_transparent_backing_layer ) {
        sqc_assert( false );
        return;
    }
    
    int required_level = m_ptr_item->required_level();
    if ( !required_level ) {
        return;
    }
    
    sqc_window_factory& factory = framework().windows_factory();
    
    using namespace layout::shop_construction_cell;
    
    // create requered level image
    milk::milk_image_ptr ptr_build_lock_image =
    factory.create_image( window_ctx, m_non_transparent_backing_layer, build_lock_image );
    
    // available label
    factory.create_label( window_ctx, ptr_build_lock_image, available_label );
                    
    // create level label
    milk::milk_label_ptr ptr_level =
    factory.create_label( window_ctx, ptr_build_lock_image, level_label );
    
    sqc_string str_level = framework().formats().format_digit_grouping( required_level );
    ptr_level->set_caption( str_level );
    
    // and disable transparent part
    disable_transparent_layer();
}

sqc_shop_building_base_item_ptr 
sqc_shop_construction_cell::get_building_item() {
    return m_ptr_item;
}


END_NAMESPACE_SQC_FRAMEWORK