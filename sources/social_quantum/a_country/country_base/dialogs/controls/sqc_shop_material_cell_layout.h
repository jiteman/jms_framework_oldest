/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_ITEM_MATERIAL_CELL_LAYOUT_H_INCLUDED__
#define __SQC_SHOP_ITEM_MATERIAL_CELL_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace shop_material_cell {
    //////////////////////////////////////////////////////////
    // quantity
    static const font_layout 
    quantity_label_font( 
                     layout_font_name( "Arial-BoldMT.otf" ), //Arial
                     layout_font_sizes( 11, 2*11, 18 ) );
    
    static const label_layout
    quantity_label(
                layout_alignment( layout_halignment_fill |
                                layout_valignment_bottom ),
                layout_string_resource( "", "" ),
                layout_black_color,
                draw_flags_hcenter_vbottom,
                quantity_label_font,
                label_rects( layout_rect( 0, 25, 0, 20 ),
                            layout_rect( 0, 2*25, 0, 2*40 ),
                            layout_rect( 0, 40, 0, 40 ) ) );
    
    
    //////////////////////////////////////////////////////////
    // already purchased image
    static const image_layout 
    purchased_image( // layout by backing image
               layout_alignment( layout_halignment_center |
                               layout_valignment_center),
               image_names( "already_purchased_icon",
                           "already_purchased_icon@2",
                           "already_purchased_icon_ipad" ),
               image_rects( 
                           layout_rect( 0, 0, 41, 30 ),
                           layout_rect( 0, 0, 82, 60 ),
                           layout_rect( 0, 0, 68, 52 ) ) );
    
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_MATERIAL_ITEM_CELL_LAYOUT_H_INCLUDED__


