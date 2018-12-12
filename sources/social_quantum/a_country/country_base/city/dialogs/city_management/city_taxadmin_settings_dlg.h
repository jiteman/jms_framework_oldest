/*
 *  city_taxadmin_settings_dlg.h
 *  aCountry dialog header
 *
 *  Created by Bacil on 15.08.2011.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_TAXADMIN_SETTINGS_DLG_H_INCLUDED__
#define __SQC_CITY_TAXADMIN_SETTINGS_DLG_H_INCLUDED__

#include "city_taxadmin_settings_dlg_layout.h"
#include "country_base/sqc_framework_base.h"
#include "city/dialogs/city_base_dlg.h"
#include "country_base/dialogs/controls/sqc_slider.h"
#include "city_tax_admin_delegate.h"

NAMESPACE_SQC_FRAMEWORK


class city_taxadmin_settings_dlg : public sqc_dialog_with_close {
public:
    
	city_taxadmin_settings_dlg( milk::milk_widget_ptr p, city_tax_admin_delegate_ptr delegate )
    : sqc_dialog_with_close( p, city_dlg_layout::taxadmin_settings_dlg::background )
    , m_factory( framework().windows_factory() )
    , m_delegate( delegate )
    , m_base_max_pop_value(0)
    {
        
   	}
    void on_init_dialog();
    void on_slider_change(float p);
    void on_ok();
private:
    
protected:
    
	sqc_window_factory& m_factory;
    milk::milk_label_ptr m_lbl_population;
    sqc_slider_ptr		 m_slider;
    
    city_tax_admin_delegate_ptr	m_delegate;
    int m_base_max_pop_value;
};


typedef std::tr1::shared_ptr<city_taxadmin_settings_dlg> city_taxadmin_settings_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif

