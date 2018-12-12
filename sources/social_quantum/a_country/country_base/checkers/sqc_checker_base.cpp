#include "sqc_checker_base.h"

NAMESPACE_SQC_FRAMEWORK

sqc_checker_base::sqc_checker_base( sqc_message_queue_base &message_queue, sqc_country_base_ui_face &ui, const sqc_string &in_name ) 
	:
		m_message_queue( message_queue ),
		m_ui( ui ),
		m_name( in_name )
{}

sqc_checker_base::~sqc_checker_base()
{}

void sqc_checker_base::parse_xml(xml::xml_doc &in_xml)
{}

END_NAMESPACE_SQC_FRAMEWORK
