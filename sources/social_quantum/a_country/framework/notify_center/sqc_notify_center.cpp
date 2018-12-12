/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_notify_center.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

sqc_notify_center::sqc_notify_center() {
}
sqc_notify_center::~sqc_notify_center() {
}

/*
 * subscribe listener
 */
sqc_listener_connection sqc_notify_center::subscribe( sqc_notification_callback cb ) {
    return m_listeners.insert( m_listeners.end(), cb );
}

/*
 * unsubscribe listener
 */
void sqc_notify_center::unsubscribe( sqc_listener_connection conn ) {
    m_listeners.erase( conn );
}

/*
 * fire event
 */
void sqc_notify_center::fire_event(
	const sqc_provider_id& provider_id, 
	const sqc_event_id& event_id,
    const sqc_call_type call_type,
    const sqc_event_value value ) {
    
    sqc_info() 
    	<< "notify_center: " << provider_id << " fire " << print_sqc_call_type( call_type ) << " " << event_id << " value: " << value << " ->";

	if ( call_async == call_type ) {
		sqc_traverser& traverser = framework().traverser();
        traverser.schedule( std::tr1::bind( 
            &sqc_notify_center::async_fire_event, this, provider_id, event_id, value ) );
        return;
    }


    sqc_listener_list local( m_listeners ); // to prevent iterator corruprion in case of unregister listener on notify event
    for( sqc_listener_list::const_iterator i = local.begin(); i != local.end(); ++i ) {
        (*i)( provider_id, event_id, value );
    }
    
    sqc_info() 
 	   << "notify_center: " << provider_id << " sync leave " << event_id << " value: " << value << " <-";
    
}


void sqc_notify_center::async_fire_event( sqc_provider_id provider_id, sqc_event_id event_id, sqc_event_value value ) {
   
    sqc_listener_list local( m_listeners ); // to prevent iterator corruprion in case of unregister listener on notify event
    for( sqc_listener_list::const_iterator i = local.begin(); i != local.end(); ++i ) {
        (*i)( provider_id, event_id, value );
    }
       
    sqc_info() 
 	   << "notify_center: " << provider_id << " async leave " << event_id << " value: " << value << " <-";
}

END_NAMESPACE_SQC_FRAMEWORK

//
// traverser
//

NAMESPACE_SQC_FRAMEWORK

sqc_traverser::sqc_traverser() {
}

sqc_traverser::~sqc_traverser() {
}

/*
 * schedule callback to be called in the main thread
 */
void sqc_traverser::schedule( sqc_callback cb ) {
    sstl::sstl_mutex_lock   lock( m_access );
    m_queue.push_back( cb );
}

/*
 * process timer - execute scheduled functions
 */
void sqc_traverser::handle_timer() {
    
    PROFILE_ENTRY( "sqc_traverser::handle_timer" );
    
    sqc_callback_list   current_queue;
    {
        sstl::sstl_mutex_lock   lock( m_access );
        current_queue.swap( m_queue );
    }
    
    for( sqc_callback_list::const_iterator i = current_queue.begin(); i != current_queue.end(); ++i ) {
        (*i)();
    }
}


END_NAMESPACE_SQC_FRAMEWORK