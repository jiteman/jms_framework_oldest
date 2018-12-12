#pragma once

#include "sqc_defs.h"
#include "sqc_yaml.h"
#include "sqc_utils.h"

#ifndef SQC_OBJECT_DISABLE_DRAWING
#include "sqc_xml.h"
#include "../surf/surf_defs.h"
#endif //#ifndef SQC_OBJECT_DISABLE_DRAWING

#include "named_storing/storage_container.h"
#include "../sqc_build_version.h"

#include <list>
//
// forward declarations
//
NAMESPACE_SQC_INFO 

class sqc_object_info;
typedef shared_ptr2<sqc_object_info>       sqc_object_info_ptr;

enum sqc_object_type {
    type_unknown              = 0,
    type_farm_base            = 0,
    type_farm_livestock       = (1 << 1),
    type_farm_factory         = (1 << 2),
    type_farm_pen             = (1 << 4),
    type_farm_multi_factory   = (1 << 5) + type_farm_factory,
    type_farm_animal_place    = (1 << 6),
    type_farm_building_place  = (1 << 7),
    type_farm_building_site   = (1 << 8),
    type_farm_tree            = (1 << 9),
    type_farm_meat_animal     = (1 << 10),
};


END_NAMESPACE_SQC_INFO


NAMESPACE_SQC

//
//	scene info
//

struct sqc_common_scene_info {
	sqc_common_scene_info() 
    	: level( 0 )
        , coins( 0 )
        , bucks( 0 )
        , experience( 0 )
        , max_experience( 0 )
        , min_experience( 0 )
        , league_number(0)
        , league_level(0)
#if defined SQC_CITY_GAME
    	, water( 0 ), max_water( 0 )
    	, power( 0 ), max_power( 0 )
    	, population( 0 ), max_population( 0 )
        , tax_rate( 0 )
        , auto_operations( 0 )
        , tax_admin_object_id( 0 ), city_hall_object_id( 0 )
#elif defined SQC_FARM_GAME
#endif
    {
    }
    
    int					level;
    int					coins;
    int					bucks;
    int					experience, max_experience, min_experience;
    int                 league_number;
    int                 league_level;
#if defined SQC_CITY_GAME
    int					water, max_water;
    int					power, max_power;
    int					population, max_population;
    sqc_int				tax_admin_object_id;	// if is equal to zero object isn't exist on the field
    sqc_int				city_hall_object_id;	// if is equal to zero object isn't exist on the field
    int					tax_rate;
    int					auto_operations;
#elif defined SQC_FARM_GAME
#endif

};


//
//	shop actions
//
enum sqc_shop_action {
	shop_action_buy,
	shop_action_gift,
	shop_action_sell,
	shop_action_ask,
	shop_action_receive,
    shop_action_countof,
};

inline
sqc_string print_shop_action( sqc_shop_action action ) {
    if ( shop_action_buy == action )			return "buy";
    else if ( shop_action_gift == action )		return "gift";
    else if ( shop_action_sell == action )		return "sell";
    else if ( shop_action_ask == action )		return "ask";
    else if ( shop_action_receive == action )	return "receive";
	return "unknown_action";
}

//
//	shop errors
//
enum sqc_shop_error_value {
	shop_result_success,
    shop_result_need_more_level,
    shop_result_need_more_coins,
    shop_result_need_more_gold,
    shop_result_need_more_invitees,
    shop_result_need_more_width,
    shop_result_current_width_is_larger_than_new_one,
};

typedef unsigned sqc_shop_error;

inline bool is_success_shop_action( sqc_shop_error error ) {
	return ( shop_result_success == error );
}

// quantity by type_name
typedef std::map<sqc_string, int>	sqc_quantity_by_name_map;
// quantity by type_id ( key=type_id, value=quantity)
typedef std::map<sqc_int, sqc_int>		sqc_quantity_by_id_map;

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
class sqc_locale_parser;
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION

#ifdef SQC_ENABLE_OBJECTS
class sqc_coord_convertor;

class sqc_game_object;
typedef shared_ptr2<sqc_game_object>    sqc_game_object_ptr;
typedef std::list<sqc_game_object_ptr>  sqc_game_object_list;

typedef sqc_game_object_ptr SQC_CLASS_FACTORY_RESULT;
#define SQC_CLASS_FACTORY_RESULT_NULL       sqc_game_object_ptr()

#else

#ifdef HIDE_OBJECTIVE_C_KEYWORDS

#define SQC_CLASS_FACTORY_RESULT        void*
#define SQC_CLASS_FACTORY_RESULT_NULL   NULL

#else

#define SQC_CLASS_FACTORY_RESULT        id
#define SQC_CLASS_FACTORY_RESULT_NULL   nil

#endif // INCLUDED_FROM_CPP

#endif //SQC_ENABLE_OBJECTS

END_NAMESPACE_SQC




NAMESPACE_SQC_INFO 



enum sqc_drawing_type {
    drawing_type_basic = 0,
    
    drawing_type_city_complex_object = 1000,
};


//
// drawing information
//

class sqc_drawing {
public:
    sqc_drawing() 
        : zorder_correction( 0 )
        , popup_offset_correction_x( 0.0f )
        , popup_offset_correction_y( 0.0f )
        , duplicate_texture ( false )
    {
        
    }
    virtual ~sqc_drawing()  {}
    
    void set_custom_image( sqc_string const &n ) {
        custom_image = n;
    }
    
    void set_duplicate_texture_params( float step_x, float step_y ) {
        duplicate_texture_step_x = step_x;
        duplicate_texture_step_y = step_y;
        duplicate_texture = true;
    }
    
    bool get_duplicate_texture() const {
        return duplicate_texture;
    }
    
    float get_duplicate_texture_step_x() const {
        return duplicate_texture_step_x;
    }

    float get_duplicate_texture_step_y() const {
        return duplicate_texture_step_y;
    }
    
    void set_popup_offset_correction( float x, float y ) {
        popup_offset_correction_x = x;
        popup_offset_correction_y = y;
    }

    float get_popup_offset_correction_x() {
        return popup_offset_correction_x;
    }

    float get_popup_offset_correction_y() {
        return popup_offset_correction_y;
    }
    
    sqc_string const &get_custom_image() const {
        return custom_image;
    }
    void set_zorder_correction( int val ) {
        zorder_correction = val;
    }
    std::map<sqc_string,sqc_string> get_extra_objects() const
    {
        return extra_objects;
    }
    bool set_extra_object(sqc_string key,sqc_string value)
    {
        std::cout<<"Add: "<< value.c_str() << " for key: " << key.c_str()<< std::endl;
        extra_objects[key] = value;
        
        return true;
    }

    int get_zorder_correction() const {
        return zorder_correction;
    }

    virtual sqc_drawing_type get_type() const {
        return drawing_type_basic;
    }
private:
    sqc_string  custom_image;
    int         zorder_correction;
    float       popup_offset_correction_x;
    float       popup_offset_correction_y;
    bool        duplicate_texture;
    float       duplicate_texture_step_x;
    float       duplicate_texture_step_y;
    std::map<sqc_string,sqc_string> extra_objects;
};

typedef shared_ptr2<sqc_drawing>   sqc_drawing_ptr;
typedef std::map<sqc_string, sqc_drawing_ptr>   sqc_drawing_map;

class sqc_drawing_provider {
public:
	virtual ~sqc_drawing_provider() {}

    virtual void load( yaml::sqc_yaml_node_ptr node ) {
    }
    
    sqc_drawing_ptr lookup( sqc_string const &type_name ) {
        sqc_drawing_map::const_iterator i = drawings.find( type_name );
        if( i == drawings.end() ) {
            return sqc_drawing_ptr();
        }
        return i->second;
    }
    
    sqc_drawing_map drawings;
};

typedef shared_ptr2<sqc_drawing_provider> sqc_drawing_provider_ptr;

class sqc_version_provider {
    typedef std::map<sqc_string, int> sqc_version_map;
public:
    sqc_version_provider() {}
    
    virtual void load( yaml::sqc_yaml_node_ptr node ) {
        sqc_version_map entries;
        yaml::get_yaml_vals( node, "supported_versions", entries );
        
        for( sqc_version_map::const_iterator i = entries.begin(); i != entries.end(); ++i ) {
            versions[i->first] = i->second;
        }
    }
    
    virtual bool is_class_supported(sqc_string class_name) {
        sqc_version_map::const_iterator it = versions.find(class_name);
        if (it == versions.end()) {
            return true;
        }
        
        return it->second <= BUILD_VERSION;
    }
    
protected:    
    sqc_version_map versions;
};

typedef shared_ptr2<sqc_version_provider> sqc_version_provider_ptr;


//
// object information
//

class sqc_object_info : public std::tr1::enable_shared_from_this<sqc_object_info> {
public:
    sqc_object_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	virtual ~sqc_object_info() {}

#if defined SQC_CONFIGURATOR
	virtual bool is_equal_to( const sqc_object_info &other );
    virtual void load( yaml::sqc_yaml_node_ptr node );
	virtual bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    virtual bool read_from( named_storing::storage_access *named_section );    

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    
    enum {class_object_type = type_unknown};
    virtual sqc_object_type get_type() const {
        return (sqc_object_type)class_object_type;
    }
    
    int get_type_id() const {
        return type_id;
    }
    
    int get_level() const {
        return level;
    }
    
    int get_cost_buy_game() const {
        return cost_buy_game;
    }
    
    int get_cost_sell_game() const {
        return cost_sell_game;
    }
    
    int get_cost_buy_real() const {
        return cost_buy_real;
    }
    
    int get_cost_buy_real( int level ) const;
    
    sqc_string const &get_image_path() const {
        if( drawing ) {
            if( !drawing->get_custom_image().empty() ) {
                return drawing->get_custom_image();
            }
        }
        assert( !image_path.empty() );
        return image_path;
    }
    
    virtual sqc_string get_shop_image_path() const {
	    return get_image_path();
    }
    
    sqc_string const &get_description() const {
        return description;
    }
    
    void set_description(sqc_string const &desc) {
        description = desc;
    }
    
    sqc_string const &get_description_text() const {
        return description_text;
    }

	
#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
	void set_description_text( const sqc_string &p_description_text ) {
		description_text = p_description_text;
	}
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
    
    sqc_string const &get_shop_department() const {
        return shop_department;
    }
    
    bool get_multi_buy() const {
        return multi_buy;
    }
    
    bool get_shoppable() const {
        return shoppable;
    }
    
    bool get_create() const {
        return create;
    }
    
    void set_create(bool c) {
        create = c;
    }
    
    bool get_pseudo_item() const {
        return pseudo_item;
    }
    
    bool get_new() const {
        return is_new;
    }
    
    bool get_can_be_rotate() const {
        return can_be_rotate;
    }
    
    bool get_sell() const {
        return sell;
    }
    
    bool get_build_site() const {
        //printf("%d", build_site);
        return build_site;
    }
    
    bool get_buy_as_gift() const {
        return buy_as_gift;
    }
    
    bool const get_can_ask() const {
        //return can_ask;
        return true;
    }
    
    bool get_move() const {
        return move;
    }
    
    bool get_apply() const {
        return apply;
    }
    
    int get_build_length() const {
        return build_length;
    }
    
    int get_width() const {
        return width;
    }
    
    int get_height() const {
        return height;
    }
    
    int get_out_of_bounds() const {
        return out_of_bounds;
    }       
    
    sqc_string const &get_type_name() const {
        return object_type_name;
    }

    const sqc_string &get_superclass_name() const {
        return _superclass_name;
    }

    sqc_string const &get_sqc_type_name() const {
        return object_sqc_type_name;
    }
    
    void set_sqc_type_name(sqc_string const &name) {
        object_sqc_type_name = name;
    }
    
    std::map<sqc_string, sqc_string>  const &get_upgrade_modify() const {
        return upgrade_info;
    }
    
    sqc_drawing* get_drawing() const {
        if( !drawing ) {
            return 0;
        }
        return drawing.get();
    }
    
    
    virtual sqc_shop_error preprocess_shop_action( 
    	const sqc_shop_action shop_action, 
        const sqc_common_scene_info& scene_info ) const;

	/// Get total material quantity requirement for object
    virtual sqc_quantity_by_name_map const &get_materials_quantity() const {
        static sqc_quantity_by_name_map    empty;
        return empty;
    }
    
    bool get_tutorial_pay_attention() const {
        return tutorial_pay_attention;
    }
    
    bool get_shoppable_tutorial() const {
        return shoppable_tutorial;
    }
    
    sqc_string  object_sqc_type_name;
    
private:    
    int type_id;
    int level;
    int cost_buy_game;
    int cost_sell_game;
    int cost_buy_real;
    
    sqc_string  image_path;
    sqc_string  description;
    sqc_string  description_text;
    sqc_string  shop_department;
    
    bool    multi_buy;
    bool    shoppable;
    bool    create;
    bool    apply;
    bool    move;
    bool    pseudo_item;
    bool    is_new; //new
    bool    can_be_rotate;
    bool    sell;
    bool    build_site;
    bool    buy_as_gift;
    bool    can_ask;
    int     build_length;
    int     width;
    int     height;
	
	bool	out_of_bounds;
    
    bool    tutorial_pay_attention;
    bool    shoppable_tutorial;
    


    // other
    sqc_string  object_type_name;
    sqc_string _superclass_name;
    std::map<int, int>  cost_buy_real_by_level;
    std::map<sqc_string, sqc_string>    upgrade_info;
    
    sqc_drawing_ptr drawing;
};


template <class T> inline
const T   *info_cast( const sqc_object_info *from ) {
    int val = T::class_object_type;
    
    if( (val & from->get_type()) != val ) {
        return 0;
    }
    return (T*) from;
}

template <class T> inline
T   *info_cast( sqc_object_info *from ) {
    int val = T::class_object_type;
    
    if( (val & from->get_type()) != val ) {
        return 0;
    }
    return (T*) from;
}


typedef sqc_object_info* (*sqc_create_proc)( sqc_string const &class_name, const sqc_string &superclass_name, sqc_drawing_ptr drawing );

class sqc_class_entry {
public:
    sqc_class_entry( sqc_string const &n, sqc_create_proc p ) 
        : class_name( n )
        , create_proc( p ) 
    {
    }
    
    const sqc_string get_name() const {
        return class_name;
    }
    
    sqc_object_info_ptr create_instance( sqc_string const &cls, const sqc_string &superclass_name, sqc_drawing_ptr drawing ) {
        if( !create_proc ) {
            return sqc_object_info_ptr();
        }
        assert( create_proc );
        return sqc_object_info_ptr( create_proc( cls, superclass_name, drawing ) );
    }
private:
    sqc_string          class_name;
    sqc_create_proc     create_proc;
};

typedef shared_ptr2<sqc_class_entry>    sqc_class_entry_ptr;



class sqc_class_factory {
public:    
    sqc_class_factory() {
        class_factory_map["base"] = sqc_class_entry_ptr( new sqc_class_entry( "object_base", create_instance<sqc_object_info> ) );
        class_factory_map["surrogate"] = sqc_class_entry_ptr( new sqc_class_entry( "object_base", 0 ) );
    }
    
    void load( yaml::sqc_yaml_node_ptr node ) {
        for( sqc_class_map::const_iterator i = class_factory_map.begin(); i != class_factory_map.end(); ++i ) {
            class_map[i->first] = i->second;
        }
        
        for( yaml::sqc_yaml_node_iterator i = node->begin(); i != node->end(); ++i ) {
            std::string class_name = i->first;
            yaml::sqc_yaml_node_ptr vals = i->second;
            
            sqc_class_entry_ptr entry;
            {
                sqc_class_map::const_iterator ii = class_factory_map.find( class_name );
                if( ii == class_factory_map.end() ) {
                    std::cerr << "class factory loader: unknown class \"" << class_name << "\"" << std::endl;
                    continue;
                }
                entry = ii->second;
            }

            
            size_t  class_count = vals->size();
            for( size_t n = 0; n != class_count; ++n ) {
                const char *raw = vals->get_child( n )->get_value_raw();
                if( raw ) {
                    class_map[raw] = entry;
                }
            }
        }
    }
    
    sqc_class_entry_ptr get_base_class( sqc_string const &derived_class ) const {
        sqc_class_map::const_iterator i = class_map.find( derived_class );
        if( i != class_map.end() ) {
            return i->second;
        }
        return sqc_class_entry_ptr();
    }
    
    std::string dump() const {
        std::stringstream out;
        out << "---base classes" << std::endl;
        for( sqc_class_map::const_iterator i = class_factory_map.begin(); i != class_factory_map.end(); ++i ) {
            out << " - " << i->first << std::endl;
        }
        
        out << "---derived classes" << std::endl;
        for( sqc_class_map::const_iterator i = class_map.begin(); i != class_map.end(); ++i ) {
            out << " - " << i->first << " <- " << i->second->get_name() << std::endl;
        }
        
        out << "---" << std::endl;
        
        return out.str();
    }
protected:    
    template <class T> static sqc_object_info *create_instance( sqc_string const &n, const sqc_string &superclass_name, sqc_drawing_ptr d ) {
        return new T( n, superclass_name, d );
    }
    
    typedef std::map<sqc_string, sqc_class_entry_ptr>    sqc_class_map;    
    sqc_class_map   class_map, class_factory_map;
};


typedef shared_ptr2<sqc_class_factory> sqc_class_factory_ptr;
typedef std::map<const char *, sqc_object_info_ptr, cmp_psz>   sqc_object_info_map;
typedef std::map<int, sqc_object_info_ptr>   sqc_object_info_by_id_map;


class sqc_object_info_provider {
public:
	
	/// Method load and instance objects

#if defined SQC_CONFIGURATOR
	#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
		void load( yaml::sqc_yaml_node_ptr node, sqc_class_factory_ptr factory, sqc_drawing_provider_ptr drawing_provider, sqc_locale_parser &locale_parser );
	#else // SQC_ENABLE_EXTERNAL_LOCALIZATION	
		void load( yaml::sqc_yaml_node_ptr node, sqc_class_factory_ptr factory, sqc_drawing_provider_ptr drawing_provider );
	#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
#endif // #if defined SQC_CONFIGURATOR

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
	bool read_from( named_storing::storage_container &named_storage, 
                   sqc_class_factory_ptr factory, 
                   sqc_drawing_provider_ptr drawing_provider, 
                   sqc_locale_parser &locale_parser, 
                   sqc_version_provider_ptr version_provider);
#else // #ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
	bool read_from( named_storing::storage_container &named_storage, 
                   sqc_class_factory_ptr factory, 
                   sqc_drawing_provider_ptr drawing_provider, 
                   sqc_version_provider_ptr version_provider );
#endif // #ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION


    
	
    sqc_object_info * get_object_info( const char *type_name ) const;
    sqc_object_info * get_object_info( int class_id ) const;
    SQC_CLASS_FACTORY_RESULT create_instance( const char *class_name ) const;
    SQC_CLASS_FACTORY_RESULT create_instance( int class_id ) const;

    /// Method returns list of loading objects names
    const sqc_string_list& get_object_names();
private:
    sqc_object_info_map         classes;
    sqc_object_info_by_id_map   classes_by_id;
    sqc_string_list             m_objectNames;
};

typedef shared_ptr2<sqc_object_info_provider> sqc_object_info_provider_ptr;

END_NAMESPACE_SQC_INFO

#ifdef SQC_ENABLE_OBJECTS

NAMESPACE_SQC

struct sqc_texture_info {
public:
    explicit sqc_texture_info( sqc_string const &n, bool o, bool a, bool r ) 
        : name( n )
        , need_anchor( o ) 
        , is_animation( a )
        , rotated( r )
    {
        
    }
    sqc_string  name;
    bool        is_animation;
    bool        need_anchor;
    bool        rotated;
};

typedef std::list<sqc_texture_info> sqc_texture_info_list;

#ifndef SQC_OBJECT_DISABLE_DRAWING
/// coord spaces
/**
 * for now we have 3 coord spaces
 * 1) game space
 *    sqc_point - cell units
 * 2) field draw space
 *    surf_point - field without zomm
 * 3) screen space
 *    surf_point - field with zoom
 */
enum sqc_coord_convert_mode {
	/// draw space with scroll ( no zoom )
	sqc_coord_convert_mode_draw,
	/// draw space without scroll ( no zoom )
	sqc_coord_convert_mode_draw_no_scroll,
	/// real screen space with scroll ( zoom applied )
	sqc_coord_convert_mode_select,
	/// real screen space without scroll ( zoom applied )
	sqc_coord_convert_mode_select_no_scroll
};
class sqc_coord_convertor {
public:
	/// current field zoom
    virtual surf::surf_val      get_zoom() const = 0;
	/// screen size
	/// @arg with_zoom if true return zoomed screen size ( field draw space )
    virtual surf::surf_nsize    get_screen_size(bool with_zoom=true) const = 0;
	/// convert game coords ( cells ) to screen or field coords
    /**
     * @arg p game cell coord
     * @arg mode conver mode
     * @arg center if true return coordinates center of cell, default left corner
     */
    virtual surf::surf_point    field_to_screen( sqc_point const &p, sqc_coord_convert_mode mode=sqc_coord_convert_mode_draw , bool center=false) const = 0;
	/// convert real screen coords to game coords ( cell )
    virtual sqc_point           screen_to_field( surf::surf_point const &pt, bool strong = true ) const = 0;
	/// cell size in field space ( not zoomed )
    virtual surf::surf_size     get_cell_size() const = 0;
};
#endif //#ifndef SQC_OBJECT_DISABLE_DRAWING


enum sqc_action {
    action_nop,
    action_tick,
    action_pick,
    action_clean,
    action_load,
    action_cancel,
    action_move,
    action_build,
    action_choose_material,
    action_purchase_building_site,
    action_put,
    action_choose_seed,
    action_move_to_pen,
    action_choose_animal,
    action_switch_input     /// change using resource (multifactory)
};

enum sqc_country_owner {
	sqc_country_owner_me,
	sqc_country_owner_friend
};

enum sqc_object_state {
    object_state_undefined = 0,
    object_state_building,
    object_state_standby,
    object_state_working,
    object_state_abandoned,
    object_state_dirty,
    object_state_expired,
    object_state_progress,
    object_state_queued,
	object_state_wait_update
};

namespace framework {
	struct sqc_bubble_content;
}


#ifndef SQC_OBJECT_DISABLE_DRAWING
struct sqc_tooltip_data {
	sqc_string	text;
	surf::surf_color	color;
	sqc_string	icon;
	sqc_tooltip_data( const sqc_string& text, const surf::surf_color& clr ) : text(text),color(clr) {
	}
};

typedef std::vector<sqc_tooltip_data> sqc_tooltips_data;
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING


struct sqc_game_object_draw_args {
    enum draw_object_mode {
        static_texture,
        animation_no_ff,
        animation_all
    } mode;
	bool	tooltip;
};
static const sqc_game_object_draw_args sqc_game_object_default_draw_arg = { sqc_game_object_draw_args::animation_all,true };

class sqc_automation {
public:
	virtual bool automate( sqc_action action, int auto_points ) = 0;
};

typedef std::tr1::shared_ptr<sqc_automation>	sqc_automation_ptr;


class sqc_game_object {
public:
    sqc_game_object( info::sqc_object_info_ptr oi ) 
        : object_info( oi )
        , object_id( -1 )
        , orientation( false )
        , process_end( -1 )
        , object_state( object_state_undefined )
        , progress_interval( 0 )
        , c_progress_offset( 11 )
        , c_progress_step_width( 5 )
        , c_max_progress( 6 )
    {
    }

    virtual ~sqc_game_object() {
    }
    
    //
    // tempo
    //
    virtual bool is_road() const {
        return false;
    }
    virtual bool is_city_object() const {
        return false;
    }
    
    virtual sqc_action get_default_action() const {
        return action_nop;
    }
    virtual bool is_single_click_action( sqc_action action ) {
        return false;
    }
    virtual sqc_action get_auto_action() const {
        return action_nop;
    }
    int const get_type_id() const {
        if( object_info ) {
            return object_info->get_type_id();
        }
        return 0;
    }
    
    int get_id() const {
        return object_id;
    }
    
    sqc_string const get_type() const {
        if( object_info ) {
            return object_info->get_type_name();
        }
        return sqc_string();
    }
 	
    sqc_point get_position() const {
        return position;
    }
    
    void set_position( sqc_point const &p ) {
        position = p;
    }
    
    bool get_orientation() const {
        return orientation;
    }
    
    void set_orientation( bool f ) {
        orientation = f;
    }
    
    int get_process_end() const {
        return process_end;
    }
    
   
    sqc_object_state get_object_state() const {
        return object_state;
    }
    
    void set_object_state( sqc_object_state state ){
        object_state = state;
    }
    
    void set_progress_delay( int delay ){
        progress_interval = delay * 1000 / c_max_progress;
    }
   
/*    virtual int get_process_end() {
        return process_end;
    }
*/
    sqc_string_map get_input_fill() const {
        return input_fill;
    }

    sqc_string_map & set_input_fill() {
        return input_fill;
    }
    
    // available
    virtual sqc_quantity_by_name_map const &get_materials_quantity() const {
        return material_quantity;
    }
    
    virtual sqc_size get_size() const;

#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual bool parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
  
    virtual void handle_timer();

#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual void reload_textures();
    virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

    virtual void enumerate_textures( sqc_texture_info_list &result );

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
    
    info::sqc_object_info_ptr get_object_info() const {
        return object_info;
    }

#ifndef SQC_OBJECT_DISABLE_DRAWING
	const sqc_tooltips_data& get_tooltips() const { 
		return tooltips;
	}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
	
#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual void render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg = sqc_game_object_default_draw_arg );
	/// return display rect in non zoomed coordinates
    virtual surf::surf_rect get_display_rect( sqc_coord_convertor &coord_conv, bool apply_scrooll = true );
    virtual bool check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv );

#endif 
    
protected:
    
	sqc_string_map		input_fill;
    info::sqc_object_info_ptr object_info;
    int             	object_id;
    sqc_point       	position;
    bool            	orientation;
    int             	process_end;
    sqc_object_state        object_state;
    sqc_ddword              progress_interval;
    const float             c_progress_offset;
    const float             c_progress_step_width;
    const int               c_max_progress;

    sqc_quantity_by_name_map	material_quantity;

#ifndef SQC_OBJECT_DISABLE_DRAWING
	sqc_tooltips_data		tooltips;
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
};

END_NAMESPACE_SQC
#endif //SQC_ENABLE_OBJECTS
