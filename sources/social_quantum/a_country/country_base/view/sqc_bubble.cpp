/*
 *  sqc_bubble.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_bubble.h"
#include "country_base/sqc_framework_base.h"

NAMESPACE_SQC_FRAMEWORK

sqc_bubble_caption_entry::sqc_bubble_caption_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) : sqc_bubble_entry(font,def,layout){
	sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
	m_shadow_size = m_layout.font.shadow_size.at(theme_size);
}
surf::surf_size sqc_bubble_caption_entry::calc_size( surf::surf_val width ) const  {
	return calc_text_size( width,m_def.text );
}
void sqc_bubble_caption_entry::draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const {
	draw_text( ctx, m_rect, m_def.text );
}

surf::surf_size sqc_bubble_caption_entry::calc_text_size( surf::surf_val width, const sqc_string& text ) const {
	return m_font->calc_size( surf::surf_context_ptr(), text, surf::surf_size(width,1024), 
							 m_layout.font.draw_string_flags );
}
void sqc_bubble_caption_entry::draw_text( surf::surf_context_ptr ctx, const surf::surf_rect& rect , const sqc_string& text) const {
	m_font->draw( ctx, text, rect.bottom_left(),rect.size(), 
				 m_layout.font.draw_string_flags ,
				 m_layout.font.color, m_layout.font.shadow_color, m_shadow_size);
}


sqc_bubble_info_entry::sqc_bubble_info_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) : sqc_bubble_caption_entry(font,def,layout)  {
	sqc_string icon_file = m_def.icon;
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme_size = factory.get_theme_size();
	if (theme_size == sqc_theme_normal)
		icon_file+="@2x";
	else if (theme_size == sqc_theme_large)
		icon_file+="_ipad";
	m_texture = sqc::framework::framework().texture_proxy().get_texture(icon_file.c_str(),load_priority_now);
	m_icon_offset = m_layout.icon_space.at(theme_size);
}
surf::surf_size sqc_bubble_info_entry::calc_size( surf::surf_val width ) const  {
	return calc_size_for_text( width, m_def.text );
}
void sqc_bubble_info_entry::draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const {
	draw_with_text( ctx, m_def.text );
}
surf::surf_size sqc_bubble_info_entry::calc_size_for_text( surf::surf_val width, const sqc_string& text ) const  {
	if (m_texture) {
		width-=m_texture->get_size().cx;
		width-=m_icon_offset;
	}
	surf::surf_size size = calc_text_size(width, text);
	if (m_texture) {
		size.cx += m_texture->get_size().cx;
		size.cx += m_icon_offset;
		if (size.cy<m_texture->get_size().cy) {
			size.cy = m_texture->get_size().cy;
		}
	}
	return size;
}
void sqc_bubble_info_entry::draw_with_text(surf::surf_context_ptr ctx,const sqc_string& text ) const {
	surf::surf_rect text_rect = m_rect;
	if (m_texture) {
		text_rect.x+=m_texture->get_size().cx;
		text_rect.x+=m_icon_offset;
		text_rect.cx-=m_texture->get_size().cx;
		text_rect.cx-=m_icon_offset;
		surf::surf_point pos = m_rect.bottom_left();
		if (m_rect.cy>m_texture->get_size().cy) {
			pos.y += (m_rect.cy-m_texture->get_size().cy)/2;
		}
		sqc_texture_draw_info draw_info;
		m_texture->draw( ctx, pos , draw_info.set_use_anchor(false));
	}
	draw_text(ctx,text_rect,text);
}


sqc_bubble_time_entry::sqc_bubble_time_entry( surf::surf_font_ptr font, const sqc_bubble_element& def , const sqc_bubble_entry_layout& layout) : sqc_bubble_info_entry(font,def,layout){
}
surf::surf_size sqc_bubble_time_entry::calc_size( surf::surf_val width ) const  {
	sqc_string str = m_def.text;
	size_t pos = str.find(sqc_bubble_time_marker);
	if (pos!=str.npos) {
		str.replace( pos,sqc_bubble_time_marker_length,framework::framework().formats().get_time_mask());
	} else {
		str = framework::framework().formats().get_time_mask();
	}
	return calc_size_for_text( width,str );
}
void sqc_bubble_time_entry::draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const {
	sqc_string str = m_def.text;
	size_t pos = str.find(sqc_bubble_time_marker);
	int time = (m_def.value>live_time) ? ( (m_def.value - live_time)/1000 ) : 0;
	if (pos!=str.npos) {
		str.replace( pos,sqc_bubble_time_marker_length,framework::framework().formats().format_time( time ));
	} else {
		str = framework::framework().formats().format_time( time );
	}
	draw_with_text( ctx, str );
}



sqc_bubble_button_entry::sqc_bubble_button_entry( surf::surf_font_ptr font, const sqc_bubble_element& def, const sqc_bubble_entry_layout& layout ) : sqc_bubble_caption_entry( font,def,layout) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme_size = factory.get_theme_size();
	sqc_string button_file = m_layout.button.at(theme_size);
	m_btn_texture = sqc::framework::framework().texture_proxy().get_texture(button_file.c_str(),load_priority_now);
}

surf::surf_size sqc_bubble_button_entry::calc_size( surf::surf_val width ) const  {
	surf::surf_size size = sqc_bubble_caption_entry::calc_size( width );
	if (m_btn_texture) {
		if (m_btn_texture->get_size().cx>size.cx)
			size.cx = m_btn_texture->get_size().cx;
		if (m_btn_texture->get_size().cy>size.cy)
			size.cy = m_btn_texture->get_size().cy;
	}
	return size;
}
void sqc_bubble_button_entry::draw(surf::surf_context_ptr ctx, sqc_ddword live_time ) const {
	surf::surf_rect text_rect = m_rect;
	if (m_btn_texture) {
		surf::surf_point pos = m_rect.bottom_left();
		if (m_rect.cy>m_btn_texture->get_size().cy) {
			pos.y += (m_rect.cy-m_btn_texture->get_size().cy)/2;
		}
		sqc_texture_draw_info draw_info;
		m_btn_texture->draw( ctx, pos , draw_info.set_use_anchor(false));
	}
	draw_text(ctx,text_rect,m_def.text);
}



sqc_bubble::sqc_bubble( milk::milk_widget_ptr parent, const sqc_bubble_layout& layout ) : milk::milk_bubble( parent ), m_layout(layout)
{
	sqc_window_factory& factory = framework().windows_factory();
	m_window_ctx = factory.create_window_ctx();
	m_update_time = clock_msec();
	
    sqc_theme_size theme_size = factory.get_theme_size();
	
	m_caption_font = m_window_ctx->create_font( m_layout.caption_font.font.sizes().at(theme_size),m_layout.caption_font.font.names().at(theme_size) );
	m_text_font = m_window_ctx->create_font( m_layout.entry.font.font.sizes().at(theme_size),m_layout.entry.font.font.names().at(theme_size) );
	
}

sqc_bubble_entry_ptr sqc_bubble::generate_entry( sqc_bubble_element const& element ) {
	if (element.tag=="caption") {
		return sqc_bubble_entry_ptr(new sqc_bubble_caption_entry(m_caption_font, element, m_layout.entry ));
	} else if (element.tag=="info") {
		return sqc_bubble_entry_ptr(new sqc_bubble_info_entry(m_text_font, element,m_layout.entry ));
	} else if (element.tag=="status") {
		return sqc_bubble_entry_ptr(new sqc_bubble_status_entry(m_text_font, element,m_layout.entry ));
	} else if (element.tag=="button") {
		return sqc_bubble_entry_ptr(new sqc_bubble_button_entry(m_text_font, element ,m_layout.entry));
	} else if (element.tag=="time") {
		return sqc_bubble_entry_ptr(new sqc_bubble_time_entry(m_text_font, element ,m_layout.entry));
	}
	return sqc_bubble_entry_ptr();
}



struct line_def {
	std::vector<sqc_bubble_entry_ptr> elements;
	surf::surf_val y;
	surf::surf_val width;
	surf::surf_val height;
};

void sqc_bubble::set_content( sqc_bubble_content const &content )
{
	m_action_callback = content.action_callback;
	m_default_action = content.default_action;
	
	sqc_window_factory& factory = framework().windows_factory();
    sqc_theme_size theme_size = factory.get_theme_size();
	surf::surf_val width = m_layout.width.at(theme_size);
	
	for (size_t i=0;i<content.elements.size();i++) {
		sqc_bubble_entry_ptr entry =  generate_entry( content.elements[i] );
		if (entry)
			m_entrys.push_back( entry );
	}
	
	/// layout elements origin: top-left
	surf::surf_point current = surf::surf_point(0,0);
	surf::surf_val cx_content_space = m_layout.items_space.at(theme_size).cx;
	surf::surf_val cy_content_space = m_layout.items_space.at(theme_size).cy;
	std::vector< line_def > lines;
	lines.push_back( line_def() );
	lines.back().y = 0;
	lines.back().width = 0;
	lines.back().height = 0;
	for (size_t i=0;i<m_entrys.size();i++) {
		sqc_bubble_entry_ptr entry(m_entrys[i]);
		surf::surf_size size = entry->calc_size( width );
		entry->set_rect( surf::surf_rect( size ) );
		if (entry->allow_horizontal_layout() && (current.x+size.cx)<width) {
	        lines.back().width+=size.cx;
			current.x += size.cx + cx_content_space;
			if (!lines.back().elements.empty())
				lines.back().width+=cx_content_space;
	        if( lines.back().height < ( size.cy ) ) {
                lines.back().height = size.cy;
            }
			lines.back().elements.push_back( entry );
		} else {
			if (!lines.back().elements.empty()) {
				current.y += lines.back().height+cy_content_space;
				lines.resize(lines.size()+1);
				lines.back().y = current.y;
			}
			lines.back().width = size.cx;
			lines.back().height = size.cy;
			lines.back().elements.push_back(entry);
            current.x = 0;
			/// single line
			if (!entry->allow_horizontal_layout()) {
				current.y += lines.back().height+cy_content_space;
				lines.resize(lines.size()+1);
				lines.back().y = current.y;
				lines.back().width = 0;
				lines.back().height = 0;
			}
    	}
	}
	if (lines.empty()) 
		return;
	if (lines.back().elements.empty()) {
		lines.pop_back();
	}
	if (lines.empty()) 
		return;
	current.y=lines.back().y+lines.back().height;
    
    if( current.y < 1 ) {
        current.y = 1;
    }
	
	window_rect = surf::surf_rect( surf::surf_size( width, current.y ) );
	resize_client_to_window();
	surf::surf_rect rect = get_client_rect();
	
	current.y = 0;
	if (rect.cy < m_layout.min_height.at(theme_size) ) {
		/// center verticaly
		/*surf::surf_val offset = (m_layout.min_height.at(theme_size)-rect.cy)/2;;
		for (size_t i=0;i<lines.size();i++) {
			lines[i].y+=offset;
		}*/
		window_rect = surf::surf_rect( surf::surf_size( width, m_layout.min_height.at(theme_size) ) );
		resize_client_to_window();
		rect = get_client_rect();
		
	}
	current.x = 0;
	
	
	/// layout all lines, origin: bottom-left
	for (size_t i=0;i<lines.size();i++) {
		surf::surf_val x = ( width - lines[i].width)/2 ;
		for (size_t j=0;j<lines[i].elements.size();j++) {
			sqc_bubble_entry_ptr entry(lines[i].elements[j]);
			surf::surf_rect element_rect = entry->get_rect();
			element_rect.cy = lines[i].height;
			element_rect.y = ceilf( rect.y+rect.cy-lines[i].y-lines[i].height );
			element_rect.x = ceilf( rect.x+x );
			element_rect.cx = ceilf( element_rect.cx+1 );
			element_rect.cy = ceilf( element_rect.cy+1 );
			entry->set_rect( element_rect );
			x+=element_rect.cx + cx_content_space;
		}
	}
	
	}

void sqc_bubble::on_timer( sqc_ddword time ) {
    bool _toredraw = false;
    milk::milk_bubble::on_timer( time );
    for (size_t i=0;i<m_entrys.size();i++) {
            m_entrys[i]->on_timer(time, _toredraw);
        }
    if (_toredraw){
        invalidate();
    }

}


void sqc_bubble::render( surf::surf_context_ptr ctx ) {
	milk::milk_bubble::render( ctx );
	for (size_t i=0;i<m_entrys.size();i++) {
		sqc_ddword now = clock_msec();
		m_entrys[i]->draw(ctx,now-m_update_time);
	}
}

bool sqc_bubble::on_touch( milk::milk_touch_info const &touch ) {
	if (!m_action_callback) return false;
    if (!get_client_rect().point_in_rect(touch.points[0])) return false;
	if ( touch.action == milk::touch_action_press ) {
        for (size_t i=0;i<m_entrys.size();i++) {
			if (m_entrys[i]->can_process_touch()) {
				if (m_entrys[i]->get_rect().point_in_rect( touch.points[0] )) {
					m_action_callback( m_entrys[i]->get_action(), m_entrys[i]->get_action_params() ); 
					invalidate();
					return true;
     			}
			}
		}
        if ( m_default_action != action_nop ) {
            m_action_callback( m_default_action, sqc_action_params_ptr() );
            return true;
        }
    } else if (touch.action == milk::touch_action_release) {
        return true;
    }
	return false;
}

void sqc_bubble::on_field_updated(sqc_ddword time_stamp) {
	m_update_time = time_stamp;
}


END_NAMESPACE_SQC_FRAMEWORK