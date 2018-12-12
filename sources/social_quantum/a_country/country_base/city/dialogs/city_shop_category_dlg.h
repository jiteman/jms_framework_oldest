/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SHOP_CATEGORY_DLG_H_INCLUDED__
#define __SQC_CITY_SHOP_CATEGORY_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_shop_category_dlg_layout.h"
#include "country_base/sqc_framework_base.h"

#include "country_base/dialogs/controls/sqc_balance_widget.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_category_dlg implementation
//
class city_shop_category_dlg 
    : public sqc_dialog_with_back_and_close
    , public milk::milk_spinboard_callbacks {
public:
	city_shop_category_dlg( milk::milk_widget_ptr p, const sqc_shop_category_params& params ) 
		: sqc_dialog_with_back_and_close( p,
                layout::city_shop_category_dlg_layout::background )
        , m_params( params )
        , m_cell_count( 0 ) {
	}
	
protected:
	// initialization 
	virtual void on_init_dialog();
        
    // milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
    virtual int get_cell_count();
        
protected:
    // add buttons, captions and image to cell
    bool    fill_shop_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                                const sqc_shop_category_item_ptr item );
protected:
    // user press buy item button
    void    on_buy_item_pressed( const sqc_string& object_type );
    // user press buy item button
    void    on_gift_item_pressed( const sqc_string& object_type );
    
	bool 	on_select_user_for_gift( const sqc_string& object_type,
    								const sqc_string& second_user_id );

    void on_add_money();
	bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
    
protected:
    sqc_balance_widget_ptr      m_balance_widget;
    milk::milk_spinboard_ptr    m_spinboard;
    sqc_shop_category_items     m_items;
    sqc_dword					m_cell_count;

    sqc_shop_category_params	m_params;
};

typedef std::tr1::shared_ptr<city_shop_category_dlg>	city_shop_category_dlg_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SHOP_CATEGORY_DLG_H_INCLUDED__


