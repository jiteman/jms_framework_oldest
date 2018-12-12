/*
 *  city_common_friends_controller_delegate.h
 *  aCountry
 *
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __CITY_COMMON_FRIENDS_CONTROLLER_DELEGATE_H__
#define __CITY_COMMON_FRIENDS_CONTROLLER_DELEGATE_H__

#include "framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

/// Person info. Contains basic person info
/// locale structure for pass to dialog
struct person_info {
    person_info( sqc_string id_, sqc_string name_,  int level_, sqc_string url_ )
    : userid(id_)
    , name(name_)
    , level(level_)
    , url(url_)
    {
    }
    
    sqc_string	userid;
    sqc_string	name;
    int			level;
    sqc_string 	url;
};

typedef std::vector<person_info> person_info_list_type;

class city_friends_panel_dlg_delegate {
public:
    virtual void on_change_user(sqc_string uid) = 0;
    virtual void on_add_friend() = 0;
    virtual void on_hide() = 0;
    virtual void on_show() = 0;
    virtual person_info_list_type & get_friend_list() = 0;
    
private:

};

END_NAMESPACE_SQC_FRAMEWORK

#endif
