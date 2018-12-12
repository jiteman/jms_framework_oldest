#pragma once

#include "../../framework/sqc_framework.h"
#include "../../milk/milk_widget.h"
#include "../../animation/animation_server.h"
#include "../../sqc/sqc_base.h"

namespace sqc { namespace animation {
	class animation_transformer;
	typedef std::tr1::shared_ptr<animation_transformer>	animation_transformer_ptr;
	typedef std::tr1::weak_ptr<animation_transformer>	animation_transformer_weak_ptr;
}}


NAMESPACE_SQC_FRAMEWORK

class sqc_tooltip {
private:
public:
	sqc_tooltip( const surf::surf_color& color,
				const surf::surf_font_ptr& font,
				const sqc_string& text,
				const surf::surf_image_ptr& icon);
	virtual void draw( const surf::surf_context_ptr& ctx );
private:
	surf::surf_color	m_color;
	surf::surf_font_ptr		m_font;
	sqc_string m_text;
	surf::surf_image_ptr m_icon;
};
typedef std::tr1::shared_ptr<sqc_tooltip> sqc_tooltip_ptr;

class sqc_tooltips_manager {
public:
	explicit sqc_tooltips_manager(  );
	
	virtual void add_tooltips( const sqc_tooltips_data& tooltips , const surf::surf_point& pos );
	
	void render( const surf::surf_context_ptr& ctx  );

	void set_scroll( const surf::surf_point& scroll ) { m_scroll = scroll; }
	void set_zoom( surf::surf_val zoom ) { m_zoom = zoom; }
	void set_font( const surf::surf_font_ptr& font ) { m_font = font;}
protected:
	void add_tooltip( const sqc_tooltip_ptr& ptr , const surf::surf_point& pos, surf::surf_val pause);
	virtual void set_tooltip_animation( const sqc::animation::animation_transformer_ptr& transformer , 
									   const surf::surf_point& pos,
									   surf::surf_val pause);
	virtual void add_tooltip( size_t index, const sqc_tooltip_data& tooltip , const surf::surf_point& pos );
	
	const surf::surf_font_ptr& get_font() const { return m_font; }
private:
	struct entry {
		sqc_tooltip_ptr tooltip;
		sqc::animation::animation_transformer_weak_ptr transform;
	};
	std::list<entry> m_entrys;
	surf::surf_point	m_scroll;
	surf::surf_val		m_zoom;
	surf::surf_font_ptr	m_font;
	std::map<sqc_string,surf::surf_image_ptr> m_icons_cache;
	void remove_entry( const sqc::animation::animation_transformer_ptr& tr );
};
typedef std::tr1::shared_ptr<sqc_tooltips_manager> sqc_tooltips_manager_ptr;

END_NAMESPACE_SQC_FRAMEWORK
