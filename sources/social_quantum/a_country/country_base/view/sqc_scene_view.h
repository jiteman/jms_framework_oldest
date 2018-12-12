#pragma once

#include "../../framework/sqc_framework_defs.h"
#include "../../framework/notify_center/sqc_notify_center.h"
#include "../sqc_field_base.h"
#include "../sqc_earth_base.h"
#include "../tools/sqc_tools_adapter.h"
#include "sqc_bubble.h"
#include "../sqc_object_selection.h"
#include "sqc_tooltips.h"

NAMESPACE_SQC_FRAMEWORK

struct sqc_bubble_content;

//
// base view for scene view
// sqc_scene_view implementation
//
class sqc_scene_view 
    : public milk::milk_scroll_zoom_area
    , public sqc_coord_convertor  
{
public:
	sqc_scene_view( milk::milk_widget_ptr p, sqc_field_ptr f );
	virtual ~sqc_scene_view();
    
    virtual void render( surf::surf_context_ptr ctx );
    virtual void on_notify( const sqc_provider_id& provider_id, const sqc_event_id& event_id, const sqc_event_value value );
    virtual void on_create();
    virtual void on_destroy();
    virtual void on_timer( surf::surf_ddword tick );
    virtual bool on_touch( milk::milk_touch_info const &touch );
    virtual void on_scroll();
	
    
    //
    //
    //
    virtual surf::surf_size  get_cell_size() const = 0;
    virtual surf::surf_val   get_zoom() const;
    virtual surf::surf_nsize get_screen_size(bool with_zoom=true) const;
    virtual surf::surf_point field_to_screen( sqc_point const &p, sqc_coord_convert_mode mode , bool center) const;
    virtual sqc_point        screen_to_field( surf::surf_point const &pt, bool strong ) const;
    
    //
    //
    //
    virtual sqc_game_object_ptr get_selected_object();
    virtual void set_selected_object( sqc_game_object_ptr object , sqc_game_object_selection_type type );
    
    
    //
    //
    //
    tools::sqc_tool_context &get_tool_context() {
        sqc_assert(m_tool_context);
        return *m_tool_context.get();
    }
	void generate_earth();

	/// bubbles
	void show_bubble( surf::surf_point const &pos, sqc_bubble_content const &content );
    void close_bubble();
	bool get_bubble_visible() const;
protected:
    sqc_game_object_ptr m_selected_object;
	sqc_object_selection_ptr	m_object_selection;

    sqc_field_ptr   m_field;
        
    sqc::framework::sqc_listener_connection   m_notify_connection;
    sqc_window_factory_ctx_ptr                m_window_ctx;
    
    bool    m_scroll_initialized;
    
    tools::sqc_tool_context_ptr         m_tool_context;
	
	sqc_ddword	m_field_update_time_stamp;
	/// bubbles
	sqc_bubble_ptr      m_bubble;
    surf::surf_point    m_bubble_pos;
	void update_bubble_pos();
	virtual sqc_bubble_ptr create_bubble( sqc_bubble_content const &content ) ;
	
	sqc_tooltips_manager_ptr	m_tooltips_mgr;
	void on_object_tooltip( const sqc_game_object_ptr& obj );
    
    
    
    void set_wait_update_object(int new_object_id);
    int m_last_object_id;
    
    int m_last_touch_id;
};

typedef std::tr1::shared_ptr<sqc_scene_view>	sqc_scene_view_ptr;

END_NAMESPACE_SQC_FRAMEWORK
