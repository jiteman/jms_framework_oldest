/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_GAME_SETTINGS_DLG_H_INCLUDED__
#define __SQC_CITY_GAME_SETTINGS_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_game_settings_dlg_layout.h"
#include "country_base/dialogs/sqc_social_network_delegate.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_game_setting_dlg implementation
//
class city_game_setting_dlg : public sqc_dialog_with_close {
public:
	city_game_setting_dlg( milk::milk_widget_ptr p,
                           sqc_social_network_delegate_ptr socnet_delegate,
						   const sqc_game_setting_params& params ) 
		: sqc_dialog_with_close( p, city_dlg_layout::game_setting_dlg::background )
        , m_socnet_delegate( socnet_delegate )
        , m_params( params ) {
	}
	~city_game_setting_dlg();
protected:
	// initialization 
	virtual void on_init_dialog();
	// destroy dialog
	virtual void end_dialog();
    
protected:
	// animation button is pressed
    void on_animation_pressed( milk::switch_state new_state );
	// enable sound button is pressed
    void on_sound_pressed( milk::switch_state new_state );
	// enable music button is pressed
    void on_music_pressed( milk::switch_state new_state );
	// contract notification button is pressed
    void on_contract_notify_pressed( milk::switch_state new_state );
	// population notification button is pressed
    void on_population_notify_pressed( milk::switch_state new_state );
	// tax notification button is pressed
    void on_tax_notify_pressed( milk::switch_state new_state );

	// change network
    void on_change_network_pressed();
	
protected:
	void add_caption_and_switch( const label_layout& label,
								const switch_button_layout& switch_btn, 
								milk::switch_callback cb ,bool enabled=true);
                                
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
    
protected:
    // update image and caption for current network
    void update_current_network_image();
    // close dialog
    void on_current_network_change();
    
protected:
    milk::milk_image_ptr       		 m_network_img;
	sqc_social_network_delegate_ptr m_socnet_delegate;   
    sqc_game_setting_params			m_params;
};

typedef std::tr1::shared_ptr<city_game_setting_dlg>	city_game_setting_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_GAME_SETTINGS_DLG_H_INCLUDED__


