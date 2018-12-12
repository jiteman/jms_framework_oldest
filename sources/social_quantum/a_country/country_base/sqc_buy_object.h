#ifndef SQC_BUY_OBJECT_H_INCLUDED
#define SQC_BUY_OBJECT_H_INCLUDED

#include "sqc_base.h"

NAMESPACE_SQC

class sqc_buy_object : public sqc_game_object {
public:
    sqc_buy_object( sqc_size const &s );
    
    virtual void render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg );
    virtual sqc_action get_default_action() const;
    
    virtual sqc_size get_size() const;
    
	virtual bool fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner );
    
    sqc_size    my_size;
};

END_NAMESPACE_SQC

#endif //SQC_BUY_OBJECT_H_INCLUDED