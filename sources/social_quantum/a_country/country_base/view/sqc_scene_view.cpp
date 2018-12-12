/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "country_base/sqc_framework_base.h"
#include "sqc_scene_view.h"
#include "sqc_country_view.h"
#include "sqc_bubble_def.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK 

sqc_scene_view::sqc_scene_view( milk::milk_widget_ptr p, sqc_field_ptr f ) 
    : milk::milk_scroll_zoom_area( p )
    , m_field( f )
    , m_scroll_initialized( false )
{
//    set_limited_wait( true );
//    set_scroll_childrens( true );
	m_field_update_time_stamp = clock_msec();
    m_last_touch_id = -1;
}

sqc_scene_view::~sqc_scene_view() {
}

void sqc_scene_view::on_object_tooltip( const sqc_game_object_ptr& obj ) {
	const sqc_tooltips_data& tooltips = obj->get_tooltips();
	if (!tooltips.empty()) {
		surf::surf_rect obj_rect = obj->get_display_rect(*this, false);
		m_tooltips_mgr->add_tooltips( tooltips , obj_rect.center());
	}
}

void  sqc_scene_view::set_wait_update_object(int new_object_id) {
    
    sqc_game_object_ptr old_object = m_field->get_object_by_id(m_last_object_id);
    
    if (old_object) {
        old_object->set_object_state(object_state_wait_update);
        old_object->reload_textures();
    }
    
    m_last_object_id = new_object_id;
}

void sqc_scene_view::on_notify( const sqc_provider_id& provider_id, const sqc_event_id& event_id, const sqc_event_value value ) {
    
    if( provider_id == country_provider_id ) {
        if( event_id == country_field_changed_event ) {
            surf::surf_rect rect = m_field->calc_rect( *this );
            set_scroll_area( rect );
            
            if( !m_scroll_initialized ) {
                surf::surf_point  default_pos = m_field->calc_default_pos( *this );
                set_scroll_pos( default_pos, true );
                
                m_scroll_initialized = true;
				on_scroll();
            }
            
            generate_earth();

            // check death of selected object
            if(m_selected_object && m_selected_object != m_field->get_object_by_id(m_selected_object->get_id()) ) {
                set_selected_object(sqc_game_object_ptr(),sqc_game_object_selection_type_none);
                close_bubble();
            }

            invalidate();
			
			m_field_update_time_stamp = clock_msec();
			
			framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );
            
                
            
            if (m_bubble)
				m_bubble->on_field_updated( m_field_update_time_stamp );
            
            
            base_framework.tools().on_field_changed(*m_tool_context.get(), *this);
			
			
			if (m_tooltips_mgr) 
				m_field->foreach_object( std::tr1::bind( &sqc_scene_view::on_object_tooltip, this, _1) );
        }
    }
    
    if (processor::command_processor_provider_id == provider_id)
    {        
        if (processor::command_processor_command_progress_event == event_id || !m_last_object_id) {
            
            set_wait_update_object(value);
            
            sqc_game_object_ptr object = m_field->get_object_by_id(value);
            if (!object) { return; }
            
            framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );
            object->set_object_state(object_state_progress);
            object->set_progress_delay(base_framework.cmd_processor().get_command_delay());
        }
        else if (processor::command_processor_command_queued_event == event_id) {
            sqc_game_object_ptr object = m_field->get_object_by_id(value);
            if (!object) { return; }
            object->set_object_state(object_state_queued);
        }
        else if (processor::command_processor_command_all_completed_event == event_id) {
            set_wait_update_object(0);
            return;
        }
    }    
}

void sqc_scene_view::on_create() {
    milk::milk_scroll_zoom_area::on_create();
    
    m_window_ctx = framework().windows_factory().create_window_ctx();
    m_notify_connection = framework().notify_center().subscribe( std::tr1::bind( &sqc_scene_view::on_notify, this, _1, _2, _3 ) );
    
    
    framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );
    
    milk::milk_widget_ptr   parent_view = get_parent();
    sqc_country_view_ptr    country_view = std::tr1::static_pointer_cast<sqc_country_view>( parent_view);
    
    
    m_tool_context.reset( new tools::sqc_tool_adapter_impl( 
                                                           *this, 
                                                           *country_view.get(),
                                                           *m_field.get(), 
                                                           base_framework.cmd_processor(), 
                                                           *base_framework.object_factory().get()
                                                           ) );
    
    tools::sqc_activate_tool_arg    arg;
    base_framework.tools().activate_tool( tools::tool_type_multi, arg, *m_tool_context.get(), *this );
}

void sqc_scene_view::on_destroy() {
    framework::framework().notify_center().unsubscribe( m_notify_connection );
    
    milk::milk_scroll_zoom_area::on_destroy();
}


void sqc_scene_view::on_timer( surf::surf_ddword tick ) {
    if( framework().texture_proxy().need_to_redraw() ) {
        invalidate();
    }
    milk::milk_scroll_zoom_area::on_timer( tick );
	if (m_object_selection && m_object_selection->need_redraw())
		invalidate();
    framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );

    if (base_framework.tools().on_timer( tick, *m_tool_context.get(), *this ))
        invalidate();
}

bool sqc_scene_view::on_touch( milk::milk_touch_info const &touch ) {
    if (touch.point_count>1) return false;
    framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );
    if( touch.action == milk::touch_action_press ) {
        m_last_touch_id = touch.points_id[0];
        sqc_info() << "sqc_scene_view : handle press with id : " << m_last_touch_id << sqc_endl();
        return base_framework.tools().on_touch_down( touch.points[0], *m_tool_context.get(), *this );
    }
    // filter only full touches
    if (m_last_touch_id!=touch.points_id[0])
        return false;
    if( touch.action == milk::touch_action_release ) {
        sqc_info() << "sqc_scene_view : handle release with id : " << touch.points_id[0] << sqc_endl();
        return base_framework.tools().on_touch_up( touch.points[0], *m_tool_context.get(), *this );
    }
    else if( touch.action == milk::touch_action_move ) {
        return base_framework.tools().on_touch_move( touch.points[0], *m_tool_context.get(), *this );
    }
    
    return false;
}

void sqc_scene_view::on_scroll() {
    framework::sqc_framework_base  &base_framework = static_cast<framework::sqc_framework_base  &>( framework() );
    base_framework.tools().on_scroll( get_scroll_pos(), *m_tool_context.get(), *this );
    generate_earth();
	if (m_bubble) {
		update_bubble_pos();
	}
	if (m_tooltips_mgr) {
		m_tooltips_mgr->set_scroll( get_scroll_pos() );
		m_tooltips_mgr->set_zoom( get_zoom() );
	}
}


void sqc_scene_view::generate_earth()
{
    if ( m_field ) 
    {
		m_field->prepare_back( *this );
    }
}


void sqc_scene_view::render( surf::surf_context_ptr ctx ) {
    
    framework().texture_proxy().on_pre_render();
    

	surf::surf_transform tr = ctx->get_transform();
	
	ctx->set_transform(tr.scaled(get_zoom()));
	
    if( m_field ) {
        m_field->render( ctx, *this );
    }
    
	ctx->set_transform(tr);
	
	if ( m_tooltips_mgr )
		m_tooltips_mgr->render( ctx );
	
    /*
    if (m_earth) {
    	m_earth->render(ctx, *this );
    }
    */
    /*
    if( m_selected_object ) {
        m_selected_object->render( ctx, *this, true );
    }*/

    framework().texture_proxy().on_post_render();
}

surf::surf_val sqc_scene_view::get_zoom() const {
    return get_zoom_value();
}

surf::surf_nsize sqc_scene_view::get_screen_size(bool with_zoom) const {
    surf::surf_rect rect = get_client_rect();
	if (with_zoom) {
		rect.cx/=get_zoom();
		rect.cy/=get_zoom();
	}
    return surf::surf_nsize( (int)rect.cx , (int)rect.cy  );
}

surf::surf_point sqc_scene_view::field_to_screen( sqc_point const &p, sqc_coord_convert_mode mode , bool center ) const {
    static const surf::surf_size cell_size = get_cell_size();
    
    surf::surf_point    result;
    
    result.x = (p.x*cell_size.cx + p.y*cell_size.cx) ;
    result.y = (-p.x*cell_size.cy + p.y*cell_size.cy) ; 
    
    if (center) {
        result.x+= cell_size.cx;
    }
    
    if ( mode==sqc_coord_convert_mode_draw_no_scroll) {
	} else if( mode == sqc_coord_convert_mode_draw ) {
        surf::surf_point    scroll_pos = get_scroll_pos()/get_zoom();
        result.x -= scroll_pos.x;
        result.y -= scroll_pos.y;
    } else if( mode == sqc_coord_convert_mode_select ) {
		result*=get_zoom();
		result-=get_scroll_pos();
	} else if( mode == sqc_coord_convert_mode_select_no_scroll ) {
		result*=get_zoom();
	}
    
    return result;
}

sqc_point sqc_scene_view::screen_to_field( surf::surf_point const &pt, bool strong ) const {
    static const surf::surf_size cell_size = get_cell_size();
    surf::surf_point    pos = get_scroll_pos() + pt;
    pos/=get_zoom();
	
    sqc_point result;
    
    if( strong ) {
        result.x = floor((pos.x/cell_size.cx - pos.y/cell_size.cy)/(2));
        result.y = floor((pos.x/cell_size.cx + pos.y/cell_size.cy)/(2));
    }
    else {
        result.x = floor((pos.x/cell_size.cx - pos.y/cell_size.cy)/(2)+.5);
        result.y = floor((pos.x/cell_size.cx + pos.y/cell_size.cy)/(2)+.5);
    }
    
    return result;
}

//
//
//
sqc_game_object_ptr sqc_scene_view::get_selected_object() {
    return m_selected_object;
}
void sqc_scene_view::set_selected_object( sqc_game_object_ptr object , sqc_game_object_selection_type type) {
	m_selected_object = object;
	if (m_object_selection) {
		m_object_selection->set_object( object , type);
	}
    invalidate();
}


/// bubbles
sqc_bubble_ptr sqc_scene_view::create_bubble( sqc_bubble_content const &content )  {
	return sqc_bubble_ptr();
}

void sqc_scene_view::show_bubble( surf::surf_point const &pos, sqc_bubble_content const &content ) {
	close_bubble();
	m_bubble_pos = pos;
	m_bubble = create_bubble(content);
	update_bubble_pos();
	m_bubble->on_field_updated( m_field_update_time_stamp );
}

void sqc_scene_view::update_bubble_pos() {
	if (!m_bubble) return;

    surf::surf_point screen_pos = m_bubble_pos*get_zoom() - get_scroll_pos();
    m_bubble->move(screen_pos);
}

void sqc_scene_view::close_bubble() {
	if (m_bubble)
		remove_child(m_bubble);
	m_bubble = sqc_bubble_ptr();
}

bool sqc_scene_view::get_bubble_visible() const {
	return m_bubble;
}


END_NAMESPACE_SQC_FRAMEWORK