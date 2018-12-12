/*
 *  city_common_friends_controller.cpp
 *  aCountry
 *  Controller for dialog Friends Panel
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city_common_friends_controller.h"
#include "city/city_framework.h"
#include "city/dialogs/city_select_person/city_select_person_dlg.h"

#include "animation/animation_transformer.h"
#include "animation/animation_server.h"
#include "animation/animation_animators.h"


NAMESPACE_SQC_FRAMEWORK

city_common_person_controller::city_common_person_controller( milk::milk_widget_ptr p, sqc_window_factory_ctx_ptr window_ctx )
	: m_parent(p)
    , m_window_ctx(window_ctx)
{
    m_dialog = m_parent->create_child<city_friends_panel_dlg>( surf::surf_rect(), this, m_window_ctx );
    sqc_assert(m_dialog);
}

// begin
void city_common_person_controller::instance_view()
{

    sqc_assert(m_parent);

	// Do not call notification until the window context is not initialized (especially View)
    m_notify_connection = framework().notify_center().subscribe( 
		std::tr1::bind( &city_common_person_controller::notify_callback, 
            this, 
            std::tr1::placeholders::_1, 
            std::tr1::placeholders::_2 ) 
    );

    sqc_user_profile_ptr profile = framework().networks().get_user_profile();

    if (profile) {
		m_dialog->current_avatar = profile->get_avatar_url();
		m_dialog->current_name = profile->get_first_name();
	}
	else {
		sqc_error() << " user profile is null";
    }
    
    m_dialog->layout_controls();
}



void city_common_person_controller::hide()
{
	//m_dialog->layout_controls_collapse();
}

void city_common_person_controller::show()
{
}

bool city_common_person_controller::is_show()
{	
	return true;
}

void city_common_person_controller::notify_callback(
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id )
{
    
    if ( social_networks == provider_id ) {
		// declare_notification_event_id( network_event_invite_friend_complete )
        // event occurs when invite has success
        if (network_event_invite_friend_complete == event_id ) {
        	on_invite_success();
		}
        // declare_notification_event_id( network_event_invite_friend_error )
        else if (network_event_invite_friend_error == event_id ) {
        	on_invite_error();
		}
	} else if ( friends == provider_id ) {
    
        if ( friends_event_query_complete == event_id ) {
			// change image for current network
            fill();
        }
        else if ( friends_event_query_error == event_id ) {
        	on_query_friends_error();
        }
    } else if (processor::command_processor_provider_id == provider_id) {
    	if (processor::command_processor_initial_xml_complete_event == event_id) {
            on_change_current_user();
        }
    }
    
}

void city_common_person_controller::make_friends_list(sqc_user_profile_list &list) 
{
/*
    m_dialog->friends_list().clear();
    for (sqc_user_profile_list::iterator it=list.begin(); it != list.end(); ++it)
    {
        m_dialog->friends_list().push_back(
			person_info(
                (*it)->get_user_id(),
                (*it)->get_first_name(),
                (*it)->get_level(),
                (*it)->get_avatar_url()
            )
        );
    }
*/
}

void city_common_person_controller::fill()
{
    sqc_info() << "query friends list complete";
    
    sqc_user_profile_list list;
    country_framework().friends().get_friends( list );

    m_view_friends_list.clear();
    for (sqc_user_profile_list::iterator it=list.begin(); it != list.end(); ++it)
    {
        m_view_friends_list.push_back(
			person_info(
                (*it)->get_user_id(),
                (*it)->get_first_name(),
                (*it)->get_level(),
                (*it)->get_avatar_url()
            )
        );
    }

	m_dialog->layout_controls();

/*
    if (! m_dialog->layouted())
    {
    	m_dialog->layout_controls(m_window_ctx);
	    framework().notify_center().fire_event( friends_panel_provider_id, friends_panel_show_event, call_sync );
    }
*/
}

void show_dialog() 
{
}

void city_common_person_controller::on_change_current_user()
{
	if (m_dialog)
    {
		if (m_game) {
            sqc_string owner = m_game->get_owner();
            sqc_user_profile_ptr profile = country_framework().friends().find_friend(owner);
            if (profile) {
                m_dialog->current_avatar =  profile->get_avatar_url();
                m_dialog->current_name = profile->get_first_name();
            }
            else {
            
                sqc_user_profile_ptr profile = framework().networks().get_user_profile();
                if ( profile ) {
                    if ( owner == profile->get_user_id() ) {
                        m_dialog->current_avatar =  profile->get_avatar_url();
                        m_dialog->current_name = profile->get_first_name();
                    } else {
	                    sqc_error() << "city_common_person_controller::on_change_current_user error: unknown user: " << owner;
                    }
                } else {
                    sqc_error() << "city_common_person_controller::on_change_current_user error: no current user";
                }
            
            }
        }
        m_dialog->set_current_user();
    }
}

void city_common_person_controller::on_query_friends_error()
{
	sqc_error() << "query friends list error";
}

void city_common_person_controller::on_change_user(sqc_string uid)
{
    tools::sqc_activate_tool_arg arg = {};

	// reset tool_type_visit_field to tool_type_multi
	// TODO: solve problem with sqc_tools_controlles
    {
        sqc_assert(m_ptr_scene_view && "not initialized m_ptr_scene_view");
	    tools::sqc_tools_controlles &controller = city::city_framework().tools();
	    tools::sqc_tool_type active_tool = controller.get_active_tool();

		if ( tools::tool_type_visit_field == active_tool )
        {

			// activate default tool
			tools::sqc_activate_tool_arg arg = {};

            controller.activate_tool( tools::tool_type_multi, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
        }
	}

	arg.user_id = uid;
	tools::sqc_tools_controlles &controller = city::city_framework().tools();
	controller.activate_tool( tools::tool_type_visit_field, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void city_common_person_controller::on_add_friend() {
	city_dialogs& dialogs = city::city_framework().dialogs();
    
	if ( !framework().networks().can_invite_friends() ) {
        sqc_message_box_params params;
        params.dlg_title	= 
			framework().strings().load( res_invite_add_friend_title.resource_id(), res_invite_add_friend_title.def_value() );
        
        params.dlg_text		= 
        	framework().strings().load( res_invite_nopossible_msg.resource_id(), res_invite_nopossible_msg.def_value() );
        
        params.button_text	= 
    		framework().strings().load( res_ok_caption.resource_id(), res_ok_caption.def_value() );

        milk::milk_dialog_ptr message_box = dialogs.show_message_box( params );
        /*
        if ( !message_box ) {
        	sqc_error() << "unable to create message box";
        	return;
        }
		*/
        
        //message_box->set_close_action( 
		//	std::tr1::bind( &sqc_backend_connection::on_message_box_close, this, type ) );
    }
    else
    {
        /*
		person_select_callback cb =
			std::tr1::bind( &city_common_person_controller::on_select_invite,
                			this, std::tr1::placeholders::_1);

        city_select_person_controller m_select_person_controller;
        m_select_person_controller.show_friends(cb);
        */
    }
}

bool city_common_person_controller::on_select_invite(sqc_string uid) {
	sqc_info() << " invite user " << uid;
	framework().networks().invite_friend( uid, 
    	framework().strings().load( res_invite_message.resource_id(), res_invite_message.def_value() )
    );
    return true;
}

void city_common_person_controller::on_invite_error() {
	city_dialogs& dialogs = city::city_framework().dialogs();
    
    sqc_message_box_params params;
    params.dlg_title	= 
    	framework().strings().load( res_invite_failed_title.resource_id(), res_invite_failed_title.def_value() );
    params.dlg_text		= 
    	framework().strings().load( res_invite_failed_title.resource_id(), res_invite_failed_title.def_value() );

    params.button_text	= 
    	framework().strings().load( res_ok_caption.resource_id(), res_ok_caption.def_value() );
	
    dialogs.show_message_box( params );
}

void city_common_person_controller::on_invite_success() {
	city_dialogs& dialogs = city::city_framework().dialogs();

    sqc_message_box_params params;

    params.dlg_title	= 
    	framework().strings().load( res_invite_success_title.resource_id(), res_invite_success_title.def_value() );
    params.dlg_text		= 
    	framework().strings().load( res_invite_success_title.resource_id(), res_invite_success_title.def_value() );

    params.button_text	= 
    	framework().strings().load( res_ok_caption.resource_id(), res_ok_caption.def_value() );
	
    dialogs.show_message_box( params );
}

void city_common_person_controller::on_hide()
{
    m_dialog->set_view_mode(VM_COLLAPSE);
    m_dialog->layout_controls();
    framework().notify_center().fire_event( friends_panel_provider_id, friends_panel_hide_event, call_sync );

        //m_dialog->layout_controls();
/*
    using namespace sqc::animation;

    framework().windows().animation().add_animator( m_dialog->transform(), 
		animation_animator_translate( surf::surf_point(0, m_dialog->get_rect().y),
    	surf::surf_point(0, -m_dialog->get_rect().size().cy), 
    	1.0 ) );
*/

}


void city_common_person_controller::on_show()
{
	m_dialog->set_view_mode(VM_EXPAND);
    framework().notify_center().fire_event( friends_panel_provider_id, friends_panel_show_event, call_sync );
    m_dialog->layout_controls();
    
}

END_NAMESPACE_SQC_FRAMEWORK
