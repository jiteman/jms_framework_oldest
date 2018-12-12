/*
 *  sqc_login_progress_dlg.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SQC_LOGIN_PROGRESS_DLG_H_INCLUDED__
#define __SQC_SQC_LOGIN_PROGRESS_DLG_H_INCLUDED__

#include "framework/dialogs/sqc_base_dialog.h"

NAMESPACE_SQC_FRAMEWORK


//
//	login progress window
//
class sqc_login_progress_window
    : public sqc_texture_panel {
public:

	sqc_login_progress_window( milk::milk_widget_ptr p, 
    							const dialog_layout& dialog_layout )
    	: sqc_texture_panel( p, dialog_layout )
        , m_image_idx( 0 )
        , m_prev_tick( 0 ) {
    }
    
    virtual ~sqc_login_progress_window();
    
protected:
    // initialization 
    virtual void handle_timer( surf::surf_ddword tick );
    
    virtual bool fill_dialog_info( milk::milk_dialog_draw_arg &arg ) {
    	return false;
    }
    
protected:    
    typedef std::vector<milk::milk_image_ptr>	image_list;
    size_t 							m_image_idx;
    image_list						m_images;
    surf::surf_ddword 				m_prev_tick;
        
    //milk::milk_image_ptr			m_background_img;
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SQC_LOGIN_PROGRESS_DLG_H_INCLUDED__