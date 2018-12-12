#include "sqc_daily_gift_checker.h"
#include "../../framework/sqc_framework.h"
#include "../sqc_framework_base.h"

NAMESPACE_SQC_FRAMEWORK

sqc_gift_checker::sqc_gift_checker( sqc_message_queue_base &message_queue, sqc_country_base_ui_face &ui, const sqc_string &in_name )
	:
		sqc_checker_base( message_queue, ui, in_name ),
		m_interval( 24 * 60 * 60 * 1000) // = one day
{}

void sqc_gift_checker::invoke()
{
    if(!need_show())
        return;
    
    // show( add to queue)
    show_dialog();
}

void sqc_gift_checker::param_reset()
{
    m_param.bonus = 0;
    m_param.day   = 0;
    m_param.bucks = 0;
}

void sqc_gift_checker::show_dialog()
{
    milk::milk_dialog_ptr dlg = m_ui.create_daily_gift_dialog(m_param);
    
    if ( !dlg )
    {
        sqc_error() << "unable to create daily gift dialog";
        return;
    }

    sqc::sqc_dword current_time = clock_msec();
    framework().preferences().set_int( "last_show_date", "last_show_time", current_time );
    
    sqc_info() << "'daily gift' dialog was added in queue "; 
    m_message_queue.add_messsage_back( dlg );
    
    param_reset();
}

sqc_gift_checker::~sqc_gift_checker()
{
    
}

void sqc_gift_checker::parse_xml(xml::xml_doc &in_xml)
{
    using namespace xml;
        
        
    //-- Uncommited for write test value to xml
    /*
    if(true)
    {
        xml_node_ptr    league_parent_node = in_xml.query_xpath_node("/country");
        xml_node_ptr    new_node = in_xml.create_node( "messages", league_parent_node );
        
        xml_node_ptr    messages_parent_node = in_xml.query_xpath_node("/country/messages");
                        new_node = in_xml.create_node( "message", messages_parent_node );
        
        new_node->set_attribute( "code",       "daily_gift_money" );
        new_node->set_attribute( "amount",     "500" );
        new_node->set_attribute( "day_count",  "3" );
        //new_node->set_attribute( "super_gift", "1" );
     }
     */
        
    xml_node_ptr _node = in_xml.query_xpath_node("/country/messages/message[@code='daily_gift_money']");
    
    if(!_node)
    {
        sqc_info() << "XML 'daily_gift_money' was empty";
        return;
    }
    
    //-- read data
    m_param.bonus = _node->get_attribute_int( "amount" );
    m_param.day   = _node->get_attribute_int( "day_count" ); 
    m_param.bucks = (m_param.day != 5) ? 1 : _node->get_attribute_int( "super_gift" );      
    //--
        
    sqc_info() << "'daily_gift_money'. sqc_gift_checker have new value:"
               << " bonus = " << m_param.bonus
               << " day = " << m_param.day
               << " megabucks = " << m_param.bucks;
}

bool sqc_gift_checker::need_show()
{
    if(!m_param.bonus || !m_param.day || !m_param.bucks)
    {
        sqc_info() << "'daily_gift_money' parameters empty. need_show() return false";
        return false;
    }
    
    bool show_dialog = false;
    
    sqc::sqc_dword current_time   = clock_msec();
    sqc::sqc_dword last_show_date = framework().preferences().get_int( "last_show_date", "last_show_time", 0 );
    
    
    if(0 == last_show_date)
    {      
        framework().preferences().set_int( "last_show_date", "last_show_time", current_time );
        sqc_info() << "'daily_gift_money' last_show_date = 0";
    }
    else
    {
        show_dialog = (current_time - last_show_date  >= m_interval);
    }
    
    return show_dialog;
}

END_NAMESPACE_SQC_FRAMEWORK