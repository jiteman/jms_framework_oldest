/*
 *  city_common_friends_controller.h
 *  aCountry
 *
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *	TODO: rename class to concrete name, remove class files to dialogs (?)
 */

#ifndef __CITY_COMMON_FRIENDS_CONTROLLER_H_INCLUDED__
#define __CITY_COMMON_FRIENDS_CONTROLLER_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "framework/notify_center/sqc_notify_center.h"

#include "city_friends_panel_dlg.h"
#include "city_friends_panel_dlg_delegate.h"

#include "city/view/city_scene_view.h"
#include "country_base/sqc_game_base.h"

NAMESPACE_SQC_FRAMEWORK


class city_common_person_controller : public sqc_noncopyable, public city_friends_panel_dlg_delegate {
public:

	city_common_person_controller(milk::milk_widget_ptr p, sqc_window_factory_ctx_ptr window_ctx);
    
    void instance_view();
	
    /// Method fills View the friends list
    void make_friends_list(sqc_user_profile_list &list);
    
    void hide();
    void show();
    bool is_show();

	void on_change_user(sqc_string uid);

	void on_add_friend();
    void on_invite_error();
    void on_invite_success();
    void on_change_current_user();
    void on_hide();
    
    void on_show();

    void set_scene_view(sqc_scene_view_ptr scene_view) {
    	m_ptr_scene_view = scene_view;
    }

    void set_game_info(sqc_game_ptr game_info) {
    	m_game = game_info;
    }
    
    void set_window_ctx(sqc_window_factory_ctx_ptr window_ctx) {
		m_window_ctx = window_ctx;
    }
    
    /// method is needed in case of default constructor
    void set_parent(milk::milk_widget_ptr p) {
    	m_parent = p;
    }

    person_info_list_type & get_friend_list() {
    	return m_view_friends_list;
    }
    
private:
    
    /// notification callback
    void notify_callback( const sqc_provider_id& provider_id, const sqc_event_id& event_id );
    bool on_select_invite(sqc_string uid);

    void on_query_friends_complete();
    void fill();
    void on_query_friends_error();
    
	milk::milk_widget_ptr m_parent;
	city_friends_panel_dlg_ptr m_dialog;
	sqc_listener_connection m_notify_connection;
	sqc_window_factory_ctx_ptr m_window_ctx;
	sqc_scene_view_ptr m_ptr_scene_view;
    sqc_game_ptr m_game;
    person_info_list_type m_view_friends_list;
};


typedef std::tr1::shared_ptr<city_common_person_controller> city_common_person_controller_ptr;

declare_notification_provider_id( friends_panel_provider_id )

declare_notification_event_id( friends_panel_show_event )
declare_notification_event_id( friends_panel_hide_event )

static const layout_string_resource res_ok_caption( "*CityOKButton", "OK" ); 

static const layout_string_resource res_invite_success_title( "*CityInviteTitle", "" ); 
static const layout_string_resource res_invite_success_msg( "*CityInviteSuccess", "User was successfully invited" ); 

static const layout_string_resource res_invite_failed_title( "*CityInviteTitle", "" ); 
static const layout_string_resource res_invite_failed_msg( "*CityInviteFailed", "I can not invite user" ); 

static const layout_string_resource res_invite_nopossible_msg( "*CityInviteNewFriends", "Login into social network and add new friends" ); 
static const layout_string_resource res_invite_add_friend_title( "*CityAddNewFriend", "Add friend" ); 

static const layout_string_resource res_invite_message( "*CityInviteFriendMessage", "I play Megapolis! Join me?" ); 

END_NAMESPACE_SQC_FRAMEWORK

#endif
