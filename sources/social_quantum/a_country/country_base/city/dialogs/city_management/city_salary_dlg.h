/*
 *  city_salary_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 02.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *  mail: ivan.quantum@yandex.ru
 */
 
 
 
 
#ifndef __SQC_CITY_SALARY_DLG_H_INCLUDED__
#define __SQC_CITY_SALARY_DLG_H_INCLUDED__

#include "city/dialogs/city_base_dlg.h"
#include "city_salary_dlg_layout.h"
#include "framework/notify_center/sqc_notify_center.h"
#include "country_base/dialogs/controls/sqc_item_buttons.h"
#include "city_salary_delegate.h"

NAMESPACE_SQC_FRAMEWORK


// main interface
class city_salary_base_dlg : public sqc_dialog_with_close
{
public:
city_salary_base_dlg( milk::milk_widget_ptr p, city_salary_delegate_ptr delegate )
    : sqc_dialog_with_close( p, city_dlg_layout::salary_dlg::background )
    , m_delegate( delegate ) 
    {
    }
    
protected:
    sqc_theme_size		m_current_theme;
    
    // initialization 
	void on_init_dialog(); // init
	virtual void	on_buy( sqc_salary salary );
    virtual void	on_gift( sqc_salary salary );
    
    // function
    void add_button_click();
    
    city_salary_delegate_ptr	m_delegate;
    
};

typedef std::tr1::shared_ptr<city_salary_base_dlg>	 sqc_salary_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif
