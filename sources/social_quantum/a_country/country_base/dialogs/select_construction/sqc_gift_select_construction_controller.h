/*
 *  sqc_gift_select_construction_controller.h
 *  aCountry
 *
 *  Created by Василий on 18.10.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_GIFT_SELECT_CONSTRUCTION_CONTROLLER_H_INCLUDED__
#define __SQC_GIFT_SELECT_CONSTRUCTION_CONTROLLER_H_INCLUDED__

#include "country_base/dialogs/select_construction/sqc_select_construction_controller.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_gift_apply_shop_material_controller
	: public sqc_apply_shop_material_controller {
public:
	sqc_gift_apply_shop_material_controller( const sqc_string& str_material_type, const int gift_id )
    	: sqc_apply_shop_material_controller( str_material_type )
        , m_gift_id(gift_id)
    {
	}
        
    virtual	bool on_select_construction( sqc_construction_ptr ptr_construction )
    {
        using namespace processor;

		/* call
        sqc_apply_gift_command( const sqc_string& user_id, const int item_id, 
                               const int gift_id,
                               const sqc_string& klass )
        */
        
		sqc::info::sqc_object_info* p_obj_info = find_material_by_type_name( m_material_type_name );
        sqc_assert(p_obj_info);
        
        sqc_command_ptr  command( new sqc_apply_gift_command( "", ptr_construction->item_id(), m_gift_id, m_material_type_name ) );
        country_framework().cmd_processor().schedule( command );
        return true;
    }
private:
	const int m_gift_id;

};

    
END_NAMESPACE_SQC_FRAMEWORK
    
#endif