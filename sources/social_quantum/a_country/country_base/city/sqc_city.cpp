#include "sqc_city.h"
#include "sqc_city_objects.h"
#ifdef SQC_ENABLE_OBJECTS


#define CREATE_OBJECT( CLASS )  sqc_game_object_ptr( new CLASS( shared_from_this() ) )

#define CREATE_CITY_OBJECT_BASE   CREATE_OBJECT( sqc::city::sqc_city_object_base )
#define CREATE_CITY_FACTORY_BASE  CREATE_OBJECT( sqc::city::sqc_factory_base )
#define CREATE_CITY_BUILDSITE_BASE  CREATE_OBJECT( sqc::city::sqc_buildsite_base )
#define CREATE_BUILDINIG_PLACE      CREATE_OBJECT( sqc::city::sqc_building_place_base )
#define CREATE_COMPLEX_BUILDSITE_FACTORY_BASE   CREATE_OBJECT( sqc::city::sqc_complex_buildsite_factory_base )
#define CREATE_CONTRACT_BASE CREATE_OBJECT( sqc::city::CONTRACT_BASE_CLASS )

NAMESPACE_SQC_INFO

typedef sqc::city::sqc_city_object_base    CITY_OBJECT_BASE_CLASS;
typedef sqc::city::sqc_house_base          HOUSE_BASE_CLASS;
typedef sqc::city::sqc_leisure_base        LEISURE_BASE_CLASS;
typedef sqc::city::sqc_power_base          POWER_BASE_CLASS;
typedef sqc::city::sqc_terrain_base        TERRAIN_BASE_CLASS;
typedef sqc::city::sqc_factory_base        FACTORY_BASE_CLASS;
typedef sqc::city::sqc_buildsite_base      BUILDSITE_BASE_CLASS;
typedef sqc::city::sqc_building_place_base BUILDINGPLACE_BASE_CLASS;
typedef sqc::city::sqc_road_base           ROAD_OBJECT_BASE_CLASS;
typedef sqc::city::sqc_railroad_base	   RAILROAD_OBJECT_BASE_CLASS;
typedef sqc::city::sqc_parking_base        PARKING_CLASS;
typedef sqc::city::sqc_automate_base       AUTOMATE_BASE_CLASS;
typedef sqc::city::sqc_contract_base       CONTRACT_BASE_CLASS;
typedef sqc::city::sqc_city_hall           CITY_HALL_LEISURE_BASE_CLASS;
typedef sqc::city::sqc_tax_collector       TAX_COLLECTOR_LEISURE_BASE_CLASS;
typedef sqc::city::sqc_shop_department_leisure SHOP_DEPARTMENT_LEISURE_BASE_CLASS;
typedef sqc::city::sqc_sport_complex_terrain   SPORT_COMPLEX_TERRAIN_BASE_CLASS;
typedef sqc::city::sqc_island_hotel_buildsite  ISLAND_HOTEL_BUILDSITE_TERRAIN_BASE_CLASS;
typedef sqc::city::sqc_bungalow            BUNGALOW_CLASS;
typedef sqc::city::sqc_inactive_place       INACTIVE_PLACE_CLASS;
typedef sqc::city::sqc_expand_base       EXPAND_BASE_CLASS;
typedef sqc::city::sqc_complex_buildsite_factory_base COMPLEX_BUILDSITE_FACTORY_BASE_CLASS;

END_NAMESPACE_SQC_INFO


#else

#import "CityObjectBase.h"
#import "HouseBase.h"
#import "LeisureBase.h"
#import "TerrainBase.h"
#import "PowerBase.h"
#import "CityFactoryBase.h"
#import "BuildingPlace.h"
#import "CityBuildsiteBase.h"
#import "TaxCollectorLeisureBase.h"
#import "CityHallLeisureBase.h"
#import "ContractBase.h"
#import "TerrainBase.h"
#import "RoadObjectBase.h"
#import "RailroadObjectBase.h"
#import "Parking.h"
#import "AutomateBase.h"
#import "OilStorageBuildsiteTerrainBase.h"
#import "OilPipelineBuildsiteTerrainBase.h"
#import "GasliftBuildsiteTerrainBase.h"
#import "IslandHotelBuildsiteTerrainBase.h"
#import "ShopDepartmentLeisureBase.h"
#import "SportComplexTerrainBase.h"
#import "InactivePlace.h"
#import "ExpandBase.h"
#import "ComplexBuildsiteFactoryBase.h"

#import "Bungalow.h"

#define CREATE_CITY_OBJECT_BASE   [[CityObjectBase alloc] initWithTypeInfo:this]
#define CREATE_CITY_FACTORY_BASE  [[CityFactoryBase alloc] initWithTypeInfo:this]
#define CREATE_CITY_BUILDSITE_BASE  [[CityBuildsiteBase alloc] initWithTypeInfo:this]
#define CREATE_BUILDINIG_PLACE      [[BuildingPlace alloc] initWithTypeInfo:this]
#define CREATE_COMPLEX_BUILDSITE_FACTORY_BASE [[ComplexBuildsiteFactoryBase alloc] initWithTypeInfo:this]
#define CREATE_CONTRACT_BASE    [[ContractBase alloc] initWithTypeInfo:this]

#define CONTRACT_BASE_CLASS ContractBase
#define CITY_OBJECT_BASE_CLASS CityObjectBase
#define ROAD_OBJECT_BASE_CLASS RoadObjectBase
#define RAILROAD_OBJECT_BASE_CLASS RailroadObjectBase
#define PARKING_CLASS       Parking
#define AUTOMATE_BASE_CLASS AutomateBase
#define HOUSE_BASE_CLASS    HouseBase
#define LEISURE_BASE_CLASS  LeisureBase
#define POWER_BASE_CLASS    PowerBase
#define INACTIVE_PLACE_CLASS InactivePlace
#define EXPAND_BASE_CLASS ExpandBase
#define SHOP_DEPARTMENT_LEISURE_BASE_CLASS ShopDepartmentLeisureBase
#define TERRAIN_BASE_CLASS TerrainBase
#define MIDDLE_METRO_TERRIAN_BASE_CLASS MiddleMetroTerrainBase
#define LITTLE_METRO_TERRIAN_BASE_CLASS LittleMetroTerrainBase
#define TAX_COLLECTOR_LEISURE_BASE_CLASS TaxCollectorLeisureBase
#define CITY_HALL_LEISURE_BASE_CLASS CityHallLeisureBase
#define ISLAND_HOTEL_BUILDSITE_TERRAIN_BASE_CLASS IslandHotelBuildsiteTerrainBase
#define SPORT_COMPLEX_TERRAIN_BASE_CLASS    SportComplexTerrainBase
#define BUNGALOW_CLASS          Bungalow
#define COMPLEX_BUILDSITE_FACTORY_BASE_CLASS ComplexBuildsiteFactoryBase

#endif //SQC_ENABLE_OBJECTS

#include "sqc/named_storing/storage_access.h"
#include "sqc/named_storing/stl_container_storing.hpp"

NAMESPACE_SQC_INFO 

sqc_city_object_info::sqc_city_object_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
    : sqc_object_info( t, superclass_name, d ) 
    , water_consume( 0 )
    , water_produce( 0 )
    , power_consume( 0 )
    , power_produce( 0 )
    , sort_order( 0 )
    , extra_exp( 0 )
    , extra_coins( 0 )
    , cost_invites( 0 )
    , required_width( 0 )
    , max_width( 0 )
    , stage_length( 0 )
    , abandoned_length( 0 )
    , population_increase( 0 )
    , max_population_increase( 0 )
    , exp( 0 )
    , delayed_animations( false )
    , shed ( false )
    , extra_params(0)
    , items_require(0)
    , fixed_position( false )
    , cost_sell_game(0)
    , extra_type(NONE)
    , dont_expires( false )
{
}
#if defined SQC_CONFIGURATOR
bool sqc_city_object_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_object_info::is_equal_to( other ) ) return false;

	const sqc_city_object_info &other_city = dynamic_cast< const sqc_city_object_info & >( other );

	if ( water_consume != other_city.water_consume ) return false;
	if ( water_produce != other_city.water_produce ) return false;
	if ( power_consume != other_city.power_consume ) return false;
	if ( water_produce != other_city.water_produce ) return false;
	if ( sort_order != other_city.sort_order ) return false;
	if ( extra_exp != other_city.extra_exp ) return false;
	if ( extra_coins != other_city.extra_coins ) return false;
	if ( cost_invites != other_city.cost_invites ) return false;
	if ( required_width != other_city.required_width ) return false;
	if ( max_width != other_city.max_width ) return false;
	if ( stage_length != other_city.stage_length ) return false;

	if ( !are_extra_parameters_equal_to( other ) ) return false;

	if ( abandoned_length != other_city.abandoned_length ) return false;
    if ( dont_expires != other_city.dont_expires ) return false;
	if ( population_increase != other_city.population_increase ) return false;
	if ( max_population_increase != other_city.max_population_increase ) return false;
	if ( exp != other_city.exp ) return false;

	if ( delayed_animations != other_city.delayed_animations ) return false;
    if ( shed != other_city.shed ) return false;
	if ( fixed_position != other_city.fixed_position ) return false;
	if ( cost_sell_game != other_city.cost_sell_game ) return false;
	if ( field_key != other_city.field_key ) return false;
    if ( single_object != other_city.single_object ) return false;
	if ( super_class != other_city.super_class ) return false;
    if ( parent_super_class != other_city.parent_super_class ) return false;

	if ( contract_require != other_city.contract_require ) return false;
	if ( quest_tags != other_city.quest_tags ) return false;

	return true;
}

void sqc_city_object_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    
    sqc_object_info::load( node );
    
    water_consume = get_yaml_val<int>( node, "water_consume" );
    water_produce = get_yaml_val<int>( node, "water_produce" );
    power_consume = get_yaml_val<int>( node, "power_consume" );
    power_produce = get_yaml_val<int>( node, "power_produce" );
    sort_order = get_yaml_val<int>( node, "sort_order" );
    extra_exp = get_yaml_val<int>( node, "extra_exp" );
    extra_coins = get_yaml_val<int>( node, "extra_coins" );
    cost_invites = get_yaml_val<int>( node, "cost_invites" );
    required_width = get_yaml_val<int>( node, "required_width" );
    max_width = get_yaml_val<int>( node, "max_width" );
    stage_length = get_yaml_length( node, "stage_length" );

    load_extra_params(node);

    abandoned_length = get_yaml_length( node, "abandoned_length" );
    dont_expires = get_yaml_val<bool>( node, "dont_expires" );
    population_increase = get_yaml_val<int>( node, "population_increase" );
    max_population_increase = get_yaml_val<int>( node, "max_population_increase" );
    exp = get_yaml_val<int>( node, "exp" );
    delayed_animations = get_yaml_val<bool>( node, "delayed_animations" );
    shed = get_yaml_val<bool>( node, "shed" );
    fixed_position = get_yaml_val<bool>( node, "fixed_position" );
    cost_sell_game = get_yaml_val<int>( node, "cost_sell_game" );
    field_key = get_yaml_val<sqc_string>( node, "field_key" );
    single_object = get_yaml_val<sqc_string>( node, "one_on_stage" );
    super_class = get_yaml_val<sqc_string>( node, "super_class" );
    parent_super_class = get_yaml_val<sqc_string>( node, "parent_super_class" );
    
    
    sqc_yaml_node_ptr   reqs = node->find( "require" );
    if ( reqs && reqs->get_type() == node_type_sequence ) {
        for ( size_t i = 0; i != reqs->size(); ++i ) {
            yaml::sqc_yaml_node_ptr items = reqs->get_child( i );
            if ( items->get_type() == node_type_sequence) {
                for ( size_t ii = 0; ii != items->size(); ++ii) {
                    contract_require.push_back( items->get_child( ii )->get_value_as<sqc_string>() );
                }
            }
            else {
                contract_require.push_back( items->get_value_as<sqc_string>() );
            }

        }
    }
    
    // quest_tag array contains values from yml node plus superclass name and name of this object
    get_yaml_vals( node, "quest_tag", quest_tags );
    sqc_string v = get_yaml_val<sqc_string>( node, "super_class" );
    quest_tags.push_back(v);
    quest_tags.push_back(get_type_name());
}

bool sqc_city_object_info::write_to( named_storing::storage_access *named_section ) const {
    if ( !sqc_object_info::write_to( named_section ) ) return false;

	if ( !named_section->store_value( "water_consume", water_consume ) ) return false;
	if ( !named_section->store_value( "water_produce", water_produce ) ) return false;
	if ( !named_section->store_value( "power_consume", power_consume ) ) return false;
	if ( !named_section->store_value( "power_produce", power_produce ) ) return false;
	if ( !named_section->store_value( "sort_order", sort_order ) ) return false;
	if ( !named_section->store_value( "extra_exp", extra_exp ) ) return false;
	if ( !named_section->store_value( "extra_coins", extra_coins ) ) return false;
	if ( !named_section->store_value( "cost_invites", cost_invites ) ) return false;
	if ( !named_section->store_value( "required_width", required_width ) ) return false;
	if ( !named_section->store_value( "max_width", max_width ) ) return false;
	if ( !named_section->store_value( "stage_length", stage_length ) ) return false;

	if ( !write_extra_parameters_to( named_section ) ) return false;

	if ( !named_section->store_value( "abandoned_length", abandoned_length ) ) return false;
    if ( !named_section->store_value( "dont_expires", dont_expires ) ) return false;
	if ( !named_section->store_value( "population_increase", population_increase ) ) return false;
	if ( !named_section->store_value( "max_population_increase", max_population_increase ) ) return false;
	if ( !named_section->store_value( "exp", exp ) ) return false;

	if ( !named_section->store_value( "delayed_animations", delayed_animations ) ) return false;
    if ( !named_section->store_value( "shed", shed ) ) return false;
	if ( !named_section->store_value( "fixed_position", fixed_position ) ) return false;
	if ( !named_section->store_value( "cost_sell_game", cost_sell_game ) ) return false;
	if ( !named_section->store_value( "field_key", field_key ) ) return false;
    if ( !named_section->store_value( "single_object", single_object ) ) return false;
	if ( !named_section->store_value( "super_class", super_class ) ) return false;
    if ( !named_section->store_value( "parent_super_class", parent_super_class ) ) return false;

	if ( !named_storing::store_vector( named_section, "contract_require_section", "contract_requre_text", contract_require ) ) return false;
	if ( !named_storing::store_vector( named_section, "quest_tag_section", "quest_tag_text", quest_tags ) ) return false;

    return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_object_info::read_from( named_storing::storage_access *named_section ) {
    if ( !sqc_object_info::read_from( named_section ) ) return false;

	if ( !named_section->query_value( "water_consume", water_consume ) ) return false;
	if ( !named_section->query_value( "water_produce", water_produce ) ) return false;
	if ( !named_section->query_value( "power_consume", power_consume ) ) return false;
	if ( !named_section->query_value( "power_produce", power_produce ) ) return false;
	if ( !named_section->query_value( "sort_order", sort_order ) ) return false;
	if ( !named_section->query_value( "extra_exp", extra_exp ) ) return false;
	if ( !named_section->query_value( "extra_coins", extra_coins ) ) return false;
	if ( !named_section->query_value( "cost_invites", cost_invites ) ) return false;
	if ( !named_section->query_value( "required_width", required_width ) ) return false;
	if ( !named_section->query_value( "max_width", max_width ) ) return false;
	if ( !named_section->query_value( "stage_length", stage_length ) ) return false;

	if ( !read_extra_parameters_from( named_section ) ) return false;

	if ( !named_section->query_value( "abandoned_length", abandoned_length ) ) return false;
    if ( !named_section->query_value( "dont_expires", dont_expires ) ) return false;
	if ( !named_section->query_value( "population_increase", population_increase ) ) return false;
	if ( !named_section->query_value( "max_population_increase", max_population_increase ) ) return false;
	if ( !named_section->query_value( "exp", exp ) ) return false;

	if ( !named_section->query_value( "delayed_animations", delayed_animations ) ) return false;
    if ( !named_section->query_value( "shed", shed ) ) return false;
	if ( !named_section->query_value( "fixed_position", fixed_position ) ) return false;
	if ( !named_section->query_value( "cost_sell_game", cost_sell_game ) ) return false;
	if ( !named_section->query_value( "field_key", field_key ) ) return false;
    if ( !named_section->query_value( "single_object", single_object ) ) return false;
	if ( !named_section->query_value( "super_class", super_class ) ) return false;
    if ( !named_section->query_value( "parent_super_class", parent_super_class ) ) return false;

	if ( !named_storing::query_vector( named_section, "contract_require_section", "contract_requre_text", contract_require ) ) return false;
	if ( !named_storing::query_vector( named_section, "quest_tag_section", "quest_tag_text", quest_tags ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT  sqc_city_object_info::create_instance() {
    return CREATE_CITY_OBJECT_BASE;
}

#if defined SQC_CONFIGURATOR
bool sqc_city_object_info::are_extra_parameters_equal_to( const sqc_object_info &other ) {
	const sqc_city_object_info &other_city = dynamic_cast< const sqc_city_object_info & >( other );

    if ( extra_params != other_city.extra_params ) return false;

    return true;
}

void sqc_city_object_info::load_extra_params(yaml::sqc_yaml_node_ptr node)
{
    using namespace yaml;
    yaml::sqc_yaml_node_ptr val = node->find( "extra_params" );
        
    if( !val )
    {
        return;
    }
    
    extra_type = NORMAL;
    
    if( val->get_type() == node_type_scalar)
    {
        sqc_string_map objectMap;
        for( sqc_yaml_node_iterator i = val->begin(); i != val->end(); ++i )
        {
            objectMap[(const sqc_string&)i->first] = (const sqc_string&)i->second;
        }
        extra_params.push_back(objectMap);
    }
    else if( val->get_type() == node_type_mapping )
    {
        for( sqc_yaml_node_iterator i = val->begin(); i != val->end(); ++i )
        {
            sqc_string next_entry = i->first; 
            
            yaml::sqc_yaml_node_ptr NextVal = val->find(next_entry.c_str());
            
            if( !NextVal )
            {
                continue;
            }
            
            if (next_entry == "required") {
                extra_type = REQUIRED;
                if( NextVal->get_type() == node_type_sequence )
                {                   
                    for ( size_t ii = 0; ii != NextVal->size(); ++ii) {                        
                        items_require.push_back( NextVal->get_child( ii )->get_value_as<sqc_string>() );
                    }            
                    
                }
                
            }else {                
                        
                sqc_string_map objectMap;
                objectMap["object_name"] =  next_entry;          
                
                if( val->get_type() == node_type_mapping )
                {
                    for( sqc_yaml_node_iterator i = val->begin(); i != val->end(); ++i )
                    {
                        const char  *raw = i->second->get_value_raw();
                        if( raw ) {
                            objectMap[i->first] = raw;
                        }
                    }
                }
                extra_params.push_back(objectMap);
            }
        }
    }
}

bool sqc_city_object_info::write_extra_parameters_to( named_storing::storage_access *named_section ) const {
	if ( !named_storing::store_vector_of_maps( named_section, "extra_parameter_section", "extra_parameter_map_section", "extra_parameter_pair_section", "first_text", "second_text", extra_params ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_object_info::read_extra_parameters_from( named_storing::storage_access *named_section ) {
    if ( !named_storing::query_vector_of_maps( named_section, "extra_parameter_section", "extra_parameter_map_section", "extra_parameter_pair_section", "first_text", "second_text", extra_params ) ) return false;

    return true;
}

#if defined SQC_CONFIGURATOR
bool sqc_city_expand_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_expand_info &other_city = dynamic_cast< const sqc_city_expand_info & >( other );

	if ( m_field_key != other_city.m_field_key ) return false;
	if ( m_size_x != other_city.m_size_x ) return false;

	return true;
}

void sqc_city_expand_info::load( yaml::sqc_yaml_node_ptr node ) {
	sqc_city_object_info::load( node );

	m_field_key = yaml::get_yaml_val< sqc_string >( node, "field_key" );

	if ( m_field_key.length() > 0 ) {
		yaml::sqc_yaml_node_ptr modify_upgrade = node->find( "modify_upgrade" );

		if ( modify_upgrade && modify_upgrade->get_type() == yaml::node_type_mapping ) {
			m_size_x = yaml::get_yaml_val< int >( modify_upgrade, m_field_key.c_str() );
		}
	}
}

bool sqc_city_expand_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

	if ( !named_section->store_value( "m_field_key", m_field_key ) ) return false;
	if ( !named_section->store_value( "m_size_x", m_size_x ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_expand_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

	if ( !named_section->query_value( "m_field_key", m_field_key ) ) return false;
	if ( !named_section->query_value( "m_size_x", m_size_x ) ) return false;

	return true;
}

sqc_city_extended_contract_info::sqc_city_extended_contract_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
    :sqc_city_object_info(t, superclass_name, d)
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_extended_contract_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	return true;
}

void sqc_city_extended_contract_info::load(yaml::sqc_yaml_node_ptr node)
{
    sqc_city_object_info::load(node);
}

bool sqc_city_extended_contract_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_extended_contract_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_extended_contract_info::create_instance()
{
    return CREATE_CONTRACT_BASE;
}

#if defined SQC_CONFIGURATOR
bool sqc_city_extended_contract_info::are_extra_parameters_equal_to( const sqc_object_info &other ) {
	const sqc_city_extended_contract_info &other_city = dynamic_cast< const sqc_city_extended_contract_info & >( other );

	if ( extra_params != other_city.extra_params ) return false;

	return true;
}

void sqc_city_extended_contract_info::load_extra_params(yaml::sqc_yaml_node_ptr node)
{
    using namespace yaml;
    extra_params.clear();

    yaml::sqc_yaml_node_ptr val;
    val = node->find("extra_params");
    
    if (val)
    {
        sqc_string params_type = get_yaml_val<sqc_string>(val, "type" );
        if (params_type == "external")
        {
            extra_type = EXTERNAL;
            val = val->find("external");
            if (val)
            {
                if (val->get_type() == node_type_mapping)
                {
                    for(sqc_yaml_node_iterator it = val->begin(); it != val->end(); ++it)
                    {
                        sqc_string_map objectMap;
                        
                        objectMap["object_name"] = it->first;
                        
                        for(sqc_yaml_node_iterator jt = it->second->begin(); jt != it->second->end(); ++jt)
                        {
                            const char *raw = jt->second->get_value_raw();
                            if( raw ) {
                                objectMap[jt->first] = raw;
                                extra_params.push_back(objectMap);
                            }
                        }
                    }
                }
            }
            else
            {
            //errror    
            }
            
            return;
        }
        
        if (params_type == "internal")
        {
            extra_type = INTERNAL;
            val = val->find("internal");
            if (val)
            {
                if (val->get_type() == node_type_mapping)
                {
                    for(sqc_yaml_node_iterator it = val->begin(); it != val->end(); ++it)
                    {
                        sqc_string_map objectMap;
                        
                        objectMap["object_name"] = it->first;
                        
                        for(sqc_yaml_node_iterator jt = it->second->begin(); jt != it->second->end(); ++jt)
                        {
                            const char *raw = jt->second->get_value_raw();
                            if( raw ) {
                                objectMap[jt->first] = raw;
                                extra_params.push_back(objectMap);
                            }
                        }
                    }
                }
            }
            else
            {
                //error
            }

            return;
        }
    }
    
}

bool sqc_city_extended_contract_info::write_extra_parameters_to( named_storing::storage_access *named_section ) const {
	if ( !named_storing::store_vector_of_maps( named_section, "extra_parameter_section", "extra_parameter_map_section", "extra_parameter_pair_section", "first_text", "second_text", extra_params ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_extended_contract_info::read_extra_parameters_from( named_storing::storage_access *named_section ) {
	if ( !named_storing::query_vector_of_maps( named_section, "extra_parameter_section", "extra_parameter_map_section", "extra_parameter_pair_section", "first_text", "second_text", extra_params ) ) return false;

	return true;
}

//
//
//

sqc_city_factory_info::sqc_city_factory_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
: sqc_city_object_info( t, superclass_name, d )
, bonus_factory( false )
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_factory_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_factory_info &other_city = dynamic_cast< const sqc_city_factory_info & >( other );

	if ( produce != other_city.produce ) return false;
	if ( contracts != other_city.contracts ) return false;
	if ( bonus_factory != other_city.bonus_factory ) return false;

	return true;
}

void sqc_city_factory_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    sqc_city_object_info::load( node );
    
    get_yaml_vals( node, "produce", produce );
    get_yaml_vals( node, "contracts", contracts );
    bonus_factory = get_yaml_val<bool>( node, "bonus_factory" );
}

bool sqc_city_factory_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

	if ( !named_storing::store_vector( named_section, "produce_section", "produce_text", produce ) ) return false;
	if ( !named_storing::store_vector( named_section, "contracts_section", "contract_text", contracts ) ) return false;
	if ( !named_section->store_value( "bonus_factory", bonus_factory ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_factory_info::read_from( named_storing::storage_access *named_section ) {
    if ( !sqc_city_object_info::read_from( named_section ) ) return false;

    if ( !named_storing::query_vector( named_section, "produce_section", "produce_text", produce ) ) return false;
    if ( !named_storing::query_vector( named_section, "contracts_section", "contract_text", contracts ) ) return false;
	if ( !named_section->query_value( "bonus_factory", bonus_factory ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_factory_info::create_instance() {
    return CREATE_CITY_FACTORY_BASE;
}

sqc_city_buildingsite_info::sqc_city_buildingsite_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
: sqc_city_object_info( t, superclass_name, d )
    , position_x( 0 )
    , position_y( 0 )
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_buildingsite_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_buildingsite_info &other_city = dynamic_cast< const sqc_city_buildingsite_info & >( other );

	if ( consumes != other_city.consumes ) return false;
	if ( materials_quantity != other_city.materials_quantity ) return false;
	if ( produce != other_city.produce ) return false;
	if ( position_x != other_city.position_x ) return false;
	if ( position_y != other_city.position_y ) return false;

	return true;
}

void sqc_city_buildingsite_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    sqc_city_object_info::load( node );
    
    get_yaml_vals( node, "consumes", consumes );
    get_yaml_vals( node, "materials_quantity", materials_quantity );
    produce = get_yaml_val<sqc_string>( node, "produce" );

    position_x = get_yaml_val<int>( node, "position_x" );
    position_y = get_yaml_val<int>( node, "position_y" );
}

bool sqc_city_buildingsite_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

    if ( !named_storing::store_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::store_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;

	if ( !named_section->store_value( "produce", produce ) ) return false;
	if ( !named_section->store_value( "position_x", position_x ) ) return false;
	if ( !named_section->store_value( "position_y", position_y ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_buildingsite_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

    if ( !named_storing::query_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::query_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;

	if ( !named_section->query_value( "produce", produce ) ) return false;
	if ( !named_section->query_value( "position_x", position_x ) ) return false;
	if ( !named_section->query_value( "position_y", position_y ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_buildingsite_info::create_instance() {
    return CREATE_CITY_BUILDSITE_BASE;
}

sqc_city_buildsite_factory_info::sqc_city_buildsite_factory_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
: sqc_city_object_info( t, superclass_name, d )
, position_x( 0 )
, position_y( 0 )
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_buildsite_factory_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_buildsite_factory_info &other_city = dynamic_cast< const sqc_city_buildsite_factory_info & >( other );

	if ( consumes != other_city.consumes ) return false;
	if ( materials_quantity != other_city.materials_quantity ) return false;
	if ( produce != other_city.produce ) return false;
	if ( position_x != other_city.position_x ) return false;
	if ( position_y != other_city.position_y ) return false;
	if ( contracts != other_city.contracts ) return false;

	return true;
}

void sqc_city_buildsite_factory_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    sqc_city_object_info::load( node );
    
    get_yaml_vals( node, "consumes", consumes );
    get_yaml_vals( node, "materials_quantity", materials_quantity );
    produce = get_yaml_val<sqc_string>( node, "produce" );
    
    position_x = get_yaml_val<int>( node, "position_x" );
    position_y = get_yaml_val<int>( node, "position_y" );
    
    get_yaml_vals( node, "contracts", contracts );
}

bool sqc_city_buildsite_factory_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

    if ( !named_storing::store_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::store_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;

	if ( !named_section->store_value( "produce", produce ) ) return false;
	if ( !named_section->store_value( "position_x", position_x ) ) return false;
	if ( !named_section->store_value( "position_y", position_y ) ) return false;

    if ( !named_storing::store_vector( named_section, "contracts_section", "contract_text", contracts ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_buildsite_factory_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

    if ( !named_storing::query_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::query_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;

	if ( !named_section->query_value( "produce", produce ) ) return false;
	if ( !named_section->query_value( "position_x", position_x ) ) return false;
	if ( !named_section->query_value( "position_y", position_y ) ) return false;

    if ( !named_storing::store_vector( named_section, "contracts_section", "contract_text", contracts ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_buildsite_factory_info::create_instance() {
    return CREATE_CITY_BUILDSITE_BASE;
}

sqc_city_buildingplace_info::sqc_city_buildingplace_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d )
: sqc_city_object_info( t, superclass_name, d )
    , position_x( 0 )
    , position_y( 0 )
    , object_id( 0 )
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_buildingplace_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_buildingplace_info &other_city = dynamic_cast< const sqc_city_buildingplace_info & >( other );

	if ( build != other_city.build ) return false;
	if ( require != other_city.require ) return false;
	if ( position_x != other_city.position_x ) return false;
	if ( position_y != other_city.position_y ) return false;
	if ( object_id != other_city.object_id ) return false;

	return true;
}

void sqc_city_buildingplace_info::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    sqc_city_object_info::load( node );
    
    get_yaml_vals( node, "build", build );
    get_yaml_vals( node, "require", require );
    
    position_x = get_yaml_val<int>( node, "position_x" );
    position_y = get_yaml_val<int>( node, "position_y" );
    object_id = get_yaml_val<int>( node, "object_id" );
}

bool sqc_city_buildingplace_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

    if ( !named_storing::store_vector( named_section, "build_section", "build_text", build ) ) return false;
    if ( !named_storing::store_vector( named_section, "require_section", "require_text", require ) ) return false;

	if ( !named_section->store_value( "position_x", position_x ) ) return false;
	if ( !named_section->store_value( "position_y", position_y ) ) return false;
	if ( !named_section->store_value( "object_id", object_id ) ) return false;
	
	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_buildingplace_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

    if ( !named_storing::query_vector( named_section, "build_section", "build_text", build ) ) return false;
    if ( !named_storing::query_vector( named_section, "require_section", "require_text", require ) ) return false;

	if ( !named_section->query_value( "position_x", position_x ) ) return false;
	if ( !named_section->query_value( "position_y", position_y ) ) return false;
	if ( !named_section->query_value( "object_id", object_id ) ) return false;
	
	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_buildingplace_info::create_instance() {
    return CREATE_BUILDINIG_PLACE;
}



template <class T, class U=sqc_city_object_info>
class sqc_object_info_impl : public U {
public:
    sqc_object_info_impl( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : U( t, superclass_name, d )
    {
    }
#ifdef SQC_ENABLE_OBJECTS
    virtual sqc_game_object_ptr create_instance()  {
        return sqc_game_object_ptr( new T( U::shared_from_this() ) );
    }
#else
    virtual id create_instance()  {
        return [[T alloc] initWithTypeInfo:this];
    }
#endif
};

class sqc_road_info : public sqc_object_info_impl<ROAD_OBJECT_BASE_CLASS> {
public:
    sqc_road_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_object_info_impl<ROAD_OBJECT_BASE_CLASS>( t, superclass_name, d ) {
    }
    
    sqc_string get_shop_image_path() const {
        return "road_shop";
    }
};

class sqc_road_parking_info : public sqc_object_info_impl<PARKING_CLASS> {
public:
    sqc_road_parking_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_object_info_impl<PARKING_CLASS>( t, superclass_name, d ) {
    }
    
    sqc_string get_shop_image_path() const {
        return "parking_shop";
    }
};

class sqc_island_hotel_info : public sqc_object_info_impl<ISLAND_HOTEL_BUILDSITE_TERRAIN_BASE_CLASS, sqc_city_buildingsite_info> {
public:
    sqc_island_hotel_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_object_info_impl<ISLAND_HOTEL_BUILDSITE_TERRAIN_BASE_CLASS, sqc_city_buildingsite_info>( t, superclass_name, d ) {
    }
    
    sqc_string get_shop_image_path() const {
        return get_image_path() + "_icon";
    }
};

class sqc_contract_info : public sqc_object_info_impl<CONTRACT_BASE_CLASS> {
public:
    sqc_contract_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_object_info_impl<CONTRACT_BASE_CLASS>( t, superclass_name, d ) {
    }
    
    sqc_string get_shop_image_path() const {
        return get_image_path();
    }
};

class sqc_material_info : public sqc_object_info_impl<CITY_OBJECT_BASE_CLASS> {
public:
    sqc_material_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_object_info_impl<CITY_OBJECT_BASE_CLASS>( t, superclass_name, d ) {
    }
    
    sqc_string get_shop_image_path() const {
        return get_image_path();
    }
    
    virtual sqc_shop_error preprocess_shop_action( 
    	const sqc_shop_action shop_action, 
        const sqc_common_scene_info& scene_info ) const {
        
        sqc_shop_error err = sqc::city::sqc_object_info::preprocess_shop_action( shop_action, scene_info );
        if ( shop_result_success != err ) {
        	std::cerr << "material disable by parent: " << get_type_name();
        	return err;
        }
#ifndef SQC_OBJECT_DISABLE_DRAWING
        
	    if ( shop_action_buy == shop_action ) {
        	if ( !sqc::city::city_framework().game()->is_necessary_material( get_type_name() ) ) {
            	std::cerr << "material disable: " << get_type_name();
            	return city::city_shop_result_not_necessary_material;
            }
            std::cerr << "material allow: " << get_type_name();
        }
#endif        
        return shop_result_success;
    }
};


sqc_city_class_factory::sqc_city_class_factory() : sqc_class_factory() {
    class_factory_map["base"] = sqc_class_entry_ptr( new sqc_class_entry( "base", create_instance<sqc_city_object_info> ) );
    class_factory_map["contract_base"] = sqc_class_entry_ptr( new sqc_class_entry( "contract_base", create_instance<sqc_contract_info > ) );
    class_factory_map["extended_contract_base"] = sqc_class_entry_ptr( new sqc_class_entry( "extended_contract_base", create_instance<sqc_city_extended_contract_info> ) );
    class_factory_map["materials"] = sqc_class_entry_ptr( new sqc_class_entry( "materials", create_instance<sqc_material_info > ) );
    class_factory_map["road_object_base"] = sqc_class_entry_ptr( new sqc_class_entry( "road_object_base", create_instance<sqc_road_info > ) );
    class_factory_map["parking"] = sqc_class_entry_ptr( new sqc_class_entry( "parking", create_instance<sqc_road_parking_info > ) );
    class_factory_map["railroad_object_base"] = sqc_class_entry_ptr( new sqc_class_entry( "railroad_object_base", create_instance<sqc_object_info_impl<RAILROAD_OBJECT_BASE_CLASS> > ) );
    class_factory_map["city_automate"] = sqc_class_entry_ptr( new sqc_class_entry( "city_automate", create_instance<sqc_object_info_impl<AUTOMATE_BASE_CLASS> > ) );
    
    class_factory_map["house_base"] = sqc_class_entry_ptr( new sqc_class_entry( "house_base", create_instance<sqc_object_info_impl<HOUSE_BASE_CLASS> > ) );
    class_factory_map["leisure_base"] = sqc_class_entry_ptr( new sqc_class_entry( "leisure_base", create_instance<sqc_object_info_impl<LEISURE_BASE_CLASS> > ) );
    class_factory_map["shop_department_leisure_base"] = sqc_class_entry_ptr( new sqc_class_entry( "shop_department_leisure_base", create_instance<sqc_object_info_impl<SHOP_DEPARTMENT_LEISURE_BASE_CLASS> > ) );
	class_factory_map["terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "terrain_base", create_instance<sqc_object_info_impl<TERRAIN_BASE_CLASS> > ) );
    class_factory_map["power_base"] = sqc_class_entry_ptr( new sqc_class_entry( "power_base", create_instance<sqc_object_info_impl<POWER_BASE_CLASS> > ) );
    class_factory_map["city_factory_base"] = sqc_class_entry_ptr( new sqc_class_entry( "city_factory_base", create_instance<sqc_city_factory_info> ) );
    class_factory_map["inactive_place"] = sqc_class_entry_ptr( new sqc_class_entry( "inactive_place", create_instance<sqc_object_info_impl<INACTIVE_PLACE_CLASS, sqc_city_buildingplace_info> > ) );
    
    class_factory_map["building_place"] = sqc_class_entry_ptr( new sqc_class_entry( "building_place", create_instance<sqc_city_buildingplace_info> ) );
    class_factory_map["auto_creatable_building_place"] = sqc_class_entry_ptr( new sqc_class_entry( "auto_creatable_building_place", create_instance<sqc_city_autocreate_buildingplace_info> ) );
    class_factory_map["city_buildsite_base"] = sqc_class_entry_ptr( new sqc_class_entry( "city_buildsite_base", create_instance<sqc_city_buildingsite_info> ) );
  
    class_factory_map["tax_collector_leisure_base"] = sqc_class_entry_ptr( new sqc_class_entry( "tax_collector_leisure_base", create_instance<sqc_object_info_impl<TAX_COLLECTOR_LEISURE_BASE_CLASS> > ) );
    class_factory_map["city_hall_leisure_base"] = sqc_class_entry_ptr( new sqc_class_entry( "city_hall_leisure_base", create_instance<sqc_object_info_impl<CITY_HALL_LEISURE_BASE_CLASS> > ) );
    class_factory_map["island_hotel_buildsite_terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "island_hotel_buildsite_terrain_base", create_instance<sqc_island_hotel_info > ) );
    class_factory_map["sport_complex_terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "sport_complex_terrain_base", create_instance<sqc_object_info_impl<SPORT_COMPLEX_TERRAIN_BASE_CLASS, sqc_city_buildingsite_info> > ) );
    class_factory_map["bungalow"] = sqc_class_entry_ptr( new sqc_class_entry( "bungalow", create_instance<sqc_object_info_impl<BUNGALOW_CLASS> > ) );
    
    class_factory_map["expand_base"] = sqc_class_entry_ptr( new sqc_class_entry( "expand_base", create_instance<sqc_object_info_impl<EXPAND_BASE_CLASS, sqc_city_expand_info> > ) );
    
    class_factory_map["complex_buildsite_factory_base"] = sqc_class_entry_ptr( new sqc_class_entry( "complex_buildsite_factory_base", create_instance<sqc_city_complex_buildsite_factory_info> ) );
    
    //  class_factory_map["oil_pipeline_buildsite_terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "oil_pipeline_buildsite_terrain_base", create_instance<sqc_object_info_impl<OilPipelineBuildsiteTerrainBase, sqc_city_buildingsite_info> > ) );
    //  class_factory_map["oil_storage_buildsite_terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "oil_storage_buildsite_terrain_base", create_instance<sqc_object_info_impl<OilStorageBuildsiteTerrainBase, sqc_city_buildingsite_info> > ) );
    //  class_factory_map["gaslift_buildsite_terrain_base"] = sqc_class_entry_ptr( new sqc_class_entry( "gaslift_buildsite_terrain_base", create_instance<sqc_object_info_impl<GasliftBuildsiteTerrainBase, sqc_city_buildingsite_info> > ) );

}

sqc_city_complex_buildsite_factory_info::sqc_city_complex_buildsite_factory_info(const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d)
    :sqc_city_factory_info(t, superclass_name, d)
{
}

#if defined SQC_CONFIGURATOR
bool sqc_city_complex_buildsite_factory_info::is_equal_to( const sqc_object_info &other ) {
	if ( !sqc_city_object_info::is_equal_to( other ) ) return false;

	const sqc_city_complex_buildsite_factory_info &other_city = dynamic_cast< const sqc_city_complex_buildsite_factory_info & >( other );

	if ( consumes != other_city.consumes ) return false;
	if ( materials_quantity != other_city.materials_quantity ) return false;
	if ( produce != other_city.produce ) return false;
	if ( position_x != other_city.position_x ) return false;
	if ( position_y != other_city.position_y ) return false;

	return true;
}

void sqc_city_complex_buildsite_factory_info::load(yaml::sqc_yaml_node_ptr node)
{
    using namespace yaml;
    sqc_city_factory_info::load(node);
    
    get_yaml_vals( node, "consumes", consumes );
    get_yaml_vals( node, "materials_quantity", materials_quantity );
    produce = get_yaml_val<sqc_string>( node, "produce" );
    
    position_x = get_yaml_val<int>( node, "position_x" );
    position_y = get_yaml_val<int>( node, "position_y" );
}

bool sqc_city_complex_buildsite_factory_info::write_to( named_storing::storage_access *named_section ) const {
	if ( !sqc_city_object_info::write_to( named_section ) ) return false;

    if ( !named_storing::store_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::store_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;

	if ( !named_section->store_value( "produce", produce ) ) return false;
	if ( !named_section->store_value( "position_x", position_x ) ) return false;
	if ( !named_section->store_value( "position_y", position_y ) ) return false;

	return true;
}
#endif // #if defined SQC_CONFIGURATOR

bool sqc_city_complex_buildsite_factory_info::read_from( named_storing::storage_access *named_section ) {
	if ( !sqc_city_object_info::read_from( named_section ) ) return false;

    if ( !named_storing::query_vector( named_section, "consumes_section", "consumes_text", consumes ) ) return false;
    if ( !named_storing::query_map( named_section, "material_quantity_section", "material_quantity_pair", "material_name", "material_quantity", materials_quantity ) ) return false;
	
    if ( !named_section->query_value( "produce", produce ) ) return false;
	if ( !named_section->query_value( "position_x", position_x ) ) return false;
	if ( !named_section->query_value( "position_y", position_y ) ) return false;

	return true;
}

SQC_CLASS_FACTORY_RESULT sqc_city_complex_buildsite_factory_info::create_instance()
{
    return CREATE_COMPLEX_BUILDSITE_FACTORY_BASE;
}


///
// buildingplace drawing entry
//
sqc_complex_object_draw_entry::sqc_complex_object_draw_entry( const sqc_string &s ) 
    :caption( s )
    ,popup_offset_correction_x( 0.0f )
    ,popup_offset_correction_y( 0.0f )
    ,factory(false)
    ,build_object(false)
{
}

void sqc_complex_object_draw_entry::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    get_yaml_vals( node, "stage_textures", image_names );
    get_yaml_vals( node, "key_objects", requested_materials );
    get_yaml_vals( node, "animated_stages", animated_stages );
    get_yaml_vals( node, "use_custom_animation",custom_animatios );
    sqc_yaml_node_ptr poc_node = node->find( "popup_offset_correction" );

    if( poc_node )
    {
        if( poc_node->get_type() == node_type_mapping  )
        {
            popup_offset_correction_x = get_yaml_val<float>( poc_node, "x");
            popup_offset_correction_y = get_yaml_val<float>( poc_node, "y");
        }
        else
        {
            std::cerr << "error loading: node popup_offset_correction is not a map" << std::endl;
        }
    }
    
    factory = get_yaml_val<bool>(node, "factory_object");
    popup_object = get_yaml_val<sqc_string>(node, "popup_info");
    custom_texture_counter = get_yaml_val<sqc_string>(node, "custom_texture_counter");
    build_object = get_yaml_val<bool>(node, "isbuid");
    rotated = get_yaml_val<bool>(node, "rotated");
    draw_all_forest = get_yaml_val<bool>(node, "draw_all_forest");
    poc_node = node->find("popup");

    if(poc_node)
    {
        if(poc_node->get_type() == node_type_mapping)
        {
            get_yaml_vals<std::string>(node, "popup", popup_actions);
        }
    }
    
    shop_department = get_yaml_val<sqc_string>(node, "shop_department");
}

//
// buildingplace drawing
//

void sqc_complex_object_drawing::load( yaml::sqc_yaml_node_ptr node ) {
    entries.clear();
    if( node->get_type() != yaml::node_type_mapping ) {
        std::cout << "invalid node type (waiting for map)" << std::endl;
        return;
    }

    using namespace yaml;
    
    sqc::yaml::sqc_yaml_node_ptr    caption_node = node->find( "main_caption" );
    if( caption_node ) {
        main_caption = sqc::yaml::get_yaml_val_localized<sqc_string>( caption_node, "description" );
        sqc::utils::process_description_string(main_caption);
    }
    
        
    yaml::sqc_yaml_node_ptr subitems_node = node->find( "subitems" );

    if( subitems_node && subitems_node->get_type() == node_type_sequence ) {
        
        for( size_t n = 0; n != subitems_node->size(); ++n ) {
            yaml::sqc_yaml_node_ptr subitem  = subitems_node->get_child( n );
            if( subitem->get_type() != node_type_mapping ) {
                continue;
            }
            
            sqc_yaml_node_iterator i = subitem->begin();
            
            std::string name = i->first;
            yaml::sqc_yaml_node_ptr vals = i->second;
            
            if( vals->get_type() != node_type_mapping ) {
                std::cerr << "invalid node type (waiting for map) for \"" << name << "\"" << std::endl;
                continue;
            }
            sqc_complex_object_draw_entry_ptr entry( new sqc_complex_object_draw_entry( name ) );
            entry->load( vals );
            
            entries.push_back( entry );
        }
    }
}

//
// drawing
//
void sqc_city_drawing_provider::load( yaml::sqc_yaml_node_ptr node ) {
    using namespace yaml;
    
    sqc_yaml_node_ptr complex_objects_node = node->find( "complex_objects" );

    if( complex_objects_node ) {
        // load complex objects custom drawing
        if( complex_objects_node->get_type() == node_type_mapping ) {
            for( sqc_yaml_node_iterator i = complex_objects_node->begin(); i != complex_objects_node->end(); ++i ) {
                shared_ptr2<sqc_complex_object_drawing> drawing( new sqc_complex_object_drawing() );
                drawing->load( i->second );
                drawings[i->first] = drawing;
            }
        }
        else {
            std::cerr << "error loading: node \"complex_objects\" is not map" << std::endl;
        }
    }
    
    {
        std::vector<sqc_string> entries;
        yaml::get_yaml_vals( node, "has_animation", entries );
        
        for( std::vector<sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( *i );
            drawing->set_animated( true );
        }
    }
    
    {
        std::vector<sqc_string> entries;
        yaml::get_yaml_vals( node, "has_no_first_frame", entries );
        
        for( std::vector<sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( *i );
            drawing->set_no_first_frame( true );
        }
    }

    {
        std::vector<sqc_string> entries;
        yaml::get_yaml_vals( node, "custom_can_rotate", entries );
        
        for( std::vector<sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( *i );
            drawing->set_custom_can_rotate( true );
        }
        
    }    
    
    {
        std::vector<sqc_string> entries;
        yaml::get_yaml_vals( node, "has_selectable_part", entries );
        
        for( std::vector<sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( *i );
            drawing->set_selectable_part( true );
        }
    }
    
    {
        std::map<sqc_string, sqc_string> entries;
        yaml::get_yaml_vals( node, "custom_images", entries );
        
        for( std::map<sqc_string, sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( i->first );
            drawing->set_custom_image( i->second );
        }
    }

    {
        sqc_yaml_node_ptr poc_node = node->find( "popup_offset_correction" );
        if( poc_node ) {
            if( poc_node->get_type() == node_type_mapping ) {
                for( sqc_yaml_node_iterator i = poc_node->begin(); i != poc_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );
                    
                    float popup_offset_correction_x = get_yaml_val<float>(i->second, "x");
                    float popup_offset_correction_y = get_yaml_val<float>(i->second, "y");
                     
                    drawing->set_popup_offset_correction(popup_offset_correction_x, popup_offset_correction_y);
                }
            }
            else {
                std::cerr << "error loading: node popup_offset_correction is not a map" << std::endl;
            }
        }
    }

    {
        sqc_yaml_node_ptr dup_node = node->find( "duplicate_texture" );
        if( dup_node ) {
            if( dup_node->get_type() == node_type_mapping ) {
                for( sqc_yaml_node_iterator i = dup_node->begin(); i != dup_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );
                    
                    float step_x = get_yaml_val<float>(i->second, "step_x");
                    float step_y = get_yaml_val<float>(i->second, "step_y");
                    
                    drawing->set_duplicate_texture_params(step_x, step_y);
                }
            }
            else {
                std::cerr << "error loading: node duplicate_texture is not a map" << std::endl;
            }
        }
    }
    
    {
        sqc_yaml_node_ptr custom_animated_stages_node = node->find( "custom_animated_stages" );  

        if( custom_animated_stages_node ) {
            // load building places custom drawing
            if( custom_animated_stages_node->get_type() == node_type_mapping ) {
                for( sqc_yaml_node_iterator i = custom_animated_stages_node->begin(); i != custom_animated_stages_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );

                    sqc_string_list stages;
                    if( i->second->get_type() == node_type_sequence ) {
                        for( size_t n = 0; n != i->second->size(); ++n ) {
                            const char *raw = i->second->get_child( n )->get_value_raw();
                            if( raw ) {
                                stages.push_back( raw );
                            }
                        }
                    }
                    
                    drawing->set_animated_stages( stages.begin(), stages.end() );
                }
            }
            else {
                std::cerr << "error loading: node \"custom_animated_stages\" is not map" << std::endl;
            }
        }
    }

    
    {
        std::map<sqc_string, int> entries;
        yaml::get_yaml_vals( node, "zorder_correction", entries );
        
        for( std::map<sqc_string, int>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( i->first );
            drawing->set_zorder_correction( i->second );
        }
    }

    
    {
        std::map<sqc_string, sqc_string> entries;
        yaml::get_yaml_vals( node, "shop_departments", entries );
        
        for( std::map<sqc_string, sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( i->first );
            drawing->set_custom_shop_enabled( true );
            drawing->set_shop_dep( i->second );
        }
    }
    
    {
        std::map<sqc_string, sqc_string> entries;
        yaml::get_yaml_vals( node, "custom_build_icons", entries );
        
        for( std::map<sqc_string, sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( i->first );
            drawing->set_custom_build_icon( i->second );
        }
    }
    
    {
        std::map<sqc_string, sqc_string> entries;
        yaml::get_yaml_vals( node, "traffic_item_category", entries );
        
        for( std::map<sqc_string, sqc_string>::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            sqc_city_drawing_ptr    drawing = lookup_and_allocate( i->first );
            
            if( i->second == "common" ) drawing->set_traffic_category( itemCategoryCommon );
            else if( i->second == "policy" ) drawing->set_traffic_category( itemCategoryPolicy );
            else if( i->second == "fire" ) drawing->set_traffic_category( itemCategoryFire );
            else if( i->second == "military" ) drawing->set_traffic_category( itemCategoryMilitary );
        }
    }
    
    {
        sqc_yaml_node_ptr railroad_objects_node = node->find( "railroad_objects" );
        if ( railroad_objects_node ) {
            
            if (railroad_objects_node->get_type() == node_type_mapping) {
                for( sqc_yaml_node_iterator i = railroad_objects_node->begin(); i != railroad_objects_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );
                    
                    sqc_yaml_node_ptr objects_node = i->second->find( "objects" );
                    if (objects_node) {
                        if( objects_node->get_type() == node_type_sequence ) {
                            sqc_string_list objects;
                            for( size_t ii = 0; ii != objects_node->size(); ++ii ) {
                                sqc_string object = objects_node->get_child( ii )->get_value_as<sqc_string>();
                                if( !object.empty() ) {
                                    std::cout<<object<<std::endl;
                                    objects.push_back( object );
                                }
                            }
                            drawing->set_railroad_objects(objects.begin(), objects.end());   
                        }                            
                    }
                }
            }
            else {
                std::cerr << "error loading: node \"railroad_objects\" is not map" << std::endl;
            }            
        }
    }
    
    {
        sqc_yaml_node_ptr relations_node = node->find( "relations" );
        if ( relations_node ) {
            
            if (relations_node->get_type() == node_type_mapping) {
                for( sqc_yaml_node_iterator i = relations_node->begin(); i != relations_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );
                    
                    sqc_yaml_node_ptr objects_node = i->second->find( "objects" );
                    if (objects_node) {
                        if( objects_node->get_type() == node_type_sequence ) {
                            sqc_string_list objects;
                            for( size_t ii = 0; ii != objects_node->size(); ++ii ) {
                                sqc_string object = objects_node->get_child( ii )->get_value_as<sqc_string>();
                                if( !object.empty() ) {
                                    std::cout<<object<<std::endl;
                                    objects.push_back( object );
                                }
                            }
                            drawing->set_relations(objects.begin(), objects.end());   
                        }                            
                    }
                }
            }
            else {
                std::cerr << "error loading: node \"requirements\" is not map" << std::endl;
            }            
        }
    }
    
    {
        sqc_yaml_node_ptr road_links_node = node->find( "road_links" );  
        
        if( road_links_node ) {
            if( road_links_node->get_type() == node_type_mapping ) {                
                for( sqc_yaml_node_iterator i = road_links_node->begin(); i != road_links_node->end(); ++i ) {
                    sqc_city_drawing_ptr drawing = lookup_and_allocate( i->first );
                    std::vector< std::map<sqc_string, int> > links;
                    
                    if( i->second->get_type() == node_type_mapping ) {
                        for( sqc_yaml_node_iterator n = i->second->begin(); n != i->second->end(); ++n ) {
                            
                            std::map<sqc_string, int> link;
                            std::string param = n->first;
                            link["x"] = get_yaml_val<int>(n->second, "x");
                            link["y"] = get_yaml_val<int>(n->second, "y");
                            link["flag"] = get_yaml_val<int>(n->second, "flag");
                            links.push_back( link );
                        }
                    }
                    
                    drawing->set_road_links( links.begin(), links.end() );
                }
            }
            else {
                std::cerr << "error loading: node \"road_links\" is not map" << std::endl;
            }
        }
    }
    
//    for( sqc_drawing_map::const_iterator i = drawings.begin(); i!=drawings.end(); ++i ) {
//        
//        sqc_city_drawing_ptr d = std::tr1::static_pointer_cast<sqc_city_drawing>( i->second );
//        std::cout << "drawing: \"" << i->first 
//        << "\" animated: " << (d->get_animated() ? "YES":"NO") 
//        << ", first_frame: " << (d->get_no_first_frame() ? "YES":"NO") 
//        << ", custom_image: " << d->get_custom_image()
//        << std::endl;
//    }
}

sqc_city_drawing_ptr sqc_city_drawing_provider::lookup_and_allocate( sqc_string const &type_name ) {
    sqc_drawing_ptr ptr = sqc_drawing_provider::lookup( type_name );
    if( !ptr ) {
        sqc_city_drawing_ptr    new_ptr( new sqc_city_drawing() );
        drawings[type_name] = new_ptr;
        
        return new_ptr;
    }
    return static_pointer2_cast<sqc_city_drawing>( ptr );
}



END_NAMESPACE_SQC_INFO