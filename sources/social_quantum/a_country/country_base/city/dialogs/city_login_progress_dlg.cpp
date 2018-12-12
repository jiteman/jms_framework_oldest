/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_login_progress_dlg.h"
#include "city/city_framework.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

city_login_progress_window::~city_login_progress_window() {
}
//
// login progress window
//

// initialization 
void city_login_progress_window::on_init_dialog() {
    PROFILE_ENTRY( "city_login_progress_view::on_init_dialog" );
    
	sqc_login_progress_window::on_init_dialog();
    

	sqc_window_factory& factory = framework().windows_factory();
	using namespace city_dlg_layout::login_progress_dlg;
    
	create_background( city_dlg_layout::login_progress_dlg::backgrounds );
    
    if ( m_backing_img ) {
    	m_backing_img->set_stretch( true );
    }
    
    
    // stretch background image
    
    // load images
    m_images.resize( 4 );
    milk::milk_image_ptr img = factory.create_image( m_window_ctx, shared_from_this(), progress_indicator0 );
    m_images[0] = img;
    
    img = factory.create_image( m_window_ctx, shared_from_this(), progress_indicator1 );
    if ( img ) img->set_visible( false );
    m_images[1] = img;
    
    
    img = factory.create_image( m_window_ctx, shared_from_this(), progress_indicator2 );
    if ( img ) img->set_visible( false );
    m_images[2] = img;

    img = factory.create_image( m_window_ctx, shared_from_this(), progress_indicator3 );
    if ( img ) img->set_visible( false );
    m_images[3] = img;
}

END_NAMESPACE_SQC_FRAMEWORK