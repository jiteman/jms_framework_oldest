/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_buy_construction_dlg.h"
#include "../city_framework.h"
#include "../../country_base/dialogs/controls/sqc_shop_construction_cell.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_buy_construction_dlg implementation
//

// dialog title
sqc_string city_buy_construction_dlg::get_dialog_title() {
    using namespace city;
    return  city_framework().shop().
                get_shop_construction_category_name( m_category );
}

// category description
sqc_string city_buy_construction_dlg::get_category_descr() {
    using namespace city;
    return city_framework().shop().
            get_shop_construction_category_descr( m_category );
}

// category image
sqc_string city_buy_construction_dlg::get_category_image() {
    using namespace city;
    return city_framework().shop().
                get_shop_construction_category_image( m_category );
}

// initialization 
void city_buy_construction_dlg::on_init_dialog() {    
    PROFILE_ENTRY( "city_buy_construction_dlg::on_init_dialog" );
    using namespace city;
    
    // enum shop
    city_framework().shop().enum_shop_construction_category( m_category, m_items );

    // create spin, etc
	city_buy_building_base_dlg::on_init_dialog();
}	

// milk_spinboard_callbacks interface
milk::milk_widget_ptr city_buy_construction_dlg::create_cell(
    int idx, surf::surf_rect const &rect ) {
    
    PROFILE_ENTRY( "city_buy_construction_dlg::create_cell" );
    
    if ( idx >= m_items.size() ||
        idx < 0 ) {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }

    sqc_assert( m_spinboard );
    
    // add cell object to spinboard
    sqc_shop_construction_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_construction_cell>( rect, m_items[idx] );
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    ptr_cell->layout_controls( m_window_ctx); //, m_params.scene_info.level );
    
    ptr_cell->set_callbacks(
                            std::tr1::bind( &city_buy_construction_dlg::on_buy_item_pressed, this, std::tr1::placeholders::_1 ),
                            std::tr1::bind( &city_buy_construction_dlg::on_ask_item_pressed, this, std::tr1::placeholders::_1 ) );
    
    return ptr_cell;
}

int city_buy_construction_dlg::get_cell_count() {
    return m_items.size();
}

// user press buy item button
void city_buy_construction_dlg::on_buy_item_pressed( const sqc_string& object_type ) {
    
	if ( m_params.buy_callback ) {
    	bool res = m_params.buy_callback( object_type );
    	if ( res ) {
        	get_server().close_modals( 
                                      std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
        }
    }
}

// user press buy item button
void city_buy_construction_dlg::on_ask_item_pressed( const sqc_string& object_type ) {
    
}


END_NAMESPACE_SQC_FRAMEWORK