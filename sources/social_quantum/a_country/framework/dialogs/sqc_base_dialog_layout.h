#pragma once

#include "../sqc_framework_defs.h"
#include "../layouts/sqc_layout_defs.h"

NAMESPACE_SQC_FRAMEWORK

enum message_box_anchor_t { 
    message_box_top_title_offset,	  // y is a distance beetwen dialog top and title top
    message_box_top_text_offset,	  // y is a distance beetwen title bottom and text top
    message_box_top_button_offset,	  // y is a distance beetwen text bottom and button top
    message_box_bottom_button_offset, // y is a distance beetwen button bottom and dialog bottom
    message_box_anchor_count_of,
};

typedef layout_points message_box_anchor;

namespace sqc_dlg_layout {
	
};

END_NAMESPACE_SQC_FRAMEWORK
