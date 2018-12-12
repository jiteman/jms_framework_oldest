/*
 *  milk_spinboard.cpp
 *  aCountry
 *
 *  Created by Andrey Yamov on 6/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "milk_spinboard.h"
#include "milk_server.h"

NAMESPACE_MILK

//
//
//
milk_spinboard::milk_spinboard( milk_widget_ptr p, milk_spinboard_callbacks_ptr cb , milk_spinboard_theme_flags flags)
: milk_scroll_area( p ) 
, callbacks( cb )
, visible_count( 0 )
, pages_count( 0 )
, selected_page( 0 )
, rows_count( 1 )
, m_theme_flags( flags )
{
    milk_metrics const &metrics = get_server().get_theme().get_metrics();
    visible_count = metrics.spinboard_visible_count;
    cx_item_spacing = metrics.spinboard_item_spacing_cx;
    cx_scroll_distance = metrics.spinboard_scroll_to_page_distance;
	m_left_fade = m_right_fade = metrics.spinboard_fade;
    assert( visible_count );
}

void milk_spinboard::set_rows_count( int rc ) {
    rows_count = rc;
    update_layout();
}

void milk_spinboard::set_visible_count( int ic ) {
    assert( visible_count );
    visible_count = ic;
    update_layout();
}

void milk_spinboard::set_item_spacing( int cx ) {
    cx_item_spacing = cx;
    update_layout();
}

void milk_spinboard::set_left_fade( int size ) { 
	m_left_fade = size;
	set_clip_children( !((m_left_fade||m_right_fade)&&get_graphics().full_render_to_target_supported()) );
}

void milk_spinboard::set_right_fade( int size ) { 
	m_right_fade = size;
	set_clip_children( !((m_left_fade||m_right_fade)&&get_graphics().full_render_to_target_supported()) );
}

void milk_spinboard::set_on_page_change( const std::tr1::function<void(int)>& callback ) {
	m_on_page_change = callback;
}

void milk_spinboard::set_on_pages_count_change( const std::tr1::function<void(int)>& callback ) {
	m_on_pages_count_change = callback;
}

surf_size milk_spinboard::calc_size( surf_size const &cell_size ) {
    return surf_size( cell_size.cx * visible_count + cx_item_spacing * (visible_count+1), cell_size.cy );
//    return surf_size( cell_size.cx * visible_count / rows_count + cx_item_spacing * (visible_count+1), cell_size.cy * rows_count );
}


void milk_spinboard::on_create() {
    cells.resize( callbacks->get_cell_count() );
    set_clip_children( !((m_left_fade||m_right_fade)&&get_graphics().full_render_to_target_supported()) );
    set_scroll_childrens( true );
    set_limited_wait( false );
    set_enable_vertical_scroll( false );
    
    update_layout();
	milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();
    
    theme.on_init_spinboard(*this,m_theme_flags);
}

void milk_spinboard::on_destroy() {
	/// for remove crosslinks in functions
	m_on_page_change = 	std::tr1::function<void(int)>();
	m_on_pages_count_change = std::tr1::function<void(int)>();
	milk_scroll_area::on_destroy();
}

surf_rect milk_spinboard::get_item_rect( int n ) {
    
    if (rows_count == 1){
        return surf_rect( n*cell_size.cx+(n+1)*cx_item_spacing, 0, cell_size.cx, cell_size.cy );
    }
    
    int c = n % 2;
    
    switch (c) {
        case 0:
            return surf_rect( n*cell_size.cx/2 + (n + 1)*cx_item_spacing, cell_size.cy + cx_item_spacing, cell_size.cx, cell_size.cy );
            break;
            
        case 1:   
            return surf_rect( (n-1)*cell_size.cx/2 + (n)*cx_item_spacing, 0, cell_size.cx, cell_size.cy );
        default:
            break;
    }
    
    return surf_rect( n*cell_size.cx+(n+1)*cx_item_spacing, 0, cell_size.cx, cell_size.cy );
}


void milk_spinboard::handle_render( surf::surf_context_ptr ctx ) {
    
    //PROFILE_ENTRY( "milk_widget::handle_render" );
    
    int idx_from = selected_page*visible_count-visible_count;
    int idx_to = selected_page*visible_count+visible_count*2;

	if (!m_rendertaget && (m_left_fade||m_right_fade) && get_graphics().full_render_to_target_supported() ) {
		m_rendertaget = get_graphics().create_target( get_client_rect().size().cx,get_client_rect().size().cy, false );
	}
	surf::surf_context_state state;
	if (m_rendertaget) {
		m_rendertaget->bind(ctx);
		ctx->store_state(state);
		m_rendertaget->clear(surf::surf_color(0,0,0,0));
		ctx->set_transform( surf::surf_transform().translated(get_rect().bottom_left()*-1) );
	}
	
    for( int n = 0; n != cells.size(); ++n ) {
        milk_widget_ptr child = cells[n];
        bool    visible = (n > idx_from && n < idx_to);
        
        if( !child ) {
            if( !visible ) {
                continue;
            }
            child = callbacks->create_cell( n, surf_rect( cell_size ) );
            
            if (!child){
                continue;
            }
            
            cells[n] = child;
        }

        child->set_visible( visible );
        
        surf_rect rect_cell = get_item_rect( n );
        
        rect_cell = rect_cell - get_scroll_pos();
        
        child->set_rect( rect_cell );
		
		if (m_rendertaget && visible) {
			ctx->set_transform( surf::surf_transform().translated( int(rect_cell.x), rect_cell.y ) );
			child->handle_render( ctx );
		}
    }
    //
	if (m_rendertaget) {
		m_rendertaget->unbind(ctx);
		ctx->restore_state(state);
	} else {
		milk_scroll_area::handle_render( ctx );
	}
	
	if (m_rendertaget) {
		surf::surf_image_ptr img = m_rendertaget->get_image();
		surf::surf_color old_clr = ctx->get_color();
		/// premultiply alpha
		surf::surf_color color = surf::surf_color(old_clr.r*old_clr.a,old_clr.g*old_clr.a,old_clr.b*old_clr.a,old_clr.a);
		ctx->set_color( color );
		if (img) {
											   
			surf::surf_rect rect = surf::surf_rect(m_left_fade,0,get_rect().cx-m_left_fade-m_right_fade,get_rect().cy);
			img->draw( ctx, rect,surf::surf_rect(rect.x,img->get_size().cy-rect.cy,rect.cx,rect.cy) );
			surf::surf_image_corners_color colors;	   
			/// left fade
			if (m_left_fade) {
				colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = surf::surf_color(0,0,0,0);
				colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = color;
				rect = surf::surf_rect(0,0,m_left_fade,get_rect().cy);
				img->draw( ctx, rect,surf::surf_rect(rect.x,img->get_size().cy-rect.cy,rect.cx,rect.cy), colors );
			}
			/// right fade
			if (m_right_fade) {
				colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = color;
				colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = surf::surf_color(0,0,0,0);
				rect = surf::surf_rect(get_rect().cx-m_right_fade,0,m_right_fade,get_rect().cy);
				img->draw( ctx, rect,surf::surf_rect(rect.x,img->get_size().cy-rect.cy,rect.cx,rect.cy) , colors);
			}
		}
		ctx->set_color( old_clr );
	}
}

void milk_spinboard::update_layout() {
    surf_rect   rect = get_client_rect();

    cell_size.cx = int ((rect.cx - (visible_count+1) * (cx_item_spacing) ) / (visible_count / rows_count));
    cell_size.cy = rect.cy / rows_count;
        
    int cell_count = cells.size() + visible_count - 1;
    pages_count = cell_count/visible_count;
    if (m_on_pages_count_change)
		m_on_pages_count_change(pages_count);
    surf_rect   scroll_area( 0, 0, get_item_rect( pages_count*visible_count ).x, cell_size.cy );
    set_scroll_area( scroll_area );
    set_active_page( selected_page, false );
}


int milk_spinboard::get_active_page() {
    return selected_page;
}

void milk_spinboard::set_active_page( int page, bool animated ) {
    if( page > pages_count-1 ) page = pages_count-1;
    if( page < 0 ) page = 0;
    
    selected_page = page;
    
    surf_point  new_scroll;
    new_scroll.x = get_item_rect( selected_page * visible_count ).x - cx_item_spacing;
    if (m_on_page_change) 
		m_on_page_change(selected_page);
	if (animated)
		animated_scroll( new_scroll );
	else {
		reset_scroll();
		set_scroll_pos( new_scroll, true );
	}
}

int     milk_spinboard::get_pages_count() {
	return pages_count;
}


void milk_spinboard::on_scroll_complete() {
    surf_point  scroll_pos = get_scroll_pos() + calculate_dynamic_target();
    surf_point  page_scroll_pos( get_item_rect( selected_page*visible_count ).x, scroll_pos.y );
    
    int page_no = selected_page;
    if( scroll_pos.x - page_scroll_pos.x > cx_scroll_distance ) ++page_no;
    if( scroll_pos.x - page_scroll_pos.x < -cx_scroll_distance ) --page_no;
    
    set_active_page( page_no, true );
}


void milk_spinboard::render( surf_context_ptr ctx ) {
    milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();
    
    theme.draw_spinboard( ctx, *this );
    
	
 //   milk_widget::render( ctx );
}

milk_spinboard_cells milk_spinboard::get_cells() {
    return cells;
}


/// pager impl

milk_spinboard_pager::milk_spinboard_pager( milk::milk_widget_ptr p) : milk::milk_scroll_area(p) {
	set_scroll_childrens( false );
	set_limited_wait( true );
	set_enable_vertical_scroll( false );
	m_step = 25;
	m_one_visible = false;
	set_centered( true );
}

void milk_spinboard_pager::on_create() {
	milk_scroll_area::on_create();
	milk_window_server &server = get_server();
    milk_theme &theme = server.get_theme();
    
    theme.on_init_pager(*this);
}

void milk_spinboard_pager::on_destroy() {
	// remove crosslinks
	m_on_select = std::tr1::function<void(int)>();
	milk_scroll_area::on_destroy();
}

void milk_spinboard_pager::set_normal_image( const surf::surf_image_ptr& img ) {
	m_normal_image = img;
}

void milk_spinboard_pager::set_active_image( const surf::surf_image_ptr& img ) {
	m_pressed_image = img;
}

void milk_spinboard_pager::set_step( surf::surf_val step ) {
	m_step = step;
}

void milk_spinboard_pager::set_one_page_visible( bool v ) {
	m_one_visible = v;
}
static const surf::surf_val fade_width = 12;
void milk_spinboard_pager::pager_button::render( surf::surf_context_ptr ctx , const surf::surf_point& pos, 
			surf::surf_val left_hide, 
			surf::surf_val right_hide,
			const surf::surf_image_ptr& normal_image,
			const surf::surf_image_ptr& pressed_image) {
	surf::surf_image_ptr image =  ( (m_active) ? pressed_image : normal_image );
	
	if ( image.get() != 0 ) {
		surf::surf_rect draw_rect( pos.x - image->get_size().cx/2,pos.y-image->get_size().cy/2,image->get_size().cx,image->get_size().cy);
		surf::surf_image_corners_color colors;
		if ((left_hide-fade_width)>draw_rect.right())
			return;
		if (right_hide<=(draw_rect.x-fade_width)) 
			return;
		if (left_hide>draw_rect.x && left_hide<=draw_rect.right()) {
			surf::surf_val part = left_hide-draw_rect.x;
			surf::surf_val w = std::min(part,fade_width);
			surf::surf_rect rect = draw_rect;
			rect.x+= part;
			rect.cx-=part;
			image->draw( ctx, rect, surf::surf_rect( part,image->get_size().cy-rect.cy,rect.cx,rect.cy) );
			rect.x = draw_rect.x+part-w;
			rect.cx = w;
			colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = surf::surf_color(1,1,1,0);
			colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = ctx->get_color();
			image->draw( ctx, rect, surf::surf_rect( part-w,image->get_size().cy-rect.cy,rect.cx,rect.cy) , colors );
		} else if ((left_hide-fade_width)>draw_rect.x && (left_hide-fade_width)<=draw_rect.right()) {
			surf::surf_val part = draw_rect.right()-(left_hide-fade_width);
			surf::surf_rect rect = draw_rect;
			rect.x= draw_rect.x+draw_rect.cx-part;
			rect.cx=part;
			colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = surf::surf_color(1,1,1,0);
			colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = surf::surf_color(1,1,1,part/fade_width);
			image->draw( ctx, rect, surf::surf_rect( draw_rect.cx-part,image->get_size().cy-rect.cy,rect.cx,rect.cy),colors );
		} else if (right_hide>draw_rect.x && right_hide<=draw_rect.right()) {
			surf::surf_val part = right_hide-draw_rect.x;
			surf::surf_rect rect = draw_rect;
			rect.cx = part;
			rect.x = draw_rect.x;
			image->draw( ctx, rect, surf::surf_rect( 0,image->get_size().cy-rect.cy,rect.cx,rect.cy) );
			surf::surf_val w = std::min(draw_rect.cx-part,fade_width);
			rect.x = draw_rect.x+part;
			rect.cx= w;
			colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = ctx->get_color();
			colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = surf::surf_color(1,1,1,0);
			image->draw( ctx, rect, surf::surf_rect( part,image->get_size().cy-rect.cy,rect.cx,rect.cy) ,colors);
		} else if ((right_hide+fade_width)>draw_rect.x && (right_hide+fade_width)<=draw_rect.right()) {
			surf::surf_val part = (right_hide+fade_width)-draw_rect.x;
			surf::surf_rect rect = draw_rect;
			rect.cx = part;
			rect.x = draw_rect.x;
			colors[surf::surf_image_corner_bottom_left]=colors[surf::surf_image_corner_top_left] = surf::surf_color(1,1,1,part/fade_width);
			colors[surf::surf_image_corner_bottom_right]=colors[surf::surf_image_corner_top_right] = surf::surf_color(1,1,1,0);
			image->draw( ctx, rect, surf::surf_rect( 0,image->get_size().cy-rect.cy,rect.cx,rect.cy),colors);
		} else {
			image->draw( ctx, draw_rect.bottom_left() );
		}
	}
}


bool milk_spinboard_pager::on_touch( milk::milk_touch_info const &touch ) {
	if (touch.point_count==1) {
		surf::surf_point pos = touch.points[0]+get_scroll_pos();
		int index = (pos.x+m_step/2)/m_step;
		if (index>=0 && index<m_buttons.size()) {
			if (touch.action==milk::touch_action_press) {
				for (int i=0;i<m_buttons.size();i++) {
					m_buttons[i].set_pressed(i==index);
				}
				//return true;
			} else if (touch.action==milk::touch_action_release) {
				if (m_buttons[index].on_release()) {
					if (m_on_select) 
						m_on_select(index);
				}
				for (int i=0;i<m_buttons.size();i++) {
					m_buttons[i].set_pressed(false);
				}
				//return true;
			}
		}
	}
	return milk::milk_scroll_area::on_touch( touch );
}

void milk_spinboard_pager::render( surf::surf_context_ptr ctx ) {
	if (!m_normal_image) return;
	if (m_buttons.size()<1) return;
	if (m_buttons.size()==1 && !m_one_visible) return;
	surf::surf_val left_hide = 0+fade_width;
	surf::surf_val right_hide = left_hide + get_client_rect().cx - fade_width*2;
	surf::surf_point pos = get_scroll_pos()*-1;
	pos.y = get_client_rect().cy/2;
	for (size_t i=0;i<m_buttons.size();i++) {
		m_buttons[i].render( ctx, pos, left_hide, right_hide , 
							m_normal_image, m_pressed_image ? m_pressed_image : m_normal_image );
		pos.x += m_step;
	}
}
void milk_spinboard_pager::set_pages( int pages ) {
	m_buttons.resize( pages );
	set_scroll_area( surf::surf_rect(-m_step,0,pages*m_step+m_step,get_client_rect().cy ) );
}
void milk_spinboard_pager::set_active_page( int page ) {
	if (page<m_buttons.size()) {
		for (int i=0;i<m_buttons.size();i++) {
			m_buttons[i].set_active(i==page);
		}
		surf::surf_val pos = page*m_step-get_client_rect().cx/2;
		animated_scroll( surf::surf_point( pos , 0) );
	}
}
void milk_spinboard_pager::set_on_select( const std::tr1::function<void(int)>& fun ) {
	m_on_select = fun;
}

static void milk_spinboard_pager_active_page_changed_proxy( const milk_spinboard_pager_ptr& pager, 
														   const std::tr1::function<void(int)>& old,int page) {
	pager->set_active_page( page );
	if (old) old(page);
}
static void milk_spinboard_pager_pages_count_changed_proxy( const milk_spinboard_pager_ptr& pager, 
														   const std::tr1::function<void(int)>& old,int pages) {
	pager->set_pages( pages );
	if (old) old(pages);
}

void milk_spinboard_pager::bind( const milk_spinboard_ptr& spinboard ) {
	spinboard->set_on_page_change( std::tr1::bind( &milk_spinboard_pager_active_page_changed_proxy,
												  std::tr1::static_pointer_cast<milk_spinboard_pager>(shared_from_this()),
												  spinboard->get_on_page_change(),
												  std::tr1::placeholders::_1) );
	spinboard->set_on_pages_count_change( std::tr1::bind( &milk_spinboard_pager_pages_count_changed_proxy,
												  std::tr1::static_pointer_cast<milk_spinboard_pager>(shared_from_this()),
												  spinboard->get_on_pages_count_change(),
												  std::tr1::placeholders::_1) );
	set_on_select(std::tr1::bind(&milk_spinboard::set_active_page,spinboard,std::tr1::placeholders::_1,false));
}


END_NAMESPACE_MILK