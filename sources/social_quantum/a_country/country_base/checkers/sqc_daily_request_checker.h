#pragma once

#include "../message_queue/sqc_message_queue_base.h"
#include "../sqc_game_base.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_daily_request_checker : public sqc_checker_base
{
public:
	sqc_daily_request_checker(sqc_message_queue_base& message_queue
                              , sqc_country_base_ui_face& ui
                              , sqc::framework::sqc_game_ptr& game
                              , sqc_notify_center& notify_center
                              , const sqc_string in_name );
    
    virtual ~sqc_daily_request_checker(); 
    
	virtual void invoke(); 
    virtual void parse_xml(xml::xml_doc &in_xml);
    
protected:
    bool need_show();
    void show_dialog();
    void on_destroy();
    
    //-- notify centre subscribe
    void subscribe_events();
    void unsubscribe_events();
    void notify_callback( const sqc_provider_id& provider_id, 
                          const sqc_event_id& event_id); 
    //--
    
    // -- members   
    bool m_show_dialog;
    sqc_daily_gift_param m_param;
    
    sqc_notify_center& m_notify_center;
    sqc_listener_connection  m_notify_connection; 
    //--
};

END_NAMESPACE_SQC_FRAMEWORK
