#pragma once

#include "../sqc_framework_defs.h"
#include "../layouts/sqc_layout_defs.h"
#include "../dialogs/sqc_base_dialog_layout.h"
#include "../dialogs/sqc_base_page.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_texture_panel implementation
//
class sqc_texture_panel : public milk::milk_dialog {
public:
	sqc_texture_panel( milk::milk_widget_ptr p, 
				 const dialog_layout& dialog_layout );
    
  	void set_center_dialog(bool center);
	bool get_center_dialog() const { return m_center_dialog;}
	
	void render( surf::surf_context_ptr ctx );
	
	const sqc_window_factory_ctx_ptr& get_window_factory_ctx() const { return m_window_ctx;}
	
	void create_background( const dialog_backgrounds& backrounds );
protected:
	// initialization 
	virtual void on_init_dialog();
	// center dialog
	virtual void center_dialog();

protected:
	// dialog layout
	const dialog_layout&			m_dialog_layout;
    sqc_window_factory_ctx_ptr      m_window_ctx;
    bool							m_center_dialog;
    
    milk::milk_image_ptr            m_backing_img;
};


//
// sqc_message_box implementation
//
class sqc_message_box : public sqc_texture_panel {
public:

	sqc_message_box( milk::milk_widget_ptr p, 
					const dialog_layout& dialog_layout,
                    const label_layout& title_layout,
					const label_layout& text_layout,
					const theme_button_layout& button_layout,
					const label_layout& button_caption_layout,
                    const layout_vals& min_button_width,
                    const layout_vals& button_text_offset_min,
                    const message_box_anchor* anchors ) 
		: sqc_texture_panel( p, dialog_layout ) 
		, m_button_layout( button_layout )
		, m_button_caption_layout( button_caption_layout ) 
        , m_min_button_width( min_button_width )
		, m_button_text_offset_min( button_text_offset_min )
		, m_title_layout( title_layout )
		, m_text_layout( text_layout )
        , m_anchors( anchors ) {
	}
    
    void	set_properties( const sqc_string& dlg_title, 
    						const sqc_string& dlg_text,
                            const sqc_string& button_text );
    void	set_button_action( milk::milk_callback& cb );
	
	
protected:
	// initialization
	virtual void on_init_dialog();
	// button action
	virtual void on_button_pressed();
	
    // calculate font size depend of label layout
    surf::surf_size	calc_font_size( const sqc_string& text,
    						const label_layout&	label_layout );
	
	bool get_dialog_init_arg( milk::milk_dialog_init_arg &arg ) { 
		arg.center_dialog = true;
		return true;
	}
protected:
	// layouts
    const theme_button_layout&		m_button_layout;
	const label_layout&				m_button_caption_layout;
    const layout_vals&				m_min_button_width;
    const layout_vals&				m_button_text_offset_min;
    
    const label_layout&				m_title_layout;
	const label_layout&				m_text_layout;
    const message_box_anchor*		m_anchors;
    
    milk::milk_callback				m_callback;

    
    sqc_string 		m_dlg_title;
    sqc_string 		m_dlg_text;
    sqc_string 		m_button_text;
};


enum dialog_mode {
	dialog_theme_style, // todo - move all dialogs to this mode
    dialog_with_close_button,
    dialog_with_back_button,
    dialog_with_next_button,
    dialog_with_back_and_close_button
};


enum sqc_dialog_theme_flag {
    dialog_has_close_button        = (1 << 1),
    dialog_has_back_button         = (1 << 2),
    dialog_has_next_button         = (1 << 3)
};

typedef sqc_dword sqc_dialog_theme_flags;


//
// sqc_dialog implementation
//
class sqc_dialog : public sqc_texture_panel {

public:

	sqc_dialog( milk::milk_widget_ptr p, 
				const dialog_layout& dialog_layout,
                const sqc_dialog_theme_flags flags )
		: sqc_texture_panel( p, dialog_layout )
        , m_dialog_mode( dialog_theme_style )
    	, m_dialog_theme_flags( flags ){
    }
    
 	/// separator vertical
	milk::milk_separator_ptr	create_separator( const milk::milk_widget_ptr& place_to, const vertical_separator_layout& layout );
	/// separator horizontal
	milk::milk_separator_ptr	create_separator( const milk::milk_widget_ptr& place_to, const horizontal_separator_layout& layout );
	
protected:
	// initialization
	virtual void 	on_init_dialog();
    virtual bool 	get_dialog_init_arg( milk::milk_dialog_init_arg &arg );
	
	virtual bool on_end_dialog();
	
	template <class T> 
	std::tr1::shared_ptr<T> create_child( surf::surf_rect const &r );
	template <class T,class Arg1> 
	std::tr1::shared_ptr<T> create_child( surf::surf_rect const &r ,Arg1);

	
	template <class T>
	surf::surf_dword add_tab( const surf::surf_string& str ,bool with_counter);
	template <class T,class Arg1>
	surf::surf_dword add_tab( const surf::surf_string& str ,bool with_counter,Arg1 arg1 );
protected:
	
protected:
private:
	template <class T> void create_page();
	template <class T,class Arg1> void create_page( Arg1 );

	dialog_mode						m_dialog_mode;
    
    sqc_dialog_theme_flags			m_dialog_theme_flags;
};
typedef std::tr1::shared_ptr<sqc_dialog> sqc_dialog_ptr;

//
// inline
//
template <class T> 
std::tr1::shared_ptr<T> sqc_dialog::create_child( surf::surf_rect const &r ) {
    std::tr1::shared_ptr<T>    new_window( new T( std::tr1::static_pointer_cast<sqc_dialog>( shared_from_this() ) ) );
    add_child( new_window, r );
    return new_window;
}
template <class T,class Arg1> 
std::tr1::shared_ptr<T> sqc_dialog::create_child( surf::surf_rect const &r, Arg1 a1 ) {
    std::tr1::shared_ptr<T>    new_window( new T( std::tr1::static_pointer_cast<sqc_dialog>( shared_from_this() ) , a1) );
    add_child( new_window, r );
    return new_window;
}

/// inlines
template <class T> void sqc_dialog::create_page() {
	sqc_dialog_page_ptr page = sqc_dialog_page_ptr( new T(std::tr1::static_pointer_cast<sqc_dialog>(shared_from_this())) );
	add_child(page, get_client_rect());
	set_page( page );
}
template <class T,class Arg1> void sqc_dialog::create_page(Arg1 arg1) {
	sqc_dialog_page_ptr page = sqc_dialog_page_ptr( new T(std::tr1::static_pointer_cast<sqc_dialog>(shared_from_this()),arg1) );
	add_child(page, get_client_rect());
	set_page( page );
}

template <class T> surf::surf_dword sqc_dialog::add_tab(const surf::surf_string& title,bool with_counter) {
	milk::milk_dialog_tab_def tab_def;
	tab_def.title = title;
	tab_def.with_counter = with_counter;
	tab_def.activate = std::tr1::bind( static_cast<void(sqc_dialog::*)()>(&sqc_dialog::create_page<T>), this );
	return add_tab_def(tab_def);
}
template <class T,class Arg1> surf::surf_dword sqc_dialog::add_tab(const surf::surf_string& title,bool with_counter,Arg1 arg1) {
	milk::milk_dialog_tab_def tab_def;
	tab_def.title = title;
	tab_def.with_counter = with_counter;
	tab_def.activate = std::tr1::bind( &sqc_dialog::create_page<T,Arg1>, this, arg1);
	return add_tab_def(tab_def);
}

//
// sqc_dialog_with_close button implementation
//
class sqc_dialog_with_close : public sqc_dialog {
public:
	sqc_dialog_with_close(milk::milk_widget_ptr p, 
								   const dialog_layout& dialog_layout)  
		: sqc_dialog( p, dialog_layout, sqc_dialog_theme_flag( dialog_has_close_button ) ) {
	}
};

//
// sqc_dialog_with_back button implementation
//
class sqc_dialog_with_back : public sqc_dialog {
public:
	sqc_dialog_with_back(milk::milk_widget_ptr p, 
								   const dialog_layout& dialog_layout)  
	: sqc_dialog( p, dialog_layout, sqc_dialog_theme_flag( dialog_has_back_button ) ) {
	}
};

//
// sqc_dialog_with_back button implementation
//
class sqc_dialog_with_next : public sqc_dialog {
public:
	sqc_dialog_with_next(milk::milk_widget_ptr p, 
                         const dialog_layout& dialog_layout ) 
    : sqc_dialog( p, dialog_layout,sqc_dialog_theme_flag( dialog_has_next_button )) 
    {
	}
};

//
// sqc_dialog_with_back_and_close button implementation
//
class sqc_dialog_with_back_and_close : public sqc_dialog {
public:
	sqc_dialog_with_back_and_close(milk::milk_widget_ptr p, 
								   const dialog_layout& dialog_layout)  
		: sqc_dialog( p, dialog_layout, sqc_dialog_theme_flag( dialog_has_back_button | dialog_has_close_button ) ) {
	}
};

END_NAMESPACE_SQC_FRAMEWORK
