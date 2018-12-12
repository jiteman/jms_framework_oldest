/*
 *  sqc_tooltips.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 10/3/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_tooltips.h"
#include <animation/animation_animators.h>
#include <animation/animation_transformer.h>

NAMESPACE_SQC_FRAMEWORK

sqc_tooltip::sqc_tooltip( const surf::surf_color& color,
			const surf::surf_font_ptr& font,
			const sqc_string& text,
			const surf::surf_image_ptr& icon)
:	m_color(color)
,	m_font( font )
,   m_text( text )
,	m_icon( icon ) {
}

static const surf::surf_draw_string_flags font_flags = surf::draw_string_alignment_left |
	surf::draw_string_valignment_center |
	surf::draw_string_single_line |
	surf::draw_string_draw_shadow_disabled |
	surf::draw_string_adjust_font_size_disabled |
	surf::draw_string_truncation_disabled;

/*
 
 surf_size   calc_size( surf_context_ptr ctx, surf_string const &s, surf_size const &size, surf_draw_string_flags flags );
 void        draw( surf_context_ptr ctx, surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size );

*/

void sqc_tooltip::draw( const surf::surf_context_ptr& ctx ) {
	surf::surf_point pos;
	surf::surf_size text_size;
	if (m_font) {
		/// @todo need remove this hack
		text_size = m_font->calc_size( ctx, m_text, surf::surf_size(1024,64), font_flags );
		pos.x-=text_size.cx/2;
	}
	surf::surf_val h = text_size.cy;
	if (m_icon) {
		if (m_icon->get_size().cy>h) 
			h = m_icon->get_size().cy;
		pos.x-=m_icon->get_size().cx/2;
		pos.x-=2;
	}
	text_size.cy = h;
	pos.y-=h/2;
	if (m_font) {
		m_font->draw( ctx, m_text , pos, surf::surf_size(text_size.cx+1,text_size.cy+1), font_flags , m_color, m_color, surf::surf_size(0,0) );
		pos.x+=text_size.cx;
	}
	if (m_icon) {
		pos.y = -m_icon->get_size().cy/2;
		pos.x+=4;
		m_icon->draw( ctx, pos ); 
	}
}


sqc_tooltips_manager::sqc_tooltips_manager(  ) :  m_zoom(1.0) {
}

void sqc_tooltips_manager::render( const surf::surf_context_ptr& ctx  ) {
	std::list<entry>::iterator i = m_entrys.begin();
	while (i!=m_entrys.end()) {
		sqc::animation::animation_transformer_ptr transformer = i->transform.lock();
		if (transformer) {
			surf::surf_transform tr = ctx->get_transform();
			
			ctx->set_transform(tr.translated(m_scroll*-1).scaled(m_zoom));
			transformer->begin_draw( ctx );
				
			i->tooltip->draw( ctx );
			
			transformer->end_draw( ctx );
			
			ctx->set_transform(tr);
		}
		i++;
	}
}

void sqc_tooltips_manager::add_tooltips( const sqc_tooltips_data& tooltips , const surf::surf_point& tpos ) {
	if (tooltips.empty()) return;
	for (size_t i=0;i<tooltips.size();i++) {
		add_tooltip(i,tooltips[i],tpos);
	}
}

void sqc_tooltips_manager::add_tooltip( size_t index, const sqc_tooltip_data& data , const surf::surf_point& pos ) {
	surf::surf_image_ptr icon;
	if (!data.icon.empty()) {
		std::map<sqc_string,surf::surf_image_ptr>::iterator it = m_icons_cache.find( data.icon );
		if (it==m_icons_cache.end()) {
			sqc_string file = data.icon;
			if (framework().windows_factory().get_theme_size()==sqc_theme_normal)
				file+="@2x";
			else if (framework().windows_factory().get_theme_size()==sqc_theme_large)
				file+="_ipad";
			surf::surf_image_ptr img = framework().graphics().create_image( file.c_str() );
			m_icons_cache[data.icon] = img;
			icon = img;
		} else {
			icon = it->second;
		}
	}
	add_tooltip( sqc_tooltip_ptr( new sqc_tooltip( data.color,get_font(),data.text,icon ) ), pos, 0.4*index );
}

void sqc_tooltips_manager::add_tooltip(const sqc_tooltip_ptr& ptr , const surf::surf_point& pos, surf::surf_val pause ) {
	animation::animation_transformer_ptr tr = animation::animation_transformer_ptr( new animation::animation_transformer() );
	set_tooltip_animation( tr,pos, pause );
	entry e = { ptr, tr };
	m_entrys.push_back( e );
}
void sqc_tooltips_manager::remove_entry( const sqc::animation::animation_transformer_ptr& tr ) {
	std::list<entry>::iterator it =  m_entrys.begin();
	while (it!=m_entrys.end()) {
		if (it->transform.lock()==tr) it=m_entrys.erase(it);
		else it++;
	}
}
void sqc_tooltips_manager::set_tooltip_animation(const sqc::animation::animation_transformer_ptr& transformer , 
												 const surf::surf_point& pos,
												 surf::surf_val pause) {
	using namespace sqc::animation;
	surf::surf_val offset = (framework().windows_factory().get_theme_size()==sqc_theme_small) ? 100 : 150;
	framework().windows().animation().add_animator( transformer ,
												   animation_animator_sequency()
													.add( animation_animator_pause( pause ) )
													.add( animation_animator_group()
														  .add( animation_animator_translate(pos,pos+surf::surf_point(0,offset),2.0) )
														  .add( animation_animator_alpha(1,0,2.0) )
													) 
												   .add( animation_animator_event( std::tr1::bind( &sqc_tooltips_manager::remove_entry, this,transformer ) ) )
												) ;
}


END_NAMESPACE_SQC_FRAMEWORK