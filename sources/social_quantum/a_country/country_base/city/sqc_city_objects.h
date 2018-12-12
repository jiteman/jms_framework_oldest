#ifndef __SQC_CITY_OBJECTS_INCLUDED
#define __SQC_CITY_OBJECTS_INCLUDED

#include "sqc_city.h"

#ifdef SQC_ENABLE_OBJECTS

#ifndef SQC_OBJECT_DISABLE_DRAWING
#include "city/city_framework.h"
//#include "framework/texture/sqc_texture_builder.h"
//#include "framework/animator/sqc_animator.h"

using namespace sqc::framework;
#endif //SQC_OBJECT_DISABLE_DRAWING


NAMESPACE_SQC_CITY

using namespace info;

class sqc_city_object_base : public sqc_game_object {
public:
    sqc_city_object_base( sqc_object_info_ptr i ) 
        : sqc_game_object( i )    
    {
    }
    
    virtual bool is_city_object() const {
        return true;
    }
    
#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
    
    sqc_string get_image_path() const;
    sqc_string get_type_name() const;
    
    virtual void enumerate_textures( sqc_texture_info_list &result );
    bool enumerate_complex_object_textures( sqc_texture_info_list &result );
    
    virtual void put_road( std::vector<sqc_byte> &field, sqc_rect const &rect_field ) {
    }

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
    
protected:
};

typedef std::tr1::shared_ptr<sqc_city_object_base> sqc_city_object_base_ptr;

struct texture_list_entry_t {
	texture_list_entry_t()
    {}
    
    texture_list_entry_t( sqc_texture_ptr p_object_texture,
                          sqc_texture_ptr p_object_texture_no_ff,
                          sqc_texture_ptr p_object_animation )

    :	object_texture(p_object_texture),
        object_texture_no_ff(p_object_texture_no_ff),
        object_animation(p_object_animation)
    {
    }

	sqc_texture_ptr object_texture;
    sqc_texture_ptr object_texture_no_ff;
    sqc_texture_ptr object_animation;
};

typedef std::vector<texture_list_entry_t> texture_vector_t;
typedef std::map<sqc_string, texture_list_entry_t> texture_map_t;


class sqc_building_base : public sqc_city_object_base {
protected:
    sqc_building_base( sqc_object_info_ptr i ) : sqc_city_object_base( i )
        , m_current_progress( 0 )
        , m_start_progress_time( 0 )
    {
    }
    
    virtual sqc_string get_building_image_path() const;
    virtual sqc_string get_status_image_path() const;
    virtual sqc_string get_main_texture_path() const;
    
    virtual bool can_rotate();
    virtual bool has_building_stage();
    virtual void enumerate_animation_stages( sqc_string_list &result );
    virtual void enumerate_textures( sqc_texture_info_list &result );

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner);
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
	
#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual void    render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg );
	
    /// Material-based select of texture name for the entry of a list of complex objects
    virtual sqc_string select_texture_name(sqc_complex_object_draw_entry_ptr obj_drawing, bool & animation);
    
    virtual void    reload_textures();
    virtual surf::surf_rect get_display_rect( sqc_coord_convertor &coord_conv, bool apply_scroll = true );
    virtual bool check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv );
    
    bool check_point_on_texture( surf::surf_point const &click_point, sqc_coord_convertor &coord_conv, sqc_texture_ptr texture, sqc_point const &texture_offset );

    texture_vector_t   texture_vector;
	//texture_map_t		texture_map;
/*
    sqc_texture_ptr    object_texture;
    sqc_texture_ptr    object_texture_no_ff;
    sqc_texture_ptr    object_animation;
*/

    sqc_texture_ptr    object_texture_status;
    sqc_texture_ptr    object_texture_progress;

#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
  
    int         m_current_progress;
    sqc_ddword  m_start_progress_time;

};

class sqc_house_base : public sqc_building_base {
public:
    sqc_house_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
    
    virtual sqc_string get_status_image_path() const;
    virtual sqc_action get_default_action() const;
    virtual bool is_single_click_action( sqc_action action );
    
    virtual void enumerate_animation_stages( sqc_string_list &result );

    virtual sqc_action get_auto_action() const;

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner);
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
};

class sqc_leisure_base : public sqc_building_base {
public:
    sqc_leisure_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
    
    virtual sqc_string get_status_image_path() const;
    virtual sqc_action get_default_action() const;
    virtual bool is_single_click_action( sqc_action action );
    
    virtual void enumerate_animation_stages( sqc_string_list &result );
    
    virtual sqc_action get_auto_action() const;


#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner);
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
};

class sqc_terrain_base : public sqc_building_base {
public:
    sqc_terrain_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
    
    virtual void enumerate_animation_stages( sqc_string_list &result );
};

class sqc_power_base : public sqc_building_base {
public:
    sqc_power_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
    
    virtual void enumerate_animation_stages( sqc_string_list &result );

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
};


class sqc_factory_base : public sqc_building_base {
public:
    sqc_factory_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
    
    virtual sqc_string get_main_texture_path() const;
    virtual sqc_string get_status_image_path() const;
    
    virtual sqc_action get_default_action() const;
    virtual bool is_single_click_action( sqc_action action );

    
    virtual void enumerate_animation_stages( sqc_string_list &result );
    virtual void enumerate_textures( sqc_texture_info_list &result );

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner);
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING
};

class sqc_buildsite_base : public sqc_building_base {
public:
    sqc_buildsite_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }

#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

    virtual sqc_action get_default_action() const;
    virtual bool is_single_click_action( sqc_action action );
    virtual bool is_buildsite_produce();
protected:
    sqc_string_vector split(const std::string& source, char delim );
};

typedef std::tr1::shared_ptr<sqc_buildsite_base> sqc_buildsite_base_ptr;

class sqc_building_place_base : public sqc_building_base {
public:
    sqc_building_place_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
        object_id = i->get_type_id();
    }
    virtual sqc_action get_default_action() const;
    virtual bool is_single_click_action( sqc_action action );
};


enum sqc_road_type {
    road_type_roadwork,
    road_type_line_left_right,
    road_type_line_top_bottom,
    road_type_turn_left_bottom,
    road_type_turn_left_top,
    road_type_turn_right_bottom,
    road_type_turn_right_top,
    road_type_3_way_crossroad_left_right_bottom,
    road_type_3_way_crossroad_left_right_top,
    road_type_3_way_crossroad_right_top_bottom,
    road_type_3_way_crossroad_left_top_bottom,
    road_type_4_way_crossroad,
    road_type_bay_right,
    road_type_bay_left,
    road_type_bay_bottom,
    road_type_bay_top,
    road_type_parking,
    road_type_crosswalk_left_right,
    road_type_crosswalk_top_bottom,
    road_type_crosswalk_left,
    road_type_crosswalk_top,
    road_type_crosswalk_right,
    road_type_crosswalk_bottom,
    
    road_type_undefined = 1000,
};


class sqc_railroad_base : public sqc_city_object_base {
public:
    sqc_railroad_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
    virtual void enumerate_textures( sqc_texture_info_list &result );
};

class sqc_road_base : public sqc_building_base {
public:
    sqc_road_base( sqc_object_info_ptr i ) : sqc_building_base( i ), road_type( road_type_undefined ) {
    }
    virtual void enumerate_textures( sqc_texture_info_list &result ) {
        result.push_back( sqc_texture_info( "road", false, false, false ) ); 
        result.push_back( sqc_texture_info( "boy", true, true, false ) ); 
        result.push_back( sqc_texture_info( "girl", true, true, false ) ); 
        result.push_back( sqc_texture_info( "man", true, true, false ) ); 
        result.push_back( sqc_texture_info( "police", true, true, false ) ); 
        result.push_back( sqc_texture_info( "woman", true, true, false ) ); 
        result.push_back( sqc_texture_info( "worker", true, true, false ) ); 
        result.push_back( sqc_texture_info( "helicopter", true, true, false ) ); 
    }
    
#ifndef SQC_OBJECT_DISABLE_DRAWING
    void    render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg );
    void    reload_textures();
    bool    check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv );
#endif
    
    virtual void put_road( std::vector<sqc_byte> &field, sqc_rect const &rect_field ) {
        int x = position.x - rect_field.x;
        int y = position.y - rect_field.y;
        
        field[x+y*rect_field.cx] = 1;
    }
    
    virtual bool is_road() const {
        return true;
    }
    
    sqc_road_type get_road_type() const {
        return road_type;
    }
    void set_road_type( sqc_road_type rt ) {
        road_type = rt;
    }
protected:
    sqc_road_type   road_type;
private:
	sqc_texture_ptr  object_texture;
};

class sqc_parking_base : public sqc_road_base {
public:
    sqc_parking_base( sqc_object_info_ptr i ) : sqc_road_base( i ) {
    }
};

class sqc_tax_collector : public sqc_building_base {
public:
    sqc_tax_collector( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
};

static const sqc_string	none_agent_id = "0";
static const sqc_string	internal_fiscal_agent_id = "-1";
static const sqc_string	internal_municipal_oficer_id = "-2";

class sqc_city_hall : public sqc_building_base {
public:
    sqc_city_hall( sqc_object_info_ptr i );

#ifndef SQC_OBJECT_DISABLE_DRAWING
	virtual bool do_parse_xml( xml::xml_node_ptr node );
#endif
	const sqc_string&   get_fiscal_agent_id() const;
	const sqc_string&	get_municipal_oficer_id() const;
#ifndef SQC_OBJECT_DISABLE_DRAWING
    virtual void		handle_timer();
#endif
protected:
	int					get_fiscal_agent_auto_points() const;
    int					get_municipal_oficer_auto_points() const;
protected:
	sqc_string			fiscal_agent_id;
    sqc_string			municipal_oficer_id;
    sqc_automation_ptr	m_automation;
    
protected:
	sstl::time_mks	m_last_run_time;
    static const sstl::time_mks	m_interval = 3 * 1000 * 1000; // 1 сек
    
};

typedef std::tr1::shared_ptr<sqc_city_hall>	sqc_city_hall_ptr;

class sqc_subway_depot_factory : public sqc_factory_base {
public:
    sqc_subway_depot_factory( sqc_object_info_ptr i ) : sqc_factory_base( i ) {
    }
};

class sqc_shop_department_leisure : public sqc_leisure_base {
public:
    sqc_shop_department_leisure( sqc_object_info_ptr i ) : sqc_leisure_base( i ) {
    }
};

class sqc_little_metro_terrain : public sqc_terrain_base {
public:
    sqc_little_metro_terrain( sqc_object_info_ptr i ) : sqc_terrain_base( i ) {
    }
};

class sqc_middle_metro_terrain : public sqc_terrain_base {
public:
    sqc_middle_metro_terrain( sqc_object_info_ptr i ) : sqc_terrain_base( i ) {
    }
};

class sqc_sport_complex_terrain : public sqc_terrain_base {
public:
    sqc_sport_complex_terrain( sqc_object_info_ptr i ) : sqc_terrain_base( i ) {
    }
};


class sqc_island_hotel_buildsite : public sqc_buildsite_base {
public:
    sqc_island_hotel_buildsite( sqc_object_info_ptr i ) : sqc_buildsite_base( i ) {
    }
};

class sqc_bungalow : public sqc_house_base {
public:
    sqc_bungalow( sqc_object_info_ptr i ) : sqc_house_base( i ) {
    }
};


class sqc_automate_base : public sqc_city_object_base {
public:
    sqc_automate_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_contract_base : public sqc_city_object_base {
public:
    sqc_contract_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_inactive_place : public sqc_city_object_base {
public:
    sqc_inactive_place( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_expand_base : public sqc_city_object_base {
public:
    sqc_expand_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_complex_buildsite_factory_base : public sqc_city_object_base {
public:
    sqc_complex_buildsite_factory_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_road_junction_buildsite_terrain_base : public sqc_city_object_base {
public:
    sqc_road_junction_buildsite_terrain_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_warehouse_buildsite_terrain_base : public sqc_city_object_base {
public:
    sqc_warehouse_buildsite_terrain_base( sqc_object_info_ptr i ) : sqc_city_object_base( i ) {
    }
};

class sqc_city_staff_buildsite_base : public sqc_building_base {
public:
    sqc_city_staff_buildsite_base( sqc_object_info_ptr i ) : sqc_building_base( i ) {
    }
};
END_NAMESPACE_SQC_CITY

#endif //#ifdef SQC_ENABLE_OBJECTS

#endif //__SQC_CITY_OBJECTS_INCLUDED
