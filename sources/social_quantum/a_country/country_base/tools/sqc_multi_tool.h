/*
 *  sqc_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __SQC_DELETE_TOOL_H_INCLUDED__
#define __SQC_DELETE_TOOL_H_INCLUDED__

#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

class sqc_multi_tool : public sqc_tool {
public:
    virtual sqc_tool_type get_type() const;
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
	virtual bool fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv  );
	virtual void on_field_changed(sqc_tool_context &ctx, sqc_coord_convertor &coord_onv);
protected:
    virtual bool need_show_bubble( const sqc_game_object_ptr& object ) const; 
    virtual sqc_action get_object_action( const sqc_game_object_ptr& object ) const;
private:
	void on_bubble_action( sqc_tool_context &ctx , sqc_action action, const sqc_action_params_ptr& params);
};

END_NAMESPACE_SQC_TOOLS

#endif//__SQC_DELETE_TOOL_H_INCLUDED__
