/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_dialogs.h"
#include "../city_framework.h"

#include "city_main_menu_dlg.h"
#include "city_game_settings_dlg.h"
#include "city_select_network_dlg.h"
#include "city_shop_categories_dlg.h"
#include "city_shop_category_dlg.h"
#include "city_buy_construction_dlg.h"
#include "city_buy_material_dlg.h"
#include "city_money_dlg.h"
#include "city_login_progress_dlg.h"
#include "city_level_up_dlg.h"
#include "city_on_next_level_available_dlg.h"
#include "city_shop_contracts_dlg.h"
#include "city_daily_gift_dlg.h"
#include "country_base/dialogs/sqc_daily_request_dlg.h"
#include "city_select_person/city_select_person_dlg.h"
#include "city_select_person/city_select_person_controller.h"
#include "country_base/dialogs/sqc_social_network_controller.h"
#include "city/dialogs/city_gift_wish/city_gift_wish_dlg.h"
#include "country_base/dialogs/gift_wish/sqc_gift_controller.h"
#include "city/dialogs/select_construction/city_select_construction_dlg.h"
#include "city_net_changed_dlg.h"
#include "city_update_message_dlg.h"


#include "city/dialogs/city_management/city_buy_management.h"
#include "city/dialogs/city_management/city_cityhall_settings_dlg.h"
#include "city/dialogs/city_management/city_salary_dlg.h"
#include "city/dialogs/city_management/city_taxadmin_settings_dlg.h"
#include "city/dialogs/city_management/city_hall_controller.h"
#include "city/dialogs/city_management/city_salary_controller.h"
#include "city/dialogs/city_management/city_tax_admin_controller.h"

NAMESPACE_SQC_FRAMEWORK

/**********************************************************/
/// city_dialogs constructor

city_dialogs::city_dialogs(sqc_notify_center &notification_center) 
	: m_notify_center(notification_center) {
    
    subscribe_events();
}

/**********************************************************/
/// city_dialogs destructor

city_dialogs::~city_dialogs() {
    unsubscribe_events();
}

/**********************************************************/
/// Show a simple message box

milk::milk_dialog_ptr city_dialogs::show_message_box( 
	const sqc_message_box_params& params ) {
    
    surf::surf_rect rect;
    city_message_box_ptr dlg = desktop()->
                create_child<city_message_box>( rect );
                
    dlg->set_properties( params.dlg_title, 
                         params.dlg_text,
                         params.button_text );
    
	dlg->do_modal();
    return dlg;
}

/**********************************************************/
/// Show login progress window

milk::milk_dialog_ptr city_dialogs::show_login_progress_window( 
	const sqc_show_login_progress_params& params ) {
    
    surf::surf_rect rect;
    city_login_progress_window_ptr dlg = desktop()->
                create_child<city_login_progress_window>( rect );
                
	dlg->do_modal();
    return dlg;
}

/**********************************************************/
/// Show select network dialog

milk::milk_dialog_ptr city_dialogs::show_select_network_dialog( 
	const sqc_select_network_params& params ) {

	surf::surf_rect rect;
	city_select_network_dlg_ptr dlg = desktop()->
  				  create_child<city_select_network_dlg>( rect, params );

	dlg->do_modal();
    return dlg;
}

milk::milk_dialog_ptr city_dialogs::show_visit_friend_dialog() {
	surf::surf_rect rect;
    
    sqc_select_preson_delegate_ptr ptr_delegate( new city_visit_friend_field_controller );
	city_select_person_dlg_ptr dlg = desktop()->create_child<city_select_person_dlg>( rect, ptr_delegate );
    dlg->do_modal();
    return dlg;
}


milk::milk_dialog_ptr city_dialogs::show_select_preson_dialog( 
    sqc_select_preson_delegate_ptr delegate ) {
	surf::surf_rect rect;
    
    
    if ( !delegate ) {
    	sqc_assert( false );
    	return milk::milk_dialog_ptr();
    }
	city_select_person_dlg_ptr dlg = desktop()->create_child<city_select_person_dlg>( rect, delegate );
    dlg->do_modal();
    return dlg;
	    
}

milk::milk_dialog_ptr city_dialogs::show_select_construction_dlg(
	sqc_select_construction_delegate_ptr delegate ) {
	
    if ( !delegate ) {
    	sqc_assert( false );
    	return milk::milk_dialog_ptr();
    }

	surf::surf_rect rect;
	city_select_construction_dlg_ptr ptr_dialog =
		framework().windows().get_desktop()->create_child<city_select_construction_dlg>(
			rect, delegate );

    sqc_assert(ptr_dialog);

    ptr_dialog->do_modal();

    return ptr_dialog;
}


// show level up dialog
milk::milk_dialog_ptr city_dialogs::show_level_up_dialog(sqc_level_up_params& params )
{
  	surf::surf_rect rect;
	city_level_up_dlg_ptr dlg = desktop()->
    create_child<city_level_up_dlg>( rect, params );
    
	dlg->do_modal();
    return dlg;
}

milk::milk_dialog_ptr  city_dialogs::show_on_next_level_dialog( sqc_on_next_level_params& params )
{
    surf::surf_rect rect;
    city_on_next_level_dlg_ptr dlg = desktop()->
    create_child<city_on_next_level_dlg>(rect,params);
    dlg->do_modal();
    return dlg;
}

milk::milk_dialog_ptr city_dialogs::show_gift_wish_dialog() {
	surf::surf_rect rect;

	sqc_gift_delegate_ptr ptr_gift_delegate( new sqc_gift_controller );
    if ( !ptr_gift_delegate ) {
    	return milk::milk_dialog_ptr();
    }
    
    city_gift_wish_dlg_ptr dlg = desktop()->
	    create_child<city_gift_wish_dlg>( rect, ptr_gift_delegate );
        
    dlg->do_modal();
    return dlg;
}

// create level up dialog
milk::milk_dialog_ptr city_dialogs::create_level_up_dialog(sqc_level_up_params& params )
{
  	surf::surf_rect rect;
	city_level_up_dlg_ptr dlg = desktop()->
    create_child<city_level_up_dlg>( rect, params );

    return dlg;
}

/*******************************************************/
/// create daily gift dialog

milk::milk_dialog_ptr city_dialogs::create_daily_gift_dialog( daily_dlg_param param )
{
    surf::surf_rect rect;
    city_daily_gift_dlg_ptr dlg = desktop()->
    create_child<city_daily_gift_dlg>(rect,daily_gift_controller_face_ptr(new daily_gift_controller(param)));
    
    return dlg;
}


/**********************************************************/
/// Soc net changed dialog

milk::milk_dialog_ptr  city_dialogs::create_net_changed_dialog()
{   
    surf::surf_rect rect;
	city_net_changed_dlg_ptr dlg = desktop()->
    create_child<city_net_changed_dlg>( rect );
    
	return dlg;
}

/**********************************************************/
/// Create update message

milk::milk_dialog_ptr city_dialogs::create_update_message_dialog(sqc_game_ptr game)
{
    surf::surf_rect rect;
    update_message_controller_face_ptr ctrl(new city_update_message_controller(game));
    
    if(!ctrl)
     return milk::milk_dialog_ptr();
       
    if(0 == ctrl->get_cell_count())
    {
        sqc_info() << "create_update_message_dialog: update_message_dialog content empty. Dialog woud't show";
        return milk::milk_dialog_ptr();
    }
    
	city_update_message_dlg_ptr dlg = desktop()->
        create_child<city_update_message_dlg>( rect, ctrl );
    
	return dlg;    
}


milk::milk_dialog_ptr  city_dialogs::create_on_next_level_dialog( sqc_on_next_level_params& params )
{
    surf::surf_rect rect;
    city_on_next_level_dlg_ptr dlg = desktop()->
    create_child<city_on_next_level_dlg>(rect,params);

    return dlg;
}

milk::milk_dialog_ptr city_dialogs::create_daily_request_dialog(sqc_daily_gift_param param)
{

    surf::surf_rect rect;
    sqc_daily_request_dlg_ptr dlg = desktop()->
    create_child<sqc_daily_request_dlg>(rect,daily_request_controller_face_ptr(new daily_request_controller(param)));
    
    return dlg;
}


/// Show main menu dialog
void city_dialogs::show_main_menu_dialog( 
	const sqc_main_menu_params& params ) {

    sqc_social_network_delegate_ptr socnet_delegate( new sqc_social_network_controller );
    if ( !socnet_delegate ) {
    	return;
    }

	surf::surf_rect rect;
	city_main_menu_dlg_ptr dlg = desktop()->
                create_child<city_main_menu_dlg>( rect, socnet_delegate, params );
	dlg->do_modal();
}

/// Show game settings dialog
void city_dialogs::show_game_setting_dialog( 
	const sqc_game_setting_params& params ) {
     
    sqc_social_network_delegate_ptr socnet_delegate( new sqc_social_network_controller );
    if ( !socnet_delegate ) {
    	return;
    }
    
	surf::surf_rect rect;
	city_game_setting_dlg_ptr dlg = desktop()->
                create_child<city_game_setting_dlg>( rect, socnet_delegate, params );
	dlg->do_modal();
}

// show shop contracts dialog
void city_dialogs::show_shop_contracts_dialog( 
    const sqc_shop_contract_params& params ) {
    
	surf::surf_rect rect;
	city_shop_contracts_dlg_ptr dlg = desktop()->
    create_child<city_shop_contracts_dlg>( rect, params );
	dlg->do_modal();
}

/**********************************************************/
/// Show shop categories dialog

void city_dialogs::show_shop_categories_dialog( 
	const sqc_shop_categories_params& params ) {
    
	surf::surf_rect rect;
	city_shop_categories_dlg_ptr dlg = desktop()->
        create_child<city_shop_categories_dlg>( rect, params );
	dlg->do_modal();
}

/**********************************************************/
/// Show shop categories dialog

void city_dialogs::show_shop_category_dialog( 
    const sqc_shop_category_params& params ) {
    
	surf::surf_rect rect;
	city_shop_category_dlg_ptr dlg = desktop()->
            create_child<city_shop_category_dlg>( rect, params );
	dlg->do_modal();
}

/**********************************************************/
/// Shop construction dialog

void city_dialogs::show_buy_construction_dialog( 
    const sqc_shop_construction_params& params) {
    
	surf::surf_rect rect;
	city_buy_construction_dlg_ptr dlg = desktop()->
        create_child<city_buy_construction_dlg>( rect, params );
	dlg->do_modal();
}
    
/**********************************************************/
/// Shop materials dialog

void city_dialogs::show_buy_material_dialog( 
    const sqc_shop_material_params& params ) {

	surf::surf_rect rect;
	city_buy_material_dlg_ptr dlg = desktop()->
            create_child<city_buy_material_dlg>( rect, params );
    
    sqc_update_callback_list::iterator it = 
                m_update_callbacks.insert(m_update_callbacks.end(), dlg->get_update_callback());
    
    dlg->set_destroy_handler(std::tr1::bind(&city_dialogs::destroy_dialog_handler, this, it));
	
    dlg->do_modal();
}

/**********************************************************/
/// Show salary dialog 

void city_dialogs::show_salary_dialog()
{
    surf::surf_rect rect;
    
    city_salary_delegate_ptr delegate( new city_salary_controller() );
    if ( !delegate ) {
    	return;
    }
    
    sqc_salary_dlg_ptr dlg = desktop()->
    create_child<city_salary_base_dlg>(rect,delegate);
    dlg->do_modal();
}



/**********************************************************/
/// Show add bucks dialog

void city_dialogs::show_bucks_dialog( milk::milk_widget_ptr p, const sqc_add_money_params& add_money_params ) {
	surf::surf_rect rect;
	money_dlg_ptr dlg = desktop()->create_child<money_dlg>(rect, add_money_params);
	dlg->switch_megabucks();
}

/**********************************************************/
/// Show add coins dialog

void city_dialogs::show_coins_dialog( milk::milk_widget_ptr p, const sqc_add_money_params& add_money_params ) {
	surf::surf_rect rect;
	money_dlg_ptr dlg = desktop()->create_child<money_dlg>(rect, add_money_params);
	dlg->switch_coins();
}

/**********************************************************/
/// Show city hall dialog

void city_dialogs::show_cityhall_dialog( milk::milk_widget_ptr p )

{
	surf::surf_rect rect;
    
    city_hall_delegate_ptr delegate = city_hall_delegate_ptr( new city_hall_controller() );
    if ( !delegate ) {
    	return;
    }
    
    if ( delegate->has_city_hall() ) {
        city_cityhall_settings_dlg_ptr dlg =
            desktop()->create_child<city_cityhall_settings_dlg>( rect, delegate );
        dlg->do_modal();
    } else {
        city_buy_cityhall_dlg_ptr dlg =
            desktop()->create_child<city_buy_cityhall_dlg>( rect, delegate );
        dlg->do_modal();
    }
    
}

/**********************************************************/
/// Show tax administration dialog

void city_dialogs::show_tax_administration_dialog( milk::milk_widget_ptr p ) 
{

	surf::surf_rect rect;

    city_tax_admin_delegate_ptr delegate = city_tax_admin_delegate_ptr( new city_tax_admin_controller() );
    if ( !delegate ) {
    	return;
    }
    
    if ( delegate->has_tax_admin() ) {
        city_taxadmin_settings_dlg_ptr dlg =
            desktop()->create_child<city_taxadmin_settings_dlg>( rect, delegate );
        dlg->do_modal();
    } else {
        city_buy_tax_administration_dlg_ptr dlg =
            desktop()->create_child<city_buy_tax_administration_dlg>( rect, delegate );
        dlg->do_modal();
    }
}

milk::milk_widget_ptr city_dialogs::desktop() const {
	return framework().windows().get_desktop();
}

void city_dialogs::destroy_dialog_handler(sqc_update_callback_list::iterator it) {
    m_update_callbacks.erase(it);
}

void city_dialogs::subscribe_events() {
    using namespace std::tr1::placeholders;
    m_notify_connection = m_notify_center.subscribe( 
                            std::tr1::bind( &city_dialogs::notify_callback, this, _1, _2 ) );
}

void city_dialogs::unsubscribe_events() {
    m_notify_center.unsubscribe( m_notify_connection );
}

void city_dialogs::notify_callback(const sqc_provider_id& provider_id, const sqc_event_id& event_id ) {
    
    if ( processor::command_processor_provider_id == provider_id ) {
        if (  processor::command_processor_initial_xml_complete_event == event_id ) {
            activate_update_callbacks();
        }
    }
}

void city_dialogs::activate_update_callbacks() {
    for (sqc_update_callback_list::iterator it = m_update_callbacks.begin(); it != m_update_callbacks.end(); ++it) {
        (*it)();
    }
}

END_NAMESPACE_SQC_FRAMEWORK
