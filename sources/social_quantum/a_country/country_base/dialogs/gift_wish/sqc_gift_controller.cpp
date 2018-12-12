/*
 *  sqc_gift_controller.cpp
 *  aCountry
 *
 *  Created by Paul K on 11.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "sqc_gift_controller.h"
#include "country_base/sqc_framework_base.h"
#include "country_base/shop/sqc_shop.h"
#include "country_base/dialogs/select_person/sqc_select_person_controller.h"
#include "country_base/dialogs/select_construction/sqc_gift_select_construction_controller.h"

NAMESPACE_SQC_FRAMEWORK


sqc_gift_controller::sqc_gift_controller() {
}

sqc_gift_controller::~sqc_gift_controller() {
}

void sqc_gift_controller::get_scene_info( sqc_common_scene_info& info ) {
	sqc_game_ptr game = get_game();
    if ( !game ) {
    	return;
    }
    
    game->fill_common_info( info );
}

//
// Get
//

bool sqc_gift_controller::get_received_gifts(
	sqc_received_gift::vector& gifts ) {
    
	sqc_game_ptr game = get_game();
    if ( !game ) {
    	return false;
    }
    return game->get_received_gifts( gifts );
}

bool sqc_gift_controller::get_available_gifts(
	sqc_available_gift::vector& gifts ) {
    
	sqc_game_ptr game = get_game();
    if ( !game ) {
    	return false;
    }
    return game->get_available_gifts( gifts );
}

bool sqc_gift_controller::get_wishes_gifts(
    sqc_wishes::vector& gifts ) {
    
	sqc_game_ptr game = get_game();
    if ( !game ) {
    	return false;
    }
    return game->get_wishes_gifts( gifts );
}

sqc_game_ptr sqc_gift_controller::get_game() {
    
	sqc_framework_base& framework = country_framework();
    sqc_game_ptr game = framework.game();
    if ( !game ) {
    	sqc_assert( false );
        return sqc_game_ptr();
    }
    return game;
}

//
// Convert gifts
//

sqc_shop_category_item_ptr sqc_gift_controller::convert_received_gift(
	sqc_received_gift::sptr ptr_gift ) {
    
	sqc_assert( ptr_gift );
    if ( !ptr_gift ) {
    	return sqc_shop_category_item_ptr();
    }
    
    sqc_shop& shop = country_framework().shop(); 
    
    sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
    sqc_shop_enum_params enum_params( 0, sqc_shop_category_all, received_gift_target );
    
    sqc_shop_category_item_ptr item =
                    shop.find_shop_item_by_type_name( enum_params
                                                     , scene_info 
                                                     , ptr_gift->type_name());

    if(!item)
    {
        sqc_error()
            << "sqc_gift_controller : unable create object name = " << ptr_gift->type_name().c_str();
            
        return sqc_shop_category_item_ptr();
    }
    
    sqc_string new_name;
    sqc_user_profile_ptr user;
    
    user = country_framework().friends().find_friend( ptr_gift->from_user_id() );

    if(user)
    {
        new_name =  user->get_first_name();
        new_name += "\n";
    }
    else
    {
        sqc_error()
            << "sqc_gift_controller : unable find_friend() for user_id = " << ptr_gift->from_user_id();
        
        new_name = "You friend\n";
    }
    
    new_name += format(framework().strings().load(
                                                  common_resources::string_message_gift_you.resource_id(),
                                                  common_resources::string_message_gift_you.def_value()), 
                        item->name().c_str());
    
    item->set_name(new_name);
     
    return item;
}

sqc_shop_category_item_ptr sqc_gift_controller::convert_available_gift(
	sqc_available_gift::sptr ptr_gift ) {
    
	sqc_assert( ptr_gift );
    if ( !ptr_gift ) {
    	return sqc_shop_category_item_ptr();
    }
    
    sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
    sqc_shop_enum_params enum_params( 0/*enum all levels*/,
    								  sqc_shop_category_all, 
                                      available_gift_target );
    
    sqc_shop& shop = country_framework().shop();
    
    sqc_shop_category_item_ptr ptr_shop_item = 
    	shop.find_shop_item_by_type_name( enum_params, 
        								  scene_info, 
                                          ptr_gift->type_name() );
    
    return ptr_shop_item;
}

sqc_shop_category_item_ptr sqc_gift_controller::convert_wishes_gift(
    sqc_wishes::sptr ptr_gift ) {
    
    sqc_assert( ptr_gift );
    if ( !ptr_gift ) {
    	return sqc_shop_category_item_ptr(); 
    }
    
    sqc_shop& shop = country_framework().shop(); 
    
    sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
    sqc_shop_enum_params enum_params( 0, sqc_shop_category_all, wishes_target );
    
    sqc_shop_category_item_ptr item =
        shop.find_shop_item_by_type_id( enum_params
                                         , scene_info 
                                         , ptr_gift->id());
    
    if(!item)
    {
        sqc_error()
        << "sqc_gift_controller : unable create object id  = " << ptr_gift->id();
        
        return sqc_shop_category_item_ptr();
    }
    
    sqc_string new_name;
    sqc_user_profile_ptr user;
    
    user = country_framework().friends().find_friend( ptr_gift->friend_id());
    
    if(user)
    {
        new_name =  user->get_first_name();
        new_name += "\n";
    }
    else
    {
        sqc_error()
        << "sqc_gift_controller : unable find_friend() for user_id = " << ptr_gift->friend_id();
        
        new_name = "You friend\n";
    }
    
    new_name += format(framework().strings().load(
                                                  common_resources::string_message_wish.resource_id(),
                                                  common_resources::string_message_wish.def_value()), 
                       item->name().c_str());
    
    item->set_name(new_name);
    
    return item;
}

//
// Action: sell, send, ...
//

bool sqc_gift_controller::sell_gift( sqc_received_gift::sptr ptr ) {
	if ( !ptr ) {
    	sqc_assert( false );
    	return false;
    }
    
    const sqc_string user_id = "";
    const sqc_int item_id = ptr->id();
    
	using namespace processor;
	sqc_command_ptr  command( new sqc_sell_gift_command( user_id, item_id ) );
	country_framework().cmd_processor().schedule( command );

    return true;
}

bool sqc_gift_controller::receive_gift( sqc_received_gift::sptr ptr ) {
	if ( !ptr ) {
    	sqc_assert( false );
    	return false;
    }

	const sqc_string user_id	= "";
    const int gift_id			= ptr->id();
    const sqc_string klass		= ptr->type_name();

    sqc_shop_enum_params parameters(0, sqc_shop_category_all, shop_target);
    
	sqc_common_scene_info scene_info;
    get_scene_info(scene_info);
        
    sqc_shop_category_item_ptr item = country_framework().shop().find_shop_item_by_type_name( parameters, scene_info, klass );

    if (item) {

    	if (item->get_create_action() == create_action_use_in_construction) {

			// apply material

			sqc_select_construction_delegate_ptr ptr_delegate(
				new sqc_gift_apply_shop_material_controller( klass, gift_id )
			);

			sqc_assert( ptr_delegate );

			country_framework().ui().show_select_construction_dlg(ptr_delegate);
		}
		else if (item->get_create_action() == create_action_apply_to_field) {

            /* call
            sqc_receive_gift_command( const sqc_string& user_id,
                         const int item_id,
                         const sqc_string &klass,
                         const int rotation,
                         const int x,
                         const int y)
        	*/

            using namespace processor;
            sqc_command_ptr command( new sqc_receive_gift_command( 
            	"", 
                ptr->id(),
                klass,
                0, 0, 0
            ) );
            country_framework().cmd_processor().schedule( command );
        }
		else {
			tools::sqc_activate_tool_arg arg = {};

			arg.user_id = framework().networks().get_user_id();
			arg.gift = true;
			arg.purchased_object_type=klass;
			tools::sqc_tools_controlles &controller = country_framework().tools();
			sqc_scene_view_ptr ptr_scene_view = country_framework().scene_view();

			controller.activate_tool( tools::tool_type_buy, arg, ptr_scene_view->get_tool_context(), *ptr_scene_view.get() );
        }
        
    }
    
    return true;
}

bool sqc_gift_controller::send_gift( sqc_available_gift::sptr ptr ) {
	if ( !ptr ) {
    	sqc_assert( false );
    	return false;
    }
    
    sqc_send_gift_to_friend_controller_ptr ptr_delegate( new sqc_send_gift_to_friend_controller() );
    ptr_delegate->set_select_person_callback( std::tr1::bind( &sqc_gift_controller::on_select_user_for_gift,
												  this,
												  std::tr1::placeholders::_1,
                                                  ptr ) );

	country_framework().ui().show_select_preson_dialog( ptr_delegate );
    return true;
}

bool sqc_gift_controller::send_gift( sqc_wishes::sptr ptr )
{
    if ( !ptr ) {
    	sqc_assert( false );
    	return false;
    }
    
    std::stringstream _ss;
    _ss << ptr->m_friend_id;
    
    using namespace processor;    
    
    /*
    // Not for delete.
    sqc_available_gift::vector	available_gifts;
    get_available_gifts( available_gifts );
     
    sqc_available_gift::vector::iterator it;
    for(it = available_gifts.begin(); it != available_gifts.end(); it++)
    {   
        if(it->get()->type_name() == ptr->type_name())
        {
            
             sqc_command_ptr  command( new sqc_send_gift_command( "", ptr->id(), _ss.str() ) );
             country_framework().cmd_processor().schedule( command );
            
            return true;
        }
    }
    */

	sqc_command_ptr  command( new sqc_send_shop_gift_command( "", ptr->type_name(), _ss.str() ) );
	country_framework().cmd_processor().schedule( command );
    
    return true;    
    
}

bool sqc_gift_controller::on_select_user_for_gift(
	const sqc_string& choose_user_id,
    sqc_available_gift::sptr ptr ) {
    
    const sqc_string user_id			= "";
    const int item_id					= ptr->id();
    const sqc_string second_user_id		= choose_user_id;
    
	using namespace processor;
	sqc_command_ptr  command( new sqc_send_gift_command( user_id, item_id, second_user_id ) );
	country_framework().cmd_processor().schedule( command );

    return true;
}

END_NAMESPACE_SQC_FRAMEWORK
