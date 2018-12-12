/*
 *  sqc_tools_common.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

bool sqc_tool::on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    ctx.hide_bubble();
    return true;
}

void sqc_tool::on_deactivate( bool apply_changes, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
	
}

void	sqc_tool::show_object_bubble( sqc_game_object_ptr object, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
	sqc::framework::sqc_bubble_content content;
	if (fill_bubble_content(object, content, ctx, coord_conv)) {
        surf::surf_rect obj_rect = object->get_display_rect(coord_conv, false);
		surf::surf_point point = surf::surf_point(obj_rect.x + obj_rect.cx/2, obj_rect.top());
        
        ctx.show_bubble( point, content );
	}
}

bool	sqc_tool::fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ){
	return false;
}

END_NAMESPACE_SQC_TOOLS