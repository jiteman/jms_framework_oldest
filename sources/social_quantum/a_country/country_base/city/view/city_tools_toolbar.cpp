//
//  city_tools_toolbar.cpp
//  aCountry
//
//  Created by Andrey Kunitsyn on 10/27/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include "city_tools_toolbar.h"

#include "country_base/sqc_framework_base.h"
#include "country_base/tools/sqc_tools_common.h"

#include "city_country_view_layout.h"
#include "city_tools_toolbar_layout.h"

NAMESPACE_SQC_CITY



sqc_city_tools_toolbar::sqc_city_tools_toolbar(  ) {
    m_visible = false;
}

sqc_city_tools_toolbar::~sqc_city_tools_toolbar() {
}

void sqc_city_tools_toolbar::create_buttons(const milk::milk_widget_ptr& parent) {
    
	
	m_buttons[delete_button]	= create_button( parent, delete_button );
    m_buttons[move_button]		= create_button( parent, move_button );
    m_buttons[apply_button]		= create_button( parent, apply_button );
    m_buttons[cancel_button]	= create_button( parent, cancel_button );
    m_buttons[warehouse_button]	= create_button( parent, warehouse_button );
    m_buttons[market_button]	= create_button( parent, market_button );
    
	enable_buttons( delete_button, false );
    enable_buttons( move_button, false );
    enable_buttons( apply_button, false );
    enable_buttons( cancel_button, false );
    enable_buttons( warehouse_button, false );
    enable_buttons( market_button, false );
    
	set_visible( false );    
}


void sqc_city_tools_toolbar::on_button_clicked( 
                                               const button_kind kind ) {
    if (m_callback) m_callback( kind );
}

void sqc_city_tools_toolbar::set_visible( bool v ) {
    for (size_t i=0;i<count_of;i++) {
        m_buttons[i]->set_visible( v );
    }
}


void sqc_city_tools_toolbar::show_toolbar() {
    tools::sqc_tools_controlles &controller = framework::country_framework().tools();
    if ( controller.get_active_tool() == tools::tool_type_buy ) {
        m_buttons[cancel_button]    ->set_visible(true);
        m_buttons[apply_button]     ->set_visible(true);
        m_buttons[move_button]      ->set_visible(false);
        m_buttons[delete_button]    ->set_visible(false);
        m_buttons[warehouse_button] ->set_visible(false);
        m_buttons[market_button]    ->set_visible(true);
        m_visible = true;
    } else if ( controller.get_active_tool() == tools::tool_type_edit ) {
        m_buttons[cancel_button]    ->set_visible(true);
        m_buttons[apply_button]     ->set_visible(true);
        m_buttons[move_button]      ->set_visible(true);
        m_buttons[delete_button]    ->set_visible(true);
        m_buttons[warehouse_button] ->set_visible(true);
        m_buttons[market_button]    ->set_visible(false);
        m_visible = true;
    } else {
        set_visible(false);
    }
}

void sqc_city_tools_toolbar::hide_toolbar() {
	set_visible( false );
    m_visible = false;
}

void sqc_city_tools_toolbar::enable_buttons( 
                                            button_kind kind, 
                                            bool enable ) {
    
    
    milk::milk_image_button_ptr	ptr_button = find_button( kind );
    if ( !ptr_button ) {
    	sqc_assert( false );
    	return;
    }
    
    ptr_button->set_is_active( enable );
    
}

void sqc_city_tools_toolbar::set_action( 
                                        toolbar_callback callback ) {
    m_callback = callback;
}


milk::milk_image_button_ptr	sqc_city_tools_toolbar::create_button( 
                                                                  const milk::milk_widget_ptr& parent,
                                                                  const button_kind btn ) {
    
    framework::sqc_window_factory& factory = sqc::framework::framework().windows_factory();
	framework::sqc_theme_size theme = factory.get_theme_size();
    
    surf::surf_rect rc;
    
    size_t row = 0;
    size_t col = 0;
    
    switch (btn) {
        case delete_button:
            col = 2;
            break;
        case warehouse_button:
            col = 1;
            break;
        case apply_button:
            row = 1;
            break;
        case cancel_button:
            break;
        case move_button:
            row = 2;
            break;
        case market_button:
            row = 2;
            break;
            
        default:
            assert( false && "unknown button" );
            break;
    }
    rc.x = city_country_view_layout::right_col_x[theme]+city_country_view_layout::col_step[theme]*col;
    rc.y = city_country_view_layout::bottom_row_y[theme]+city_country_view_layout::row_step[theme]*row;
    rc.cx = city_country_view_layout::icon_button_width[theme];
    rc.cy = city_country_view_layout::icon_button_height[theme];
    rc = factory.layout_child_rect(parent, rc, city_country_view_layout::tools::layout );
    
    milk::milk_image_button_ptr	ptr_button = 
    parent->create_child<milk::milk_image_button>( rc );
    
    ptr_button->set_action( std::tr1::bind( &sqc_city_tools_toolbar::on_button_clicked, this, btn ) );
    
    const toolbar_button_layout* layout = find_button_layout( btn );
    if ( !layout ) {
    	sqc_assert( false );
    }
    sqc_string str_img			= layout->unpressed().at( theme );
    sqc_string str_pressed_img	= layout->pressed().at( theme );
    sqc_string str_inactive_img	= layout->disabled().at( theme );
    
    ptr_button->set_image( sqc::framework::framework().graphics().create_image( str_img.c_str() ) );
    ptr_button->set_pressed_image( sqc::framework::framework().graphics().create_image( str_pressed_img.c_str() ) );
    ptr_button->set_inactive_image( sqc::framework::framework().graphics().create_image( str_inactive_img.c_str() ) );
    
    return ptr_button;
}

milk::milk_image_button_ptr	sqc_city_tools_toolbar::find_button( 
                                                                const button_kind btn ) {
    
    int idx = (int)btn;
    if ( idx < 0 || idx >= count_of ) {
	    return milk::milk_image_button_ptr();
    }
    return m_buttons[idx];
}

const toolbar_button_layout* sqc_city_tools_toolbar::find_button_layout( 
                                                                        const button_kind kind ) {
    
    if ( delete_button == kind )		 return &city_country_view_layout::tools::delete_button;
    else if ( move_button == kind )		 return &city_country_view_layout::tools::move_button;
    else if ( apply_button == kind )	 return &city_country_view_layout::tools::apply_button;
    else if ( cancel_button == kind )	 return &city_country_view_layout::tools::cancel_button;
    else if ( warehouse_button == kind ) return &city_country_view_layout::tools::warehouse_button;
    else if ( market_button == kind )    return &city_country_view_layout::tools::market_button;
    
    sqc_assert( false );
}


END_NAMESPACE_SQC_CITY
