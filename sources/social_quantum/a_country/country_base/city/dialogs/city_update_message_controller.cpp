/*
 *  city_update_message_controller.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 25.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_update_message_controller.h"
#include "city/city_framework.h"
#include "country_base/dialogs/select_person/sqc_select_person_controller.h"

NAMESPACE_SQC_FRAMEWORK

city_update_message_controller::city_update_message_controller(sqc_game_ptr game)
: update_message_controller_face(game) 
, m_visible_cell_count(3)
{    
    update();
    fill_items();
}


city_update_message_controller::~city_update_message_controller()
{
    sqc_info() << "city_update_message_controller: controller destroyed";
}

sqc_dword city_update_message_controller::get_visible_cell()
{
    return m_visible_cell_count;
}

sqc_dword city_update_message_controller::get_cell_count()
{
    return m_items.size();
}    

sqc_shop_category_deque_items& city_update_message_controller::get_items()
{
    return m_items;
}

void city_update_message_controller::update()
{
    m_game->fill_common_info(m_scene_info);
}

void city_update_message_controller::fill_items()
{
    m_items.clear();
    
    sqc_shop_category_items items;
    
    sqc_shop_enum_params enum_params( 0, sqc_shop_category_all, shop_target, true );
    city::city_framework().shop().enum_shop_category( enum_params, m_scene_info, items );
    
    
    sqc_shop_category_items::iterator it;
    for(it = items.begin(); it != items.end(); it++)
    {
        if (false == framework().preferences().get_bool("update_message_showed", it->get()->name() , false))
        {
            m_items.push_back(*it);
        }
    }
    
    sqc_info() << "'city_update_message_controller::fill_items' get " << m_items.size() << " items";
}


sqc_dword city_update_message_controller::get_level()
{  
    return m_scene_info.level;
}

void city_update_message_controller::buy_pressed(sqc_shop_category_item_ptr item)
{
    PROFILE_ENTRY( "city_update_message_controller::buy_pressed" );
  
    sqc_shop shop = country_framework().shop();
	const sqc_object_info *p_obj = country_framework().object_factory()->get_object_info( item->object_type().c_str() );
    
    sqc_assert(p_obj && "have no object");
    
    if ( p_obj->get_pseudo_item() )
    {
		const sqc_string userid="";
        const sqc_string type_name = p_obj->get_type_name();
        const sqc_point point;
        
        processor::sqc_command_ptr command(
                                           new sqc::processor::sqc_create_command(
                                                                                  userid,
                                                                                  type_name,
                                                                                  sqc_point(),
                                                                                  false
                                                                                  )
                                           );
        
        country_framework().cmd_processor().schedule( command );
    }
    else 
    {
        tools::sqc_activate_tool_arg    arg = {};
        
        arg.operation_coords_defined      = true;
        arg.operation_coords              = sqc_point();
        arg.purchased_object_type         = item->object_type();
        sqc_scene_view_ptr ptr_scene_view = country_framework().scene_view();
        tools::sqc_tools_controlles &controller = country_framework().tools();
        
        controller.activate_tool( tools::tool_type_buy, arg, ptr_scene_view->get_tool_context(),
                                                            *ptr_scene_view.get());
	}
}
  
void city_update_message_controller::gift_pressed(sqc_shop_category_item_ptr item)
{
    sqc_send_gift_to_friend_controller_ptr ptr_delegate( new sqc_send_gift_to_friend_controller() );
    ptr_delegate->set_select_person_callback( std::tr1::bind( &city_update_message_controller::on_select_user_for_gift,
                                                             this,
                                                             std::tr1::placeholders::_1,
                                                             item ) );
    
	country_framework().ui().show_select_preson_dialog( ptr_delegate );
}

bool city_update_message_controller::on_select_user_for_gift( const sqc_string& choose_user_id,
                                                             sqc_shop_category_item_ptr item)
{
    
	using namespace processor;
    sqc_command_ptr  command( new sqc_send_shop_gift_command( "", item->object_type(), choose_user_id ) );
	country_framework().cmd_processor().schedule( command );
    
    return true;
}


END_NAMESPACE_SQC_FRAMEWORK