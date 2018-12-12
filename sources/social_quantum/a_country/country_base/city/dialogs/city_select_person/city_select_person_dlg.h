/*
 *  city_select_person_dlg.h
 *  aCountry
 *
 *  Created by Василий on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_SELECT_PERSON_DLG_H_INCLUDED__
#define __SQC_CITY_SELECT_PERSON_DLG_H_INCLUDED__

#include "country_base/sqc_framework_base.h"
#include "city/dialogs/city_base_dlg.h"
#include "country_base/dialogs/select_person/sqc_select_person_dlg.h"
#include "country_base/dialogs/controls/sqc_person_cell.h"
#include "city_select_person_dlg_layout.h"


NAMESPACE_SQC_FRAMEWORK

class city_select_person_dlg : public sqc_select_person_dlg {

public:
	city_select_person_dlg( milk::milk_widget_ptr p, 
                           sqc_select_preson_delegate_ptr delegate );
    void on_init_dialog();
    milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
  
    void    on_person_selected( const sqc_string& person_id );
	bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);
private:
};

typedef std::tr1::shared_ptr<city_select_person_dlg> city_select_person_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif
