#pragma once

#include "../../framework/sqc_framework_defs.h"

#include "sqc_scene_view.h"
#include "../sqc_game_base.h"

NAMESPACE_SQC_FRAMEWORK

//
// base view for country view
// sqc_country_view implementation
//
class sqc_country_view : public milk::milk_widget {
public:
	sqc_country_view( milk::milk_widget_ptr p, sqc_game_ptr g );
	virtual ~sqc_country_view();
    
    virtual void on_create();
    virtual void on_destroy();
    
    virtual void render( surf::surf_context_ptr ctx );
    
    void on_rotate_pressed();
    void on_delete_pressed();
    
    void on_warehouse_pressed();
    void on_market_pressed();
    
    
     // notification callback
    virtual void	notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id );
    
    virtual void    show_contracts_shop( int item_id, sqc_string const &type ) = 0;
    virtual void 	show_material_shop( sqc_game_object_ptr object  ) = 0;
    virtual void 	show_construction_shop( sqc_point const &object_coords, sqc_string const &type ) = 0;
    virtual void 	show_shop( sqc_point const &object_coords ) = 0;
    virtual void 	show_seeds_shop( sqc_point const &object_coords ) = 0;
    virtual void 	show_animals_shop( sqc_point const &object_coords ) = 0;
    
    virtual void	update_toolbar_controls();
    virtual void	update_top_gui();
    
    sqc_scene_view_ptr scene_view();
    
    virtual void switch_to_default_tool();
protected:
	sqc_scene_view_ptr              m_ptr_scene_view;
    sqc_game_ptr                    m_game;
    sqc_window_factory_ctx_ptr      m_window_ctx;
    
    sqc_listener_connection         m_notify_connection;
};

typedef std::tr1::shared_ptr<sqc_country_view>	sqc_country_view_ptr;
	
END_NAMESPACE_SQC_FRAMEWORK
