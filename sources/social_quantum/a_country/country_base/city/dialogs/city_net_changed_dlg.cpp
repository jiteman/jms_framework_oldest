/*
 *  city_net_changed_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 21.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_net_changed_dlg.h"
#include "city/city_framework.h"

NAMESPACE_SQC_FRAMEWORK

    
void city_net_changed_dlg::on_init_dialog()
{
    sqc_dialog_with_close::on_init_dialog();
    
    sqc_window_factory& factory = framework().windows_factory();
    
    const sqc_theme_size theme = factory.get_theme_size();
    
    using namespace city_dlg_layout::net_changed_layout;
    
    
    // create images
    factory.create_image( m_window_ctx, shared_from_this(), enter_image_img );

    
    // create title
    set_caption( framework().strings().load( 
                                            city_dlg_layout::net_changed_layout::string_enter_caption.resource_id(),
                                            city_dlg_layout::net_changed_layout::string_enter_caption.def_value() ) );
                                            
    //
    // create labels
    //
    
    //upper message
    milk::milk_label_ptr ptr_label_upper_message = 
    factory.create_label(
                         m_window_ctx, 
                         shared_from_this(),
                         label_upper_message
                         );	                        
    
    const sqc_network_type nt = framework().networks().current_network();
    const sqc_string net_name = framework().networks().get_network_name(nt);
    
    ptr_label_upper_message->set_caption(
                                       format(framework().strings().load(string_enter_upper_message.resource_id(),
                                                                         string_enter_upper_message.def_value()),
                                                                         net_name.c_str())
                                       );    
    // other labels                                
    factory.create_label( m_window_ctx, shared_from_this(), label_lower_message );
    factory.create_label( m_window_ctx, shared_from_this(), label_enter_step_1 );
    factory.create_label( m_window_ctx, shared_from_this(), label_enter_step_2 );
    factory.create_label( m_window_ctx, shared_from_this(), label_enter_step_3 );
    
    // create separators
    milk::milk_widget_ptr parent;
    for(sqc_word i = 0; i < 3; i++)
    {   
        parent = shared_from_this()->create_child<milk::milk_widget>( separator_rects[i].at(theme) );
        factory.create_image( m_window_ctx, parent, separator_img  );
    }
    
    // cretae step numbers
    milk::milk_label_ptr ptr_label;
    for(sqc_word step = 0; step < 3; step++)
    {   
        parent = shared_from_this()->create_child<milk::milk_widget>( step_rects[step].at(theme) );
        
        ptr_label = factory.create_label(
                                         m_window_ctx, 
                                         parent,
                                         label_step_number
                                         );	
        ptr_label->set_caption(
                              format(
                                     framework().strings().load(string_step_number.resource_id(),
                                     string_step_number.def_value()),
                                     step + 1));
    }
    
}

END_NAMESPACE_SQC_FRAMEWORK