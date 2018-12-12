#pragma once

#include "sqc_shop_defs.h"
#include "../../sqc/sqc_base.h"

#include "../sqc_country_base_ui.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_texture_proxy;

//
//  shop implementation
//

class sqc_shop {
public:
    sqc_shop( sqc::info::sqc_object_info_provider_ptr& object_factory );
    virtual ~sqc_shop();

	//
    //	shop errors
    //
	sqc_string	get_shop_error_descr( sqc_shop_error error );

    //
    //  shop category
    //
public:    
    
    // retrieve shop category name
    sqc_string get_shop_category_name( const sqc_shop_category category );

    // enum items
    bool enum_shop_category( const sqc_shop_enum_params& enum_params,
                             const sqc::sqc_common_scene_info& scene_info,
                             sqc_shop_category_items& items );
                             
    sqc_shop_category_item_ptr find_shop_item_by_type_id( 
    						const sqc_shop_enum_params& enum_params, 
                            const sqc::sqc_common_scene_info& scene_info,
                            int type_id );
    
    sqc_shop_category_item_ptr find_shop_item_by_type_name( 
    						const sqc_shop_enum_params& enum_params, 
                            const sqc::sqc_common_scene_info& scene_info,
                            const sqc_string& type_name );

private:
	sqc_shop_category	get_shop_category_by_shop_department( 
						     const sqc_string& category );
    
	template <class T>
    bool 			fill_item( const sqc::info::sqc_object_info* type_info,
    						   const sqc_shop_enum_params& enum_params,
                               const sqc::sqc_common_scene_info& scene_info,
                               std::tr1::shared_ptr<T>& ptr_item );
                               
    //
    //  shop constructions
    //
    
public:
    // retrieve shop construction name
    sqc_string get_shop_construction_category_name( 
                    const sqc_construction_category& category );
    sqc_string get_shop_construction_category_image( 
                    const sqc_construction_category& category );
    sqc_string get_shop_construction_category_descr( 
                    const sqc_construction_category& category );
    
    // enum construction category
    bool enum_shop_construction_category( const sqc_construction_category& category,
                            sqc_shop_construction_items& items );

    sqc_string_map get_construction_info( sqc_string const &category );

    //
    //  shop materials
    //
public:    
    // retrieve shop material category name
    sqc_string get_shop_material_category_name( 
                            const sqc_material_category& category );
    sqc_string get_shop_material_category_image( 
                            const sqc_construction_category& category );
    sqc_string get_shop_material_category_descr( 
                            const sqc_material_category& category );
    
    // enum material category
    bool enum_shop_material_category( const sqc_material_category& category,
                                     const sqc_string_map& input_fill,
                                     const sqc::sqc_common_scene_info& scene_info,
                                     sqc_shop_material_items& items,
                                     sqc_game_object_ptr owner = sqc_game_object_ptr() );
                                      
    sqc_string_map get_produce_info( sqc_string const &category );
                                      
    // 
    // shop constracts
    //
public:
    sqc_string  get_shop_contracts_name();
    bool        enum_shop_contracts(const sqc_string& type, sqc_shop_contract_items& items ); 
                            
protected:
	// class factory
	sqc::info::sqc_object_info_provider_ptr& 	m_object_factory;
};

END_NAMESPACE_SQC_FRAMEWORK
