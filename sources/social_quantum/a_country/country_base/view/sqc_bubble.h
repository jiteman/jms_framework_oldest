#pragma once

#include "../../framework/sqc_framework.h"
#include "../../milk/milk_controls.h"
#include "sqc_bubble_def.h"

NAMESPACE_SQC_FRAMEWORK

struct sqc_bubble_font_layout {
	font_layout		font;
	surf::surf_color	color;
	layout_sizes	shadow_size;
	surf::surf_color	shadow_color;
	surf::surf_draw_string_flags draw_string_flags;
};

struct sqc_bubble_entry_layout {
	layout_vals	icon_space;
	sqc_bubble_font_layout font;
	image_names button;
};

struct sqc_bubble_layout {
	layout_vals		width;
	layout_vals		min_height;
	sqc_bubble_font_layout		caption_font;
	layout_sizes	items_space;
	sqc_bubble_entry_layout entry;
};

class sqc_bubble_entry {
public:
	sqc_bubble_entry( surf::surf_font_ptr font, const sqc_bubble_element& def,const sqc_bubble_entry_layout& layout) : 
		m_def(def), m_font(font), m_layout(layout) {}
	virtual bool allow_horizontal_layout() const { return false;} 
	virtual surf::surf_size calc_size( surf::surf_val width ) const = 0;
	void set_rect(const surf::surf_rect& rect) { m_rect = rect;}
	const surf::surf_rect& get_rect() const { return m_rect;}
	virtual void draw(surf::surf_context_ptr ctx, sqc_ddword linve_time ) const = 0;
	virtual bool can_process_touch() const { return false; }
	sqc_action get_action( ) const { return m_def.action; }
    
    /** Gets params of action
     */
    sqc_action_params_ptr get_action_params() const { return m_def.params; }

    virtual void on_timer( sqc_ddword time , bool &need_to_redraw_self) {};
protected:
	sqc_bubble_element	m_def;
	surf::surf_font_ptr	m_font;
	const	sqc_bubble_entry_layout& m_layout;
	surf::surf_rect	m_rect;
};
typedef std::tr1::shared_ptr<sqc_bubble_entry>    sqc_bubble_entry_ptr; 


/// just caption
class sqc_bubble_caption_entry : public sqc_bubble_entry {
public:
	sqc_bubble_caption_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) ;
	virtual surf::surf_size calc_size( surf::surf_val width ) const ;
	virtual void draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const ;
private:
	surf::surf_size	m_shadow_size;
protected:
	surf::surf_size calc_text_size( surf::surf_val width, const sqc_string& text ) const ;
	void draw_text( surf::surf_context_ptr ctx, const surf::surf_rect& rect , const sqc_string& text) const;
};

/// icon and caption
class sqc_bubble_info_entry : public sqc_bubble_caption_entry  {
public:
	sqc_bubble_info_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout );
	virtual surf::surf_size calc_size( surf::surf_val width ) const;
	virtual void draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const;
	virtual bool allow_horizontal_layout() const { return true;} 
private:
	sqc_texture_ptr		m_texture;
	surf::surf_val		m_icon_offset;
protected:
	surf::surf_size calc_size_for_text( surf::surf_val width, const sqc_string& text ) const;
	void draw_with_text(surf::surf_context_ptr ctx,const sqc_string& text ) const;
};

class sqc_bubble_time_entry : public sqc_bubble_info_entry {
public:
	sqc_bubble_time_entry( surf::surf_font_ptr font, const sqc_bubble_element& def , const sqc_bubble_entry_layout& layout) ;
	virtual surf::surf_size calc_size( surf::surf_val width ) const;
	virtual void draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const;
	virtual bool allow_horizontal_layout() const { return false;}
protected:
};

class sqc_bubble_status_entry : public sqc_bubble_info_entry {
public:
	sqc_bubble_status_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) : sqc_bubble_info_entry( font,def,layout ) {
	}
	virtual bool allow_horizontal_layout() const { return false;}
};

class sqc_bubble_button_entry : public sqc_bubble_caption_entry  {
public:
	sqc_bubble_button_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) ;
	bool can_process_touch() const { return true;}
	virtual surf::surf_size calc_size( surf::surf_val width ) const ;
	virtual void draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const;
private:
	sqc_texture_ptr		m_btn_texture;
};


class sqc_bubble	: public milk::milk_bubble {
public:
	sqc_bubble( milk::milk_widget_ptr parent, const sqc_bubble_layout& layout);
	void set_content( sqc_bubble_content const &content );
	virtual sqc_bubble_entry_ptr generate_entry( sqc_bubble_element const& element );
	virtual void render( surf::surf_context_ptr ctx );
	bool on_touch( milk::milk_touch_info const &touch );
	void on_field_updated(sqc_ddword time_stamp);
    virtual void on_timer( sqc_ddword time );
private:
protected:
	sqc_ddword						m_update_time;
	sqc_window_factory_ctx_ptr      m_window_ctx;
	const sqc_bubble_layout& m_layout;
	std::vector<sqc_bubble_entry_ptr>	m_entrys;
	sqc_action	m_default_action;
	sqc_bubble_content::action_callback_t m_action_callback;
	surf::surf_font_ptr m_caption_font;
	surf::surf_font_ptr m_text_font;
};

typedef std::tr1::shared_ptr<sqc_bubble>    sqc_bubble_ptr;

END_NAMESPACE_SQC_FRAMEWORK
