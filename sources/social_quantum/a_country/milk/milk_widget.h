#ifndef __MILK_WIDGET_H_INCLUDED
#define __MILK_WIDGET_H_INCLUDED

#include "milk_defs.h"

namespace sqc { namespace animation {
class animation_transformer;
typedef std::tr1::shared_ptr<animation_transformer>	animation_transformer_ptr;
typedef std::tr1::weak_ptr<animation_transformer>	animation_transformer_weak_ptr;
}}

NAMESPACE_MILK

enum milk_widget_style {
    widget_style_transparent = 1 << 0,
    widget_style_clip_children = 1 << 1,
    widget_style_hidden = 1 << 2,
    widget_style_disabled = 1 << 3,
};

typedef surf_dword milk_widget_styles;
typedef std::tr1::function<void()> milk_destroy_callback;

class milk_widget : public std::tr1::enable_shared_from_this<milk_widget> {
public:
    milk_widget( milk_widget_ptr p );
    
    template <class T> 
    std::tr1::shared_ptr<T> create_child( surf_rect const &r );
    
    template <class T, class A1> 
    std::tr1::shared_ptr<T> create_child( surf_rect const &r, A1 a1 );
    
    template <class T, class A1, class A2> 
    std::tr1::shared_ptr<T> create_child( surf_rect const &r, A1 a1, A2 a2 );

    template <class T, class A1, class A2, class A3> 
    std::tr1::shared_ptr<T> create_child( surf_rect const &r, A1 a1, A2 a2, A3 a3 );
    
    void destroy();
    
    void set_destroy_handler(milk_destroy_callback callback);
    
    virtual void set_rect( surf_rect const &r );
    virtual surf_rect get_rect() const;
    virtual surf_rect get_client_rect() const;
    
    virtual void set_caption( surf_string const &caption );
    surf_string get_caption() const;
    
    milk_widget_ptr get_parent() const;
    void set_parent( milk_widget_ptr ptr );
    
    
    void set_transparent( bool flag );
    bool is_transparent() const;
    void set_alpha( surf_val alpha );
    surf_val get_alpha() const;
    void set_clip_children( bool flag );
    bool is_clip_children() const;
    void set_visible( bool flag );
    bool is_visible() const;
    void set_disabled( bool flag );
    bool is_disabled() const;
    
    void set_font( surf_font_ptr f );
    surf_font_ptr get_font() const;
    
    surf_point screen_to_client( surf_point const &point );
    surf_point client_to_screen( surf_point const &point );
    
    void    invalidate();
	
	sqc::animation::animation_transformer_ptr transform();
public:

    virtual bool handle_touch( milk_touch_info const &info, bool bypass_click );
    virtual void handle_timer( surf_ddword tick );
    virtual void handle_render( surf_context_ptr ctx );
    virtual void handle_cancel_mode();
    virtual void handle_destroy();
    
    //
    //
    //
    virtual void on_show_window( bool show );
    virtual void on_create();
    virtual void on_destroy();
    virtual bool on_touch( milk_touch_info const &touch );
    virtual void on_cancel_mode();
    virtual void on_timer( surf_ddword tick );
    virtual void render( surf_context_ptr ctx );
    
    bool is_running() const;
    
    virtual milk_window_server  &get_server() const;
    surf_graphics_server &get_graphics();
public:
    // add child to back of childrens list
    void    add_child( milk_widget_ptr child, surf_rect const &rect );
	// add child to given index if possible, else at end
	void    add_child_at_index( milk_widget_ptr child, surf_rect const &rect , size_t index);
    // add child to front of childrens list
    void    add_child_front( milk_widget_ptr child, surf_rect const &rect ) {
        add_child_at_index(child, rect, 0);
    }
protected:
    void    remove_child( milk_widget_ptr child );
	bool	in_parent_rect();
	bool	in_child_rect();
protected:
protected:
    milk_widget_weak_ptr    parent;
    milk_widget_list        childs;
    
    surf_rect               window_rect;
    surf_string             window_caption;
    surf_font_ptr           font;
    
    milk_widget_styles      styles;
    surf_val                alpha;
    milk_destroy_callback   destroy_callback;
    
    bool is_runnig;
	sqc::animation::animation_transformer_weak_ptr	m_transformer;
};



class milk_desktop : public milk_widget {
public:
    milk_desktop( milk_window_server &s );
    virtual milk_window_server  &get_server() const;
    virtual void render( surf_context_ptr ctx );
private:    
    milk_window_server  &server;
};

//
// inline
//
template <class T> 
std::tr1::shared_ptr<T> milk_widget::create_child( surf_rect const &r ) {
    std::tr1::shared_ptr<T>    new_window( new T( shared_from_this() ) );
    add_child( new_window, r );
    return new_window;
}

template <class T, class A1> 
std::tr1::shared_ptr<T> milk_widget::create_child( surf_rect const &r, A1 a1 ) {
    std::tr1::shared_ptr<T>    new_window( new T( shared_from_this(), a1 ) );
    add_child( new_window, r );
    return new_window;
}

template <class T, class A1, class A2> 
std::tr1::shared_ptr<T> milk_widget::create_child( surf_rect const &r, A1 a1, A2 a2 ) {
    std::tr1::shared_ptr<T>    new_window( new T( shared_from_this(), a1, a2 ) );
    add_child( new_window, r );
    return new_window;
}

template <class T, class A1, class A2, class A3> 
std::tr1::shared_ptr<T> milk_widget::create_child( surf_rect const &r, A1 a1, A2 a2, A3 a3 ) {
    std::tr1::shared_ptr<T>    new_window( new T( shared_from_this(), a1, a2, a3 ) );
    add_child( new_window, r );
    return new_window;
}


END_NAMESPACE_MILK

#endif //__MILK_WIDGET_H_INCLUDED
