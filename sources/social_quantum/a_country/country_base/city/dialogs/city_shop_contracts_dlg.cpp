/*
 *  city_shop_contracts_dlg.cpp
 *  aCountry
 *
 *  Created by Maxim Korolkov on 06.09.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#include "city_shop_contracts_dlg.h"
#include "city/city_framework.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_category_dlg implementation
//

// initialization 
void city_shop_contracts_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_shop_contracts_dlg::on_init_dialog" );
    
	sqc_dialog_with_back_and_close::on_init_dialog();
	
	set_bevel_type( milk::milk_bevel_type_content_scroll );
	
	sqc_window_factory& factory = framework().windows_factory();

	using namespace layout::city_shop_contracts_dlg_layout;
	
	// create dialog title
	{
		sqc_string str_title = city::city_framework().shop().get_shop_contracts_name();
		set_caption( str_title );
	}
   
    // create balance label and balance widget
    {
        factory.create_label( m_window_ctx, shared_from_this(), balance_label );
        
        surf::surf_rect rc = factory.layout_child_rects( 
                                shared_from_this(), 
                                balance_widget_rects,
                                balance_widget_alignment );
                                
        m_balance_widget =
		shared_from_this()->create_child<sqc_balance_widget>( rc );
        m_balance_widget->layout_controls( m_window_ctx );

    }

    // enum shop
    m_items.clear();
    
    city::city_framework().shop().enum_shop_contracts( m_params.factory_type, m_items );
    
    //create spinboard
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           shop_spinboard, 
                                           this );
    
    // set cell count
    int cell_count = ( ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 );
    m_spinboard->set_visible_count( cell_count );

	// create pager
	factory.create_spinboard_pager( m_window_ctx,
								   shared_from_this(),
								   m_spinboard,
								   shop_spinboard_pager );
	
    // update balance
    if ( m_balance_widget ) {
        m_balance_widget->update_coins( m_params.scene_info.coins );
        m_balance_widget->update_bucks( m_params.scene_info.bucks );
    }
    
}	

bool city_shop_contracts_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
	if (m_balance_widget) a.bevel_bottom = m_balance_widget->get_rect().cy;
    
	return sqc_dialog_with_back_and_close::get_dialog_init_arg(a);
}

// milk_spinboard_callbacks interface
milk::milk_widget_ptr city_shop_contracts_dlg::create_cell(
    int idx, surf::surf_rect const &rect ) {
    PROFILE_ENTRY( "city_shop_contract_dlg::create_cell" );
    
    if ( idx >= m_items.size() ||
        idx < 0 ) {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    // add cell object to spinboard
    sqc_shop_contract_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_contract_cell>( rect, m_items[idx] );
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    ptr_cell->set_callbacks(
        std::tr1::bind( &city_shop_contracts_dlg::on_buy_item_pressed, this, _1 ) );

    bool draw_separator = true;
    ptr_cell->layout_controls( m_window_ctx, m_params.scene_info.level, draw_separator );
    
    // fill cell with content
    fill_shop_contract_cell( ptr_cell, m_items[idx] );
    
    return ptr_cell;
}

int city_shop_contracts_dlg::get_cell_count() {
    return m_items.size();
}

// add buttons, captions and image to cell
bool city_shop_contracts_dlg::fill_shop_contract_cell( sqc_shop_contract_cell_ptr ptr_cell,
                                const sqc_shop_contract_item_ptr item ) {

    if ( !ptr_cell ) {
        return false;
    }

    return true;
}

// user press buy item button
void city_shop_contracts_dlg::on_buy_item_pressed( const sqc_string& object_type ) {

	if ( m_params.buy_callback ) {
    	bool res = m_params.buy_callback( object_type );
    	if ( res ) {
        	get_server().close_modals( 
            	std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
        }
    }
}


END_NAMESPACE_SQC_FRAMEWORK