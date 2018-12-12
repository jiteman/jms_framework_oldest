#pragma once

#include "animation_defs.h"
#include "../surf/surf_defs.h"

NAMESPACE_ANIMATION

class animation_transformer {

public:
	animation_transformer();
	/// translate
	const surf::surf_point& translate() const { return m_translate;}
	void set_translate( const surf::surf_point& tr ) { m_translate = tr;}
	/// anchor
	const surf::surf_point& anchor() const { return m_anchor;}
	void set_anchor( const surf::surf_point& tr ) { m_anchor = tr;}
	/// scale
	const surf::surf_point& scale() const { return m_scale;}
	void set_scale( const surf::surf_point& s ) { m_scale = s;}
	void set_scale( surf::surf_val s ) { m_scale = surf::surf_point(s,s);}
	/// color
	const surf::surf_color& color() const { return m_color;}
	void set_color( const surf::surf_color& c) { m_color = c;}
	void set_alpha( surf::surf_val a ) { m_color.a = a; }
	
	/// apply methods
	void begin_draw( const surf::surf_context_ptr& ctx );
	void end_draw( const surf::surf_context_ptr& ctx );
private:
	surf::surf_point	m_translate;
	surf::surf_point	m_anchor;
	surf::surf_point	m_scale;
	surf::surf_color	m_color;
	struct surf_ctx_state {
		surf::surf_transform transform;
		surf::surf_color color;
	};
	surf_ctx_state	m_state;
	bool	m_in_draw;
};

typedef std::tr1::shared_ptr<animation_transformer>	animation_transformer_ptr;

END_NAMESPACE_ANIMATION
