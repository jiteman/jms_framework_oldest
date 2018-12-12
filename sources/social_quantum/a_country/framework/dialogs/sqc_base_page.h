#pragma once

#include "../sqc_framework_defs.h"
#include "../layouts/sqc_layout_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_dialog;
typedef std::tr1::shared_ptr<sqc_dialog> sqc_dialog_ptr;

class sqc_dialog_page : public milk::milk_dialog_page {
public:
	sqc_dialog_page( sqc_dialog_ptr p );
protected:
	sqc_window_factory_ctx_ptr      m_window_ctx;
	/// separator vertical
	milk::milk_separator_ptr	create_separator( const milk::milk_widget_ptr& place_to, const vertical_separator_layout& layout );
	/// separator horizontal
	milk::milk_separator_ptr	create_separator( const milk::milk_widget_ptr& place_to, const horizontal_separator_layout& layout );
};

typedef std::tr1::shared_ptr<sqc_dialog_page> sqc_dialog_page_ptr;

END_NAMESPACE_SQC_FRAMEWORK
