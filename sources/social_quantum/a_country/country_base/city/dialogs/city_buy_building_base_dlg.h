/*
 *  city_buy_building_base.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_BUY_BUILDING_BASE_DLG_H_INCLUDED__
#define __SQC_CITY_BUY_BUILDING_BASE_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_buy_building_base_dlg_layout.h"
#include "../../country_base/shop/sqc_shop_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_buy_building_base_dlg implementation
//
class city_buy_building_base_dlg
    : public sqc_dialog_with_close
    , public milk::milk_spinboard_callbacks {
public:
	city_buy_building_base_dlg( milk::milk_widget_ptr p ) 
		: sqc_dialog_with_close( p,
                    city_dlg_layout::buy_building_base_dlg::background ) {
	}

protected:
    // dialog title
    virtual sqc_string get_dialog_title() = 0;
    // category description
    virtual sqc_string get_category_descr() = 0;
    // category image
    virtual sqc_string get_category_image() = 0;

    // initialization 
	virtual void on_init_dialog();
    
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
protected:
    sqc_int                   m_cell_count;
    milk::milk_spinboard_ptr  m_spinboard;
};


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_BUY_BUY_BUILDING_BASE_DLG_H_INCLUDED__


