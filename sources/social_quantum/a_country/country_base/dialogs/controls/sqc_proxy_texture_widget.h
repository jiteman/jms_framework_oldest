/*
 *  sqc_texture_image_widget.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_PROXY_TEXTURE_WIDGET_H_INCLUDED__
#define __SQC_PROXY_TEXTURE_WIDGET_H_INCLUDED__

#include "framework/layout/sqc_layout_defs.h"
#include "country_base/shop/sqc_shop_defs.h"
#include "framework/texture/sqc_texture_builder.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_proxy_texture_widget implementation
//
class sqc_proxy_texture_widget : public milk::milk_widget 
{
public:
    sqc_proxy_texture_widget( milk::milk_widget_ptr p );
    virtual ~sqc_proxy_texture_widget();
    
    bool set_local_image( const sqc_string& name );
    bool set_texture( const sqc_string& name );
    bool set_remote_texture( const sqc_string& uri, 
                             const bool consider_social_network = true );

protected:
    void reset();
    virtual void render( surf::surf_context_ptr ctx );

public:
	sqc_texture_ptr         m_texture;
    surf::surf_image_ptr    m_local_image;
};

typedef std::tr1::shared_ptr<sqc_proxy_texture_widget>	sqc_proxy_texture_widget_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__SQC_PROXY_TEXTURE_WIDGET_H_INCLUDED__


