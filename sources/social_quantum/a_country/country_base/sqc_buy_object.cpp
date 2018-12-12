#include "sqc_buy_object.h"
#include "view/sqc_bubble_def.h"
#include "sqc_framework_base.h"

NAMESPACE_SQC

#ifdef SQC_FARM_GAME
static const bool USE_DEFAULT_BUY_ACTION(false);
#endif

sqc_buy_object::sqc_buy_object( sqc_size const &s ) 
    : sqc_game_object( info::sqc_object_info_ptr() )
    , my_size( s )
{
    
}

void sqc_buy_object::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg ) {
    surf::surf_color clr = ctx->get_color();
    ctx->set_color( clr * surf::surf_color(1,1,0,1) );
    sqc_size    size = my_size;
    surf::surf_point   pos1 = coord_conv.field_to_screen( get_position()+sqc_point( 0, 0 ) );
    surf::surf_point   pos2 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, 0 ) );
    surf::surf_point   pos3 = coord_conv.field_to_screen( get_position()+sqc_point( size.cx, size.cy ) );
    surf::surf_point   pos4 = coord_conv.field_to_screen( get_position()+sqc_point( 0, size.cy ) );
    
    ctx->set_width( 1 );
    
    surf::surf_curve_ptr    curve = ctx->server().create_curve();
    curve->move_to( pos1 );
    curve->line_to( pos2 );
    curve->line_to( pos3 );
    curve->line_to( pos4 );
    
    curve->draw( ctx );
    
    ctx->set_width( 1 );
    ctx->set_color( clr );
}

sqc_action sqc_buy_object::get_default_action() const {
#ifdef SQC_FARM_GAME    
    if(!USE_DEFAULT_BUY_ACTION)
        return action_nop;
#endif    
    return action_build;
}

sqc_size sqc_buy_object::get_size() const {
    return my_size;
}

#ifdef SQC_FARM_GAME
bool sqc_buy_object::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner )
{
    bool result = sqc_game_object::fill_bubble_content( bubble, owner );

    if(USE_DEFAULT_BUY_ACTION)
        return result;
    
    sqc::framework::sqc_bubble_element element_caption;
    element_caption.tag = "button";
    element_caption.text = sqc::framework::framework().strings().load( "*BuyPressTo", "Press to");
    element_caption.action = action_build;
    bubble.elements.push_back( element_caption );
    
    sqc::framework::sqc_bubble_element element;
    element.tag = "button";
    element.text = sqc::framework::framework().strings().load( "*BuyBuild", "build");
    element.action = action_build;
    bubble.elements.push_back( element );
    return true;
}
#endif

#ifdef SQC_CITY_GAME
bool sqc_buy_object::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner ) {
    sqc::framework::sqc_bubble_element element;
    element.tag = "caption";
    element.text = framework::framework().strings().load("*CommonEmptySpace","Empty space"); 
    bubble.default_action = action_build;
    bubble.elements.push_back(element);
    element.tag = "status";
    element.text = framework::framework().strings().load("*CommonClickToBuyHere","Click To Buy Here"); 
    element.icon = "bubble_build";
    bubble.elements.push_back(element);
    return true;
}
#endif

END_NAMESPACE_SQC