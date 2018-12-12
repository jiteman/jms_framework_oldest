/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SHOP_CATEGORIES_DLG_H_INCLUDED__
#define __SQC_CITY_SHOP_CATEGORIES_DLG_H_INCLUDED__

#include "city_base_dlg.h"
#include "city_shop_categories_dlg_layout.h"
#include "country_base/shop/sqc_shop_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_categories_dlg implementation
//
class city_shop_categories_dlg : public sqc_dialog_with_close {
public:
	city_shop_categories_dlg( milk::milk_widget_ptr p, const sqc_shop_categories_params& params ) 
		: sqc_dialog_with_close( p, 
                    city_dlg_layout::shop_categories_dlg::background )
        , m_params( params ) {
	}
	
protected:
	// initialization 
	virtual void on_init_dialog();
	
protected:
    // shop button is pressed
    void on_shop_button_pressed( const sqc_shop_category category );
    
protected:
    // add button and caption
	void add_button_and_caption( const image_button_layout& button, 
						 const label_layout& caption, 
                         const size_t idx_button,
                         const sqc_shop_category category );
                         
	sqc_shop_categories_params m_params;
    void on_add_money();
    void on_find_money();

};

typedef std::tr1::shared_ptr<city_shop_categories_dlg>	city_shop_categories_dlg_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_SHOP_CATEGORIES_DLG_H_INCLUDED__


