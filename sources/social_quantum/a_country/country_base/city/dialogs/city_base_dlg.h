#pragma once

#include "../../../framework/sqc_framework_defs.h"
#include "../../../framework/dialogs/sqc_base_dialog.h"
#include "city_base_dlg_layout.h"
#include "country_base/sqc_country_base_ui.h"
#include "city_dialogs_params.h"

NAMESPACE_SQC_FRAMEWORK



class city_message_box : public sqc_message_box {
public:
	city_message_box( milk::milk_widget_ptr p )    
    	: sqc_message_box( p, 
                         city_dlg_layout::message_box::background, 
                         city_dlg_layout::message_box::title,
                         city_dlg_layout::message_box::text,
                         city_dlg_layout::message_box::def_button,
                         city_dlg_layout::message_box::def_button_text,
                         city_dlg_layout::message_box::min_button_width,
                         city_dlg_layout::message_box::button_text_offset_min,
                         city_dlg_layout::message_box::anchors ) {
    }
        
    virtual ~city_message_box() {
    }
};

typedef std::tr1::shared_ptr<city_message_box>	city_message_box_ptr;

END_NAMESPACE_SQC_FRAMEWORK
