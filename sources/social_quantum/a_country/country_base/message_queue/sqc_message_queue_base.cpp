#include "sqc_message_queue_base.h"
#include "../commands/sqc_command_processor.h"
#include "../sqc_framework_base.h"

//-- include checkers
#include "../checkers/sqc_daily_gift_checker.h"
#include "../checkers/sqc_daily_request_checker.h"
#include "../checkers/sqc_level_checker.h"
#include "../checkers/sqc_net_changed_checker.h"
#include "../checkers/sqc_update_message_checker.h"
//--

NAMESPACE_SQC_FRAMEWORK

sqc_message_queue_base::sqc_message_queue_base(sqc_notify_center& notify_center,
                                               sqc_game_ptr game,
                                               sqc_country_base_ui_face& ui)
            : m_notify_center(notify_center)
            , m_game(game)
            , m_ui(ui)
            , m_notify_connection(0)
            , m_last_time(0)
            , m_interval(0)

{
    //init();
}

void sqc_message_queue_base::add_messsage_back(queue_item item )
{
    m_message_list.push_back( item );
}

void sqc_message_queue_base::add_messsage_front( queue_item item )
{
    m_message_list.push_front( item );
}

sqc_message_queue_base::~sqc_message_queue_base()
{
}

bool sqc_message_queue_base::init()
{
    subscribe_events();
    
    m_checkers.push_back(                                          
                         sqc_checker_base_ptr(
                                              new sqc_gift_checker(
                                                                   *this,
                                                                   m_ui,
                                                                   sqc::sqc_string("daily_gift_checker") )));
    
    m_checkers.push_back(                                          
                         sqc_checker_base_ptr(
                                              new sqc_daily_request_checker(
                                                                            *this,
                                                                            m_ui,
                                                                            m_game,
                                                                            m_notify_center,
                                                                            sqc::sqc_string("daily_request_checker") )));
                                                                                            
    m_checkers.push_back(
                         sqc_checker_base_ptr(
                                              new sqc_level_checker(
                                                                    *this,
                                                                    m_game,
                                                                    m_ui,
                                                                    sqc::sqc_string("net_level_checker") )));
                                                                    
    m_checkers.push_back(
                         sqc_checker_base_ptr(
                                              new sqc_net_changed_checker(
                                                                          *this,
                                                                          m_ui,
                                                                          sqc::sqc_string("net_changed_checker") )));
                                                                          
    m_checkers.push_back(
                         sqc_checker_base_ptr(
                                              new sqc_update_message_checker(
                                                                             *this,
                                                                             m_ui,
                                                                             m_game,
                                                                             m_notify_center,
                                                                             sqc::sqc_string("update_message_checker") )));

    
    return true;
}

void sqc_message_queue_base::on_programm_start()
{
    check_all_checkers();
    
}

void sqc_message_queue_base::on_xml_received()
{
    check_all_checkers();
}

void sqc_message_queue_base::on_xml_received(xml::xml_doc &in_xml)
{
    for(checkers_list::iterator it = m_checkers.begin(); it != m_checkers.end();it++ )
    {
        sqc_info() << "call parse_xml for " << it->get()->print_info().c_str();
        it->get()->parse_xml(in_xml);
    }
}


void sqc_message_queue_base::check_all_checkers()
{
    for(checkers_list::iterator it = m_checkers.begin(); it != m_checkers.end();it++ )
    {
        it->get()->invoke();
    }
}


// subscribe for events
void sqc_message_queue_base::subscribe_events()
{    
    m_notify_connection = m_notify_center.subscribe( 
                            std::tr1::bind( &sqc_message_queue_base::notify_callback,
                                            this,
                                            std::tr1::placeholders::_1,
                                            std::tr1::placeholders::_2 ) );
}


// unsubscribe for events
void sqc_message_queue_base::unsubscribe_events()
{
	m_notify_center.unsubscribe( m_notify_connection );
    
}

void sqc_message_queue_base::notify_callback(
                                             const sqc_provider_id& provider_id, 
                                             const sqc_event_id& event_id)
{
    if ( processor::command_processor_provider_id == provider_id )
    {
        if ( processor::command_processor_initial_xml_complete_event == event_id )
        {
            on_xml_received();
        }
    }
}

bool sqc_message_queue_base::delay_period_expired()
{    
    PROFILE_ENTRY( "sqc_message_queue_base::delay_period_expired" );
    
    if(clock_msec() - m_last_time < m_interval)
        return false;
    else 
        return true;
}

void sqc_message_queue_base::handle_timer()
{
    PROFILE_ENTRY( "sqc_country_base_state_alerts::handle_timer" );
    
    if( m_active_item )
    {
         if (m_active_item->is_running())
             return;

         m_active_item.reset();

    }

    
    if ( !m_message_list.size())
        return;
    
    if(!delay_period_expired())
        return;
    
    
    m_active_item = m_message_list.front();
    m_message_list.pop_front();
    m_active_item->do_modal();
}

END_NAMESPACE_SQC_FRAMEWORK
