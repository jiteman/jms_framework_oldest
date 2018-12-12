/*
 *  sqc_texture_image_widget.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_proxy_texture_widget.h"
#include "framework/sqc_framework.h"
#include "country_base/dialogs/select_person/sqc_select_person_delegate.h"

NAMESPACE_SQC_FRAMEWORK
  
//
// sqc_proxy_texture_widget implementation
//
sqc_proxy_texture_widget::sqc_proxy_texture_widget( 
    milk::milk_widget_ptr p ) 
	: milk::milk_widget( p ) {
}

sqc_proxy_texture_widget::~sqc_proxy_texture_widget() {

}

void sqc_proxy_texture_widget::reset() {

    m_local_image.reset();
    m_texture.reset();
}

bool sqc_proxy_texture_widget::set_local_image( 
    const sqc_string& name ) {
    
    reset();
    
    m_local_image = framework().graphics().create_image( name.c_str() );
    
    return !!m_local_image;
}

bool sqc_proxy_texture_widget::set_texture( 
    const sqc_string& name ) {

    reset();
    
	m_texture = framework().texture_proxy().get_texture( name.c_str(), load_priority_now );
    if ( !m_texture ) {
    	sqc_error() << "texture_widget: unable to load texture for " << name;	
        return false;
    }

    return true;
}

bool sqc_proxy_texture_widget::set_remote_texture( 
    const sqc_string& uri, 
    const bool consider_social_network ) {
    
    reset();
    
    sqc_string name_texture = get_avatar_texture_name( uri );

	m_texture = framework().texture_proxy().get_remote_texture(//TODO 
                            uri.c_str(), name_texture.c_str(), "jpg", load_priority_now );
    if ( !m_texture ) {
    	sqc_error() << "texture_widget: unable to load remote texture for " << name_texture;	
        return false;
    }

    return true;
}

void sqc_proxy_texture_widget::render( 
	surf::surf_context_ptr ctx ) {
    
    surf::surf_rect client_rect = get_client_rect();
    
    if ( m_texture ) {
        sqc_texture_draw_info   draw_info;
        draw_info.set_stretch( client_rect.size(), true );
		m_texture->draw( ctx, client_rect.bottom_left(), draw_info );
    } else if ( m_local_image ) {
        m_local_image->draw( ctx, client_rect );
    }
}


END_NAMESPACE_SQC_FRAMEWORK