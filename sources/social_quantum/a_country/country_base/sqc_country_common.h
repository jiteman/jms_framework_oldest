#pragma once

//#include "sqc_defs.h"
#include "../sqc/sqc_base.h"

NAMESPACE_SQC

/// object selection type
enum	sqc_game_object_selection_type {
    sqc_game_object_selection_type_none,    ///< none, object not selected
    sqc_game_object_selection_type_normal,  ///< normal selection, countour
    sqc_game_object_selection_type_edit,    ///< eited object ( typicaly green fill )
    sqc_game_object_selection_type_invalid  ///< invalid object status ( typicaly red fill )
};



enum sqc_gift_type {
	sqc_gift_received,
    sqc_gift_available,
    sqc_gift_wishes
};

///
///	Base gift class. The class contains base information about the received gifts
///
class sqc_gift { 
public:
	sqc_gift( 
	    const sqc_string& type_name,	//type name in shop
    	const sqc_int id,				// gift id
    	const sqc_int quantity ) 
        : m_type_name( type_name )
        , m_id( id )
        , m_quantity( quantity ) {
    }
              
	typedef std::tr1::shared_ptr<sqc_gift>	sptr;
	typedef std::vector<sqc_gift::sptr>		vector;
                          
	const sqc_string&	type_name() const {
    	return m_type_name;
    }
	/// Returns gift id
    const sqc_int		id() const {
    	return m_id;
    }
    const sqc_int 		quantity() const {
    	return m_quantity;
    }
    
    virtual sqc_gift_type	gift_type() const = 0;

protected:
	sqc_string	m_type_name;
	sqc_int		m_id;
    sqc_int 	m_quantity;
};

//
//	received gift class
//
class sqc_received_gift : public sqc_gift { 
public:

	typedef std::tr1::shared_ptr<sqc_received_gift>	sptr;
	typedef std::vector<sqc_received_gift::sptr>	vector;

	sqc_received_gift( 
	    const sqc_string& type_name,
    	const sqc_int id,
    	const sqc_int quantity,
        const sqc_string from_user_id ) 
        : sqc_gift( type_name, id, quantity )
        , m_from_user_id( from_user_id ) {
    }

    virtual sqc_gift_type	gift_type() const {
    	return sqc_gift_received;
    }
                    
	const sqc_string		from_user_id() const {
    	return m_from_user_id;
    }
protected:
	sqc_string				m_from_user_id;
};


//
//	available gift class
//
class sqc_available_gift : public sqc_gift { 
public:
	typedef std::tr1::shared_ptr<sqc_available_gift>	sptr;
	typedef std::vector<sqc_available_gift::sptr>		vector;

	sqc_available_gift( 
	    const sqc_string& type_name,
    	const sqc_int id,
    	const sqc_int quantity,
        const bool is_new ) 
        : sqc_gift( type_name, id, quantity )
        , m_is_new( is_new ) {
    } 
                    
    virtual sqc_gift_type	gift_type() const {
    	return sqc_gift_available;
    }

	const bool	is_new() const {
    	return m_is_new;
    }
protected:
	bool	m_is_new;
};

//
// wishes gift
//

class sqc_wishes : public sqc_gift { 

public:
	typedef std::tr1::shared_ptr<sqc_wishes>	sptr;
	typedef std::vector<sqc_wishes::sptr>		vector;

    sqc_wishes(
                    const sqc_string& type_name
                    , const sqc_dword friend_id
                    , const sqc_int id)                    
    : sqc_gift( type_name, id, 1 )
    , m_friend_id(friend_id) {
    }
    
    virtual sqc_gift_type	gift_type() const {
        return sqc_gift_wishes;
    }
    
    virtual sqc_dword friend_id() const {
        return m_friend_id;
    }
        
    sqc_dword m_friend_id;
};    

//
//	game friend class
//
class sqc_game_friend { 
public:
	typedef std::tr1::shared_ptr<sqc_game_friend>	sptr;
	typedef std::vector<sqc_game_friend::sptr>		vector;

	sqc_game_friend( 
    	const sqc_string id,
        const sqc_int level,
        const sqc_int exp,
        const sqc_int population,
        const sqc_int max_population,
        const bool have_gift ) 
        	: m_id( id )
        	, m_level( level )
        	, m_exp( exp )
        	, m_population( population )
        	, m_max_population( max_population )
        	, m_have_gift( have_gift ) {
    } 
                    
    virtual sqc_string	id() const {
    	return m_id;
    }
    virtual sqc_int	level() const {
    	return m_level;
    }
    virtual sqc_int	exp() const {
    	return m_exp;
    }
    virtual sqc_int	population() const {
    	return m_population;
    }
    virtual sqc_int	max_population() const {
    	return m_max_population;
    }

	const bool	have_gift() const {
    	return m_have_gift;
    }
protected:
	sqc_string	m_id;
	sqc_int		m_level;
    sqc_int		m_exp;
    sqc_int		m_population;
    sqc_int		m_max_population;
    bool		m_have_gift;
};

/// Person info. Contains basic person info
struct sqc_person_info {
	sqc_person_info( sqc_string id_p,
                     sqc_string name_p,
                     sqc_string avatar_p,
        			 int level_p,
                     bool local_avatar_p )
    	: avatar(avatar_p)
        , id(id_p)
        , name(name_p)
        , level(level_p)
        , local_avatar( local_avatar_p )
    {
    }
	
    sqc_string	id;
    sqc_string	name;
    sqc_string	avatar;
    int			level;
    bool		local_avatar;
};

/// List of person info.
typedef std::vector<sqc_person_info> sqc_person_info_list_type;

//
// Barn item struct
//
struct sqc_barn_item {
    
	typedef std::tr1::shared_ptr<sqc_barn_item>	sptr;
	typedef std::vector<sqc_barn_item::sptr>	vector;
    
	sqc_barn_item( sqc_string type_p,
                    int id_p,
                    int quantity_p )
    : type(type_p)
    , id(id_p)
    , quantity(quantity_p)
    {
    }
	
    sqc_string	type;
    int         id;
    int			quantity;
};


END_NAMESPACE_SQC
