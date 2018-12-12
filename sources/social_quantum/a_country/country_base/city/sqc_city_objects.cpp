/*
 *  sqc_city_objects.cpp
 *  configurator
 *
 *  Created by Andrey Yamov on 5/13/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_city_objects.h"

#ifndef SQC_OBJECT_DISABLE_DRAWING
#include "country_base/view/sqc_bubble_def.h"
#include "city/city_framework.h"
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#include <stdlib.h>

NAMESPACE_SQC_CITY
#ifdef SQC_ENABLE_OBJECTS

//
//
// sqc_city_object_base
//
//

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_city_object_base::do_parse_xml( xml::xml_node_ptr node ) {
    if (object_state != object_state_queued && object_state != object_state_progress  ) {
        object_state = static_cast<sqc_object_state>( node->get_attribute_int( "state" ) );
    }
    
    return sqc_game_object::do_parse_xml( node );
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING


sqc_string sqc_city_object_base::get_image_path() const {
    const sqc_city_drawing * city_drawing = static_cast<sqc_city_drawing const *>( object_info->get_drawing() );
    
    if( city_drawing ) {
        if( !city_drawing->get_custom_image().empty() ) {
            return city_drawing->get_custom_image();
        }
    }
    return object_info->get_image_path();
}

sqc_string sqc_city_object_base::get_type_name() const {
    return object_info->get_type_name();
}

void sqc_city_object_base::enumerate_textures( sqc_texture_info_list &result ) {
    if (enumerate_complex_object_textures(result)) {
        return;
    }
    /* материалы и контракты отрабатываются сдесь , пока не реализован способ отделить одни обьекты от других
     
    if (object_info->get_image_path()=="archaeological_excavations" ||
        object_info->get_image_path()=="discovery_of_cave_painting" ||
        object_info->get_image_path()=="study_of_ancient_artifacts" ||
        object_info->get_image_path()=="study_of_ancient_writing"
        ) {
        
        result.push_back(sqc_texture_info( "popup_" + object_info->get_image_path(), false, false, false ) ); 
        result.push_back(sqc_texture_info( "popup_hd_" + object_info->get_image_path(), false, false, false ) ); 
        result.push_back(sqc_texture_info( "popup_ipad_" + object_info->get_image_path(), false, false, false ) );
    }*/
     
    result.push_back(sqc_texture_info( object_info->get_image_path(), false, false, false ) ); 
}

bool sqc_city_object_base::enumerate_complex_object_textures( sqc_texture_info_list &result )
{   
    sqc_city_drawing *city_drawing = static_cast<sqc_city_drawing*>( object_info->get_drawing() );
    if(city_drawing && city_drawing->get_type() == drawing_type_city_complex_object)
    {
        sqc_complex_object_drawing *complex_object_drawing = static_cast<sqc_complex_object_drawing*>( city_drawing );
        
        sqc_complex_object_draw_entry_list const &entries = complex_object_drawing->get_entries();
        
        for( sqc_complex_object_draw_entry_list::const_iterator i = entries.begin(); i!=entries.end(); ++i )
        {
            std::vector<sqc_string> const &image_names = (*i)->get_image_names();
            int image_names_size = image_names.size();
            
            for( std::vector<sqc_string>::const_iterator j = image_names.begin(); j != image_names.end(); ++j )
            {
                
                if ((*i)->is_rotated_object()) {
                     result.push_back( sqc_texture_info( *j+"_v1", true, false, false ) );
                     result.push_back( sqc_texture_info( *j+"_v2", true, false, false ) );
                }else {
                     result.push_back( sqc_texture_info( *j, true, false, false ) );
                }
            }
            
            std::vector<int> const &animated_stages = (*i)->get_animated_stages();
            
            if(!(*i)->get_custom_texture_counter().empty())
            {
                result.push_back( sqc_texture_info((*i)->get_custom_texture_counter(), true, false, false ) );
            };
            
            for( std::vector<int>::const_iterator j = animated_stages.begin(); j != animated_stages.end(); ++j )
            {
                if( *j < image_names_size ) {
                    sqc_string const &image_name = image_names[*j];
                    std::vector<sqc_string> const &custom_animatios =  (*i)->get_custom_animatios();
                    if (custom_animatios.size()) {
                            if ((*i)->is_rotated_object()) {
                                    for( std::vector<sqc_string>::const_iterator l = custom_animatios.begin(); l != custom_animatios.end(); ++l )
                                    {
                                        result.push_back( sqc_texture_info( image_name +"_v1" +"_no_ff", true, false, false ) );
                                        result.push_back( sqc_texture_info( image_name +"_v2" +"_no_ff", true, false, false ) );
                                        result.push_back( sqc_texture_info( *l +"_v1" +"_d_animation", true, true, false ) );
                                        result.push_back( sqc_texture_info( *l +"_v2" +"_d_animation", true, true, false ) );
                                    }
                        }else {
                            for( std::vector<sqc_string>::const_iterator l = custom_animatios.begin(); l != custom_animatios.end(); ++l )
                            {
                                result.push_back( sqc_texture_info( image_name + "_no_ff", true, false, false ) );
                                result.push_back( sqc_texture_info( *l + "_d_animation", true, true, false ) );                            
                            }
                            
                        }
                    }else {
                        if ((*i)->is_rotated_object()) {                        
                            result.push_back( sqc_texture_info( image_name +"_v1"+ "_no_ff", true, false, false ) );
                            result.push_back( sqc_texture_info( image_name +"_v2"+ "_no_ff", true, false, false ) );
                            result.push_back( sqc_texture_info( image_name +"_v1"+ "_d_animation", true, true, false ) );
                            result.push_back( sqc_texture_info( image_name +"_v2"+ "_d_animation", true, true, false ) );
                        }else {                        
                            result.push_back( sqc_texture_info( image_name + "_no_ff", true, false, false ) );
                            result.push_back( sqc_texture_info( image_name + "_d_animation", true, true, false ) );                        
                        }
                    } 
              }
                
            }    
            
            
        }
        return true;
    }
    return false;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_city_object_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner) {
	sqc_game_object::fill_bubble_content( bubble,owner );
	if (object_state==object_state_building && get_process_end()>0) {
		sqc::framework::sqc_bubble_element element;
		element.tag = "time";
		element.value = get_process_end();
		element.icon = "bubble_bubble_build";
		element.text = sqc_bubble_time_marker;
		bubble.elements.push_back(element);
		return true;
	}
	return false;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

//
//
// sqc_building_base
//
//

sqc_string sqc_building_base::get_building_image_path() const {
    int w = object_info->get_width();
    int h = object_info->get_height();
    
    if( w > h ) {
        std::swap( w, h );
    }
    
    std::stringstream   result;
    result << "build_" << w << "x" << h;
    
    return result.str();
}

sqc_string sqc_building_base::get_status_image_path() const {
    
    if (object_state == object_state_progress) {
        return "status_progress";
    }
    else if (object_state == object_state_queued) {
        return "status_queued";
    }
    
    return sqc_string();
}

bool sqc_building_base::can_rotate() {
    //std::tr1::shared_ptr<info::sqc_city_object_info>    city_info = std::tr1::static_pointer_cast<info::sqc_city_object_info> (object_info);
    return object_info->get_move();
}

bool sqc_building_base::has_building_stage() {
    if( !object_info->get_create() ) {
        return false;
    }
    if( !object_info->get_build_length() ) {
        return false;
    }
    return true;
}

void sqc_building_base::enumerate_animation_stages( sqc_string_list &result ) {
    // do not add "BUILDING" stage
    result.push_back( "2" );
}

void sqc_building_base::enumerate_textures( sqc_texture_info_list &result ) {
    if (enumerate_complex_object_textures(result)) {
        return;
    }

    sqc_city_drawing *city_drawing = static_cast<sqc_city_drawing*>( object_info->get_drawing() );
    sqc_string image_path = get_image_path();
    
    result.push_back( sqc_texture_info( image_path+"_v1", true, false, false ) ); 
    if( can_rotate() ) {
        result.push_back( sqc_texture_info( image_path+"_v2", true, false, true ) ); 
    }
    
    if( city_drawing ) {
        if( city_drawing->get_animated() ) {
            if( city_drawing->get_no_first_frame() ) {
                result.push_back( sqc_texture_info( image_path+"_v1_no_ff", true, false, false ) ); 
                if( can_rotate() ) {
                    result.push_back( sqc_texture_info( image_path+"_v2_no_ff", true, false, true ) ); 
                }
            }
            
            sqc_string_list animated_stages;
            enumerate_animation_stages( animated_stages );
            
            for( sqc_string_list::const_iterator i = animated_stages.begin(); i != animated_stages.end(); ++i ) {
                if( !city_drawing->is_animated_stage( *i ) ) {
                    continue;
                }
                result.push_back( sqc_texture_info( image_path + "_0_" + *i + "_animation", true, true, false ) ); 
                if( can_rotate() ) {
                    result.push_back( sqc_texture_info( image_path + "_1_" + *i + "_animation", true, true, true ) ); 
                }
            }
        }
        
        sqc_string custom_build_icon = city_drawing->get_custom_build_icon();
        if( !custom_build_icon.empty() && custom_build_icon != "none" ) {
            result.push_back( sqc_texture_info( custom_build_icon , false, false, false ) );
        }
    }

    if( !has_building_stage() ) {
        return;
    }
    //
    // object can be created - building stage is important
    // 
    
    sqc_string  build_path = get_building_image_path();
    result.push_back( sqc_texture_info( build_path+"_v1", true, false, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_v2", true, false, true ) ); 
    
    result.push_back( sqc_texture_info( build_path+"_v1_no_ff", true, false, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_v2_no_ff", true, false, true ) ); 
    
    result.push_back( sqc_texture_info( build_path+"_0_1_animation", true, true, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_1_1_animation", true, true, true ) ); 
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_building_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner) {
	sqc_city_object_base::fill_bubble_content( bubble  , owner);
	return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
template <class T> inline
bool is_texture_ready( T ptr ) {
    if( !ptr ) {
        return false;
    }
    if( !ptr->is_ready() ) {
        
        return false;
    }
    return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING

void sqc_building_base::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg ) {
    
    surf::surf_point   pos = coord_conv.field_to_screen( get_position() );
    
    sqc_texture_draw_info   draw_info;
    
    texture_list_entry_t texture_list_entry;
    for (texture_vector_t::iterator it = texture_vector.begin(); it != texture_vector.end(); ++it) {
        texture_list_entry_t entry = *it;    
        
        bool    noff_ready = is_texture_ready( entry.object_texture_no_ff );
        bool    anim_ready = is_texture_ready( entry.object_animation );
        if( noff_ready && anim_ready && (draw_arg.mode != sqc_game_object_draw_args::static_texture) )
        {
            entry.object_texture_no_ff->draw( ctx, pos, draw_info );
            if (draw_arg.mode == sqc_game_object_draw_args::animation_all)
                entry.object_animation->draw( ctx, pos, draw_info );
        }
        else if( is_texture_ready( entry.object_texture ) ) {
            entry.object_texture->draw( ctx, pos, draw_info );
        }
        else {
            sqc_game_object::render( ctx, coord_conv, draw_arg );    
        }
    }
    
    if( is_texture_ready( object_texture_status ) && draw_arg.tooltip ) {
        surf::surf_point   status_pos = coord_conv.field_to_screen( get_position() + sqc_point( 0, get_size().cy ) );
        
        object_texture_status->draw( ctx, status_pos, draw_info );
    }
    
    if (object_state != object_state_progress) {
        m_start_progress_time = 0;
    }
    
    if( object_state == object_state_progress && is_texture_ready( object_texture_progress ) && draw_arg.tooltip ) {
        
        if (!m_start_progress_time) {
            m_start_progress_time = sqc::framework::framework().windows().get_tick_count();
        }
        
        if (sqc::framework::framework().windows().get_tick_count() - m_start_progress_time >= progress_interval) {
            m_current_progress++;
            m_start_progress_time = sqc::framework::framework().windows().get_tick_count();
            
            if (m_current_progress > c_max_progress) {
                m_current_progress = c_max_progress;
            }
        }
        
        surf::surf_nsize progress_size = object_texture_progress->get_size();
        progress_size.cx = c_progress_offset + c_progress_step_width*m_current_progress;
        
        surf::surf_point   progress_pos = coord_conv.field_to_screen( get_position() + sqc_point( 0, get_size().cy ) );
        
        draw_info.use_anchor = true;
        draw_info.use_source_size = true;
        draw_info.source_size_info.source_size = surf::surf_size( progress_size.cx, progress_size.cy );
        
        draw_info.use_target_size = true;
        draw_info.target_size_info.keep_aspect = false;
        draw_info.target_size_info.target_size = draw_info.source_size_info.source_size;
        if ( draw_arg.tooltip )
            object_texture_progress->draw( ctx, progress_pos, draw_info );
    }
}

#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

sqc_string sqc_building_base::get_main_texture_path() const {
    sqc_string texture_key;
    texture_key = get_image_path();
    texture_key += get_orientation() ? "_v2" : "_v1";
    
    return texture_key;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
surf::surf_rect sqc_building_base::get_display_rect( sqc_coord_convertor &coord_conv, bool apply_scroll )
{
    surf::surf_rect max_rect = sqc_city_object_base::get_display_rect( coord_conv, apply_scroll );
    for (texture_vector_t::iterator it = texture_vector.begin(); it != texture_vector.end(); ++ it)
    {
        surf::surf_rect rect;

		texture_list_entry_t texture_list_entry = *it;

        if( !texture_list_entry.object_texture ) {
			return sqc_city_object_base::get_display_rect( coord_conv, apply_scroll );
        }

        surf::surf_point point = coord_conv.field_to_screen(
        	get_position(),
            apply_scroll ? sqc_coord_convert_mode_draw : sqc_coord_convert_mode_draw_no_scroll
        );
        surf::surf_nsize size( texture_list_entry.object_texture->get_size() );
        surf::surf_npoint anchor( texture_list_entry.object_texture->get_anchor() );

		point.x -= anchor.x;
        point.y -= size.cy - anchor.y;
        rect = surf::surf_rect( point.x, point.y, size.cx, size.cy );
        max_rect.union_rect(rect);
    }
    
    return max_rect;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_building_base::check_point_on_texture( surf::surf_point const &click_point, sqc_coord_convertor &coord_conv, sqc_texture_ptr texture, sqc_point const &texture_offset ) {
	if ( !texture ) {
    	return false;
    }
    
    surf::surf_point   offset = coord_conv.field_to_screen( texture_offset, sqc_coord_convert_mode_select );
    surf::surf_nsize   size( texture->get_size() );
    surf::surf_npoint   anchor( texture->get_anchor() );
    
    offset.x -= coord_conv.get_zoom()*anchor.x;
    offset.y -= coord_conv.get_zoom()*size.cy - coord_conv.get_zoom()*anchor.y;
    
    surf::surf_rect object_screen_rect( offset.x, offset.y, coord_conv.get_zoom()*size.cx, coord_conv.get_zoom()*size.cy );
    if( !object_screen_rect.point_in_rect( click_point ) ) {
        return false;
    }
    
    if( !is_texture_ready( texture ) ) {
        return true;
    }
    
    surf::surf_point   texture_coords( click_point.x - offset.x, coord_conv.get_zoom()*size.cy - coord_conv.get_zoom() - (click_point.y - offset.y) );
    texture_coords/=coord_conv.get_zoom();
    
    return texture->hit_test( surf::surf_npoint(texture_coords.x+0.5,texture_coords.y+0.5) );
}

bool sqc_building_base::check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv ) {
	sqc_texture_ptr ot;
    if ( texture_vector.size() > 0 ) {
    	ot = texture_vector[0].object_texture;
    }
    
	if( !ot && !object_texture_status ) {
        return sqc_city_object_base::check_point_on_object( point, coord_conv );
    }
    
	for (texture_vector_t::iterator it = texture_vector.begin(); it != texture_vector.end(); ++it) {
        texture_list_entry_t entry = *it;
        if ( check_point_on_texture( point, coord_conv, entry.object_texture, get_position() ) ) {
            return true;
        }
    }
    
    {
    	sqc_point texture_offset = get_position() + sqc_point( 0, get_size().cy );
        if ( check_point_on_texture( point, coord_conv, object_texture_status, texture_offset ) ) {
            return true;
        }
    }
	
    return false;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING

enum building_stages_t {
	bs_none = 0,
    bs_building,
    bs_complete
};

#define S1 "    "
#define S2 "        "
#define S3 "            "
#define S4 "                "


class stage_texture {
public:
	stage_texture(sqc_complex_object_draw_entry_ptr obj_drawing)
    	: m_obj_drawing(obj_drawing)
        , m_image_list( obj_drawing->get_image_names() )
    {}
    
    bool is_animation_ability(building_stages_t state) {
        std::vector<int> animated_stages = m_obj_drawing->get_animated_stages();
        for ( std::vector<int>::iterator
             it = animated_stages.begin(); it != animated_stages.end(); ++it)
        {
            int stage = (*it);
            if (stage == state) {
                return true;
            }
        }
        return false;
    }
    
    sqc_string name(building_stages_t state) {
        int img_count = m_image_list.size();
        return state > (img_count - 1) ? m_image_list[img_count-1] : m_image_list[state];
    }
private:
	sqc_complex_object_draw_entry_ptr m_obj_drawing;
    building_stages_t m_state;
    std::vector<sqc_string> m_image_list;
};

sqc_string
sqc_building_base::select_texture_name( sqc_complex_object_draw_entry_ptr obj_drawing, 
										bool & animation )
{
    stage_texture texture(obj_drawing);
    
    std::vector<sqc_string> image_list = obj_drawing->get_image_names();
    const int images_count = image_list.size();
    if ( images_count == 0 ) {
        sqc_error() << "No defined texture names for object " << obj_drawing->get_caption();
        return "";
    }

	sqc_string img_name;
	// materials quantities (see "materials_quantity" node in city_items.yml)
    const sqc_quantity_by_name_map & total_materials_quantity = get_object_info()->get_materials_quantity();
    const sqc_quantity_by_name_map & current_materials_quantity = get_materials_quantity();

	/*** Log debug ***********************************************************

    sqc_info() << S1 << obj_drawing->get_caption() << " (" << total_materials_quantity.size() << ", " << current_materials_quantity.size() << ")";
    std::vector<sqc_string> req_mat = obj_drawing->get_requested_materials();
    sqc_info() << S2 << "request materials:";
    for (std::vector<sqc_string>::iterator rmit = req_mat.begin(); rmit != req_mat.end(); ++rmit) {
        sqc_info() << S3 << *rmit;
    }

    sqc_info() << S2 << "object_info->materials_quantity = {";
    for (sqc_quantity_by_name_map::const_iterator it = total_materials_quantity.begin(); it != total_materials_quantity.end(); ++it) {
        sqc_info() << S3 << it->first << ": " << it->second;
    }
    sqc_info() << S2 << "}";
    
    sqc_info() << S2 << "game_object->materials_quantity = {";
    for (sqc_quantity_by_name_map::const_iterator it = current_materials_quantity.begin(); it != current_materials_quantity.end(); ++it) {
        sqc_info() << S3 << it->first << ": " << it->second;
    }
    sqc_info() << S2 << "}";

	/**************************************************************************/

	// if total material quantity is empty then object have completed state
    if (total_materials_quantity.size() == 0) {
		
        animation = texture.is_animation_ability(bs_complete);
        return texture.name(bs_complete);
    }
    
    // if current material quantity is empty then object have begin stage
    if (current_materials_quantity.size() == 0) {
		animation = texture.is_animation_ability(bs_none);
        return texture.name(bs_none);
    }
	
    if (images_count == 1) {
        // There is only one texture (object has begin stage)
        animation = texture.is_animation_ability(bs_none);
        img_name = texture.name(bs_none);
    }
    // if texture list exists 1 item, material-based select algorithm is disabled
    else if ( images_count > 1 ) {

        // select stage
        //
        std::vector<sqc_string> key_material_list = obj_drawing->get_requested_materials();
        
        int state[ sizeof(building_stages_t) ] = {0};
        for ( std::vector<sqc_string>::iterator
              material_it = key_material_list.begin(); material_it != key_material_list.end(); ++material_it )
        {
            sqc_string material = *material_it;
            
            sqc_quantity_by_name_map::const_iterator
            	total_mq_it = total_materials_quantity.find(material);

            if ( total_mq_it == total_materials_quantity.end() ) {
                sqc_error() << "Not found material \"" << material << "\" in total_materials_quantity";
                continue;
            }

            sqc_quantity_by_name_map::const_iterator
            	current_mq_it = current_materials_quantity.find(material);
            
            // if material not exists in current_materials_quantity then material was not purchased
            if ( current_mq_it == current_materials_quantity.end() ) {
				state[bs_none]++;
				continue;
            }

            if (current_mq_it->second > 0 && current_mq_it->second < total_mq_it->second) {
                state[bs_building]++;
            }
            else if (current_mq_it->second == total_mq_it->second) {
                state[bs_complete]++;
            }
        }
        /*!
            Object changes its texture when the key materials have purchased.
            Logic of choice of texture:
                purchased one or more materials, but not all, for any item - state building
                purchased all materials for all items - state complete
                no purchased materials, for all items - state none
        */

        building_stages_t bs = 
        	state[bs_building] ? bs_building : state[bs_complete] ? bs_complete : bs_none;
            
        img_name = texture.name(bs);
        animation = texture.is_animation_ability(bs);
    }

	return img_name;
}

void sqc_building_base::reload_textures() {
    // 
    // getting the textures key
    // texture_vector[main_texture, complex_texture1, complex_texture2, .., complex_textureN]
    
    bool init_texture_vector = texture_vector.size() == 0;
    sqc_string texture_key;
    sqc_string texture_key_animation, texture_key_no_ff;
    sqc_string status_key = get_status_image_path();

	if( object_state == object_state_building )
    {
        texture_key = get_building_image_path() + ( get_orientation() ? "_v2" : "_v1" );
        texture_key_no_ff = get_building_image_path() + ( get_orientation() ? "_v2_no_ff" : "_v1_no_ff" );
        texture_key_animation = get_building_image_path() + ( get_orientation() ? "_1_1_animation" : "_0_1_animation" );
    }
    else 
    {
		texture_key = get_main_texture_path();

        // getting drwaing information for object
        sqc_city_drawing *city_drawing = static_cast<sqc_city_drawing*>( object_info->get_drawing() );

        sqc_string image_path = get_image_path();

		if( city_drawing ) {
            if( city_drawing->get_animated() ) {
                sqc_string  stage_postfix;
                stage_postfix += '0' + ((int)object_state);
                
                if( city_drawing->is_animated_stage( stage_postfix ) ) {
                    if( city_drawing->get_no_first_frame() ) {
						texture_key_no_ff = image_path + (get_orientation() ? "_v2_no_ff" : "_v1_no_ff");
					}

					texture_key_animation = image_path + (get_orientation() ? "_1_" : "_0_") + stage_postfix + "_animation";
                }
            }
        }
    }
    
    //
    // load textures
    //
    sqc_texture_proxy & proxy = framework::framework().texture_proxy();

    texture_list_entry_t texture_list_entry;
    if( !texture_list_entry.object_texture || texture_list_entry.object_texture->get_name()!= texture_key ) {
		texture_list_entry.object_texture = proxy.get_texture( texture_key.c_str(), framework::load_priority_normal );
    }

	if( !texture_key_animation.empty() ) {
    	if( !texture_list_entry.object_animation || texture_list_entry.object_animation->get_name() != texture_key_animation ) {
        	texture_list_entry.object_animation = proxy.get_texture( texture_key_animation.c_str(), framework::load_priority_idle );
        }
    }
    else {
        texture_list_entry.object_animation.reset();
    }
    
    if( !texture_key_no_ff.empty() ) {
    	if( !texture_list_entry.object_texture_no_ff || texture_list_entry.object_texture_no_ff->get_name() != texture_key_no_ff ) {
        	texture_list_entry.object_texture_no_ff = proxy.get_texture( texture_key_no_ff.c_str(), framework::load_priority_idle );
        }
    }
    else {
        texture_list_entry.object_texture_no_ff = texture_list_entry.object_texture;
    }
    
    if( !status_key.empty() ) {
        if( !object_texture_status || object_texture_status->get_name() != status_key ) {
            object_texture_status = proxy.get_texture( status_key.c_str(), framework::load_priority_normal );

            //
            // temporary workaround
            // HACK!!! HACK!!! HACK!!!
            // need to put the anchor to textures.plist
            //
            if( object_texture_status ) {
                object_texture_status->set_anchor( surf::surf_npoint( 21, 53 ) );
                
            }
        }
    }
    else {
        object_texture_status.reset();
    }
    
    if (!object_texture_progress && object_state == object_state_progress) {
        object_texture_progress = proxy.get_texture( "progress_bar", framework::load_priority_normal );
        
        //
        // temporary workaround
        // HACK!!! HACK!!! HACK!!!
        // need to put the anchor to textures.plist
        //
        if( object_texture_progress ) {
            object_texture_progress->set_anchor( surf::surf_npoint( 21, 53 ) );
        }
    }    
	
    if (init_texture_vector) {
    	texture_vector.push_back( texture_list_entry );
    }
    else {
    	texture_vector[0] = texture_list_entry;
    }

	sqc_complex_object_drawing *complex_object = dynamic_cast<sqc_complex_object_drawing*>( object_info->get_drawing() );
	
    if ( !complex_object ) {
    	// sqc_info() << "NOCOMPLEX object " << object_info->get_type_name() << "";
    }
    else
    {
        // sqc_info() << "COMPLEX object <" << object_info->get_type_name() << ">";
        sqc_complex_object_draw_entry_list entries = complex_object->get_entries();
        //const int s = entries.size(); // for test checking
        
        // enumerate complex object list
        //
        int i = 1;
        for (sqc_complex_object_draw_entry_list::iterator it = entries.begin(); it != entries.end(); ++it, ++i)
        {
            sqc_complex_object_draw_entry_ptr entry(*it);

            sqc_string caption = entry->get_caption();

            // select texture name
            //
            bool has_animation = false;
            sqc_string img_name = select_texture_name(entry, has_animation);

			//entry->get_animated_stages();
  
            sqc_string img_noff;
            sqc_string img_key_animation;
 			if (has_animation) {
                img_noff = img_name + "_no_ff";
                img_key_animation = img_name + "_d_animation";
            }
            
            // check exists texture object
            //
            texture_list_entry_t texture_list_entry;

            if (init_texture_vector) {
            	texture_list_entry.object_texture = proxy.get_texture( img_name.c_str(), framework::load_priority_normal );
                texture_list_entry.object_texture_no_ff =  proxy.get_texture( img_noff.c_str(), framework::load_priority_normal );
                texture_list_entry.object_animation =  proxy.get_texture( img_key_animation.c_str(), framework::load_priority_normal );
                texture_vector.push_back(texture_list_entry);
            }
            else {
				texture_list_entry = texture_vector[i];
                if ( !texture_list_entry.object_texture || texture_list_entry.object_texture->get_name() != img_name ) {
                	texture_list_entry.object_texture = proxy.get_texture( img_name.c_str(), framework::load_priority_normal );
                }
                if ( !texture_list_entry.object_texture_no_ff || texture_list_entry.object_texture_no_ff->get_name() != img_noff ) {
                	texture_list_entry.object_texture_no_ff = proxy.get_texture( img_noff.c_str(), framework::load_priority_normal );
                }
                if ( !texture_list_entry.object_animation || texture_list_entry.object_animation->get_name() != img_key_animation ) {
                	texture_list_entry.object_animation = proxy.get_texture( img_key_animation.c_str(), framework::load_priority_normal );
                }

                texture_vector[i] = texture_list_entry;
            }
        } // for (entries...
    } // if (complex_object)
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING


//
//
// sqc_house_base
//
//
void sqc_house_base::enumerate_animation_stages( sqc_string_list &result ) {
    // POPULATION
    result.push_back( "3" );
}

sqc_string sqc_house_base::get_status_image_path() const {
    if( object_state == object_state_standby ) {
        return "status_population";
    }
    return  sqc_building_base::get_status_image_path();
}

sqc_action sqc_house_base::get_default_action() const {
    if( object_state == object_state_standby ) {
        return action_pick;
    }
    return action_nop;
}

sqc_action sqc_house_base::get_auto_action() const {
    if( object_state == object_state_standby ) {
        return action_pick;
    }
    return action_nop;
}

bool sqc_house_base::is_single_click_action( sqc_action action ) {
    return true;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_house_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner ) {
	if (object_state==object_state_building) {
		return sqc_building_base::fill_bubble_content(bubble , owner);
	}
	/// title
	sqc_city_object_base::fill_bubble_content( bubble , owner);
	if (owner!=sqc_country_owner_me)
		return true;
	
	sqc::framework::sqc_bubble_element element;
	if (get_process_end()>0) {
		element.tag = "time";
		element.value = get_process_end();
		bubble.elements.push_back(element);
		element.value = 0;
	}
	
	int population = info::info_cast<sqc_city_object_info>(object_info.get())->get_population_increase();
	if (population!=0) {
		element.tag = "info";
		element.icon = "bubble_icon_people";
		element.text = sqc::framework::framework().formats().format_digit_grouping( population );
		if (population>0)
			element.text = sqc_string("+") + element.text;
		bubble.elements.push_back(element);
	}
	
	if (object_state==object_state_standby) {
		element.tag = "button";
		element.text = sqc::framework::framework().strings().load("*CityActionPick","Pick");
		element.icon = "bubble_icon_people";
		element.action = action_pick;
		bubble.elements.push_back(element);
	}
	return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_house_base::do_parse_xml( xml::xml_node_ptr node ) {
    sqc_object_state old_state = object_state;
	const bool res = sqc_building_base::do_parse_xml( node );
	/// @todo local processing hack
	tooltips.clear();
	if ( (old_state==object_state_wait_update) &&
		(object_state==object_state_working) ) {
		sqc_string buf;
		int population_increase = info::info_cast<sqc_city_object_info>(object_info.get())->get_population_increase();
		int extra_exp = info::info_cast<sqc_city_object_info>(object_info.get())->get_extra_exp();
		buf = sqc_string("+ ")+sqc::framework::framework().formats().format_digit_grouping(population_increase);
		tooltips.push_back( sqc_tooltip_data(buf,surf::surf_color(255/255.0,200/255.0,0/255.0,1)));
		tooltips.back().icon = "icon_population_pl";
		buf = sqc_string("+ ")+sqc::framework::framework().formats().format_digit_grouping(extra_exp);
		tooltips.push_back( sqc_tooltip_data(buf,surf::surf_color(247/255.0,187/255.0,255/255.0,1)));
		tooltips.back().icon = "icon_exp_pl";
	}
	return res;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

//
//
// sqc_leisure_base
//
//
void sqc_leisure_base::enumerate_animation_stages( sqc_string_list &result ) {
    // POPULATION
    result.push_back( "4" );
}

sqc_string sqc_leisure_base::get_status_image_path() const {
    if( object_state == object_state_dirty ) {
        return "status_tax";
    }
    return  sqc_building_base::get_status_image_path();
}

sqc_action sqc_leisure_base::get_default_action() const {
    if( object_state == object_state_dirty ) {
        return action_clean;
    }
    return action_nop;
}

sqc_action sqc_leisure_base::get_auto_action() const {
    if( object_state == object_state_dirty ) {
        return action_clean;
    }
    return action_nop;
}

bool sqc_leisure_base::is_single_click_action( sqc_action action ) {
    return true;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_leisure_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble, sqc_country_owner owner ) {
	if (object_state==object_state_building) {
		return sqc_building_base::fill_bubble_content( bubble , owner );
	}
	/// fill title
	sqc_city_object_base::fill_bubble_content( bubble, owner );
	if (owner!=sqc_country_owner_me)
		return true;
	sqc::framework::sqc_bubble_element element;
	if ( get_process_end() > 0 )
	{
		sqc::framework::sqc_bubble_element element;
		element.tag = "time";
		element.value = get_process_end();
		bubble.elements.push_back(element);
	}
	int max_population = info::info_cast<sqc_city_object_info>(object_info.get())->get_max_population_increase();
	if (max_population!=0) {
		element.tag = "info";
		element.icon = "bubble_icon_people";
		element.text = sqc::framework::framework().formats().format_digit_grouping( max_population );
		if (max_population>0)
			element.text = sqc_string("+") + element.text;
		bubble.elements.push_back(element);
	}
	
	int coins = info::info_cast<sqc_city_object_info>(object_info.get())->get_extra_coins();
	if (coins>0) {
		element.tag = "info";
		element.icon = "bubble_icon_money";
		element.text = sqc::framework::framework().formats().format_digit_grouping( coins );
		if (coins>0)
			element.text = sqc_string("+") + element.text;
		bubble.elements.push_back(element);
	}
	
	if (object_state==object_state_dirty) {
		element.tag = "button";
		element.icon = "bubble_icon_money";
		element.action = action_clean;
		element.text = sqc::framework::framework().strings().load("*CityActionTax","Tax");
		bubble.elements.push_back(element);
	}
	return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_leisure_base::do_parse_xml( xml::xml_node_ptr node ) {
	sqc_object_state old_state = object_state;
	bool res = sqc_building_base::do_parse_xml( node );
	/// @todo local processing hack
	tooltips.clear();
	if ( (old_state==object_state_wait_update) &&
		((object_state==object_state_working)||
		 (object_state==object_state_abandoned))) {
		sqc_string buf;
		/// @todo calc coins
		int add_coins = info::info_cast<sqc_city_object_info>(object_info.get())->get_extra_coins();
		int extra_exp = info::info_cast<sqc_city_object_info>(object_info.get())->get_extra_exp();
		if (add_coins>0) {
			buf = sqc_string("+ ")+sqc::framework::framework().formats().format_digit_grouping(add_coins);
			tooltips.push_back( sqc_tooltip_data(buf,surf::surf_color(255/255.0,238/255.0,22/255.0,1)));
		} else {
			buf = sqc::framework::framework().formats().format_digit_grouping(add_coins);
			tooltips.push_back( sqc_tooltip_data(buf,surf::surf_color(1,0,0,1)));
		}
		tooltips.back().icon = "icon_money_pl";
		buf = sqc_string("+ ")+sqc::framework::framework().formats().format_digit_grouping(extra_exp);
		tooltips.push_back( sqc_tooltip_data(buf,surf::surf_color(247/255.0,187/255.0,255/255.0,1)));
		tooltips.back().icon = "icon_exp_pl";
	}
	return res;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING


//
//
// sqc_terrain_base
//
//
void sqc_terrain_base::enumerate_animation_stages( sqc_string_list &result ) {
    // WORKING
    result.push_back( "2" );
}

//
//
// sqc_power_base
//
//
void sqc_power_base::enumerate_animation_stages( sqc_string_list &result ) {
    // WORKING
    result.push_back( "2" );
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_power_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner) {
	if (object_state==object_state_building)
    {
        return sqc_building_base::fill_bubble_content(bubble,owner);
    }
	sqc_city_object_base::fill_bubble_content( bubble,owner );
	sqc::framework::sqc_bubble_element element;
	int power = info::info_cast<sqc_city_object_info>(object_info.get())->get_power_produce();
	if (power!=0) {
		element.tag = "info";
		element.icon = "bubble_icon_power";
		element.text = sqc::framework::framework().formats().format_digit_grouping( power );
		if (power>0)
			element.text = sqc_string("+") + element.text;
		bubble.elements.push_back(element);
	}
	return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

//
//
// sqc_factory_base
//
//
void sqc_factory_base::enumerate_animation_stages( sqc_string_list &result ) {
    result.push_back( "2" );
    result.push_back( "3" );
    result.push_back( "4" );
    result.push_back( "5" );
    result.push_back( "6" );
}

void sqc_factory_base::enumerate_textures( sqc_texture_info_list &result ) {
    if (enumerate_complex_object_textures(result)) {
        return;
    }

    sqc_city_drawing *city_drawing = static_cast<sqc_city_drawing*>( object_info->get_drawing() );
    if( city_drawing && !city_drawing->get_custom_image().empty() ) {
        sqc_building_base::enumerate_textures( result );
        return;
    }
    
    sqc_string_list animated_stages;
    enumerate_animation_stages( animated_stages );
    
    for( sqc_string_list::const_iterator i = animated_stages.begin(); i != animated_stages.end(); ++i ) {
        sqc_string image_path = get_image_path();
        
        sqc_string  bn;
        {
            int n = atoi( i->c_str() );
            std::stringstream   s;
            s << n-1;
            bn = s.str();
        }
        
        result.push_back( sqc_texture_info( image_path+"_v1_" + bn, true, false, false ) ); 
        if( can_rotate() ) result.push_back( sqc_texture_info( image_path+"_v2_" + bn, true, false, true ) ); 
        
        if( city_drawing ) {
            if( city_drawing->is_animated_stage( *i ) ) {
                if( city_drawing->get_no_first_frame() ) {
                    result.push_back( sqc_texture_info( image_path+"_v1_" + bn + "_no_ff", true, false, false ) ); 
                    if( can_rotate() ) result.push_back( sqc_texture_info( image_path+"_v2_" + bn + "_no_ff", true, false, true ) ); 
                }
                
                result.push_back( sqc_texture_info( image_path + "_0_" + *i + "_animation", true, true, false ) ); 
                if( can_rotate() ) result.push_back( sqc_texture_info( image_path + "_1_" + *i + "_animation", true, true, true ) ); 
            }
        }
    }
    
    if( !has_building_stage() ) {
        return;
    }
    //
    // object can be created - building stage is important
    // 
    
    sqc_string  build_path = get_building_image_path();
    result.push_back( sqc_texture_info( build_path+"_v1", true, false, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_v2", true, false, true ) ); 
    
    result.push_back( sqc_texture_info( build_path+"_v1_no_ff", true, false, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_v2_no_ff", true, false, true ) ); 
    
    result.push_back( sqc_texture_info( build_path+"_0_1_animation", true, true, false ) ); 
    result.push_back( sqc_texture_info( build_path+"_1_1_animation", true, true, true ) ); 
}


sqc_string sqc_factory_base::get_main_texture_path() const {
    if( object_state == object_state_building ) {
        return sqc_building_base::get_main_texture_path();
    }
    
    sqc_string texture_key;
    texture_key = get_image_path();
    texture_key += (get_orientation() ? "_v2_" : "_v1_");
    texture_key += '0' + ((int)object_state - 1);
    
    return texture_key;
}

sqc_string sqc_factory_base::get_status_image_path() const {
    if( object_state == object_state_standby ) {
        return "status_standby";
    }
    else if( object_state == object_state_dirty ) {
        return "status_clean";
    }
    else if( object_state == object_state_abandoned ) {
        return "status_factory_ready";
    }
    else if( object_state == object_state_expired ) {
        return "status_factory_expired";
    }
    return  sqc_building_base::get_status_image_path();
}

sqc_action sqc_factory_base::get_default_action() const {
    if( object_state == object_state_standby ) {
        return action_load;
    }
    else if( object_state == object_state_dirty ) {
        return action_clean;
    }
    else if( object_state == object_state_abandoned ) {
        return action_pick;
    }
    else if( object_state == object_state_expired ) {
        return action_pick;
    }
    else if( object_state == object_state_working ) {
        return action_cancel;
    }
    return action_nop;
}

bool sqc_factory_base::is_single_click_action( sqc_action action ) {
    if( action == action_pick || action == action_clean ) {
        return true;
    }
    return false;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_factory_base::fill_bubble_content( sqc::framework::sqc_bubble_content& bubble , sqc_country_owner owner) {
	if (object_state == object_state_building || (owner != sqc_country_owner_me)) {
		return sqc_building_base::fill_bubble_content( bubble , owner);
	}
	/// title
	sqc_city_object_base::fill_bubble_content( bubble, owner );
	sqc::framework::sqc_bubble_element element;
	if (object_state==object_state_standby) {
		element.tag = "status";
		element.text = sqc::framework::framework().strings().load("*CityFactoryStateStandby","Standby");
		element.icon = "bubble_icon_standby";
		bubble.elements.push_back(element);
		
		element.tag = "button";
		element.text = sqc::framework::framework().strings().load("*CityFactoryActionLoad","Load!");
		element.icon = "bubble_icon_standby";
		element.action = action_load;
		bubble.elements.push_back(element);
	} else if (object_state==object_state_working) {
		element.tag = "status";
		element.text = sqc::framework::framework().strings().load("*CityFactoryStateWorking","Working...");
		element.icon = "bubble_icon_working";
		bubble.elements.push_back(element);
		
		if (get_process_end()>0) {
			element.tag = "time";
			element.value = get_process_end();
			element.text = sqc_string( sqc::framework::framework().strings().load("*CityFactoryRemaining","Remaining: ") )+sqc_string(" ")+sqc_bubble_time_marker;
			element.icon = "";
			bubble.elements.push_back(element);
		}
		{
			sqc::framework::sqc_bubble_element element;
			element.tag = "button";
			element.text = sqc::framework::framework().strings().load("*CityFactoryActionCancel","Cancel!");
			element.icon = "bubble_icon_standby";
			element.action = action_cancel;
			bubble.elements.push_back(element);
		}
	}
	return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

/*- (void) invokeMultiCommand:(NSString*)command withArgs:(NSDictionary*) args {
	if( [command isEqualToString:@"cancel"] ) {
        if ( ![[CommandManager sharedManager] countByItem:self.objectId andCommand:@"cancel"]) {
            
            AppDelegateBase *appDelegate = (AppDelegateBase *) [[UIApplication sharedApplication] delegate];
            [appDelegate playSound:@"cancel"];
            
            [[CommandManager sharedManager] addCommand:@"cancel" withObject:self params:nil delay:c_default_command_delay];
        }
	}
    else if( [command isEqualToString:@"pick"] ) {
		if ( ![[CommandManager sharedManager] countByItem:self.objectId andCommand:@"pick"]) {
            
            AppDelegateBase *appDelegate = (AppDelegateBase *) [[UIApplication sharedApplication] delegate];
            [appDelegate playSound:@"sale"];
            
			[[CommandManager sharedManager] addCommand:@"pick" withObject:self params:nil delay:c_default_command_delay];
		}
	}
    else if( [command isEqualToString:@"clean"] ) {
		if ( ![[CommandManager sharedManager] countByItem:self.objectId andCommand:@"clean"]) {
            
            AppDelegateBase *appDelegate = (AppDelegateBase *) [[UIApplication sharedApplication] delegate];
            [appDelegate playSound:@"cancel"];
            
			[[CommandManager sharedManager] addCommand:@"clean" withObject:self params:nil delay:c_default_command_delay];
		}
	}
    else if( [command isEqualToString:@"load"] ) {
        iCityAppDelegate    *cityDelegate = (iCityAppDelegate*)[UIApplication sharedApplication].delegate;
        NSLog(@"%@",[self getContracts]);
        [cityDelegate showContracts:[self getContracts] target:self action:@selector(completeLoadAction:) object:self];
        
    }
    else {
        [super invokeMultiCommand:command withArgs:args];
    }
}*/



//
//
// road, road
//
//

#ifndef SQC_OBJECT_DISABLE_DRAWING
void sqc_road_base::reload_textures() {
    sqc_string texture_key;
    
    texture_key = get_image_path();
    sqc_texture_proxy & proxy = framework::framework().texture_proxy();
	
    object_texture = proxy.get_texture( texture_key.c_str(), framework::load_priority_normal );
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
void sqc_road_base::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv, const sqc_game_object_draw_args& draw_arg ) {
    if( road_type != road_type_undefined && is_texture_ready( object_texture )) {
        surf::surf_point   pos = coord_conv.field_to_screen( get_position() );
        
        sqc_texture_draw_info   draw_info;
        draw_info.use_tile = true;
        draw_info.tile_info.tile_size = sqc_size( 50*2, 25*2 );
        draw_info.tile_info.tile_cols = 5;
        draw_info.tile_info.tile_rows = 5;
        draw_info.tile_info.tile_no = road_type;;
        object_texture->draw( ctx, pos, draw_info );
    }
    else {
        sqc_game_object::render( ctx, coord_conv, draw_arg );
    }
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_road_base::check_point_on_object( surf::surf_point const &point, sqc_coord_convertor &coord_conv ) {
    sqc_point   coords = coord_conv.screen_to_field( point );
    return coords == get_position();
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

//
// sqc_buildsite_base
//
sqc_action sqc_buildsite_base::get_default_action() const {
    return action_choose_material;
}

bool sqc_buildsite_base::is_single_click_action( sqc_action action ) {
    return false;
}

bool sqc_buildsite_base::is_buildsite_produce() {
    sqc_city_buildingsite_info_ptr buildsite_info = std::tr1::static_pointer_cast<sqc_city_buildingsite_info>(object_info);    
    return buildsite_info->get_produce().size() != 0;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_buildsite_base::do_parse_xml( xml::xml_node_ptr node ) {
    sqc_building_base::do_parse_xml( node );
    
    info::sqc_object_info_provider_ptr ip = city_framework().object_factory();
    sqc_string inp_fill = node->get_attribute( "input_fill");
    
    if (inp_fill.size()) {
        sqc_string_vector pairs = split(inp_fill, ',');
        
        for (sqc_string_vector::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
            sqc_string_vector materials = split(*it, ':');
            
            sqc_string_vector::const_iterator id_it = materials.begin();
            if ( materials.end() == id_it ) {
            	sqc_assert( false );
                continue;
            }
            
            sqc_string_vector::const_iterator count_it = id_it + 1;
            if ( materials.end() == count_it ) {
            	sqc_assert( false );
                continue;
            }
                
            const sqc_string& material_type_id = *id_it;
            const sqc_string& material_count = *count_it;
            
            set_input_fill()[material_type_id] = material_count;
            
            sqc_int type_id = atoi( material_type_id.c_str() );
            sqc_int quantity = atoi( material_count.c_str() );
            sqc_assert( type_id );
            sqc_assert( quantity );
            
            info::sqc_city_object_info *info = static_cast<info::sqc_city_object_info*>( ip->get_object_info(type_id) );
            
            if ( info ) {
                material_quantity[ info->get_type_name() ] = quantity;
            }
        }
    }
    
    return true;
}
#endif // #ifndef SQC_OBJECT_DISABLE_DRAWING

sqc_string_vector sqc_buildsite_base::split(const std::string& source, char delim ) 
{
    sqc_string_vector result;
    
    std::istringstream stream(source);
    std::string str;
    
    while (std::getline(stream, str, delim))
    {
        result.push_back(str);
    }
    
    return result;
}

//
// sqc_building_place_base
//
sqc_action sqc_building_place_base::get_default_action() const {
    return action_purchase_building_site;
}

bool sqc_building_place_base::is_single_click_action( sqc_action action ) {
    return false;
}



void sqc_railroad_base::enumerate_textures(sqc_texture_info_list &result) {
    result.push_back(sqc_texture_info( object_info->get_image_path() + "_v1", true, false, false ) ); 
    result.push_back(sqc_texture_info( object_info->get_image_path() + "_v2", true, false, false ) ); 
    
    sqc_city_drawing *city_drawing = static_cast<sqc_city_drawing*>( object_info->get_drawing() );
    if (city_drawing) {
        sqc_string custom_build_icon = city_drawing->get_custom_build_icon();
        if( !custom_build_icon.empty() && custom_build_icon != "none" ) {
            result.push_back( sqc_texture_info( custom_build_icon , false, false, false ) );
        }
    }  
}

//
//	city hall automation
//
class sqc_city_hall_automation : public  sqc_automation {
public:
	sqc_city_hall_automation() {
    }
    virtual bool automate( sqc_action action, int auto_points ) {
    
#ifndef SQC_OBJECT_DISABLE_DRAWING
        sqc_field_ptr field = get_field();    
        if ( !field ) {
            return false;
        }
        
        using namespace std::tr1::placeholders;
        sqc_game_object_ptr ptr_object = field->find_first( 
        	std::tr1::bind( &sqc_city_hall_automation::find_first_object, this, _1, action ) );
        
        if ( !ptr_object ) {
        	return false;
        }
        
        
        using namespace processor;
        sqc_command_ptr  command;
        sqc_string str_user_id = "";
    
        if( action == action_pick ) { 
            command.reset( new sqc_pick_command( str_user_id, ptr_object->get_id(), auto_points ) );
        }
        else if( action == action_clean ) {
            command.reset( new sqc_clean_command( str_user_id, ptr_object->get_id(), auto_points ) );
        }
        
        processor::sqc_command_processor&	cmd_processor = country_framework().cmd_processor();
        if ( command ) {
	        cmd_processor.schedule( command, command_priority_idle );
        }
#endif        
    	return true;
    }
protected:
#ifndef SQC_OBJECT_DISABLE_DRAWING
	bool find_first_object( sqc_game_object_ptr obj, sqc_action action ) const {
    
	    if ( action == obj->get_auto_action() ) {
        	return true;
        }
    	return false;
    }   
protected:
    sqc_field_ptr get_field() const {
    
    	sqc_framework_base& framework = country_framework();
        
        sqc_game_ptr game = framework.game();
        if ( !game ) {
            return sqc_field_ptr();
        }
        
        sqc_field_ptr field = game->get_field();    
        if ( !field ) {
            return sqc_field_ptr();
        }
        
        return field;
    }
#endif
    
    
};

//
//	city hall
//

sqc_city_hall::sqc_city_hall( sqc_object_info_ptr i ) 
    : sqc_building_base( i )
    , m_last_run_time( 0 ) {
    m_automation.reset( new sqc_city_hall_automation );
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
bool sqc_city_hall::do_parse_xml( xml::xml_node_ptr node ) {

	bool res = sqc_building_base::do_parse_xml( node );
    if ( !res ) {
    	return false;
    }
    
    fiscal_agent_id		= node->get_attribute( "input_fill" );
    municipal_oficer_id	= node->get_attribute( "output_fill" );

	return true;
}
#endif

const sqc_string& sqc_city_hall::get_fiscal_agent_id() const {
    return fiscal_agent_id;
}

const sqc_string& sqc_city_hall::get_municipal_oficer_id() const {
    return municipal_oficer_id;
}

#ifndef SQC_OBJECT_DISABLE_DRAWING
void sqc_city_hall::handle_timer() {

	sqc_building_base::handle_timer();
    
    if( object_state != object_state_standby ) {
    	return;
    }
    
    if ( !m_automation ) {
        return;
    }

	//
    //	check active tool
    //
    sqc_framework_base& framework = country_framework();
    
    tools::sqc_tools_controlles& tools = framework.tools();
    tools::sqc_tool_type active_tool = tools.get_active_tool();
    if ( tools::tool_type_multi != active_tool ) {
        return;
    }

	//
    //	check for time
    //
    sstl::time_mks	now = 0;
    sstl::get_current_time_mks( now );
    
    if ( now - m_last_run_time < m_interval ) {
        return;
    }
    m_last_run_time = now;

    
    //
    //	check auto operations count
    //
	{
        sqc_game_ptr game = framework.game();
        if ( !game ) {
            return;
        }
        
        sqc_common_scene_info info;
        game->fill_common_info( info );
        
        if ( info.auto_operations <= 2 ) {
        	return;
        }
    }
    
    //
    //	automate!!!
    //
    {
	    int	auto_points = get_fiscal_agent_auto_points();
        if ( auto_points ) {
        	m_automation->automate( action_clean, auto_points );
        }
    }

    {
	    int	auto_points = get_municipal_oficer_auto_points();
        if ( auto_points ) {
        	m_automation->automate( action_pick, auto_points );
        }
    }
    
}
#endif
int	sqc_city_hall::get_fiscal_agent_auto_points() const {
	if ( fiscal_agent_id.empty() ) {
    	return 0;
    }
    
    if ( fiscal_agent_id == none_agent_id ) {
	    return 0;
    }

    if ( fiscal_agent_id == internal_fiscal_agent_id ) {
	    return 2;
    }
    
    return 1;
    
}

int	sqc_city_hall::get_municipal_oficer_auto_points() const {
	if ( municipal_oficer_id.empty() ) {
    	return 0;
    }
    
    if ( municipal_oficer_id == none_agent_id ) {
	    return 0;
    }

    if ( municipal_oficer_id == internal_municipal_oficer_id ) {
	    return 2;
    }
    
    return 1;
    
}


#endif //#ifdef SQC_ENABLE_OBJECTS
END_NAMESPACE_SQC_CITY
