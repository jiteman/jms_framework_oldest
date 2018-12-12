#pragma once

#include "../../sqc/sqc_defs.h"
#include "../../sqc/sqc_base.h"

#include "../view/sqc_bubble_def.h"
#include "../sqc_country_common.h"

#define NAMESPACE_SQC_TOOLS  namespace sqc { namespace tools {
#define END_NAMESPACE_SQC_TOOLS } }


NAMESPACE_SQC_TOOLS

enum sqc_tool_type {
    tool_type_undefined,
    tool_type_multi,
    tool_type_edit,
    tool_type_buy,
    tool_type_visit_field,
    tool_type_shovel,
    tool_type_seed,
};

enum sqc_tool_action {
    tool_action_apply,
    tool_action_rotate,
    tool_action_delete,
    tool_action_move,
    tool_action_cancel,
    tool_action_market,     ///< market action ( show shop )
    tool_action_warehouse
};

declare_notification_provider_id( tool_provider_id )
declare_notification_event_id( object_tool_event )

inline 
const char *print_tool_type( sqc_tool_type type ) {
    if( type == tool_type_multi )   return "multi_tool";
    else if( type == tool_type_edit ) return "edit_tool";
    else if( type == tool_type_buy ) return "buy_tool";
    else if( type == tool_type_visit_field ) return "visit_field_tool";
    else if( type == tool_type_shovel ) return "shovel_tool";
    else if( type == tool_type_seed ) return "shovel_seed";
    else return "undefined_tool";
}

inline
const char *print_tool_action( sqc_tool_action action ) {
    if( action == tool_action_apply )   return "[apply]";
    else if( action == tool_action_rotate ) return "[rotate]";
    else if( action == tool_action_delete ) return "[delete]";
    else if( action == tool_action_market ) return "[market]";
    else if( action == tool_action_warehouse ) return "[warehouse]";
    else return "[???]";
}


struct sqc_activate_tool_arg {
    sqc_string purchased_object_type;
    
    bool        operation_coords_defined;
    sqc_point   operation_coords;
    
    bool        apply_changes;
    bool		gift;

    sqc_string  user_id;
};

struct sqc_action_params {
    sqc_string str_value;
};

typedef std::tr1::shared_ptr<sqc_action_params> sqc_action_params_ptr;

class sqc_tool_context {

public:
    virtual sqc_game_object_ptr get_selected_object() = 0;
    virtual void set_selected_object( sqc_game_object_ptr object , 
                                     sqc_game_object_selection_type type = sqc_game_object_selection_type_normal ) = 0;
    virtual void reset_selected_object() = 0;
    
    virtual void scroll_to_object( sqc_game_object_ptr object ) = 0;
    
    virtual sqc_game_object_ptr get_object_by_point( sqc_point const &coords ) = 0;
    virtual sqc_game_object_ptr get_object_by_screen_point( surf::surf_point const &coords ) = 0;
    virtual bool move_object( sqc_game_object_ptr object, sqc_point const &point ) = 0;
    virtual bool rotate_object( sqc_game_object_ptr object ) = 0;
    
    
    virtual bool is_allow_build( sqc_rect const &rect )= 0;
    virtual sqc_game_object_ptr create_build_object( sqc_point const &coords, sqc_size const &object_size ) = 0;
    virtual sqc_game_object_ptr create_object( sqc_point const &coords, sqc_string const &object_type ) = 0;
    
    
    virtual void apply_move_object( sqc_game_object_ptr object ) = 0;
    virtual void build_object( sqc_game_object_ptr object, sqc_point const &point ) = 0;
    virtual void receive_object( sqc_game_object_ptr object, sqc_point const &point ) = 0;
    virtual bool delete_object( sqc_game_object_ptr object ) = 0;
    virtual bool run_action( sqc_game_object_ptr object, sqc_action action, const sqc_action_params_ptr& params = sqc_action_params_ptr()) = 0;
    
    virtual void show_construction_shop( sqc_point *pobject_coords = 0, sqc_string const &construction_type = sqc_string() ) = 0;
    virtual void show_shop( sqc_point *pobject_coords = 0 ) = 0;
	
	virtual void show_bubble(  surf::surf_point const &pos, sqc::framework::sqc_bubble_content const &content ) = 0;
	virtual void hide_bubble() = 0;
	virtual bool get_bubble_active() const = 0;
	
	virtual sqc_country_owner get_country_owner() const = 0;
    
    virtual void fire_event( sqc_string event ) = 0;

    virtual void visit_frend_field( const sqc_string& user_id ) = 0;
    virtual void leave_frend_field() = 0;
    
    /// close current tool ( switch to default )
    virtual void close_tool() = 0;
    /// time before activate second action (ms)
    virtual surf::surf_dword get_second_action_time() const = 0;
};

typedef std::tr1::shared_ptr<tools::sqc_tool_context> sqc_tool_context_ptr;

class sqc_tool {

public:
    sqc_tool() {
    }
    virtual ~sqc_tool() {
    }
    
    virtual sqc_tool_type get_type() const = 0;
    
    virtual bool on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    
    virtual void on_deactivate( bool apply_changes, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    
    virtual bool on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
        return false;
    }
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
        return false;
    }
    virtual bool on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
        return false;
    }
    virtual bool on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
        return false;
    }
    virtual bool process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
        return false;
    }
    virtual bool on_timer(sqc_ddword ticks, sqc_tool_context &ctx,  sqc_coord_convertor &coord_conv) {
        return false;
	}
	virtual void on_field_changed(sqc_tool_context &ctx, sqc_coord_convertor &coord_onv) {
	}
    virtual bool is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx ) {
        return false;
    }

protected:
	void	show_object_bubble( sqc_game_object_ptr object, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
	virtual bool	fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv  );
	
};

END_NAMESPACE_SQC_TOOLS
