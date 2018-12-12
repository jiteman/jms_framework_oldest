#pragma once

#include "../sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_animation {
public:
    bool is_ready() {
        return true;
    }
};

typedef std::tr1::shared_ptr<sqc_animation> sqc_animation_ptr;

//
// sqc_animator implementation
//
class sqc_animator {
public:
	sqc_animator() {
	}
	virtual ~sqc_animator() {
	}
};
	
END_NAMESPACE_SQC_FRAMEWORK
