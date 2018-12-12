/*
 *  sqc_login_progress_dlg.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_login_progress_dlg.h"
#include "framework/sqc_framework.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// login progress window
//

sqc_login_progress_window::~sqc_login_progress_window() {
}

void sqc_login_progress_window::handle_timer( milk::surf_ddword tick ) {
	sqc_texture_panel::handle_timer( tick );
    
    if ( tick - m_prev_tick < 200 ) {
    	return;
    }
    
    m_prev_tick = tick;
    
    size_t idx_prev = m_image_idx;
    size_t idx_new = m_image_idx + 1;
    
	if ( m_image_idx + 1 >= m_images.size() ) {
	    idx_new = 0;
    }
    
    m_image_idx = idx_new;
    
    if ( m_images[idx_prev] ) {
	    m_images[idx_prev]->set_visible( false );
    }
    
    if ( m_images[idx_new] ) {
	    m_images[idx_new]->set_visible( true );
    }
}



END_NAMESPACE_SQC_FRAMEWORK