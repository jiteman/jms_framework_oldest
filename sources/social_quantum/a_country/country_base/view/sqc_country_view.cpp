/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_country_view.h"
#include "country_base/sqc_framework_base.h"

using namespace std::tr1::placeholders;


NAMESPACE_SQC_FRAMEWORK

sqc_country_view::sqc_country_view( 
	milk::milk_widget_ptr p, 
    sqc_game_ptr g ) 
		: milk::milk_widget( p ) 
        , m_game( g )
        , m_notify_connection( 0 ) {
}
    
sqc_country_view::~sqc_country_view() {
}

void sqc_country_view::on_create() {
    milk::milk_widget::on_create();    
    
    m_window_ctx = framework().windows_factory().create_window_ctx();
    
    m_notify_connection = framework().notify_center().subscribe( 
        std::tr1::bind( &sqc_country_view::notify_callback, this, _1, _2 ) );
}

void sqc_country_view::on_destroy() {
	framework().notify_center().unsubscribe( m_notify_connection );
    milk::milk_widget::on_destroy();
}

void sqc_country_view::render( surf::surf_context_ptr ctx ) {
    if( m_game ) {
        m_game->render( ctx );
    }
}

void sqc_country_view::on_rotate_pressed() {
    tools::sqc_tools_controlles &controller = country_framework().tools();
    controller.process_action( tools::tool_action_rotate, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void sqc_country_view::on_delete_pressed() {
    tools::sqc_tools_controlles &controller = country_framework().tools();
    controller.process_action( tools::tool_action_delete, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void sqc_country_view::on_warehouse_pressed() {
}

void sqc_country_view::on_market_pressed() {
    tools::sqc_activate_tool_arg arg = {};    
    tools::sqc_tools_controlles &controller = country_framework().tools();
    controller.activate_tool( tools::tool_type_buy, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void sqc_country_view::update_toolbar_controls() {
}

void sqc_country_view::update_top_gui() {
}

 // notification callback
void sqc_country_view::notify_callback( 
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    // TODO: change to global constant!!!
    if ( "framework" == provider_id ) {
    	if ( "tool_activated" == event_id ) {
        	update_toolbar_controls();
        }
    }
    
    if( provider_id == country_provider_id ) {
        if( event_id == country_field_changed_event ) {
        	update_top_gui();
            update_toolbar_controls();
        }
    }
}

sqc_scene_view_ptr sqc_country_view::scene_view() {
    sqc_assert( m_ptr_scene_view );
    return m_ptr_scene_view;
}

void sqc_country_view::switch_to_default_tool() {
    tools::sqc_tools_controlles &controller = country_framework().tools();
    tools::sqc_activate_tool_arg arg = {}; 
    arg.apply_changes = false;
    controller.activate_tool( tools::tool_type_multi, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

END_NAMESPACE_SQC_FRAMEWORK