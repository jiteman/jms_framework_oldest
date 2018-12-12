/*
 *  city_hall_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "city_hall_controller.h"
#include "city/city_framework.h"
#include "city_cityhall_settings_dlg_layout.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

city_hall_controller::city_hall_controller() {
 	// subscribe for events
    m_notify_connection = framework().notify_center().subscribe( 
    std::tr1::bind( &city_hall_controller::notify_callback, this, _1, _2 ) );
}

city_hall_controller::~city_hall_controller() {
	// unsubscribe
    framework().notify_center().unsubscribe( m_notify_connection );
}
  
void city_hall_controller::set_refresh_callback( refresh_callback cb ) {
	m_refresh_cb = cb;
}
  
sqc_game_ptr city_hall_controller::get_game() {
	sqc_framework_base& framework = country_framework();
    sqc_game_ptr game = framework.game();
    if ( !game ) {
    	sqc_assert( false );
        return sqc_game_ptr();
    }
    return game;
}

void city_hall_controller::get_scene_info(
	sqc_common_scene_info& scene_info ) {
    
    sqc_game_ptr game = get_game();
    if ( !game ) {
    	sqc_assert( false );
        return;
    }
    game->fill_common_info( scene_info );
}

bool city_hall_controller::has_city_hall() {

	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );
    
	return !!scene_info.city_hall_object_id;
}

bool city_hall_controller::buy_city_hall( const sqc_string& klass ) {

    tools::sqc_activate_tool_arg arg = {};

    arg.user_id = framework().networks().get_user_id();
    arg.gift = false;
    arg.purchased_object_type = klass;
    tools::sqc_tools_controlles &controller = country_framework().tools();
    sqc_scene_view_ptr ptr_scene_view = country_framework().scene_view();

    controller.activate_tool( tools::tool_type_buy, arg, ptr_scene_view->get_tool_context(), *ptr_scene_view.get() );
	return true;
}

bool city_hall_controller::fill_agent_info( 
	const sqc_string agent_id,
    const city_hall_agent_type_t type, 
    city_hall_agent_info& info ) {
	
    sqc_theme_size theme = framework().windows_factory().get_theme_size();
    
    using namespace city_dlg_layout::cityhall_settings_dlg;
    
    if ( city_hall_fiscal_agent == type ) {
    	info.description = framework().strings().load("*CityHallGather", "Collect");
    } else if ( city_hall_municipal_officer == type ) {
	    info.description = framework().strings().load("*CityHallPeoples", "Population Census");
    } else {
    	sqc_assert( false );
    }


    if ( agent_id.empty() || agent_id == sqc::city::none_agent_id ) {
    
		info.agent_id		= sqc::city::none_agent_id;
    	info.name			= framework().strings().load( "*CityHallNoOneHired", "No one hired" );
        info.local_avatar	= true;
        info.avatar			= no_one_hired_icon.at( theme );
        
    } else if ( agent_id == sqc::city::internal_fiscal_agent_id ) {
    
		info.agent_id		= sqc::city::internal_fiscal_agent_id;
    	info.name			= framework().strings().load( "*CityHallTaxAgent", "Fiscal Agent" );
        info.local_avatar	= true;
        info.avatar			= fiscal_agent_icon.at( theme );
        
    } else if ( agent_id == sqc::city::internal_municipal_oficer_id ) {
    
		info.agent_id		= sqc::city::internal_municipal_oficer_id;
    	info.name			= framework().strings().load( "*CityHallMunicipalityOfficer", "Municipality Officer" );
        info.local_avatar	= true;
        info.avatar			= municipality_officer_icon.at( theme );
    } else {
		
        info.agent_id		= agent_id;
		sqc_user_profile_ptr profile = country_framework().friends().find_friend( agent_id );
        if ( profile ) {
            info.name			= profile->get_first_name();
            info.local_avatar	= false;
            info.avatar			= profile->get_avatar_url();
        } else {
        	sqc_error() << "city_hall_controller: unable to find friend id:" << agent_id;
            info.agent_id		= sqc::city::none_agent_id;
            info.name			= framework().strings().load( "*CityHallNoOneHired", "No one hired" );
            info.local_avatar	= true;
            info.avatar			= no_one_hired_icon.at( theme );
            return false;
        }
    }

	return true;
}

//
//	fiscal agent
//
bool city_hall_controller::get_fiscal_agent( city_hall_agent_info& info ) {
    return fill_agent_info( get_current_fiscal_agent_id(), city_hall_fiscal_agent, info );
}

bool city_hall_controller::hire_fiscal_agent() {


    city_hall_agents_controller_ptr controller( 
    		new city_hall_agents_controller( city_hall_fiscal_agent,
             std::tr1::bind( &city_hall_controller::on_fiscal_agent_selected,
                        				this,
                                        _1 ) ) );
            
    if ( !controller ) {
    	return false;
    }
    sqc::city::city_framework().dialogs().show_select_preson_dialog( controller );
    return true;
}

bool city_hall_controller::on_fiscal_agent_selected( const sqc_string& agent_id ) {
	return run_cmd( agent_id, get_current_municipal_officer_id() );
}

bool city_hall_controller::fire_fiscal_agent() {
	return run_cmd( sqc::city::none_agent_id, get_current_municipal_officer_id() );
}

//
//	municipal oficer
//    
bool city_hall_controller::get_municipal_officer( city_hall_agent_info& info ) {
	return fill_agent_info( get_current_municipal_officer_id(), city_hall_municipal_officer, info );
}

bool city_hall_controller::hire_municipal_officer() {
	
    city_hall_agents_controller_ptr controller( 
    	new city_hall_agents_controller( city_hall_municipal_officer,
         std::tr1::bind( &city_hall_controller::on_municipal_officer_selected,
                        				this,
                                        _1 ) ) );
    if ( !controller ) {
    	return false;
    }
    
    sqc::city::city_framework().dialogs().show_select_preson_dialog( controller );
    return true;
}

bool city_hall_controller::on_municipal_officer_selected( const sqc_string& agent_id ) {
	return run_cmd( get_current_fiscal_agent_id(), agent_id );
}

bool city_hall_controller::fire_municipal_officer() {
	return run_cmd( get_current_fiscal_agent_id(), sqc::city::none_agent_id );
}

sqc_string city_hall_controller::get_current_fiscal_agent_id() {
	sqc::city::sqc_city_hall_ptr city_hall = get_city_hall();
    if ( !city_hall ) {
    	return sqc_text( "" );
    }
    return city_hall->get_fiscal_agent_id();
}

sqc_string city_hall_controller::get_current_municipal_officer_id() {
	sqc::city::sqc_city_hall_ptr city_hall = get_city_hall();
    if ( !city_hall ) {
    	return sqc_text( "" );
    }
    return city_hall->get_municipal_oficer_id();
}


bool city_hall_controller::refill_budget() {
	sqc::city::city_framework().dialogs().show_salary_dialog();
    return true;
}

sqc::city::sqc_city_hall_ptr city_hall_controller::get_city_hall() {
	
    //
    //	asserts cos don't use this controller without cityhall is exist on the field
    //
    
	sqc_int city_hall_id = 0;
	{
    	sqc_common_scene_info scene_info;
    	get_scene_info( scene_info );
        city_hall_id = scene_info.city_hall_object_id;
        if ( !city_hall_id ) {
            sqc_assert( false );
            return sqc::city::sqc_city_hall_ptr();
        }
    }
    
	sqc_game_ptr game = get_game();
    if ( !game ) {
    	sqc_assert( false );
        return sqc::city::sqc_city_hall_ptr();
    }
	
    sqc_field_ptr field = game->get_field();    
    if ( !field ) {
    	sqc_assert( false );
        return sqc::city::sqc_city_hall_ptr();
    }
    
    sqc_game_object_ptr object = field->get_object_by_id( city_hall_id );
    if ( !object ) {
    	sqc_assert( false );
        return sqc::city::sqc_city_hall_ptr();
    }
    
    sqc::city::sqc_city_hall_ptr city_hall = 
    		std::tr1::static_pointer_cast<sqc::city::sqc_city_hall>( object );
            
    return city_hall;
}

bool city_hall_controller::run_cmd(
    const sqc_string& fiscal_agent_id, 
    const sqc_string& municipal_oficer_id ) {
    
	sqc_common_scene_info scene_info;
    get_scene_info( scene_info );

    const sqc_string user_id	= "";
    const int item_id			= scene_info.city_hall_object_id;

	using namespace processor;
	sqc_command_ptr  command( new sqc_io_command( user_id, item_id, fiscal_agent_id, municipal_oficer_id ) );
	country_framework().cmd_processor().schedule( command );
	
    return true;
}


// notification callback
void city_hall_controller::notify_callback(
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
 	
    if ( processor::command_processor_provider_id == provider_id ) {
        if (  processor::command_processor_initial_xml_complete_event == event_id ) {
        	if ( m_refresh_cb ) {
            	m_refresh_cb();
            }
        }
    }
    
	if ( friends == provider_id ) {
        if ( friends_event_query_complete == event_id ) {
        	if ( m_refresh_cb ) {
            	m_refresh_cb();
            }
        }
    }    
}


//
//  controller for cityhall agents
//

city_hall_agents_controller::city_hall_agents_controller(
	city_hall_agent_type_t type, 
    select_person_callback cb )
    : m_agent_type( type )
    , m_callback( cb ) {
}

bool city_hall_agents_controller::on_person_select( const sqc_string& id ) {
	if ( !m_callback ) {
	    return false;
    }
	return m_callback( id );    
}

void city_hall_agents_controller::get_persons( sqc_person_info_list_type& persons ) {

	city_hall_agent_info agent_info;
    sqc_string agent_id;
    if ( city_hall_fiscal_agent == m_agent_type ) {
    	agent_id = sqc::city::internal_fiscal_agent_id;
    } else if ( city_hall_municipal_officer == m_agent_type ) {
	    agent_id = sqc::city::internal_municipal_oficer_id;
    } else {
    	sqc_assert( false );
    }

	city_hall_controller::fill_agent_info( agent_id, m_agent_type, agent_info );
    
    // add specific agent
    sqc_person_info person_info( agent_info.agent_id, 
    							 agent_info.name, 
                                 agent_info.avatar,
                                 0,// level
                                 agent_info.local_avatar );
    persons.push_back( person_info );
    
	sqc_select_person_controller::get_persons( persons );
}

sqc_string city_hall_agents_controller::get_button_caption() {
	return framework().strings().load( "*CityHallEmploy", "Hire" );
}


END_NAMESPACE_SQC_FRAMEWORK
