/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "country_base/sqc_framework_base.h"
#include "city/city_framework.h"
#include "city_scene_view.h"
#include "city_bubble.h"
#include "city_tooltips.h"
#include "sqc_city_objects.h"


NAMESPACE_SQC_FRAMEWORK

sqc_city_scene_view::sqc_city_scene_view( milk::milk_widget_ptr p, sqc_field_ptr f )
: sqc_scene_view( p, f ) {
}

sqc_city_scene_view::~sqc_city_scene_view() {
}

void sqc_city_scene_view::on_create() {
    sqc_scene_view::on_create();
	m_object_selection = sqc_object_selection_ptr( new sqc_object_selection( "selection_pattern", 4,2 ) );
	m_field->set_object_selection( m_object_selection );
	m_tooltips_mgr = sqc_tooltips_manager_ptr( new sqc_city_tooltips_manager( ) );
}

void sqc_city_scene_view::render( surf::surf_context_ptr ctx ) {
    sqc_scene_view::render( ctx );
}

surf::surf_size sqc_city_scene_view::get_cell_size() const {
    return surf::surf_size( 50, 25 );
}

sqc_bubble_ptr sqc_city_scene_view::create_bubble( sqc_bubble_content const &content ) {
	sqc_city_bubble_ptr bubble = sqc_city_bubble_ptr(new sqc_city_bubble( shared_from_this() ) );
	bubble->set_content( content );
	add_child_at_index(bubble, bubble->get_rect(),0);
	return bubble;
}

void sqc_city_scene_view::on_notify( const sqc_provider_id& provider_id, const sqc_event_id& event_id, const sqc_event_value value ) {
    sqc_scene_view::on_notify(provider_id, event_id, value);
    
    if (processor::command_processor_provider_id == provider_id) {
        
        city::sqc_city_object_base_ptr object =
                std::tr1::static_pointer_cast<city::sqc_city_object_base>(m_field->get_object_by_id(value));
        
        if (!object) {
            return;
        }
        
        object->reload_textures();
    }else if ( provider_id=="framework" ) {
        if ( event_id == "tool_activated" ) {
            tools::sqc_tools_controlles &controller = country_framework().tools();
            m_field->set_objects_no_status( controller.get_active_tool() != tools::tool_type_multi);
        }
    }
}

END_NAMESPACE_SQC_FRAMEWORK