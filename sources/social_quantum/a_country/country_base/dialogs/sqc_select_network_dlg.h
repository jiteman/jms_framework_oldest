/*
 *  sqc_select_network_dlg.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SQC_SELECT_NETWORK_DLG_H_INCLUDED__
#define __SQC_SQC_SELECT_NETWORK_DLG_H_INCLUDED__

#include "framework/dialogs/sqc_base_dialog.h"
#include "framework/social_network/sqc_social_network_defs.h"
#include "country_base/sqc_country_base_ui.h"

NAMESPACE_SQC_FRAMEWORK

typedef std::vector<sqc_network_type>  network_vector;
//
// sqc_select_network_dlg implementation
//
class sqc_select_network_dlg
    : public sqc_dialog
    , public milk::milk_spinboard_callbacks {
public:
	sqc_select_network_dlg( milk::milk_widget_ptr p,
						    const dialog_layout& dialog_layout,
						    const sqc_select_network_params params );
    virtual ~sqc_select_network_dlg();
	
protected:
	// initialization 
	virtual void on_init_dialog();
    virtual bool on_end_dialog();
	
public:
    // milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
    virtual int get_cell_count();
    
    virtual milk::milk_widget_ptr on_create_cell( const sqc_network_type network_type,
    								surf::surf_rect const &rect_cell,
							    	milk::milk_callback& cell_action,
                                    sqc_word idx ) = 0;
protected:
    // user press change network button
    void on_network_pressed( const sqc_network_type network_type );
    
        
    virtual sqc_dword get_visible_count();
        
protected:
    milk::milk_spinboard_ptr    		m_spinboard;
    network_vector              		m_available_networks;
    
    sqc_select_network_params			m_params;
    sqc_word                            m_visible_count;
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SQC_SELECT_NETWORK_DLG_H_INCLUDED__


