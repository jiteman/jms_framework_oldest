#include "sqc_net_changed_checker.h"
#include "../../framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

sqc_net_changed_checker::sqc_net_changed_checker(sqc_message_queue_base& message_queue
                            ,sqc_country_base_ui_face& ui
                            ,const sqc_string in_name)
: sqc_checker_base(message_queue,ui,in_name)
{
    
}
    
sqc_net_changed_checker::~sqc_net_changed_checker()
{
}
    
void sqc_net_changed_checker::invoke()
{
    if(!need_show())
        return;
    
    // show( add to queue)
    show_dialog();
}
    
bool sqc_net_changed_checker::return_false(sqc_string reason)
{   
    if(!reason.empty())
        sqc_info() << "sqc_net_changed_checker: need_show() return false, becouse:" << reason.c_str();
        
    return false;
}
    
bool sqc_net_changed_checker::need_show()
{   /*
     condition:
     Past network must be a local network, and the current must be nonlocal
    */
    
    sqc_word last_net = framework().preferences().get_int("socnet", "last_net", 0);
    
    if(sqc_network_none == last_net) // == 0
        return return_false("last_net == sqc_network_none");    

    if(sqc_network_social_quantum != last_net) // != "SQ"
        return return_false("last_net != sqc_network_social_quantum");
        
    sqc_word current_net = framework().preferences().get_int("socnet", "current", last_net);    

    if(sqc_network_none == current_net)
        return return_false("current_net == sqc_network_none");    
        
    if(sqc_network_social_quantum == current_net)
        return return_false("current_net == sqc_network_social_quantum");
    
    framework().preferences().set_int("socnet", "last_net", 0);
    
    sqc_info() << "sqc_net_changed_checker: socnet was changed from local to remote server";

    return true;
}

void sqc_net_changed_checker::show_dialog()
{
    milk::milk_dialog_ptr dlg = m_ui.create_net_changed_dialog();
    
    if ( !dlg )
    {
        sqc_error() << "unable to create city_net_changed_dlg";
        return;
    }
    
    sqc_info() << "'city_net_changed_dlg' dialog was added in queue "; 
    m_message_queue.add_messsage_back( dlg );
}

END_NAMESPACE_SQC_FRAMEWORK