/*
 *  city_cityhall_hire.cpp
 *  aCountry
 *
 *  Created by Василий on 09.08.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city_cityhall_settings_dlg.h"
#include "city_cityhall_settings_dlg_layout.h"
#include "city/city_framework.h"
#include "city/dialogs/city_money_dlg.h"
#include "city/dialogs/city_management/city_salary_dlg.h"
#include "city/dialogs/city_dialogs.h"

NAMESPACE_SQC_FRAMEWORK

using namespace city_dlg_layout;

void city_cityhall_settings_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_cityhall_settings_dlg::on_init_dialog" );
    sqc_dialog_with_close::on_init_dialog();
    
    sqc_assert( m_delegate );
    
    m_delegate->set_refresh_callback( std::tr1::bind( &city_cityhall_settings_dlg::refresh, this ) );
    
	sqc_theme_size current_theme = m_factory.get_theme_size();
	surf::surf_rect fiscal_rectangle( cityhall_settings_dlg::rct_fiscal_agent.at(current_theme) );

	/// dialog title
	set_caption( framework().strings().load( 
											cityhall_settings_dlg::dialog_title.resource_id(), cityhall_settings_dlg::dialog_title.def_value() ) );
	
	/// deparators
	create_separator( shared_from_this(),cityhall_settings_dlg::separator_h1);
	create_separator( shared_from_this(),cityhall_settings_dlg::separator_h2);
	create_separator( shared_from_this(),cityhall_settings_dlg::separator_v);
	
    m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_common_header );
	m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_budget );
    
	m_operation_label = m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_operation );

	milk::milk_button_ptr b_refill = 
    	m_factory.create_button( m_window_ctx, shared_from_this(), cityhall_settings_dlg::btn_refill );
	m_factory.create_label( m_window_ctx, b_refill, cityhall_settings_dlg::lbl_refill );
    {
      milk::milk_callback cb_add = std::tr1::bind(&city_cityhall_settings_dlg::on_refill_pressed, this);
      b_refill->set_action( cb_add );    }

	milk::milk_button_ptr b_coins = 
    	m_factory.create_button( m_window_ctx, shared_from_this(), cityhall_settings_dlg::btn_coins );
	m_factory.create_label( m_window_ctx, b_coins, cityhall_settings_dlg::lbl_coins );
    
    milk::milk_callback b_coins_cb = std::tr1::bind( &city_cityhall_settings_dlg::on_addcoins, this ); 
    b_coins->set_action( b_coins_cb );
    
    m_factory.create_image( m_window_ctx, shared_from_this(), cityhall_settings_dlg::image_budget );

	// Fiscal Agent
    {
    	
        m_fiscal_agent_cell = shared_from_this()->create_child<agent_control>( fiscal_rectangle );
        m_fiscal_agent_cell->layout_controls( m_window_ctx,
        	std::tr1::bind( &city_cityhall_settings_dlg::on_fiscal_agent_pressed, this ) );
    }

	// Municipality Officer
    {
        surf::surf_rect municipality_officer_rectangle( cityhall_settings_dlg::rct_municipality_officer.at(current_theme) );

        m_municipal_oficer_cell = 
            shared_from_this()->create_child<agent_control>( 
                municipality_officer_rectangle );
        
        m_municipal_oficer_cell->layout_controls(m_window_ctx,
        	std::tr1::bind( &city_cityhall_settings_dlg::on_municipal_officer_pressed, this ) );
    }
    
    refresh();
}

void city_cityhall_settings_dlg::refresh() {
	
    sqc_assert( m_delegate );
    if ( !m_delegate ) {
    	return;
    }

    sqc_assert( m_operation_label );
    if ( m_operation_label ) {
        sqc_string r_operation = framework().strings().load( 
        				cityhall_settings_dlg::res_operation.resource_id(), 
				        cityhall_settings_dlg::res_operation.def_value() );
                        
        std::string format_operation = format( r_operation, get_operation() );
        m_operation_label->set_caption( format_operation );
    }
    
    sqc_assert( m_fiscal_agent_cell );
    if ( m_fiscal_agent_cell ) {
    	city_hall_agent_info info;
        m_delegate->get_fiscal_agent( info );
	    cha_agent_ptr agent( new cha_agent( info ) );
        m_fiscal_agent_cell->refresh( agent );
	}    
    
    sqc_assert( m_municipal_oficer_cell );
    if ( m_municipal_oficer_cell ) {
    	city_hall_agent_info info;
        m_delegate->get_municipal_officer( info );
	    cha_agent_ptr agent( new cha_agent( info ) );

        m_municipal_oficer_cell->refresh( agent );
    }
    
}

void city_cityhall_settings_dlg::on_refill_pressed()
{
	sqc_assert( m_delegate );
    if ( !m_delegate ) {
    	return;
    }
    
    m_delegate->refill_budget();
}

void city_cityhall_settings_dlg::on_fiscal_agent_pressed() {
	sqc_assert( m_delegate );
    if ( !m_delegate ) {
    	return;
    }
    
    city_hall_agent_info info;
    m_delegate->get_fiscal_agent( info );
    
    if ( info.is_hired() ) {
    	m_delegate->fire_fiscal_agent();
    } else {
	    m_delegate->hire_fiscal_agent();	
    }

}

void city_cityhall_settings_dlg::on_municipal_officer_pressed() {
	sqc_assert( m_delegate );
    if ( !m_delegate ) {
    	return;
    }
    
    city_hall_agent_info info;
    m_delegate->get_municipal_officer( info );
    
    if ( info.is_hired() ) {
    	m_delegate->fire_municipal_officer();
    } else {
	    m_delegate->hire_municipal_officer();	
    }
}

bool city_cityhall_settings_dlg::get_dialog_init_arg( milk::milk_dialog_init_arg& a )
{
    sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 20, 40, 5 };
	a.bevel_bottom = height[theme_size];
    
	return sqc_dialog::get_dialog_init_arg( a );
    
}

int city_cityhall_settings_dlg::get_operation() 
{
	sqc_assert( m_delegate );
    if ( !m_delegate ) {
    	return 0;
    }
    sqc_common_scene_info scene_info;
    m_delegate->get_scene_info( scene_info );
	return scene_info.auto_operations;
}

void city_cityhall_settings_dlg::on_addcoins() {
	surf::surf_rect rect;
    sqc_add_money_params params;
	money_dlg_ptr dlg = framework().windows().get_desktop()->create_child<money_dlg>(rect, params);
	dlg->switch_megabucks();

} 

/***************************************************************************/
// Agent Control class implementation

void agent_control::layout_controls( sqc_window_factory_ctx_ptr window_ctx, milk::milk_callback button_callback )
{
	m_button_callback = button_callback;
    
	m_window_ctx = window_ctx;
	milk::milk_button_ptr b_pers = 
		m_factory.create_button( m_window_ctx, shared_from_this(), cityhall_settings_dlg::btn_pers_bg );

    // m_i_pers = m_factory.create_image( m_window_ctx, b_pers, cityhall_settings_dlg::img_pers_avatar );
    
    m_l_name = m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_pers_name );

    m_l_descr = m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_pers_descr );

	milk::milk_button_ptr b_action = 
    	m_factory.create_button( m_window_ctx, shared_from_this(), cityhall_settings_dlg::btn_pers_action );
        
    milk::milk_callback b_action_cb = std::tr1::bind( &agent_control::on_action, this ); 
    b_action->set_action( b_action_cb );

    m_l_action = m_factory.create_label( m_window_ctx, shared_from_this(), cityhall_settings_dlg::lbl_pers_action );
    
    
    
    m_avatar_widget = m_factory.create_child<sqc_proxy_texture_widget>( 
    									m_window_ctx,
                                         b_pers, 
                                         cityhall_settings_dlg::img_pers_avatar.rects(),
                                         cityhall_settings_dlg::img_pers_avatar.alignment() );
	
}

void agent_control::refresh( cha_agent_ptr options )
{
	sqc_assert( options );
    if ( !options ) {
    	return;
    }
    
	m_l_name->set_caption( options->get_name() );
	m_l_descr->set_caption( options->get_description() );
	m_l_action->set_caption( 
    	options->is_hire() ? framework().strings().load("*CityHallDismiss", "Dismiss") :
			framework().strings().load("*CityHallEmploy", "Employ")
    );
    
    if ( m_avatar_widget ) {
	    const city_hall_agent_info& info = options->get_info();
        if ( info.local_avatar ) {
        	m_avatar_widget->set_local_image( info.avatar );
        } else {
            bool consider_social_network = true;
	        m_avatar_widget->set_remote_texture( info.avatar, consider_social_network ); 
        }

    }
    //m_i_pers->set_image( m_window_ctx->create_image( options->get_picture() ) );
}

// event push button hire/dismiss
void agent_control::on_action() {
	if ( m_button_callback ) {
    	m_button_callback();
    }
}

END_NAMESPACE_SQC_FRAMEWORK
