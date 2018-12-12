/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_game_settings_dlg.h"
#include "../city_framework.h"
using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// city_game_setting_dlg implementation
//

city_game_setting_dlg::~city_game_setting_dlg() {
}

// initialization 
void city_game_setting_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_game_setting_dlg::on_init_dialog" );
    
	sqc_dialog_with_close::on_init_dialog();
	
    // subscribe for events
    if ( m_socnet_delegate ) {
    	m_socnet_delegate->set_success_login_callback( 
	        std::tr1::bind( &city_game_setting_dlg::on_current_network_change, this ) );
    }
    
	sqc_window_factory& factory = framework().windows_factory();
	
	using namespace city_dlg_layout::game_setting_dlg;
	
	// create title
	{
        set_caption( framework().strings().load( 
           dialog_title.resource_id(), dialog_title.def_value() ) );
	}
	
	create_separator( shared_from_this(),city_dlg_layout::game_setting_dlg::separator_v1 );

	// animation
	milk::milk_label_ptr ptr_title;
    add_caption_and_switch( animation_label, animation_button,
		std::tr1::bind( &city_game_setting_dlg::on_animation_pressed, this, _1 ) );
	
	// enable sound
	add_caption_and_switch( sound_label, sound_button,
		std::tr1::bind( &city_game_setting_dlg::on_sound_pressed, this, _1 ) ,
         framework().preferences().get_bool("settings", "sound_enabled", true));

	// enable music
   	add_caption_and_switch( music_label, music_button,
		std::tr1::bind( &city_game_setting_dlg::on_music_pressed, this, _1 ) ,
        framework().preferences().get_bool("settings", "music_enabled", true));
	
	// contract notification
	add_caption_and_switch( contracts_label, contracts_button,
		std::tr1::bind( &city_game_setting_dlg::on_contract_notify_pressed, this, _1 ) );
	
	// population notification
	add_caption_and_switch( population_label, population_button,
		std::tr1::bind( &city_game_setting_dlg::on_population_notify_pressed, this, _1 ) );
	
	// tax notification
	add_caption_and_switch( tax_label, tax_button,
		std::tr1::bind( &city_game_setting_dlg::on_tax_notify_pressed, this, _1 ) );

	// network back "big" button
	{
		milk::milk_theme_button_ptr ptr_btn = 
		factory.create_button( m_window_ctx, shared_from_this(), network_background_btn );
		ptr_btn->set_action( 
			std::tr1::bind( &city_game_setting_dlg::on_change_network_pressed, this ) );
        
        
        // create current network button
        m_network_img = 
        factory.create_image( m_window_ctx, ptr_btn, current_network_image );
 	}
	
	// network description
	factory.create_label( m_window_ctx, shared_from_this(), change_network_descr );
	
	// change network button
	{
		milk::milk_theme_button_ptr ptr_btn = 
		factory.create_button( m_window_ctx, shared_from_this(), change_network_btn );
		ptr_btn->set_action( 
			std::tr1::bind( &city_game_setting_dlg::on_change_network_pressed, this ) );

		factory.create_label( m_window_ctx, shared_from_this(), change_network_caption );
	}
	
    // update image and caption for current network
    update_current_network_image();
}

// destroy dialog
void city_game_setting_dlg::end_dialog() {

    sqc_dialog_with_close::end_dialog();
}

bool city_game_setting_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a)
{
    a.title_args.flags |= milk::milk_font_modify_size;
    a.title_args.size = layout_vals(20,40,30).at( framework().windows_factory().get_theme_size() );

    return sqc_dialog_with_close::get_dialog_init_arg(a);

}

void city_game_setting_dlg::add_caption_and_switch(
	const label_layout& label,
	const switch_button_layout& switch_btn, 
	milk::switch_callback cb ,
    bool enabled ) {
	
	sqc_window_factory& factory = framework().windows_factory();
	
	// create label
	factory.create_label( m_window_ctx, shared_from_this(), label );
	
	// and button
	milk::milk_switch_button_ptr ptr_btn = 
	factory.create_switch_button( m_window_ctx, shared_from_this(), switch_btn );
	ptr_btn->set_state( enabled ? milk::switch_state_on : milk::switch_state_off );
	ptr_btn->set_action( cb );
}


// animation button is pressed
void city_game_setting_dlg::on_animation_pressed( 
	milk::switch_state new_state ) {
}

// enable sound button is pressed
void city_game_setting_dlg::on_sound_pressed( 
	milk::switch_state new_state ) {
    framework().preferences().set_bool("settings", "sound_enabled", milk::switch_state_on==new_state);
    framework().sound().set_sound_enabled(milk::switch_state_on==new_state);
}

// enable music button is pressed
void city_game_setting_dlg::on_music_pressed( 
	milk::switch_state new_state ) {
    framework().preferences().set_bool("settings", "music_enabled", milk::switch_state_on==new_state);
    if (new_state==milk::switch_state_on) {
        framework().sound().music().play();
    } else {
        framework().sound().music().stop();
    }
}

// contract notification button is pressed
void city_game_setting_dlg::on_contract_notify_pressed( 
	milk::switch_state new_state ) {
}

// population notification button is pressed
void city_game_setting_dlg::on_population_notify_pressed(
	milk::switch_state new_state ) {
}

// tax notification button is pressed
void city_game_setting_dlg::on_tax_notify_pressed( 
	milk::switch_state new_state ) {
}

// change network
void city_game_setting_dlg::on_change_network_pressed() {
	if ( m_socnet_delegate ) { 
	    m_socnet_delegate->change_network();
    }
}

// close dialog
void city_game_setting_dlg::on_current_network_change() {
    sqc_info() 
        << "game_settings_dlg: current network is changed - close all modal windows.";
    // and hide all other modal windows (main menu, main settings)
    get_server().close_modals( 
            std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
}

// update image and caption for current network
void city_game_setting_dlg::update_current_network_image() {
    if ( !m_network_img || !m_socnet_delegate ) {
        sqc_assert( false );
        return;
    }
    
    // retrieve network images
    const sqc_network_type network_type = m_socnet_delegate->current_network();
    const sqc_string network_image = m_socnet_delegate->get_network_image( network_type );
    
    m_network_img->set_image( 
            framework().graphics().create_image( network_image.c_str() ) );
}

END_NAMESPACE_SQC_FRAMEWORK