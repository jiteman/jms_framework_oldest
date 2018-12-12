#pragma once

#include "../message_queue/sqc_message_queue_base.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_update_message_checker : public sqc_checker_base
{
public:
	sqc_update_message_checker( sqc_message_queue_base& message_queue
                     , sqc_country_base_ui_face& ui
                     , sqc_game_ptr game
                     , sqc_notify_center& notify_center
                     , const sqc_string in_name );
    
	virtual void invoke();
    
    virtual ~sqc_update_message_checker();
    
protected:
    bool need_show();
    void show_dialog();
    
    bool m_showed;

    sqc_game_ptr m_game;
    
protected:

    //-- notify centre subscribe
    void subscribe_events();
    void unsubscribe_events();
    void notify_callback( const sqc_provider_id& provider_id, 
                          const sqc_event_id& event_id); 
    //--
    
    sqc_notify_center&       m_notify_center;
    sqc_listener_connection  m_notify_connection; 
};

END_NAMESPACE_SQC_FRAMEWORK
