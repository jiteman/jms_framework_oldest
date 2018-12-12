/*
 *  milk_scroll_area.cpp
 *  aCountry
 *
 *  Created by Andrey Yamov on 6/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "milk_scroll_area.h"
#include "milk_server.h"

NAMESPACE_MILK

//
//
//
milk_scroll_area::milk_scroll_area( milk_widget_ptr p ) 
: milk_control( p )
, scroll_state( scroll_state_idle )
, last_timeout( 0 )
, scroll_childrens( false )
, limited_wait_for_scroll( false )
, enable_horizontal_scroll( true )
, enable_vertical_scroll( true )
, m_centered(false)
, m_small_scroll_enabled(true)
{
}

bool milk_scroll_area::handle_touch( milk_touch_info const &info, bool bypass_click ) {
    milk_metrics const &metrics = get_server().get_theme().get_metrics();
    
    PROFILE_ENTRY( "milk_scroll_area::handle_touch" );
    bool other_widgets_handled = false;
    if( !scroll_childrens ) {
        if( scroll_state != scroll_state_scrolling &&
            scroll_state != scroll_state_pre_scrolling ) {
            if( milk_control::handle_touch( info, bypass_click ) ) {
				if( info.action == touch_action_release ) {
					if (scroll_state == scroll_state_waiting_scroll) {
						scroll_state = scroll_state_idle;
						last_timeout = 0;
					}
				}
                return true;
            }
            other_widgets_handled = true;
        }
    }
    
    bool    processed = false;
    if( info.point_count == 1 ) {
        if( info.action == touch_action_press ) {
			if ( scroll_state == scroll_state_idle ||
				scroll_state == scroll_state_animation ) {
				surf_info() << "scroll area is prepared for scroll by " << info;
				
				last_touch_info = info;
				
				if( limited_wait_for_scroll ) {
					last_timeout = info.tick + metrics.scroll_timeout;
					scroll_state = scroll_state_delay_event;
				}
				else {
					last_timeout = 0;
					scroll_state = scroll_state_waiting_scroll;
					
                    if (!other_widgets_handled) {
                        milk_widget::handle_touch( info, bypass_click );
                        other_widgets_handled = true;
                    }
				}
				
				processed = true;
			}
        }
        else if( info.action == touch_action_move ) {
			if (last_touch_info.points_id[0]==info.points_id[0]) {
				if( scroll_state == scroll_state_delay_event ||
					scroll_state == scroll_state_waiting_scroll ) {
					surf_info() << "begin to scroll by " << info << ", pos = " << get_scroll_pos();
					
					scroll_state = scroll_state_pre_scrolling;
					
					handle_pre_scroll_begin();
					start_scroll_pos = info.points[0];
					
					surf_info() << "after process pos = " << get_scroll_pos();
					processed = true;
				}
				if( scroll_state == scroll_state_pre_scrolling  ) {
					surf_verbose() << "scroll area is pre-scrolled by " << info << " -> scroll pos = " << get_scroll_pos();
					
					surf_point  delta = last_touch_info.points[0] - info.points[0];
					handle_scroll( delta );
					last_touch_info = info;
					
					if( fabs( start_scroll_pos.x - info.points[0].x ) > metrics.scroll_start_delta ||
					   fabs( start_scroll_pos.y - info.points[0].y ) > metrics.scroll_start_delta )  
					{
						handle_scroll_begin();
					}
					
					processed = true;
				}
				if( scroll_state == scroll_state_scrolling  ) {
					surf_verbose() << "scroll area is scrolled by " << info << " -> scroll pos = " << get_scroll_pos();
					
					surf_point  delta = last_touch_info.points[0] - info.points[0];
					handle_scroll( delta );
					last_touch_info = info;
					
					processed = true;
				}
			}
        }
        else if( info.action == touch_action_release ) {
			if (last_touch_info.points_id[0]==info.points_id[0]) {
				if( scroll_state == scroll_state_delay_event ||
					scroll_state == scroll_state_waiting_scroll ) {
					surf_info() << "scroll area is receiving touch up during waiting for scroll, call down/up " << info;
					
                    /// WTF???
					if( scroll_state == scroll_state_delay_event ) {
						milk_control::handle_touch( last_touch_info, bypass_click );
                        other_widgets_handled = true;
					} else {
                        milk_control::handle_touch( info, bypass_click );
                        other_widgets_handled = true;
					}
                    
					scroll_state = scroll_state_idle;
					last_timeout = 0;
					
					processed = true;
				}
				else if( scroll_state == scroll_state_scrolling ||
						scroll_state == scroll_state_pre_scrolling ) {
					surf_info() << "scroll area finished scroll/up " << info;
					
					processed = (scroll_state == scroll_state_scrolling);
					
					surf_point  delta = last_touch_info.points[0] - info.points[0];
					handle_scroll( delta );
					handle_scroll_end();
					
					
				}
			}
        }
    }
    
    if( !processed ) {
        if( scroll_state == scroll_state_delay_event || 
           scroll_state == scroll_state_waiting_scroll ) {
            surf_info() << "scroll area is receiving event during waiting for scroll, call down " << info;
           
            if( scroll_state == scroll_state_delay_event ) {
                milk_widget::handle_touch( last_touch_info, bypass_click );
                other_widgets_handled = true;
            }
            scroll_state = scroll_state_idle;
            
            processed = true;
        }
        
        if( scroll_childrens ) {
            return milk_control::handle_touch( info, bypass_click );
        }
        else {
            if( !bypass_click ) {
                if (!other_widgets_handled) {
                    return milk_widget::handle_touch( info, false );
                } else 
                    return on_touch( info );
            }
            else {
                if (!other_widgets_handled) {
                    return milk_widget::handle_touch( info, true );
                }
            }
        }
        return processed;
    }
    return true;
}

void milk_scroll_area::on_timer( surf_ddword tick ) {
    PROFILE_ENTRY( "milk_scroll_area::on_timer" );
    
     if( scroll_state == scroll_state_delay_event ) {
        if( last_timeout && tick >= last_timeout ) {
            surf_info() << "scroll area is receiving timer event, call down " << last_touch_info;
            
            // no scroll
            if( milk_widget::handle_touch( last_touch_info, false ) ) {
                scroll_state = scroll_state_idle;
            }
            
            last_timeout = 0;
        }
    }
    else if( scroll_state == scroll_state_animation ) {
        surf_point delta = animated_scroll_pos - scroll_pos;
        if( fabs(delta.x) < .5 && fabs(delta.y) < .5 ) {
            set_scroll_pos( animated_scroll_pos, false );
            on_scroll();

            
            scroll_state = scroll_state_idle;
            surf_info() << "scroll animation is done, current position is " << get_scroll_pos();
        }
        else {
            milk_metrics const &metrics = get_server().get_theme().get_metrics();
            
            set_scroll_pos( scroll_pos + delta/metrics.scroll_animation_decrease_factor, false );
            on_scroll();
        }
    }
    else if( scroll_state == scroll_state_scrolling ||
            scroll_state == scroll_state_pre_scrolling ) {
        surf_point  current_pos = get_scroll_pos();
        surf_point delta = current_pos - last_history_point;
        last_history_point = current_pos;
        
        milk_metrics const &metrics = get_server().get_theme().get_metrics();
        if( scroll_history.size() > metrics.scroll_history_max_size ) {
            scroll_history.pop_front();
        }
        scroll_history.push_back( delta );
    }
//    bool need_to_redraw_self = false;
    milk_widget::on_timer( tick );
}

void milk_scroll_area::handle_pre_scroll_begin() {
    last_timeout = 0;
    scroll_history.clear();
    get_server().set_capture( shared_from_this() );
    
    last_history_point = get_scroll_pos();
}

void milk_scroll_area::handle_scroll_begin() {
    // send the cancel mode notification
    for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
        milk_widget_ptr child( *i );
        child->handle_cancel_mode();
    }
    
    last_timeout = 0;
    scroll_history.clear();
    get_server().set_capture( shared_from_this() );
    
    last_history_point = get_scroll_pos();
	scroll_state = scroll_state_scrolling;
}


void milk_scroll_area::handle_scroll_end() {
    get_server().release_capture( shared_from_this() );
    on_scroll_complete();
    scroll_history.clear();
}

void milk_scroll_area::handle_scroll( surf_point const &delta ) {
    
    if( scroll_history.empty()) {
        scroll_history.push_back( delta );
    }
    
    set_scroll_pos( get_scroll_pos() + delta, false );
    on_scroll();
}

void milk_scroll_area::render( surf_context_ptr ctx ) {
    milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();
    
    theme.draw_scroller( ctx, *this );
    
    milk_widget::render( ctx );
}

void milk_scroll_area::set_scroll_area( surf_rect const &r ) {
    scroll_area = r;
    scroll_pos = get_valid_scroll_pos( scroll_pos );
}

surf_rect milk_scroll_area::get_scroll_rect() const {
    return scroll_area;
}

void milk_scroll_area::set_scroll_pos( surf_point const &p, bool validate ) {
    scroll_pos = p;
    
    if( !enable_horizontal_scroll ) scroll_pos.x = 0;
    if( !enable_vertical_scroll ) scroll_pos.y = 0;
    
    if( validate ) {
        scroll_pos = get_valid_scroll_pos( scroll_pos );
    }
	
	if (!m_small_scroll_enabled) {
		surf_rect   visible_rect = get_rect();
		if( enable_horizontal_scroll && visible_rect.cx >= scroll_area.cx ) {
			if (m_centered) scroll_pos.x = scroll_area.x-(visible_rect.cx-scroll_area.cx)/2; else scroll_pos.x = scroll_area.x;
		}
		if( enable_vertical_scroll && visible_rect.cy >= scroll_area.cy )  {
			if (m_centered) scroll_pos.y =  scroll_area.y-(visible_rect.cy-scroll_area.cy)/2; else scroll_pos.y = scroll_area.y;
		}
	}
    
    invalidate();
}

surf_point milk_scroll_area::get_scroll_pos() const {
    return surf_point(int(scroll_pos.x),int(scroll_pos.y));
}


surf_point milk_scroll_area::get_valid_scroll_pos( surf_point point ) {
    surf_rect   visible_rect = get_rect();
    
    surf_point  result_pos = point;
    
	
	if( visible_rect.cx >= scroll_area.cx ) {
		if (m_centered) result_pos.x = scroll_area.x-(visible_rect.cx-scroll_area.cx)/2; else result_pos.x = scroll_area.x;
    } else if( result_pos.x < scroll_area.x ) result_pos.x = scroll_area.x;
    else if( result_pos.x > scroll_area.x + scroll_area.cx - visible_rect.cx ) result_pos.x = scroll_area.x + scroll_area.cx - visible_rect.cx;
    
    if( visible_rect.cy >= scroll_area.cy )  {
		if (m_centered) result_pos.y =  scroll_area.y-(visible_rect.cy-scroll_area.cy)/2; else result_pos.y = scroll_area.y;
    } else if( result_pos.y < scroll_area.y ) result_pos.y = scroll_area.y;
    else if( result_pos.y > scroll_area.y + scroll_area.cy - visible_rect.cy ) result_pos.y = scroll_area.y + scroll_area.cy - visible_rect.cy;
    
    return result_pos;
}

void milk_scroll_area::reset_scroll( ) {
	scroll_state = scroll_state_idle;
	scroll_history.clear();
}
void milk_scroll_area::animated_scroll( surf_point const &p ) {
    animated_scroll_pos = get_valid_scroll_pos( p );
    scroll_state = scroll_state_animation;
    
    surf_info() << "animated scroll to " << animated_scroll_pos << ", from = " << get_scroll_pos();
}

void milk_scroll_area::on_scroll() {
    
}

surf_point milk_scroll_area::calculate_dynamic_target() {
    surf_point  average_delta;
    
    if( scroll_history.size() ) {
        for( std::list<surf_point>::const_iterator i = scroll_history.begin(); i != scroll_history.end(); ++i ) {
            average_delta += *i;
        }
        
        average_delta /= scroll_history.size();
    }
    
    milk_metrics const &metrics = get_server().get_theme().get_metrics();
    average_delta *= metrics.scroll_dynamic_factor;
    
    surf_info() << "calculated dynamic scroll target " << average_delta << " by " << scroll_history.size() << " points";
    
    return average_delta;
}

void milk_scroll_area::on_scroll_complete() {
    // begin animation to valid pos
    animated_scroll( get_scroll_pos() + calculate_dynamic_target() );
}



milk_scroll_zoom_area::milk_scroll_zoom_area( milk_widget_ptr p ) 
: milk_scroll_area( p )
, m_zoom(1.0)
, m_in_zoom(false)
, m_animate_zoom(false)
{
	set_min_zoom(0.25);
	set_max_zoom(4.0);
}

void milk_scroll_zoom_area::set_min_zoom( surf::surf_val value ) {
	m_min_zoom = value;
	m_min_zoom_hard = value *0.75;
}

void milk_scroll_zoom_area::set_max_zoom( surf::surf_val value ) {
	m_max_zoom = value;
	m_max_zoom_hard = value *1.25;
}
 
bool milk_scroll_zoom_area::handle_touch( milk_touch_info const &info, bool bypass_click ) {
    PROFILE_ENTRY( "milk_scroll_zoom_area::handle_touch" );
	if (m_in_zoom && !m_animate_zoom) {
		if (info.action==touch_action_release) {
			on_end_zoom();
		} else if (info.action==touch_action_press) {
			/// getting more touches, bad
			on_end_zoom();
		} else if (info.action==touch_action_move) {
			// ok
			
			surf::surf_point finger_a = m_last_touch.points[0];
			surf::surf_point finger_b = m_last_touch.points[1];
			
			surf::surf_point move_finger_a = m_finger_a - finger_a;
			surf::surf_point move_finger_b = m_finger_b - finger_b;
			
			for (int i=0;i<info.point_count;i++) {
				if (info.points_id[i]==m_last_touch.points_id[0]) {
					move_finger_a = info.points[i]-m_last_touch.points[0];
				} else if (info.points_id[i]==m_last_touch.points_id[1]) {
					move_finger_b = info.points[i]-m_last_touch.points[1];
				} else {
					// hm...
					on_end_zoom();
					return true;
				}
			}
			/// ok, now calc zoom
			
			surf::surf_point old_center_pos = (finger_a+finger_b)*0.5;
			surf::surf_val old_len = (finger_b-finger_a).length();
			
			finger_a+=move_finger_a;
			finger_b+=move_finger_b;
			
			m_finger_a = finger_a;
			m_finger_b = finger_b;
			
			surf::surf_point new_center_pos = (finger_a+finger_b)*0.5;
			surf::surf_val new_len = (finger_b-finger_a).length();
			surf::surf_val zoom = new_len / old_len;
			
			append_zoom(new_center_pos, zoom);
			
		}
		return true;
	}
    if (info.point_count==1) {
		if (m_animate_zoom) {
			on_end_zoom();
		}
		return milk_scroll_area::handle_touch( info,bypass_click);
	}
	if (info.point_count==2) {
		if (info.action == touch_action_move) {
			/// begin zoom
			m_last_touch = info;
			m_finger_a = m_last_touch.points[0];
			m_finger_b = m_last_touch.points[1];
			m_initial_zoom_point = m_last_zoom_point = (m_finger_a+m_finger_b)*0.5;
			m_animate_zoom = false;
			on_begin_zoom();
			return true;
		}
	}
	return false;
}

void milk_scroll_zoom_area::on_begin_zoom() {
	m_in_zoom = true;
	m_last_zoom = m_zoom;
	m_last_scroll = get_scroll_pos();
	reset_scroll( );
	handle_scroll_begin();
}

void milk_scroll_zoom_area::append_zoom(  const surf::surf_point& pos, surf::surf_val zoom ) {
	m_last_zoom_point = pos;
	m_zoom = m_last_zoom*zoom;
	if (m_zoom<m_min_zoom_hard) {
		m_zoom = m_min_zoom_hard;
		zoom = m_zoom / m_last_zoom;
	}
	if (m_zoom>m_max_zoom_hard) {
		m_zoom = m_max_zoom_hard;
		zoom = m_zoom / m_last_zoom;
	}
	surf::surf_point delta = m_initial_zoom_point*zoom - m_initial_zoom_point;
	set_scroll_pos(m_last_scroll*zoom+delta-(pos-m_initial_zoom_point), false);
	on_scroll();
}

void milk_scroll_zoom_area::on_end_zoom() {
	m_in_zoom = false;
	m_last_scroll = get_scroll_pos();
	m_animate_zoom = false;
	
	if (m_zoom > m_max_zoom) {
		animated_zoom( m_max_zoom , m_last_zoom_point);
	} else if (m_zoom<get_min_zoom()) {
		animated_zoom( get_min_zoom() , m_last_zoom_point );
	} else {
		reset_scroll( );
		handle_scroll_end( );
	}
}

void milk_scroll_zoom_area::on_set_zoom( surf::surf_val zoom ) {
}

void milk_scroll_zoom_area::animated_zoom( surf::surf_val zoom , const surf::surf_point& zoom_pos ) {
	m_animate_zoom = true;
	m_animate_zoom_val = zoom;
	m_initial_zoom_point = zoom_pos;
	m_animation_start_tick = get_server().get_tick_count();
	on_begin_zoom();
}

/// zoom animation speed
static const surf::surf_val zoom_animation_speed = 8.0;

void milk_scroll_zoom_area::on_timer( surf_ddword tick ) {
	if (!m_in_zoom) {
		{
			milk_scroll_area::on_timer( tick );
		}
	} else if (m_animate_zoom) {
		{
			bool complete  = false;
			surf_val delta = zoom_animation_speed*(tick-m_animation_start_tick)*0.001;
			surf_val prev_zoom = m_zoom;
			surf_val zoom = 1.0;
			if (m_zoom<m_animate_zoom_val) {
				zoom = (m_zoom+delta)/m_zoom;
				if (m_zoom*zoom>m_animate_zoom_val) {
					complete = true;
				}
				
			} else {
				zoom = (m_zoom-delta)/m_zoom;
				if (m_zoom*zoom<m_animate_zoom_val) {
					complete = true;
				}
			}
			if (complete) {
				zoom = m_animate_zoom_val/prev_zoom;
			}
			append_zoom(m_initial_zoom_point, zoom);
			m_last_zoom = m_zoom;
			m_last_scroll = get_scroll_pos();
			if (complete) {
				on_end_zoom();
			}
			m_animation_start_tick = tick;
		}
	} 
}


surf_point milk_scroll_zoom_area::get_valid_scroll_pos( surf_point point ) {
	surf_rect   visible_rect = get_rect();
    
	surf_rect scroll_area = get_scroll_rect();
	scroll_area.x*=m_zoom;
	scroll_area.y*=m_zoom;
	scroll_area.cx*=m_zoom;
	scroll_area.cy*=m_zoom;
	
    surf_point  result_pos = point;
    
    if( visible_rect.cx >= scroll_area.cx )  result_pos.x = scroll_area.x-(visible_rect.cx-scroll_area.cx)/2;
    else if( result_pos.x < scroll_area.x ) result_pos.x = scroll_area.x;
    else if( result_pos.x > scroll_area.x + scroll_area.cx - visible_rect.cx ) result_pos.x = scroll_area.x + scroll_area.cx - visible_rect.cx;
    
    if( visible_rect.cy >= scroll_area.cy )  result_pos.y =  scroll_area.y-(visible_rect.cy-scroll_area.cy)/2;
    else if( result_pos.y < scroll_area.y ) result_pos.y = scroll_area.y;
    else if( result_pos.y > scroll_area.y + scroll_area.cy - visible_rect.cy ) result_pos.y = scroll_area.y + scroll_area.cy - visible_rect.cy;
    
    return result_pos;
}

surf::surf_val milk_scroll_zoom_area::get_min_zoom() {
	surf_val res = m_min_zoom;
	if (get_rect().cx/get_scroll_rect().cx>res) {
		res = get_rect().cx/get_scroll_rect().cx;
	}
	if (get_rect().cy/get_scroll_rect().cy>res) {
		res = get_rect().cy/get_scroll_rect().cy;
	}
	return res;
}


END_NAMESPACE_MILK