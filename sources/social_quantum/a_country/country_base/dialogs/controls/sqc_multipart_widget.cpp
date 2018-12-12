/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_multipart_widget.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK


//
// sqc_city_top_gui implementation
//
sqc_multipart_widget::sqc_multipart_widget(
    milk::milk_widget_ptr p, 
    sqc_window_factory_ctx_ptr window_ctx )
    : milk::milk_widget( p )
    , m_window_ctx( window_ctx )
    , m_freeze_parts_count( 0 )
    , m_enable_move( true )
    , m_visible_count( 0 )
    , m_start_tick( 0 )
    , m_start_x( 0 )
    , m_end_x( 0 )
    , m_animation_step( 1*30 )
    , m_dragging( false )
    , m_start_in_active_rect( false )
{
    m_have_to_hide_invisible_childs = false;
}

sqc_multipart_widget::~sqc_multipart_widget() {
}

void sqc_multipart_widget::set_part_count( const unsigned count ) {    
    m_endpoints.resize( count );
    m_visible_count = count;
}

unsigned sqc_multipart_widget::get_part_count() const {
	return m_endpoints.size();
}

void sqc_multipart_widget::set_part_endpoint( const unsigned part_idx, const surf::surf_val& endpoint ) {    
    if ( part_idx >= m_endpoints.size() ) {
    	sqc_assert( false );
        return;
    }
    
    m_endpoints[ part_idx ] = endpoint;
}

void sqc_multipart_widget::set_enable_move( const bool enable ) {
    m_enable_move = enable;
}

void sqc_multipart_widget::set_freeze_count( const unsigned freeze_parts_count ) {
	m_freeze_parts_count = freeze_parts_count;
}

unsigned sqc_multipart_widget::get_freeze_count() const {
	return m_freeze_parts_count;
}

void sqc_multipart_widget::set_visible_count( const unsigned visible_parts_count ) {    
	const unsigned idx = visible_parts_count - 1;
    
    if ( idx > m_endpoints.size() ) {
    	sqc_assert( false );
        return;
    }

    if ( visible_parts_count < m_freeze_parts_count ) {
    	return;
    }

	m_start_tick = get_server().get_tick_count();
	m_start_x = get_rect().x;    
    m_end_x	= get_rect().cx - m_endpoints[ idx ];    
    m_visible_count = visible_parts_count;    
    on_visible_count_change();
}

unsigned sqc_multipart_widget::get_visible_count() const {
	return m_visible_count;
}

void sqc_multipart_widget::set_animation_step( const surf::surf_val step ) {
    m_animation_step = step;
}

void sqc_multipart_widget::on_visible_count_change() {
}

void sqc_multipart_widget::handle_timer( const surf::surf_ddword tick ) {    
    if ( m_start_tick ) {
	    surf::surf_rect rc_this = get_rect();
        surf::surf_val current_x = rc_this.x;

		if ( m_start_x < m_end_x ) { // make short
            current_x += m_animation_step * (tick-m_start_tick) * 0.001;
			m_start_tick = tick;
            
            if ( current_x >= m_end_x ) {
            	current_x = m_end_x;
                m_start_tick = 0;
            }
        } else { // make lower
            current_x -= m_animation_step * (tick-m_start_tick) * 0.001;;
            m_start_tick = tick;
			
            if ( current_x <= m_end_x ) {
            	current_x = m_end_x;
                m_start_tick = 0;
            }
        }

        rc_this.x = current_x;
        set_rect( rc_this );

        if ( m_have_to_hide_invisible_childs ) {
            const surf::surf_val right_margin_x = get_rect().cx - current_x + 1;
            
            for ( milk::milk_widget_list::iterator child_iterator = childs.begin(); child_iterator != childs.end(); ++child_iterator ) {
                ( *child_iterator )->set_visible( ( *child_iterator )->get_rect().top_right().x < right_margin_x ? true : false );
            }
            
            on_visible_count_change();
        }
        
        invalidate();
    }
    
    milk::milk_widget::handle_timer( tick );
}

bool sqc_multipart_widget::handle_touch( const milk::milk_touch_info &info, bool bypass_click ) {    
    if ( milk_widget::handle_touch( info, bypass_click ) ) {
    	return true;
    }
    
    if ( m_active_rect.cx == 0 || m_active_rect.cy == 0 ) {
    	return true;
    }
    
    if ( info.action == milk::touch_action_press ) {
        if( !m_active_rect.point_in_rect( info.points[ 0 ] ) ) {
            return false;
        }
                                                                
        m_start_in_active_rect = true;        
        get_server().set_capture( shared_from_this() );
        m_drag_start_point = client_to_screen( info.points[ 0 ] );
        m_drag_start_window_rect = get_rect();
    } else if ( info.action == milk::touch_action_move ) {    
        if ( m_start_in_active_rect ) {
            surf::surf_val offset = client_to_screen( info.points[ 0 ] ).x - m_drag_start_point.x;
            
            if ( fabs( offset ) > 5 ) {
                surf::surf_rect rc = m_drag_start_window_rect;
                rc.x += offset;
                set_rect( rc );                
                m_dragging = true;                
                invalidate();
            }
        }
    } else if ( info.action == milk::touch_action_release ) {
        get_server().release_capture( shared_from_this() );
        surf::surf_val visible_width = get_rect().cx - get_rect().x;
        m_start_in_active_rect = false;
        
        if ( m_dragging ) {
            m_dragging = false;
            int visible_count = 0;
            surf::surf_val prev_part_y = 0;
            
            for ( endpoints::const_iterator it = m_endpoints.begin(); it != m_endpoints.end(); ++it ) {
                surf::surf_val part_y = *it;
                
                if ( part_y < visible_width ) {
                    prev_part_y = part_y;
                    ++visible_count;
                    continue;
                }
            
                surf::surf_val part_width = part_y - prev_part_y;
                surf::surf_val invisible_part_width = part_y - visible_width;
                sqc_assert( invisible_part_width >= 0 );

                if ( invisible_part_width < part_width / 2 ) {
                    ++visible_count;
                }
                
                break;
            }
            
            const unsigned freeze_count = get_freeze_count();
            
            if ( visible_count < freeze_count ) {
                visible_count = freeze_count;
            }
            
            set_visible_count( visible_count );
            
        } else {        
            if ( !m_active_rect.point_in_rect( info.points[0] ) ) {
                return false;
            }
             
            if ( get_visible_count() == get_freeze_count() ) {
                set_visible_count( get_part_count() );
            } else {
                set_visible_count( get_visible_count() - 1 );
            }
        }
    }
    
    return true;
}

void sqc_multipart_widget::set_active_rect( 
	const surf::surf_rect& rc ) {
    m_active_rect = rc;
}

void sqc_multipart_widget::set_have_to_hide_invisible_childs( const bool have_to_hide_invisible_childs ) {
    m_have_to_hide_invisible_childs = have_to_hide_invisible_childs;
}


END_NAMESPACE_SQC_FRAMEWORK