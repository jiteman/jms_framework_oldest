#pragma once


/* -------  FILE DESCRIPTION  ---------- */
/*
 * Current checkers used for event processing "Daily gift" 
 * A workflow for displays dialogue "daily gift" consists of two phases:
 *  1) At the beginning should read the xml file
 *     for correctly fill member m_param.
 *  2) Dialog is called from sqc_message_queue_base.
 *     Remember: dialogue displayed only if need_show() return true.
 *
 */

#include "../message_queue/sqc_message_queue_base.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_gift_checker : public sqc_checker_base
{
public:
	sqc_gift_checker(sqc_message_queue_base& message_queue
                    ,sqc_country_base_ui_face& ui
                    ,const sqc_string &in_name);
    
    virtual ~sqc_gift_checker(); 
    
	virtual void invoke(); 
    virtual void parse_xml(xml::xml_doc &in_xml); 
    
protected:
    bool need_show();
    void show_dialog();
    void param_reset();
    // -- members   
    sqc_ddword m_interval;
    daily_dlg_param m_param;
};

END_NAMESPACE_SQC_FRAMEWORK
