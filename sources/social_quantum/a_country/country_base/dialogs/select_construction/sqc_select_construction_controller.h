/*
 *  sqc_select_construction_controller.h
 *  aCountry
 *
 *  Created by paul K on 10/11/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */
 
 
#ifndef __SQC_SELECT_CONSTRUCTION_CONTROLLER_H_INCLUDED__
#define __SQC_SELECT_CONSTRUCTION_CONTROLLER_H_INCLUDED__

#include "sqc_base.h"
#include "framework/sqc_framework_defs.h"
#include "sqc_select_construction_delegate.h"
#include "country_base/shop/sqc_shop_defs.h"

NAMESPACE_SQC_FRAMEWORK


//
//	apply material base controller
//
class sqc_apply_material_base_controller
    : public sqc_noncopyable
    , public sqc_select_construction_delegate {
public:
	sqc_apply_material_base_controller( const sqc_string& str_material_type_name );
	virtual ~sqc_apply_material_base_controller();

	virtual sqc_string	get_dialog_item_name();
    virtual sqc_string	get_dialog_item_image();
	virtual void    	get_constructions( sqc_constructions& constructions );
    
protected:
	typedef	std::list<sqc_game_object_ptr>	game_objects;
protected:
	sqc::info::sqc_object_info*	find_material_by_type_name( const sqc_string& type_name );
    
    void						enum_game_object( const sqc_game_object_ptr& obj,
    									const sqc_int material_type_id,
                                        const sqc_string& material_type_name,
    									game_objects* constructions );
protected:
	sqc_string			m_material_type_name;
    game_objects		m_constructions;
};


//
//	apply shop material controller
//
class sqc_apply_shop_material_controller
	: public sqc_apply_material_base_controller {
public:
    sqc_apply_shop_material_controller( const sqc_string& str_material_type ) :
    	sqc_apply_material_base_controller( str_material_type ) {
    }
	virtual sqc_string	get_dialog_caption();
    virtual sqc_string	get_dialog_item_descr();
    
    virtual	bool		on_select_construction( sqc_construction_ptr ptr_construction );
};

END_NAMESPACE_SQC_FRAMEWORK

#endif //__SQC_SELECT_CONSTRUCTION_CONTROLLER_H_INCLUDED__