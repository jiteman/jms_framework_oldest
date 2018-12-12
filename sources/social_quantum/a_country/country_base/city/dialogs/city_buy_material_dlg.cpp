/*
 *  city_buy_material_dlg.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_buy_material_dlg.h"
#include "../city_framework.h"
#include "../../country_base/dialogs/controls/sqc_shop_material_cell.h"


NAMESPACE_SQC_FRAMEWORK

//
// city_buy_material_dlg implementation
//

// dialog title
sqc_string city_buy_material_dlg::get_dialog_title() {
    using namespace city;
    return city_framework().shop().
                get_shop_material_category_name( m_category );
}

// category description
sqc_string city_buy_material_dlg::get_category_descr() {
    using namespace city;
    return city_framework().shop().
                get_shop_material_category_descr( m_category );
}

// category image
sqc_string city_buy_material_dlg::get_category_image() {
    using namespace city;
    return city_framework().shop().
                get_shop_material_category_image( m_category );
}

void city_buy_material_dlg::enum_shop() {
    using namespace city;
    
    sqc_string_map input_fill;
    m_params.input_fill_callback(input_fill);
    
    m_items.clear();
    city_framework().shop().enum_shop_material_category( m_category, input_fill,m_params.scene_info, m_items );
}

// initialization 
void city_buy_material_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_buy_material_dlg::on_init_dialog" );
    
    enum_shop();
    
	city_buy_building_base_dlg::on_init_dialog();
}	

// milk_spinboard_callbacks interface
milk::milk_widget_ptr city_buy_material_dlg::create_cell(
    int idx, surf::surf_rect const &rect ) {
    PROFILE_ENTRY( "city_buy_material_dlg::create_cell" );
    
    if ( idx >= m_items.size() ||
        idx < 0 ) {
        sqc_assert( false );
    return milk::milk_widget_ptr();
    }
    
    sqc_assert( m_spinboard );
    
    // add cell object to spinboard
    
    sqc_shop_material_cell_ptr ptr_cell = 
    m_spinboard->create_child<sqc_shop_material_cell>( rect, m_items[idx] );
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    m_total_material += m_items[idx]->total();
    
    //-- draw separator or not
    bool draw_separator;
    
    if(0 == (idx+1) % m_cell_count) 
        draw_separator = false;
    else draw_separator = true;
    //--
    
    ptr_cell->layout_controls( m_window_ctx, draw_separator );
    ptr_cell->set_callbacks(
        std::tr1::bind( &city_buy_material_dlg::on_buy_item_pressed, this, std::tr1::placeholders::_1 ),
        std::tr1::bind( &city_buy_material_dlg::on_ask_item_pressed, this, m_items[idx] ));
    
    return ptr_cell;
}

int city_buy_material_dlg::get_cell_count() {
    return m_items.size();
}

// user press buy item button
void city_buy_material_dlg::on_buy_item_pressed(const sqc_string& object_type) {
    
    if ( m_params.buy_callback ) {
    	m_params.buy_callback( object_type );
    	
        if (m_total_material - m_count_material == 1) {
            get_server().close_modals( 
                                      std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
            return;
        }
    }
}

// user press ask item button
void city_buy_material_dlg::on_ask_item_pressed(sqc_shop_material_item_ptr ptr_item) {

    if(!ptr_item)
    {
        sqc_assert(false);
        sqc_error() << "city_buy_material_dlg::on_ask_item_pressed() empty parameter sqc_shop_material_item_ptr";
    }        

    
    using namespace processor;
	sqc_command_ptr  command( new sqc_ask_material_gift_command( "", ptr_item->object_type_id()));
	country_framework().cmd_processor().schedule( command );
            
    sqc_error() << "Item ( id = " << ptr_item->object_type_id() 
                <<", Name = " << ptr_item->name() << " ) was added in you wish list";
    
}

void city_buy_material_dlg::update_dialog() {
    enum_shop();
    int index = 0;
    milk::milk_spinboard_cells cells = m_spinboard->get_cells();
    
    m_count_material = 0;
    for (milk::milk_spinboard_cells::iterator it = cells.begin(); it != cells.end(); ++it) {
        sqc_shop_material_cell_ptr shop_material_cell = std::tr1::static_pointer_cast<sqc_shop_material_cell>(*it);
        
        m_count_material += m_items[index]->count();
        
        shop_material_cell->set_item(m_items[index]);
        shop_material_cell->layout_controls( m_window_ctx);
        ++index;
    }
}

sqc_dialog_update_callback city_buy_material_dlg::get_update_callback() {
    return std::tr1::bind(&city_buy_material_dlg::update_dialog, this);
}


END_NAMESPACE_SQC_FRAMEWORK