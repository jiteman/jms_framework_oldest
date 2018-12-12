#pragma once

#include "sqc_field_base.h"
#include "sqc_country_common.h"
#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK 


class sqc_game_base : public sqc_noncopyable {
public:

    sqc_game_base();
    virtual void parse_xml( xml::xml_node_ptr xml );
    void render( surf::surf_context_ptr ctx );

    virtual void	fill_common_info( sqc_common_scene_info &info );

    virtual bool	get_received_gifts( sqc_received_gift::vector& gifts );
    virtual bool	get_available_gifts( sqc_available_gift::vector& gifts );
    virtual bool	get_wishes_gifts( sqc_wishes::vector& gifts );
    virtual bool	get_game_friends( sqc_game_friend::vector& friends );
    virtual bool	get_barn( sqc_barn_item::vector& barn );
    virtual bool	is_necessary_material( const sqc_string& material_type_name ) const;
    
    sqc_field_ptr	get_field();
    sqc_string		get_owner();

//
//	necessary materials
//
protected:
	struct enum_game_objects_context;
    virtual void	enum_game_object( const sqc_game_object_ptr& obj,
                                        enum_game_objects_context& enum_ctx );

	// map by type_name, not by type_id
	typedef std::map<sqc_string,int>	sqc_material_name_map;
	sqc_material_name_map				m_necessary_materials;

    
protected:
	bool 			fill_received_gifts( xml::xml_node_ptr xml );
    bool 			fill_available_gifts( xml::xml_node_ptr xml );
    bool 			fill_wishes_gifts( xml::xml_node_ptr xml );
    bool 			fill_game_friends( xml::xml_node_ptr xml );
    bool 			fill_barn( xml::xml_node_ptr xml );
	bool			fill_necessary_material();
    
protected:
    sqc_field_ptr   m_field;
    
    sqc_string      m_owner;
    int             m_level;
    int             m_exp, m_current_level_exp, m_next_level_exp;
    int             m_gold, m_coins, m_spent_coins, m_auto_points;
    sqc_dword       m_league_number;
    sqc_dword       m_league_level;
    

    sqc_received_gift::vector	m_received_gifts;
    sqc_available_gift::vector	m_available_gifts;
    sqc_wishes::vector     m_wishes_gifts;
    sqc_game_friend::vector		m_game_friends;
    sqc_barn_item::vector       m_barn;
    
    // iCity specific
    //int             population, max_population;
    //int             tax;
};

typedef std::tr1::shared_ptr<sqc_game_base>    sqc_game_ptr;

END_NAMESPACE_SQC_FRAMEWORK
