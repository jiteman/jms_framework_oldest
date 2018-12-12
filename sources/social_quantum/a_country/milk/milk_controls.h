#ifndef __MILK_CONTROLS_H_INCLUDED
#define __MILK_CONTROLS_H_INCLUDED

#include "milk_widget.h"


NAMESPACE_MILK

class milk_window : public milk_widget {
public:
    milk_window( milk_widget_ptr p );
    void render( surf_context_ptr ctx );
};

class milk_dialog_page;
typedef std::tr1::shared_ptr<milk_dialog_page>   milk_dialog_page_ptr;

class milk_dialog : public milk_widget {
public:
	milk_dialog( milk_widget_ptr p );
    
    
	// run dialog
	virtual void do_modal();
	virtual void end_dialog();
    
    virtual void render( surf_context_ptr ctx );
    virtual bool get_dialog_init_arg( milk_dialog_init_arg &arg );
    
	// destroy dialog
    void set_close_button_action( milk_callback cb );
    void set_next_button_action(milk_callback cb);
    void set_back_button_action(milk_callback cb);
  
	
protected:
	// initialization 
	virtual void on_init_dialog();
	virtual void on_post_init_dialog();
    virtual bool on_end_dialog();

	template <class T>
	surf::surf_dword add_tab( const surf_string& str ,bool with_counter);
	template <class T,class Arg1>
	surf::surf_dword add_tab( const surf_string& str ,bool with_counter,Arg1 arg1 );
	void activate_tab( surf::surf_dword index );
	void set_tab_counter( surf::surf_dword index, int value );
	
	void set_bevel_type( milk_bevel_type type );
	
	void on_destroy();
public:
	// button action
	virtual void on_close_button_pressed();
	virtual void on_back_button_pressed();
    virtual void on_next_button_pressed();
    
protected:
    milk_callback     close_callback;
    milk_callback     next_callback;
    milk_callback     back_callback;
	milk_dialog_draw_arg	draw_arg;
    milk_bevel_type		bevel_type;
	surf::surf_dword add_tab_def(const milk_dialog_tab_def& def);
	void set_page( const milk_dialog_page_ptr& page );
private:
	template <class T> void create_page();
	template <class T,class Arg1> void create_page(Arg1 arg1);
	std::vector<milk_dialog_tab_def>	tabs;
	milk_dialog_page_ptr	current_page;
};

typedef std::tr1::shared_ptr<milk_dialog>   milk_dialog_ptr;

class milk_dialog_page	: public milk_widget {
public:
	milk_dialog_page( milk_dialog_ptr p) : milk_widget(p) {}
	virtual void on_init() {}
	virtual void on_end() {}
protected:
};
typedef std::tr1::shared_ptr<milk_dialog_page>   milk_page_ptr;


/// inlines
template <class T> void milk_dialog::create_page() {
	milk_dialog_page_ptr page = milk_dialog_page_ptr( new T(std::tr1::static_pointer_cast<milk_dialog>(shared_from_this())) );
	add_child(page, get_client_rect());
	set_page( page );
}
template <class T,class Arg1> void milk_dialog::create_page(Arg1 arg1) {
	milk_dialog_page_ptr page = milk_dialog_page_ptr( new T(std::tr1::static_pointer_cast<milk_dialog>(shared_from_this()),arg1) );
	add_child(page, get_client_rect());
	set_page( page );
}

template <class T> surf::surf_dword milk_dialog::add_tab(const surf::surf_string& title,bool with_counter) {
	milk_dialog_tab_def tab_def;
	tab_def.title = title;
	tab_def.with_counter = with_counter;
	tab_def.activate = std::tr1::bind( &milk_dialog::create_page<T>, this );
	return add_tab_def(tab_def);
}
template <class T,class Arg1> surf::surf_dword milk_dialog::add_tab(const surf::surf_string& title,bool with_counter,Arg1 arg1) {
	milk_dialog_tab_def tab_def;
	tab_def.title = title;
	tab_def.with_counter = with_counter;
	tab_def.activate = std::tr1::bind( &milk_dialog::create_page<T,Arg1>, this, arg1);
	return add_tab_def(tab_def);
}

class milk_control : public milk_widget {
public:
    milk_control( milk_widget_ptr p ); 
};

class milk_separator : public milk_control {
public:
    milk_separator( milk_widget_ptr p , milk_separator_direction dir);
	void set_type( milk_separator_type type );
	void set_position( const surf::surf_point& pos );
	void set_length( surf::surf_val len );
	void render( surf_context_ptr ctx );
private:
	milk_separator_draw_arg m_draw_arg;
	void recalculate_rect();
};
typedef std::tr1::shared_ptr<milk_separator>   milk_separator_ptr;


class milk_bevel : public milk_control {
public:
    milk_bevel( milk_widget_ptr p ); 
	void render( surf_context_ptr ctx );
	void set_type( milk_bevel_type type ) {
		m_type = type;
	}
private:
	milk_bevel_type	m_type;
};
typedef std::tr1::shared_ptr<milk_bevel>   milk_bevel_ptr;


class milk_label : public milk_control {
public:
    milk_label( milk_widget_ptr p );
    void render( surf_context_ptr ctx );

    void set_color( surf_color c );
    surf_color get_color() const;

    void set_shadow_color( surf_color c );
    surf_color get_shadow_color() const;

    void set_shadow_size ( surf_size s );
    surf_size get_shadow_size() const;

	void set_draw_flags( surf_draw_string_flags flags ) { draw_flags = flags;}
    surf_draw_string_flags get_draw_flags() const;

    void set_horizontal_alignment(surf_draw_string_flags ha);
    void set_vertical_alignment(surf_draw_string_flags va);
    void set_truncation_mode(surf_draw_string_flags tm);
    void set_multiline_enabled(bool e);
    void set_draw_shadow_enabled(bool e);
    void set_adjust_font_size_enabled(bool e);
private:
    surf_draw_string_flags  draw_flags;
    surf_font_ptr           font;
    surf_color              text_color;
    surf_color              shadow_color;
    surf_size               shadow_size;
};

typedef std::tr1::shared_ptr<milk_label>   milk_label_ptr;

class milk_image : public milk_label {
public:    
    milk_image( milk_widget_ptr p );
    void render( surf_context_ptr ctx );
	
    void set_image( surf_image_ptr i );
    surf_image_ptr get_image() const;
    
    void set_is_rotated( bool rotated );
    void set_is_v_mirrored( bool mirrored );
    
    void set_stretch( bool flag );
private:
    surf_image_ptr  image;
    bool            stretch_image;
    bool            is_rotated;
    bool            is_v_mirrored;
};

typedef std::tr1::shared_ptr<milk_image>   milk_image_ptr;

class milk_slice_image : public milk_control {
public:    
    milk_slice_image( milk_widget_ptr p );
    void render( surf_context_ptr ctx );
    void set_image(surf_9way_image_ptr);
    surf_9way_image_ptr get_image() const;

private:
    surf_9way_image_ptr image;
};

typedef std::tr1::shared_ptr<milk_slice_image> milk_slice_image_ptr;

enum milk_button_style {
    push_button,
    radio_button,
};

class milk_button;
typedef std::tr1::shared_ptr<milk_button>   milk_button_ptr;

class milk_radio_group {
    friend class milk_button;
public:
    milk_radio_group();
    virtual ~milk_radio_group();
    void    add_to_group( milk_button_ptr button );
protected:
    void    set_active_button( milk_button_ptr button );
protected:
    typedef std::list<milk_button_ptr>  button_list;
    button_list     m_buttons;
};


class milk_button : public milk_label {
friend class milk_radio_group;
public:    
    milk_button( milk_widget_ptr p );
    
    // virtuals
    void render( surf_context_ptr ctx );
    //~virtuals
    
    bool on_touch( milk_touch_info const &info );
    
    void on_cancel_mode();
    void set_action( milk_callback cb );
    
    bool is_pressed() const;
    
    bool is_checked() const;
    void set_checked( bool checked );

    void fire_action();
    
    void set_is_active( bool active );
    bool is_active() const;

    milk_button_style   get_button_style() const;
    void                set_button_style( milk_button_style style );
protected:
    void                set_group( milk_radio_group* group );
    
private:
    milk_callback           m_action;
    bool                    m_is_pressed;
    bool                    m_is_active;
    bool                    m_is_checked;
    milk_button_style       m_button_style;
    
    milk_radio_group*       m_group;
};


class milk_image_button : public milk_button {
    
public:
    milk_image_button( milk_widget_ptr p );
    void render( surf_context_ptr ctx );
    
    void set_image( surf_image_ptr image );
    surf_image_ptr get_image() const;
    
    void set_pressed_image( surf_image_ptr image );
    surf_image_ptr get_pressed_image() const;
    
    void set_inactive_image( surf_image_ptr image );
    surf_image_ptr get_inactive_image() const;
    
    void set_stretch( bool flag );

private:
    surf_image_ptr m_normal_image;
    surf_image_ptr m_pressed_image;
    surf_image_ptr m_inactive_image;
    bool m_is_stretch_image;
    
};

typedef std::tr1::shared_ptr< milk_image_button > milk_image_button_ptr;

/*
class milk_group_button : public milk_control {
public:
	milk_group_button(milk_widget_ptr p) 
    	: milk_control(p)
    {
    }
    
    int add_control(milk_button_ptr c)
    {
    	m_list.push_back(c);
        return 1;
    }
    
    
private:
	std::list<milk_button_ptr> m_list;
};

typedef std::tr1::shared_ptr<milk_group_button>   milk_group_button_ptr;
*/

//
// Milk theme button
//

class milk_theme_button : public milk_button {
public:
    milk_theme_button( milk_widget_ptr p, milk::theme_button_type btype );
    void render( surf_context_ptr ctx );
	//void set_group(milk_group_button_ptr group);
    //void set_pressed_image( surf_image_ptr i );
    //surf_image_ptr get_pressed_image() const;
    
   	//void set_stretch( bool flag );
    
	milk::theme_button_type get_button_type() const;
private:
	milk::theme_button_type m_btype;
};

typedef std::tr1::shared_ptr<milk_theme_button>   milk_theme_button_ptr;


// switch state
enum switch_state {
	switch_state_off,
	switch_state_on,
};

typedef std::tr1::function<void( switch_state new_state )>	switch_callback;


//
// milk switch button
class milk_switch_button : public milk_control {
public:	
    milk_switch_button( milk_widget_ptr p );
public:
	// on and off properties
	void set_on_properties( const surf_string& on_text, 
						    const surf_image_ptr on_image,
						    const surf_font_ptr on_font,
						    const surf_color& on_text_color,
						    const surf_color& on_text_shadow_color,
						    const surf_size& on_text_shadow_size );
	
	void set_off_properties( const surf_string& off_text, 
						    const surf_image_ptr off_image,
						    const surf_font_ptr off_font,
							const surf_color& off_text_color,
							const surf_color& off_text_shadow_color,
							const surf_size& off_text_shadow_size );
	
	// switch state
	void set_state( switch_state state );
	switch_state get_state() const;
	
	// store action
    void set_action( switch_callback cb );
	
protected:
    void render( surf_context_ptr ctx );
    bool on_touch( milk_touch_info const &info );
	void fire_action();
	
private:
    surf_image_ptr  on_image, off_image;
	surf_string		on_text, off_text;
	surf_font_ptr   on_font, off_font;
	surf_color		on_text_color, off_text_color;
	surf_color		on_text_shadow_color, off_text_shadow_color;
	surf_size		on_text_shadow_size, off_text_shadow_size;
	
	switch_callback	callback;
	switch_state	state;
	
};

typedef std::tr1::shared_ptr<milk_switch_button>   milk_switch_button_ptr;

//
//milk bubble
class milk_bubble : public milk_widget {
public:
	milk_bubble( milk_widget_ptr p );

	void move( surf_point const &pos );
    virtual void on_timer( surf_ddword tick );
    
protected:
	void on_create();
	virtual surf_rect get_client_rect() const;
	
    virtual void render( surf_context_ptr ctx );
	
protected:
    
protected:
	void	resize_client_to_window();
	milk_bubble_metrics const& get_metrics() const;
};

typedef std::tr1::shared_ptr<milk_bubble>   milk_bubble_ptr;


//
//milk progress bar
class milk_progress_bar : public milk_widget {
public:
	milk_progress_bar( milk_widget_ptr p );
    void set_range( surf_val min, surf_val max );
    void set_pos( surf_val pos );
    void set_image( surf_9way_image_ptr image);
    void render( surf_context_ptr ctx );
private:
	surf_val m_min, m_max, m_pos;
    surf::surf_rect m_bar_rect;
    surf_9way_image_ptr m_image;
};

typedef std::tr1::shared_ptr<milk_progress_bar> milk_progress_bar_ptr;

END_NAMESPACE_MILK

#endif //__MILK_CONTROLS_H_INCLUDED
