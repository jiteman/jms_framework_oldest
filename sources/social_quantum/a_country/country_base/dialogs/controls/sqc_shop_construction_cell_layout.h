/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_ITEM_CONSTRUCTION_CELL_LAYOUT_H_INCLUDED__
#define __SQC_SHOP_ITEM_CONSTRUCTION_CELL_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace shop_construction_cell {
    //////////////////////////////////////////////////////////

    static const image_layout 
    build_lock_image( // layout by spinboard cell
                     layout_alignment( layout_halignment_center |
                                     layout_valignment_center),
                     image_names( "build_lock",
                                 "build_lock@2x",
                                 "build_lock_ipad" ),
                     image_rects( 
                                 layout_rect( 0, 0, 125, 27 ),
                                 layout_rect( 0, 0, 250, 54 ),
                                 layout_rect( 0, 0, 145, 50 ) ) );

    // available caption
    static const font_layout 
    available_label_font(
                        layout_font_name( "Arial.otf" ), //Arial
                        layout_font_sizes( 11, 2*11, 18 ) );
    
    static const label_layout
    available_label( // layout by lock image
                   layout_alignment( layout_halignment_center |
                                   layout_valignment_fill ),
                   layout_string_resource( "*CityRequiredLevel",
                                          "Required level" ),
                   layout_black_color,
                   draw_flags_hcenter_vcenter,
                   available_label_font,
                   label_rects( layout_rect( 0, 0, 50, 0 ),
                               layout_rect( 0, 0, 2*50, 0 ),
                               layout_rect( 0, 0, 50, 0 ) ) );

    static const label_layout
    level_label( // layout by lock image
                    layout_alignment( layout_halignment_right |
                                    layout_valignment_fill ),
                    layout_string_resource( "", "" ),
                    layout_black_color,
                    draw_flags_hcenter_vcenter,
                    available_label_font,
                    label_rects( layout_rect( 0, 5, 20, 0 ),
                                layout_rect( 0, 2*5, 2*20, 0 ),
                                layout_rect( 0, 5, 20, 0 ) ) );

    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_CONSTRUCTION_ITEM_CELL_LAYOUT_H_INCLUDED__


