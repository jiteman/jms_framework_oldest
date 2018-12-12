#pragma once

#include "../../framework/sqc_framework_defs.h"
#include "../../sqc/sqc_base.h"
#include <functional>

namespace sqc {
    namespace tools {
        struct sqc_action_params;
    }
}

NAMESPACE_SQC_FRAMEWORK

static const char sqc_bubble_time_marker[] = "<HHh:MMm:SSs>"; 
static const size_t sqc_bubble_time_marker_length = sizeof(sqc_bubble_time_marker)-1;

typedef std::tr1::shared_ptr<tools::sqc_action_params> sqc_action_params_ptr;

struct sqc_bubble_element {
	sqc_string              tag;
	sqc_string              icon;
	int                     value;
	sqc_string              text;
	sqc::sqc_action         action;
    sqc_action_params_ptr   params; /// Nessesary params for running of action
    
	sqc_bubble_element() : value(0), action(action_nop) {
	}
    
    template<typename T>
    void add_value(const sqc_string& key, const T& value) {
        std::ostringstream iss;
        iss << value;
        map_insert(key, iss.str());
    }
    
    void add_value(const sqc_string& key, const sqc_string& value) {
        map_insert(key, value);
    }
    
    template<typename T>
    bool get_value(const sqc_string& key, T& value) const {
        sqc_string_map::const_iterator strval = values.find(key);
        if(strval == values.end())
            return false;
        
        convert((*strval).second, value);
        
        return false;
    }
    
private:
    typedef std::map<sqc_string, sqc_string> sqc_string_map;
    
    void map_insert(const sqc_string& key, const sqc_string& value);
    
    template<typename T>
    void convert(const sqc_string& strval, T& val) const {
        std::istringstream iss(strval);
        iss >> val;
    }
    
    void convert(const sqc_string& strval, sqc_string& val);
    
    sqc_string_map values;
};

struct sqc_bubble_content {
	std::vector<sqc_bubble_element>	elements;
	typedef std::tr1::function<void(sqc_action, const sqc_action_params_ptr &)> action_callback_t;
	action_callback_t	action_callback;
	sqc::sqc_action	default_action;
	sqc_bubble_content() : default_action( action_nop ) {
	}
};

END_NAMESPACE_SQC_FRAMEWORK
