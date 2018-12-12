/*
 *  city_net_changed_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 21.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_NET_CHANGED_DLG_H_INCLUDED__
#define __SQC_CITY_NET_CHANGED_DLG_H_INCLUDED__


#include "city_base_dlg.h"
#include "city_net_changed_layout.h"

NAMESPACE_SQC_FRAMEWORK

class city_net_changed_dlg : public sqc_dialog_with_close
{
public:
    city_net_changed_dlg( milk::milk_widget_ptr p)
    : sqc_dialog_with_close( p, city_dlg_layout::net_changed_layout::background ) 
    {
    }
    
protected:
    
    // initialization 
	void on_init_dialog(); // init
};

typedef std::tr1::shared_ptr<city_net_changed_dlg>	 city_net_changed_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif