/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_CONSTRUCTION_CELL_H_INCLUDED__
#define __SQC_SHOP_CONSTRUCTION_CELL_H_INCLUDED__

#include "sqc_shop_building_base_cell.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_construction_cell implementation
//
class sqc_shop_construction_cell
    : public sqc_shop_building_base_cell {
public:
    sqc_shop_construction_cell( milk::milk_widget_ptr p,
                       sqc_shop_construction_item_ptr ptr_item );
    virtual ~sqc_shop_construction_cell();
    virtual void layout_controls( sqc_window_factory_ctx_ptr window_ctx, bool draw_separator = true);
protected:
    virtual sqc_shop_building_base_item_ptr get_building_item();
        
protected:
    sqc_shop_construction_item_ptr m_ptr_item;
};

typedef std::tr1::shared_ptr<sqc_shop_construction_cell>
                                        sqc_shop_construction_cell_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_CONSTRUCTION_ITEM_CELL_H_INCLUDED__


