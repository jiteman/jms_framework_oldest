/*
 *  city_select_person_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 9/19/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sqc_select_person_controller.h"
#include "country_base/sqc_framework_base.h"
#include "utils/crc32utils.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


sqc_select_person_controller::sqc_select_person_controller() {
    // subscribe for events
    m_notify_connection = framework().notify_center().subscribe( 
    std::tr1::bind( &sqc_select_person_controller::notify_callback, this, _1, _2 ) );

}

sqc_select_person_controller::~sqc_select_person_controller() {
	// unsubscribe
    framework().notify_center().unsubscribe( m_notify_connection );
}

// notification callback
void sqc_select_person_controller::notify_callback(
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {

    if ( friends == provider_id ) {
        if ( friends_event_query_complete == event_id ) {
            sqc_info() << "select_person_controller: received friends is ready signal";
            on_query_friends_complete();
        }
    }
}

void sqc_select_person_controller::set_persons_ready_callback( 
    persons_ready_callback cb ) {
    
    m_ready_callback = cb;
    
    friend_query_state state = country_framework().friends().friends_state();
    if ( state != friend_state_pending ) {
        sqc_info() << "select_person_controller: friends is ready on init";
        on_query_friends_complete();
    } else {
        sqc_info() << "select_person_controller: friends is not ready";
    }
}

void sqc_select_person_controller::get_persons( 
    sqc_person_info_list_type& persons ) {
    
    sqc_user_profile_list list;
    country_framework().friends().get_friends( list );
    sqc_info() << "select_person_controller: take " << list.size() << " friends";
    
    
    // add friends 
	for ( sqc_user_profile_list::const_iterator it = list.begin(); 
        it != list.end(); ++it ) {
        
        sqc_user_profile_ptr ptr_user = *it;
        
        bool local_avatar = false;
        sqc_person_info info( ptr_user->get_user_id(),
                         		ptr_user->get_first_name(),
				         		ptr_user->get_avatar_url(),
            			 		ptr_user->get_level(),
                                local_avatar );
                         
        persons.push_back( info );
    }
    
}

void sqc_select_person_controller::on_query_friends_complete() {
    if ( m_ready_callback ) {
        m_ready_callback();
    }
}


sqc_string get_avatar_texture_name( const sqc_string& avatar ) {
    sqc_string prefix = print_social_network( framework().networks().current_network() );
    
    std::stringstream out;
    out  << prefix
        << "_"
        << crc32utils::crc32( avatar.c_str(), avatar.size() );
        
    return out.str();
}


//
//  controller for send_gift
//
bool sqc_send_gift_to_friend_controller::on_person_select( 
	const sqc_string& id ) {
    
    if ( m_callback ) {
    	return m_callback( id );
    }
    return false;
}

sqc_string sqc_send_gift_to_friend_controller::get_button_caption() {
	return framework().strings().load(common_resources::string_text_gift.resource_id(),
                                      common_resources::string_text_gift.def_value() );
}
    
void sqc_send_gift_to_friend_controller::set_select_person_callback( 
	select_person_callback cb ) {
    m_callback = cb;
}




END_NAMESPACE_SQC_FRAMEWORK