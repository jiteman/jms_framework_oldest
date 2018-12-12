/*
 *  city_on_next_level_available.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 12.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_ON_NEXT_LEVEL_DLG_H_INCLUDED__
#define __SQC_CITY_ON_NEXT_LEVEL_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_on_next_level_available_dlg_layout.h"
#include "country_base/sqc_framework_base.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"

NAMESPACE_SQC_FRAMEWORK

class city_on_next_level_dlg 
: public sqc_dialog_with_back_and_close 
, public milk::milk_spinboard_callbacks 
{
public: 
    city_on_next_level_dlg( milk::milk_widget_ptr p, const sqc_on_next_level_params& params ) 
    : sqc_dialog_with_back_and_close( p, city_dlg_layout::next_level_available::background )
    , m_params( params )
    {}
    
        
    // milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    virtual sqc_int get_cell_count();
        
    bool fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                        const sqc_shop_category_item_ptr item );
                        
    sqc_on_next_level_params	m_params;
    sqc_shop_category_items     m_items;
    milk::milk_spinboard_ptr    m_spinboard;
    
protected:
	// initialization 
	virtual void on_init_dialog();
	bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
};

typedef std::tr1::shared_ptr<city_on_next_level_dlg>	 city_on_next_level_dlg_ptr;
    


END_NAMESPACE_SQC_FRAMEWORK

#endif