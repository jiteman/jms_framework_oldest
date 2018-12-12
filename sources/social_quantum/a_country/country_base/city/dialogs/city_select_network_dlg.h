/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SELECT_NETWORK_DLG_H_INCLUDED__
#define __SQC_CITY_SELECT_NETWORK_DLG_H_INCLUDED__

#include "city_select_network_dlg_layout.h"
#include "country_base/dialogs/sqc_select_network_dlg.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_select_network_dlg implementation
//
class city_select_network_dlg 
    : public sqc_select_network_dlg  {
public:
	city_select_network_dlg( milk::milk_widget_ptr p,
						    const sqc_select_network_params params ) 
		: sqc_select_network_dlg( p, 
                city_dlg_layout::select_network_dlg::background, 
                params ) {
	}
    virtual ~city_select_network_dlg();
	
protected:
	// initialization 
	virtual void on_init_dialog();
	
	virtual milk::milk_widget_ptr on_create_cell( 
    							const sqc_network_type network_type,
                                surf::surf_rect const &rect_cell,
                                milk::milk_callback& cell_action,
                                sqc_word idx);
                                
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);  
};

typedef std::tr1::shared_ptr<city_select_network_dlg>	city_select_network_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SELECT_NETWORK_DLG_H_INCLUDED__


