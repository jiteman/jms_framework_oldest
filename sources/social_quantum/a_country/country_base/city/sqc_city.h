#pragma once

#include "../../sqc/sqc_base.h"

//#if !defined ( SQC_NEW_TRACK_API ) && !defined ( HIDE_OBJECTIVE_C_KEYWORDS )
//#include "TrackAPI.h"
//#else // #if !defined ( SQC_NEW_TRACK_API ) && !defined ( HIDE_OBJECTIVE_C_KEYWORDS )

NAMESPACE_SQC

enum TrafficItemCategory {
    itemCategoryCommon,
    itemCategoryPolicy,
    itemCategoryFire,
    itemCategoryMilitary,
};

END_NAMESPACE_SQC

//#endif // #if !defined ( SQC_NEW_TRACK_API ) && !defined ( HIDE_OBJECTIVE_C_KEYWORDS )



#define NAMESPACE_SQC_CITY  namespace sqc { namespace city {
#define END_NAMESPACE_SQC_CITY }}



NAMESPACE_SQC_CITY
    
enum sqc_city_shop_error_value {
    city_shop_result_need_more_water = 1000,
    city_shop_result_need_more_power,
    city_shop_result_need_more_population,
    city_shop_result_not_necessary_material,
    city_shop_result_need_city_hall_present,
    city_shop_result_need_tax_office_present,
    city_shop_result_no_buildsite_to_apply_to,
    city_shop_result_need_sport_complex,
    city_shop_result_need_2nd_field,
    city_shop_result_need_warehouse,
};

END_NAMESPACE_SQC_CITY



NAMESPACE_SQC_INFO 

class sqc_city_object_info : public sqc_object_info {
public:
    enum ExtraParamsType
    {
        NONE = 0,
        NORMAL,
        EXTERNAL,
        INTERNAL,
        REQUIRED,
    };
public:
    sqc_city_object_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

    // virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );

    //~virtuals sqc_object_info
    virtual SQC_CLASS_FACTORY_RESULT create_instance();

    int get_water_consume() const {
        return water_consume;
    }
    
    int get_water_produce() const {
        return water_produce;
    }
    
    int get_power_consume() const {
        return power_consume;
    }
    
    int get_power_produce() const {
        return power_produce;
    }
    
    int get_sort_order() const {
        return sort_order;
    }
    int get_extra_exp() const {
        return extra_exp;
    }
    int get_extra_coins() const {
        return extra_coins;
    }
    int get_cost_invites() const {
        return cost_invites;
    }
    int get_required_width() const {
        return required_width;
    }    
    int get_max_width() const {
        return max_width;
    }    
    int get_stage_length() const {
        return stage_length;
    }    
    int get_abandoned_length() const {
        return abandoned_length;
    }    
    int get_population_increase() const {
        return population_increase;
    }    
    int get_max_population_increase() const {
        return max_population_increase;
    }    
    int get_exp() const {
        return exp;
    }    
    bool get_delayed_animations() const {
        return delayed_animations;
    }
    bool get_shed() const {
        return shed;
    }

    virtual std::vector<sqc_string_map> const &get_extra_params() const {
        return extra_params;
    }
    
    virtual std::vector<sqc_string> const &get_items_require() const {
        return items_require;
    }
    
    bool get_fixed_position() const {
        return fixed_position;
    }
    
    int get_cost_sell_game() const {
        return cost_sell_game;
    }
    
    sqc_string const &get_field_key() const {
        return field_key;
    }
    
    std::vector<sqc_string> const &get_quest_tags() const{        
        return quest_tags;
    }

	ExtraParamsType get_extra_params_type() const
    {
        return extra_type;
    }
    
    const std::vector<sqc_string>& get_contract_require() const
    {
        return contract_require;
    }
    
    const sqc_string& get_super_class() const
    {
        return super_class;
    }
    
    const sqc_string& get_single_object() const
    {
        return single_object;
    }

    const sqc_string& get_parent_super_class() const
    {
        return parent_super_class;
    }
    
    bool get_dont_expires() const {
        return dont_expires;
    }


    virtual sqc_string get_shop_image_path() const {
        
        // !!!
        // !!! hack! for materials, factories and SQ-city
        // !!!
        sqc_string shop_department = get_shop_department();
        int tid = get_type_id();
        
        if (shop_department == "materials") {
            return get_image_path();
        }
        if (shop_department == "city_factories" && tid!= 10439 && tid != 10440) {
            return get_image_path() + sqc_text( "_v1_2" );
        }
        
        return get_image_path() + sqc_text( "_v1" );
        
        
        /*
        int tid = get_type_id();
        if( tid >= 10900 && tid < 11100 ) {
           return get_image_path();
        }
	    return get_image_path() + sqc_text( "_v1" );
         */
    }

// Eugene Saluhin: a function without definition
//     virtual sqc_shop_error preprocess_shop_action( 
//     	const sqc_shop_action shop_action, 
//         const sqc_common_scene_info& scene_info ) const;

private:    
    int water_consume;
    int water_produce;
    int power_consume;
    int power_produce;
    int sort_order;
    int extra_exp;
    int extra_coins;
    int cost_invites;
    int required_width;
    int max_width;
    int stage_length;
    int abandoned_length;
    int population_increase;
    int max_population_increase;
    int exp;
    bool delayed_animations;
    bool shed;
    bool fixed_position;
    int cost_sell_game;
    bool    dont_expires;
    sqc_string field_key;
    sqc_string super_class;
    sqc_string parent_super_class;
    sqc_string single_object;
protected:
    
#if defined SQC_CONFIGURATOR
	virtual bool are_extra_parameters_equal_to( const sqc_object_info &other );
    virtual void load_extra_params(yaml::sqc_yaml_node_ptr node);
    virtual bool write_extra_parameters_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    virtual bool read_extra_parameters_from( named_storing::storage_access *named_section );

    ExtraParamsType extra_type;
    std::vector<sqc_string_map> extra_params;
    std::vector<sqc_string>     items_require;
    std::vector<sqc_string>     quest_tags;
    std::vector<sqc_string>     contract_require;
};

class sqc_city_expand_info : public sqc_city_object_info {
public:
    sqc_city_expand_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) : sqc_city_object_info( t, superclass_name, d )
    , m_size_x(0)
	{
    }
    
    sqc_string get_shop_image_path() const {
        return get_image_path();
    }

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
	void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );
	//~virtuals sqc_object_info

    int size_x() const {
    	return m_size_x;
    }
    
    int field_no() const{
    	if (m_field_key == "size_x") {
        	return 1;
        } 
        else if (m_field_key == "size_x_2") {
        	return 2;
        }
        else {
        	return 0;
        }
    }
private:
    sqc_string m_field_key;
    int m_size_x;
};



class sqc_city_extended_contract_info : public sqc_city_object_info
{
public:
    sqc_city_extended_contract_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    
    virtual std::vector<sqc_string_map> const &get_extra_params() const {
        return extra_params;
    }
    virtual std::vector<sqc_string> const &get_items_require() const
    {
        return items_require;
    }
    virtual sqc_string get_shop_image_path() const {
	    return get_image_path();
    }

protected:
	// virtuals sqc_city_object_info
#if defined SQC_CONFIGURATOR
	virtual bool are_extra_parameters_equal_to( const sqc_object_info &other );
    virtual void load_extra_params(yaml::sqc_yaml_node_ptr node);
    virtual bool write_extra_parameters_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    virtual bool read_extra_parameters_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_city_object_info
};

class sqc_city_buildsite_factory_info : public sqc_city_object_info {
public:
    sqc_city_buildsite_factory_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    
	std::vector<sqc_string> const &get_contracts() const {
        return contracts;
    }
    
    std::vector<sqc_string> const &get_consumes() const {
        return consumes;
    }
    sqc_quantity_by_name_map const &get_materials_quantity() const {
        return materials_quantity;
    }
    
    sqc_string const &get_produce() const {
        return produce;
    }
    
    int get_position_x() const {
        return position_x;
    }
    int get_position_y() const {
        return position_y;
    }
   
private:    
    std::vector<sqc_string>     consumes;
    sqc_string                  produce;
    sqc_quantity_by_name_map   	materials_quantity;
    int position_x;
    int position_y; 

    std::vector<sqc_string> contracts;
};

class sqc_city_factory_info : public sqc_city_object_info {
public:
    sqc_city_factory_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    

	std::vector<sqc_string> const &get_contracts() const {
       return contracts;
    }
    
    bool get_bonus_factory() const {
        return bonus_factory;
    }
    
    virtual sqc_string get_shop_image_path() const {
        return sqc_city_object_info::get_shop_image_path();
    }
private:
    std::vector<sqc_string> const &get_factory_produce() const {
        return produce;
    }
    std::vector<sqc_string> produce;
    std::vector<sqc_string> contracts;
    bool            bonus_factory;
};

class sqc_city_buildingsite_info : public sqc_city_object_info {
public:
    sqc_city_buildingsite_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info
    
    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    
    std::vector<sqc_string> const &get_consumes() const {
        return consumes;
    }
    sqc_quantity_by_name_map const &get_materials_quantity() const {
        return materials_quantity;
    }
    
    sqc_string const &get_produce() const {
        return produce;
    }

    int get_position_x() const {
        return position_x;
    }
    int get_position_y() const {
        return position_y;
    }
    
private:    
    std::vector<sqc_string>     consumes;
    sqc_string                  produce;
    sqc_quantity_by_name_map   	materials_quantity;

    int position_x;
    int position_y; 
};

typedef std::tr1::shared_ptr<sqc_city_buildingsite_info> sqc_city_buildingsite_info_ptr;

class sqc_city_complex_buildsite_factory_info : public sqc_city_factory_info
{
public:
    sqc_city_complex_buildsite_factory_info(const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d);

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    std::vector<sqc_string> const &get_consumes() const 
    {
        return consumes;
    }
    sqc_quantity_by_name_map const &get_materials_quantity() const
    {
        return materials_quantity;
    }
    
    sqc_string const &get_produce() const
    {
        return produce;
    }
    
    int get_position_x() const
    {
        return position_x;
    }
    
    int get_position_y() const
    {
        return position_y;
    }
private:
    std::vector<sqc_string>     consumes;
    sqc_string                  produce;
    sqc_quantity_by_name_map   	materials_quantity;
    sqc_string                  contracts_from;
    
    int position_x;
    int position_y; 
};

class sqc_city_buildingplace_info : public sqc_city_object_info {
public:
    sqc_city_buildingplace_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d );

	// virtuals sqc_object_info
#if defined SQC_CONFIGURATOR
	bool is_equal_to( const sqc_object_info &other );
    void load( yaml::sqc_yaml_node_ptr node );
    bool write_to( named_storing::storage_access *named_section ) const;
#endif // #if defined SQC_CONFIGURATOR

    bool read_from( named_storing::storage_access *named_section );	
	//~virtuals sqc_object_info

    virtual SQC_CLASS_FACTORY_RESULT create_instance();
    
    
    int get_position_x() const {
        return position_x;
    }
    int get_position_y() const {
        return position_y;
    }
    int get_object_id() const {
        return object_id;
    }
    std::vector<sqc_string> const &get_build() const {
        return build;
    }
    std::vector<sqc_string> const &get_require() const {
        return require;
    }
    virtual bool get_auto_create() const {
        return false;
    }
private:
    std::vector<sqc_string> build;
    std::vector<sqc_string> require;
    
    int position_x;
    int position_y; 
    int object_id;
};

class sqc_city_autocreate_buildingplace_info : public sqc_city_buildingplace_info {
public:
    sqc_city_autocreate_buildingplace_info( const sqc_string &t, const sqc_string &superclass_name, sqc_drawing_ptr d ) 
    : sqc_city_buildingplace_info( t, superclass_name, d ) 
    {}
    
    virtual bool get_auto_create() const {
        return true;
    }
};

//
//
//

class sqc_city_class_factory : public sqc_class_factory {
public:
    sqc_city_class_factory();
};

//
//
//
class sqc_city_drawing : public sqc_drawing {
public:
    sqc_city_drawing() 
        : animated( false )
        , no_first_frame( false ) 
        , custom_can_rotate( false )
        , selectable_part( false )
        , traffic_category( itemCategoryCommon )
        , is_custom_shop_enabled( false )
        , shop_dep( "none" )
        , custom_build_icon ( "none" )
        , animated_stages_defined( false )
        , road_links_enabled( false )
    {
    }
    
    void set_custom_build_icon( sqc_string img )
    {
        custom_build_icon = img;
    }
    
    sqc_string get_custom_build_icon()
    {
        return custom_build_icon;
    }
    
    void set_traffic_category( TrafficItemCategory a ) {
        traffic_category = a;
    }
    
    TrafficItemCategory get_traffic_category() const {
        return traffic_category;
    }
    
    void set_shop_dep( sqc_string dep ) {
        shop_dep = dep;
    }
    sqc_string get_shop_dep() const {
        return shop_dep;
    }
    
    void set_custom_shop_enabled( bool flag ) {
        is_custom_shop_enabled = flag;
    }
    bool get_custom_shop_enabled() {
        return is_custom_shop_enabled;
    }
    void set_animated( bool flag ) {
        animated = flag;
    }
    void set_custom_can_rotate(bool flag)
    {
        custom_can_rotate = flag;
    }
    void set_no_first_frame( bool flag ) {
        no_first_frame = flag;
    }
    void set_selectable_part( bool flag ) {
        selectable_part = flag;
    }
    
    bool get_animated() const {
        return animated;
    }
    bool get_no_first_frame() const {
        return no_first_frame;
    }
    bool get_custom_can_rotate() const
    {
        return custom_can_rotate;
    }
    bool get_selectable_part() const {
        return selectable_part;
    }
    
    bool is_animated_stage( sqc_string const &stage ) const {
        if( !animated ) {
            return false;
        }
        if( !animated_stages_defined ) {
            return true;
        }
        return animated_stages.find( stage ) != animated_stages.end();
    }
    template <class T>
    void set_animated_stages( T b, T e ) {
        animated_stages.clear();
        animated_stages_defined = true;
        for( T i = b; i != e; ++i ) {
            animated_stages.insert( *i );
        }
    }
    bool has_road_links() {
        return road_links_enabled;
    }
    
    template <class T> 
    void set_railroad_objects( T b, T e ) {
        railroad_objects.clear();
        for( T i = b; i != e; ++i ) {
            railroad_objects.push_back( *i );
        }
    }
    
    std::vector<sqc_string> const &get_railroad_objects() const {
        return railroad_objects;
    }
    
    template <class T> 
    void set_relations( T b, T e ) {
        relations.clear();
        for( T i = b; i != e; ++i ) {
            relations.push_back( *i );
        }
    }
    
    std::vector<sqc_string> const &get_relations() const {
        return relations;
    }
    
    template <class T>
    void set_road_links( T b, T e ) {
        road_links.clear();
        for( T i = b; i != e; ++i ) {
            road_links_enabled = true;
            road_links.push_back( *i );
        }
    }
    
    std::vector< std::map< sqc_string, int> > const &get_road_links() const {
        return road_links;
    }
    
private:
    bool    animated;
    bool    no_first_frame;
    bool    custom_can_rotate;
    bool    selectable_part;
    
    TrafficItemCategory    traffic_category;
    
    sqc_string shop_dep;
    bool is_custom_shop_enabled;
    
    sqc_string custom_build_icon;
    
    std::set<sqc_string>  animated_stages;
    bool    animated_stages_defined;
    bool    one_animation_for_totation;      
    bool    road_links_enabled;
    std::vector< std::map< sqc_string, int> > road_links;
    std::vector<sqc_string> railroad_objects;
    std::vector<sqc_string> relations;
};

typedef shared_ptr2<sqc_city_drawing> sqc_city_drawing_ptr;

class sqc_complex_object_draw_entry {
public:
    sqc_complex_object_draw_entry( const sqc_string &s );
    void load( yaml::sqc_yaml_node_ptr node );
    
    std::vector<sqc_string> const &get_image_names() const {
        return image_names;
    }
    
    std::vector<sqc_string> const &get_requested_materials() const {
        return requested_materials;
    }
    
    std::vector<int> const &get_animated_stages() const {
        return animated_stages;
    }
    
    
    std::vector<sqc_string> const &get_custom_animatios() const {
        return custom_animatios;
    } 
    bool is_stage_animated(int stage) {
        for( std::vector<int>::const_iterator i = animated_stages.begin(); i != animated_stages.end(); ++i ) {
            if( *i == stage )
                return true;
        }
        return false;
    }

    sqc_string const &get_caption() const {
        return caption;
    }
    
    float get_popup_offset_correction_x() {
        return popup_offset_correction_x;
    }
    
    float get_popup_offset_correction_y() {
        return popup_offset_correction_y;
    }
    
    bool is_factory()
    {
        return factory;
    }
    
    const std::string&  get_popup_object()
    {
        return popup_object;
    }

    bool is_build_object()
    {
        return build_object;
    }
    bool is_rotated_object()
    {
        return rotated;
    }
    bool draw_forest ()
    {
        return draw_all_forest;
    }
    const sqc_string_map& get_popup_actions()
    {
        return popup_actions;
    }
    
    const sqc_string& get_shop_department()
    {
        return shop_department;
    }
    const sqc_string& get_custom_texture_counter()
    {
        return custom_texture_counter;
    }    
private:
    sqc_string caption;
    std::string popup_object;
    std::vector<sqc_string> image_names;
    std::vector<sqc_string> requested_materials;
    std::vector<int> animated_stages;
    std::vector<sqc_string> custom_animatios;
    sqc_string_map  popup_actions;
    sqc_string      shop_department;
    sqc_string      custom_texture_counter;
    float popup_offset_correction_x;
    float popup_offset_correction_y;
    bool factory;
    bool build_object;
    bool rotated;
    bool draw_all_forest;
};

typedef shared_ptr2<sqc_complex_object_draw_entry> sqc_complex_object_draw_entry_ptr;
typedef std::list<sqc_complex_object_draw_entry_ptr> sqc_complex_object_draw_entry_list;

class sqc_complex_object_drawing : public sqc_city_drawing {
public:
    void load( yaml::sqc_yaml_node_ptr node );
    sqc_complex_object_draw_entry_list const &get_entries() const {
        return entries;
    }

    sqc_drawing_type get_type() const {
        return drawing_type_city_complex_object;
    }

    const sqc_string& get_main_caption() {
        return main_caption;
    }
    
private:    
    sqc_complex_object_draw_entry_list entries;
    sqc_string main_caption;
};


class sqc_city_drawing_provider : public sqc_drawing_provider {
public:
    virtual void load( yaml::sqc_yaml_node_ptr node );
    sqc_city_drawing_ptr lookup_and_allocate( sqc_string const &type_name );
    
    
};

END_NAMESPACE_SQC_INFO
