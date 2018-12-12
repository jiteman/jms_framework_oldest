#pragma once

#include "../../framework/sqc_framework_defs.h"
#include "sqc_checker_base.h"
#include "../../framework/notify_center/sqc_notify_center.h"

NAMESPACE_SQC_FRAMEWORK
//
//  States analyzer
//

class sqc_message_queue_base
{
public:
        
    typedef milk::milk_dialog_ptr	queue_item;
    
    void add_messsage_back( queue_item item );
    void add_messsage_front( queue_item item ); 
    
    sqc_message_queue_base(sqc_notify_center& notify_center,
                           sqc_game_ptr game,
                           sqc_country_base_ui_face& ui);
    virtual ~sqc_message_queue_base();
    
    void handle_timer();
    
    /*
     * @brief Some checkers invokes when specific xml received
     *
    */
    void on_xml_received(xml::xml_doc &in_xml);
    
    sqc_ddword        m_last_time;        // last dialog was closed in <m_last_time>
    queue_item        m_active_item;      // current active checker
protected:

    virtual bool init();
        
    //-- notify centre subscribe
    void subscribe_events();
    void unsubscribe_events();
    void notify_callback( const sqc_provider_id& provider_id, 
                          const sqc_event_id& event_id); 
    //--
        
    typedef std::list<queue_item>	    message_list;
    typedef std::list<sqc_checker_base_ptr>	checkers_list;
    message_list	  m_message_list;     // list with dialogs queue 
    checkers_list     m_checkers;         // list of all possible checkers.
    sqc_dword         m_interval;         // interval what shoud waiting
                                          //  between closes dialogs.
                                          //  and current time.
                                        
    //-- notify                                                                  
    sqc_notify_center&       m_notify_center;                                          
    sqc_listener_connection  m_notify_connection;
    //--
    
    sqc_country_base_ui_face& m_ui;
    sqc_game_ptr m_game;
    
private:
    //--  internal methods
    void check_all_checkers();
    /*
     @brief Function checks as long previous dialogue was closed.
     @return true - if another long, otherwise return - false.
     */
    bool delay_period_expired(); 
        
    virtual void on_programm_start(); 
    virtual void on_xml_received(); 
    //--
    
};

END_NAMESPACE_SQC_FRAMEWORK
