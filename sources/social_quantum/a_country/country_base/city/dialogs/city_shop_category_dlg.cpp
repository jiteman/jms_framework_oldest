/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_shop_category_dlg.h"
#include "city/city_framework.h"

#include "country_base/dialogs/select_person/sqc_select_person_controller.h"

#include "country_base/dialogs/select_construction/sqc_select_construction_controller.h"
#include "city/dialogs/select_construction/city_select_construction_dlg.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_category_dlg implementation
//

// initialization 
void city_shop_category_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_shop_category_dlg::on_init_dialog" );
    
	sqc_dialog_with_back_and_close::on_init_dialog();
	
	set_bevel_type( milk::milk_bevel_type_content_scroll );
	
	sqc_window_factory& factory = framework().windows_factory();

	using namespace layout::city_shop_category_dlg_layout;

        
	// create dialog title
	{
		sqc_string str_title = city::city_framework().shop().get_shop_category_name( m_params.shop_category );
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
    
    sqc_shop_enum_params enum_params( 0/*enum all levels*/, m_params.shop_category, shop_target );
    city::city_framework().shop().enum_shop_category( enum_params, m_params.scene_info, m_items );
    
    
    
    //create spinboard
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           shop_spinboard, 
                                           this );
    
    // set cell count
    m_cell_count = ( ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 );
    m_spinboard->set_visible_count( m_cell_count );

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

    {
        milk::milk_button_ptr add_coins_button_ptr = 
            framework().windows_factory().create_button( m_window_ctx, shared_from_this(), btn_add_coins );
	
        milk::milk_callback add_money_cb = std::tr1::bind( &city_shop_category_dlg::on_add_money, this ); 
        add_coins_button_ptr->set_action(add_money_cb);

        framework().windows_factory().create_label( m_window_ctx, add_coins_button_ptr, add_coins_caption );
    }
}	


bool city_shop_category_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
	a.bevel_bottom = m_balance_widget->get_rect().cy;
    
	return sqc_dialog_with_back_and_close::get_dialog_init_arg(a);
}



// milk_spinboard_callbacks interface
milk::milk_widget_ptr city_shop_category_dlg::create_cell(
    int idx, surf::surf_rect const &rect ) {
    PROFILE_ENTRY( "city_shop_category_dlg::create_cell" );
    
    if ( idx >= m_items.size() ||
        idx < 0 ) {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    // add cell object to spinboard
    sqc_shop_item_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_item_cell>( rect, m_items[idx], shop_target );
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_buy_callback(
        std::tr1::bind( &city_shop_category_dlg::on_buy_item_pressed, this, _1 ) );
        
    ptr_cell->set_gift_callback( 
    	std::tr1::bind( &city_shop_category_dlg::on_gift_item_pressed, this, _1 ) );
    
    bool draw_separator;
        
    if(0 == (idx+1) % m_cell_count) 
	    draw_separator = false;
    else 
    	draw_separator = true;
     
    ptr_cell->layout_controls( m_window_ctx, m_params.scene_info.level, draw_separator );    
    
    // fill cell with content
    fill_shop_item_cell( ptr_cell, m_items[idx] );
    
    return ptr_cell;
}

int city_shop_category_dlg::get_cell_count() {
    return m_items.size();
}

// add buttons, captions and image to cell
bool city_shop_category_dlg::fill_shop_item_cell(
    sqc_shop_item_cell_ptr ptr_cell,
    const sqc_shop_category_item_ptr item ) {

    if ( !ptr_cell ) {
        return false;
    }

    return true;
}



// user press buy item button
void city_shop_category_dlg::on_buy_item_pressed( const sqc_string& object_type ) {

	if ( sqc_shop_category_materials == m_params.shop_category ) {
    	// select construction
        
        sqc_select_construction_delegate_ptr ptr_delegate(
        		new sqc_apply_shop_material_controller( object_type ) );
                
        if ( !ptr_delegate ) {
        	return;
        }
            
        surf::surf_rect rect;
        city_select_construction_dlg_ptr ptr_dialog =
    	framework().windows().get_desktop()->create_child<city_select_construction_dlg>(
                                                                rect, 
                                                                ptr_delegate );
        if ( !ptr_dialog ) {
        	return;
        }
		
        ptr_dialog->do_modal();
        
    
    }
    
    /*
    else if ( sqc_shop_category_expand == m_params.shop_category ) {
    	// select expand
    }
    */
    else {
		// select everything else
        if ( m_params.buy_callback ) {
            bool res = m_params.buy_callback( object_type );
            if ( res ) {
                get_server().close_modals( 
                    std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
            }
        }
    }
}

// user press gift item button
void city_shop_category_dlg::on_gift_item_pressed( const sqc_string& object_type ) {

	// show friends dialog
    sqc_send_shop_gift_to_friend_controller_ptr ptr_delegate( new sqc_send_shop_gift_to_friend_controller() );
    ptr_delegate->set_select_person_callback( std::tr1::bind( &city_shop_category_dlg::on_select_user_for_gift,
												  this,
                                                  object_type,
                                                  std::tr1::placeholders::_1 ) );

	sqc::city::city_framework().ui().show_select_preson_dialog( ptr_delegate );
}

bool city_shop_category_dlg::on_select_user_for_gift(
	const sqc_string& object_type,
    const sqc_string& second_user_id) {
    
	if ( m_params.gift_callback ) {
    	m_params.gift_callback( object_type, second_user_id );
    }
    
    return true;
}

void city_shop_category_dlg::on_add_money()
{
	city::city_framework().dialogs().show_bucks_dialog( shared_from_this(), m_params.add_money );
}

END_NAMESPACE_SQC_FRAMEWORK