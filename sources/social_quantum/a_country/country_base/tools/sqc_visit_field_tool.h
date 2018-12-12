//
//  sqc_visit_field_tool.h
//  aCountry
//
//  Created by Paul  on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef __SQC_VISIT_FIELD_TOOL_H_INCLUDED__
#define __SQC_VISIT_FIELD_TOOL_H_INCLUDED__

#include "sqc_multi_tool.h"

NAMESPACE_SQC_TOOLS

class sqc_visit_field_tool : public sqc_multi_tool {
public:
    virtual sqc_tool_type get_type() const;
    
    virtual bool on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    virtual void on_deactivate( bool apply_changes, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv);
protected:
    virtual sqc_action get_object_action( const sqc_game_object_ptr& object ) const;
};


END_NAMESPACE_SQC_TOOLS

#endif//__SQC_VISIT_FIELD_TOOL_H_INCLUDED__
