#ifndef __MILK_SCROLL_AREA_H_INCLUDED__
#define __MILK_SCROLL_AREA_H_INCLUDED__

#include "milk_controls.h"

NAMESPACE_MILK

class milk_scroll_area : public milk_control {
    enum milk_scroll_state {
        scroll_state_idle,
        scroll_state_delay_event,
        scroll_state_waiting_scroll,
        scroll_state_pre_scrolling,
        scroll_state_scrolling,
        scroll_state_animation,
    };
public:
    milk_scroll_area( milk_widget_ptr p );
    void render( surf_context_ptr ctx );
    
    bool handle_touch( milk_touch_info const &info, bool bypass_click );
    void on_timer( surf_ddword tick );
    
    
    void    set_scroll_area( surf_rect const &r );
    surf_rect get_scroll_rect() const;
    
    void    animated_scroll( surf_point const &p );
    void    set_scroll_pos( surf_point const &p, bool validate );
    surf_point get_scroll_pos() const;
    
    void    set_scroll_childrens( bool flag )  {
        scroll_childrens = flag;
    }
    void    set_limited_wait( bool flag ) {
        limited_wait_for_scroll = flag;
    }
    void    set_enable_vertical_scroll( bool flag ) {
        enable_vertical_scroll = flag;
    }
    void    set_enable_horizontal_scroll( bool flag ) {
        enable_horizontal_scroll = flag;
    }
	void	set_centered( bool flag ) {
		m_centered = flag;
	}
	/// enable or disable scroll if content smaller that window size
	void	set_small_scroll_enabled( bool enabled ) {
		m_small_scroll_enabled = enabled;
	}

protected:
    virtual void on_scroll();
    virtual void on_scroll_complete();
    virtual surf_point get_valid_scroll_pos( surf_point point );
    
    void handle_pre_scroll_begin();
    void handle_scroll_begin();
    void handle_scroll_end();
    void handle_scroll( surf_point const &delta );
    
    surf_point calculate_dynamic_target();


	void reset_scroll( );
	
private:
    
    surf_point   scroll_pos;
    surf_rect    scroll_area;
    milk_scroll_state   scroll_state;
    milk_touch_info     last_touch_info;
    surf_point          start_scroll_pos;
    surf_dword          last_timeout;
    
    bool                scroll_childrens;
    bool                limited_wait_for_scroll;
    surf_point          animated_scroll_pos;
    
    
    std::list<surf_point> scroll_history;
    surf_point            last_history_point;
    
    bool                    enable_vertical_scroll;
    bool                    enable_horizontal_scroll;
	bool					m_centered;
	bool	m_small_scroll_enabled;
};

typedef std::tr1::shared_ptr<milk_scroll_area>   milk_scroll_area_ptr;


class milk_scroll_zoom_area : public milk_scroll_area {
public:
	milk_scroll_zoom_area( milk_widget_ptr p );
    
	void set_min_zoom( surf::surf_val value );
	void set_max_zoom( surf::surf_val value );

	bool handle_touch( milk_touch_info const &info, bool bypass_click );
	
	void on_timer( surf_ddword tick );
	
	void animated_zoom( surf::surf_val zoom , const surf::surf_point& zoom_pos);
protected:
	surf::surf_val get_zoom_value() const { return m_zoom;}
private:
	surf::surf_val	m_zoom;
	surf::surf_val	m_min_zoom;
	surf::surf_val	m_max_zoom;
	surf::surf_val	m_min_zoom_hard;
	surf::surf_val	m_max_zoom_hard;
	bool	m_in_zoom;
	surf::surf_val	m_last_zoom;
	milk_touch_info	m_last_touch;
	surf::surf_point	m_finger_a;
	surf::surf_point	m_finger_b;
	surf::surf_point	m_last_scroll;
	surf::surf_point get_valid_scroll_pos( surf::surf_point point );
	void on_begin_zoom();
	void on_set_zoom( surf::surf_val z );
	void on_end_zoom();
	void append_zoom( const surf::surf_point& pos, surf::surf_val z );
	surf::surf_point	m_initial_zoom_point;
	surf::surf_point	m_last_zoom_point;
	bool	m_animate_zoom;
	surf::surf_val	m_animate_zoom_val;
	surf_ddword	m_animation_start_tick;
	surf::surf_val get_min_zoom();
};

END_NAMESPACE_MILK


#endif //#ifndef __MILK_SCROLL_AREA_H_INCLUDED__