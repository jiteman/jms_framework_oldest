/*
 *  city_gift_wish_dlg.h
 *  aCountry
 *
 *  Created by Paul K on 11.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */
 
#ifndef __SQC_CITY_GIFT_WISH_DLG_H_INCLUDED__
#define __SQC_CITY_GIFT_WISH_DLG_H_INCLUDED__
 
#include "../city_base_dlg.h"
#include "city_gift_wish_dlg_layout.h"
#include "country_base/dialogs/controls/sqc_balance_widget.h"
#include "country_base/dialogs/controls/sqc_shop_item_cell.h"
#include "country_base/dialogs/gift_wish/sqc_gift_delegate.h"
 
NAMESPACE_SQC_FRAMEWORK
 
 
//
// Pages
//

class city_abstract_page_dlg :
  public sqc_dialog_page
 ,public milk::milk_spinboard_callbacks
{
public:
    
	city_abstract_page_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate );
	
    virtual void on_init();
    virtual void get_items() = 0;
    
    
    // milk_spinboard_callbacks interface
    virtual sqc_int get_cell_count() = 0;
    virtual milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect ) = 0;
    virtual bool fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                        const sqc_shop_category_item_ptr item );
    
    
protected:
    sqc_shop_category_items     m_items;
    milk::milk_spinboard_ptr    m_spinboard;
    sqc_common_scene_info		m_scene_info;
    sqc_gift_delegate_ptr       m_gift_delegate;
    sqc_word                    m_cell_visible_count;
    sqc_dialog_ptr				m_dialog;

};


class city_wish_dlg : public city_abstract_page_dlg
{
public:
    
	city_wish_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate  );
	
    void get_items();
    
    // base-virtual
    sqc_int get_cell_count();
    milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    
    
protected:
    void on_gift_button_pressed(sqc_wishes::sptr ptr);
    
    sqc_wishes::vector	m_wishes_gifts;
};

class city_received_dlg : public city_abstract_page_dlg
{
public:
    
	city_received_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate);
	
    void get_items();
    // base-virtual
    sqc_int get_cell_count();
    milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    
protected:
    void on_received_button_pressed(sqc_received_gift::sptr ptr);
    void on_sell_button_pressed(sqc_received_gift::sptr ptr);
        
    sqc_received_gift::vector	m_received_gifts;
};

class city_available_dlg : public city_abstract_page_dlg
{
public:
    
	city_available_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate  );
		
    void get_items();
    
    // base-virtual
    sqc_int get_cell_count();
    milk::milk_widget_ptr create_cell( sqc_int idx, surf::surf_rect const &rect );
    
protected:
    void on_gift_button_pressed(sqc_available_gift::sptr ptr);
    
    sqc_available_gift::vector	m_available_gifts;
}; 
 


//
// Main dialog
//
class city_gift_wish_dlg
    : public sqc_dialog_with_close {
public:
    city_gift_wish_dlg( milk::milk_widget_ptr p, sqc_gift_delegate_ptr gift_delegate )
        : sqc_dialog_with_close(p, city_dlg_layout::gift_wish_layout::background)
        , m_gift_delegate( gift_delegate ){
    }
     
    virtual void on_init_dialog();
	virtual void on_post_init_dialog();
     
protected:
        sqc_word get_availabel_cell_count();
        sqc_word get_received_cell_count();
        sqc_word get_wish_cell_count();
		
    bool get_dialog_init_arg(milk::milk_dialog_init_arg& a);    
protected:
    sqc_gift_delegate_ptr		m_gift_delegate;
    
    // tabs
  	surf::surf_dword            m_available_page;
   	surf::surf_dword            m_received_page;
  	surf::surf_dword            m_wish_page;
};
 
typedef std::tr1::shared_ptr<city_gift_wish_dlg>     city_gift_wish_dlg_ptr;
 
END_NAMESPACE_SQC_FRAMEWORK
 
#endif//__SQC_CITY_GIFT_WISH_DLG_H_INCLUDED__
