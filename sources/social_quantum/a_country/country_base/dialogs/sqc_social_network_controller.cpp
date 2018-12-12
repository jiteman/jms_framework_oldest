/*
 *  sqc_social_network_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 10/11/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sqc_social_network_controller.h"
#include "country_base/sqc_framework_base.h"


using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


sqc_social_network_controller::sqc_social_network_controller() {

    // subscribe for events
    m_notify_connection = framework().notify_center().subscribe( 
    std::tr1::bind( &sqc_social_network_controller::notify_callback, this, _1, _2 ) );
}

sqc_social_network_controller::~sqc_social_network_controller() {

    // unsubscribe
    framework().notify_center().unsubscribe( m_notify_connection );
}

// notification callback
void sqc_social_network_controller::notify_callback(
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {

    if ( backend_connection_provider_id == provider_id ) {
        if ( backend_login_to_social_network_complete_event == event_id ) {
			sqc_info() << "sqc_social_network_controller: received login_to_social_network_complete signal";            
            
            if ( m_login_success_callback ) {
            	m_login_success_callback();
            }
        }
    }
}

// network properties
sqc_network_type sqc_social_network_controller::current_network() {

    return framework().networks().current_network();
}

sqc_string sqc_social_network_controller::get_network_image( 
	sqc_network_type network ) {
    
    return framework().networks().get_network_image( network );
}

// store callbacks
void sqc_social_network_controller::set_success_login_callback( 
	login_success_callback cb ) {
    
    m_login_success_callback = cb;
}

// try to login to network
bool sqc_social_network_controller::change_network() {

	sqc_info() << "sqc_social_network_controller: change_network";            
    country_framework().backend_connection().connect_to_social_network();
    
    return true;
}


END_NAMESPACE_SQC_FRAMEWORK