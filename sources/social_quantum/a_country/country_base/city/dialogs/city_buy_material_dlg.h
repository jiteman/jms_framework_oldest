/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_BUY_MATERIAL_DLG_H_INCLUDED__
#define __SQC_CITY_BUY_MATERIAL_DLG_H_INCLUDED__

#include "city_buy_building_base_dlg.h"
#include "city_buy_building_base_dlg_layout.h"
#include "city_buy_construction_dlg_layout.h"
#include "city_dialogs.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_buy_material_dlg implementation
//
class city_buy_material_dlg
: public city_buy_building_base_dlg {
public:
	city_buy_material_dlg( milk::milk_widget_ptr p, 
                              const sqc_shop_material_params& params ) 
    : city_buy_building_base_dlg( p )
    , m_category( params.buildsite_type )
    , m_params( params )
    , m_count_material(0)
    , m_total_material(0) {
	}
    
    sqc_dialog_update_callback get_update_callback();     
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
    void    on_ask_item_pressed( sqc_shop_material_item_ptr ptr_item);
    
    void    update_dialog();
    
    void    enum_shop();
protected:
    sqc_material_category       m_category;
    sqc_shop_material_items     m_items;
    sqc_shop_material_params    m_params;
    
    int     m_count_material;
    int     m_total_material;
};

typedef std::tr1::shared_ptr<city_buy_material_dlg>	city_buy_material_dlg_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_BUY_CONSTRUCTION_DLG_H_INCLUDED__


