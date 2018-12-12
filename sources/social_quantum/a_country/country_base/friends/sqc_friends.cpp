/*
 *  sqc_friends.cpp
 *  aCountry
 *
 *  Created by paul K on 10/3/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sqc_friends.h"
#include "country_base/sqc_framework_base.h"

using namespace std::tr1::placeholders;


NAMESPACE_SQC_FRAMEWORK


sqc_friends::sqc_friends( 
	sqc_notify_center& notify, 
    sqc_social_networks& networks,
    sqc_game_ptr& game ) 
        : m_notify_center( notify )
        , m_networks( networks )
        , m_game( game )
        , m_query_state( friend_state_pending )
        , m_social_network_friends_ready( false )
        , m_game_friends_ready( false ) {
	
    reset_cache();
}

sqc_friends::~sqc_friends() {
	unsubscribe_events();
}


bool sqc_friends::init() {
	subscribe_events();
	return true;
}

friend_query_state sqc_friends::friends_state() {
	sqc_info() << "friends: status is " << print_query_friend_status( m_query_state );
	return m_query_state;
}

void sqc_friends::get_friends( sqc_user_profile_list& list ) {

    sqc_info() << "friends: copy with status " << print_query_friend_status( m_query_state );
    
    // make copy
    for ( sqc_user_profile_list::const_iterator it = m_friends.begin();
    	it != m_friends.end(); ++it ) {
        list.push_back( sqc_user_profile_ptr( new sqc_user_profile( *it->get() ) ) );
    }
	
}

sqc_user_profile_ptr sqc_friends::find_friend( const sqc_string& user_id ) {

    sqc_info() << "friends: find_friend with status " << print_query_friend_status( m_query_state );
    
    // make copy
    for ( sqc_user_profile_list::const_iterator it = m_friends.begin();
    	it != m_friends.end(); ++it ) {
        
        if ( it->get()->get_user_id() == user_id ) {
        // make copy
        	return sqc_user_profile_ptr( new sqc_user_profile( *it->get() ) );
        }
    }
    
    return sqc_user_profile_ptr();
}

sqc_user_profile_ptr sqc_friends::find_friend( const sqc_dword&  user_id )
{
    std::stringstream _ss;
    _ss << user_id;
    return find_friend( _ss.str() );
}



// reset all
void sqc_friends::reset_cache() {

	sqc_info() << "friends: reset cache";
    
    m_friends.clear();
    
	m_query_state					= friend_state_pending;
    m_social_network_friends_ready	= false;
    m_game_friends_ready			= false;

}

// query friends from social networks (1-st stage)
void sqc_friends::query_social_network_friends() {

	m_query_state = friend_state_pending;
    
	bool res = m_networks.query_friends();
    
    if ( res ) {
    	sqc_info() << "friends: query social network friends (1-stage)";
    } else {
    	sqc_error() << "friends: unable to query social network friends (1-stage)";
        bool error = true;
        query_social_network_friends_complete( error );
    }
}

// query friends from social networks is complete (1-st stage)
void sqc_friends::query_social_network_friends_complete( bool error ) {

	PROFILE_ENTRY_CRITICAL( "sqc_friends::query_social_network_friends_complete" );

    if ( error ) {
        sqc_error() << "friends: unable to complete query social network friends (1-stage)";
        reset_cache();
        m_query_state = friend_state_error;
        
        m_notify_center.fire_event( friends, friends_event_query_error, call_async );
        
        return;
    }
    
    sqc_info() << "friends: query social network friends complete (1-stage)";
	
	m_social_network_friends_ready = true;
    m_networks.get_friends( m_friends );
    
    sqc_info() << "friends: social network friends count:" << m_friends.size();

    analyze_friends_ready();
    
}

// game friends ready (2-st stage)
void sqc_friends::game_friends_complete() {

    if ( m_game_friends_ready ) {
	    sqc_info() << "friends: skip game friends complete duplicate message";
    	return;
    }
    
    sqc_info() << "friends: game friends complete (2-stage)";
    m_game_friends_ready = true;
    
    analyze_friends_ready();
}

// analyze 1-st and 2-nd stage
void sqc_friends::analyze_friends_ready() {

	bool all_ready = ( m_social_network_friends_ready && m_game_friends_ready );
    if ( !all_ready ) {
	    sqc_info() << "friends: not all stages ready";
    	return;
    } 
    
    // merge!!!
    merge_friends_properties();
    
    m_query_state = friend_state_success;
    sqc_info() << "friends: all stages ready. fire ready event";
    
    m_notify_center.fire_event( friends, friends_event_query_complete, call_async );
}


// merge properties
void sqc_friends::merge_friends_properties() {

	PROFILE_ENTRY_CRITICAL( "sqc_friends::query_social_network_friends_complete" );

	sqc_assert( m_social_network_friends_ready && m_game_friends_ready );

    // update level and ingame property
    if ( !m_game ) {
    	// нонсенс. блин
    	sqc_assert( false );
        return;
    }
    
    sqc_game_friend::vector game_friends;
    typedef std::map<sqc_string,sqc_game_friend::sptr>	game_friend_map_t;
    game_friend_map_t	game_friend_map;
    
    // create map by string id
    {
        m_game->get_game_friends( game_friends );
        sqc_info() << "friends: game friends count:" << game_friends.size();
        sqc_info() << "friends: social network friends count:" << m_friends.size();
    
        for ( sqc_game_friend::vector::const_iterator it = game_friends.begin();
        	it != game_friends.end(); ++it ){
            game_friend_map[it->get()->id()] = *it;
        }
    }

	int update_count = 0;    
    
    // update some properties from game_friends
    for ( sqc_user_profile_list::iterator it = m_friends.begin();
    		it != m_friends.end(); ++it ) {
        
        sqc_user_profile_ptr ptr_user = *it;
        //sqc_user_profile& p = *ptr_user;
        
        game_friend_map_t::const_iterator it_game_friend = 
        					game_friend_map.find( ptr_user->get_user_id() );
                            
        if ( it_game_friend == game_friend_map.end() ) {
        	continue;
        }
        
    	ptr_user->set_in_game( true );
		ptr_user->set_have_gift( it_game_friend->second->have_gift() );
		ptr_user->set_level( it_game_friend->second->level() );
        update_count++;
    }
    
    sqc_info() << "friends: merged friends count:" << update_count;
    
    if ( update_count != game_friends.size() ) {
    	sqc_error() << "friends: merge friends error";
    }
}


// subscribe for events
void sqc_friends::subscribe_events() {
    m_notify_connection = m_notify_center.subscribe( 
            std::tr1::bind( &sqc_friends::notify_callback, this, _1, _2 ) );
}

// unsubscribe for events
void sqc_friends::unsubscribe_events() {
    m_notify_center.unsubscribe( m_notify_connection );
}

// notification callback
void sqc_friends::notify_callback( 
	const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    if ( social_networks == provider_id ) {
        if ( network_event_loggin_complete == event_id ) {
            
            reset_cache();
            // query friends from social networks (1-st stage)
            query_social_network_friends();
             
        } else if ( network_event_query_friends_complete == event_id ) {

        	bool error = false;
            // query friends from social networks is complete (1-st stage)
        	query_social_network_friends_complete( error );
            
        } else if ( network_event_query_friends_error == event_id ) {
        
        	bool error = true;
            // query friends from social networks is complete (1-st stage) with error
        	query_social_network_friends_complete( error );
        }
    } else if ( country_provider_id == provider_id ) {
    	if ( event_id == country_field_changed_event ) {
	        // game friends ready (2-st stage)
			game_friends_complete();        
        } 
    }
}

END_NAMESPACE_SQC_FRAMEWORK
