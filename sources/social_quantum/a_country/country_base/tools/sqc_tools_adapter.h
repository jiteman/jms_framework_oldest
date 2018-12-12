#pragma once

#include "../../framework/notify_center/sqc_notify_center.h"
#include "sqc_tools.h"
#include "../shop/sqc_shop_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_scene_view;
class sqc_field_base;
class sqc_country_view;
class sqc_building_area_ptr;

END_NAMESPACE_SQC_FRAMEWORK

NAMESPACE_SQC_INFO

class sqc_object_info_provider;

END_NAMESPACE_SQC_INFO

NAMESPACE_SQC_PROCESSOR

class sqc_command_processor;

END_NAMESPACE_SQC_PROCESSOR


NAMESPACE_SQC_TOOLS

using namespace framework;


class sqc_tool_adapter_impl : public sqc_tool_context {
public:
    sqc_tool_adapter_impl( sqc_scene_view &v, sqc_country_view &cv, sqc_field_base &f, processor::sqc_command_processor &p, info::sqc_object_info_provider& ip );
    ~sqc_tool_adapter_impl();
    
    virtual sqc_game_object_ptr get_selected_object();
    virtual void set_selected_object( sqc_game_object_ptr object , sqc_game_object_selection_type type );
    virtual void reset_selected_object();
    
    virtual void scroll_to_object( sqc_game_object_ptr object );
    virtual bool move_object( sqc_game_object_ptr object, sqc_point const &point );
    virtual bool rotate_object( sqc_game_object_ptr object );
    
    virtual sqc_game_object_ptr get_object_by_point( sqc_point const &coords );
    virtual sqc_game_object_ptr get_object_by_screen_point( surf::surf_point const &point );
    
    
    virtual bool is_allow_build( sqc_rect const &rect );
    virtual sqc_game_object_ptr create_build_object( sqc_point const &coords, sqc_size const &object_size );
    virtual sqc_game_object_ptr create_object( sqc_point const &coords, sqc_string const &object_type );
    
    
    virtual void apply_move_object( sqc_game_object_ptr object );
    virtual void build_object( sqc_game_object_ptr object, sqc_point const &point );
    virtual void receive_object( sqc_game_object_ptr object, sqc_point const &point );
    virtual bool delete_object( sqc_game_object_ptr object );
    virtual bool run_action( sqc_game_object_ptr object, sqc_action action, const sqc_action_params_ptr& params );
    
    virtual void show_construction_shop( sqc_point *pobject_coords = 0, sqc_string const &construction_type = sqc_string() );
    virtual void show_shop( sqc_point *pobject_coords = 0 );
#if defined SQC_FARM_GAME    
    virtual void show_seeds_shop( sqc_point *pobject_coords, sqc_shop_category category );
#endif
    
    virtual void show_bubble( surf::surf_point const &pos, sqc::framework::sqc_bubble_content const &content );
	virtual void hide_bubble();
	virtual bool get_bubble_active() const;
	
	virtual sqc_country_owner get_country_owner() const ;
    
    virtual void fire_event( sqc_string event );
    
    virtual void visit_frend_field( const sqc_string& friend_id );
    virtual void leave_frend_field();
    
    /// close current tool ( switch to default )
    virtual void close_tool();
    /// time before activate second action (ms)
    virtual surf::surf_dword get_second_action_time() const;
protected:
    void on_object_purchased( sqc_string object_class, sqc_point object_coords );
    void notify_callback( const sqc_provider_id& provider_id, 
                          const sqc_event_id& event_id,
                          const sqc_event_value value );
        
protected:
    sqc_scene_view &m_view;
    sqc_country_view &m_country_view;
    sqc_field_base &m_field;
    processor::sqc_command_processor &m_processor;
    info::sqc_object_info_provider  &m_factory;
    sqc_country_owner m_country_owner;
    sqc_listener_connection	m_notify_connection;
};

END_NAMESPACE_SQC_TOOLS
