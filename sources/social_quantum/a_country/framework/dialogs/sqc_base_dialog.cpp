/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_base_dialog.h"
#include "../sqc_framework.h"
#include <functional>

NAMESPACE_SQC_FRAMEWORK

//
// sqc_texture_panel implementation
//

sqc_texture_panel::sqc_texture_panel( milk::milk_widget_ptr p, 
                  const dialog_layout& dialog_layout )
	: milk::milk_dialog( p )
	, m_dialog_layout( dialog_layout )
    , m_center_dialog( true )
{
	sqc_window_factory& factory = framework().windows_factory();
	m_window_ctx = factory.create_window_ctx();
}

void sqc_texture_panel::set_center_dialog(bool center)
{
	m_center_dialog = center;
}

// initialization 
void sqc_texture_panel::on_init_dialog() {
	milk::milk_dialog::on_init_dialog();
    
	// center dialog
	if (m_center_dialog) {
    	center_dialog();
    }

}

void sqc_texture_panel::create_background( const dialog_backgrounds& backrounds ) {
	sqc_window_factory& factory = framework().windows_factory();
	m_backing_img = factory.create_background( m_window_ctx, shared_from_this(), backrounds );
}

void sqc_texture_panel::render( surf::surf_context_ptr ctx ) {
	if (!m_backing_img) {
		milk::milk_dialog::render( ctx );
	}
}

// center dialog
void sqc_texture_panel::center_dialog() {
	sqc_window_factory& factory = framework().windows_factory();
	
	surf::surf_size dlg_size = m_dialog_layout.sizes().at( factory.get_theme_size() );
	surf::surf_rect dlg_rect( 0, 0, dlg_size.cx, dlg_size.cy );
	
	// center dialog by desktop, not by parent
	surf::surf_rect center_rect = factory.layout_child_rect( 
									  framework().windows().get_desktop(), 
									  dlg_rect,
									  layout_halignment_center|layout_valignment_center );
	
	// and set rect!!!
	set_rect( center_rect );
}

//
// sqc_message_box implementation
//

void sqc_message_box::set_properties( 
    const sqc_string& dlg_title, 
    const sqc_string& dlg_text,
    const sqc_string& button_text ) {
    
    m_dlg_title		= dlg_title;
    m_dlg_text		= dlg_text;
    m_button_text	= button_text;
}

void sqc_message_box::set_button_action( 
	milk::milk_callback& cb ) {
    m_callback = cb;
}


// initialization
void sqc_message_box::on_init_dialog() {
	sqc_texture_panel::on_init_dialog();
	draw_arg.type = milk::milk_dialog_type_alert;
	
	sqc_window_factory& factory = framework().windows_factory();
	
    sqc_theme_size theme_size = factory.get_theme_size();
	layout_size dlg_size = m_dialog_layout.sizes().at( theme_size );
    
    surf::surf_size size_title = calc_font_size( m_dlg_title, m_title_layout );
    surf::surf_size size_text = calc_font_size( m_dlg_text, m_text_layout );
    surf::surf_size size_button_text = calc_font_size( m_button_text, m_button_caption_layout );
    
    size_button_text.cy = m_button_layout.rects().at(theme_size).cy;
    size_button_text.cx += 2 * m_button_text_offset_min.at(theme_size);
    if ( size_button_text.cx < m_min_button_width.at(theme_size) ) {
        size_button_text.cx = m_min_button_width.at(theme_size);
    }

	surf::surf_rect rect_title;
    surf::surf_rect rect_text;
    surf::surf_rect rect_button;

	// calculate new dialog height
	int dialog_width = dlg_size.cx;
    int dialog_height =  m_anchors[message_box_top_title_offset].at(theme_size).y + 
                         size_title.cy + 5 +
                         m_anchors[message_box_top_text_offset].at(theme_size).y + 
                         size_text.cy + 5 +
                         m_anchors[message_box_top_button_offset].at(theme_size).y + 
                         size_button_text.cy + 5 +
                         m_anchors[message_box_bottom_button_offset].at(theme_size).y;
                     
    // calculate dialog controls rect
    {
        rect_button = surf::surf_rect( ( dialog_width - size_button_text.cx ) / 2,
                                         m_anchors[message_box_bottom_button_offset].at(theme_size).y,
                                         size_button_text.cx + 5,
                                         size_button_text.cy + 5);
                                        
        rect_text = surf::surf_rect( ( dialog_width - size_text.cx ) / 2,
                                       rect_button.y + rect_button.cy + 
                                    	  m_anchors[message_box_top_button_offset].at(theme_size).y,
                                       size_text.cx + 5,
                                       size_text.cy + 5 );
                                    
        rect_title = surf::surf_rect( ( dialog_width - size_title.cx ) / 2,
                                        rect_text.y + rect_text.cy +
                                    	    m_anchors[message_box_top_text_offset].at(theme_size).y,
                                        size_title.cx + 5,
                                        size_title.cy + 5 );
    }
    								

	// set new height of dialog
    {
        surf::surf_rect dlg_rect( 0, 0, dlg_size.cx, dialog_height );
       
        // expand rect
//        sqc_assert( m_background_img );
//        if ( m_background_img ) {
//            m_background_img->set_stretch( true );
//            m_background_img->set_rect( dlg_rect ) ;
//        }
        
        // center dialog by desktop, not by parent
        surf::surf_rect center_rect = factory.layout_child_rect( 
                                        framework().windows().get_desktop(), 
                                        dlg_rect,
                                        layout_halignment_center|layout_valignment_center );
        
        set_rect( center_rect );
    }
    
	// create title
    milk::milk_label_ptr title_label;
    {
        title_label = factory.create_label( m_window_ctx, shared_from_this(), m_title_layout );
        title_label->set_caption( m_dlg_title );
        title_label->set_rect( rect_title );
    }

	// create main text
    milk::milk_label_ptr text_label;
    {
		text_label = factory.create_label( m_window_ctx, shared_from_this(), m_text_layout );
        text_label->set_caption( m_dlg_text );
        text_label->set_rect( rect_text );
    }

	
	// create button
    milk::milk_theme_button_ptr button;
    milk::milk_label_ptr button_label;
    {
        button = factory.create_button( m_window_ctx, shared_from_this(), m_button_layout );
        button->set_rect( rect_button );
                        
        button->set_action( std::tr1::bind( 
                                &sqc_message_box::on_button_pressed, this ) );
            

        button_label =
        factory.create_label( m_window_ctx, button, m_button_caption_layout );
        button_label->set_caption( m_button_text );
    }
}

// button action
void sqc_message_box::on_button_pressed() {
	if ( m_callback ) {
	    m_callback();
    }
	sqc_texture_panel::end_dialog();
}

// calculate font size depend of label layout
surf::surf_size sqc_message_box::calc_font_size(
    const sqc_string& text,
    const label_layout&	label_layout ) {
    
	sqc_window_factory& factory = framework().windows_factory();
    sqc_theme_size theme_size = factory.get_theme_size();
    
	layout_size dlg_size = m_dialog_layout.sizes().at( theme_size );
    surf::surf_size init_size( dlg_size.cx, 0 );
    
    const layout_font_name& font_name	= label_layout.fnt_layout().names().at( theme_size );
    const layout_font_size font_size	= label_layout.fnt_layout().sizes().at( theme_size );
    
    surf::surf_rect rc_label = label_layout.rects().at( theme_size );
    
    init_size.cx -= 2 * rc_label.x;
    
    sqc_assert( m_window_ctx );
    surf::surf_font_ptr font = m_window_ctx->create_font( font_size, font_name.c_str() );
    if ( !font ) {
    	return surf::surf_size();
    }
    
    surf::surf_context_ptr ctx;
    return font->calc_size( ctx, text, init_size, label_layout.label_draw_flags() );
}


//
// sqc_dialog implementation
//


// initialization
void sqc_dialog::on_init_dialog() {
	set_bevel_type( milk::milk_bevel_type_content );
	sqc_texture_panel::on_init_dialog();
}

bool sqc_dialog::on_end_dialog() {
	return sqc_texture_panel::on_end_dialog();
}


bool sqc_dialog::get_dialog_init_arg( milk::milk_dialog_init_arg &arg ) {
	milk::milk_dialog::get_dialog_init_arg( arg );
    bool create_close_button	= false;
    bool create_back_button		= false;
    bool create_next_button		= false;
    
    create_close_button	= ( dialog_with_close_button == m_dialog_mode );
    create_close_button	|= ( dialog_with_back_and_close_button == m_dialog_mode );
    create_close_button	|= ( ( dialog_theme_style == m_dialog_mode) && 
                            	(dialog_has_close_button & m_dialog_theme_flags ) );
    
    create_back_button = ( dialog_with_back_button == m_dialog_mode );
    create_back_button |= ( dialog_with_back_and_close_button == m_dialog_mode ); 
    create_back_button	|= ( ( dialog_theme_style == m_dialog_mode) && 
                            	( dialog_has_back_button & m_dialog_theme_flags ) );
    
    create_next_button  = (dialog_with_next_button == m_dialog_mode);
    create_next_button	|= ( ( dialog_theme_style == m_dialog_mode) && 
                            	(dialog_has_next_button & m_dialog_theme_flags ) );
    
                                
                
    arg.has_back	= create_back_button;
    arg.has_close	= create_close_button;
    arg.has_next	= create_next_button;
    
	arg.center_dialog = m_center_dialog;
    return true;
}
	


/// separator vertical
milk::milk_separator_ptr	sqc_dialog::create_separator( const milk::milk_widget_ptr& place_to,const vertical_separator_layout& layout ) {
	if ( !m_window_ctx ) {
        sqc_assert( false );
        return milk::milk_separator_ptr();
    }
	
	milk::milk_window_server &server = get_server();
	milk::milk_theme &theme = server.get_theme();
	milk::milk_dialog_init_arg arg;
	surf::surf_rect client_rect  = get_rect();
	if (get_dialog_init_arg(arg)) {
		client_rect = theme.get_dialog_content_rect( client_rect , arg );
	}
	
	sqc_window_factory& factory = framework().windows_factory();
	// take current theme size
	sqc_theme_size theme_size = factory.get_theme_size();
	/// get offsets
	surf::surf_val bottom = layout.get_bottom().at(theme_size);
	surf::surf_val top = layout.get_top().at(theme_size);
	
	surf::surf_point p = factory.layout_position(client_rect,
										 surf::surf_point(layout.get_x().at(theme_size),0), 
										 layout_alignment(layout.alignment().mask()&layout_alignment_hmask));
	p.y = factory.layout_position(client_rect, 
						  surf::surf_point(0,0), 
						  layout_alignment(layout_valignment_center)).y;
	p+=client_rect.bottom_left();
	p-=get_rect().bottom_left();
	surf::surf_val l = client_rect.cy -  bottom - top;
	p.y+=int(bottom/2);
	p.y-=int(top/2);
	surf::surf_rect rc = surf::surf_rect( p, surf::surf_size(1,1) );
	
	milk::milk_separator_ptr separator = place_to->create_child<milk::milk_separator,milk::milk_separator_direction>( rc,milk::milk_separator_direction_vertical );
	separator->set_position( p );
	separator->set_length( l );
	separator->set_type( layout.get_type() );
	return separator;
}
/// separator horizontal
milk::milk_separator_ptr	sqc_dialog::create_separator( const milk::milk_widget_ptr& place_to,const horizontal_separator_layout& layout ) {
	if ( !m_window_ctx ) {
        sqc_assert( false );
        return milk::milk_separator_ptr();
    }
	sqc_window_factory& factory = framework().windows_factory();
	// take current theme size
	sqc_theme_size theme_size = factory.get_theme_size();
	
	milk::milk_window_server &server = get_server();
	milk::milk_theme &theme = server.get_theme();
	milk::milk_dialog_init_arg arg;
	surf::surf_rect client_rect  = get_rect();
	if (get_dialog_init_arg(arg)) {
		client_rect = theme.get_dialog_content_rect( client_rect , arg );
	}	
	surf::surf_point p = factory.layout_position(client_rect, 
										 surf::surf_point(0,layout.get_y().at(theme_size)), 
										 layout_alignment(layout.alignment().mask()&layout_alignment_vmask));
	p.x = factory.layout_position(client_rect, 
						  surf::surf_point(0,0), 
						  layout_alignment(layout_halignment_center)).x;
	p+=client_rect.bottom_left();
	p-=get_rect().bottom_left();
	p.x+=int(layout.get_left().at(theme_size)/2);
	p.x-=int(layout.get_right().at(theme_size)/2);
	surf::surf_val l = client_rect.cx - layout.get_left().at(theme_size) - layout.get_right().at(theme_size);
	surf::surf_rect rc = surf::surf_rect( p, surf::surf_size(1,1) );
	milk::milk_separator_ptr separator = place_to->create_child<milk::milk_separator,milk::milk_separator_direction>( rc,milk::milk_separator_direction_horizontal );
	separator->set_position( p );
	separator->set_length( l );
	separator->set_type( layout.get_type() );
	return separator;
}


END_NAMESPACE_SQC_FRAMEWORK