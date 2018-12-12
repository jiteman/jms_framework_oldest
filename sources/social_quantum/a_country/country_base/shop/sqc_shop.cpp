/*
 *  sqc_shop.cpp
 *  aCountry
 *
 *  Created by Paul K on 6/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_shop.h"
#include "country_base/sqc_framework_base.h"
#include "framework/texture/sqc_texture_builder.h"
#include <algorithm>

#if defined SQC_FARM_GAME
#include "sqc_farm.h"
#elif defined SQC_CITY_GAME
#include "sqc_city.h"
#else
#error uncompatible game target
#endif




NAMESPACE_SQC_FRAMEWORK

//
//  shop implementation
//
sqc_shop::sqc_shop(
	sqc::info::sqc_object_info_provider_ptr& object_factory ) 
	: m_object_factory( object_factory ) {
}

sqc_shop::~sqc_shop() {
}

//
//  shop category
//

// retrieve shop category name
sqc_string sqc_shop::get_shop_category_name( 
    const sqc_shop_category category ) {
    
    sqc_string_resources& res = sqc::framework::framework().strings();
#if defined SQC_CITY_GAME
    if ( sqc_shop_category_houses == category ) {
        return res.load( common_resources::string_title_houses.resource_id(),
                         common_resources::string_title_houses.def_value() );
    } else if ( sqc_shop_category_factories == category ) {
        return res.load( common_resources::string_title_factories.resource_id(),
                         common_resources::string_title_factories.def_value() );
    } else if ( sqc_shop_category_leisures == category ) {
        return res.load( common_resources::string_title_leisures.resource_id(),
                         common_resources::string_title_leisures.def_value() );
    } else if ( sqc_shop_category_terrains == category ) {
        return res.load( common_resources::string_title_terrains.resource_id(),
                         common_resources::string_title_terrains.def_value() );
    } else if ( sqc_shop_category_power == category ) {
        return res.load( common_resources::string_title_power.resource_id() ,
                         common_resources::string_title_power.def_value() );
    } else if ( sqc_shop_category_roads == category ) {
        return res.load( common_resources::string_title_roads.resource_id(),
                         common_resources::string_title_roads.def_value());
    } else if ( sqc_shop_category_materials == category ) {
        return res.load(common_resources::string_title_materials.resource_id() ,
                        common_resources::string_title_materials.def_value() );
    } else if ( sqc_shop_category_expand == category ) {
        return res.load( common_resources::string_message_shop_expand.resource_id(),
                         common_resources::string_message_shop_expand.def_value()  );
    }

#elif defined SQC_FARM_GAME

    if ( sqc_shop_category_materials == category ) {
        return res.load( "*FarmShopMaterials", "Materials" );
    } else if ( sqc_shop_category_extra == category ) {
        return res.load( "*FarmShopExtra", "Extra" );
    } else if ( sqc_shop_category_automation == category ) {
        return res.load( "*FarmShopAutomation", "Automation" );
    } else if ( sqc_shop_category_decorations == category ) {
        return res.load( "*FarmShopDecorations", "Decorations" );
    } else if ( sqc_shop_category_flowers == category ) {
        return res.load( "*FarmShopFlowers", "Flowers" );
    } else if ( sqc_shop_category_seeds == category ) {
        return res.load( "*FarmShopSeeds", "Seeds" );
    } else if ( sqc_shop_category_houses == category ) {
        return res.load( "*FarmShopHousess", "Houses" );
    } else if ( sqc_shop_category_trees == category ) {
        return res.load( "*FarmShopTrees", "Trees" );
    } else if ( sqc_shop_category_factories == category ) {
        return res.load( "*FarmShopFactories", "Factories" );
    } else if ( sqc_shop_category_fertilizers == category ) {
        return res.load( "*FarmShopFertilizers", "Fertilizers" );
    } else if ( sqc_shop_category_animals == category ) {
        return res.load( "*FarmShopAnimals", "Animals" );
    } else if ( sqc_shop_category_expand == category ) {
        return res.load( "*FarmShopExpansions", "Expansions" );
    }
    
#else
#error uncompatible game target
#endif
    
    sqc_assert( false );
    return "unknown category";
}

sqc_shop_category sqc_shop::get_shop_category_by_shop_department( 
    const sqc_string& category ) {
    
    // sqc_error() << " category: " << category;
#if defined SQC_CITY_GAME

    if ( category == sqc_text( "houses" ) ) {
        return sqc_shop_category_houses;
    } else if ( category == sqc_text( "city_factories" ) ) {
        return sqc_shop_category_factories;
    } else if ( category == sqc_text( "leisures" ) ) {
        return sqc_shop_category_leisures;
    } else if ( category == sqc_text( "terrains" ) ) {
        return sqc_shop_category_terrains;
    } else if ( category == sqc_text( "power" ) ) {
        return sqc_shop_category_power;
    } else if ( category == sqc_text( "roads" ) ) {
        return sqc_shop_category_roads;
    } else if ( category == sqc_text( "materials" ) ) {
        return sqc_shop_category_materials;
    } else if ( category == sqc_text( "expand" ) ) {
        return sqc_shop_category_expand;
    }
    
#elif defined SQC_FARM_GAME
    
    if ( category == sqc_text( "materials" ) ) {
        return sqc_shop_category_materials;
    } else if ( category == sqc_text( "extra" ) ) {
        return sqc_shop_category_extra;
    } else if ( category == sqc_text( "automation" ) ) {
        return sqc_shop_category_automation;
    } else if ( category == sqc_text( "decor" ) ) {
        return sqc_shop_category_decorations;
    } else if ( category == sqc_text( "flowers" ) ) {
        return sqc_shop_category_flowers;
	} else if ( category == sqc_text( "seeds" ) ) {
        return sqc_shop_category_seeds;
    } else if ( category == sqc_text( "houses" ) ) {
        return sqc_shop_category_houses;
    } else if ( category == sqc_text( "trees" ) ) {
        return sqc_shop_category_trees;
    } else if ( category == sqc_text( "gears" ) ) {
        return sqc_shop_category_factories;
    } else if ( category == sqc_text( "fertilizer" ) ) {
        return sqc_shop_category_fertilizers;
    } else if ( category == sqc_text( "animals" ) ) {
        return sqc_shop_category_animals;
    } else if ( category == sqc_text( "expand" ) ) {
    	return sqc_shop_category_expand;
    }

/*
extra
seeds
materials
gears
decor
animals
materials
flowers
automation
houses
tutorial_sunflower
trees
fertilizer
bridges
*/
#else
#error uncompatible game target
#endif
    
    return sqc_shop_category_unknown;
}


struct sort_shop_items_t {
	bool operator() ( const sqc_shop_item_ptr p0, const sqc_shop_item_ptr p1 ) 
	{
		sqc_assert( p0 && p1 );
		
        // category
        
		if( p0->get_category() > p1->get_category() ) {
			return false;
		}
		else if( p0->get_category() < p1->get_category() ) {
			return true;
		}
		else {
			if( p0->get_category() == sqc_shop_category_expand ) {
				if( p0->get_field_no() > p1->get_field_no() ) {
					return false;
				}
				else if( p0->get_field_no() < p1->get_field_no() ) {
					return true;
                }
				else if( p0->get_size_x() > p1->get_size_x() ) {
					return false;
				}
				else if( p0->get_size_x() < p1->get_size_x() ) {
					return true;
				}
				else {
					return false;
				}
			}
			/*else if( po->get_category() == material ) {
			}
			*/
			else {
				if( p0->get_sort_order() > p1->get_sort_order() ) {
					return false;
				}
                else if( p0->get_sort_order() < p1->get_sort_order() ) {
					return true;
                }
				else if( p0->required_level() > p1->required_level() ) {
					return false;
                }
				else if( p0->required_level() < p1->required_level() ) {
					return true;
                }
				else if( p0->price_in_megabucks() > p1->price_in_megabucks() ) {
					return false;
				}
                else if( p0->price_in_megabucks() < p1->price_in_megabucks() ) {
					return true;
				}
				else if( p0->price_in_coins() > p1->price_in_coins() ) {
					return false;
				}
				else if( p0->price_in_coins() < p1->price_in_coins() ) {
					return true;
				}
				else {
					return false;
				}
			}
		}
    }
} sort_shop_items;


sqc_string	sqc_shop::get_shop_error_descr( sqc_shop_error error ) {

	struct table_t {
    	sqc_shop_error		err;
    	sqc_string			section;    
        sqc_string			def_value;
    };

	sqc_string str_section;
    sqc_string str_def_value;
    
	static table_t table[] = {
    	{ shop_result_success, "section", "success", },
        { shop_result_need_more_level, "section", "need more level", },
        { shop_result_need_more_coins, "section", "need more coins", },
        { shop_result_need_more_gold, "section", "need more gold", },
        { shop_result_need_more_invitees, "section", "need more invitees", },
        { shop_result_need_more_width, "section", "need more width", },
        { shop_result_current_width_is_larger_than_new_one, "section", "current width is larger than new ", },
#if defined SQC_CITY_GAME
        { city::city_shop_result_need_more_water, "section", "need more water", },
        { city::city_shop_result_need_more_power, "section", "need more power", },
        { city::city_shop_result_need_more_population, "section", "need more population", },
        { city::city_shop_result_not_necessary_material, "section", "not necessary material", },
        { city::city_shop_result_need_city_hall_present, "section", "need city hall present", },
        { city::city_shop_result_need_tax_office_present, "section", "need tax office present", },
        { city::city_shop_result_no_buildsite_to_apply_to, "section", "no buildsite to apply to", },
        { city::city_shop_result_need_sport_complex, "section", "need sport complex", },
        { city::city_shop_result_need_2nd_field, "section", "need 2nd field", },
        { city::city_shop_result_need_warehouse, "section", "need warehouse", },
#elif defined SQC_FARM_GAME
        { farm::farm_shop_result_need_more_cows, "section", "need more cows", },
#else
	#error uncompatible game target
#endif
    };

    
    for ( int idx = 0; idx < sizeof(table)/sizeof(table[0]); ++idx ) {
   		if ( table[idx].err == error ) {
            str_section		= table[idx].section;
            str_def_value	= table[idx].def_value;
        	break;
        } 	
    }
	
    if ( str_section.empty() ) {
        sqc_error()
        	<< "shop error: unable to find error code:" << error;
		sqc_assert( 0 );
    	return "Unknown error";
    }
    
	return framework().strings().load( str_section, str_def_value );
}


template <class T>
bool sqc_shop::fill_item( const sqc::info::sqc_object_info* type_info,
                           const sqc_shop_enum_params& enum_params,
                           const sqc::sqc_common_scene_info& scene_info,
                           std::tr1::shared_ptr<T>& ptr_item ) {
                
                           
    if ( !type_info ) {
        sqc_error()
        	<< "shop error: unable to enum shop category. no type info for type:"
        	<< type_info->get_type_name();
            
        return false;
    }
    
    
    //-- checkers
    if ( !type_info->get_shoppable() ) {
        return false;
    }
    
    // skip base objects
    if ( type_info->get_type_id() < 0 ) {
        return false;
    }
    
    sqc_string const& shop_department = type_info->get_shop_department();
    
    //
    //	check for category
    //
    sqc_shop_category type_info_category = get_shop_category_by_shop_department( shop_department );
    {
        if ( type_info_category == sqc_shop_category_unknown ) {
            //sqc_error() << "shop error: unsuported category:" << shop_department;
            return false;
        }
            
        if( sqc_shop_category_all != enum_params.enum_category ) {
            // not all category 
            if ( type_info_category != enum_params.enum_category ) {
                // it'a not a corresponding category
                return false;
            }
        }
    }

    //
    //	check for level
    //
    {
    	int type_info_level = type_info->get_level();
        if ( type_info_level && enum_params.enum_level ) {
            if ( type_info_level != enum_params.enum_level ) {
                return false;
            }
        }
    }
    
    //
    // Check only new
    //
    if(true == enum_params.show_only_new){
        if(false == type_info->get_new() )
            return false; 
        
        /*
        // Uncommite and chang "false" on "true"
        //  for test. Don't forget increase (a > ..)
        //  after each used.
        if(false)
        {
            static int a = 0;
            if(a > 165)
                return false;
        
            
           a++;
        }
        */
        
    }

    
    //--
    
    //
    //	create item instance
    //
#if defined SQC_CITY_GAME
    ptr_item.reset(new T( type_info->get_description(), 
                          type_info->get_shop_image_path()));
#elif defined SQC_FARM_GAME
    ptr_item.reset(new T( type_info->get_description(), 
                          type_info->get_shop_image_path() ) );
#else
	#error uncompatible game target
#endif

	//
    //	fill common info
    //
	sqc_assert( type_info->get_type_name().size() );
	
    ptr_item->set_object_type( type_info->get_type_name() );
    ptr_item->set_object_type_id( type_info->get_type_id() );
    ptr_item->set_category( type_info_category );


    int v = type_info->get_level();
    if( v > scene_info.level )
    {
        ptr_item->set_required_level( v );
    }
    
    ptr_item->set_sort_order( type_info->get_level() );
    
    int coins = type_info->get_cost_buy_game();
    int bucks = type_info->get_cost_buy_real( scene_info.level );
    
    if ( coins ) {
        ptr_item->set_price_in_coins( coins );
    } else if ( bucks ) {
        ptr_item->set_price_in_megabucks( bucks );
    }
    
    if ( coins && bucks ) {
        //sqc_assert( false );
        sqc_error()
        << "shop: wrong price in bucks and coins for \""
        << type_info->get_description()
        << "\"";
    }
    
    int sell_price = type_info->get_cost_sell_game();
    if ( sell_price ) { 
        ptr_item->set_sell_price_in_coins( sell_price );
    }
    
    
    if(view_only_target == enum_params.shop_target)
    {
        // Do nothing, becouse
        //  no one button and action not associated with this action.
    }
    
    //
    //	buy is available
    //
    
    if ( shop_target == enum_params.shop_target ||
    	material_target == enum_params.shop_target ||
        construction_target == enum_params.shop_target ) {
        ptr_item->set_action_state( shop_action_buy, shop_state_enable );
    }
    
    //
    // ask is available
    //
    
    if ( material_target == enum_params.shop_target ) {
        if( framework().networks().can_have_friends()
            && type_info->get_can_ask() ) {
            ptr_item->set_action_state( shop_action_ask, shop_state_enable );
        }
    }
        
    //
    //	gift is available
    //
    if ( shop_target == enum_params.shop_target ||
    	available_gift_target == enum_params.shop_target ||
        wishes_target == enum_params.shop_target ) {
        
        if ( type_info->get_buy_as_gift() ) {
            ptr_item->set_action_state( shop_action_gift, shop_state_enable );
        }
    }

    //
    //	sell and receieve
    //
    if ( received_gift_target == enum_params.shop_target ) {
        ptr_item->set_action_state( shop_action_receive, shop_state_enable );
        ptr_item->set_action_state( shop_action_sell, shop_state_enable );
    }
    
    // create action (type of instance object)
    
    if ( type_info->get_pseudo_item() ) {
    	ptr_item->set_create_action(create_action_apply_to_field);
    }
    else if ( type_info->get_create() ) {
		ptr_item->set_create_action(create_action_place_to_field);
    }
    else if ( type_info->get_apply() ) {
		ptr_item->set_create_action(create_action_use_in_construction);
	}
#if defined SQC_CITY_GAME
    
    // TODO: cast via using type() metod of sqc_object_info
    sqc::info::sqc_city_object_info* city_type_info = (sqc::info::sqc_city_object_info*)type_info;
    
    
    v = city_type_info->get_water_consume(); //get_water_produce
    if ( v ) {
        ptr_item->set_water_change( v );
    }
    
    v = city_type_info->get_power_consume(); //get_power_produce
    if ( v ) {
        ptr_item->set_power_change( v );
    }
    
    v = city_type_info->get_population_increase(); //get_max_population_increase
    if ( v ) {
        ptr_item->set_population_change( v );
    }
    
    v = city_type_info->get_exp(); //get_extra_exp
    if ( v ) {
        ptr_item->set_experience_change( v );
    }
    
    v = city_type_info->get_stage_length(); //get_abandoned_length
    if ( v ) {
        ptr_item->set_build_time_sec( v );
    }
    
    const sqc_city_expand_info* expand_info = dynamic_cast<const sqc_city_expand_info*>(type_info);
    
    if (expand_info) {
        ptr_item->set_size_x( expand_info->size_x() );
        ptr_item->set_field_no( expand_info->field_no() );
    }
    
#elif defined SQC_FARM_GAME
    
    // TODO: cast via using type() metod of sqc_object_info
    sqc::info::sqc_farm_object_info* farm_type_info = (sqc::info::sqc_farm_object_info*)type_info;
    

    v = farm_type_info->get_exp(); //get_extra_exp
    if ( v ) {
        ptr_item->set_experience_change( v );
    }
    
    v = farm_type_info->get_stage_length(); //get_abandoned_length
    if ( v ) {
        ptr_item->set_build_time_sec( v / 1000 );
    }

	/*
    paul: comment cos there is no sqc_farm_expand_info class in farm
    const sqc_farm_expand_info* expand_info = dynamic_cast<const sqc_farm_expand_info*>(type_info);
    
    if ( expand_info ) {
        ptr_item->set_size_x( expand_info->size_x() );
        ptr_item->set_field_no( expand_info->field_no() );
    }*/
    
#else
	#error uncompatible game target
#endif

	sqc_verbose() << "shop item: " << type_info->get_type_name() << "(" << type_info->get_description() << ")--->";
	// preprocess shop errors
    {
    	for ( int idx = 0; idx < shop_action_countof; idx++ ) {
        	sqc_shop_action action = (sqc_shop_action)idx;
            
            // don't waste time for unusable button
            if ( !ptr_item->is_button_visible( action ) ) {
                continue;
            }
            
            // if has error
            sqc_shop_error error = type_info->preprocess_shop_action( action, scene_info );
            ptr_item->set_shop_error( action, error );
            
            // disable button
            if ( !is_success_shop_action( error ) ) {
                ptr_item->set_action_state( action, shop_state_disable );
            }
    		sqc_verbose() 
            	<< "  " << print_shop_action( action ) << ": "
            	<< print_shop_action_state( ptr_item->get_action_state( action ) );
            
        }
    }
    
    sqc_verbose() << "<---shop item: " << type_info->get_type_name() << "";

	
#ifdef _DEBUG
    // no more than 2 button can be active
    {
        int button_count = 0;
        for ( int idx = 0; idx < shop_action_countof; idx++ ) {
            sqc_shop_action action = (sqc_shop_action)idx;
            if ( ptr_item->is_button_visible( action ) ) {
                ++button_count;
            }
        }
        sqc_assert( button_count <= 2 );
    }
#endif
    
    return true;
}

bool sqc_shop::enum_shop_category( 
    const sqc_shop_enum_params& enum_params,
    const sqc::sqc_common_scene_info& scene_info,
    sqc_shop_category_items& items ) {
    
    if ( !m_object_factory ) {
    	sqc_error()
        	<< "shop error: unable to enum shop category. no class factory";
	    return false;
    }
    
    sqc_shop_category_item_ptr ptr_item;
    sqc_string_list type_names = m_object_factory->get_object_names();
    for ( sqc_string_list::const_iterator it = type_names.begin();
    		it != type_names.end(); ++it ) {
            
        sqc_string const& type_name = *it;
        sqc_object_info* type_info = m_object_factory->get_object_info( type_name.c_str() );
        
        if ( fill_item( type_info, enum_params, scene_info, ptr_item ) ) {
			items.push_back( ptr_item );
        }
    }
    
    std::sort( items.begin(), items.end(), sort_shop_items );
    
    return true;
}


sqc_shop_category_item_ptr sqc_shop::find_shop_item_by_type_id( 
    const sqc_shop_enum_params& enum_params, 
    const sqc::sqc_common_scene_info& scene_info,
    int type_id ) {
    if ( !m_object_factory ) {
    	sqc_error()
        	<< "shop error: unable to find shop item by type_id. no class factory";
	    return sqc_shop_category_item_ptr();
    }
    
    sqc_shop_category_item_ptr ptr_item;
    sqc_string_list type_names = m_object_factory->get_object_names();
    for ( sqc_string_list::const_iterator it = type_names.begin();
    		it != type_names.end(); ++it ) {
            
        sqc_string const& type_name = *it;
        sqc_object_info* type_info = m_object_factory->get_object_info( type_name.c_str() );
        
        if ( !type_info ) {
        	continue;
        }
        
        if ( type_info->get_type_id() != type_id ) {
        	continue;
        }
        
        if ( !fill_item( type_info, enum_params, scene_info, ptr_item ) ) {
            sqc_error()
                << "shop error: unable to fill shop item by type_id. no class factory";
        }
        break;
    }
    return ptr_item;
}

sqc_shop_category_item_ptr sqc_shop::find_shop_item_by_type_name( 
    const sqc_shop_enum_params& enum_params, 
    const sqc::sqc_common_scene_info& scene_info,
    const sqc_string& type_name ) {
    if ( !m_object_factory ) {
    	sqc_error()
        	<< "shop error: unable to find shop item by type_name. no class factory";
	    return sqc_shop_category_item_ptr();
    }
    
    sqc_shop_category_item_ptr ptr_item;
    sqc_string_list type_names = m_object_factory->get_object_names();
    for ( sqc_string_list::const_iterator it = type_names.begin();
    		it != type_names.end(); ++it ) {
            
        sqc_string const& test_type_name = *it;
        if ( test_type_name != type_name ) {
        	continue;
        }
        
        sqc_object_info* type_info = m_object_factory->get_object_info( type_name.c_str() );
        if ( !type_info ) {
        	continue;
        }
        
        if ( !fill_item( type_info, enum_params, scene_info, ptr_item ) ) {
            sqc_error()
                << "shop error: unable to fill shop item by type_name. no class factory";
            break;
        }
        break;
    }
    return ptr_item;
}

//
//  shop constructions
//

sqc_string_map sqc_shop::get_construction_info( sqc_string const &category ) {
    sqc_string_map result;

#if defined SQC_CITY_GAME

    sqc_city_buildingplace_info *type_info = 
    static_cast<sqc_city_buildingplace_info *>(m_object_factory->get_object_info( category.c_str() ));
    
    sqc_string_vector builds = type_info->get_build();
    
    if (builds.size()) {
        sqc_object_info *info = m_object_factory->get_object_info(builds[0].c_str());
        
        if (info) {
            result["description"] = info->get_description();
            result["image_path"] = info->get_shop_image_path();
            result["description_text"] = info->get_description_text();
        }
    }

#endif
    
    return result;
}

// retrieve shop construction name
sqc_string sqc_shop::get_shop_construction_category_name( 
    const sqc_construction_category& category ) {
    
    return get_construction_info(category)["description"];
}

sqc_string sqc_shop::get_shop_construction_category_image( 
    const sqc_construction_category& category ) {
    
    return get_construction_info(category)["image_path"];
}
sqc_string sqc_shop::get_shop_construction_category_descr( 
    const sqc_construction_category& category ) {
    
    return get_construction_info(category)["description_text"];
}

// enum construction category
bool sqc_shop::enum_shop_construction_category(
    const sqc_construction_category& category,
    sqc_shop_construction_items& items ) {

    if ( !m_object_factory ) {
    	sqc_error()
        << "construction buy error: unable to enum construction items. no class factory";
	    return false;
    }

#if defined SQC_CITY_GAME

	// TODO: replace with fill_item
    
    sqc_city_buildingplace_info *pbuild_info = 
            static_cast<sqc_city_buildingplace_info *>(m_object_factory->get_object_info(category.c_str()));
    
    sqc_assert(pbuild_info);
    
    sqc_string_vector const &builds = pbuild_info->get_build();
    for (sqc_string_vector::const_iterator it = builds.begin(); it != builds.end(); ++it) {
        
        sqc_string type_name = *it;
        sqc_assert( type_name.size() );
        
        sqc_city_object_info *city_type_info = 
            static_cast<sqc_city_object_info *>(m_object_factory->get_object_info( type_name.c_str() ));
        
        if (!city_type_info) {
            sqc_warning() << "construction buy error: object info for type: \"" << type_name << "\" not found";
            continue;
        }
        
        sqc_string str = city_type_info->get_shop_image_path();
        sqc_shop_construction_item_ptr ptr_item(
                                                new sqc_shop_construction_item( city_type_info->get_description(), 
                                                                                city_type_info->get_shop_image_path() ) );
        
        ptr_item->set_object_type( type_name );
        items.push_back( ptr_item );
        
        static int game_level = 1;
        
        int v = city_type_info->get_level();
        if ( v > game_level ) {
	        ptr_item->set_required_level( v );
        }
        
        ptr_item->set_sort_order( city_type_info->get_level() );
        
        v = city_type_info->get_water_consume(); //get_water_produce
        if ( v ) {
	        ptr_item->set_water_change( v );
        }
        
        v = city_type_info->get_power_consume(); //get_power_produce
        if ( v ) {
	        ptr_item->set_power_change( v );
        }
        
        v = city_type_info->get_population_increase(); //get_max_population_increase
        if ( v ) {
	        ptr_item->set_population_change( v );
        }
        
        v = city_type_info->get_exp(); //get_extra_exp
        if ( v ) {
        	ptr_item->set_experience_change( v );
        }
        
        v = city_type_info->get_stage_length(); //get_abandoned_length
        if ( v ) {
        	ptr_item->set_build_time_sec( v / 1000 );
        }
        
        int coins = city_type_info->get_cost_buy_game();
        int bucks = city_type_info->get_cost_buy_real( /*level*/);
        
        if ( coins ) {
        	ptr_item->set_price_in_coins( coins );
        } else if ( bucks ) {
	        ptr_item->set_price_in_megabucks( bucks );
        }
        
        if ( coins && bucks ) {
        	sqc_assert( false );
        }
        
		ptr_item->set_action_state( shop_action_buy, shop_state_enable );
        
        if ( city_type_info->get_buy_as_gift() ) {
        	ptr_item->set_action_state( shop_action_gift, shop_state_enable );        
        }
    }
    
    std::sort( items.begin(), items.end(), sort_shop_items );

#endif//SQC_CITY_GAME
    
    return true;
}

//
//  shop materials
//

sqc_string_map sqc_shop::get_produce_info( sqc_string const &category ) {
    sqc_string_map result;
    
#if defined SQC_CITY_GAME
    
    sqc_city_buildingsite_info *type_info = 
    static_cast<sqc_city_buildingsite_info *>(m_object_factory->get_object_info( category.c_str() ));
    
    sqc_string produce = type_info->get_produce();
    
    if (produce.size()) {
        sqc_object_info *info = m_object_factory->get_object_info(produce.c_str());
        
        if (info) {
            result["description"] = info->get_description();
            result["image_path"] = info->get_shop_image_path();
            result["description_text"] = info->get_description_text();
        }
    }
    

#endif
    
    return result;
}


// retrieve shop material category name
sqc_string sqc_shop::get_shop_material_category_name( 
    const sqc_material_category& category ) {
    
    return get_produce_info(category)["description"];
}

sqc_string sqc_shop::get_shop_material_category_image( 
    const sqc_construction_category& category ) {
    
    return get_produce_info(category)["image_path"];
}
sqc_string sqc_shop::get_shop_material_category_descr( 
    const sqc_material_category& category ) {
    
    return get_produce_info(category)["description_text"];
}

// enum material category
bool sqc_shop::enum_shop_material_category(
                                           const sqc_material_category& category,
                                           const sqc_string_map& input_fill,
                                           const sqc::sqc_common_scene_info& scene_info,
                                           sqc_shop_material_items& items,
                                           sqc_game_object_ptr owner ) {
                                           
    if ( !m_object_factory ) {
    	sqc_error() << "material buy error: unable to enum material items. no class factory";
            
	    return false;
    }

#if defined SQC_CITY_GAME

    sqc_city_buildingsite_info *pbuild_info = 
        static_cast<sqc_city_buildingsite_info *>(m_object_factory->get_object_info(category.c_str()));
    
    if(!pbuild_info)
    {
        sqc_assert(pbuild_info);
        sqc_error() << "can't get_object_info() object name <<" << category.c_str();
            
	    return false;
    }
    
    sqc_shop_material_item_ptr ptr_item;
    sqc_shop_enum_params enum_params( 0, sqc_shop_category_all, material_target );
        
    sqc_quantity_by_name_map quantity = pbuild_info->get_materials_quantity();

    sqc_string_vector const &builds = pbuild_info->get_consumes();
    for (sqc_string_vector::const_iterator it = builds.begin(); it != builds.end(); ++it) {
        
        sqc_string type_name = *it;
        sqc_assert( type_name.size() );
        
        sqc_city_object_info *type_info = 
            static_cast<sqc_city_object_info *>(m_object_factory->get_object_info( type_name.c_str() ));
        
        if (!type_info) {
            sqc_warning() << "material buy error: object info for type: \"" << type_name << "\" not found";
            continue;
        }
        
        if ( fill_item( type_info, enum_params, scene_info, ptr_item ) ) {
        	items.push_back( ptr_item );
            
            // ptr->set_total();
            // ptr->set_count();
        }
        
    }// End: for(sqc_string_vector::const_iterator; ...)

    std::sort( items.begin(), items.end(), sort_shop_items );

#elif defined SQC_FARM_GAME    
    
    sqc_farm_buildsite_info* pbuild_info = 
    static_cast<sqc_farm_buildsite_info*>(m_object_factory->get_object_info(category.c_str()));
    
    if(!pbuild_info)
    {
        sqc_assert(pbuild_info);
        sqc_error() << "can't get_object_info() object name <<" << category.c_str();
        
	    return false;
    }
    
    sqc_shop_material_item_ptr ptr_item;
    sqc_shop_enum_params enum_params( 0, sqc_shop_category_all, material_target );
    
    static sqc_quantity_by_name_map dummy;
    const sqc_quantity_by_name_map& total = pbuild_info->get_materials_quantity();
    const sqc_quantity_by_name_map& count = owner ? owner->get_materials_quantity() : dummy;
    
    sqc_string_vector const &builds = pbuild_info->get_consumes();
    for (sqc_string_vector::const_iterator it = builds.begin(); it != builds.end(); ++it) {
        
        sqc_string type_name = *it;
        sqc_assert( type_name.size() );
        
        sqc_farm_object_info *type_info = 
        static_cast<sqc_farm_object_info *>(m_object_factory->get_object_info( type_name.c_str() ));
        
        if (!type_info) {
            sqc_warning() << "material buy error: object info for type: \"" << type_name << "\" not found";
            continue;
        }
        
        if ( fill_item( type_info, enum_params, scene_info, ptr_item ) ) {
            
            sqc_quantity_by_name_map::const_iterator it;    
            
            // fill total
            it = total.find( type_name );
            if (it != total.end())
                ptr_item->set_total( it->second );
            
            // fill count
            it = count.find( type_name );
            if (it != count.end())
                ptr_item->set_count( it->second );
            
        	items.push_back( ptr_item );
        }
        
    }// End: for(sqc_string_vector::const_iterator; ...)
    
    std::sort( items.begin(), items.end(), sort_shop_items );
    
#endif
    
return true;

}

sqc_string sqc_shop::get_shop_contracts_name() {
    return "Contracts";
}

// enum contracts 
bool sqc_shop::enum_shop_contracts(const sqc_string& type, sqc_shop_contract_items& items ) {
    
    if ( !m_object_factory ) {
    	sqc_error()
        << "contract buy error: unable to enum contracts items. no class factory";
	    return false;
    }
    
#if defined SQC_CITY_GAME
    
    sqc_city_factory_info *factory_info = 
    static_cast<sqc_city_factory_info *>(m_object_factory->get_object_info(type.c_str()));
    
    sqc_assert(factory_info);
    
    sqc_string_vector contracts = factory_info->get_contracts();
    
    for (sqc_string_vector::const_iterator it = contracts.begin(); it != contracts.end(); ++it) {
        
        sqc_string type_name = *it;
        sqc_assert( type_name.size() );
        
        sqc_city_object_info *city_type_info = 
        static_cast<sqc_city_object_info *>(m_object_factory->get_object_info( type_name.c_str() ));
        
        if (!city_type_info) {
            sqc_warning() << "material buy error: object info for type: \"" << type_name << "\" not found";
            continue;
        }
        
        sqc_string str = city_type_info->get_shop_image_path();
        sqc_shop_contract_item_ptr ptr_item(
                                            new sqc_shop_contract_item( city_type_info->get_description(), 
                                                                       city_type_info->get_shop_image_path() ) );
        
        ptr_item->set_object_type( type_name );
        items.push_back( ptr_item );
        
        static int game_level = 1;
        
        int v = city_type_info->get_level();
        if ( v > game_level ) {
	        ptr_item->set_required_level( v );
        }
        
        ptr_item->set_sort_order( city_type_info->get_level() );
        
        v = city_type_info->get_water_consume(); //get_water_produce
        if ( v ) {
	        ptr_item->set_water_change( v );
        }
        
        v = city_type_info->get_power_consume(); //get_power_produce
        if ( v ) {
	        ptr_item->set_power_change( v );
        }
        
        v = city_type_info->get_population_increase(); //get_max_population_increase
        if ( v ) {
	        ptr_item->set_population_change( v );
        }
        
        v = city_type_info->get_exp(); //get_extra_exp
        if ( v ) {
        	ptr_item->set_experience_change( v );
        }
        
        v = city_type_info->get_stage_length(); //get_abandoned_length
        if ( v ) {
        	ptr_item->set_build_time_sec( v / 1000 );
        }
        
        v = city_type_info->get_cost_sell_game(); //get_cost_sell_game
        if ( v ) {
        	ptr_item->set_coins_change( v );
        }

        
        int coins = city_type_info->get_cost_buy_game();
        int bucks = city_type_info->get_cost_buy_real( /*level*/);
        
        if ( coins ) {
        	ptr_item->set_price_in_coins( coins );
        } else if ( bucks ) {
	        ptr_item->set_price_in_megabucks( bucks );
        }
        
        if ( coins && bucks ) {
        	sqc_assert( false );
        }
        
        ptr_item->set_action_state( shop_action_buy, shop_state_enable );
        
        if ( city_type_info->get_buy_as_gift() ) {
	        ptr_item->set_action_state( shop_action_gift, shop_state_enable );
        }
    }
    
    std::sort( items.begin(), items.end(), sort_shop_items );
    
#endif//SQC_CITY_GAME
    
    return true;
}


END_NAMESPACE_SQC_FRAMEWORK
