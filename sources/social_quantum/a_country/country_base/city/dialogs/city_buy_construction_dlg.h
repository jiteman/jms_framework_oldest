/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_BUY_CONSTRUCTION_DLG_H_INCLUDED__
#define __SQC_CITY_BUY_CONSTRUCTION_DLG_H_INCLUDED__

#include "city_buy_building_base_dlg.h"
#include "city_buy_building_base_dlg_layout.h"
#include "city_buy_construction_dlg_layout.h"


NAMESPACE_SQC_FRAMEWORK

//
// city_buy_construction_dlg implementation
//
class city_buy_construction_dlg 
    : public city_buy_building_base_dlg {
public:
	city_buy_construction_dlg( milk::milk_widget_ptr p, 
                              const sqc_shop_construction_params& params ) 
		: city_buy_building_base_dlg( p )
        , m_params( params )
        , m_category (params.construction_type) {
	}

protected:
    // dialog title
    virtual sqc_string get_dialog_title();
    // category description
    virtual sqc_string get_category_descr();
    // category image
    virtual sqc_string get_category_image();
        
	// initialization 
	virtual void on_init_dialog();
        
    // milk_spinboard_callbacks interface
    virtual milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
    virtual int get_cell_count();
        
protected:
    // user press buy item button
    void    on_buy_item_pressed(const sqc_string& object_type);
    // user press ask item button
    void    on_ask_item_pressed(const sqc_string& object_type);
    
protected:
    sqc_shop_construction_params    m_params;
    sqc_construction_category       m_category;
    sqc_shop_construction_items     m_items;
};

typedef std::tr1::shared_ptr<city_buy_construction_dlg>	city_buy_construction_dlg_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_BUY_CONSTRUCTION_DLG_H_INCLUDED__


