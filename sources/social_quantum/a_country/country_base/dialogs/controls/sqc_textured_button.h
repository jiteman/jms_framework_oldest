/*
 *  sqc_textured_button.h
 *  aCountry
 *
 *  Created by Ilya Radinsky on 25.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_TEXTURED_BUTTON_H_INCLUDED__
#define __SQC_TEXTURED_BUTTON_H_INCLUDED__

#include "framework/layout/sqc_layout_defs.h"
#include "country_base/shop/sqc_shop_defs.h"
#include "framework/texture/sqc_texture_builder.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_textured_button : public milk::milk_button 
{
public:
    sqc_textured_button( milk::milk_widget_ptr p );
    
    bool set_texture( const sqc_string& name );

protected:
    virtual void render( surf::surf_context_ptr ctx );

public:
	sqc_texture_ptr     m_texture;
};

typedef std::tr1::shared_ptr<sqc_textured_button>	sqc_textured_button_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__SQC_TEXTURED_BUTTON_H_INCLUDED__


