#pragma once

#include "../sqc_country_base_ui.h"
#include "../../sqc/sqc_xml.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_message_queue_base;

class sqc_checker_base {

public:
	sqc_checker_base( sqc_message_queue_base &message_queue, sqc_country_base_ui_face &ui, const sqc_string &in_name );
                      
	virtual void invoke() = 0;
    virtual void parse_xml(xml::xml_doc &in_xml);
    
    virtual ~sqc_checker_base();
    
protected:
    //-- links
	sqc_message_queue_base&   m_message_queue;
	sqc_country_base_ui_face& m_ui;
    
    //-- member
    sqc_string   m_name;   
};

typedef std::tr1::shared_ptr<sqc_checker_base>	 sqc_checker_base_ptr;

END_NAMESPACE_SQC_FRAMEWORK
