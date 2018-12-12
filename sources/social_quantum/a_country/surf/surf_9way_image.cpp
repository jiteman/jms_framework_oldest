#include "surf_9way_image.h"

NAMESPACE_SURF

surf_9way_image::surf_9way_image() {
    offset_left = 0;
    offset_right = 0;
    offset_top = 0;
    offset_bottom = 0;
    tile_flag = tile_flag_both;
}

bool surf_9way_image::create( const char *resource_id, surf_9way_info const &info, surf::surf_graphics_server &graphics_server ) {
    offset_left = info.offset_left;
    offset_top = info.offset_top;
    offset_right = info.offset_right;
    offset_bottom = info.offset_bottom;
    tile_flag = info.tile_flag;
	draw_center = info.draw_center;
    
    image_corners = graphics_server.create_image( resource_id );
    
    if( !image_corners ) {
        return false;
    }
    if ( tile_flag == tile_flag_none ) {
		return true;
	}
	
    surf::surf_nsize    size = image_corners->get_size();
    surf::surf_create_image_info    create_info;
    //create_info.reduce_bitwidth = true;
    create_info.clip_image = true;
    
    
    if( offset_left ) {
        create_info.source_rect.x = 0;
        create_info.source_rect.y = offset_top;
        create_info.source_rect.cx = offset_left;
        create_info.source_rect.cy = size.cy - offset_top - offset_bottom;
        image_left = graphics_server.create_image_ex( resource_id, create_info );
    }
    
    if( offset_top ) {
        create_info.source_rect.x = offset_left;
        create_info.source_rect.y = 0;
        create_info.source_rect.cx = size.cx - offset_left - offset_right;
        create_info.source_rect.cy = offset_top;
        image_top = graphics_server.create_image_ex( resource_id, create_info );
    }
    
    if( offset_right ) {
        create_info.source_rect.x = size.cx - offset_right;
        create_info.source_rect.y = offset_top;
        create_info.source_rect.cx = offset_right;
        create_info.source_rect.cy = size.cy - offset_top - offset_bottom;
        image_right = graphics_server.create_image_ex( resource_id, create_info );
    }
    
    if( offset_bottom ) {
        create_info.source_rect.x = offset_left;
        create_info.source_rect.y = size.cy - offset_bottom;
        create_info.source_rect.cx = size.cx - offset_left - offset_right;
        create_info.source_rect.cy = offset_bottom;
        image_bottom = graphics_server.create_image_ex( resource_id, create_info );
    }
    
	if ( info.draw_center ) {
		create_info.source_rect.x = offset_left;
		create_info.source_rect.y = offset_top;
		create_info.source_rect.cx = size.cx - offset_left - offset_right;
		create_info.source_rect.cy = size.cy - offset_top - offset_bottom;
		image_center = graphics_server.create_image_ex( resource_id, create_info );
	}
    
    return true;
}

void surf_9way_image::draw( surf::surf_context_ptr ctx, surf::surf_rect const &rect ) {
    if( !image_corners ) {
        return;
    }
    
    surf::surf_nsize    size = image_corners->get_size();
    surf::surf_rect rect_to;
    
    // bottom-left
	if ( (offset_left > 0) && (offset_bottom > 0) ) {
		image_corners->draw( ctx, 
                        surf::surf_rect( rect.x, rect.y, offset_left, offset_bottom), 
                        surf::surf_rect( 0, size.cy - offset_bottom, offset_left, offset_bottom ), 
                        surf::tile_flag_none );
	}
    
    // bottom-right
	if ( (offset_right > 0) && (offset_bottom > 0) ) {
		image_corners->draw( ctx, 
                        surf::surf_rect( rect.x + rect.cx - offset_right, rect.y, offset_right, offset_bottom), 
                        surf::surf_rect( size.cx-offset_right, size.cy - offset_bottom, offset_right, offset_bottom ),
                        surf::tile_flag_none );
	}
    // top-left
	if ( (offset_left > 0) && (offset_top > 0) ) {
		image_corners->draw( ctx, 
                        surf::surf_rect( rect.x, rect.y + rect.cy - offset_top, offset_left, offset_top), 
                        surf::surf_rect( 0, 0, offset_left, offset_top ),
                        surf::tile_flag_none );
	}
    // top-right
	if ( (offset_right > 0) && (offset_top > 0) ) {
		image_corners->draw( ctx, 
                        surf::surf_rect( rect.x + rect.cx - offset_right, rect.y + rect.cy - offset_top, offset_right, offset_top), 
                        surf::surf_rect( size.cx - offset_right, 0, offset_right, offset_top ),
                        surf::tile_flag_none );
	}
    if (tile_flag == tile_flag_none) {
		/// left
		if (offset_left>0) {
			image_corners->draw( ctx, 
								surf::surf_rect( rect.x, rect.y+offset_bottom, offset_left, rect.cy - offset_top - offset_bottom ),
								surf::surf_rect( 0, offset_top, offset_left, size.cy-offset_top-offset_bottom ),
								surf::tile_flag_none );
		}
		/// right
		if (offset_right>0) {
			image_corners->draw( ctx, 
								surf::surf_rect( rect.x+rect.cx -offset_right, rect.y+offset_bottom, offset_right, rect.cy - offset_top - offset_bottom ),
								surf::surf_rect( size.cx-offset_right, offset_top, offset_right, size.cy-offset_top-offset_bottom ),
								surf::tile_flag_none );
		}
		/// top
		if (offset_top>0) {
			image_corners->draw( ctx, 
								surf::surf_rect( rect.x+offset_left, rect.y+rect.cy-offset_top, rect.cx - offset_left - offset_right, offset_top ), 
								surf::surf_rect( offset_left, 0, size.cx-offset_left-offset_right, offset_top ),
								surf::tile_flag_none );
		}
		/// bottom
		if (offset_bottom>0) {
			image_corners->draw( ctx, 
								surf::surf_rect( rect.x+offset_left, rect.y, rect.cx - offset_left - offset_right, offset_bottom ), 
								surf::surf_rect( offset_left, size.cy-offset_bottom, size.cx-offset_left-offset_right, offset_bottom ),
								surf::tile_flag_none );
		}
		// center
		if ( draw_center ) {
			image_corners->draw( ctx, 
								 surf::surf_rect( rect.x+offset_left, rect.y+offset_bottom, rect.cx - offset_left - offset_right, rect.cy - offset_bottom - offset_top ), 
								surf::surf_rect( offset_left, offset_top, size.cx-offset_left-offset_right, size.cy-offset_top-offset_bottom ),
								surf::tile_flag_none );
		}
	} else {
		// left
		if( image_left )image_left->draw( ctx, 
										 surf::surf_rect( rect.x, rect.y+offset_bottom, offset_left, rect.cy - offset_top - offset_bottom ), 
										 surf::surf_rect( surf_npoint(), image_left->get_size() ),
										 tile_flag );
		// right
		if( image_right )image_right->draw( ctx, 
										   surf::surf_rect( rect.x+rect.cx -offset_right, rect.y+offset_bottom, offset_right, rect.cy - offset_top - offset_bottom ), 
										   surf::surf_rect( surf_npoint(), image_right->get_size() ),
										   tile_flag );
		// top
		if( image_top )image_top->draw( ctx, 
									   surf::surf_rect( rect.x+offset_left, rect.y+rect.cy-offset_top, rect.cx - offset_left - offset_right, offset_top ), 
									   surf::surf_rect( surf_npoint(), image_top->get_size() ),
									   tile_flag );
		// bottom
		if( image_bottom ) image_bottom->draw( ctx, 
											  surf::surf_rect( rect.x+offset_left, rect.y, rect.cx - offset_left - offset_right, offset_bottom ), 
											  surf::surf_rect( surf_npoint(), image_bottom->get_size() ),
											  tile_flag );
		
		// center
		if( image_center ) image_center->draw( ctx, 
											  surf::surf_rect( rect.x+offset_left, rect.y+offset_bottom, rect.cx - offset_left - offset_right, rect.cy - offset_bottom - offset_top ), 
											  surf::surf_rect( surf_npoint(), image_center->get_size() ),
											  tile_flag );
	}
}


END_NAMESPACE_SURF