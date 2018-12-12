/*
 *  city_buy_management.h
 *  aCountry
 *
 *  Created by Василий on 04.08.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_BUY_MANAGEMENT_H_INCLUDED__
#define __SQC_CITY_BUY_MANAGEMENT_H_INCLUDED__

#include "country_base/sqc_framework_base.h"
#include "city/dialogs/city_base_dlg.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"
#include "country_base/shop/sqc_shop_defs.h"
#include "city/dialogs/city_dialogs.h"

#include "city_buy_management_layout.h"

#include "city_tax_admin_delegate.h"
#include "city_hall_delegate.h"


NAMESPACE_SQC_FRAMEWORK

struct properties {
    int water;
    int power;
    int experience;
    int build_time_min;
    int price_in_megabucks;
};

class city_buy_management_base : public sqc_dialog_with_close {
public:
	city_buy_management_base(
    	milk::milk_widget_ptr p
    )
    
    : sqc_dialog_with_close(p, city_dlg_layout::buy_management_dlg::background)
    , m_factory( framework().windows_factory() )
    {
    }
	void on_add_coins();
    virtual void on_init_dialog();
    virtual sqc_string get_object_title() = 0;
    virtual sqc_string get_object_header() = 0;
    virtual sqc_string get_object_description() = 0;
    //virtual sqc_string get_object_item_image() = 0;
    //virtual sqc_shop_category_item_ptr get_object_property_item() =0;
    virtual void set_on_buy(sqc_shop_item_cell_ptr ptr_cell) = 0;
    virtual sqc_string get_type_name() = 0;
	virtual void get_scene_info( sqc_common_scene_info& scene_info ) = 0;
    
private:

protected:
	sqc_window_factory& m_factory;
    sqc_shop_item_cell_ptr m_ptr_cell;
    sqc_shop_category_item_ptr m_item_ptr;
};

class city_buy_cityhall_dlg : public city_buy_management_base {
public:
	city_buy_cityhall_dlg( milk::milk_widget_ptr p, city_hall_delegate_ptr delegate );
    
    sqc_string get_object_title();
    sqc_string get_object_header();
    sqc_string get_object_description();
    //sqc_string get_object_item_image();
    sqc_shop_category_item_ptr get_object_property_item();
    void on_buy(const sqc_string& s);
    void set_on_buy(sqc_shop_item_cell_ptr ptr_cell);
    sqc_string get_type_name();
    virtual void get_scene_info( sqc_common_scene_info& scene_info );


protected:
	city_hall_delegate_ptr m_delegate;
};

typedef std::tr1::shared_ptr<city_buy_cityhall_dlg> city_buy_cityhall_dlg_ptr;

class city_buy_tax_administration_dlg : public city_buy_management_base {
public:
	city_buy_tax_administration_dlg( 
		milk::milk_widget_ptr p, city_tax_admin_delegate_ptr delegate )
    : city_buy_management_base( p )
    , m_delegate( delegate )
    {
    }

    sqc_string get_object_title();
    sqc_string get_object_header();
    sqc_string get_object_description();
    sqc_string get_type_name();
	virtual void get_scene_info( sqc_common_scene_info& scene_info );
    
    void on_buy(const sqc_string& s);
    void set_on_buy(sqc_shop_item_cell_ptr ptr_cell);

protected:
	city_tax_admin_delegate_ptr m_delegate;
};

typedef std::tr1::shared_ptr<city_buy_tax_administration_dlg> city_buy_tax_administration_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif
