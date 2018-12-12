#ifndef __MILK_DEFS_H_INCLUDED
#define __MILK_DEFS_H_INCLUDED

//
//
//
#define NAMESPACE_MILK namespace milk {
#define END_NAMESPACE_MILK }

#include <list>
#include <vector>
#include <functional>
#include <cassert>
#include <math.h>

#include "../surf/surf_defs.h"
#include "../sstl/sstl_profiler.h"
#include "../surf/surf_9way_image.h"


#if defined _DEBUG
#define milk_assert(_Expression)     assert(_Expression)
#else
#define milk_assert(_Expression)     ((void)0)
#endif

NAMESPACE_MILK

using namespace surf;

enum milk_interface_paradigm {
    interface_paradigm_phone,
    interface_paradigm_hires,
    interface_paradigm_tablet,
};

struct milk_device_info {
    milk_device_info()
        : interface_paradigm( interface_paradigm_phone ) 
    {
        
    }
    
    milk_interface_paradigm interface_paradigm;
    surf_nsize              screen_size;
};



enum milk_touch_action {
    touch_action_press,
    touch_action_release,
    touch_action_move,
};

struct milk_touch_info {
    milk_touch_info() 
        : action( touch_action_press )
        , point_count( 0 ) 
        , tick( 0 )
    {
    }
    
    surf_point          points[10];
	int					points_id[10];
    int                 point_count;
    surf_ddword         tick;
    milk_touch_action   action;
    
    
    void offset_coords( surf_point const &p ) {
        for( int n = 0; n != point_count; ++n ) {
            points[n] -= p;
        }
    }
};


inline
std::ostream &operator << ( std::ostream &o, milk_touch_info const &info ) {
    o << "{";
    if( info.action == touch_action_press ) o << "press:";
    else if( info.action == touch_action_release ) o << "release:";
    else if( info.action == touch_action_move ) o << "move:";

    for( int n = 0; n != info.point_count; ++n ) {
        if( n )  o << ", ";
        o << info.points[n];
    }
    o << "}";

    return o;
}


class milk_widget;
typedef std::tr1::shared_ptr<milk_widget>    milk_widget_ptr;
typedef std::list<milk_widget_ptr>  milk_widget_list;
typedef std::tr1::weak_ptr<milk_widget>      milk_widget_weak_ptr;

class milk_button;
class milk_window;
class milk_label;
class milk_scroll_area;
class milk_spinboard;
class milk_theme_button;
class milk_spinboard_pager;
typedef std::tr1::shared_ptr<milk_spinboard_pager> milk_spinboard_pager_ptr;
typedef std::tr1::shared_ptr<milk_spinboard> milk_spinboard_ptr;

struct milk_metrics {
    milk_metrics()
    {
        spinboard_visible_count = 6;
        spinboard_item_spacing_cx = 5;
        spinboard_scroll_to_page_distance = 150;
        
        scroll_animation_decrease_factor = 3.5;
        scroll_dynamic_factor = 2.5;
        scroll_history_max_size = 10;
        scroll_timeout = 10;
        scroll_start_delta = 10;
        
		spinboard_fade = spinboard_item_spacing_cx;
        
        default_font_size = 20;
        default_font_name = "Arial.otf";
    }
    
    int spinboard_visible_count;
    int spinboard_item_spacing_cx;
    int spinboard_scroll_to_page_distance;
	int spinboard_fade;
    
    surf_val    scroll_animation_decrease_factor;
    surf_val    scroll_dynamic_factor;
    surf_val    scroll_start_delta;
    int         scroll_history_max_size;
    int         scroll_timeout;
    
    int default_font_size;
    surf_string default_font_name;
	
	surf_val	separator_size;
};

enum milk_spinboard_themed_elements {
	milk_spinboard_themed_left_right = 1<<0,	///< left/right buttons
	milk_spinboard_themed_pages = 1<<1			///< pages counter
};
typedef surf::surf_dword milk_spinboard_theme_flags;

enum milk_dialog_type {
	milk_dialog_type_window,
	milk_dialog_type_alert,
	milk_dialog_type_game_specific_first,///< game specific
};

enum milk_bevel_type {
	milk_bevel_type_none,
	milk_bevel_type_content,			///< basic content
	milk_bevel_type_content_scroll,		///< content with scroll
	milk_bevel_type_caption,			///< caption
	milk_bevel_type_counter,			///< counter
	milk_bevel_type_game_specific_first,///< game specific
};


struct milk_dialog_draw_arg {
    bool                full_screen;
	surf::surf_rect		right_rect;
    bool                has_right_button;
	surf::surf_rect		left_rect;
    bool                has_left_button;
	milk_dialog_type	type;
	
	milk_dialog_draw_arg() 
	: full_screen(false)
	,has_right_button(false)
	,has_left_button(false)
	,type(milk_dialog_type_window)
	{
	}
};

struct milk_dialog_tab_def {
	surf_string title;
	bool	with_counter;
	std::tr1::function<void(int)> set_counter;
	typedef std::tr1::function<void()> activate_callback;
	activate_callback activate;
};

enum milk_font_modify_flag {
	milk_font_modify_face =		1<<0,
	milk_font_modify_size =		1<<1,
	milk_font_modify_color =	1<<2,
	milk_font_modify_shadow_color =	1<<3,
	milk_font_modify_shadow_size =	1<<4,
};

struct milk_font_modify_args {
	surf::surf_dword flags;
	surf::surf_string face;
	surf::surf_val size;
	surf::surf_color color;
	surf::surf_color shadow_color;
	surf::surf_size  shadow_size;
};

struct milk_dialog_init_arg {
    bool                has_close;
    bool                has_back;
    bool                has_next;
	bool				center_dialog;
	surf_string			title;
	milk_font_modify_args title_args;
	milk_bevel_type		bevel;
	surf_val	bevel_left;
	surf_val	bevel_right;
	surf_val	bevel_top;
	surf_val	bevel_bottom;
	milk_dialog_init_arg()
	: has_close(false)
	, has_back(false)
	, has_next(false)
	, center_dialog(false)
	,bevel(milk_bevel_type_none) 
	,bevel_left(0)
	,bevel_right(0)
	,bevel_top(0)
	,bevel_bottom(0)
	{
		title_args.flags = 0;
	}
};

struct milk_bubble_draw_arg {
    std::string         caption;
	surf::surf_val		tail_pos;
};

struct milk_bubble_metrics {
	surf::surf_val content_left_offset;
	surf::surf_val content_right_offset;
	surf::surf_val content_top_offset;
	surf::surf_val content_bottom_offset;
	surf::surf_point tail_pos;
};

class milk_dialog;

enum milk_separator_direction {
	milk_separator_direction_horizontal,	///< horizontal separator
	milk_separator_direction_vertical		///< vertical separator
};

enum milk_separator_type {
	milk_separator_type_basic,				///< basic separator
	milk_separator_type_game_specific_first
};

struct milk_separator_draw_arg {
	milk_separator_direction direction;
	surf::surf_point	center;
	surf::surf_val		length;
	milk_separator_type type;
	milk_separator_draw_arg() 
		: direction(milk_separator_direction_horizontal)
		, type(milk_separator_type_basic)
	{
	}
	milk_separator_draw_arg(milk_separator_direction dir,const surf::surf_point& ceneter,surf::surf_val len) 
		: direction( dir)
		, center(ceneter)
		, length(len)
		, type(milk_separator_type_basic)
	{
	}
};


struct milk_bevel_draw_arg {
	milk_bevel_type type;
};

class milk_theme {
public:
    virtual ~milk_theme() {
    };
	virtual void init_metrics() {}
    virtual void draw_dialog( surf_context_ptr ctx, surf::surf_rect const &rect, milk_dialog_draw_arg const &arg ) = 0;
    virtual void draw_window( surf_context_ptr ctx, milk_window &w ) = 0;
    virtual void draw_button( surf_context_ptr ctx, milk_theme_button &w ) = 0;
    virtual void draw_label( surf_context_ptr ctx, milk_label &w ) = 0;
    virtual void draw_scroller( surf_context_ptr ctx, milk_scroll_area &w ) = 0;
    virtual void draw_spinboard( surf_context_ptr ctx, milk_spinboard &w ) = 0;
	virtual void draw_bubble( surf_context_ptr ctx, surf::surf_rect const &rect, milk_bubble_draw_arg const &arg ) = 0;
	virtual void draw_separator( surf_context_ptr ctx, milk_separator_draw_arg const &arg ) = 0;
	virtual void draw_bevel( surf_context_ptr ctx, surf::surf_rect const &rect, milk_bevel_draw_arg const &arg ) = 0;
    
    virtual void on_init_dialog( milk::milk_dialog& dlg, milk_dialog_init_arg const &arg , milk_dialog_draw_arg& draw_arg ) = 0;
	virtual bool on_end_dialog( milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg ) = 0;
    virtual surf::surf_rect get_dialog_content_rect( const surf::surf_rect& rect, const milk_dialog_init_arg& init_arg ) = 0;
	virtual void init_dialog_tabs( milk::milk_dialog& dlg, 
								  const milk::milk_dialog_init_arg& init_arg,
								  milk::milk_dialog_draw_arg const &arg,  
								  std::vector<milk::milk_dialog_tab_def>& tabs ) = 0;
	virtual void on_init_spinboard( milk::milk_spinboard& spin , milk_spinboard_theme_flags flags ) = 0;
	virtual void on_init_pager( milk::milk_spinboard_pager& pager  ) = 0;
	
    const milk_metrics    &get_metrics() const {
        return metrics;
    }
	virtual const milk_bubble_metrics &get_bubble_metrics() const = 0;
protected:
    milk_metrics    metrics;
												
};

typedef std::tr1::shared_ptr<milk_theme>    milk_theme_ptr;

typedef std::tr1::function<void()>   milk_callback;


class milk_window_server;

// todo: rename BT_one -> theme_button_one
enum theme_button_type {
	theme_button_default,
    theme_button_message,
	theme_button_game_specific_first
    
};

END_NAMESPACE_MILK

#endif //__MILK_DEFS_H_INCLUDED
