/*
 *  sqc_gift_delegate.h
 *  aCountry
 *
 *  Created by Paul K on 11.10.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SQC_GIFT_DELEGATE_H_INCLUDED__
#define __SQC_SQC_GIFT_DELEGATE_H_INCLUDED__

#include "country_base/sqc_country_common.h"


NAMESPACE_SQC_FRAMEWORK

class sqc_gift_delegate {
public:

public:
    virtual void	get_scene_info( sqc_common_scene_info& info ) = 0;
    
    virtual bool	get_received_gifts( sqc_received_gift::vector& gifts ) = 0;
    virtual bool	get_available_gifts( sqc_available_gift::vector& gifts ) = 0;
    virtual bool	get_wishes_gifts( sqc_wishes::vector& gifts ) = 0;
    
    virtual sqc_shop_category_item_ptr	convert_received_gift( sqc_received_gift::sptr ptr_gift ) = 0;
	virtual sqc_shop_category_item_ptr	convert_available_gift( sqc_available_gift::sptr ptr_gift ) = 0;
    virtual sqc_shop_category_item_ptr	convert_wishes_gift( sqc_wishes::sptr ptr_gift ) = 0;

	virtual bool	sell_gift( sqc_received_gift::sptr ptr ) = 0;
	virtual bool	receive_gift( sqc_received_gift::sptr ptr ) = 0;
	virtual bool	send_gift( sqc_available_gift::sptr ptr ) = 0;
  	virtual bool	send_gift( sqc_wishes::sptr ptr ) = 0;
};

typedef std::tr1::shared_ptr<sqc_gift_delegate> sqc_gift_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SQC_GIFT_DELEGATE_H_INCLUDED__