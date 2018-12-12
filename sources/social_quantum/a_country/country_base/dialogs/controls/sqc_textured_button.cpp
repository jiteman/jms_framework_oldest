/*
 *  sqc_textured_button.cpp
 *  aCountry
 *
 *  Created by Ilya Radinsky on 25.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "sqc_textured_button.h"
#include "framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK
  
sqc_textured_button::sqc_textured_button( 
    milk::milk_widget_ptr p ) 
	: milk::milk_button( p ) {
}

bool sqc_textured_button::set_texture( 
    const sqc_string& name ) {

	m_texture = framework().texture_proxy().get_texture( name.c_str(), load_priority_now );
    if ( !m_texture ) {
    	sqc_error() << "texture_widget: unable to load texture for " << name;	
        return false;
    }

    return true;
}

void sqc_textured_button::render( 
	surf::surf_context_ptr ctx ) {
    if ( m_texture ) {
        surf::surf_rect client_rect = get_client_rect();
        sqc_texture_draw_info   draw_info;
        draw_info.set_stretch( client_rect.size(), true );
		m_texture->draw( ctx, client_rect.bottom_left(), draw_info );
    }
}


END_NAMESPACE_SQC_FRAMEWORK