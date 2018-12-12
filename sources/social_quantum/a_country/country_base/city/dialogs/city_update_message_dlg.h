/*
 *  city_update_message_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 24.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_UPDATE_MESSAGE_DLG_H__
#define __SQC_CITY_UPDATE_MESSAGE_DLG_H__

#include "city_base_dlg.h"
#include "city_update_message_layout.h"
#include "city_update_message_controller.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"

NAMESPACE_SQC_FRAMEWORK

class city_update_message_dlg : public sqc_dialog_with_close
                              , public milk::milk_spinboard_callbacks 
{
public:
    city_update_message_dlg( milk::milk_widget_ptr p, update_message_controller_face_ptr control)
    : sqc_dialog_with_close( p, city_dlg_layout::city_update_message_layout::dialog ) 
    , m_control(control)
    {
    }
    
protected:
    
	void    on_init_dialog();
    
    //-- milk_spinboard_callbacks interface
    milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    sqc_int get_cell_count();
    
    bool fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                        const sqc_shop_category_item_ptr item );
    //--
    
    //-- buttons 
    void on_buy_pressed( sqc_shop_category_item_ptr item );
    
    void on_gift_pressed( sqc_shop_category_item_ptr item );
    //--
    
    void save_item_in_prefs();
    
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
    
protected:

    milk::milk_spinboard_ptr           m_spinboard;
    update_message_controller_face_ptr m_control;
    
};

typedef std::tr1::shared_ptr<city_update_message_dlg>	 city_update_message_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif