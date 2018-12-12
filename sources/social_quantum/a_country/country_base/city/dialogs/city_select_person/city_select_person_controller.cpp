/*
 *  city_select_person_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 9/19/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "city_select_person_controller.h"
#include "city/city_framework.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


//
//  controller for visit friends field
//
bool city_visit_friend_field_controller::on_person_select( 
    const sqc_string& id ) {
    
    sqc_scene_view_ptr ptr_scene_view = sqc::city::city_framework().scene_view();
    if ( !ptr_scene_view ) {
        sqc_assert( false );
        return false;
    }

    tools::sqc_tools_controlles &controller = sqc::city::city_framework().tools();
    tools::sqc_tool_type active_tool = controller.get_active_tool();

	// reset tool_type_visit_field to tool_type_multi
    
	// TODO: solve problem with sqc_tools_controlles
    {
        
        if ( tools::tool_type_visit_field == active_tool ) {
            
            
            // activate default tool
            tools::sqc_activate_tool_arg    arg = {};
            controller.activate_tool( tools::tool_type_multi, 
                            arg, ptr_scene_view->get_tool_context(), 
                            *ptr_scene_view.get() );
        }

    }    
    
    tools::sqc_activate_tool_arg    arg = {};
    arg.user_id = id;
    controller.activate_tool( tools::tool_type_visit_field,
                              arg, 
                              ptr_scene_view->get_tool_context(), 
                              *ptr_scene_view.get() );
    
    return true;
}

sqc_string city_visit_friend_field_controller::get_button_caption() {
    return framework().strings().load( "*CommonFriendsVisit", "Visit" );
};


//
//  controller for invite friend
//
bool city_invite_friend_controller::on_person_select( const sqc_string& id ) {

    return true;
}

bool city_invite_friend_controller::can_invite_friend() {
    return framework().networks().can_invite_friends();
}

bool city_invite_friend_controller::invite_friend( 
    const sqc_string& id,
    const sqc_string& msg,
    invite_complete_callback cb,
    invite_error_callback cb_err ) {
    
    m_complete_cb   = cb;
    m_error_cb      = cb_err;
    
    return framework().networks().invite_friend( id, msg );
}

// notification callback
void city_invite_friend_controller::notify_callback(
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    if ( social_networks == provider_id ) {
    
        if ( network_event_invite_friend_complete == event_id ) {
            if ( m_complete_cb ) {
                m_complete_cb();
            }
        } 
        else if ( network_event_invite_friend_error == event_id ) {
            if ( m_error_cb ) {
                m_error_cb();
            }
        }
    }
}

sqc_string city_invite_friend_controller::get_button_caption() {
    return framework().strings().load( "*CommonFriendsInvite", "Invite" );
}

//
//  controller for municipality officer
//
bool city_municipality_officer_controller::on_person_select( const sqc_string& id ) {

    return true;
}

sqc_string city_municipality_officer_controller::get_button_caption() {
    return "???";
}


//
//  controller for fiscal agent
//
bool city_fiscal_agent_controller::on_person_select( const sqc_string& id ) {

    return true;
}

sqc_string city_fiscal_agent_controller::get_button_caption() {
    return "???";
}

END_NAMESPACE_SQC_FRAMEWORK