/*
 *  sqc_common_resources.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 13.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *  email: vkonnov@yandex.ru
 */


/* -------  FILE DESCRIPTION  ---------- */
/*
 * This component contains common components
 * (like as "strings" for example).
 * After refactoring shoud delete, split, 
 * reimplement or remove this file. 
 * Coz, i just think is bad when the code
 * duplicated.
 */
 
 
 // To do : refactoring this file and contents.
 
#ifndef __SQC_COMMON_RESOURCES_H_INCLUDED__
#define __SQC_COMMON_RESOURCES_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace common_resources
{ 
    static const layout_string_resource
    string_message_wish( "*CityWishTitle", "wish %s" );
    
    static const layout_string_resource
    string_message_back( "*Back", "Back" );
    
    static const layout_string_resource
    string_message_add_coins_and_bucks( "*CityAddCoinsAndBucks", "Add coins and megabucks" );

    static const layout_string_resource
    string_message_gift_you( "*CityGiftSenderTitle", "gift you\n%s" );
    
    static const layout_string_resource
    string_message_no_one_hired("*CityHallNoOneHired", "No one hired");
    
    static const layout_string_resource
    string_message_megabucks("*CityMegabucksOneUppercase", "Megabucks");
    
    static const layout_string_resource
    string_message_shop_expand( "*CityShopExpand", "Expansions" );

    static const layout_string_resource
    string_title_factories("*CityShopFactories", "Factories");
    
    static const layout_string_resource
    string_title_houses( "*CityShopHouses", "Houses" );
    
    static const layout_string_resource
    string_title_leisures( "*CityShopLeisures", "Leisures" );
    
    static const layout_string_resource
    string_title_materials( "*CityShopMaterials", "Materials" );
    
    static const layout_string_resource
    string_title_power( "*CityShopPower", "Power" );
    
    static const layout_string_resource
    string_title_roads( "*CityShopRoads", "Roads" );
    
    static const layout_string_resource
    string_title_terrains( "*CityShopTerrains", "Terrains" );
    
    static const layout_string_resource
    string_title_add_coins("*CommonAddCoins" , "Add coins" );
    
    static const layout_string_resource
    string_text_buy( "*CommonBuyButtonText", "Buy" );
    
    static const layout_string_resource
    string_text_gift( "*CommonGiftButtonText", "Gift" );
    
    static const layout_string_resource
    string_title_choose_net("*CommonNetChoiceLabel", "Choose Net" );
    
    static const layout_string_resource
    string_text_balance( "*CommonYourBalanceText", "Balance:" );
    
    static const layout_string_resource
    string_title_message( "*SimpleMessageTitle", "Message" );
}

END_NAMESPACE_SQC_FRAMEWORK

#endif