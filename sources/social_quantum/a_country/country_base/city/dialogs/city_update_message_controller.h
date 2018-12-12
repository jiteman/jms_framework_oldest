/*
 *  city_update_message_controller.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 25.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_UPDATE_MESSAGE_CONTROLLER_H_INCLUDED__
#define __SQC_CITY_UPDATE_MESSAGE_CONTROLLER_H_INCLUDED__

#include "city_base_dlg.h"
#include "country_base/dialogs/sqc_update_message_controller.h"

NAMESPACE_SQC_FRAMEWORK

class city_update_message_controller : public update_message_controller_face
{
public:
    city_update_message_controller(sqc_game_ptr game);
    virtual ~city_update_message_controller();
    
    //-- virtual func implementation
    sqc_shop_category_deque_items& get_items();
    
    void buy_pressed(sqc_shop_category_item_ptr item);
    void gift_pressed(sqc_shop_category_item_ptr item);   
    
    sqc_dword get_visible_cell();
    sqc_dword get_cell_count(); 
    sqc_dword get_level();
    //--
    
protected:

    void    update();
    void    fill_items();
    
    bool    on_select_user_for_gift(const sqc_string& choose_user_id,
                                    sqc_shop_category_item_ptr item);
        
protected:
    
    sqc_word   m_visible_cell_count;

    sqc_shop_category_deque_items  m_items;
    sqc::sqc_common_scene_info     m_scene_info;    
};

END_NAMESPACE_SQC_FRAMEWORK

#endif