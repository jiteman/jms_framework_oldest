#pragma once

#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_construction {

public:
	sqc_construction( const sqc_int item_id, 
    				  const sqc_string&	name, 
                      const sqc_string& image_name ) 
        : m_item_id( item_id )
    	, m_name( name )
        , m_image_name( image_name ) {
    }
    
    sqc_int	item_id() const {
    	return m_item_id;
    }
    const	sqc_string&	name() {
    	return m_name;
    }
	const	sqc_string&	image_name() {
    	return m_image_name;
    }
    
protected:
	sqc_int			m_item_id;
	sqc_string		m_name;
    sqc_string		m_image_name;
};

typedef std::tr1::shared_ptr<sqc_construction> sqc_construction_ptr;
typedef std::vector<sqc_construction_ptr>	sqc_constructions;

class sqc_select_construction_delegate {

public:
	virtual sqc_string	get_dialog_caption() = 0;
	virtual sqc_string	get_dialog_item_name() = 0;
    virtual sqc_string	get_dialog_item_descr() = 0;
    virtual sqc_string	get_dialog_item_image() = 0;
    
    virtual void    	get_constructions( sqc_constructions& constructions ) = 0;
    virtual bool		on_select_construction( sqc_construction_ptr ptr_construction ) = 0;

};

typedef std::tr1::shared_ptr<sqc_select_construction_delegate> sqc_select_construction_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK
