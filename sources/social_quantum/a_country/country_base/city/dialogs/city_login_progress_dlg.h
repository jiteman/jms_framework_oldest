/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_LOGIN_PROGRESS_DLG_H_INCLUDED__
#define __SQC_CITY_LOGIN_PROGRESS_DLG_H_INCLUDED__


#include "city_login_progress_dlg_layout.h"
#include "country_base/dialogs/sqc_login_progress_dlg.h"

NAMESPACE_SQC_FRAMEWORK


//
//	login progress window
//
class city_login_progress_window
    : public sqc_login_progress_window {
public:

	city_login_progress_window( milk::milk_widget_ptr p )
    	: sqc_login_progress_window( p,
                            city_dlg_layout::login_progress_dlg::dialog ) {
    }
    
    virtual ~city_login_progress_window();
    
protected:
    // initialization 
    virtual void on_init_dialog();
};

typedef std::tr1::shared_ptr<city_login_progress_window> city_login_progress_window_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_LOGIN_PROGRESS_DLG_H_INCLUDED__


