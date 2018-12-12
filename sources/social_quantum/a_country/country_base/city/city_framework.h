#pragma once

#include "../sqc_framework_base.h"

#include "../../framework/sqc_framework.h"
#include "view/city_country_view.h"
#include "theme/city_theme.h"
#include "dialogs/city_dialogs.h"
#include "sqc_yaml.h"
#include "sqc_city.h"
#include "sqc_building_area.h"

NAMESPACE_SQC_CITY

using namespace sqc::framework;

class sqc_city_server_config : public sqc_server_config_base {
public:
    sqc_city_server_config(sqc_http_service &http_service)
        : sqc_server_config_base(http_service)
        , m_path_to_object_localization_strings( "iCity/localization/items.city." + sqc::yaml::get_language_suffix() + ".strings" )
        , m_path_to_quest_localization_strings( "iCity/localization/quests.city." + sqc::yaml::get_language_suffix() + ".strings" )
    {
        m_app_name = "city.";
        m_textures_subfolder = "iCity";
    }        
    
    const char *get_yml_name( sqc_request_type request_type ) const {
        if     ( request_type == request_type_objects )  return "city_items.yml";
        else if( request_type == request_type_hierarchy )  return "city_hierarchy.yml";
        else if( request_type == request_type_quests )  return "city_quests.yml";
        else if( request_type == request_type_requests )  return "city_requests.yml";
        else if( request_type == request_type_textures_plist )  return "iCity/textures.plist";
        else if( request_type == request_type_object_localization_strings ) return m_path_to_object_localization_strings.c_str();
        else if( request_type == request_type_quest_localization_strings ) return m_path_to_quest_localization_strings.c_str();
        else if( request_type == request_type_binary_objects ) return "city_items.bin";
        
        sqc_assert( false );
        return 0;
    }
            
private:
    const sqc_string m_path_to_object_localization_strings;
    const sqc_string m_path_to_quest_localization_strings;
};

class sqc_city_field : public sqc_field_base {
public:
    sqc_city_field( info::sqc_object_info_provider_ptr of );    
    virtual void parse_xml( xml::xml_node_ptr node );
    virtual void update_roads();
    virtual bool add_extra_objects();
    
    int			get_tax_admin_id();
    int			get_city_hall_id();
    
    virtual void render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    virtual bool is_allow_build( sqc_rect const &rect );
    virtual void set_objects_no_status( bool is_no_status ); 
    
    void    get_water_info( int &current, int &max );
    void    get_power_info( int &current, int &max );
    int     get_max_population();
protected:
    sqc_building_area_ptr m_ptr_building_area;
};
typedef std::tr1::shared_ptr<sqc_city_field>	sqc_city_field_ptr;


class  sqc_city_game : public sqc_game_base {
public:
    sqc_city_game( info::sqc_object_info_provider_ptr of );
    
    virtual void parse_xml( xml::xml_node_ptr xml );
    virtual void fill_common_info( sqc_common_scene_info &info );

protected:
    int m_population;
    int m_tax_rate;
    int m_auto_operations;
};

typedef std::tr1::shared_ptr<sqc_city_game>	sqc_city_game_ptr;



class sqc_city_message_queue : public sqc_message_queue_base
{
public:
    sqc_city_message_queue( sqc_notify_center& notify_center
                            , sqc_game_ptr& game
                            , sqc_country_base_ui_face& ui);    
	~sqc_city_message_queue();
    
    void param_instance(sqc_notify_center& notify_center
                  , sqc_game_ptr& game
                  , sqc_country_base_ui_face& ui);
};


//
// sqc_city_framework implementation
//
class sqc_city_framework : public sqc_framework_base {
public:
	sqc_city_framework( surf::surf_image_loader& img_loader, 
					   surf::surf_font_loader& fnt_loader,
					   sqc_string_resources& string_res,
					   sqc_http_service& http_service,
                       sqc_social_networks_factory& networks_factory,
                       sqc_preferences&  preferences,
                       sqc_sound_server_ptr sound);
	
    // create country view
    virtual bool create_country_view( const milk::surf_rect& rect );
    
	// return city specific dialogs
	city_dialogs&	dialogs();

private:
	sqc_city_theme			m_theme;
	city_dialogs			m_dialogs;
    sqc_city_message_queue  m_message_queue;
	sqc_city_server_config	m_server_config;
};
typedef std::tr1::shared_ptr<sqc_city_framework>	sqc_city_framework_ptr;
extern sqc_city_framework& city_framework();

END_NAMESPACE_SQC_FRAMEWORK
