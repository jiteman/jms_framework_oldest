#pragma once

#include "surf_defs.h"
#include "surf_gl.h"

NAMESPACE_SURF

struct surf_9way_info {
    int offset_left;
    int offset_right;
    int offset_top;
    int offset_bottom;
    surf_draw_image_flags  tile_flag;
	bool draw_center;
    
    
    surf_9way_info() : offset_left( 0 ), offset_right( 0 ), offset_top( 0 ), offset_bottom( 0 ),tile_flag(tile_flag_both),draw_center(true)
    {}
    surf_9way_info( int l, int t, surf_draw_image_flags f = tile_flag_both ) : offset_left( l ), offset_right( l ), offset_top( t ), offset_bottom( t ), tile_flag( f ),draw_center(true)
    {}
    surf_9way_info( int l, int t, int r, int b, surf_draw_image_flags f = tile_flag_both ) : offset_left( l ), offset_right( r ), offset_top( t ), offset_bottom( b ), tile_flag( f ),draw_center(true)
    {}
};


class surf_9way_image {
public:
    surf_9way_image();
    bool    create( const char *resource_id, surf_9way_info const &info, surf_graphics_server &graphics_server );
    
    virtual void draw( surf_context_ptr ctx, surf_rect const &rect );
private:
    int offset_left;
    int offset_top;
    int offset_right;
    int offset_bottom;
    
    surf_image_ptr  
        image_left, 
        image_right, 
        image_top, 
        image_bottom, 
        image_center, 
        image_corners;
    
    surf_draw_image_flags tile_flag;
	bool	draw_center;
};

typedef std::tr1::shared_ptr<surf_9way_image>   surf_9way_image_ptr;

END_NAMESPACE_SURF
