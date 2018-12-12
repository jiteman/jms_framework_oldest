/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_tools.h"
#include "sqc_buy_tool.h"
#include "sqc_edit_tool.h"
#include "sqc_multi_tool.h"
#include "sqc_visit_field_tool.h"
#include "sqc_shovel_tool.h"
#include "sqc_seed_tool.h"
#include "framework/sqc_framework.h"


NAMESPACE_SQC_TOOLS

sqc_tools_controlles::sqc_tools_controlles() {
    tool_by_type[tool_type_multi].reset( new sqc_multi_tool() );
    tool_by_type[tool_type_edit].reset( new sqc_edit_tool() );
    tool_by_type[tool_type_buy].reset( new sqc_buy_tool() );
    tool_by_type[tool_type_visit_field].reset( new sqc_visit_field_tool() );
#ifdef SQC_FARM_GAME    
    tool_by_type[tool_type_shovel].reset( new sqc_shovel_tool() );
    tool_by_type[tool_type_seed].reset( new sqc_seed_tool() );
#endif
}

sqc_tools_controlles::~sqc_tools_controlles() {
}

bool sqc_tools_controlles::activate_tool( sqc_tool_type type, sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    sqc_info() << "activate tool: " << print_tool_type( type );
    
    if( active_tool ) {
        if( active_tool->get_type() == type ) {
            sqc_info() << "tool is already activated, re-activate";
            active_tool->on_deactivate( arg.apply_changes, ctx , coord_onv );
            active_tool = sqc_tool_ptr();
        }
    }
    
    sqc_tool_by_type::iterator i = tool_by_type.find( type );
    if( i == tool_by_type.end() ) {
        sqc_error() << "failed  to activate tool because it is not found";
        return false;
    }
    
    if( !i->second->on_activate( arg, ctx, coord_onv ) ) {
        sqc_warning() << "tool activation is rejected by tool";
        return false;
    }

    
    if( active_tool ) {
        active_tool->on_deactivate( arg.apply_changes, ctx , coord_onv );
    }
    
    active_tool = i->second;
    
    // fire tool activated
    // TODO: change to global constant!!!
	sqc::framework::framework().notify_center().fire_event( "framework", "tool_activated", sqc::framework::call_sync );
    
    return true;
}

sqc_tool_type sqc_tools_controlles::get_active_tool() const {
    if( !active_tool ) {
        return tool_type_undefined;
    }
    
    return active_tool->get_type();
}

void sqc_tools_controlles::process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if( !active_tool ) {
        sqc_warning() << "failed to process action " << print_tool_action( action ) << "because no tool is active";
        return;
    }
    sqc_warning() << "tool " << print_tool_type( active_tool->get_type() ) << ", action fired: " << print_tool_action( action );
    active_tool->process_action( action, ctx, coord_conv );
}


bool sqc_tools_controlles::on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if( !active_tool ) {
        return false;
    }
    return active_tool->on_touch_down( point, ctx, coord_conv );
}

bool sqc_tools_controlles::on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if( !active_tool ) {
        return false;
    }
    return active_tool->on_touch_up( point, ctx, coord_conv );
}

bool sqc_tools_controlles::on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if( !active_tool ) {
        return false;
    }
    return active_tool->on_touch_move( point, ctx, coord_conv );
}

bool sqc_tools_controlles::on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if( !active_tool ) {
        return false;
    }
    return active_tool->on_scroll( scroll_pos, ctx, coord_conv );
}
bool sqc_tools_controlles::on_timer( sqc_ddword ticks, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv) {
    if( !active_tool ) {
        return false;
    }
    return active_tool->on_timer( ticks, ctx, coord_conv );
}
void sqc_tools_controlles::on_field_changed( sqc_tool_context &ctx, sqc_coord_convertor &coord_conv) {
	if( !active_tool ) {
        return;
    }
    return active_tool->on_field_changed(ctx, coord_conv);
}

bool sqc_tools_controlles::is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx ) {
    if (!active_tool) {
        return false;
    }
    return active_tool->is_action_avaible(action, ctx);
}

END_NAMESPACE_SQC_TOOLS
