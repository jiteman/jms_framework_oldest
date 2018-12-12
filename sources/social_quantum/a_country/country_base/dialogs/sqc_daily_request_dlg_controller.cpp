/*
 *  sqc_daily_request_dlg_control.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 28.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "sqc_daily_request_dlg_controller.h"
#include "country_base/sqc_framework_base.h"
#include "country_base/dialogs/sqc_daily_request_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK



daily_request_controller_face::daily_request_controller_face()
{}

daily_request_controller_face::~daily_request_controller_face()
{}

    


daily_request_controller::daily_request_controller(sqc_daily_gift_param param)
: m_level(0)
, m_shop_category(sqc_shop_category_all)
, m_param(param)
, m_visible_cell_count(3) // default value
{
    m_items.clear();
    
    sqc_shop& shop = country_framework().shop(); 
    
    sqc_string _new_name;
    sqc_user_profile_ptr _user;
    sqc::sqc_common_scene_info _si;
    sqc_shop_category_item_ptr _item; 
    sqc_shop_enum_params       _param(0,
                                     sqc_shop_category_all,
                                     received_gift_target);
           
    //-- received items
    std::list<sqc_daily_gift_param::received_object>::iterator received_iter;
    
    for(received_iter = m_param.m_received_objs.begin(); received_iter != m_param.m_received_objs.end(); received_iter++ )
    {
            
        _item = shop.find_shop_item_by_type_name( 
                                                 _param,
                                                 _si,
                                                 received_iter->m_item_name.c_str());
        if(_item)
        {   
             _new_name.clear();
             _user = country_framework().friends().find_friend( received_iter->m_from_user_id );
             
             if(_user)
             {
                 _new_name =  _user->get_first_name();
                 _new_name += "\n";
             }
             else
             {
                 sqc_error()
                 << "daily_request_controller(): unable find_friend() for user_id = " << received_iter->m_from_user_id;
                 
                 _new_name = "You friend\n";
             }
              
            _new_name += format(framework().strings().load(
                                                          common_resources::string_message_gift_you.resource_id(),
                                                          common_resources::string_message_gift_you.def_value()), 
                               _item->name().c_str());
            
            _item->set_name(_new_name);
            
            m_items.push_back(_item);                                                                            
        }
        else
        {
            m_param.m_received_objs.erase(received_iter);
        }

    }
    //--
    
    
    //-- wishes item
    std::list<sqc_daily_gift_param::wish_object>::iterator wish_iter;
    std::list<sqc_string>::iterator str_iter;
    
    //
    // First for(..) - cicle by friend
    // Second (inner) for(..) - cicle by items
    //
    
    _item.reset();
    
    for(wish_iter = m_param.m_wish_objs.begin(); wish_iter != m_param.m_wish_objs.end(); wish_iter++ )
    {
        for(str_iter = wish_iter->m_wishes_list.begin(); str_iter != wish_iter->m_wishes_list.end(); str_iter++ )
        { 
            _item = shop.find_shop_item_by_type_id( 
                                                 _param,
                                                 _si,
                                                 strtoul(str_iter->c_str(),NULL,0));

            if(_item)
            {    
                _new_name.clear();
                
                _user = country_framework().friends().find_friend( wish_iter->m_friend_id );      
                if(_user)
                { 
                    _new_name  = _user->get_first_name();
                    _new_name += "\n";
                }
                else
                {
                    sqc_error()
                    << "daily_request_controller(): unable find_friend() for user_id = " << received_iter->m_from_user_id;
                    
                    _new_name = "You friend\n";
                }
                
                
                _new_name += format(framework().strings().load(
                                                              common_resources::string_message_wish.resource_id(),
                                                              common_resources::string_message_wish.def_value()), 
                                   _item->name().c_str());
                _item->set_name(_new_name);
                                                                      
                m_items.push_back(_item);                                                                            
            } 
            else
            {
                wish_iter->m_wishes_list.erase(str_iter);
            }
        }
    }
    //--
                                                                                                    
    if(framework().windows_factory().get_theme_size() == sqc_theme_large)
        m_visible_cell_count = 5;
                                    
}

sqc_dword daily_request_controller::get_level()
{
    return m_level;
}

sqc_word daily_request_controller::get_cell_count()
{
    return m_items.size();
}

sqc_shop_category& daily_request_controller::get_shop_category()
{
    return m_shop_category;
}

sqc_dword daily_request_controller::get_message_count()
{
    std::list<sqc_daily_gift_param::wish_object>::iterator wish_iter;
    sqc_dword wish_count = 0;
    
    
    for(wish_iter = m_param.m_wish_objs.begin(); wish_iter != m_param.m_wish_objs.end(); wish_iter++ )
    {
        wish_count += wish_iter->m_wishes_list.size();  
    }
    
    return (m_param.m_received_objs.size() + wish_count);
}
    
bool daily_request_controller::need_wall_button()
{
    return false;
}

sqc_shop_category_items& daily_request_controller::get_shop_category_items()
{
    return m_items;
}

sqc_dword daily_request_controller::get_visible_cell()
{
    return m_visible_cell_count;
}
    
void daily_request_controller::send_to_wall(const sqc_string message)
{}
    
void daily_request_controller::update()
{
    sqc::sqc_common_scene_info _si;
    
    m_param.m_game->fill_common_info(_si); 
    
    m_level = _si.level;
}


END_NAMESPACE_SQC_FRAMEWORK