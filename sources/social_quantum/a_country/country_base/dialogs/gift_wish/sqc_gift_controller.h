/*
 *  sqc_gift_controller.h
 *  aCountry
 *
 *  Created by Paul K on 11.10.11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */
 
 
#ifndef __SQC_GIFT_CONTROLLER_H_INCLUDED__
#define __SQC_GIFT_CONTROLLER_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "country_base/shop/sqc_shop_defs.h"
#include "country_base/sqc_game_base.h"
#include "country_base/commands/sqc_command_processor.h"

#include "sqc_gift_delegate.h"

NAMESPACE_SQC_FRAMEWORK


class sqc_gift_controller
    : public sqc_noncopyable
    , public sqc_gift_delegate {
public:
    sqc_gift_controller();
    virtual ~sqc_gift_controller();

    virtual void	get_scene_info( sqc_common_scene_info& info );
    
    virtual bool	get_received_gifts( sqc_received_gift::vector& gifts );
    virtual bool	get_available_gifts( sqc_available_gift::vector& gifts );
    virtual bool	get_wishes_gifts( sqc_wishes::vector& gifts );
    
    virtual sqc_shop_category_item_ptr	convert_received_gift( sqc_received_gift::sptr ptr_gift );
	virtual sqc_shop_category_item_ptr	convert_available_gift( sqc_available_gift::sptr ptr_gift );
    virtual sqc_shop_category_item_ptr	convert_wishes_gift( sqc_wishes::sptr ptr_gift );
    
	virtual bool	sell_gift( sqc_received_gift::sptr ptr );
	virtual bool	receive_gift( sqc_received_gift::sptr ptr );
	virtual bool	send_gift( sqc_available_gift::sptr ptr );
   	virtual bool	send_gift( sqc_wishes::sptr ptr );
    
    bool			on_select_user_for_gift( const sqc_string& user_id, sqc_available_gift::sptr ptr );
protected:
	sqc_game_ptr 	get_game();
};

END_NAMESPACE_SQC_FRAMEWORK

#endif /*__SQC_GIFT_CONTROLLER_H_INCLUDED__*/