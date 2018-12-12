/*
 *  city_level_up_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 08.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_LEVEL_UP_DLG_H_INCLUDED__
#define __SQC_CITY_LEVEL_UP_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_level_up_dlg_layout.h"
#include "country_base/sqc_framework_base.h"

#include "country_base/dialogs/controls/sqc_balance_widget.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"

NAMESPACE_SQC_FRAMEWORK

class city_level_up_dlg 
                    : public sqc_dialog_with_next 
                    , public milk::milk_spinboard_callbacks 
                    {
public:
    city_level_up_dlg( milk::milk_widget_ptr p, const sqc_level_up_params& params)
    : sqc_dialog_with_next( p, city_dlg_layout::level_up_dlg::dialog )
    , m_params( params ) 
    {
    }
    
    // milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    virtual sqc_int get_cell_count();
                        
    bool fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                                 const sqc_shop_category_item_ptr item );
                                 
    void on_buy_item_pressed( const sqc_string& object_type );
    void on_gift_item_pressed( const sqc_string& object_type );
    
    sqc_level_up_params	m_params;
    sqc_shop_category_items     m_items;
    milk::milk_spinboard_ptr    m_spinboard;
    
protected:
	// initialization 
	virtual void on_init_dialog();

};

typedef std::tr1::shared_ptr<city_level_up_dlg>	 city_level_up_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif