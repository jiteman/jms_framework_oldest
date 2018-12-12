/*
 *  sqc_base_page.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/21/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_base_page.h"
#include "../sqc_framework.h"
#include "sqc_base_dialog.h"

NAMESPACE_SQC_FRAMEWORK

sqc_dialog_page::sqc_dialog_page( sqc_dialog_ptr  p ) : milk::milk_dialog_page( p ) {
	m_window_ctx = p->get_window_factory_ctx();
}




/// separator vertical
milk::milk_separator_ptr	sqc_dialog_page::create_separator( const milk::milk_widget_ptr& place_to, const vertical_separator_layout& layout ) {
	return std::tr1::static_pointer_cast<sqc_dialog>(get_parent())->create_separator(place_to,layout);
}
/// separator horizontal
milk::milk_separator_ptr	sqc_dialog_page::create_separator( const milk::milk_widget_ptr& place_to, const horizontal_separator_layout& layout ) {
	return std::tr1::static_pointer_cast<sqc_dialog>(get_parent())->create_separator(place_to,layout);
}


END_NAMESPACE_SQC_FRAMEWORK