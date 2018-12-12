/*
 *  city_cityhall_hire.h
 *  aCountry
 *  Window employment figures. settings City Hall.
 *
 *  Created by Василий on 09.08.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_CITYHALL_SETTINGS_DLG_H_INCLUDED__
#define __SQC_CITY_CITYHALL_SETTINGS_DLG_H_INCLUDED__

#include "country_base/sqc_framework_base.h"
#include "city/dialogs/city_base_dlg.h"
#include "city_cityhall_settings_dlg_layout.h"
#include "city/dialogs/city_select_person/city_select_person_dlg.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"

#include "city_hall_delegate.h"

NAMESPACE_SQC_FRAMEWORK

// Base class of any agents
class cha_agent {
public:
	cha_agent( const city_hall_agent_info& _info ) 
    	: info(_info)
    {
    }
	virtual sqc_string get_name() {
    	return info.name;
    }
    virtual sqc_string get_description() {
    	return info.description;
    }
    virtual sqc_string get_picture() {
    	return info.avatar;
    }

    /// flag agent hiring
    bool is_hire() const {
    	return info.is_hired();
    }
    
    const city_hall_agent_info& get_info() const {
    	return info;
    }
protected:
    city_hall_agent_info	info;

private:
	// no copy
    cha_agent(const cha_agent & );
	cha_agent & operator=(const cha_agent & );
};

typedef std::tr1::shared_ptr<cha_agent> cha_agent_ptr;

/// inheritance milk_widget. draw
class agent_control : public milk::milk_widget
{
public:
	agent_control( milk::milk_widget_ptr p )
        
    : milk::milk_widget( p )
    , m_factory( framework().windows_factory() )
    { 
    }
	void layout_controls(sqc_window_factory_ctx_ptr window_ctx, milk::milk_callback button_callback );
    void on_action();

	void refresh( cha_agent_ptr options );
    
private:
	sqc_window_factory& m_factory;
    milk::milk_image_ptr 			m_i_pers;
    sqc_proxy_texture_widget_ptr	m_avatar_widget;
    milk::milk_label_ptr m_l_name;
    milk::milk_label_ptr m_l_descr;
    milk::milk_label_ptr m_l_action;
    sqc_window_factory_ctx_ptr m_window_ctx;
    milk::milk_callback		   m_button_callback;
};

typedef std::tr1::shared_ptr< agent_control > agent_control_ptr;


class city_cityhall_settings_dlg : public sqc_dialog_with_close {
public:

	city_cityhall_settings_dlg( milk::milk_widget_ptr p,
		city_hall_delegate_ptr delegate )

		: sqc_dialog_with_close( p, city_dlg_layout::cityhall_settings_dlg::background )
		, m_factory( framework().windows_factory() )
        , m_delegate( delegate )
    {
    }
    
    
    void on_init_dialog();
    int  get_operation();
    void on_addcoins();
    void on_refill_pressed();

	void	on_fiscal_agent_pressed();
    void	on_municipal_officer_pressed();
    void	refresh();

protected:

	sqc_window_factory& m_factory;
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);

	milk::milk_label_ptr	m_operation_label;
    agent_control_ptr		m_fiscal_agent_cell;
    agent_control_ptr		m_municipal_oficer_cell;
    
	city_hall_delegate_ptr m_delegate;
};

typedef std::tr1::shared_ptr<city_cityhall_settings_dlg> city_cityhall_settings_dlg_ptr;




END_NAMESPACE_SQC_FRAMEWORK


#endif

