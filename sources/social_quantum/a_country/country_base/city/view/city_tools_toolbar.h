//
//  city_tools_toolbar.h
//  aCountry
//
//  Created by Andrey Kunitsyn on 10/27/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef aCountry_city_tools_toolbar_h
#define aCountry_city_tools_toolbar_h

#include "sqc_city.h"
#include "framework/layout/sqc_layout_defs.h"

NAMESPACE_SQC_CITY

class toolbar_button_layout {
public:
	toolbar_button_layout( const sqc::framework::image_names& unpressed,
                          const sqc::framework::image_names& pressed,
                          const sqc::framework::image_names& disabled )
    :	m_unpressed( unpressed )
    , m_pressed( pressed )
    , m_disabled( disabled ) {
    }
    
	const sqc::framework::image_names& unpressed() const {
    	return m_unpressed;
    }
    
    const sqc::framework::image_names& pressed() const {
    	return m_pressed;
    }
    
    const sqc::framework::image_names& disabled() const {
    	return m_disabled;
    }
protected:
	sqc::framework::image_names	 	m_unpressed;
    sqc::framework::image_names 	m_pressed;
    sqc::framework::image_names 	m_disabled;
};


class sqc_city_tools_toolbar {
public:
	enum button_kind {
        cancel_button,
        apply_button,
        move_button,
    	delete_button,
        warehouse_button,
        market_button,
        count_of,
    };
	typedef std::tr1::function<void(const button_kind kind)>
    toolbar_callback;
    
	sqc_city_tools_toolbar(  );
    virtual ~sqc_city_tools_toolbar();
    
    void	create_buttons( const milk::milk_widget_ptr& parent );
    bool is_visible() const { return m_visible;}
protected:
    void			on_button_clicked( const button_kind kind );
public:
	void			show_toolbar();
    void			hide_toolbar();
	void			enable_buttons( button_kind button, bool enable );
    void			set_action( toolbar_callback callback );
protected:
    milk::milk_image_button_ptr	create_button( const milk::milk_widget_ptr& parent, 
                                              const button_kind btn );
    milk::milk_image_button_ptr	find_button( const button_kind btn );
    const toolbar_button_layout* find_button_layout( const button_kind btn );
    void            set_visible( bool v );
protected:
    milk::milk_image_button_ptr       m_buttons[count_of];
    toolbar_callback                  m_callback;
    bool                              m_visible;
};

typedef std::tr1::shared_ptr<sqc_city_tools_toolbar>    sqc_city_tools_toolbar_ptr;

END_NAMESPACE_SQC_CITY

#endif
