#include "sqc_update_message_checker.h"
#include "../sqc_framework_base.h"

NAMESPACE_SQC_FRAMEWORK

sqc_update_message_checker::sqc_update_message_checker( sqc_message_queue_base& message_queue
                     ,sqc_country_base_ui_face& ui
                     ,sqc_game_ptr game
                     ,sqc_notify_center& notify_center
                     ,const sqc_string in_name )
: sqc_checker_base(message_queue,ui,in_name)
, m_showed(false)
, m_game(game)
, m_notify_center(notify_center)
//, m_notify_connection(0)
{}
    
void sqc_update_message_checker::invoke()
{
    if(!need_show())
        return;
    
    // show( add to queue)
    show_dialog();
}
    
bool sqc_update_message_checker::need_show()
{
    if(m_showed)
        return false;
        
    sqc_info() << "'update_message_dialog::need_show' return true "; 
    return true;
}
 
void sqc_update_message_checker::show_dialog()
{
    /*
    dlg - can be NULL, not only if create_update_message_dialog()
          have error. If control havn't content for dialogue,
          create_update_message_dialog() too return 'dlg = NULL'.
          See create_update_message_dialog() implementation.
    */
    milk::milk_dialog_ptr dlg = m_ui.create_update_message_dialog(m_game);
    
    if ( !dlg )
    {
        sqc_warning() << "unable to create update_message_dialog";
        return;
    }
    
    sqc_info() << "'update_message_dialog' dialog was added in queue "; 
    m_message_queue.add_messsage_back( dlg );
    
    m_showed = true;
}
           
sqc_update_message_checker::~sqc_update_message_checker()
{
     sqc_info() << "'sqc_update_message_checker' checker destryed "; 
}

void sqc_update_message_checker::subscribe_events()
{
    m_notify_connection = m_notify_center.subscribe( 
                                                    std::tr1::bind( &sqc_update_message_checker::notify_callback,
                                                                   this,
                                                                   std::tr1::placeholders::_1,
                                                                   std::tr1::placeholders::_2 ) );
}

void sqc_update_message_checker::unsubscribe_events()
{
    m_notify_center.unsubscribe( m_notify_connection );
}

void sqc_update_message_checker::notify_callback( const sqc_provider_id& provider_id, 
                     const sqc_event_id& event_id)
{
    /*
     To do: I think this is not the final version,
            coz need subscribe to the event "received a new yml"
    */
    if ( processor::country_provider_id == provider_id )
    {
        if ( processor::country_configuration_ready_event == event_id )
        {
            m_showed = false;
        }
    } 
}

END_NAMESPACE_SQC_FRAMEWORK
