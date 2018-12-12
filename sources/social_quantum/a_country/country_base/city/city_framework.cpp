#include "city_framework.h"

#include "sqc_city.h"
#include "sqc_city_objects.h"
#include "sound/sqc_sound.h"

//
// city field
//
NAMESPACE_SQC_CITY

void sqc_city_field::parse_xml( xml::xml_node_ptr node ) {
    sqc_field_base::parse_xml( node );
    update_roads();
}


void sqc_city_field::get_water_info( int &current, int &max ) {
    current = max = 0;
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        sqc_object_info_ptr object_info( object->get_object_info() );
        sqc_city_object_info *info = (sqc_city_object_info *)object_info.get();
        
        current += info->get_water_consume();
        max += info->get_water_produce();
    }
}

void sqc_city_field::get_power_info( int &current, int &max ) {
    current = max = 0;
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        sqc_object_info_ptr object_info( object->get_object_info() );
        sqc_city_object_info *info = (sqc_city_object_info *)object_info.get();
        
        current += info->get_power_consume();
        max += info->get_power_produce();
    }
}

int sqc_city_field::get_max_population() {
    int result = 0;
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        sqc_object_info_ptr object_info( object->get_object_info() );
        sqc_city_object_info *info = (sqc_city_object_info *)object_info.get();
        
        result += info->get_max_population_increase();
    }
    
    return result;
}


static const sqc_byte c_has_left                 = (1<<0);
static const sqc_byte c_has_right                = (1<<1);    
static const sqc_byte c_has_top                  = (1<<2);
static const sqc_byte c_has_bottom               = (1<<3);    
static const sqc_byte c_left_connect_forbidden   = (1<<4);
static const sqc_byte c_right_connect_forbidden  = (1<<5);
static const sqc_byte c_top_connect_forbidden    = (1<<6);
static const sqc_byte c_bottom_connect_forbidden = (1<<7);

static const sqc_road_type c_road_type_by_index[] =
{
    road_type_roadwork,                             /*0000*/
    road_type_bay_left,                             /*0001*/
    road_type_bay_right,                            /*0010*/
    road_type_line_left_right,                      /*0011*/
    road_type_bay_top,                              /*0100*/
    road_type_turn_left_top,                        /*0101*/
    road_type_turn_right_top,                       /*0110*/
    road_type_3_way_crossroad_left_right_top,       /*0111*/
    road_type_bay_bottom,                           /*1000*/
    road_type_turn_left_bottom,                     /*1001*/
    road_type_turn_right_bottom,                    /*1010*/
    road_type_3_way_crossroad_left_right_bottom,    /*1011*/
    road_type_line_top_bottom,                      /*1100*/
    road_type_3_way_crossroad_left_top_bottom,      /*1101*/
    road_type_3_way_crossroad_right_top_bottom,     /*1110*/
    road_type_4_way_crossroad,                      /*1111*/
};

#define IS_CROSSROAD(v) ((v) >= road_type_3_way_crossroad_left_right_bottom && (v) <= road_type_4_way_crossroad)



sqc_city_field::sqc_city_field( info::sqc_object_info_provider_ptr of ) 
	: sqc_field_base( of ) 
{
    sqc_point field_start( 44, 44 );
    surf::surf_nsize txt_offset( 1500, 1325 );
    surf::surf_nsize txt_size( 36, 22 );
    sqc_string prefix = "earth";
    earth_ptr.reset ( new sqc_earth_base( prefix, field_start, txt_offset, txt_size ) );
    m_ptr_building_area.reset( new sqc_building_area());
}

void sqc_city_field::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
    sqc_field_base::render( ctx, coord_conv );
    m_ptr_building_area->draw( ctx, coord_conv );
}

bool sqc_city_field::is_allow_build( sqc_rect const &rect ) {
    
    bool allow = sqc_field_base::is_allow_build(rect);
    
    if (!allow) {
        return false;
    }
    
    return m_ptr_building_area->is_allow_build( rect );    
}

void sqc_city_field::set_objects_no_status( bool is_no_status )  {
    sqc_field_base::set_objects_no_status(is_no_status);
}

void sqc_city_field::update_roads() {
    BEGIN_PROFILED_AREA("on_new_xml->roads")
    
    bool    initialized = false;
    sqc_rect    rect_field;
    
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        sqc_rect  rect_object( object->get_position(), object->get_size() );
        
        if( !initialized ) {
            rect_field = rect_object;
            initialized = true;
        }
        else {
            rect_field.union_rect( rect_object );
        }
    }
    

    int cx = rect_field.cx;
    int cy = rect_field.cy;
    
    std::vector<sqc_byte>   field;
    field.resize( cx * cy );
    
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        if( !object->is_city_object() ) {
            continue;
        }
        
        sqc_city_object_base    *city_object = static_cast<sqc_city_object_base*>( object.get() );
        city_object->put_road( field, rect_field );
    }
/*    
    std::stringstream out;
    out << "   ";
    for( int x = 0; x != cx; ++x ) {
        out << (x%10) << " ";
    }
    out << std::endl;
    for( int y = 0; y != cy; ++y ) {
        out << y%10 << "  ";
        for( int x = 0; x != cx; ++x ) {
            if( field[x+y*cx] )
                out << "# ";
            else 
                out << ". ";
            
        }
        out << std::endl;
    }
    std::cerr <<out.str();
    
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        if( !object->is_city_object() ) {
            continue;
        }
        
        sqc_city_object_base    *city_object = static_cast<sqc_city_object_base*>( object.get() );
        city_object->put_road( field, rect_field );
    }*/
    
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        
        if( !object->is_road() ) {
            continue;
        }
        
        sqc_road_base *road_object = static_cast<sqc_road_base*>( object.get() );
        if( road_object->get_road_type() == road_type_parking ) {
            continue;
        }
        
        
        sqc_point   position = road_object->get_position();
        int     x = position.x - rect_field.x;
        int     y = position.y - rect_field.y;
        
        int nn = 0;
        
        if (x > 0      && field[x-1 +   (y)*cx] && !(field[x-1 +   (y)*cx] & c_right_connect_forbidden )) nn |= c_has_left;
        if (x < (cx-1) && field[x+1 +   (y)*cx] && !(field[x+1 +   (y)*cx] & c_left_connect_forbidden  )) nn |= c_has_right;
        if (y > 0      && field[x   + (y-1)*cx] && !(field[x   + (y-1)*cx] & c_top_connect_forbidden   )) nn |= c_has_bottom;
        if (y < (cy-1) && field[x   + (y+1)*cx] && !(field[x   + (y+1)*cx] & c_bottom_connect_forbidden)) nn |= c_has_top;
        
        
        sqc_road_type road_type = c_road_type_by_index[nn];
        
        road_object->set_road_type( road_type );
        field[y * cx + x] = road_type;
    }
    
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr &object = *i;
        
        if( !object->is_road() ) {
            continue;
        }
        
        sqc_road_base *road_object = static_cast<sqc_road_base*>( object.get() );
        sqc_road_type   road_type = road_object->get_road_type();
        
        if( road_type == road_type_parking ) {
            continue;
        }
        

        sqc_point   position = road_object->get_position();
        int     x = position.x - rect_field.x;
        int     y = position.y - rect_field.y;
        
        assert( x >= 0 );
        assert( y >= 0 );
        assert( x < rect_field.cx );
        assert( y < rect_field.cy );

        
        if( road_type == road_type_line_left_right ) {
            if (x > 0      && IS_CROSSROAD(field[x-1 + (y)*cx])) road_type = road_type_crosswalk_left;
            if (x < (cx-1) && IS_CROSSROAD(field[x+1 + (y)*cx])) road_type = (road_type == road_type_crosswalk_left) ? road_type_crosswalk_left_right : road_type_crosswalk_right;
        }
        
        if( road_type == road_type_line_top_bottom ) {
            if (y > 0      && IS_CROSSROAD(field[x + (y-1)*cx])) road_type = road_type_crosswalk_bottom;
            if (y < (cy-1) && IS_CROSSROAD(field[x + (y+1)*cx])) road_type = (road_type == road_type_crosswalk_bottom ) ? road_type_crosswalk_top_bottom : road_type_crosswalk_top;
        }
        
        road_object->set_road_type( road_type );
    }
}

bool sqc_city_field::add_extra_objects() {
    BEGIN_PROFILED_AREA( "parse_xml->create_extra_objects" );
    
    static const char *buildingplace_types[] = {
        "subway_depot_place",
        "bridge_place",
        "beach_place",
        "water_system_place",
        "hydroelectric_power_station_place",
        "island_hotel_place",
        "derrick_place",
        "oil_storage_place",
        "oil_pipeline_place",
        "gaslift_place",
        "wwtp_place",
        "lighthouse_place",
        "port_place",
        "yacht_club_place",
        "military_base_place",
        "sawmill_place",
        "airport_place",
        "pyramid_place",
        "armoured_military_base_place",
        "road_junction_place",
        "north_bridge_place",
        "naval_station_place",
        "sea_naval_station_place",
        "gas_power_station_building_place_base",
        "mototrail_place",
        "karnak_temple_place",
        0};
    
    bool    changed = false;
    for( size_t n = 0; buildingplace_types[n]; ++n ) {
        
        const char *object_type = buildingplace_types[n];
        info::sqc_city_buildingplace_info *pbuild_info = 0;
       
        pbuild_info = static_cast<info::sqc_city_buildingplace_info *>(m_object_factory->get_object_info(object_type));
        if( !pbuild_info ) {
            continue;
        }
               
        std::vector<sqc::sqc_string> const &requires = pbuild_info->get_require();
        
        sqc_point coords;
        coords.x = pbuild_info->get_position_x();
        coords.y = pbuild_info->get_position_y();
        
        if( pbuild_info->get_auto_create() ) {
            std::vector<sqc::sqc_string> const &build = pbuild_info->get_build();
            if( !build.size() ) {
                continue;
            }
            
            sqc::sqc_string const &produced_type = *build.begin();
            pbuild_info = static_cast<info::sqc_city_buildingplace_info *>( m_object_factory->get_object_info(produced_type.c_str()));
        }
       
        bool required_found = true;
       
        for( std::vector<sqc::sqc_string>::const_iterator i = requires.begin(); i != requires.end(); ++i ) {
            sqc::info::sqc_object_info *prequire_info = m_object_factory->get_object_info(i->c_str());
           
            if( !get_object_by_type_id(prequire_info->get_type_id()) ) {
                required_found = false;
                break;
            }
        }
        if( !required_found ) {
            continue;
        }
              
        sqc_game_object_ptr obj_found;
        obj_found = get_object_by_point(coords);
       
        // TODO
        bool obj_usable = true; 
        if( obj_found && obj_found->get_id() == pbuild_info->get_object_id() ) {
            //obj_found->object_usable = true;
            obj_usable = true;
            continue;
        }
        else if( obj_found && /*obj_found->object_usable*/obj_usable ) {
            continue;
        }
        else {
            sqc_game_object_ptr new_object = pbuild_info->create_instance(); 
            new_object->set_position(coords);
            new_object->set_orientation(false);
                      
            m_objects.push_back(new_object);
            changed = true;
        }
    }
    return changed;    
}


int sqc_city_field::get_tax_admin_id() {
	sqc_game_object_list list;
	get_object_by_type_name( "tax_collector_real", list );
    if ( list.empty() ) {
    	get_object_by_type_name( "tax_collector_unreal", list );
    }
    
    if ( list.empty() ) {
    	return 0;
    }
	return list.begin()->get()->get_id();    
}

int sqc_city_field::get_city_hall_id() {
	sqc_game_object_list list;
	get_object_by_type_name( "city_hall_real", list );
    if ( list.empty() ) {
    	get_object_by_type_name( "city_hall_unreal", list );
    }
    
    if ( list.empty() ) {
    	return 0;
    }
	return list.begin()->get()->get_id();    
}

sqc_city_game::sqc_city_game( info::sqc_object_info_provider_ptr of )
: m_population( 0 )
, m_tax_rate( 0 )
, m_auto_operations( 0 ) 
{
	m_field.reset( new sqc_city_field( of ) );
}

void sqc_city_game::parse_xml( xml::xml_node_ptr xml ) {
    sqc_game_base::parse_xml( xml );
    
    m_population		= xml->get_attribute_int( "population" );
    m_tax_rate			= xml->get_attribute_int( "tax" );
    m_auto_operations	= xml->get_attribute_int( "auto" );
}

    
void sqc_city_game::fill_common_info( sqc_common_scene_info &info ) {
	sqc_game_base::fill_common_info( info );
    
    sqc_city_field_ptr  city_field = std::tr1::static_pointer_cast<sqc_city_field>( m_field );
    
    city_field->get_water_info( info.water, info.max_water ); 
    city_field->get_power_info( info.power, info.max_power ); 
                       
    info.population			= m_population;
    info.max_population		= city_field->get_max_population();
    
    info.tax_admin_object_id	= city_field->get_tax_admin_id();
    info.city_hall_object_id	= city_field->get_city_hall_id();
    
    info.tax_rate			= m_tax_rate;
    info.auto_operations	= m_auto_operations;
}



END_NAMESPACE_SQC_FRAMEWORK


//
//
//

NAMESPACE_SQC_CITY


// -- sqc_message_queue_base;
sqc_city_message_queue::sqc_city_message_queue(sqc_notify_center& notify_center
                                               , sqc_game_ptr& game
                                               , sqc_country_base_ui_face& ui)
            : sqc_message_queue_base(notify_center,game,ui)
{
}

sqc_city_message_queue::~sqc_city_message_queue()
{

}

/*
Жуткий костыль
*/
void sqc_city_message_queue::param_instance(sqc_notify_center& notify_center
              , sqc_game_ptr& game
              , sqc_country_base_ui_face& ui)
{
    m_game = game;
    m_ui   = ui;
    m_notify_center = notify_center;
    
    init();
}
// --



sqc_city_framework::sqc_city_framework( 
	surf::surf_image_loader& img_loader, 
    surf::surf_font_loader& fnt_loader,
    sqc_string_resources& string_res,
    sqc_http_service& http_service,
    sqc_social_networks_factory& networks_factory,
    sqc_preferences&  preferences,
    sqc_sound_server_ptr sound)
: sqc_framework_base( m_theme, 
                     img_loader, 
                     fnt_loader, 
                     string_res, 
                     http_service,
                     networks_factory,
                     preferences,
                     m_server_config,
                     m_dialogs,
                     m_message_queue,
                     sound)    
    , m_server_config( http_service ) 
    , m_theme( m_graphics )
    , m_dialogs(m_notify_center)
    , m_message_queue(m_notify_center,m_game,m_ui)
{

    m_class_factory.reset( new sqc_city_class_factory() );
    m_drawing_provider.reset( new sqc_city_drawing_provider() );
    m_class_provider.reset( new sqc_object_info_provider() );
    m_game.reset( new sqc_city_game( m_class_provider ) );
    m_message_queue.param_instance(m_notify_center,m_game,m_ui);
}

// create country view
bool sqc_city_framework::create_country_view( const milk::surf_rect& rect ) {
    m_ptr_country_view = windows().get_desktop()->create_child<sqc_city_country_view>( rect, m_game );
    if (preferences().get_bool("settings", "music_enabled", true) )
        sound().play_music("city_background"); 
    else 
        sound().music().open("city_background");
    return ( !!m_ptr_country_view );
}

city_dialogs&	sqc_city_framework::dialogs() {
    return m_dialogs;
}

END_NAMESPACE_SQC_CITY
