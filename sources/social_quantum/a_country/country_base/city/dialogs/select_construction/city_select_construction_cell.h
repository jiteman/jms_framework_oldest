/*
 *  city_select_construction_cell.h
 *  aCountry
 *
 *  Created by paul on 10/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __CITY_SELECT_CONSTRUCTION_CELL_H_INCLUDED___
#define __CITY_SELECT_CONSTRUCTION_CELL_H_INCLUDED___

#include "country_base/dialogs/select_construction/sqc_select_construction_delegate.h"
#include "country_base/dialogs/controls/sqc_item_buttons.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_building_base_cell implementation
//

typedef std::tr1::function<void( const sqc_construction_ptr construction )> cell_apply_callback;


class city_select_construction_cell
    : public milk::milk_widget {
public:
    city_select_construction_cell( milk::milk_widget_ptr p, sqc_construction_ptr construction );
    virtual ~city_select_construction_cell();
public:
    void set_apply_callbacks( cell_apply_callback cb );
    virtual void layout_controls( sqc_window_factory_ctx_ptr window_ctx );
protected:        
    void	on_apply_pressed();
protected:
    cell_apply_callback             m_apply_callback;
        
protected:
    sqc_construction_ptr            m_construction;
};

typedef std::tr1::shared_ptr<city_select_construction_cell>	city_select_construction_cell_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__CITY_SELECT_CONSTRUCTION_CELL_H_INCLUDED___


