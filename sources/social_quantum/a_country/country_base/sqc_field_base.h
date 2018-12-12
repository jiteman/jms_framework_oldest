#pragma once

#include "../sqc/sqc_xml.h"
#include "../sqc/sqc_base.h"
#include "../framework/sqc_framework_defs.h"
#include "../framework/texture/sqc_texture_builder.h"
#include "sqc_earth_base.h"
#include "sqc_object_selection.h"

NAMESPACE_SQC_FRAMEWORK


class sqc_field_base : public sqc_noncopyable {
public:
    sqc_field_base( info::sqc_object_info_provider_ptr of);
    virtual ~sqc_field_base() {}
    
    virtual void parse_xml( xml::xml_node_ptr xml );
    
    virtual surf::surf_rect calc_rect( sqc_coord_convertor &coord_conv );
    virtual surf::surf_point calc_default_pos( sqc_coord_convertor &coord_conv );

    virtual void render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    
    virtual void render_border( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    virtual void render_objects( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    virtual void render_grid( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    virtual void render_back( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    
    virtual void handle_timer();
    
    virtual bool is_allow_build( sqc_rect const &rect );
    virtual sqc_game_object_ptr get_object_intersect_rect( sqc_rect const &rect, int object_id = 0 );
    virtual sqc_game_object_ptr get_object_by_point( sqc_point const &coords );
    virtual sqc_game_object_ptr get_object_by_screen_point( surf::surf_point const &point, sqc_coord_convertor &coord_conv );
    virtual sqc_game_object_ptr get_object_by_type_id( int type_id );
    virtual sqc_game_object_ptr get_object_by_id( int object_id );
    virtual void get_object_by_type_name( sqc_string const &type_name, sqc_game_object_list& list );
    virtual void get_object_by_type( info::sqc_object_type type, sqc_game_object_list& list );
    virtual bool move_object( sqc_game_object_ptr object, sqc_point const &point );
    virtual bool rotate_object( sqc_game_object_ptr object );
    virtual void zorder_objects();
    
    virtual bool calculate_nearest_process_end( sqc_ddword &next_process_end, int &next_object_id );

    virtual bool add_extra_objects();
    virtual void prepare_back(sqc_coord_convertor &coord_conv);
    
    virtual void set_objects_no_status( bool is_no_status ) {
        m_objects_no_status = is_no_status;
    }
	
	void set_object_selection( sqc_object_selection_ptr s ) {
		m_object_selection = s;
	}
    
	template <class T>
    sqc_game_object_ptr find_first( T f ) {
		for (typename sqc_game_object_list::iterator i=m_objects.begin();i!=m_objects.end();i++) {
			if ( f(*i) ) {
            	return *i;
            }
		}
        return sqc_game_object_ptr();
    }
	
	template <class T>
	void foreach_object( T f ) {
		for (typename sqc_game_object_list::iterator i=m_objects.begin();i!=m_objects.end();i++) {
			f(*i);
		}
	}
protected:
    std::list<sqc_rect>     m_bounds;
    sqc_game_object_list    m_objects;
    info::sqc_object_info_provider_ptr  m_object_factory;
    
    sqc_texture_ptr         m_background_texture;
	sqc_earth_base_ptr		earth_ptr;
	sqc_object_selection_ptr	m_object_selection;
private:
    bool    m_objects_no_status;
    bool    m_objects_no_animation;
};

typedef std::tr1::shared_ptr<sqc_field_base>   sqc_field_ptr;

END_NAMESPACE_SQC_FRAMEWORK
