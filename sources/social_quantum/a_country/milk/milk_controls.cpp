/*
 *  milk_controls.cpp
 *  milk
 *
 *  Created by Andrey Yamov on 5/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "milk_controls.h"
#include "milk_server.h"

NAMESPACE_MILK


milk_window::milk_window( milk_widget_ptr p ) 
    : milk_widget( p )
{
}

void milk_window::render( surf_context_ptr ctx ) {
    milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();
    
    theme.draw_window( ctx, *this );
    
    milk_widget::render( ctx );
}

//
//	milk_dialog implementation
//
milk_dialog::milk_dialog( milk_widget_ptr p ) 
    : milk_widget( p )
{
	bevel_type = milk_bevel_type_none;
}

// run dialog
void milk_dialog::do_modal() {
	// notify windows server
	milk_window_server& server = get_server();	
	server.activate_modal( std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );

	// initialization
	on_init_dialog();
	on_post_init_dialog();
    
    invalidate();
}


// destroy dialog

void milk_dialog::end_dialog() {
    
	// notify windows server
	milk_window_server& server = get_server();
	server.deactivate_modal( std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
	
    invalidate();
	
	milk_theme &theme = get_server().get_theme();
	
    milk_dialog_init_arg arg;
	if( get_dialog_init_arg( arg ) ) {
		if (theme.on_end_dialog( *this, arg ))
			destroy();
    } else {
		destroy();
	}
}

void milk_dialog::on_destroy() {
	set_page(milk_dialog_page_ptr());
	// clear callbacks
	tabs.clear();
	milk_widget::on_destroy();
}


bool milk_dialog::get_dialog_init_arg( milk_dialog_init_arg &arg ) {
	arg.bevel = bevel_type;
	arg.title = get_caption();
	return false;
}

void milk_dialog::set_bevel_type( milk_bevel_type type ) {
	bevel_type = type; 
}

void milk_dialog::set_page( const milk_dialog_page_ptr& page ) {
	if (current_page) {
		current_page->on_end();
		current_page->destroy();
	}
	current_page = page;
	if (current_page) {
		current_page->on_init();
	}
}

void milk_dialog::render( surf_context_ptr ctx ) {
	milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();

	theme.draw_dialog( ctx, get_client_rect(), draw_arg );
}
	
// initialization 
void milk_dialog::on_init_dialog() {
}

void milk_dialog::on_post_init_dialog() {
	
	milk_theme &theme = get_server().get_theme();

    milk_dialog_init_arg arg ;
	if( get_dialog_init_arg( arg ) ) {
		theme.on_init_dialog( *this, arg , draw_arg);
		if (!tabs.empty()) {
			theme.init_dialog_tabs( *this, arg, draw_arg, tabs );
		}
    }
}

bool milk_dialog::on_end_dialog() {
	return true;
}

// button action
void milk_dialog::on_close_button_pressed() {
	if ( !on_end_dialog() ) {
    	return;
    }
    
    if ( close_callback ) {
        close_callback();
    }
    
	end_dialog();
}

 void milk_dialog::on_back_button_pressed() {
 
    if ( !on_end_dialog() ) {
     return;
    }
     
	if(back_callback) {
        back_callback();
    }
    

	end_dialog();
}

void milk_dialog::on_next_button_pressed() {

    if ( !on_end_dialog() ) {
    	return;
    }
    
	if(next_callback) {
        next_callback();
    }
    
	end_dialog();
}

void milk_dialog::set_back_button_action(milk_callback cb ) {
	back_callback = cb;
}

void milk_dialog::set_next_button_action(milk_callback cb ) {
	next_callback = cb;
}

void milk_dialog::set_close_button_action( milk_callback cb ) {
	close_callback = cb;
}

void milk_dialog::activate_tab( surf::surf_dword index ) {
	if (index < tabs.size() )
		tabs[index].activate();
}
void milk_dialog::set_tab_counter( surf::surf_dword index, int value ) {
	if (index < tabs.size() ) {
		if (tabs[index].set_counter) {
			tabs[index].set_counter(value);
		}
	}
}

surf::surf_dword milk_dialog::add_tab_def(const milk_dialog_tab_def& def) {
	surf::surf_dword res = tabs.size();
	tabs.push_back(def);
	return res;
}

//
//
//

milk_control::milk_control( milk_widget_ptr p ) 
    : milk_widget( p ) 
{
}


/// separator
milk_separator::milk_separator( milk_widget_ptr p , milk_separator_direction dir ) :milk_control(p){
	m_draw_arg.direction = dir;
}
void milk_separator::set_position( const surf::surf_point& pos ) {
	m_draw_arg.center = pos;
	recalculate_rect();
}
void milk_separator::set_type( milk_separator_type type ) {
	m_draw_arg.type = type;
}
void milk_separator::set_length( surf::surf_val len ) {
	m_draw_arg.length = len;
	recalculate_rect();
}
void milk_separator::recalculate_rect() {
	milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();
	if (m_draw_arg.direction==milk_separator_direction_vertical) {
		set_rect(surf::surf_rect(m_draw_arg.center.x-theme.get_metrics().separator_size/2,
								 m_draw_arg.center.y-m_draw_arg.length/2,
								 theme.get_metrics().separator_size,
								 m_draw_arg.length));
	} else if (m_draw_arg.direction==milk_separator_direction_horizontal){
		set_rect(surf::surf_rect(m_draw_arg.center.x-m_draw_arg.length/2,
								 m_draw_arg.center.y-theme.get_metrics().separator_size/2,
								 m_draw_arg.length,
								 theme.get_metrics().separator_size));
	}
}
void milk_separator::render( surf_context_ptr ctx ) {
	milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();
	milk_separator_draw_arg arg = m_draw_arg;
	arg.center -= get_rect().bottom_left();
	theme.draw_separator(ctx, arg);
}
//
//
//
milk_radio_group::milk_radio_group() {
}

milk_radio_group::~milk_radio_group() {
}

void milk_radio_group::add_to_group( milk_button_ptr button ) {
    m_buttons.push_back( button );
    button->set_group( this );
}

void milk_radio_group::set_active_button( milk_button_ptr button ) {
    for ( button_list::iterator it = m_buttons.begin();
        it != m_buttons.end(); ++it ) {
        
        if ( button != *it ) {
            (*it)->set_checked( false );
        }
    }
}

//
//
//
milk_button::milk_button( milk_widget_ptr p ) 
    : milk_label( p ) 
    , m_button_style(push_button)   
    , m_is_pressed( false )
    , m_is_checked( false )
    , m_is_active( true )
    , m_group( 0 )
{
}

void milk_button::render( surf_context_ptr ctx ) {
    milk_label::render( ctx );
}

bool milk_button::on_touch( milk_touch_info const &info ) {
    if ( !is_visible()) return false;
    if ( !is_active() ) return true;
    
    if ( info.action == touch_action_press ) {
        surf_info() << "button received event: " << info;
        get_server().set_capture( shared_from_this() );
        get_server().redraw();
        m_is_pressed = true;
    } else if ( info.action == touch_action_release ) {
        surf_info() << "button received event: " << info;
        get_server().release_capture( shared_from_this() );
        get_server().redraw();
		if (m_is_pressed) {
			m_is_pressed = false;
			if ( radio_button == m_button_style ) {
				set_checked( true );
			}
			fire_action();
		}
    }
    
    return true;
}

void milk_button::on_cancel_mode() {
    if ( m_is_pressed ) {
        surf_info() << "button received cancel mode";        
        get_server().release_capture( shared_from_this() );
        get_server().redraw();
        m_is_pressed = false;
    }    
}

bool milk_button::is_pressed() const {
    return m_is_pressed;
}

bool milk_button::is_checked() const {
    return m_is_checked;
}

void milk_button::set_checked( bool checked ) {
    if ( radio_button == m_button_style ) {
        m_is_checked = checked;
        if ( m_group && checked ) {
            milk_button_ptr ptr_this = std::tr1::static_pointer_cast<milk_button>(shared_from_this());
            m_group->set_active_button( ptr_this );
        }
        invalidate();
    }
}

void milk_button::set_action( milk_callback cb ) {
    m_action = cb;
}

void milk_button::fire_action() {
    surf_info() << "fire button action!";
    if( m_action ) {
        m_action();
    }
}

void milk_button::set_is_active( const bool is_active ) {
    m_is_active = is_active;
}

bool milk_button::is_active() const {
    return m_is_active;
}

milk_button_style milk_button::get_button_style() const {
    return m_button_style;
}

void milk_button::set_button_style( milk_button_style style ) {
    m_button_style = style;
}

void milk_button::set_group( milk_radio_group* group ) {
    m_group = group;
}
//
// image buttpn
//
milk_image_button::milk_image_button( milk_widget_ptr p ) 
    : milk_button( p ) 
{
    m_is_stretch_image = false;
}

void milk_image_button::render( surf_context_ptr ctx ) {
    surf_image_ptr image = is_active() ? ( is_pressed() ? m_pressed_image : m_normal_image ) : m_inactive_image;

    if ( image.get() != 0 ) {
        m_is_stretch_image ? image->draw( ctx, get_client_rect() ) : image->draw( ctx, surf_point() );
    }
    
    milk_label::render( ctx );
}

void milk_image_button::set_stretch( const bool flag ) {
    m_is_stretch_image = flag;
}

void milk_image_button::set_image( surf_image_ptr image ) {
    m_normal_image = image;
}

surf_image_ptr milk_image_button::get_image() const {
    return m_normal_image;
}

void milk_image_button::set_pressed_image( surf_image_ptr image ) {
    m_pressed_image = image;
}
surf_image_ptr milk_image_button::get_pressed_image() const {
    return m_pressed_image;
}

void milk_image_button::set_inactive_image( surf_image_ptr image ) {
    m_inactive_image = image;
}

surf_image_ptr milk_image_button::get_inactive_image() const {
    return m_inactive_image;
}

//
// Milk Theme Button
//

milk_theme_button::milk_theme_button( milk_widget_ptr p, milk::theme_button_type btype ) 
	: milk_button( p )
    , m_btype(btype)
{
}

milk::theme_button_type milk_theme_button::get_button_type() const
{
	return m_btype;
}

void milk_theme_button::render( surf_context_ptr ctx )
{
    milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();
	theme.draw_button( ctx, *this );
}


//
//
//
milk_label::milk_label( milk_widget_ptr p ) 
    : milk_control( p )
    , draw_flags ( 0 )
{
    text_color   = surf_color(1, 1, 1, 1);
    shadow_color = surf_color(0, 0, 0, 0);
    shadow_size  = surf_size(1, -1);
}

void milk_label::render( surf_context_ptr ctx ) {
    milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();

    theme.draw_label( ctx, *this );

    //
    // debug
    //
	if (surf::surf_font_ptr font = get_font()) 
		font->draw( ctx, get_caption(), surf_point(), get_rect().size(), get_draw_flags(), get_color(), get_shadow_color(), get_shadow_size() );
    
    milk_widget::render( ctx );
}

surf_draw_string_flags milk_label::get_draw_flags() const {
    return draw_flags;
}

void milk_label::set_color( surf_color c ) {
    text_color = c;
}

surf_color milk_label::get_color() const {
    return text_color;
}

void milk_label::set_shadow_color( surf_color c ) {
    shadow_color = c;
}

surf_color milk_label::get_shadow_color() const {
    return shadow_color;
}

void milk_label::set_shadow_size ( surf_size s ) {
    shadow_size = s;
}

surf_size milk_label::get_shadow_size() const {
    return shadow_size;
}

void milk_label::set_horizontal_alignment(surf_draw_string_flags ha) {
    draw_flags = (draw_flags & ~draw_string_alignment_mask) | (ha & draw_string_alignment_mask);
}

void milk_label::set_vertical_alignment(surf_draw_string_flags va) {
    draw_flags = (draw_flags & ~draw_string_valignment_mask) | (va & draw_string_valignment_mask);
}

void milk_label::set_truncation_mode(surf_draw_string_flags tm) {
    draw_flags = (draw_flags & ~draw_string_truncation_mask) | (tm & draw_string_truncation_mask);
}

void milk_label::set_multiline_enabled(bool e) {
    draw_flags = (draw_flags & ~draw_string_lines_mask);
    if( e ) {
        draw_flags |= draw_string_multi_line;
    }
    else {
        draw_flags |= draw_string_single_line;
    }
}

void milk_label::set_draw_shadow_enabled(bool e) {
    draw_flags = (draw_flags & ~draw_string_draw_shadow_mask);
    if( e ) {
        draw_flags |= draw_string_draw_shadow_enabled;
    }
    else {
        draw_flags |= draw_string_draw_shadow_disabled;
    }
}

void milk_label::set_adjust_font_size_enabled(bool e) {
    draw_flags = (draw_flags & ~draw_string_adjust_font_size_mask);
    if( e ) {
        draw_flags |= draw_string_adjust_font_size_enabled;
    }
    else {
        draw_flags |= draw_string_adjust_font_size_disabled;
    }
}

//
//	milk image
//
milk_image::milk_image( milk_widget_ptr p ) 
    : milk_label( p )
    , stretch_image( false )
    , is_rotated( false )
    , is_v_mirrored(false){
}

void milk_image::render( surf_context_ptr ctx ) {
    
    if( image ) {
        {
            if ( is_rotated || is_v_mirrored || stretch_image)
            {
                surf_draw_image_flags _flags = 0;
                
                if ( is_rotated )     _flags |= draw_image_rotated;
                if ( is_v_mirrored )  _flags |= draw_image_v_mirrored;                

                surf_rect rect_to = get_client_rect();
                surf_rect rect_from = surf_rect ( 0, 0, image->get_size().cx, image->get_size().cy );
                
                if (_flags)
                    image->draw( ctx, rect_to, rect_from, _flags );
                else 
                    image->draw(ctx, rect_to);
            }
            else
            {
                image->draw( ctx, surf_point() );
            }
        }
    }
}

void milk_image::set_image( surf_image_ptr i ) {
	image = i;
}

surf_image_ptr milk_image::get_image() const {
	return image;
}

void milk_image::set_stretch( bool flag ) {
    stretch_image = flag;
}

void milk_image::set_is_rotated( bool rotated )
{
    is_rotated = rotated;
}

void milk_image::set_is_v_mirrored( bool mirrored )
{
    is_v_mirrored = mirrored;
}

//
//	milk slice image
//


milk_slice_image::milk_slice_image( milk_widget_ptr p ) 
	: milk_control( p )
{
}

void milk_slice_image::render( surf_context_ptr ctx ) {
	if (image) {
    	image->draw( ctx, get_client_rect() );
    }
}

void milk_slice_image::set_image(surf_9way_image_ptr img) {
	image = img;
}

surf_9way_image_ptr milk_slice_image::get_image() const {
	return image;
}


/****
    class milk_slice_image : public milk_control {
    public:    
        milk_slice_image( milk_widget_ptr p );
        void render( surf_context_ptr ctx );
        
    private:
    };
****/

//
//	milk switch
//

milk_switch_button::milk_switch_button( milk_widget_ptr p )
	: milk_control( p )
	, callback( 0 )
	, state( switch_state_off ) {
}

// on and off properties
void milk_switch_button::set_on_properties(
	const surf_string& _on_text, 
	const surf_image_ptr _on_image,
	const surf_font_ptr _on_font,
	const surf_color& _on_text_color,
	const surf_color& _on_text_shadow_color,
	const surf_size& _on_text_shadow_size ) {
	
	on_text					= _on_text;
	on_image				= _on_image;
	on_font					= _on_font;
	on_text_color			= _on_text_color;
	on_text_shadow_color	= _on_text_shadow_color;
	on_text_shadow_size		= _on_text_shadow_size;
}

void milk_switch_button::set_off_properties( 
	const surf_string& _off_text, 
	const surf_image_ptr _off_image,
	const surf_font_ptr _off_font,
	const surf_color& _off_text_color,
	const surf_color& _off_text_shadow_color,
	const surf_size& _off_text_shadow_size ) {
	
	off_text				= _off_text;
	off_image				= _off_image;
	off_font				= _off_font;
	off_text_color			= _off_text_color;
	off_text_shadow_color	= _off_text_shadow_color;
	off_text_shadow_size	= _off_text_shadow_size;
}
	
// switch state
void milk_switch_button::set_state( switch_state s ) {
	state = s;
}

switch_state milk_switch_button::get_state() const {
	return state;
}
	
// store action
void milk_switch_button::set_action( switch_callback cb ) {
	callback = cb;
}
	
void milk_switch_button::render( surf_context_ptr ctx ) {
	
	// draw image
	{
		surf_image_ptr  image;
	
		if ( switch_state_off == state ) {
			image = off_image;
		}
		else if ( switch_state_on == state ) {
			image = on_image;
		}

		if ( image ) {
			image->draw( ctx, get_client_rect() );
		}
	}

	// draw text
	{
		surf_string& sel_text		= ( switch_state_on == state ? on_text : off_text );
		surf_font_ptr&	sel_font	= ( switch_state_on == state ? on_font : off_font );
		surf_color& sel_color		= ( switch_state_on == state ? on_text_color : off_text_color );
		surf_color& sel_shadow_color= ( switch_state_on == state ? on_text_shadow_color : off_text_shadow_color );
		surf_size& sel_shadow_size	= ( switch_state_on == state ? on_text_shadow_size : off_text_shadow_size );
		
		surf_draw_string_flags sel_draw_flags = draw_string_alignment_center |
											draw_string_valignment_center;
		
		surf_rect rect_client = get_client_rect();
		surf_point point;
		surf_size  size( rect_client.cx / 2, rect_client.cy );
		
		if ( switch_state_off == state ) {
			point.x = rect_client.cx / 2;
		}
		
		if ( sel_font ) {
			sel_font->draw( ctx, 
							 sel_text, 
							 point, 
							 size, 
							 sel_draw_flags, 
							 sel_color, 
							 sel_shadow_color, 
							 sel_shadow_size );
		}
	}
	
    milk_control::render( ctx );
}

bool milk_switch_button::on_touch( milk_touch_info const &info ) {
    if( info.action == touch_action_press ) {
        surf_info() << "switch received event: " << info;
        get_server().set_capture( shared_from_this() );
    }
    else if( info.action == touch_action_release ) {
        surf_info() << "switch received event: " << info;
        get_server().release_capture( shared_from_this() );
        state = ( (switch_state_off == state) ? switch_state_on : switch_state_off);
        get_server().redraw();
        
		fire_action();
    }
    return true;
}

void milk_switch_button::fire_action() {
	if ( callback ) {
		callback( get_state() );
	}
}



//	milk_bubble implementation
//
milk_bubble::milk_bubble( milk_widget_ptr p ) : milk_widget( p ) {
}

void milk_bubble::on_timer( surf_ddword tick ){

}

void milk_bubble::render( surf_context_ptr ctx ) {
	milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();
	
	milk_bubble_draw_arg arg = {};
	arg.caption = get_caption();
	theme.draw_bubble( ctx, surf::surf_rect(get_rect().size()), arg );
}

milk_bubble_metrics const& milk_bubble::get_metrics() const {
	return get_server().get_theme().get_bubble_metrics();
}

surf::surf_rect milk_bubble::get_client_rect() const {
	const milk_bubble_metrics &metrics = get_metrics();
	surf_rect rect = get_rect();
	rect.x=metrics.content_left_offset;
	rect.y=metrics.content_bottom_offset;
	rect.cx-=metrics.content_left_offset+metrics.content_right_offset;
	rect.cy-=metrics.content_top_offset+metrics.content_bottom_offset;
	return rect;
}

void milk_bubble::on_create() {
	milk_widget::on_create();
	
}

void milk_bubble::resize_client_to_window() {
	const milk_bubble_metrics &metrics = get_metrics();
	window_rect.x-=metrics.content_left_offset;
	window_rect.y-=metrics.content_bottom_offset;
	window_rect.cx+=metrics.content_left_offset+metrics.content_right_offset;
	window_rect.cy+=metrics.content_top_offset+metrics.content_bottom_offset;
	move(window_rect.bottom_left());
}

void milk_bubble::move( surf_point const &pos ) {
	window_rect.x = pos.x-window_rect.cx/2-get_metrics().tail_pos.x;
	window_rect.y = pos.y-get_metrics().tail_pos.y;
	invalidate();
}

// milk_bevel
//

milk_bevel::milk_bevel( milk_widget_ptr p ) : milk_control( p ) {
	m_type = milk_bevel_type_content;
}

void milk_bevel::render( surf_context_ptr ctx ) {
	milk_window_server &server = get_server();
	milk_theme &theme = server.get_theme();
	
	milk_bevel_draw_arg arg = {};
	arg.type = m_type;
	theme.draw_bevel( ctx, surf::surf_rect(get_rect().size()), arg );
}


milk_progress_bar::milk_progress_bar( milk_widget_ptr p )
	: milk_widget(p)
    , m_min(0)
    , m_max(100)
    , m_pos(0)
{
}

void milk_progress_bar::set_range( surf_val min, surf_val max )
{
	if (max < min) {
    	m_min = min;
        m_max = min+1;
        
    }
    else {
	    m_max = max;
    	m_min = min;
    }
}

void milk_progress_bar::set_pos( surf_val pos )
{
	m_pos = pos;
    
    int logical_width = m_max - m_min;
    
    if (logical_width == 0) {
    	logical_width = 1;
    }
    
    if (pos < 0) {
        m_pos=0;
    }
    
    if (m_pos > logical_width) {
        m_pos = logical_width;
	}
        
    surf::surf_rect r = get_client_rect();
    
    surf::surf_val npos =floor( m_pos * r.cx * 1. / logical_width );
    
	m_bar_rect = surf::surf_rect(r.x, r.y, npos, r.cy );
}

void milk_progress_bar::set_image( surf_9way_image_ptr image)
{
	m_image = image;
}

void milk_progress_bar::render( surf_context_ptr ctx ) {
	//milk_window_server & server = get_server();
	//milk_theme & theme = server.get_theme();
    
    if( m_image ) {
        m_image->draw( ctx, m_bar_rect );
    }
    
	
}


END_NAMESPACE_MILK
