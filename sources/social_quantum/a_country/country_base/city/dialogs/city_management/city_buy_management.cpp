/*
 *  city_buy_management.cpp
 *  aCountry
 *
 *  Created by Василий on 04.08.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_buy_management.h"
#include "city/dialogs/city_money_dlg.h"
#include "city_cityhall_settings_dlg.h"
#include "city_taxadmin_settings_dlg.h"
#include "city/city_framework.h"


NAMESPACE_SQC_FRAMEWORK

using namespace city_dlg_layout;
using namespace std::tr1::placeholders;

/*****************************************************************************/
//  Class city_buy_management_base implementation

void city_buy_management_base::on_init_dialog()
{
    PROFILE_ENTRY( "city_buy_management_base::on_init_dialog" );

    sqc_dialog_with_close::on_init_dialog();

	set_caption(get_object_title());
    
	// add coins button

    milk::milk_button_ptr addcoins_button_ptr = 
    	m_factory.create_button( m_window_ctx, shared_from_this(), buy_management_dlg::add_coins_button );

    milk::milk_callback addcoins_cb = std::tr1::bind(&city_buy_management_base::on_add_coins, this); 
    addcoins_button_ptr->set_action( addcoins_cb );
    
	m_factory.create_label( m_window_ctx, shared_from_this(), buy_management_dlg::add_coins_caption );

	sqc_theme_size current_theme = m_factory.get_theme_size();

    surf::surf_rect cell_rect( buy_management_dlg::item_rects.at(current_theme) );

	sqc_shop_enum_params enum_params(0, sqc_shop_category_all, construction_target);
    
    sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
	m_item_ptr = city::city_framework().shop().find_shop_item_by_type_name(enum_params, scene_info, get_type_name());
    
    if (!m_item_ptr) {
		sqc_error() << "returns empty item";
        m_item_ptr.reset(
			new sqc_shop_category_item( "", "" ) );
    }
	else {
        // shop_category_item m_item_ptr
        m_item_ptr->set_name("");
        m_ptr_cell = 
            shared_from_this()->create_child<sqc_shop_item_cell>( cell_rect, m_item_ptr, shop_target );
            
        set_on_buy(m_ptr_cell);
        bool divider = false;
        int level = 0;
        m_ptr_cell->layout_controls(m_window_ctx, level, divider);
    }
    
	milk::milk_label_ptr lb_header_ptr = m_factory.create_label( m_window_ctx, shared_from_this(), buy_management_dlg::cityhall_header );
    lb_header_ptr->set_caption(get_object_header());
    
	milk::milk_label_ptr lb_description_ptr = m_factory.create_label( m_window_ctx, shared_from_this(), buy_management_dlg::cityhall_descr );
    lb_description_ptr->set_caption( get_object_description() );
}

void city_buy_management_base::on_add_coins() {

	sqc_add_money_params params;
	surf::surf_rect rect;
	money_dlg_ptr dlg = framework().windows().get_desktop()->create_child<money_dlg>(rect, params);
	dlg->switch_megabucks();
}

/*****************************************************************************/
//  Class city_buy_cityhall_dlg implementation

city_buy_cityhall_dlg::city_buy_cityhall_dlg( milk::milk_widget_ptr p,
                      city_hall_delegate_ptr delegate )
    : city_buy_management_base(p)
    , m_delegate( delegate )
{
    sqc_common_scene_info scene_info;
    m_delegate->get_scene_info( scene_info );

	sqc_shop_enum_params enum_params(0, sqc_shop_category_all, shop_target);
	m_item_ptr = city::city_framework().shop().find_shop_item_by_type_name(enum_params, scene_info, get_type_name());

}

sqc_string city_buy_cityhall_dlg::get_object_title()
{
	return "City Hall";
}

sqc_string city_buy_cityhall_dlg::get_object_header()
{
	return "You haven't built this construction yet";
}

sqc_string city_buy_cityhall_dlg::get_object_description()
{
	return "City hall allow you to hire your friend as fiscal \
agents or administration officers. It helps to automate tax collection and census of population.";
}

sqc_string city_buy_cityhall_dlg::get_type_name() {
	return "city_hall_real";
}

void city_buy_cityhall_dlg::on_buy(const sqc_string& s) {

	if ( m_delegate->buy_city_hall( s ) ) {
	    get_server().close_modals( 
        	std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );	
    }
}

void city_buy_cityhall_dlg::set_on_buy(sqc_shop_item_cell_ptr ptr_cell)
{
    cell_buy_callback cb_buy = std::tr1::bind(&city_buy_cityhall_dlg::on_buy, this, _1);
	ptr_cell->set_buy_callback( cb_buy );
}

void city_buy_cityhall_dlg::get_scene_info( sqc_common_scene_info& scene_info ) {
	m_delegate->get_scene_info( scene_info );
}


/*****************************************************************************/
//  Class city_buy_taxadministration implementation

sqc_string city_buy_tax_administration_dlg::get_object_title()
{
	return "Tax oficce";
}

sqc_string city_buy_tax_administration_dlg::get_object_header()
{
	return "You haven't built this construction yet";
}

sqc_string city_buy_tax_administration_dlg::get_object_description()
{
	return "You can regulate interest rates of tax charges in the Tax Administration";
}

sqc_string city_buy_tax_administration_dlg::get_type_name() {
	return "tax_collector_real";
}


void city_buy_tax_administration_dlg::on_buy(const sqc_string& s) {

	if ( m_delegate->buy_tax_admin( s ) ) {
	    get_server().close_modals( 
        	std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );	
    }
}

void city_buy_tax_administration_dlg::set_on_buy(sqc_shop_item_cell_ptr ptr_cell) {

    cell_buy_callback cb_buy = std::tr1::bind(&city_buy_tax_administration_dlg::on_buy, this, _1);
	ptr_cell->set_buy_callback( cb_buy );
 
}

void city_buy_tax_administration_dlg::get_scene_info( sqc_common_scene_info& scene_info ) {
	m_delegate->get_scene_info( scene_info );
}

END_NAMESPACE_SQC_FRAMEWORK
