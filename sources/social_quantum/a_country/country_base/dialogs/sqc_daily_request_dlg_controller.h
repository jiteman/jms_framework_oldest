/*
 *  sqc_daily_request_dlg_control.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 28.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *  email: vkonnov@yandex.ru
 */


#ifndef __SQC_DAILY_REQUEST_CONTROLLER_H_INCLUDED__
#define __SQC_DAILY_REQUEST_CONTROLLER_H_INCLUDED__

#include "city/dialogs/city_base_dlg.h"
#include "country_base/sqc_game_base.h"


NAMESPACE_SQC_FRAMEWORK



class daily_request_controller_face
{
public:
    daily_request_controller_face();
    virtual ~daily_request_controller_face();
    
    //-- get
    virtual sqc_shop_category_items& get_shop_category_items() = 0; 
    virtual sqc_shop_category& get_shop_category() = 0;
    virtual sqc_dword get_message_count() = 0;
    virtual sqc_word  get_cell_count() = 0;
    virtual sqc_dword get_level() = 0;
    virtual sqc_dword get_visible_cell() = 0;
    //--
    
    //-- wall
    virtual bool need_wall_button() = 0;
    virtual void send_to_wall(const sqc_string message) = 0;
    //--
    
};

typedef std::tr1::shared_ptr<daily_request_controller_face> daily_request_controller_face_ptr;


class daily_request_controller : public daily_request_controller_face
{
public:

    //-- get
    sqc_shop_category_items& get_shop_category_items(); 
    sqc_shop_category& get_shop_category();
    sqc_dword get_message_count();
    sqc_word  get_cell_count();
    sqc_dword get_visible_cell();
    sqc_dword get_level();
    //--
    
    //-- wall
    bool need_wall_button();
    void send_to_wall(const sqc_string message);
    //--
    
    void update();
    
    //-- Constructor
    daily_request_controller(sqc_daily_gift_param param);
    
protected:
    sqc_shop_category m_shop_category; //sqc_shop_category_all
    sqc_shop_category_items m_items;
    sqc_dword m_level;
    
    sqc_daily_gift_param m_param;
    
    sqc::sqc_dword m_visible_cell_count;
    
};


END_NAMESPACE_SQC_FRAMEWORK


#endif // FILE_ALREADY_INCLUDED