/*
 *  city_select_construction_dlg.h
 *  aCountry
 *
 *  Created by paul on 10/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __CITY_SELECT_CONSTRUCTION_DLG_H_INCLUDED___
#define __CITY_SELECT_CONSTRUCTION_DLG_H_INCLUDED___

#include "city/dialogs/city_base_dlg.h"
#include "city_select_construction_dlg_layout.h"
#include "country_base/dialogs/select_construction/sqc_select_construction_delegate.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_select_construction_dlg implementation
//
class city_select_construction_dlg
    : public sqc_dialog_with_close
    , public milk::milk_spinboard_callbacks {
public:
	city_select_construction_dlg( milk::milk_widget_ptr p,
        sqc_select_construction_delegate_ptr ptr_delegate ) 
		: sqc_dialog_with_close( p,
                    city_dlg_layout::select_construction_dlg::background )
        , m_delegate( ptr_delegate ){
	}
    
protected:
    // initialization 
	virtual void on_init_dialog();

protected:
    virtual milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
    virtual int get_cell_count();
    virtual void on_apply_pressed( const sqc_construction_ptr construction );

protected:    
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
protected:
    milk::milk_spinboard_ptr       		 m_spinboard;
    sqc_select_construction_delegate_ptr m_delegate;
    sqc_constructions					 m_constructions;
};

typedef std::tr1::shared_ptr<city_select_construction_dlg> city_select_construction_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__CITY_SELECT_CONSTRUCTION_DLG_H_INCLUDED___