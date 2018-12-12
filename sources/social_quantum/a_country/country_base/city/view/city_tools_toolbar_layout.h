//
//  city_tools_toolbar_layout.h
//  aCountry
//
//  Created by Andrey Kunitsyn on 10/27/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef aCountry_city_tools_toolbar_layout_h
#define aCountry_city_tools_toolbar_layout_h

NAMESPACE_SQC_CITY
//struct image_info
namespace city_country_view_layout {
    
namespace tools {
    
    static const layout_alignment layout( 
                                         layout_halignment_right|layout_valignment_bottom );
    
    static const toolbar_button_layout delete_button(
                                                     image_names( "guiButtonDelete", "guiButtonDelete_HD", "guiButtonDelete_iPad" ),
                                                     image_names( "guiButtonDeleteOn", "guiButtonDeleteOn_HD", "guiButtonDeleteOn_iPad" ),
                                                     image_names( "guiButtonDeleteNA", "guiButtonDeleteNA_HD", "guiButtonDeleteNA_iPad" ) );
    
    static const toolbar_button_layout move_button(
                                                   image_names( "guiButtonRotate", "guiButtonRotate_HD", "guiButtonRotate_iPad" ),
                                                   image_names( "guiButtonRotateOn", "guiButtonRotateOn_HD", "guiButtonRotateOn_iPad" ),
                                                   image_names( "guiButtonRotateNA", "guiButtonRotateNA_HD", "guiButtonRotateNA_iPad" ) );
    
    static const toolbar_button_layout apply_button(
                                                    image_names( "guiButtonApply", "guiButtonApply_HD", "guiButtonApply_iPad" ),
                                                    image_names( "guiButtonApplyOn", "guiButtonApplyOn_HD", "guiButtonApplyOn_iPad" ),
                                                    image_names( "guiButtonApplyNA", "guiButtonApplyNA_HD", "guiButtonApplyNA_iPad" ) );
    
    static const toolbar_button_layout cancel_button(
                                                     image_names( "guiButtonCancel", "guiButtonCancel_HD", "guiButtonCancel_iPad" ),
                                                     image_names( "guiButtonCancelOn", "guiButtonCancelOn_HD", "guiButtonCancelOn_iPad" ),
                                                     image_names( "guiButtonCancelOn", "guiButtonCancelOn_HD", "guiButtonCancelOn_iPad" ) );
    
    static const toolbar_button_layout warehouse_button(
                                                        image_names( "buttton_warehouse_normal",   "buttton_warehouse_normal@2x",   "buttton_warehouse_normal_ipad" ),
                                                        image_names( "buttton_warehouse_selected", "buttton_warehouse_selected@2x", "buttton_warehouse_selected_ipad" ),
                                                        image_names( "buttton_warehouse_disabled", "buttton_warehouse_disabled@2x", "buttton_warehouse_disabled_ipad" ) );
    
    static const toolbar_button_layout market_button(
                                                     image_names( "button_market_normal",   "button_market_normal@2x",   "button_market_normal_ipad" ),
                                                     image_names( "button_market_selected", "button_market_selected@2x", "button_market_selected_ipad" ),
                                                     image_names( "guiButtonMarketNA", "guiButtonMarketNA_HD", "guiButtonMarketNA_iPad" ) );
} // namespace tools

} // namespace city_country_view_layout

END_NAMESPACE_SQC_CITY

#endif
