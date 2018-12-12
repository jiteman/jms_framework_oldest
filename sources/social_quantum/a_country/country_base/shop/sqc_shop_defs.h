#pragma once

#include "../sqc/sqc_base.h"

#include "../framework/sqc_framework_defs.h"
#include "../country_base/sqc_country_common.h"


NAMESPACE_SQC

enum sqc_shop_target {
	shop_target,				// buy || gift
	material_target,			// ask || buy
	construction_target,		// buy
	
	available_gift_target,		// gift
	received_gift_target,		// sell || receive
	wishes_target,				// gift
    view_only_target            // without button.
};


// shop categories
enum sqc_shop_category {
	sqc_shop_category_unknown,
    sqc_shop_category_all,
#if defined SQC_CITY_GAME
    sqc_shop_category_houses,
    sqc_shop_category_factories,
    sqc_shop_category_leisures,
    sqc_shop_category_terrains,
    sqc_shop_category_power,
    sqc_shop_category_roads,
    sqc_shop_category_materials,
    sqc_shop_category_expand,
#elif defined SQC_FARM_GAME
    sqc_shop_category_materials,
    sqc_shop_category_extra,
    sqc_shop_category_automation,
    sqc_shop_category_decorations,
    sqc_shop_category_flowers,
	sqc_shop_category_seeds,
    sqc_shop_category_houses,
    sqc_shop_category_trees,
    sqc_shop_category_factories,
    sqc_shop_category_fertilizers,
    sqc_shop_category_animals,
    sqc_shop_category_expand,
#else
#error uncompatible game target
#endif
};

struct sqc_shop_enum_params {

	sqc_shop_enum_params( int l, sqc_shop_category c, sqc_shop_target t,bool n = false ) 
    	: enum_level( l )
        , enum_category( c )
        , shop_target( t )
        , show_only_new(n) {
    }
    
    bool show_only_new;
    
	int enum_level;// if 0 - enum all
	sqc_shop_category	enum_category;// if sqc_shop_category_all - enum all
	sqc_shop_target		shop_target;
};

// shop item cells elements visibility
enum sqc_shop_item_show_flags {
	sqc_shop_item_show_power_change         = (1 << 0),
	sqc_shop_item_show_water_change         = (1 << 1),
	sqc_shop_item_show_population_change    = (1 << 2),
    sqc_shop_item_show_coins_change         = (1 << 3),
	sqc_shop_item_show_experience_change    = (1 << 4),
    sqc_shop_item_show_time_build           = (1 << 5),
	sqc_shop_item_show_price_in_coins       = (1 << 6),
    sqc_shop_item_show_price_in_megabucks   = (1 << 7),

    sqc_shop_item_show_sell_price_in_coins  = (1 << 8),
    sqc_shop_item_show_error                = (1 << 9),
    
};

typedef unsigned int sqc_shop_item_show_mask;



enum sqc_shop_action_state {
    shop_state_invisible,
    shop_state_disable,
	shop_state_enable,
};


inline
sqc_string print_shop_action_state( sqc_shop_action_state state ) {
    if ( shop_state_invisible == state )	return "invisible";
    else if ( shop_state_disable == state )	return "disable";
	else if ( shop_state_enable == state )	return "enable";
	return "unknown_action_state";
}

/// Enumeration of ways to create object
enum sqc_create_action {
	create_action_place_to_field,    //! object can be placed on the playing field (ex.: house, cow, etc) 
    create_action_apply_to_field,    //! object can be applied to the playing field (ex.: game extension)
    create_action_use_in_construction, //! object can be applied to another object (ex.: brick, any material)
};

//
//  basic shop item
//
class sqc_shop_item {
public:
    sqc_shop_item(
        const sqc_string& name,
        const sqc_string& image_name )
    : m_name( name )
    , m_image_name( image_name )
    , m_object_type_id( 0 )
    , m_water_change( 0 )
    , m_power_change( 0 )
    , m_coins_change( 0 )
    , m_population_change( 0 )
    , m_experience_change( 0 )
    , m_build_time_sec( 0 )
    , m_price_in_coins( 0 )
    , m_price_in_megabucks( 0 )
    , m_sell_price_in_coins( 0 )
    , m_shop_show_mask( 0 )
    , m_required_level( 0 )
    , m_sort_order( 0 )
    , m_size_x(0)
    , m_category(sqc_shop_category_unknown)
    , m_field_no(0)
    , m_create_action(create_action_place_to_field)
    
    {
    	memset( &m_action_state, 0, sizeof(m_action_state) );
        memset( &m_shop_errors, 0, sizeof(m_shop_errors) );
    }
    
    const sqc_string& name() const {
        return m_name;
    }
    const sqc_string& image_name() const {
        return m_image_name;
    }

    void set_name(sqc_string name) {
        m_name = name;
    }
    
    void set_image_name( const sqc_string& image_name) {
        m_image_name = image_name;
    }
    
    void set_object_type( const sqc_string& type ) {
    	m_object_type = type;
    }
    const sqc_string& object_type() const {
    	return m_object_type;
    }
    void set_object_type_id( const sqc_int type_id ) {
    	m_object_type_id = type_id;
    }
    const sqc_int& object_type_id() const {
    	return m_object_type_id;
    }
    
    sqc_shop_item_show_mask show_mask() const {
        return m_shop_show_mask;
    }
    
    const int water_change() const {
        return m_water_change;
    }
    void set_water_change( int w ) {
        m_shop_show_mask |= sqc_shop_item_show_water_change;
        m_water_change = w;
    }

    const int power_change() const {
        return m_power_change;
    }
    void set_power_change( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_power_change;
        m_power_change = p;
    }

    const int coins_change() const {
        return m_coins_change;
    }
    void set_coins_change( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_coins_change;
        m_coins_change = p;
    }
    
    const int population_change() const {
        return m_population_change;
    }
    void set_population_change( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_population_change;
        m_population_change = p;
    }

    const int experience_change() const {
        return m_experience_change;
    }
    void set_experience_change( int e ) {
        m_shop_show_mask |= sqc_shop_item_show_experience_change;
        m_experience_change = e;
    }
    
    const int build_time_sec() const {
        return m_build_time_sec;
    }
    void set_build_time_sec( int s ) {
        m_shop_show_mask |= sqc_shop_item_show_time_build;
        m_build_time_sec = s;
    }

    const int price_in_coins() const {
        return m_price_in_coins;
    }
    void set_price_in_coins( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_price_in_coins;
        m_price_in_coins = p;
    }
    
    const int sell_price_in_coins() const {
        return m_sell_price_in_coins;
    }
    void set_sell_price_in_coins( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_sell_price_in_coins;
        m_sell_price_in_coins = p;
    }

    const int price_in_megabucks() const {
        return m_price_in_megabucks;
    }
    void set_price_in_megabucks( int p ) {
        m_shop_show_mask |= sqc_shop_item_show_price_in_megabucks;
        m_price_in_megabucks = p;
    }

	sqc_shop_action_state get_action_state( sqc_shop_action action ) const {
    	return m_action_state[action];
    }
	void set_action_state( sqc_shop_action action, sqc_shop_action_state state ) {
    	m_action_state[action] = state;
    }
    
    sqc_shop_error get_shop_error( sqc_shop_action action ) const {
	    return m_shop_errors[action];
    }
    void set_shop_error( sqc_shop_action action, sqc_shop_error error ) {
	    m_shop_errors[action] = error;
    }
    
    // helpers
    bool is_button_visible( sqc_shop_action action ) const {
    	return ( shop_state_invisible != m_action_state[action] );
    }
    bool is_button_disable( sqc_shop_action action ) const {
    	return ( shop_state_disable == m_action_state[action] );
    }
    // helpers
    
    void set_required_level( int level ) {
        m_required_level = level;
    }
    const int required_level() const {
        return m_required_level;
    }

    const sqc_string&  get_buy_error() const {
        return m_error;
    }
    void set_buy_error( const sqc_string& str_error ) {
        m_shop_show_mask |= sqc_shop_item_show_error;
        m_error = str_error;
    }
    
    void set_sort_order( int sort_order ) {
        m_sort_order = sort_order;
    }
    int get_sort_order() const {
        return m_sort_order;
    }
    
    void set_size_x(int size_x) {
    	m_size_x = size_x;
    }
    
    int get_size_x() {
    	return m_size_x;
    }
    
    sqc_shop_category get_category() {
    	return m_category;
    }

    void set_category(sqc_shop_category category) {
    	m_category = category;
    }
    
    int get_field_no() {
    	return m_field_no;
    }
    
    void set_field_no(int field_no) {
    	m_field_no = field_no;
    }
    
    void set_create_action(sqc_create_action act) {
    	m_create_action = act;
    }

    sqc_create_action get_create_action() {
    	return m_create_action;
    }
     
protected:
    sqc_string  m_name;
    sqc_string  m_image_name;
    sqc_string  m_object_type;
    sqc_int     m_object_type_id;
    int         m_water_change;
    int         m_power_change;
    int         m_population_change;
    int         m_experience_change;
    int         m_coins_change;
    int         m_build_time_sec;
    int         m_price_in_coins;
    int			m_price_in_megabucks;
    int			m_sell_price_in_coins;

    sqc_string  m_error;
    int			m_required_level;
    int			m_sort_order;
    int			m_size_x;
    sqc_shop_category m_category;
    int 		m_field_no;
    
    sqc_shop_item_show_mask     m_shop_show_mask;
    
    sqc_shop_action_state		m_action_state[shop_action_countof];
    sqc_shop_error				m_shop_errors[shop_action_countof];
    sqc_create_action			m_create_action;
};    

typedef std::tr1::shared_ptr<sqc_shop_item>	sqc_shop_item_ptr;


//
//  shop category item
//
class sqc_shop_category_item : public sqc_shop_item {
public:
    sqc_shop_category_item( const sqc_string& name,
                       const sqc_string& image_name )
    : sqc_shop_item( name, image_name ) {
    }
    
};

typedef std::tr1::shared_ptr<sqc_shop_category_item>	sqc_shop_category_item_ptr;
typedef std::vector<sqc_shop_category_item_ptr>         sqc_shop_category_items;
typedef std::deque<sqc_shop_category_item_ptr>          sqc_shop_category_deque_items;


//
//  shop contract item
//
class sqc_shop_contract_item : public sqc_shop_item {
public:
    sqc_shop_contract_item( const sqc_string& name,
                           const sqc_string& image_name )
    : sqc_shop_item( name, image_name ) {
    }
    
};

typedef std::tr1::shared_ptr<sqc_shop_contract_item>	sqc_shop_contract_item_ptr;
typedef std::vector<sqc_shop_contract_item_ptr>         sqc_shop_contract_items;


//
//  shop building base item
//
class sqc_shop_building_base_item : public sqc_shop_item {
public:
    sqc_shop_building_base_item( const sqc_string& name,
                           const sqc_string& image_name )
    : sqc_shop_item( name, image_name ){
    }
    
};

typedef std::tr1::shared_ptr<sqc_shop_building_base_item>	
                                        sqc_shop_building_base_item_ptr;

//
//  shop construction item
//
class sqc_shop_construction_item : public sqc_shop_building_base_item {
public:
    sqc_shop_construction_item( const sqc_string& name,
                           const sqc_string& image_name )
    : sqc_shop_building_base_item( name, image_name ) {
    }
};

typedef std::tr1::shared_ptr<sqc_shop_construction_item>	sqc_shop_construction_item_ptr;
typedef std::vector<sqc_shop_construction_item_ptr>         sqc_shop_construction_items;

typedef sqc_string  sqc_construction_category;

//
//  shop material item
//
class sqc_shop_material_item : public sqc_shop_building_base_item {
public:
    sqc_shop_material_item( const sqc_string& name,
                               const sqc_string& image_name )
    : sqc_shop_building_base_item( name, image_name )
    , m_total( 0 )
    , m_count( 0 ) {
    }
    void set_total( int total ) {
        m_total = total;
    }
    int total() const {
        return m_total;
    }
    void set_count( int count ) {
        m_count = count;
    }
    int count() const {
        return m_count;
    }
protected:
    int m_total;
    int m_count;
};

typedef std::tr1::shared_ptr<sqc_shop_material_item>	sqc_shop_material_item_ptr;
typedef std::vector<sqc_shop_material_item_ptr>         sqc_shop_material_items;

typedef sqc_string  sqc_material_category;

END_NAMESPACE_SQC
