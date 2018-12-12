#pragma once

#include "../sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

// provider and event id
typedef sqc_string sqc_provider_id;
typedef sqc_string sqc_event_id;
typedef int        sqc_event_value;

typedef std::tr1::function<void(const sqc_provider_id& provider_id, const sqc_event_id& event_id, const sqc_event_value value)> sqc_notification_callback;
typedef std::list<sqc_notification_callback>    sqc_listener_list;
typedef sqc_listener_list::iterator             sqc_listener_connection;

//
// sqc_social_networks implementation
//
class sqc_notify_center {
public:
	sqc_notify_center();
    virtual ~sqc_notify_center();

    /*
     * subscribe listener
     */
    sqc_listener_connection subscribe( sqc_notification_callback cb );
    
    /*
     * unsubscribe listener
     */
    void unsubscribe( sqc_listener_connection conn );
    
    /*
     * fire event
     */
    virtual void fire_event( const sqc_provider_id& provider_id,  
    						const sqc_event_id& event_id,
                            const sqc_call_type call_type,
                            const sqc_event_value value = 0 );
                            
protected:
	void async_fire_event( sqc_provider_id provider_id, sqc_event_id event_id, sqc_event_value value );
private:    
    sqc_listener_list   m_listeners;
};

//
// traverser
//

typedef std::tr1::function<void()>  sqc_callback;
typedef std::list<sqc_callback> sqc_callback_list;

class sqc_traverser {
public:
	sqc_traverser();
    virtual ~sqc_traverser();
    
    /*
     * schedule callback to be called in the main thread
     */
    void    schedule( sqc_callback cb );
    
    /*
     * process timer - execute scheduled functions
     */
    void    handle_timer();
private:
    sqc_callback_list   m_queue;
    sstl::sstl_mutex    m_access;
};
	
END_NAMESPACE_SQC_FRAMEWORK
