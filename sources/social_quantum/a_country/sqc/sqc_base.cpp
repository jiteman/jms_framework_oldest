#include "sqc_defs.h"
#include "sqc_base.h"
#include "sqc_yaml.h"

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
#include "sqc_locale_parser.h"
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION

#ifndef SQC_ENABLE_OBJECTS
#import "ObjectBase.h"
#endif//SQC_ENABLE_OBJECTS

#ifndef SQC_OBJECT_DISABLE_DRAWING
#include "country_base/view/sqc_bubble_def.h"
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#include "named_storing/storage_access.h"
#include "named_storing/stl_container_storing.hpp"

NAMESPACE_SQC_INFO

sqc_object_info::sqc_object_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) 
    : object_type_name( t )
    , _superclass_name( superclass_name )
    , object_sqc_type_name("sqc_game_object")
    , drawing( d )
    , level( 0 )
    , cost_buy_game( 0 )
    , cost_sell_game( 0 )
    , cost_buy_real( 0 )
    , multi_buy( 0 )
    , shoppable( false )
    , create( false )
    , apply( false )
    , move( false )
    , pseudo_item( false )
    , is_new( false )
    , can_be_rotate( false )
    , sell( false )
    , build_site( false )
    , buy_as_gift( false )
    , build_length( 0 ) 
    , width( 0 )
    , height( 0 )
    , out_of_bounds( false )
    , tutorial_pay_attention( false )
    , shoppable_tutorial( false )
{
}

#if defined SQC_CONFIGURATOR
bool sqc_object_info::is_equal_to( const sqc_object_info &other ) {
    if ( object_type_name != other.object_type_name ) return false;
    if ( _superclass_name != other._superclass_name ) return false;
    if ( type_id != other.type_id ) return false;
    if ( level != other.level ) return false;
	if ( cost_buy_game != other.cost_buy_game ) return false;
	if ( cost_sell_game != other.cost_sell_game ) return false;
	if ( cost_buy_real != other.cost_buy_real ) return false;

	if ( cost_buy_real == 0 ) {
		if ( cost_buy_real_by_level != other.cost_buy_real_by_level ) return false;
	}

	if ( multi_buy != other.multi_buy ) return false;
	if ( shoppable != other.shoppable ) return false;
	if ( create != other.create ) return false;
	if ( apply != other.apply ) return false;
	if ( pseudo_item != other.pseudo_item ) return false;
	if ( is_new != other.is_new ) return false;

	if ( can_be_rotate != other.can_be_rotate ) return false;
	if ( move != other.move ) return false;

	if ( sell != other.sell ) return false;

	if ( build_site != other.build_site ) return false;
	if ( buy_as_gift != other.buy_as_gift ) return false;
	if ( build_length != other.build_length ) return false;

	if ( shop_department != other.shop_department ) return false;
	if ( width != other.width ) return false;
	if ( height != other.height ) return false;

	if ( image_path != other.image_path ) return false;
	if ( out_of_bounds != other.out_of_bounds ) return false;
    
    if ( upgrade_info != other.upgrade_info ) return false;
    
    if ( tutorial_pay_attention != other.tutorial_pay_attention ) return false;
    if ( shoppable_tutorial != other.shoppable_tutorial ) return false;

    return true;
}

void sqc_object_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;

    level = get_yaml_val<int>( node, "level" );
    cost_buy_game = get_yaml_val<int>( node, "cost_buy_game" );
    cost_sell_game = get_yaml_val<int>( node, "cost_sell_game" );
    cost_buy_real = get_yaml_val<int>( node, "cost_buy_real" );

    if( !cost_buy_real ) {
        sqc_string_map  tempo;
        get_yaml_vals( node, "cost_buy_real", tempo );
        
        for( sqc_string_map::const_iterator i = tempo.begin(); i != tempo.end(); ++i ) {
            cost_buy_real_by_level[atoi( i->first.c_str() )] = atoi(i->second.c_str());
        }
    }

    multi_buy = get_yaml_val<bool>( node, "multi_buy" );
    shoppable = get_yaml_val<bool>( node, "shoppable" );
    create = get_yaml_val<bool>( node, "create" );
    apply = get_yaml_val<bool>( node, "apply" );
    pseudo_item = get_yaml_val<bool>( node, "pseudo_item" );
    
    /*
     #ifndef SQC_CONFIGURATOR
     NSArray *preferredlanguages = [NSLocale preferredLanguages];
     if ([[preferredlanguages objectAtIndex: 0] isEqualToString:@"ru"])
     is_new = get_yaml_val<bool>( node,"new.ru");
     else if ([[preferredlanguages objectAtIndex: 0] isEqualToString:@"en"])
     is_new = get_yaml_val<bool>( node,"new.en");
     else if ([[preferredlanguages objectAtIndex: 0] isEqualToString:@"ko"])
     is_new = get_yaml_val<bool>( node,"new.ko");
     else
     #endif //#ifndef SQC_CONFIGURATOR
     */
    is_new = get_yaml_val<bool>( node,"new");	
    
    bool    fixed_position = get_yaml_val<bool>( node, "fixed_position" );
    bool    free_coords = get_yaml_val<bool>( node, "free_coordinates" ); 

    if( fixed_position||free_coords ) {
        can_be_rotate = false;
        move = false;
    }
    else {
    can_be_rotate = get_yaml_val<bool>( node, "can_be_rotate" );
        move = get_yaml_val<bool>( node, "move" );
        
        // TODO need investigate
        can_be_rotate = move;
    }
    
    if( free_coords ) {
        sell = false;
    }
    else {
        sell = get_yaml_val<bool>( node, "sell" );
    }
    build_site = get_yaml_val<bool>( node, "buildsite" );
    buy_as_gift = get_yaml_val<bool>( node, "buy_as_gift" );
    build_length = get_yaml_length( node, "build_length" );

#ifndef SQC_ENABLE_EXTERNAL_LOCALIZATION
	description = get_yaml_val_localized<sqc_string>( node, "description" );
    sqc::utils::process_description_string(description);
	description_text = get_yaml_val_localized<sqc_string>( node, "description_text" );
    sqc::utils::process_description_string(description_text);
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
	
    shop_department = get_yaml_val<sqc_string>( node, "shop_department" );
    width = get_yaml_val<int>( node, "width" );
    height = get_yaml_val<int>( node, "height" );
    type_id = get_yaml_val<int>( node, "id" ); 

    size_t idx;

    // load image path
    image_path = get_yaml_val<sqc_string>( node, "swf_name" );
    if ( (idx = image_path.rfind( '.' )) != -1 ) {
        image_path.resize( idx );
    }

    out_of_bounds = (get_yaml_val<bool>( node, "out_of_bounds" ) || get_yaml_val<bool>( node, "free_coordinates" ));
    
    get_yaml_vals( node, "modify_upgrade", upgrade_info );
    
    tutorial_pay_attention = get_yaml_val<bool>( node, "tutorial_pay_attention" );
    if( tutorial_pay_attention ) {
        shoppable_tutorial = get_yaml_val<bool>( node, "shoppable_in_tutorial" );
    }
}

bool sqc_object_info::write_to( named_storing::storage_access *named_section ) const {
    if ( !named_section->store_value( "type_identifier", type_id ) ) return false;
    if ( !named_section->store_value( "level", level ) ) return false;
	if ( !named_section->store_value( "cost_buy_game", cost_buy_game ) ) return false;
	if ( !named_section->store_value( "cost_sell_game", cost_sell_game ) ) return false;
	if ( !named_section->store_value( "cost_buy_real", cost_buy_real ) ) return false;

    if ( cost_buy_real == 0 ) {
		if ( !named_storing::store_map( named_section, "cost_buy_real_section", "cost_pair_section", "level_value", "cost_value", cost_buy_real_by_level ) ) return false;
    }

	if ( !named_section->store_value( "multi_buy", multi_buy ) ) return false;
	if ( !named_section->store_value( "shoppable", shoppable ) ) return false;
	if ( !named_section->store_value( "create", create ) ) return false;
	if ( !named_section->store_value( "apply", apply ) ) return false;
	if ( !named_section->store_value( "pseudo_item", pseudo_item ) ) return false;
	if ( !named_section->store_value( "is_new", is_new ) ) return false;

	if ( !named_section->store_value( "can_be_rotate", can_be_rotate ) ) return false;
	if ( !named_section->store_value( "move", move ) ) return false;

	if ( !named_section->store_value( "sell", sell ) ) return false;

	if ( !named_section->store_value( "build_site", build_site ) ) return false;
	if ( !named_section->store_value( "buy_as_gift", buy_as_gift ) ) return false;
	if ( !named_section->store_value( "build_length", build_length ) ) return false;

	if ( !named_section->store_value( "shop_department", shop_department ) ) return false;
	if ( !named_section->store_value( "width", width ) ) return false;
	if ( !named_section->store_value( "height", height ) ) return false;

	if ( !named_section->store_value( "image_path", image_path ) ) return false;
	if ( !named_section->store_value( "out_of_bounds", out_of_bounds ) ) return false;
    
    if ( !named_storing::store_map( named_section, "upgrade_info_section", "upgrade_info_pair", "upgrade_info_key", "upgrade_info_mapped", upgrade_info ) ) return false;
    
    if ( !named_section->store_value( "tutorial_pay_attention", tutorial_pay_attention ) ) return false;
    if ( !named_section->store_value( "shoppable_in_tutorial", shoppable_tutorial ) ) return false;

    return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_object_info::read_from( named_storing::storage_access *named_section ) {
    if ( !named_section->query_value( "type_identifier", type_id ) ) return false;
    if ( !named_section->query_value( "level", level ) ) return false;
	if ( !named_section->query_value( "cost_buy_game", cost_buy_game ) ) return false;
	if ( !named_section->query_value( "cost_sell_game", cost_sell_game ) ) return false;
	if ( !named_section->query_value( "cost_buy_real", cost_buy_real ) ) return false;

    if ( cost_buy_real == 0 ) {
		if ( !named_storing::query_map( named_section, "cost_buy_real_section", "cost_pair_section", "level_value", "cost_value", cost_buy_real_by_level ) ) return false;
    }

	if ( !named_section->query_value( "multi_buy", multi_buy ) ) return false;
	if ( !named_section->query_value( "shoppable", shoppable ) ) return false;
	if ( !named_section->query_value( "create", create ) ) return false;
	if ( !named_section->query_value( "apply", apply ) ) return false;
	if ( !named_section->query_value( "pseudo_item", pseudo_item ) ) return false;
	if ( !named_section->query_value( "is_new", is_new ) ) return false;

	if ( !named_section->query_value( "can_be_rotate", can_be_rotate ) ) return false;
	if ( !named_section->query_value( "move", move ) ) return false;

	if ( !named_section->query_value( "sell", sell ) ) return false;

	if ( !named_section->query_value( "build_site", build_site ) ) return false;
	if ( !named_section->query_value( "buy_as_gift", buy_as_gift ) ) return false;
	if ( !named_section->query_value( "build_length", build_length ) ) return false;

	if ( !named_section->query_value( "shop_department", shop_department ) ) return false;
	if ( !named_section->query_value( "width", width ) ) return false;
	if ( !named_section->query_value( "height", height ) ) return false;

	if ( !named_section->query_value( "image_path", image_path ) ) return false;
	if ( !named_section->query_value( "out_of_bounds", out_of_bounds ) ) return false;
    
    if ( !named_storing::query_map( named_section, "upgrade_info_section", "upgrade_info_pair", "upgrade_info_key", "upgrade_info_mapped", upgrade_info ) ) return false;

    if ( !named_section->query_value( "tutorial_pay_attention", tutorial_pay_attention ) ) return false;
    if ( !named_section->query_value( "shoppable_in_tutorial", shoppable_tutorial ) ) return false;

    return true;
}

int sqc_object_info::get_cost_buy_real( const int level ) const {
    if ( cost_buy_real ) {
        return cost_buy_real;
    }

    if ( !cost_buy_real_by_level.size() ) {
        return 0;
    }
    
    for( std::map< int, int >::const_reverse_iterator i = cost_buy_real_by_level.rbegin(); i != cost_buy_real_by_level.rend(); ++i ) {
        if ( level >= i->first ) {
            return i->second;
        }

		if ( cost_buy_real_by_level.size() ) {
			return cost_buy_real_by_level.begin()->second;
		}
    }

    return 0;
}

SQC_CLASS_FACTORY_RESULT sqc_object_info::create_instance() {
#ifdef SQC_ENABLE_OBJECTS
    return sqc_game_object_ptr( new sqc_game_object( shared_from_this() ) );
#else
    return [[ObjectBase alloc] initWithTypeInfo: this];
#endif //SQC_ENABLE_OBJECTS
}

sqc_shop_error sqc_object_info::preprocess_shop_action(
	const sqc_shop_action shop_action, 
    const sqc_common_scene_info& scene_info ) const {
    
    /*
    shop_action_buy,
	shop_action_gift,
	shop_action_sell,
	shop_action_ask,
	shop_action_receive,
	*/
    
    /*
	shop_result_success,
    shop_result_need_more_level,
    shop_result_need_more_coins,
    shop_result_need_more_gold,
    shop_result_need_more_invitees,
    shop_result_need_more_width,
    shop_result_current_width_is_larger_than_new_one,
    */
    
    if ( shop_action_buy == shop_action ) {
    	int level = get_level();
        if ( level && level > scene_info.level ) {
        	return shop_result_need_more_level;
        }
        
        int coins = get_cost_buy_game();
        int bucks = get_cost_buy_real( scene_info.level );
        
        if ( coins && coins > scene_info.coins ) {
    		return shop_result_need_more_coins;    	
        } 
        
        if ( bucks && bucks > scene_info.bucks ) {
    		return shop_result_need_more_gold;
        }
    }
    
    return shop_result_success;
}

//
//
//
#if defined SQC_CONFIGURATOR
#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
void sqc_object_info_provider::load( yaml::sqc_yaml_node_ptr node, sqc_class_factory_ptr factory, sqc_drawing_provider_ptr drawing_provider, sqc_locale_parser &locale_parser ) {
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
void sqc_object_info_provider::load( yaml::sqc_yaml_node_ptr node, sqc_class_factory_ptr factory, sqc_drawing_provider_ptr drawing_provider ) {
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
    using namespace yaml;
    std::set<sqc_string>    missing_classes;
 
    {
        BEGIN_PROFILED_AREA( "load_object->load_node");
        node->size();
        END_PROFILED_AREA;
    }
    

    for( sqc::yaml::sqc_yaml_node_iterator i = node->begin(); i != node->end(); ++i ) {
        const char     *class_name = i->first;

//#ifdef DEBUG
        if( !strcmp( class_name, "steel" ) ) {
            std::cerr << "load road_junction_buildsite" << std::endl;
        }
//#endif 
        

        {
            assert( class_name );
            BEGIN_PROFILED_AREA( "load_object->duplicate_check");

            if( classes.find( class_name ) != classes.end() ) {
                std::cerr << "class loader: duplicate classes found: \"" << class_name <<"\"" << std::endl;
                continue;
            }
            
            END_PROFILED_AREA;
        }
        
        sqc_class_entry_ptr class_entry;
        
        const char *type_name = get_yaml_val<const char *>( i->second, "super_class" );
        {
            BEGIN_PROFILED_AREA( "load_object->find_class_entry");
            class_entry = factory->get_base_class( class_name );
            if( !class_entry ) {
                
                if( !type_name ) {
                    std::cerr << "class loader: superclass if empty for: \"" << class_name <<"\"" << std::endl;
                    continue;
                }
                
                class_entry = factory->get_base_class( type_name );
                if( !class_entry ) {
                    missing_classes.insert( type_name );
                    std::cerr << "class loader: unknown classes found: \"" << class_name <<"\" for type: \"" << type_name << "\"" << std::endl;
                    //print_node_content( i.second() );
                    continue;
                }
            }
            END_PROFILED_AREA
        }
        
        /*
        // не понятно где брать shop_department
        // HACK
        if ( shop_department == "materials" ) {
	        sqc_class_entry_ptr materials_class_entry = factory->get_base_class( "materials" );
            if ( materials_class_entry ) {
	            class_entry = materials_class_entry;
            }
        }*/
        
        sqc_drawing_ptr drawing;
        
        {
            BEGIN_PROFILED_AREA( "load_object->find drawing" );
            drawing= drawing_provider->lookup( class_name );
            if( !drawing && type_name ) {
                drawing = drawing_provider->lookup( type_name );
            }
            END_PROFILED_AREA;
        }
        
        sqc_object_info_ptr info;
        
        {
            BEGIN_PROFILED_AREA( "load_object->create_instance");
            info = class_entry->create_instance( class_name, type_name == 0 ? std::string() : std::string( type_name ), drawing );
            if( !info ) {
                continue;
            }
            END_PROFILED_AREA;
        }

        {
            BEGIN_PROFILED_AREA( "load_object->load!!!");
            info->load( i->second );
			
#if defined SQC_ENABLE_EXTERNAL_LOCALIZATION
			{
				const sqc_string class_name_string( class_name );
				
				{
					sqc_string description = locale_parser.get_string( class_name_string + ":description" );

					if ( !description.empty() ) {
                        sqc::utils::process_description_string(description);
						info->set_description( description );
					}
				}
				
				{
					sqc_string description_text = locale_parser.get_string( class_name_string + ":description_text" );
					
					if ( !description_text.empty() ) {
                        sqc::utils::process_description_string(description_text);
						info->set_description_text( description_text );
					}
				}
			}
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
			
            END_PROFILED_AREA;
        }

        {
            BEGIN_PROFILED_AREA( "load_object->register");
            classes[strdup( class_name )] = info;
            classes_by_id[info->get_type_id()] = info;
            END_PROFILED_AREA
        }
    }

    {
        BEGIN_PROFILED_AREA( "load_object->report");

        if( !missing_classes.empty() ) {
            std::cerr << "---missed classess" << std::endl;
            for( std::set<sqc_string>::const_iterator i = missing_classes.begin(); i != missing_classes.end(); ++i ) {
                std::cerr << "  - \"" << *i << "\"" << std::endl;
            }
            std::cerr << "---missed classess end" << std::endl;
        }
        END_PROFILED_AREA
    }
}
#endif // #if defined SQC_CONFIGURATOR

sqc_object_info *sqc_object_info_provider::get_object_info( const int type_id ) const {
    sqc_object_info_by_id_map::const_iterator i = classes_by_id.find( type_id );
    if( i != classes_by_id.end() ) {
        return i->second.get();
    }
    return 0;
}

#if defined SQC_ENABLE_EXTERNAL_LOCALIZATION
    bool sqc_object_info_provider::read_from( named_storing::storage_container &named_storage, 
                                             sqc_class_factory_ptr factory, 
                                             sqc_drawing_provider_ptr drawing_provider, 
                                             sqc_locale_parser &locale_parser,
                                             sqc_version_provider_ptr version_provider) {
#else // #if defined SQC_ENABLE_EXTERNAL_LOCALIZATION
        bool sqc_object_info_provider::read_from( named_storing::storage_container &named_storage, 
                                                 sqc_class_factory_ptr factory, 
                                                 sqc_drawing_provider_ptr drawing_provider,
                                                 sqc_version_provider_ptr version_provider) {
#endif // #if defined SQC_ENABLE_EXTERNAL_LOCALIZATION

    std::set< sqc_string > missing_classes;   

    for ( named_storing::storage_access *object_info_section = named_storage.open_section( "object_entry", nullptr ); object_info_section != nullptr; object_info_section = object_info_section->get_next_section() ) {
        sqc_string class_name;
        {
            if ( !object_info_section->query_value( "name_of_class", class_name ) ) return false;
        }
    
        
//#ifdef DEBUG
        if( !strcmp( class_name.c_str(), "cow" ) ) {
            std::cerr << "load road_junction_buildsite" << std::endl;
        }
//#endif 
        

        {
            assert( class_name.c_str() );
            BEGIN_PROFILED_AREA( "load_object->duplicate_check");

            if( classes.find( class_name.c_str() ) != classes.end() ) {
                std::cerr << "class loader: duplicate classes found: \"" << class_name <<"\"" << std::endl;
                continue;
            }
            
            END_PROFILED_AREA;
        }
        
        sqc_class_entry_ptr class_entry;
        
        sqc_string superclass_name;
        {
            if ( !object_info_section->query_value( "name_of_superclass", superclass_name ) ) return false;
        }

//        const char *type_name = get_yaml_val<const char *>( i->second, "super_class" );
        {
            BEGIN_PROFILED_AREA( "load_object->find_class_entry");
            class_entry = factory->get_base_class( class_name );

            if ( !class_entry ) {                
                if ( superclass_name.empty() ) {
                    std::cerr << "class loader: superclass if empty for: \"" << class_name <<"\"" << std::endl;
                    continue;
                }
                
                class_entry = factory->get_base_class( superclass_name );

                if ( !class_entry ) {
                    missing_classes.insert( superclass_name );
                    std::cerr << "class loader: unknown classes found: \"" << class_name <<"\" for type: \"" << superclass_name << "\"" << std::endl;
                    //print_node_content( i.second() );
                    continue;
                }
            }
            END_PROFILED_AREA
        }
        
        // HACK
        sqc_string shop_department;
        if ( !object_info_section->query_value( "shop_department", shop_department ) ) {
        	std::cerr << "class loader: unable to locate shop department" << std::endl;
        }
        
        if ( shop_department == "materials" ) {
	        sqc_class_entry_ptr materials_class_entry = factory->get_base_class( "materials" );
            if ( materials_class_entry ) {
	            class_entry = materials_class_entry;
            }
        }
        
        sqc_drawing_ptr drawing;
        {
            BEGIN_PROFILED_AREA( "load_object->find drawing" );
            drawing= drawing_provider->lookup( class_name );
            if( !drawing && !superclass_name.empty() ) {
                drawing = drawing_provider->lookup( superclass_name );
            }
            END_PROFILED_AREA;
        }
        
        sqc_object_info_ptr info;
        
        {
            BEGIN_PROFILED_AREA( "load_object->create_instance");
            info = class_entry->create_instance( class_name, superclass_name, drawing );
            if( !info ) {
                continue;
            }
            END_PROFILED_AREA;
        }

        {
            BEGIN_PROFILED_AREA( "load_object->load!!!");
            info->read_from( object_info_section );
			
#if defined SQC_ENABLE_EXTERNAL_LOCALIZATION
			{
				const sqc_string class_name_string( class_name );
				
				{
					sqc_string description = locale_parser.get_string( class_name_string + ":description" );
				
					if ( !description.empty() ) {
                        sqc::utils::process_description_string( description );
						info->set_description( description );
					}
				}
				
				{
					sqc_string description_text = locale_parser.get_string( class_name_string + ":description_text" );
					
					if ( !description_text.empty() ) {
                        sqc::utils::process_description_string( description_text );
						info->set_description_text( description_text );
					}
				}
			}
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
			
            END_PROFILED_AREA;
        }

        {
            BEGIN_PROFILED_AREA( "load_object->register");
            
            if (version_provider->is_class_supported(class_name) && version_provider->is_class_supported(superclass_name)) {
                classes[ strdup( class_name.c_str() ) ] = info;
                classes_by_id[ info->get_type_id() ] = info;
            }
            else {
                std::cerr << "class: \"" << class_name << "\" or superclass: \"" << superclass_name << "\" doesn't support in this version.";
            }
            
            END_PROFILED_AREA
        }
    }

    {
        BEGIN_PROFILED_AREA( "load_object->report");

        if( !missing_classes.empty() ) {
            std::cerr << "---missed classess" << std::endl;
            for( std::set<sqc_string>::const_iterator i = missing_classes.begin(); i != missing_classes.end(); ++i ) {
                std::cerr << "  - \"" << *i << "\"" << std::endl;
            }
            std::cerr << "---missed classess end" << std::endl;
        }
        END_PROFILED_AREA
    }

    return true;
}

sqc_object_info *sqc_object_info_provider::get_object_info( const char *type_name ) const {
    sqc_object_info_map::const_iterator i = classes.find( type_name );
    if( i != classes.end() ) {
        return i->second.get();
    }
    return 0;
}


SQC_CLASS_FACTORY_RESULT sqc_object_info_provider::create_instance( const char *class_name ) const {
    
#ifdef DEBUG
    if( !strcmp( class_name, "road_junction_buildsite" ) ) {
        std::cerr << "create road_junction_buildsite" << std::endl;
    }
#endif

    sqc_object_info_map::const_iterator i = classes.find( class_name );
    if( i == classes.end() ) {
        std::cerr << "class factory: unknown class \"" << class_name << "\"" << std::endl;
        return SQC_CLASS_FACTORY_RESULT_NULL;
    }
    if( !i->second ) {
        // case of surrogated objects
        return SQC_CLASS_FACTORY_RESULT_NULL;
    }
    
    //    if( class_name == "derrick" ) {
    //        std::cerr << "class factory: road \"" << class_name << "\"" << std::endl;
    //    }
    
    return i->second->create_instance();
}

SQC_CLASS_FACTORY_RESULT sqc_object_info_provider::create_instance( int class_id ) const {
    sqc_object_info_by_id_map::const_iterator i = classes_by_id.find( class_id );
    if( i == classes_by_id.end() ) {
        return SQC_CLASS_FACTORY_RESULT_NULL;
    }
    if( !i->second ) {
        // case of surrogated objects
        return SQC_CLASS_FACTORY_RESULT_NULL;
    }
    
    return i->second->create_instance();
}


const sqc_string_list& sqc_object_info_provider::get_object_names()
{
    if (!m_objectNames.size())
    {
        for (sqc_object_info_map::const_iterator i = classes.begin(); i != classes.end(); ++i)
        {  
            m_objectNames.push_back(i->first);
        }
    }
    return m_objectNames;
}

END_NAMESPACE_SQC_INFO



//
// object
//
#ifdef SQC_ENABLE_OBJECTS

NAMESPACE_SQC

void sqc_game_object::enumerate_textures( sqc_texture_info_list &result ) {
}

void sqc_game_object::handle_timer()
{
        
}
    
sqc_size sqc_game_object::get_size() const {
    if( !object_info ) {
        return sqc_size( 1, 1 );
    }
    if( orientation )  {
        return sqc_size( object_info->get_height(), object_info->get_width() );
    }
    else {
        return sqc_size( object_info->get_width(), object_info->get_height() );
    }
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_game_object::do_parse_xml( xml::xml_node_ptr node ) {
    object_id = node->get_attribute_int( "id" );
    position.x = node->get_attribute_int( "x" );
    position.y = node->get_attribute_int( "y" );
    orientation = node->get_attribute_bool( "rotation" );
    process_end = node->get_attribute_int( "process_end", -1 );
//    std::cout << "object=" << object_id << ", orientation: " << orientation;
    
    return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_game_object::parse_xml( xml::xml_node_ptr node ) {
    if( !do_parse_xml( node ) ) {
        return false;
    }
    
    reload_textures();
    return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
void sqc_game_object::reload_textures() {
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
void sqc_game_object::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg ) {
    surf::surf_color clr = ctx->get_color();
    ctx->set_color( clr * surf::surf_color(0,0,1,1) );
    sqc_size    size = get_size();
    surf::surf_point   pos1 = coord_conv.field_to_screen( get_position()+sqc_point( 0, 0 ) );
    surf::surf_point   pos2 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, 0 ) );
    surf::surf_point   pos3 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, size.cy ) );
    surf::surf_point   pos4 = coord_conv.field_to_screen( get_position()+sqc_point( 0, size.cy ) );
    
    ctx->set_width( 3 );
    
    surf::surf_curve_ptr    curve = ctx->server().create_curve();
    curve->move_to( pos1 );
    curve->line_to( pos2 );
    curve->line_to( pos3 );
    curve->line_to( pos4 );
    
    curve->draw( ctx );
    
    ctx->set_width( 1 );
    ctx->set_color( clr );
}
    
surf::surf_rect sqc_game_object::get_display_rect( sqc_coord_convertor &coord_conv, bool apply_scroll ) {
    sqc_size    size = get_size();
    surf::surf_point   pos1 = coord_conv.field_to_screen( get_position()+sqc_point( 0, 0 ), apply_scroll ? sqc_coord_convert_mode_draw : sqc_coord_convert_mode_draw_no_scroll );
    surf::surf_point   pos2 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, 0 ), apply_scroll ? sqc_coord_convert_mode_draw : sqc_coord_convert_mode_draw_no_scroll );
    surf::surf_point   pos3 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, size.cy ), apply_scroll ? sqc_coord_convert_mode_draw : sqc_coord_convert_mode_draw_no_scroll );
    surf::surf_point   pos4 = coord_conv.field_to_screen( get_position()+sqc_point( 0, size.cy ), apply_scroll ? sqc_coord_convert_mode_draw : sqc_coord_convert_mode_draw_no_scroll );
    
    return surf::surf_rect( pos1.x, pos2.y, pos3.x - pos1.x, pos4.y - pos2.y );
}
    
bool sqc_game_object::check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv ) {
    sqc_rect rect( get_position(),get_size() );
    sqc_point pos = coord_conv.screen_to_field( point );
    return rect.point_in_rect( pos );
}
	
bool sqc_game_object::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner ) {
	if( object_info ) {
		sqc::framework::sqc_bubble_element element;
		element.tag = "caption";
		element.text = object_info->get_description();
		bubble.elements.push_back(element);
	}
	return false;
}


#endif 


END_NAMESPACE_SQC

#endif //SQC_ENABLE_OBJECTS
