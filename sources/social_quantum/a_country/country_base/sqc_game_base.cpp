/*
 *  sqc_game_base.cpp
 *  aCountry
 *
 *  Created by Andrey Yamov on 7/5/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_game_base.h"
#include "country_base/sqc_framework_base.h"
//
// game
//

NAMESPACE_SQC_FRAMEWORK

sqc_game_base::sqc_game_base() 
: m_level( 0 )
, m_exp( 0 )
, m_current_level_exp( 0 )
, m_next_level_exp( 1 )
, m_gold( 0 )
, m_coins( 0 )
, m_spent_coins( 0 )
, m_auto_points( 0 )
, m_league_number(0)
, m_league_level(0)
{
    
}

void sqc_game_base::parse_xml( xml::xml_node_ptr node ) {
    using namespace xml;
    
    /*
    // Uncommit for test "level_up" checker.
    // Warning: you should restart settings
    // on you device, after testing.
    if(true)
    {
       node->set_attribute_int( "level", 51 );
    }
    */
    
    //
    // read data
    //
    m_owner             = node->get_attribute( "owner_id" );
    
    m_level             = node->get_attribute_int( "level" );
    
    m_exp               = node->get_attribute_int( "exp" );
    m_current_level_exp = node->get_attribute_int( "current_level_exp" );
    m_next_level_exp    = node->get_attribute_int( "next_level_exp" );
    
    m_gold              = node->get_attribute_int( "gold" );
    m_spent_coins       = node->get_attribute_int( "spent_coins" );
    m_auto_points       = node->get_attribute_int( "auto_points" );
    m_coins             = node->get_attribute_int( "coins" );


    
    
    //
    // read sub-items
    //
    xml_node_list  childs;
    node->get_childs( childs );
    
    for( xml_node_list::const_iterator i = childs.begin(); i != childs.end(); ++i ) {
        xml_node_ptr    child_node( *i );
        xml_string      entry_name( child_node->get_name() );
        
        if( entry_name == "league")
        {   
            m_league_level  = child_node->get_attribute_int( "league_level" );                 
            m_league_number = child_node->get_attribute_int( "league_number" );
        }
        
        if( entry_name == "field" ) {
            m_field->parse_xml( child_node );
        }
    }
    
    //
    //	received gifts
    //
    fill_received_gifts( node );

    //
    //	available gifts
    //
    fill_available_gifts( node );
    
    //
    //	wishes gifts
    //
    
    fill_wishes_gifts(node);
    
    //
    //	user friends in game
    //
    
    fill_game_friends( node );
    
    //
    // barn items
    //
    
    fill_barn( node );
    
    fill_necessary_material();
}

void sqc_game_base::render( surf::surf_context_ptr ctx ) {
}

sqc_field_ptr sqc_game_base::get_field() {
	return m_field;
}
    
sqc_string sqc_game_base::get_owner() {
	return m_owner;
}

void sqc_game_base::fill_common_info( sqc_common_scene_info &info ) {
	PROFILE_ENTRY_REALTIME( "sqc_game_base::fill_common_info" );
    
    info.level = m_level;
    info.coins = m_coins;
    info.bucks = m_gold;
    
    
    info.experience		= m_exp;
    info.max_experience	= m_next_level_exp;
    info.min_experience	= m_current_level_exp; 
    
    info.league_number	= m_league_number;
    info.league_level 	= m_league_level;
}

bool sqc_game_base::is_necessary_material( const sqc_string& material_type_name ) const {
    return ( m_necessary_materials.end() != m_necessary_materials.find( material_type_name ) );
}

struct sqc_game_base::enum_game_objects_context {
    sqc_quantity_by_name_map	total_by_name;
    sqc_quantity_by_name_map	count_by_name;
};

bool sqc_game_base::fill_necessary_material() {
	
	m_necessary_materials.clear();
    
	enum_game_objects_context enum_ctx;
    if ( m_field ) {
        m_field->foreach_object( 
            std::tr1::bind( &sqc_game_base::enum_game_object, 
                            this, 
                            std::tr1::placeholders::_1, 
                            std::tr1::ref( enum_ctx ) ) );
    } else {
    	sqc_assert( false );
    }

	sqc_object_info_provider_ptr info_provider = country_framework().object_factory();
    if ( !info_provider ) {
    	sqc_assert( false );
        return false;
    }
    
    // create necessary materials
    {
        for ( sqc_quantity_by_name_map::const_iterator it = enum_ctx.total_by_name.begin();
        	it != enum_ctx.total_by_name.end(); ++it ) {
            
            const sqc_string& material_type_name = it->first;
            const sqc_int material_total = it->second;
            
            sqc_int remains = material_total;
            
            sqc_int material_type_id = 0;
            {
	        	sqc_object_info* info = info_provider->get_object_info( material_type_name.c_str() );
                if ( info ) {
                	material_type_id = info->get_type_id();
                }
            }
            
            if ( !material_type_id ) {
            	continue;
            }
            
            sqc_quantity_by_name_map::const_iterator it_count = enum_ctx.count_by_name.find( material_type_name );
            if ( it_count != enum_ctx.count_by_name.end() ) {
            	remains -= it_count->second;
            }
            
            if ( remains > 0 ) {
            	m_necessary_materials[material_type_name] = remains;
                sqc_info() << "sqc_game_base: need material: " << material_type_name << " :" << remains;
            }
        }
    }
    
    return true;
}

void sqc_game_base::enum_game_object( 
    const sqc_game_object_ptr& obj,
    enum_game_objects_context& material_ctx ) {
    
    sqc_assert( obj );

	// update totals from type_info (material_type_name->total)
    {
        sqc::info::sqc_object_info_ptr object_type_info = obj->get_object_info();
        if ( !object_type_info ) {
            sqc_assert( false );
            return;
        }
        
        sqc_quantity_by_name_map const& map_total = object_type_info->get_materials_quantity();
        for ( sqc_quantity_by_name_map::const_iterator it = map_total.begin();
        	it != map_total.end(); ++it ) {
            material_ctx.total_by_name[it->first] += it->second;
        }
	}    
    
    // update count from object (material_type_id->count)
    {
        sqc_quantity_by_name_map const& map_count = obj->get_materials_quantity();
        for ( sqc_quantity_by_name_map::const_iterator it = map_count.begin();
        	it != map_count.end(); ++it ) {
            material_ctx.count_by_name[it->first] += it->second;
        }
    }
    
}

/*
<gifts>
	<received>
		<water_pump id='132596221' from_user_id='3238769609071095966' quantity='1'  />
		<rope id='127136047' from_user_id='3238769609071095966' quantity='1'  />
		<yellow_flower_patch id='123767969' from_user_id='3238769609071095966' quantity='1'  />
	</received>
	<available>
		<brick id='333403507' quantity='1' new='true' />
		<steel id='333403506' quantity='1' new='true' />
	</available>
</gifts>
*/

bool sqc_game_base::fill_received_gifts( xml::xml_node_ptr xml ) {

    xml::xml_node_ptr gifts_node = xml->find( "gifts" );
    if ( gifts_node ) {
    	gifts_node = gifts_node->find( "received" );
    }
    
    if ( !gifts_node ) {
    	sqc_info() << "sqc_game_base: xml has no received_gifts node";
        return false;
    }
    
    m_received_gifts.clear();

    xml::xml_node_list gift_entries;
    gifts_node->get_childs( gift_entries );

    for( xml::xml_node_list::const_iterator i = gift_entries.begin(); i != gift_entries.end(); ++i )
    {
        xml::xml_node_ptr    child_node( *i );
        
        sqc_string	type_name		= child_node->get_name();
        sqc_int		id				= child_node->get_attribute_int( "id" );
        sqc_int		quantity 		= child_node->get_attribute_int( "quantity" );
        sqc_string	from_user_id	= child_node->get_attribute( "from_user_id" );
        
        
        sqc_received_gift::sptr sptr( new sqc_received_gift( type_name,
                                                             id,
                                                             quantity,
                                                             from_user_id ) );
        m_received_gifts.push_back( sptr );
    }
    
    sqc_info() << "sqc_game_base: received_gifts count: " << m_received_gifts.size();

    return true;
}

bool sqc_game_base::fill_available_gifts( xml::xml_node_ptr xml ) {

    xml::xml_node_ptr gifts_node = xml->find( "gifts" );
    if ( gifts_node ) {
    	gifts_node = gifts_node->find( "available" );
    }

    if ( !gifts_node ) {
    	sqc_info() << "sqc_game_base: xml has no available_gifts node";
        return false;
    }

    m_available_gifts.clear();

    xml::xml_node_list gift_entries;
    gifts_node->get_childs( gift_entries );

    for( xml::xml_node_list::const_iterator i = gift_entries.begin(); i != gift_entries.end(); ++i )
    {
        xml::xml_node_ptr    child_node( *i );
        
        sqc_string	type_name		= child_node->get_name();
        sqc_int		id				= child_node->get_attribute_int( "id" );
        sqc_int		quantity 		= child_node->get_attribute_int( "quantity" );
        bool		new_gift		= child_node->get_attribute_bool( "new" );
        
        
        sqc_available_gift::sptr sptr( new sqc_available_gift( type_name,
                                                               id,
                                                               quantity,
                                                               new_gift ) );
        m_available_gifts.push_back( sptr );
    }
    
    sqc_info() << "sqc_game_base: available_gifts count: " << m_available_gifts.size();

    return true;
}

bool sqc_game_base::get_wishes_gifts( sqc_wishes::vector& gifts ){

    gifts = m_wishes_gifts;
    return true;
}

bool sqc_game_base::fill_wishes_gifts( xml::xml_node_ptr xml ) {
    
    xml::xml_node_list    node_entries;
        
    xml::xml_node_ptr _node = xml->find( "friends" );

    if( !_node) {
    	sqc_info() << "sqc_game_base: xml has no wishes node";
        return false;
    }
	m_wishes_gifts.clear();
    
    _node->get_childs( node_entries );
        
    sqc::framework::sqc_framework_base  &base_framework = 
        static_cast<sqc::framework::sqc_framework_base  &>( sqc::framework::framework() );
    
    info::sqc_object_info_provider_ptr ip = base_framework.object_factory();
    
    for( xml::xml_node_list::const_iterator i = node_entries.begin(); i != node_entries.end(); ++i )
    {
        xml::xml_node_ptr    child_node( *i );
            
        int m_friend_id  = child_node->get_attribute_int("id");
            
        sqc_string  str = child_node->get_attribute("wish_list");
            
        std::istringstream iss(str);
        sqc_string token;
            
            
        while(getline(iss, token, ','))
        {   
            sqc_object_info *object_info = ip->get_object_info(atoi(token.c_str()));
            
            if(object_info)
            {       
                sqc_wishes::sptr sptr(new sqc_wishes(object_info->get_type_name()
                                            , m_friend_id
                                            , atoi(token.c_str())));
                                            
                m_wishes_gifts.push_back(sptr);
            }
            else
            {
                sqc_info() << "sqc_game_base: can't get object info for object id = " << token.c_str();
            }

        }
    }

    sqc_info() << "sqc_game_base: wishes count: " << m_wishes_gifts.size();
    
    return true;    
}

/*
<friends>
	<friend id='3238769609071095966' level='48' exp='563800' population='2093240' max_population='1956300' have_gift='false'
									request_reward_count='0' 
									bounds='{"size_x":{"x":29,"y":29,"width":41,"height":41},"size_x_2":{"x":15,"y":45,"width":9,"height":9}}'
									respect_level='7' 
									wish_list='10904,10920,10903,10921,11412'
									requests='{"recover_contract":{"time":1318362084,"count":0,"user":[3238769526918291845],"item_id":102976589}}'
									help_items=''/>
	<friend id='3238769527360293873' level='1' exp='29' population='985' max_population='2125' have_gift='false'
									request_reward_count='0'
									bounds='{"size_x":{"x":45,"y":45,"width":9,"height":9}}'
									respect_level='1'
									wish_list=''
									requests='{}'
									help_items=''/>
	<friend id='-42' level='54' exp='860903' population='1327665' max_population='1430825' have_gift='false'
									request_reward_count='0'
									bounds='{"size_x_2":{"y":29,"width":41,"height":41,"x":-17},"size_x":{"y":29,"width":41,"height":41,"x":29}}'
									respect_level='8' wish_list='' requests='{}' help_items=''/>
</friends>
*/

bool sqc_game_base::fill_game_friends( xml::xml_node_ptr xml ) {

    m_game_friends.clear();
    
    xml::xml_node_ptr friends_node = xml->find( "friends" );

    if ( !friends_node ) {
    	sqc_error() << "sqc_game_base: xml has no friends node";
        return false;
    }

    xml::xml_node_list friend_entries;
    friends_node->get_childs( friend_entries );

    for( xml::xml_node_list::const_iterator i = friend_entries.begin(); i != friend_entries.end(); ++i )
    {
        xml::xml_node_ptr    child_node( *i );
        
        sqc_string	id				= child_node->get_attribute( "id" );
        sqc_int		level			= child_node->get_attribute_int( "level" );
        sqc_int		exp				= child_node->get_attribute_int( "exp" );
        sqc_int		population		= child_node->get_attribute_int( "population" );
        sqc_int 	max_population	= child_node->get_attribute_int( "max_population" );
        bool		have_gift		= child_node->get_attribute_bool( "have_gift" );

        sqc_game_friend::sptr sptr( new sqc_game_friend( id, 
        												 level,
                                                         exp,
                                                         population,
                                                         max_population,
                                                         have_gift ) );
        m_game_friends.push_back( sptr );
    }
    
    sqc_info() << "sqc_game_base: friends count: " << m_game_friends.size();

    return true;
}

bool sqc_game_base::get_received_gifts(
	sqc_received_gift::vector& gifts ) {
    
    gifts = m_received_gifts;
    return true;
}

bool sqc_game_base::get_available_gifts( 
	sqc_available_gift::vector& gifts ) {
    
    gifts = m_available_gifts;
    return true;
}

bool sqc_game_base::get_game_friends(
	sqc_game_friend::vector& friends ) {
    
    friends = m_game_friends;
	return true;
}

/*
<barn>
    <black_wool id='113' quantity='1' />
    <lucerne id='414' quantity='1' />
    <corn id='13' quantity='1' />
    <milk id='3' quantity='7' />
    <clover id='2' quantity='6' />
    <wheat id='7' quantity='1' />
</barn>
*/

bool sqc_game_base::fill_barn( xml::xml_node_ptr xml ) {
    
    m_barn.clear();
    
    xml::xml_node_ptr barn_node = xml->find( "barn" );
    
    if ( !barn_node ) {
    	sqc_error() << "sqc_game_base: xml has no barn node";
        return false;
    }
    
    xml::xml_node_list barn_entries;
    barn_node->get_childs( barn_entries );
    
    for( xml::xml_node_list::const_iterator i = barn_entries.begin(); i != barn_entries.end(); ++i )
    {
        xml::xml_node_ptr    child_node( *i );
        
        sqc_string  type        = child_node->get_name();
        sqc_int		id			= child_node->get_attribute_int( "id" );
        sqc_int		quantity	= child_node->get_attribute_int( "quantity" );
        
        sqc_barn_item::sptr sptr( new sqc_barn_item( type,
                                                     id, 
                                                     quantity ) );
        m_barn.push_back( sptr );
    }
    
    sqc_info() << "sqc_game_base: barn items count: " << m_barn.size();
    
    return true;
}

bool sqc_game_base::get_barn( sqc_barn_item::vector& barn ) {
    
    barn = m_barn;
	return true;
}


END_NAMESPACE_SQC_FRAMEWORK


