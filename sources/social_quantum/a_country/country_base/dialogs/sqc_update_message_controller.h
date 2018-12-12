/*
 *  sqc_update_message_controller.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 26.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef _SQC_UPDATE_MESSAGE_CONTROLLER_H_INCLUDED__
#define _SQC_UPDATE_MESSAGE_CONTROLLER_H_INCLUDED__

#include "country_base/shop/sqc_shop_defs.h"
#include "country_base/sqc_game_base.h"

NAMESPACE_SQC_FRAMEWORK

class update_message_controller_face
{
public:
    update_message_controller_face(sqc_game_ptr game);
    virtual ~update_message_controller_face();
    
    virtual void buy_pressed(sqc_shop_category_item_ptr item)  = 0;
    virtual void gift_pressed(sqc_shop_category_item_ptr item) = 0;
    
    virtual sqc_shop_category_deque_items& get_items() = 0;
    
    virtual sqc_dword get_visible_cell() = 0;
    virtual sqc_dword get_cell_count()   = 0;
    virtual sqc_dword get_level()        = 0;
    
protected:
    sqc_game_ptr m_game;
};

typedef std::tr1::shared_ptr<update_message_controller_face> update_message_controller_face_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif