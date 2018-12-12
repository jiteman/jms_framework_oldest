/*
 *  sqc_select_network_dlg.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_select_network_dlg.h"
#include "framework/sqc_framework.h"
using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// sqc_select_network_dlg implementation
//

sqc_select_network_dlg::sqc_select_network_dlg(
    milk::milk_widget_ptr p,
    const dialog_layout& dialog_layout,
    const sqc_select_network_params params ) 
    : sqc_dialog( p, dialog_layout, 
        ( params.user_can_close_dialog ? 
                    dialog_has_close_button : 0 ) )
    , m_params( params )
    , m_visible_count(3) {
}

sqc_select_network_dlg::~sqc_select_network_dlg() {
}


// initialization 
void sqc_select_network_dlg::on_init_dialog() {
	sqc_dialog::on_init_dialog();
	set_bevel_type( milk::milk_bevel_type_content );
	
    // store available networks
    {
        sqc_social_networks& networks = framework().networks();
        
        network_list list;
        networks.get_available_networks( list );
        
        for ( network_list::const_iterator it = list.begin();
             it != list.end(); ++it ) {
            m_available_networks.push_back( *it );
        }
    }
    
    m_visible_count = get_visible_count();
}

bool sqc_select_network_dlg::on_end_dialog() {
	if ( !m_params.user_can_close_dialog ) {
    	return false;
    }
    return sqc_dialog::on_end_dialog();
}


// milk_spinboard_callbacks interface
milk::milk_widget_ptr sqc_select_network_dlg::create_cell(
    int idx, surf::surf_rect const &rect_cell ) {

    if ( idx >= m_available_networks.size() ||
        idx < 0 ) {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    const sqc_network_type network_type = m_available_networks[idx];
    
    milk::milk_callback action = 
    std::tr1::bind( &sqc_select_network_dlg::on_network_pressed, this, network_type );
    
    return  on_create_cell( network_type, rect_cell, action,idx);
}

sqc_dword sqc_select_network_dlg::get_visible_count()
{
    sqc_window_factory& factory = framework().windows_factory();
    return ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 ;
}

int sqc_select_network_dlg::get_cell_count() {
    return m_available_networks.size();
}

// user press change network button
void sqc_select_network_dlg::on_network_pressed( 
    const sqc_network_type network_type ) {

    sqc_info() 
    	<< "select_network_dlg: connecting to new network...";

	if ( m_params.callback ) {
	    m_params.callback( network_type );
    }
}

END_NAMESPACE_SQC_FRAMEWORK