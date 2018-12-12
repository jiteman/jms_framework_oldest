#include "sqc_tools_adapter.h"
#include "country_base/view/sqc_scene_view.h"
#include "country_base/view/sqc_country_view.h"
#include "country_base/sqc_field_base.h"
#include "country_base/commands/sqc_command_processor.h"
#include "country_base/sqc_buy_object.h"

NAMESPACE_SQC_TOOLS

/// time before activate second tool action ( move ) ms
static const surf::surf_dword SECOND_ACTION_ACTIVATE_TIME = 400;


sqc_tool_adapter_impl::sqc_tool_adapter_impl( sqc_scene_view &v, sqc_country_view &cv, sqc_field_base &f, processor::sqc_command_processor &p, info::sqc_object_info_provider &ip ) 
    : m_view( v ), m_country_view( cv ), m_field( f ), m_processor( p ), m_factory( ip ), m_country_owner ( sqc_country_owner_me )
{
    using namespace std::tr1::placeholders;
    m_notify_connection = 
        sqc::framework::framework().notify_center().subscribe(std::tr1::bind( &sqc_tool_adapter_impl::notify_callback, this, _1, _2, _3 ));
}

sqc_tool_adapter_impl::~sqc_tool_adapter_impl() {
    sqc::framework::framework().notify_center().unsubscribe(m_notify_connection);
}

sqc_game_object_ptr sqc_tool_adapter_impl::get_selected_object() {
    return m_view.get_selected_object();
    
}
void sqc_tool_adapter_impl::set_selected_object( sqc_game_object_ptr object , sqc_game_object_selection_type type) {
    m_view.set_selected_object( object , type );
    fire_event(object_tool_event);
}
void sqc_tool_adapter_impl::reset_selected_object() {
    m_view.set_selected_object( sqc_game_object_ptr() , sqc_game_object_selection_type_none );
    fire_event(object_tool_event);
}

void sqc_tool_adapter_impl::scroll_to_object( sqc_game_object_ptr object ) {
    if( !object ) {
        return;
    }
    
    /*
    sqc_point   point1 = object->get_position();
    sqc_size    object_size = object->get_size();
    sqc_point   point2( object_size.cx, object_size.cy );
    
    surf::surf_point    
    pos = m_view.field_to_screen( point1, false );
    pos += m_view.field_to_screen( point2, false );
    pos /= 2;
    
    surf::surf_nsize size = m_view.get_screen_size();
    pos.x -= size.cx/2;
    pos.y -= size.cy/2;
    
    m_view.animated_scroll( pos );
    */
    
    surf::surf_point scroll_position = m_view.get_scroll_pos();
    surf::surf_rect obj_rect = object->get_display_rect( m_view );
    obj_rect *= m_view.get_zoom();
    obj_rect += scroll_position;
    
    surf::surf_nsize _size = m_view.get_screen_size(false);
	surf::surf_point pos;
    pos.x = obj_rect.x-(_size.cx-obj_rect.cx)/2;
    pos.y = obj_rect.y-(_size.cy-obj_rect.cy)/2;
    
    m_view.animated_scroll( pos );
}

sqc_game_object_ptr sqc_tool_adapter_impl::get_object_by_screen_point( surf::surf_point const &point ) {
    sqc_game_object_ptr object( m_view.get_selected_object() );
    
    if( object ) {
        if( object->check_point_on_object( point, m_view ) ) {
            return object;
        }
    }
    
    return m_field.get_object_by_screen_point( point, m_view );
    
}


sqc_game_object_ptr sqc_tool_adapter_impl::get_object_by_point( sqc_point const &coords ) {
    
    sqc_game_object_ptr object( m_view.get_selected_object() );
    
    if( object ) {
        sqc_rect    rect( object->get_position(), object->get_size() );
        
        if( rect.point_in_rect( coords ) ) {
            return object;
        }
    }

    
    return m_field.get_object_by_point( coords );
}

bool sqc_tool_adapter_impl::move_object( sqc_game_object_ptr object, sqc_point const &point ) {
    if( !m_field.move_object( object, point ) ) {
        return false;
    }
    m_view.invalidate();
    fire_event(object_tool_event);
    return true;
}

bool sqc_tool_adapter_impl::rotate_object( sqc_game_object_ptr object ) {
    if( !m_field.rotate_object( object ) ) {
        return false;
    }
    m_view.invalidate();
    fire_event(object_tool_event);
    return true;
}


bool sqc_tool_adapter_impl::is_allow_build( sqc_rect const &rect ) {
    if (!m_field.is_allow_build( rect )) return false;
    sqc_game_object_ptr obj = get_selected_object();
    sqc_game_object_ptr new_obj = m_field.get_object_intersect_rect(rect, obj ? obj->get_id() : 0 );
    if (new_obj && new_obj != obj )
        return false;
    return true;
}

sqc_game_object_ptr sqc_tool_adapter_impl::create_build_object( sqc_point const &coords, sqc_size const &object_size ) {
    sqc_game_object_ptr object( new sqc_buy_object( object_size ) );
    
    object->set_position( coords );
    
    return object;
}
sqc_game_object_ptr sqc_tool_adapter_impl::create_object( sqc_point const &coord, sqc_string const &object_type ) {
    sqc_game_object_ptr object( m_factory.create_instance( object_type.c_str() ) );
    if( !object ) {
        return object;
    }
    
    sqc_size    object_size( object->get_size() );
    sqc_point   object_coords( coord.x - object_size.cx+1, coord.y );
    object->set_position( object_coords );
    
    object->reload_textures();

    return object;
}


void sqc_tool_adapter_impl::apply_move_object( sqc_game_object_ptr object ) {
    m_field.zorder_objects();
    
    using namespace processor;
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_move_command( str_user_id, object->get_id(), object->get_position(), object->get_orientation() ) );
    m_processor.schedule( command );
    
}
void sqc_tool_adapter_impl::build_object( sqc_game_object_ptr object, sqc_point const &point ) {
    using namespace processor;
    sqc_string str_user_id = "";

    sqc_command_ptr  command( new sqc_create_command( str_user_id, object->get_type(), object->get_position(), object->get_orientation() ) );
    m_processor.schedule( command );
}

void sqc_tool_adapter_impl::receive_object( sqc_game_object_ptr object, sqc_point const &point ) {
    using namespace processor;
    sqc_string str_user_id = "";

    
    sqc_command_ptr command( 
        new sqc_receive_gift_command( str_user_id,
                                      object->get_id(),
                                      object->get_type(),
                                      object->get_orientation(),
                                      object->get_position().x,
                                      object->get_position().y
                                    ) 
            
	);
    m_processor.schedule( command );
}

bool sqc_tool_adapter_impl::delete_object( sqc_game_object_ptr object ) {
    using namespace processor;
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_sell_command( str_user_id, object->get_id() ) );
    m_processor.schedule( command );
    
    return true;
}


bool sqc_tool_adapter_impl::run_action( sqc_game_object_ptr object, sqc_action action, const sqc_action_params_ptr& params ) {
	if (!object) return false;
    
    if (get_country_owner() != sqc_country_owner_me && action != action_choose_material) {
        return false;
    }
    
    if( action == action_build ) {
        //city_dialogs& dialogs = city_framework().dialogs();
        //dialogs.show_shop_categories_dialog( shared_from_this() );
        sqc_point   coords = object->get_position();
        show_shop( &coords );
        return true;
    }
    
#if defined SQC_FARM_GAME    
    if( action == action_choose_seed ) {
        sqc_point   coords = object->get_position();
        show_seeds_shop( &coords, sqc_shop_category_seeds );
        return true;
    }    
    
    if( action == action_choose_animal ) {
        sqc_point   coords = object->get_position();
        show_seeds_shop( &coords, sqc_shop_category_animals );
        return true;
    }

#endif
    
    if( action == action_purchase_building_site ) {
        sqc_point   coords = object->get_position();
        show_construction_shop( &coords, object->get_type() );
        return true;
    }
    
    if( action == action_choose_material ) {
        m_country_view.show_material_shop( object );
        return true;
    }
    
    if ( action == action_load ) {
        m_country_view.show_contracts_shop( object->get_id(), object->get_type() );
        return true;
    }
    
    using namespace processor;
    sqc_command_ptr  command;
    sqc_string str_user_id = "";
    
    sqc_command_priority priority = command_priority_now;
    
    if( action == action_tick ) {
        command.reset( new sqc_tick_command( str_user_id, object->get_id() ) );
    }
    else if( action == action_pick ) { 
        command.reset( new sqc_pick_command( str_user_id, object->get_id() ) );
        priority = command_priority_idle;
    }
    else if( action == action_clean ) {
        command.reset( new sqc_clean_command( str_user_id, object->get_id() ) );
        priority = command_priority_idle;
    }
    else if( action == action_cancel ) {
        command.reset( new sqc_cancel_command( str_user_id, object->get_id() ) );
    }
    else if( action == action_move_to_pen ) {
        command.reset( new sqc_move_to_pen_command( str_user_id, object->get_id() ) );
        priority = command_priority_idle;
    }
    else if( action == action_put ){
        
        info::sqc_object_info_ptr _object_info = object->get_object_info();
        
        switch(_object_info->get_type()) 
        {
            case sqc::info::type_farm_factory:
            case sqc::info::type_farm_animal_place:
            {
                command.reset( new sqc_put_command_2_params( str_user_id, object->get_id() ) );
            }break;
            case sqc::info::type_farm_multi_factory:
            {
                if(params) {
                    sqc_string _type = params->str_value;
                    command.reset( new sqc_put_command( str_user_id, _type, object->get_id() ) );
                }
            }break;
            default:
                break;
        }
        
        priority = command_priority_idle;
    }
    else if (action == action_switch_input) {
        // change using resource (multifactory)
        if(params) {
            sqc_string type_item = params->str_value;
            command.reset( new sqc_switch_item_command( str_user_id, object->get_id(), type_item ) );
            priority = command_priority_idle;
        }
    }

    if( !command ) {
        return false;
    }
    
    m_processor.schedule( command, priority );
	return true;
}

void sqc_tool_adapter_impl::on_object_purchased( sqc_string object_class, sqc_point object_coords ) {
    
}

void sqc_tool_adapter_impl::show_construction_shop( sqc_point *pobject_coords, sqc_string const &construction_type ) {
    sqc_point   object_coords;
    if( pobject_coords ) {
        object_coords = *pobject_coords;
    }
    else {
        surf::surf_point point( m_view.get_screen_size().cx/2, m_view.get_screen_size().cy/2 );
        object_coords = m_view.screen_to_field( point, false );
    }
    
    
    m_country_view.show_construction_shop( object_coords, construction_type );
}

void sqc_tool_adapter_impl::show_shop( sqc_point *pobject_coords ) {
    sqc_point   object_coords;
    if( pobject_coords ) {
        object_coords = *pobject_coords;
    }
    else {
        surf::surf_point    point( m_view.get_screen_size(false).cx/2, m_view.get_screen_size(false).cy/2 );
        object_coords = m_view.screen_to_field( point, false );
    }
    
    
    m_country_view.show_shop( object_coords );
}

#if defined SQC_FARM_GAME
void sqc_tool_adapter_impl::show_seeds_shop( sqc_point *pobject_coords, sqc_shop_category category  ) {
    sqc_point   object_coords;
    if( pobject_coords ) {
        object_coords = *pobject_coords;
    }
    else {
        surf::surf_point    point( m_view.get_screen_size(false).cx/2, m_view.get_screen_size(false).cy/2 );
        object_coords = m_view.screen_to_field( point, false );
    }
     
    if (category == sqc_shop_category_seeds)
        m_country_view.show_seeds_shop( object_coords );
    else if (category == sqc_shop_category_animals)
        m_country_view.show_animals_shop( object_coords );
    else
        assert( false && "unsupported" );
}
#endif

void sqc_tool_adapter_impl::show_bubble( surf::surf_point const &pos, sqc::framework::sqc_bubble_content const &content ) {
	m_view.show_bubble( pos, content );
}

void sqc_tool_adapter_impl::hide_bubble() {
	m_view.close_bubble();
}

bool sqc_tool_adapter_impl::get_bubble_active() const {
	return m_view.get_bubble_visible();
}

sqc_country_owner sqc_tool_adapter_impl::get_country_owner() const  {
	return m_country_owner;
}

void sqc_tool_adapter_impl::fire_event( sqc_string event ) {
    sqc::framework::framework().notify_center().fire_event(
                                                           tool_provider_id, 
                                                           event,
                                                           sqc::framework::call_async );
}

void sqc_tool_adapter_impl::visit_frend_field( const sqc_string& friend_id ) {

    using namespace processor;
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_view_friend_field_command( str_user_id, friend_id ) );
    m_processor.schedule( command );
}

void sqc_tool_adapter_impl::leave_frend_field() {
    using namespace processor;
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_view_own_field_command( str_user_id ) );
    m_processor.schedule( command );
}

void sqc_tool_adapter_impl::notify_callback( const sqc_provider_id& provider_id, 
                                             const sqc_event_id& event_id,
                                             const sqc_event_value value ) {
    
    if (processor::command_processor_provider_id == provider_id) {

        if (processor::command_processor_command_successfully_event == event_id) {
            if (processor::server_cmd_view_friend_field == value) {
                m_country_owner = sqc_country_owner_friend;
                m_field.set_objects_no_status(true);
            }
            else if(processor::server_cmd_view_own_field == value) {
                m_country_owner = sqc_country_owner_me;
                m_field.set_objects_no_status(false);
            }
        }
    }
}

/// close current tool ( switch to default )
void sqc_tool_adapter_impl::close_tool() {
    m_country_view.switch_to_default_tool();
}

/// time before activate second action (ms)
surf::surf_dword sqc_tool_adapter_impl::get_second_action_time() const {
    return SECOND_ACTION_ACTIVATE_TIME;
}


END_NAMESPACE_SQC_TOOLS
