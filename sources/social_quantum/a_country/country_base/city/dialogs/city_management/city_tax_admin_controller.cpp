/*
 *  city_tax_admin_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "city_tax_admin_controller.h"
#include "country_base/sqc_framework_base.h"

NAMESPACE_SQC_FRAMEWORK

city_tax_admin_controller::city_tax_admin_controller() {
}

city_tax_admin_controller::~city_tax_admin_controller() {
}

sqc_game_ptr city_tax_admin_controller::get_game() {
	sqc_framework_base& framework = country_framework();
    sqc_game_ptr game = framework.game();
    if ( !game ) {
    	sqc_assert( false );
        return sqc_game_ptr();
    }
    return game;
}
    
void city_tax_admin_controller::get_scene_info(
	sqc_common_scene_info& scene_info ) {

    sqc_game_ptr game = get_game();
    if ( !game ) {
    	sqc_assert( false );
        return;
    }
    game->fill_common_info( scene_info );
}

bool city_tax_admin_controller::has_tax_admin() {

	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
	return !!scene_info.tax_admin_object_id;
}

sqc_int	city_tax_admin_controller::get_tax_rate() {
	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
	return scene_info.tax_rate;
}

sqc_int city_tax_admin_controller::get_max_population() {
	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
    return scene_info.max_population;
}

bool city_tax_admin_controller::buy_tax_admin( const sqc_string& klass ) {
    tools::sqc_activate_tool_arg arg = {};

    arg.user_id = framework().networks().get_user_id();
    arg.gift = false;
    arg.purchased_object_type=klass;
    tools::sqc_tools_controlles &controller = country_framework().tools();
    sqc_scene_view_ptr ptr_scene_view = country_framework().scene_view();

    controller.activate_tool( tools::tool_type_buy, arg, ptr_scene_view->get_tool_context(), *ptr_scene_view.get() );
    
	return true;
}

bool city_tax_admin_controller::set_tax_rate( const sqc_int tax_rate ) {

	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );

    const sqc_string user_id			= "";
    const int item_id					= scene_info.tax_admin_object_id;
    
	using namespace processor;
	sqc_command_ptr  command( new sqc_change_tax_command( user_id, item_id, tax_rate ) );
	country_framework().cmd_processor().schedule( command );

	return true;	
}

END_NAMESPACE_SQC_FRAMEWORK
