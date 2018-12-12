/*
 *  sqc_daily_request_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 28.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *  email: vkonnov@yandex.ru
 */

#ifndef __SQC_DAILY_REQUEST_DLG_H_INCLUDED__
#define __SQC_DAILY_REQUEST_DLG_H_INCLUDED__

#include "country_base/sqc_framework_base.h"

#include "country_base/dialogs/controls/sqc_balance_widget.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"
#include "country_base/dialogs/sqc_daily_request_dlg_controller.h"
#include "country_base/dialogs/sqc_daily_request_dlg_layout.h"
#include "country_base/commands/sqc_command_processor.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_daily_request_dlg 
: public sqc_dialog_with_close 
, public milk::milk_spinboard_callbacks 
{
public:
    sqc_daily_request_dlg( milk::milk_widget_ptr p,daily_request_controller_face_ptr control)
    : sqc_dialog_with_close( p, daily_request_layout::background )
    , m_control(control)
    {
    }
    
    //-- milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    virtual sqc_int get_cell_count();
    
    bool fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                        const sqc_shop_category_item_ptr item );
    //--
    
    //-- buttons 
    void on_sell_pressed( const sqc_string& object_type );
    
    void on_received_pressed( const sqc_string& object_type );
    //--
    
    milk::milk_spinboard_ptr    m_spinboard;
    
protected:
	// initialization 
	virtual void on_init_dialog();
	virtual void on_post_init_dialog();
    daily_request_controller_face_ptr m_control;
};

typedef std::tr1::shared_ptr<sqc_daily_request_dlg>	 sqc_daily_request_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif