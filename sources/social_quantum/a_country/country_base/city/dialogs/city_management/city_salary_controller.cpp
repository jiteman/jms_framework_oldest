/*
 *  city_salary_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "city_salary_controller.h"
#include "city/city_framework.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

city_salary_controller::city_salary_controller() {
}

city_salary_controller::~city_salary_controller() {
}
 
sqc_game_ptr city_salary_controller::get_game() {
	sqc_framework_base& framework = country_framework();
    sqc_game_ptr game = framework.game();
    if ( !game ) {
    	sqc_assert( false );
        return sqc_game_ptr();
    }
    return game;
}
   
void city_salary_controller::get_scene_info(
	sqc_common_scene_info& scene_info ) {

    sqc_game_ptr game = get_game();
    if ( !game ) {
    	sqc_assert( false );
        return;
    }
    game->fill_common_info( scene_info );
}

bool city_salary_controller::buy( sqc_salary salary ) {

    const sqc_string user_id			= framework().networks().get_user_id();
    const sqc_string object_type		= get_object_type( salary );
    const sqc_point  create_point;
    const bool rotation					= false;
    
	using namespace processor;
	sqc_command_ptr  command( new sqc_create_command( user_id, object_type, create_point, rotation ) );
	country_framework().cmd_processor().schedule( command );

	return true;
}

bool city_salary_controller::on_friend_selected(
	const sqc_string& friend_id, const sqc_salary salary ) {

    const sqc_string user_id		= framework().networks().get_user_id();
	const sqc_string object_type	= get_object_type( salary );
    const sqc_string second_user_id = friend_id;

	using namespace processor;
	sqc_command_ptr  command( new sqc_send_shop_gift_command( user_id, object_type, second_user_id ) );
	country_framework().cmd_processor().schedule( command );

	return true;
}

bool city_salary_controller::gift( sqc_salary salary ) {

    city_gift_salary_controller_ptr controller( 
    		new city_gift_salary_controller(
             std::tr1::bind( &city_salary_controller::on_friend_selected,
                        				this,
                                        _1,
                                        salary ) ) );
            
    if ( !controller ) {
    	return false;
    }
    sqc::city::city_framework().dialogs().show_select_preson_dialog( controller );
    
	return true;
}

sqc_string city_salary_controller::get_object_type( 
	const sqc_salary salary ) {

	sqc_stringstream out;
    out << sqc_text( "city_automate" ) << (int)salary;
	return out.str();
}


//
// gift salary
//
city_gift_salary_controller::city_gift_salary_controller(
    select_person_callback cb )
    : m_callback( cb ) {
}

bool city_gift_salary_controller::on_person_select( const sqc_string& id ) {
	if ( !m_callback ) {
	    return false;
    }
	return m_callback( id );    
}

sqc_string city_gift_salary_controller::get_button_caption() {
	return framework().strings().load( "*CommonGiftButtonText", "Gift" );
}

END_NAMESPACE_SQC_FRAMEWORK
