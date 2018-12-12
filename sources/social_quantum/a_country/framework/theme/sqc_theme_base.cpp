/*
 *  sqc_theme_base.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/9/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_theme_base.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

sqc_theme_base::sqc_theme_base( surf::surf_graphics_server& gs ) : m_graphics_server(gs), m_loaded(false) {
	
}


surf::surf_9way_image_ptr sqc_theme_base::create_9way_image( const char* file,
															 const surf::surf_rect& offset,
															 bool draw_center ,
															 surf::surf_draw_image_flags flags ) {
	surf::surf_9way_info  info( offset.x, offset.y, offset.cx, offset.cy );
	info.tile_flag = flags;
	info.draw_center = draw_center;
	
	surf::surf_9way_image_ptr image = surf::surf_9way_image_ptr( new surf::surf_9way_image() );
	image->create( file, info, m_graphics_server );
	return image;
}

surf::surf_9way_image_ptr sqc_theme_base::create_9way_image( const image_names& name, const slice_offsets& slices,bool draw_center,
											surf::surf_draw_image_flags flags ) {
	sqc_theme_size  current_theme = framework().windows_factory().get_theme_size();
	surf::surf_9way_info  info = slices.at( current_theme );
	info.tile_flag = flags;
	info.draw_center = draw_center;
	surf::surf_9way_image_ptr image = surf::surf_9way_image_ptr( new surf::surf_9way_image() );
	image->create( name.at( current_theme ).c_str(), info, m_graphics_server );
	return image;
}


bool sqc_theme_base::load_all() {
	if (!m_loaded) {
		preload();
		m_loaded = true;
	}
	return true;
}

void sqc_theme_base::set_button_def( milk::theme_button_type type, const theme_button_def& def ) {
	m_buttons_map[type].def = def;
}

surf::surf_9way_image_ptr sqc_theme_base::get_button_skin( milk::theme_button_type button_type, theme_button_def::button_skin skin) {
	ButtonsMap::iterator it = m_buttons_map.find(button_type);
	if (it!=m_buttons_map.end()) {
		surf::surf_9way_image_ptr image = it->second.images[skin];
		if (!image) {
			sqc_theme_size current_theme = framework().windows_factory().get_theme_size();
			sqc_string back_name = it->second.def.skins[skin].at( current_theme );
			if (!back_name.empty()) {
				image = surf::surf_9way_image_ptr( new surf::surf_9way_image() );
				image->create( back_name.c_str(),it->second.def.slice.at( current_theme ) , framework().graphics() );
				it->second.images[skin] = image;
			}
		}
		return image;
	}	
	return surf::surf_9way_image_ptr();
}

void sqc_theme_base::draw_button( surf::surf_context_ptr ctx, milk::milk_theme_button &w )  {
	ButtonsMap::iterator it = m_buttons_map.find(w.get_button_type());
	if (it!=m_buttons_map.end()) {
		theme_button_def::button_skin skin = theme_button_def::button_skin_normal;
		if (w.is_pressed() || w.is_checked()) {
			skin = theme_button_def::button_skin_pushed;
		}
		if (w.is_disabled()) {
			skin = theme_button_def::button_skin_disabled;
		}
		surf::surf_9way_image_ptr image = it->second.images[skin];
		sqc_theme_size current_theme = framework().windows_factory().get_theme_size();
        while (!image) {
			sqc_string back_name = it->second.def.skins[skin].at( current_theme );
			if (back_name.empty()) {
				/// if not set normal skin draw nothing
				if (skin==theme_button_def::button_skin_normal) {
					break;
				}
				/// if skin not set use normal skin
				skin = theme_button_def::button_skin_normal;
				image = it->second.images[skin];
			} else {
				image = surf::surf_9way_image_ptr( new surf::surf_9way_image() );
				image->create( back_name.c_str(),it->second.def.slice.at( current_theme ) , framework().graphics() );
				it->second.images[skin] = image;
			}
		}
		if (image) image->draw( ctx, w.get_client_rect() );
	}
}

surf::surf_rect sqc_theme_base::get_dialog_content_rect( const surf::surf_rect& rect, const milk::milk_dialog_init_arg& init_arg ) {
	surf::surf_rect res = rect;
	res.x+=init_arg.bevel_left;
	res.y+=init_arg.bevel_bottom;
	res.cx-=init_arg.bevel_left+init_arg.bevel_right;
	res.cy-=init_arg.bevel_top+init_arg.bevel_bottom;
	return res;
}

END_NAMESPACE_SQC_FRAMEWORK
