/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_shop_material_cell.h"
#include "sqc_shop_material_cell_layout.h"
#include "sqc_shop_building_base_cell_layout.h"

#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_material_cell
//

sqc_shop_material_cell::sqc_shop_material_cell(
    milk::milk_widget_ptr p,
    sqc_shop_material_item_ptr ptr_item )
    : sqc_shop_building_base_cell( p, ptr_item->object_type() )
    , m_ptr_item( ptr_item ) {
}

sqc_shop_material_cell::~sqc_shop_material_cell() {
}

void sqc_shop_material_cell::layout_controls(
    sqc_window_factory_ctx_ptr window_ctx, bool draw_separator  ) {

    bool dialog_creating = !m_quantity_label;
    
    if (dialog_creating) {
        sqc_shop_building_base_cell::layout_controls( window_ctx, draw_separator );
    }
    
    if ( !m_ptr_item || 
        !m_transparent_layer || 
        !m_transparent_backing_layer || 
        !m_non_transparent_backing_layer ) {
        sqc_assert( false );
        return;
    }
    
    const int count = m_ptr_item->count();
    const int total = m_ptr_item->total();
    
    //if ( !count && !total ) {
    //    return;
    //}
    
    sqc_window_factory& factory = framework().windows_factory();
    
    using namespace layout::shop_material_cell;
    
    // create quantity label
    if (dialog_creating) {
        m_quantity_label = factory.create_label( window_ctx, m_transparent_layer, quantity_label );
    }
    
    sqc_string str_caption = framework().formats().format_quantity( count, total );
    m_quantity_label->set_caption( str_caption );
    
    // already purchased
    if ( count == total && total ) {
        if (!m_purchased_image) {
            m_purchased_image = factory.create_image( window_ctx, m_non_transparent_backing_layer, purchased_image );
            // and disable transparent part
            disable_transparent_layer();
        }
    }    
    
    // shadow
    typedef surf::surf_size	sz;
    surf::surf_size surf_sizes [] = { sz( -0.5, 1 ), sz( -1, 2 ), sz( -0.75, 1 )};
    
    m_name_label->set_shadow_color(surf::surf_color(0,0,0,1));
    m_name_label->set_shadow_size(surf_sizes[factory.get_theme_size()]);
    m_name_label->set_draw_shadow_enabled(true);
}

void sqc_shop_material_cell::set_item(sqc_shop_material_item_ptr ptr_item) {
    m_ptr_item.reset();
    m_ptr_item = ptr_item;
}


sqc_shop_building_base_item_ptr 
sqc_shop_material_cell::get_building_item() {
    return m_ptr_item;
}

END_NAMESPACE_SQC_FRAMEWORK