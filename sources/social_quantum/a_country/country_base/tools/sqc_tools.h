#pragma once

#include "../../framework/sqc_framework_defs.h"
#include "../../sqc/sqc_base.h"
#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

typedef std::tr1::shared_ptr<sqc_tool>  sqc_tool_ptr;
typedef std::map<sqc_tool_type, sqc_tool_ptr>   sqc_tool_by_type;


class sqc_tools_controlles {

public:
	sqc_tools_controlles();
	virtual ~sqc_tools_controlles();
    bool activate_tool( sqc_tool_type type, sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    void process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    sqc_tool_type get_active_tool() const;
    virtual bool on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    bool on_timer( sqc_ddword ticks, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv);
	void on_field_changed( sqc_tool_context &ctx, sqc_coord_convertor &coord_conv);
    bool is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx);

protected:
    sqc_tool_by_type    tool_by_type;
    sqc_tool_ptr        active_tool;
};
	
END_NAMESPACE_SQC_TOOLS
