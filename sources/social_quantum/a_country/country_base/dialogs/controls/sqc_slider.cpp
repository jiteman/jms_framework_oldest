/*
 *  sqc_slider.cpp
 *  aCountry dialog implementation
 *
 *  Created by Bacil (albacil@gmail.com) on 16.08.2011.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "framework/sqc_framework.h"
#include "sqc_slider.h"
#include <math.h>
#include "sqc_slider_layout.h"

NAMESPACE_SQC_FRAMEWORK
using namespace layout;

//
//  sqc_slider
//

sqc_slider::sqc_slider(milk::milk_widget_ptr p)
	: milk_widget(p) 
    , m_pressed(false)
	, m_factory( framework().windows_factory() )
    , m_theme_size(m_factory.get_theme_size() )
    , m_touchx(0)
    , m_dtouchx(0)
    , m_pinx(0)
    , m_max(100)
    , m_min(0)
    , m_pos(0)
    , m_step(0)
{
}

void sqc_slider::layout_controls( sqc_window_factory_ctx_ptr window_ctx)
{
	// preparing images for the Spin control
    layout_string str_image_n = slider::ibt_slpin.names().at( m_theme_size );
	layout_string str_image_p = slider::ibt_slpin.pressed_names().at( m_theme_size );
	m_normal_image = window_ctx->create_image( str_image_n.c_str() );
	m_pressed_image = window_ctx->create_image( str_image_p.c_str() );

	// create gutter
	
	surf::surf_9way_info gutter_info( slider::offs_gutter.at(m_theme_size) );
	m_img_gutter_ptr.reset( new surf::surf_9way_image() );

    m_img_gutter_ptr->create( 
		slider::img_gutter.at(m_theme_size).c_str(),
		gutter_info,
		framework().graphics()
	);
}

void sqc_slider::render( surf::surf_context_ptr ctx )
{
	surf::surf_image_ptr image;
    surf::surf_rect r = gutter_rect();
   
    layout_rect pinr = slider::ibt_slpin.rects().at(m_theme_size);
    if (m_img_gutter_ptr) {

		r.cx += slider::gutter_x_margins[m_theme_size]*2;
        r.x -= slider::gutter_x_margins[m_theme_size];

        r.cy = slider::gutter_height[m_theme_size];
        r.y = r.cy/2;
        m_img_gutter_ptr->draw( ctx, r );
    }

    image = m_pressed ? m_pressed_image : m_normal_image;
	
    if (image) {
        //image->draw( ctx, surf::surf_point(m_pinx - pinr.cx/2, 0) );
        image->draw( ctx, surf::surf_point( pos_to_x( pos() ) - pinr.cx/2, 0) );
	}
}

bool sqc_slider::on_touch( milk::milk_touch_info const &info ) {
    
	// touch_action_press
	// touch_action_release
	// touch_action_move
    
    surf::surf_rect r = gutter_rect();
    layout_rect pinr = slider::ibt_slpin.rects().at(m_theme_size);
    surf::surf_val tx = info.points[0].x;

    switch (info.action) {
        case milk::touch_action_press: {
            //surf::surf_info() << "slider received event: " << info;
            get_server().set_capture( shared_from_this() );
            get_server().redraw();
            m_pressed = true;
            m_touchx = tx;
            
            // verify that a click is inside the button
            if (tx >= m_pinx && tx <= m_pinx + pinr.cx) {
                // get drag offset
                m_dtouchx = tx - m_pinx;
            }

            set_pos( x_to_pos(tx) );
            break;
        }
        case milk::touch_action_release: {
            //surf::surf_info() << "button received event: " << info;
            get_server().release_capture( shared_from_this() );
            get_server().redraw();
            m_pressed = false;
            break;
        }
        case milk::touch_action_move:
            /*
            // check going beyond the left border
            if ( (tx - dtouchx_ + pinr.cx/2) < r.x ) {
                pinx_ = r.x - pinr.cx/2;
            }

            // check going beyond the right border
            else if ( (tx - dtouchx_ + pinr.cx/2) > (r.x + r.cx) ) {
                pinx_ = r.x + r.cx - pinr.cx/2;
            }
            else {
            	if (step_) {
                	stepx(tx);
                }
                else {
                	pinx_ = tx - dtouchx_;
                }
            }
            */
            
            /* debug
            surf::surf_info() << "x:" << info.points[0].x;
            surf::surf_info() << "pinx_:" << pinx_;
            surf::surf_info() << "pos:" << pos(info.points[0].x);
            */
             
            set_pos( x_to_pos( info.points[0].x ) );

			break;
            
        default:
            break;
    }
    
    return true;
}


// convert pix to logical point
surf::surf_val sqc_slider::x_to_pos(int x) {
	// p = l/w * x;
    return x * (m_max - m_min) / gutter_rect().cx;
}

void sqc_slider::set_pos(float p) {
	// x = w/l * p
    
    // prevent out of bounds
    if (p > m_max) {
        p = m_max;
    }
    
    if (p < m_min) {
        p = m_min;
    }
    
    float cpos = p;

    if (m_step) {
        cpos = round( p / m_step ) * m_step;
    }

	m_pos = cpos;
    
    m_pinx = pos_to_x(m_pos);

    if ( m_on_change) {
        m_on_change(m_pos);
    }
}

// convert logical position to pixels
surf::surf_val sqc_slider::pos_to_x(float pos)
{
    return pos * (gutter_rect().cx / (m_max - m_min) );
}


surf::surf_val sqc_slider::pos()
{
	return m_pos;
}

void sqc_slider::set_min(int min) {
	m_min = min;
}

int sqc_slider::min() {
	return m_min;
}

void sqc_slider::set_max(int max) {
	m_max = max;
}

int sqc_slider::max() {
	return m_max;
}

void sqc_slider::set_step(int step)
{
    m_step = step;
}

void sqc_slider::set_on_change(on_change cb)
{
	m_on_change = cb;
}

double sqc_slider::round(double r) {
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

surf::surf_rect sqc_slider::gutter_rect()
{
	surf::surf_rect r( get_client_rect() );
    r.cy = slider::gutter_height[m_theme_size];
    r.cx -= slider::gutter_x_margins[m_theme_size]*2;
    return r;
}

END_NAMESPACE_SQC_FRAMEWORK

