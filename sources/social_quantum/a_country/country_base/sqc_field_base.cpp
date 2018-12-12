/*
 *  sqc_field_base.cpp
 *  aCountry
 *
 *  Created by Andrey Yamov on 7/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "framework/sqc_framework_defs.h"
#include "sqc_field_base.h"
#include "sqc_zorder_sort.h"
#include "framework/sqc_framework.h"
//
// field
//
NAMESPACE_SQC_FRAMEWORK

sqc_field_base::sqc_field_base( info::sqc_object_info_provider_ptr of ) 
    : m_object_factory( of )
{
    m_objects_no_status = false;
    m_objects_no_animation = false;
}

void sqc_field_base::parse_xml( xml::xml_node_ptr node ) {
    using namespace xml;
    
    //
    // read bounds
    //
    int zero_x = node->get_attribute_int( "zero_x" );
    int zero_y = node->get_attribute_int( "zero_y" );
    int size_x = node->get_attribute_int( "size_x" );
    int size_y = node->get_attribute_int( "size_y" );
    
    sqc_string  bounds_entry = node->get_attribute( "bounds" );
    
    m_bounds.clear();
    m_bounds.push_back( sqc_rect( zero_x, zero_y, size_x-zero_x, size_y-zero_y ) );
    
    
    //
    // read objects
    //
    std::map<int, sqc_game_object_list::iterator>   current_objects;
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        current_objects[(*i)->get_id()] = i;
    }
    
    xml_node_list  childs;
    node->get_childs( childs );
    
    bool    need_zorder = false;
    
    for( xml_node_list::const_iterator i = childs.begin(); i != childs.end(); ++i ) {
        xml_node_ptr    child_node( *i );
        
        
        xml_string      entry_name( child_node->get_name() );
        int             object_id = child_node->get_attribute_int( "id" );
        
        if( entry_name == "middle_metro_real" ) {
            sqc_verbose() << "load:  " << entry_name;
        }
        
        
        sqc_game_object_ptr  object_to_load;
        std::map<int, sqc_game_object_list::iterator>::iterator i_obj = current_objects.find( object_id );
        if( i_obj != current_objects.end() ) {
            if( (*i_obj->second)->get_type() == entry_name ) {
                object_to_load = *i_obj->second;
                current_objects.erase( i_obj );
            }
        }
        
        if( !object_to_load ) {
            object_to_load = m_object_factory->create_instance( entry_name.c_str() );
            if( !object_to_load ) {
                sqc_error() << "failed to load object, class = \"" << entry_name << "\"";
                continue;
            }
            need_zorder = true;
            m_objects.push_back( object_to_load );
        }
        
        sqc_point   old_position = object_to_load->get_position();
        bool        old_orientation = object_to_load->get_orientation();
        
        object_to_load->parse_xml( child_node );
        //object_to_load->reload_textures();
        
        if( old_position != object_to_load->get_position() || old_orientation != object_to_load->get_orientation() ) {
            need_zorder = true;
        }
    }
    
    //
    // remove old objects
    //
    for( std::map<int, sqc_game_object_list::iterator>::iterator i = current_objects.begin(); i != current_objects.end(); ++i ) {
        m_objects.erase( i->second );
    }
    
    if (!add_extra_objects()) {
        need_zorder = true;
    }
    
    for (sqc_game_object_list::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
        (*it)->reload_textures();
    }
    
    //
    // z-order objects if neccesary
    //
    
    if( need_zorder ) {
        zorder_sort( m_objects );
    }
}

void sqc_field_base::zorder_objects() {
    zorder_sort( m_objects );
}


surf::surf_point sqc_field_base::calc_default_pos( sqc_coord_convertor &coord_conv ) {
    sqc_point  center_point;
    int count = 0;
    for( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        //current_objects[(*i)->get_id()] = i;
        center_point += (*i)->get_position(); 
        ++count;
    }
    
    for( std::list<sqc_rect>::const_iterator i = m_bounds.begin(); i != m_bounds.end(); ++i ) {
        center_point += (*i).center();
        ++count;
    }
    
    center_point /= count;
    
    surf::surf_point  screen_point = coord_conv.field_to_screen( center_point, sqc_coord_convert_mode_select_no_scroll );
    surf::surf_nsize   screen_size = coord_conv.get_screen_size();
    
    screen_point.x -= screen_size.cx/2;
    screen_point.y -= screen_size.cy/2;
    
    return screen_point;
}

surf::surf_rect sqc_field_base::calc_rect( sqc_coord_convertor &coord_conv ) {
    surf::surf_point    min_point;
    surf::surf_point    max_point;
    bool initialized = false;
     
    for( std::list<sqc_rect>::const_iterator i = m_bounds.begin(); i != m_bounds.end(); ++i ) {
        sqc_rect    rect( *i );
         
        sqc_point   points[4];
        points[0] = rect.bottom_left();
        points[1] = rect.bottom_right();
        points[2] = rect.top_left();
        points[3] = rect.top_right();
         
        for( int n = 0; n != 4; ++n )  {
             
            surf::surf_point  test = coord_conv.field_to_screen( points[n], sqc_coord_convert_mode_draw_no_scroll );
             
            if( !initialized ) {
                min_point = max_point = test;
                initialized = true;
            }
            else {
                if( min_point.x > test.x )  min_point.x = test.x;
                if( min_point.y > test.y )  min_point.y = test.y;
                if( max_point.x < test.x )  max_point.x = test.x;
                if( max_point.y < test.y )  max_point.y = test.y;
            }
        }
    }

	for ( sqc_game_object_list::iterator i = m_objects.begin(); i != m_objects.end(); ++i) {

		sqc_rect rect(
        	(*i)->get_position().x,
            (*i)->get_position().y,
            (*i)->get_size().cx,
            (*i)->get_size().cy
        );

        sqc_point   points[4];
        points[0] = rect.bottom_left();
        points[1] = rect.bottom_right();
        points[2] = rect.top_left();
        points[3] = rect.top_right();
         
        for( int n = 0; n != 4; ++n )  {
             
            surf::surf_point  test = coord_conv.field_to_screen( points[n], sqc_coord_convert_mode_draw_no_scroll );
             
            if( min_point.x > test.x )  min_point.x = test.x;
            if( min_point.y > test.y )  min_point.y = test.y;
            if( max_point.x < test.x )  max_point.x = test.x;
            if( max_point.y < test.y )  max_point.y = test.y;
        }
    
    }
 
    return surf::surf_rect( min_point, max_point );
}


void sqc_field_base::render_border( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
    ctx->set_width( 1.5 * coord_conv.get_zoom() );
    //ctx->set_smooth( true );
    
    for( std::list<sqc_rect>::const_iterator i = m_bounds.begin(); i != m_bounds.end(); ++i ) {
        sqc_rect    rect( *i );
        surf::surf_curve_ptr    curve = ctx->server().create_curve();
        
        curve->move_to( coord_conv.field_to_screen( rect.top_left() ) );
        curve->line_to( coord_conv.field_to_screen( rect.top_right() ) );
        curve->line_to( coord_conv.field_to_screen( rect.bottom_right() ) );
        curve->line_to( coord_conv.field_to_screen( rect.bottom_left() ) );
        curve->line_to( coord_conv.field_to_screen( rect.top_left() ) );
        
        
//        curve->move_to( surf::surf_point( 100, 100 ) );
//        curve->line_to( surf::surf_point( 50, 150 ) );
//        curve->line_to( surf::surf_point( 100, 200 ) );
//        curve->line_to( surf::surf_point( 150, 150 ) );
//        curve->line_to( surf::surf_point( 100, 100 ) );
        
        ctx->set_color( surf::surf_byte_color( 114, 220, 86, 255 ) ); 
        curve->draw( ctx );
        
        curve->offset( surf::surf_point( 3, -3 ) );
        ctx->set_color( surf::surf_byte_color( 0, 0, 0, 120 ) ); 
        curve->draw( ctx );
    }
    ctx->set_width( 1 );
}

void sqc_field_base::render_objects( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
    surf::surf_nrect    rect_screen( surf::surf_npoint(), coord_conv.get_screen_size() );
    sqc_object_selection* selection = m_object_selection.get();
    
    bool    selection_processed = false;
    
    
    ctx->set_color( surf::surf_byte_color( 255, 255, 255, 255 ) ); 
    sqc_game_object_draw_args draw_args = sqc_game_object_default_draw_arg;
    if (m_objects_no_animation)
        draw_args.mode = sqc_game_object_draw_args::static_texture;
    draw_args.tooltip = !m_objects_no_status;
    
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        surf::surf_rect rect = object->get_display_rect( coord_conv );
        if( !rect_screen.is_intercepted( rect ) ) {
            continue;
        }
        
        if (selection && ( selection->get_object()==object ) ) { 
            if ( selection->get_selection_type()==sqc_game_object_selection_type_normal)  {
                selection_processed = true;
                selection->render(ctx, coord_conv,draw_args);
            }
		} else
            object->render( ctx, coord_conv ,draw_args);
    }
    
    if( !selection_processed ) {
        selection->render(ctx, coord_conv,draw_args);
    }
}

void sqc_field_base::handle_timer()
{
    for (sqc_game_object_list::iterator it = m_objects.begin(); it != m_objects.end(); ++it) {
        (*it)->handle_timer();
    } 
}

void sqc_field_base::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
    render_back( ctx, coord_conv );
    render_grid( ctx, coord_conv );
    render_border( ctx, coord_conv );
    render_objects( ctx, coord_conv );
}

void sqc_field_base::render_back( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {

    if( !m_background_texture ) {
        sqc_texture_proxy   &proxy = framework::framework().texture_proxy();
        m_background_texture = proxy.get_texture( "bg", framework::load_priority_now );
    }
    if( !m_background_texture ) {
        return;
    }
    
    
    surf::surf_nsize    texture_size = m_background_texture->get_size();
    
    surf::surf_point    start_coord = coord_conv.field_to_screen( sqc_point() );
    surf::surf_nsize    screen_size = coord_conv.get_screen_size();
    
    double start_x = -start_coord.x / (double)texture_size.cx;
    double end_x = (-start_coord.x+screen_size.cx) / (double)texture_size.cx;
    double start_y = -start_coord.y / (double)texture_size.cy;
    double end_y = (-start_coord.y+screen_size.cy) / (double)texture_size.cy;
    
    int x1 = floor( start_x );
    int x2 = ceil( end_x );
    int y1 = floor( start_y );
    int y2 = ceil( end_y );
    
    surf::surf_rect rect( start_coord.x + x1*texture_size.cx,
                         start_coord.y + y1*texture_size.cy,
                         (x2-x1)*texture_size.cx,
                         (y2-y1)*texture_size.cy );
    
    //m_background_texture->fill( ctx, rect/*surf::surf_rect( 0, 0, screen_size.cx, screen_size.cy )*/ );
    //virtual void draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info ) = 0;
	
    sqc_texture_draw_info draw_info;
	draw_info.set_fill( rect.size() );
	m_background_texture->draw( ctx, rect.bottom_left(), draw_info );

    //m_background_texture->fill( ctx, surf::surf_rect( 0, 0, screen_size.cx, screen_size.cy ) );
    
    if (earth_ptr) {
    	earth_ptr->render(ctx);
    }
}

void sqc_field_base::render_grid( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
//#ifdef DEBUG
    for( std::list<sqc_rect>::const_iterator i = m_bounds.begin(); i != m_bounds.end(); ++i ) {
        sqc_rect    rect( *i );
        
        ctx->set_color( surf::surf_byte_color( 0, 255, 0, 255 ) ); 
        for( int x = 1; x != rect.cx; ++x ) {
            surf::surf_curve_ptr    curve = ctx->server().create_curve();
            
            curve->move_to( coord_conv.field_to_screen( rect.bottom_left() + sqc_point( x, 0 ) ) );
            curve->line_to( coord_conv.field_to_screen( rect.bottom_left() + sqc_point( x, rect.cy ) ) );
            curve->draw( ctx );
        }
        for( int y = 1; y != rect.cy; ++y ) {
            surf::surf_curve_ptr    curve = ctx->server().create_curve();
            
            curve->move_to( coord_conv.field_to_screen( rect.bottom_left() + sqc_point( 0, y ) ) );
            curve->line_to( coord_conv.field_to_screen( rect.bottom_left() + sqc_point( rect.cx, y ) ) );
            curve->draw( ctx );
        }
    }
//#endif
}


//
//
//

bool sqc_field_base::is_allow_build( sqc_rect const &rect ) {
    int   x1 = rect.x;
    int   y1 = rect.y;
    int   x2 = x1 + rect.cx;
    int   y2 = y1 + rect.cy;
  
    for( std::list<sqc_rect>::const_iterator i = m_bounds.begin(); i != m_bounds.end(); ++i ) {
        sqc_rect const &rect( *i );
        /// all object in one of bounds
        bool in_bound = true;
        for (int y = y1; (y < y2)&&in_bound; ++y) {
            for (int x = x1; (x < x2)&&in_bound; ++x) {
                sqc_point coords( x, y );
                if( !rect.point_in_rect( coords ) ) {
                    in_bound = false;
                }
            }
        }
        if (in_bound) return true;
    }
    return false;
}

sqc_game_object_ptr sqc_field_base::get_object_by_type_id( int type_id ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        if( object->get_type_id() == type_id ) {
            return object;
        }
    }
    
    return sqc_game_object_ptr();
}

sqc_game_object_ptr sqc_field_base::get_object_by_id( int object_id ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        if( object->get_id() == object_id ) {
            return object;
        }
    }
    
    return sqc_game_object_ptr();
}

void sqc_field_base::get_object_by_type_name( sqc_string const &type_name, sqc_game_object_list& list ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        if( object->get_type() == type_name ) {
            list.push_back( object );
        }
    }
}

void sqc_field_base::get_object_by_type( info::sqc_object_type type, sqc_game_object_list& list ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        info::sqc_object_info* info = object->get_object_info().get();
        
        if( info && info->get_type() == type ) {
            list.push_back( object );
        }
    }
}

sqc_game_object_ptr sqc_field_base::get_object_intersect_rect( sqc_rect const &rect, int object_id ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        if (object_id && object_id == object->get_id() ) {
            continue;
        }
        
        sqc_rect    current_rect( object->get_position(), object->get_size() );
        if( rect.rect_intersect_rect( current_rect ) ) {
            return object;
        }
    }
    
    return sqc_game_object_ptr();
}


sqc_game_object_ptr sqc_field_base::get_object_by_point( sqc_point const &coords ) {
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        sqc_rect    rect( object->get_position(), object->get_size() );
        if( rect.point_in_rect( coords ) ) {
            return object;
        }
    }

    return sqc_game_object_ptr();
}

sqc_game_object_ptr sqc_field_base::get_object_by_screen_point( surf::surf_point const &point, sqc_coord_convertor &coord_conv ) {
    for( sqc_game_object_list::const_reverse_iterator i = m_objects.rbegin(); i != m_objects.rend(); ++i ) {
        sqc_game_object_ptr object( *i );
        
        if( object->check_point_on_object( point, coord_conv ) ) {
            return object;
        }
    }
    
    return sqc_game_object_ptr();
}


bool sqc_field_base::move_object( sqc_game_object_ptr object, sqc_point const &point ) {
    if( !object ) {
        return false;
    }
    
    if( object->get_position() == point ) {
        return false;
    }
    
    object->set_position( point );
    return true;
}

bool sqc_field_base::rotate_object( sqc_game_object_ptr object ) {
    if( !object ) {
        return false;
    }
    
    object->set_orientation( !object->get_orientation() );
    object->reload_textures();
    
    return true;
}

bool sqc_field_base::calculate_nearest_process_end( sqc_ddword &next_process_end, int &next_object_id ) {
    next_object_id = 0;
    
    for( sqc_game_object_list::const_iterator i = m_objects.begin(); i != m_objects.end(); ++i ) {
        sqc_game_object_ptr object( *i );
        sqc_dword process_end = object->get_process_end();
        if( process_end != -1 ) {
            if( next_object_id ) {
                if( next_process_end > process_end ) {
                    next_object_id = object->get_id();
                    next_process_end = process_end;
                }
            }
            else {
                next_object_id = object->get_id();
                next_process_end = process_end;
            }
        }
    }
    
    return next_object_id != 0;
}

void sqc_field_base::prepare_back(sqc_coord_convertor &coord_conv)
{

    if (earth_ptr) {
		earth_ptr->generate_texture_list(coord_conv);
    }
}

bool sqc_field_base::add_extra_objects() {
    return false;
}

END_NAMESPACE_SQC_FRAMEWORK
