/*
 *  sqc_select_person_dlg.h
 *  aCountry
 *	The file contains a base class for select people dialog
 *  Created by Vasily Alioshechkin (albacil@gmail.com) on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_SELECT_PERSON_DLG_H_INCLUDED__
#define __SQC_SELECT_PERSON_DLG_H_INCLUDED__

#include "country_base/sqc_framework_base.h"
#include "framework/dialogs/sqc_base_dialog.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"
#include "sqc_select_person_delegate.h"

NAMESPACE_SQC_FRAMEWORK

/// Base class for select people dialog
/// Class is abstract


class sqc_select_person_dlg
	: public sqc_dialog
    , public milk::milk_spinboard_callbacks
{
public:
	sqc_select_person_dlg(
    	milk::milk_widget_ptr p, 
        const dialog_layout& dialog_layout, 
        const spinboard_layout& spinboard_layout,
        sqc_select_preson_delegate_ptr delegate,
		int visible_cell);
    virtual ~sqc_select_person_dlg();
	
protected:
    // initialization 
	virtual void on_init_dialog();
	
public:
    virtual milk::milk_widget_ptr create_cell( int idx, 
                                surf::surf_rect const &rect ) = 0;
    virtual int get_cell_count();
    
    sqc_proxy_texture_widget_ptr create_texture_widget(
                                        milk::milk_widget_ptr p, 
                                        int idx, layout_rect rect, 
                                        layout_alignment alignment);
    sqc_person_info_list_type& person_list();
    
    void on_persons_ready();
	milk::milk_spinboard_ptr create_spinboard();

protected:
	milk::milk_spinboard_ptr    m_spinboard;
	sqc_theme_size              m_theme_size;
	sqc_person_info_list_type   m_person_list;
	spinboard_layout            m_spinboard_layout;
    
	sqc_select_preson_delegate_ptr m_delegate;
	int m_visible_count;
};


END_NAMESPACE_SQC_FRAMEWORK

#endif
