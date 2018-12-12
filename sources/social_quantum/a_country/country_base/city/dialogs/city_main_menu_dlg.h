/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_MAIN_MENU_DLG_H_INCLUDED__
#define __SQC_CITY_MAIN_MENU_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_main_menu_dlg_layout.h"
#include "country_base/dialogs/sqc_social_network_delegate.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_main_menu_dlg implementation
//
class city_main_menu_dlg : public sqc_dialog_with_back_and_close {
public:
	city_main_menu_dlg( milk::milk_widget_ptr p, 
    					sqc_social_network_delegate_ptr socnet_delegate,
    					const sqc_main_menu_params& params ) 
		: sqc_dialog_with_back_and_close( p, city_dlg_layout::main_menu_dlg::background )
        , m_socnet_delegate( socnet_delegate )
        , m_params( params ) {
	}
	
protected:
	// initialization 
	virtual void on_init_dialog();
	
protected:
	// tax admin button is pressed
    void on_tax_admin_pressed();
	// help button is pressed
    void on_help_pressed();
	// settings button is pressed
    void on_settings_pressed();
	// city_hall button is pressed
    void on_city_hall_pressed();
	// bucks button is pressed
    void on_add_bucks_pressed();
	// gold button is pressed
    void on_add_coins_pressed();    
    // social button pressed
    void on_social_button_pressed();
    
    // close dialog
    void on_current_network_change();

	
protected:
	void add_button_and_caption( const image_button_layout& btn, 
						 const label_layout& label, 
						 milk::milk_callback cb );
                         
	sqc_main_menu_params			m_params;
    sqc_social_network_delegate_ptr m_socnet_delegate;   

};

typedef std::tr1::shared_ptr<city_main_menu_dlg>	city_main_menu_dlg_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_MAIN_MENU_DLG_H_INCLUDED__


