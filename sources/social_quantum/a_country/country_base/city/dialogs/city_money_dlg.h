/*
 *  city_add_money.h
 *  aCountry
 *
 *  Created by Василий on 27.07.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_MONEY_DLG_H_INCLUDED__
#define __SQC_CITY_MONEY_DLG_H_INCLUDED__


#include "city_base_dlg.h"
#include "city_money_dlg_layout.h"
#include "framework/notify_center/sqc_notify_center.h"
#include "country_base/dialogs/controls/sqc_item_buttons.h"
#include "city_dialogs_params.h"

NAMESPACE_SQC_FRAMEWORK

/// Service item class
class money_barter_item {
public:
	money_barter_item(int amount, double price) 
    	: m_amount(amount), m_price(price) 
    { }
	double get_price() {
    	return m_price;
    }

	int get_amount() {
    	return m_amount;
    }
	
private:
	int m_amount;
    double m_price;
};

/// Class provides conversion Megabucks in coins and vice versa
class money_barter {
typedef std::map<sqc_add_money_enum, money_barter_item> items_map_t;
public:

	money_barter() {
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_5, money_barter_item(5, 1.99) ) );
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_15, money_barter_item(15, 3.99) ) );
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_40, money_barter_item(40, 6.99) ) );
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_55, money_barter_item(55, 8.99) ) );
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_80, money_barter_item(80, 11.99) ) );
    	m_map.insert ( items_map_t::value_type( sqc_megabucks_100, money_barter_item(100, 13.99) ) );

    	m_map.insert ( items_map_t::value_type( sqc_coins_12, money_barter_item(12000, 5) ) );
    	m_map.insert ( items_map_t::value_type( sqc_coins_20, money_barter_item(20000, 8) ) );
    	m_map.insert ( items_map_t::value_type( sqc_coins_30, money_barter_item(30000, 10) ) );
    	m_map.insert ( items_map_t::value_type( sqc_coins_60, money_barter_item(60000, 15) ) );
    	m_map.insert ( items_map_t::value_type( sqc_coins_100, money_barter_item(100000, 20) ) );
    	m_map.insert ( items_map_t::value_type( sqc_coins_140, money_barter_item(140000, 25) ) );
    }
    
    money_barter_item get_item(sqc_add_money_enum item) {
    	return m_map.find(item)->second;
    }
private:
    items_map_t m_map;
    double m_price;
    double rate;
};


enum city_money_t {
    city_coins, city_bucks
};

class money_dlg;

//
// city_game_setting_dlg implementation
//

class city_buy_money_base_page : public sqc_dialog_page {
public:
    
	city_buy_money_base_page( sqc_dialog_ptr p,
                             city_money_t dlg_kind,
                             const sqc_add_money_params &params );
	
	void on_init(); // initialization 
	void on_end();
	
	void show_page();
    void create_tab_sheet();
	
    void on_switch_tab(city_money_t pos );

protected:
    void on_buy_item_pressed(sqc_add_money_enum item);
    city_money_t m_money;
	sqc_add_money_params m_add_money_params;
protected:
    
};

class city_buy_bucks_page : public city_buy_money_base_page {
public:
	city_buy_bucks_page( sqc_dialog_ptr p, const sqc_add_money_params &params )
    	: city_buy_money_base_page(p,  city_bucks, params )

    { 
    }
};

class city_buy_coins_page : public city_buy_money_base_page {
public:
	city_buy_coins_page( sqc_dialog_ptr p,  const sqc_add_money_params &params )
    	: city_buy_money_base_page(p, city_coins, params)
    { 
    }
};

/// Сlass switch dialog panels
class money_dlg : public sqc_dialog {
public:
	money_dlg(milk::milk_widget_ptr p, const sqc_add_money_params &params);
	
	void on_init_dialog();
	
    void switch_coins();
    void switch_megabucks();
	virtual void do_modal();

protected:
	virtual bool get_dialog_init_arg( milk::milk_dialog_init_arg &arg );
private:
	bool m_modal;
    sqc_add_money_params m_params;
	surf::surf_dword m_bucks_page;
	surf::surf_dword m_coins_page;
};

typedef std::tr1::shared_ptr<money_dlg> money_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK


#endif
