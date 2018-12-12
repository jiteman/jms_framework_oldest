#ifndef __SQC_SHOVEL_TOOL_H_INCLUDED__
#define __SQC_SHOVEL_TOOL_H_INCLUDED__

#include "sqc_buy_tool.h"

NAMESPACE_SQC_TOOLS

class sqc_shovel_tool : public sqc_buy_tool {
    
public:
    virtual sqc_tool_type get_type() const;
};
    

END_NAMESPACE_SQC_TOOLS

#endif//__SQC_SHOVEL_TOOL_H_INCLUDED__
