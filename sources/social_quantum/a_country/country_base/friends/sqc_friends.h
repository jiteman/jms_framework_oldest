#pragma once

#include "../../framework/sqc_framework.h"
#include "../../framework/notify_center/sqc_notify_center.h"
#include "../sqc_game_base.h"
#include "../../framework/social_network/sqc_social_network.h"

NAMESPACE_SQC_FRAMEWORK

enum friend_query_state {
    friend_state_success,
    friend_state_error,
    friend_state_pending,
};

inline sqc_string 
print_query_friend_status( friend_query_state state ) {
    if ( friend_state_success == state )		return "success";
    else if ( friend_state_error == state )		return "error";
    else if ( friend_state_pending == state ) 	return "pending";
    else {
    	return "unkn state";
    }
}

class sqc_friends {
public:

	sqc_friends( sqc_notify_center& notify, 
    			 sqc_social_networks& networks, 
                 sqc_game_ptr& game );
    virtual ~sqc_friends();
    bool	init();

	// in case of status is friend_state_pending - wait for 
    //	"friends_event_query_complete" or "friends_event_query_error message"
    //	otherwise call get_friends or find_friend at once
	friend_query_state		friends_state();
    
    void					get_friends( sqc_user_profile_list& list );
    sqc_user_profile_ptr	find_friend( const sqc_string& user_id );
    sqc_user_profile_ptr	find_friend( const sqc_dword&  user_id );
protected:

    // subscribe for events
    void					subscribe_events();
    // unsubscribe for events
    void					unsubscribe_events();
    // notification callback
    void					notify_callback( const sqc_provider_id& provider_id, 
                         			const sqc_event_id& event_id);    

	sqc_listener_connection     m_notify_connection;
    
protected:
	// reset all
	void						reset_cache();
    // query friends from social networks (1-st stage)
    void						query_social_network_friends();
    // query friends from social networks is complete (1-st stage)
    void						query_social_network_friends_complete( bool error );
    
    // game friends ready (2-st stage)
    void						game_friends_complete();
    
    // analyze 1-st and 2-nd stage
    void						analyze_friends_ready();
    
private:
	// merge properties
    void						merge_friends_properties();
private:

	//mutable sstl::sstl_mutex	m_access;
    
    // 1-st stage is ready
    bool						m_social_network_friends_ready;
    // 2-nd stage is ready
    bool						m_game_friends_ready;
    
    friend_query_state			m_query_state;
	sqc_user_profile_list		m_friends;
    
    sqc_notify_center&			m_notify_center;
    sqc_social_networks&		m_networks;
    sqc_game_ptr&               m_game;
};

// provider events id
declare_notification_provider_id( friends )

// notification events id
declare_notification_event_id( friends_event_query_complete )
declare_notification_event_id( friends_event_query_error )

END_NAMESPACE_SQC_FRAMEWORK
