#pragma once

#include "../../shop/sqc_shop_defs.h"
#include "../../sqc_country_common.h"
#include "../../sqc_country_base_ui.h"


NAMESPACE_SQC_FRAMEWORK

enum sqc_add_money_enum {
	sqc_megabucks_5, 
    sqc_megabucks_15,
    sqc_megabucks_40,
    sqc_megabucks_55,
    sqc_megabucks_80,
    sqc_megabucks_100,

    sqc_coins_12,
    sqc_coins_20,
    sqc_coins_30,
    sqc_coins_60,
    sqc_coins_100,
    sqc_coins_140
};

/// Parameters for add coins dialog
struct sqc_add_money_params {
	typedef std::tr1::function<void(sqc_add_money_enum money)> add_money_callback_t;
    add_money_callback_t	add_money_callback;
};


struct sqc_shop_category_params {
	// if callback return true - dialog should be closed
    // otherwise buy operation is failed
	typedef std::tr1::function<bool(const sqc_string& object_type)>
    													buy_callback_t;
	typedef std::tr1::function<bool(const sqc_string& object_type,
    								const sqc_string& second_user )>
    													gift_callback_t;

	sqc_shop_category_params()
    	: shop_category( sqc_shop_category_unknown ) {
    }
    
    buy_callback_t          buy_callback;
    gift_callback_t			gift_callback;
    sqc_shop_category       shop_category;
    sqc_common_scene_info   scene_info;
    sqc_add_money_params	add_money;
};

struct sqc_shop_categories_params {

	sqc_shop_category_params	category_params;
};

struct sqc_game_setting_params {
};


/// Parameters for Refill dialog
struct sqc_refill_params {
	// parameters: amount, buy/gift
    typedef std::tr1::function<void(int, bool)> refill_money_callback_t;
    refill_money_callback_t		refill_money_callback;
};

struct sqc_main_menu_params {
	sqc_shop_categories_params	shop_categories_params;	
    sqc_game_setting_params		game_setting_params;
	sqc_add_money_params		add_money;
};

struct sqc_shop_contract_params {
	typedef std::tr1::function<bool(const sqc_string& object_type)>
    buy_callback_t;
    
    buy_callback_t          buy_callback;
    sqc_string              factory_type;
    sqc_common_scene_info   scene_info;
};

struct sqc_shop_construction_params {
	typedef std::tr1::function<bool(const sqc_string& object_type)>
    buy_callback_t;
    
    buy_callback_t          buy_callback;
    sqc_string              construction_type;
    sqc_common_scene_info   scene_info;
};

struct sqc_shop_material_params {
	typedef std::tr1::function<bool(const sqc_string& object_type)>
    buy_callback_t;
    
    typedef std::tr1::function<void(sqc_string_map &input_fill)>
    input_fill_callback_t;
    
    buy_callback_t          buy_callback;
    input_fill_callback_t   input_fill_callback;
    sqc_string              buildsite_type;
    sqc_common_scene_info   scene_info;
};


END_NAMESPACE_SQC_FRAMEWORK
