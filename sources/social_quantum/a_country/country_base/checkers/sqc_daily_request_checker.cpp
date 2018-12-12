#include "sqc_daily_request_checker.h"
#include "../sqc_framework_base.h"

NAMESPACE_SQC_FRAMEWORK


sqc_daily_request_checker::sqc_daily_request_checker(
                                   sqc_message_queue_base& message_queue
                                   ,sqc_country_base_ui_face& ui
                                   ,sqc::framework::sqc_game_ptr& game
                                   ,sqc_notify_center& notify_center
                                   ,const sqc_string in_name)
: sqc_checker_base(message_queue,ui,in_name)
, m_show_dialog(false)
, m_param(game)
, m_notify_center(notify_center)
//, m_notify_connection(0)
{
    subscribe_events();
}

void sqc_daily_request_checker::invoke()
{
    if(!need_show())
        return;
    
    // show( add to queue)
    show_dialog();
}
void sqc_daily_request_checker::show_dialog()
{
    milk::milk_dialog_ptr dlg = m_ui.create_daily_request_dialog(m_param);
    
    /*       //-- TEST PRINT
    std::list<sqc_daily_gift_param::received_object>::iterator iter;
    
    for(iter = m_param.m_received_objs.begin(); iter != m_param.m_received_objs.end(); iter++ )
    {
        sqc_info() << iter->item_name;
    }
    */
    
    if ( !dlg )
    {
        sqc_error() << "unable to create daily request dialog";
        return;
    }
    
    dlg->set_destroy_handler( 
                          std::tr1::bind( &sqc_daily_request_checker::on_destroy, this ) );
                          
    sqc_info() << "'daily request' dialog was added in queue "; 
    m_message_queue.add_messsage_back( dlg );

}

void sqc_daily_request_checker::on_destroy()
{
    m_param.m_received_objs.clear();
    m_param.m_wish_objs.clear();
}
    
void sqc_daily_request_checker::subscribe_events()
{
    m_notify_connection = m_notify_center.subscribe( 
                                                    std::tr1::bind( &sqc_daily_request_checker::notify_callback,
                                                                   this,
                                                                   std::tr1::placeholders::_1,
                                                                   std::tr1::placeholders::_2 ) );
}

void sqc_daily_request_checker::unsubscribe_events()
{
   	m_notify_center.unsubscribe( m_notify_connection );
}

void sqc_daily_request_checker::notify_callback( const sqc_provider_id& provider_id, 
                     const sqc_event_id& event_id)
{
    if ( processor::friends == provider_id )
    {
        if ( processor::friends_event_query_complete == event_id )
        {
            m_show_dialog = true;
        }
        else if(processor::friends_event_query_error == event_id )
        {
            sqc_error()
                << "sqc_daily_request_checker: friends_event_query_error";
        }
    } 
}

sqc_daily_request_checker::~sqc_daily_request_checker()
{
    
}


void sqc_daily_request_checker::parse_xml(xml::xml_doc &in_xml)
{
    using namespace xml;
    
    //-- write test value to xml
    /*
     xml_node_ptr    received_parent_node = in_xml.query_xpath_node("/country/gifts/received");
     xml_node_ptr    new_node = in_xml.create_node( "furniture", received_parent_node );
     
     new_node->set_attribute( "new",          "true" );
     new_node->set_attribute( "quantity",     "1" );
     new_node->set_attribute( "id",           "46153148" );
     new_node->set_attribute( "from_user_id", "1766466" ); //type some you friend "id"
     */
    //--
    
    
    //-- Получение подаренных объектов
    {
        xml_node_list _node_entries;
        
        xml_node_ptr _node = in_xml.query_xpath_node("/country/gifts/received");
        if(_node)
        {
            _node->get_childs( _node_entries );
        }
        
        for( xml_node_list::const_iterator i = _node_entries.begin(); i != _node_entries.end(); ++i )
        {
            xml_node_ptr    child_node( *i );
            sqc_daily_gift_param::received_object _field;
            
            if(child_node->get_attribute("new") == "true")
            {
                _field.m_item_name     = child_node->get_name();
                _field.m_id            = child_node->get_attribute_int("id");
                _field.m_from_user_id  = child_node->get_attribute_int("from_user_id");
                _field.m_quantity      = child_node->get_attribute_int("quantity");
        
                m_param.m_received_objs.push_back(_field);   
            }
        }
    }
    //--
    
    //-- Получение желаемых объектов
    {
        xml_node_list    node_entries;
        
        xml_node_ptr _node = in_xml.query_xpath_node("/country/friends");
        if(_node)
        {
            _node->get_childs( node_entries );
        }
        
        
        for( xml_node_list::const_iterator i = node_entries.begin(); i != node_entries.end(); ++i )
        {
            xml_node_ptr    child_node( *i );
            
            sqc_daily_gift_param::wish_object _field;
                    
            _field.m_friend_id  = child_node->get_attribute_int("id");
            sqc_string  str     = child_node->get_attribute("wish_list");
                
            std::istringstream iss(str);
            sqc_string token;
    
            sqc_string wisher = "wisher_" + child_node->get_attribute("id");
            const sqc_string _def   = "new";
            
            while(getline(iss, token, ','))
            {   
                if( _def == framework().preferences().get_string(wisher, token, "old"))
                {
                    _field.m_wishes_list.push_back(token);
                    framework().preferences().set_string(wisher, token, "old");
                }   
            }
            
            if(!_field.m_wishes_list.empty())
            {
                m_param.m_wish_objs.push_back(_field); 
            }
        }
    }
    //--
    
}

bool sqc_daily_request_checker::need_show()
{       
    if(m_param.m_received_objs.empty()
       && m_param.m_wish_objs.empty() )
    {
        return false;
    }
    else 
        return m_show_dialog;
        
}

END_NAMESPACE_SQC_FRAMEWORK
