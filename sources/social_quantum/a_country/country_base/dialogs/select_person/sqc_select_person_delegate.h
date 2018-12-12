#pragma once

#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_select_preson_delegate {
public:
    typedef std::tr1::function<void()> persons_ready_callback;

public:
    virtual void    set_persons_ready_callback( persons_ready_callback cb ) = 0;
    virtual void    get_persons( sqc_person_info_list_type& persons ) = 0;
    
    virtual bool    on_person_select( const sqc_string& id ) = 0;

    virtual sqc_string  get_button_caption() = 0;
};

typedef std::tr1::shared_ptr<sqc_select_preson_delegate> sqc_select_preson_delegate_ptr;

sqc_string get_avatar_texture_name( const sqc_string& avatar );

END_NAMESPACE_SQC_FRAMEWORK
