#pragma once

#include "../message_queue/sqc_message_queue_base.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_net_changed_checker : public sqc_checker_base
{
public:
	sqc_net_changed_checker(sqc_message_queue_base& message_queue
                     ,sqc_country_base_ui_face& ui
                     ,const sqc_string in_name);
    
    virtual ~sqc_net_changed_checker(); 
    
	virtual void invoke(); 
    
protected:
    bool need_show();
    void show_dialog();
    bool return_false(sqc_string reason);
};

END_NAMESPACE_SQC_FRAMEWORK
