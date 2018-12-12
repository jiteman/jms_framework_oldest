#include "milk_server.h"
#include "milk_controls.h"

#include "animation/animation_server.h"

NAMESPACE_MILK

//
// milk_window_server implementation
//
milk_window_server::milk_window_server( surf_graphics_server &s, milk_theme &t ) 
    : graphics( s )
    , theme( t )
    , need_redraw( false ) 
    , tick_count( 0 )
{
	m_animation_server = new sqc::animation::animation_server();
}

milk_window_server::~milk_window_server() {
	delete m_animation_server;
}

void milk_window_server::init_desktop() {
    desktop.reset( new milk_desktop( *this ) );
}

void milk_window_server::render() {
    //PROFILE_ENTRY( "milk_window_server::render" );
    surf_context_ptr    ctx  = get_graphics().create_context();
    desktop->handle_render( ctx );
    
    need_redraw = false;
}

bool milk_window_server::need_render() const {
    return need_redraw;
}

void milk_window_server::handle_timer( surf_ddword ticks ) {
    
    PROFILE_ENTRY( "milk_window_server::handle_timer" );
    
    tick_count = ticks;
    
    if ( desktop ) {
	    desktop->handle_timer( tick_count );
    }
    
    /*if( need_redraw ) {
        render();
        need_redraw = false;
    }*/
	
	if (m_animation_server) {
		if (m_animation_server->handle_timer(ticks))
			need_redraw = true;
	}
}

bool milk_window_server::get_bypass_current_click() const {
    return bypass_current_click;
}


bool milk_window_server::handle_touch( milk_touch_info const &touch ) {
    if( touch.action == touch_action_release ) {
        surf_info() << "release";
    }
    //
    // find the root of touch handlers
    //
	milk_widget_ptr active_widget = desktop;
    {
		// has modal dialog?
		dialogs_list::const_reverse_iterator last = modal_dialogs.rbegin();
		if ( last != modal_dialogs.rend() ) {
			active_widget = *last;
		}
	}
    
    bool    processed = false;
    
    //
    // process capture
    //
    bool    bypass_current_click = false;
    if( capture_widget ) {
        bypass_current_click = true;

        milk_touch_info local_touch( touch );
        local_touch.tick = tick_count;
        
        for( int n = 0; n != local_touch.point_count; ++n ) {
            local_touch.points[n] = capture_widget->screen_to_client( local_touch.points[n] );
        }
        
        processed |= capture_widget->handle_touch( local_touch, false );
	}
    
    //
    // process normal (not capured) handlers
    //
    if( active_widget ) {
        milk_touch_info local_touch( touch );
        local_touch.tick = tick_count;

        for( int n = 0; n != local_touch.point_count; ++n ) {
            local_touch.points[n] = active_widget->screen_to_client( local_touch.points[n] );
        }
        
        processed |= active_widget->handle_touch( local_touch, bypass_current_click );
    }
    
    bypass_current_click = false;
    
    return processed;
        
}

void milk_window_server::set_device_info( milk_device_info const &info ) {
    device_info = info;
    desktop->set_rect( surf_rect( 0, 0, device_info.screen_size.cx, device_info.screen_size.cy ) );
    redraw();
}

void milk_window_server::redraw() {
    need_redraw = true;
}

milk_desktop_ptr milk_window_server::get_desktop() {
    return desktop;
}

surf_ddword milk_window_server::get_tick_count() {
    return tick_count;
}

milk_theme &milk_window_server::get_theme() {
    return theme;
}

surf_graphics_server &milk_window_server::get_graphics() {
    return graphics;
}

void milk_window_server::set_capture( milk_widget_ptr ptr ) {
    capture_widget = ptr;
}

void milk_window_server::release_capture( milk_widget_ptr ptr ) {
    if( ptr == capture_widget ) {
        capture_widget.reset();
    }
}

void milk_window_server::activate_modal( milk_dialog_ptr ptr ) {
	modal_dialogs.push_back( ptr );
}

void milk_window_server::deactivate_modal( milk_dialog_ptr ptr ) {
	if ( modal_dialogs.empty() ) {
		milk_assert( false );
		return;
	}
	
    for ( dialogs_list::iterator it = modal_dialogs.begin();
	    it != modal_dialogs.end(); ++it ) {
        if ( *it == ptr ) {
        	modal_dialogs.erase( it );
            return;
        }
    }

	milk_assert( false );
}

void milk_window_server::close_modals( milk_dialog_ptr ptr_first ) {
	dialogs_list close_dialogs;
    
    bool find = false;
    for ( dialogs_list::reverse_iterator it = modal_dialogs.rbegin();
	    it != modal_dialogs.rend(); ++it ) {
        
        if ( !find ) {
	        find = ( ptr_first == *it );
        }
        
        if ( find ) {
        	close_dialogs.push_back( *it );
        }
    }
    
    for ( dialogs_list::iterator it = close_dialogs.begin();
    	it != close_dialogs.end(); ++it ) {
        it->get()->end_dialog();
    }
}

END_NAMESPACE_MILK