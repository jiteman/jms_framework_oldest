/*
 *  sqc_select_construction_controller.cpp
 *  aCountry
 *
 *  Created by paul K on 10/11/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sqc_select_construction_controller.h"
#include "country_base/sqc_framework_base.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


//
//	select construction base controller
//
sqc_apply_material_base_controller::sqc_apply_material_base_controller(
	const sqc_string& material_type_name )
    	: m_material_type_name( material_type_name ) {
}

sqc_apply_material_base_controller::~sqc_apply_material_base_controller() {
}


sqc_string sqc_apply_material_base_controller::get_dialog_item_image() {

	sqc::info::sqc_object_info* info = find_material_by_type_name( m_material_type_name );
    if ( !info ) {
    	return sqc_text( "" );
    }
    
    return info->get_shop_image_path();
}

sqc_string sqc_apply_material_base_controller::get_dialog_item_name() {
	sqc::info::sqc_object_info* info = find_material_by_type_name( m_material_type_name );
    if ( !info ) {
    	return sqc_text( "Error" );
    }
    
    return info->get_description();
}

void sqc_apply_material_base_controller::get_constructions(
	sqc_constructions& list ) {
 
 	sqc_game_ptr ptr_game = country_framework().game();
	if ( !ptr_game ) {
    	sqc_assert( false );
        return;
    }
    
    sqc_field_ptr ptr_field = ptr_game->get_field();
    if ( !ptr_field ) {
    	sqc_assert( false );
        return;
    }
    
    sqc::info::sqc_object_info* type_info = find_material_by_type_name( m_material_type_name );
    
    if ( !type_info ) {
    	sqc_error()
        	<< "sqc_select_construction_controller: unable to find material_id for type_name:\"" 
            << m_material_type_name
            << "\"";
        
    	return;
    }
    
    sqc_int	material_type_id = type_info->get_type_id();

	game_objects constructions;

	ptr_field->foreach_object( 
    	std::tr1::bind( &sqc_apply_material_base_controller::enum_game_object, 
        				this, 
                        _1, 
                        material_type_id, 
                        m_material_type_name,
                        &constructions ) );
        
    for ( game_objects::const_iterator it = constructions.begin();
        it != constructions.end(); ++it ) {
        
        sqc_game_object_ptr ptr_game_object = *it;
        
        sqc::info::sqc_object_info_ptr object_type_info = ptr_game_object->get_object_info();
        if ( !object_type_info ) {
            sqc_assert( false );
            return;
        }

		sqc_int	object_id				= ptr_game_object->get_id();
        const sqc_string&	name		= object_type_info->get_description();
        const sqc_string&   image_name	= object_type_info->get_shop_image_path();
        sqc_construction_ptr ptr( new sqc_construction( object_id, name, image_name ) );
        list.push_back( ptr );
    }
}

void sqc_apply_material_base_controller::enum_game_object( 
	const sqc_game_object_ptr& obj,
    const sqc_int material_type_id,
    const sqc_string& material_type_name,
    game_objects* constructions ) {

	if ( !obj || !constructions ) {
    	sqc_assert( false );
        return;
    }
    
    sqc::info::sqc_object_info_ptr object_type_info = obj->get_object_info();
    if ( !object_type_info ) {
    	sqc_assert( false );
        return;
    }
    
    sqc_int total = 0;
    {
    	sqc_quantity_by_name_map const& map_total = object_type_info->get_materials_quantity();
        sqc_quantity_by_name_map::const_iterator it_total = map_total.find( material_type_name );
    	if ( map_total.end() == it_total ) {
    		return;
    	}
        total = it_total->second;
        if ( total <= 0 ) {
        	return;
        }
    }
    
    
    sqc_int count = 0;
    {
        sqc_quantity_by_name_map const& map_count = obj->get_materials_quantity();
        sqc_quantity_by_name_map::const_iterator it_count = map_count.find( material_type_name );
        if ( map_count.end() != it_count ) {
            count = it_count->second;
        }
        
    }

    if ( count >= total ) {
    	return;
    }
    
    constructions->push_back( obj );
}

sqc::info::sqc_object_info* sqc_apply_material_base_controller::find_material_by_type_name( 
	const sqc_string& type_name ) {
    
    sqc_object_info_provider_ptr ptr_factory = country_framework().object_factory();
    if ( !ptr_factory ) {
    	sqc_assert( 0 );
        return 0;
    }
    
    sqc::info::sqc_object_info* info = ptr_factory->get_object_info( type_name.c_str() );
    if ( !info ) {
    	sqc_error()
        	<< "sqc_select_construction_controller: unable to find material_id for type_name:\"" 
            << type_name
            << "\"";
        return 0;
    }
    
    return info;
}


//
//	apply shop material controller
//
bool sqc_apply_shop_material_controller::on_select_construction( 
	sqc_construction_ptr ptr_construction ) {
    
    if ( !ptr_construction ) {
    	sqc_assert( false );
    	return false;
    }
    
    using namespace processor;
    
    processor::sqc_command_processor& proc = country_framework().cmd_processor();
        
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_apply_command( str_user_id, m_material_type_name, ptr_construction->item_id() ) );
    proc.schedule( command );
    
    return true;
}

sqc_string sqc_apply_shop_material_controller::get_dialog_caption() {
	return framework().strings().load( "*ApplyGiftWindowTitle", "Apply material" );
}

sqc_string sqc_apply_shop_material_controller::get_dialog_item_descr() {
	return framework().strings().load( "*ApplyGiftWindowDescription", 
    	"You can apply selected material to any object listed below." );
}



END_NAMESPACE_SQC_FRAMEWORK