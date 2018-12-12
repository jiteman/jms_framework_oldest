/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_main_menu_dlg.h"
#include "../city_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// city_main_menu_dlg implementation
//

// initialization 
void city_main_menu_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_game_setting_dlg::on_init_dialog" );
    
	sqc_dialog_with_back_and_close::on_init_dialog();
	
	using namespace city_dlg_layout::main_menu_dlg;
	
    // subscribe for events
    if ( m_socnet_delegate ) {
    	m_socnet_delegate->set_success_login_callback( 
	        std::tr1::bind( &city_main_menu_dlg::on_current_network_change, this ) );
    }
    
	// create title
	{
		set_caption( framework().strings().load( 
				dialog_title.resource_id(), dialog_title.def_value() ) );
	}
	
	// add tax admin controls
	add_button_and_caption( tax_admin_button, tax_admin_label, 
			std::tr1::bind( &city_main_menu_dlg::on_tax_admin_pressed, this ) );
						 
	// add help controls
    add_button_and_caption( help_button, help_label,
			std::tr1::bind( &city_main_menu_dlg::on_help_pressed, this ) );
						   
	// add settings controls
    add_button_and_caption( settings_button, settings_label,
			std::tr1::bind( &city_main_menu_dlg::on_settings_pressed, this ) );
						   
	// add city_hall controls
    add_button_and_caption( city_hall_button, city_hall_label,
			std::tr1::bind( &city_main_menu_dlg::on_city_hall_pressed, this ) );
            
    // add city_hall controls
    add_button_and_caption( social_button, social_label,
                           std::tr1::bind( &city_main_menu_dlg::on_social_button_pressed, this ) );

	// add gold controls
    add_button_and_caption( add_coins_button, add_coins_label,
						 std::tr1::bind( &city_main_menu_dlg::on_add_coins_pressed, this ) );

	
	//if(![[[SocNetManager sharedManager].socnetAPI getAPIName] isEqualToString:@"od"])
	{
		// add bucks controls
		add_button_and_caption( add_bucks_button, add_bucks_label,
				std::tr1::bind( &city_main_menu_dlg::on_add_bucks_pressed, this ) );
					
		// add bucks separator
		create_separator( shared_from_this(), separator_h1 );
        create_separator( shared_from_this(), separator_h2 );
        create_separator( shared_from_this(), separator_v1 );
        create_separator( shared_from_this(), separator_v2 );
        create_separator( shared_from_this(), separator_v3 );
	}
	
}

void city_main_menu_dlg::add_button_and_caption(
	const image_button_layout& btn,
	const label_layout& label,
	milk::milk_callback cb ) {
	
	sqc_window_factory& factory = framework().windows_factory();
	
	// create button
	milk::milk_image_button_ptr ptr_btn = 
	factory.create_button( m_window_ctx, shared_from_this(), btn );
	
	ptr_btn->set_action( cb );
	
	// and label
	factory.create_label( m_window_ctx, shared_from_this(), label );
}

// tax admin button is pressed
void city_main_menu_dlg::on_tax_admin_pressed() {
    city_dialogs& dialogs = city::city_framework().dialogs();
	dialogs.show_tax_administration_dialog( shared_from_this() );
}

// help button is pressed
void city_main_menu_dlg::on_help_pressed() {
}

// settings button is pressed
void city_main_menu_dlg::on_settings_pressed() {
	city_dialogs& dialogs = city::city_framework().dialogs();
	dialogs.show_game_setting_dialog( m_params.game_setting_params );
}

// city_hall button is pressed
void city_main_menu_dlg::on_city_hall_pressed() {
	city_dialogs& dialogs = city::city_framework().dialogs();
    dialogs.show_cityhall_dialog( shared_from_this() );
}

void city_main_menu_dlg::on_social_button_pressed(){
	if ( m_socnet_delegate ) { 
	    m_socnet_delegate->change_network();
    }
}

// bucks button is pressed
void city_main_menu_dlg::on_add_bucks_pressed() {
	city_dialogs& dialogs = city::city_framework().dialogs();
	dialogs.show_bucks_dialog( shared_from_this(), m_params.add_money );
}

// coins button is pressed
void city_main_menu_dlg::on_add_coins_pressed() {
	city_dialogs& dialogs = city::city_framework().dialogs();
	dialogs.show_coins_dialog( shared_from_this(), m_params.add_money );
}

// close dialog
void city_main_menu_dlg::on_current_network_change() {
    sqc_info() 
        << "city_main_menu_dlg: current network is changed - close all modal windows.";
    // and hide all other modal windows (main menu, main settings)
    get_server().close_modals( 
            std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
}


END_NAMESPACE_SQC_FRAMEWORK
