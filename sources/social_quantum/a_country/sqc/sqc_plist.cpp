#include "sqc_plist.h"

NAMESPACE_SQC_PLIST

//
// dict entry
//

bool sqc_plist_entry_dict::parse_xml( xml::xml_node_ptr node ) {
    sqc_string  current_entry;
    xml::xml_node_list   childs;
    node->get_childs( childs );
    
    for( xml::xml_node_list::const_iterator i = childs.begin(); i != childs.end(); ++i ) {
        xml::xml_node_ptr    child( *i );
        sqc_string  name( child->get_name() );
        
        sqc_plist_entry_ptr new_entry;
        if( name == "key" ) {
            current_entry = child->get_value();
        }
        else if( name == "string" ) {
            new_entry.reset( new sqc_plist_entry_string() );
        }
        else if( name == "integer" ) {
            new_entry.reset( new sqc_plist_entry_int() );
        }
        else if( name == "true" || name == "false" ) {
            new_entry.reset( new sqc_plist_entry_bool() );
        }
        else if( name == "dict" ) {
            new_entry.reset( new sqc_plist_entry_dict() );
        }
        
        if( new_entry ) {
            assert( !current_entry.empty() );
            
            if( new_entry->parse_xml( child ) ) {
                vals[current_entry] = new_entry;
            }
            else {
                return false;
            }
            
            current_entry.clear();
        }
    }
    
    return true;
}

bool sqc_plist_entry_dict::format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml ) {
    xml::xml_node_ptr   node = xml.create_node( "dict", parent );
    for( sqc_plist_iterator i = vals.begin(); i != vals.end(); ++i ) {
        sqc_plist_entry_ptr entry( i->second );

        xml::xml_node_ptr   node_key = xml.create_node( "key", i->first.c_str(), node );
        
        entry->format_xml( node, xml );
    }
    
    return true;
}


bool sqc_plist_entry_dict::get_value_bool( sqc_string const &entry ) const {
    sqc_plist_entry_ptr ptr = get_value( entry );
    if( !ptr )  return bool();
    return ptr->get_value_bool();
}

int sqc_plist_entry_dict::get_value_int( sqc_string const &entry ) const {
    sqc_plist_entry_ptr ptr = get_value( entry );
    if( !ptr )  return int();
    return ptr->get_value_int();
}

sqc_string sqc_plist_entry_dict::get_value_string( sqc_string const &entry ) const {
    sqc_plist_entry_ptr ptr = get_value( entry );
    if( !ptr )  return sqc_string();
    return ptr->get_value_string();
}

sqc_plist_entry_ptr sqc_plist_entry_dict::get_value( sqc_string const &entry ) const      {
    sqc_plist_iterator  i = vals.find( entry );
    if( i != vals.end() ) {
        return i->second;
    }
    return sqc_plist_entry_ptr();
}

void sqc_plist_entry_dict::set_value_bool( sqc_string const &entry, bool val ) {
    set_value( entry, sqc_plist_entry_ptr( new sqc_plist_entry_bool( val ) ) );
}

void sqc_plist_entry_dict::set_value_int( sqc_string const &entry, int val ) {
    set_value( entry, sqc_plist_entry_ptr( new sqc_plist_entry_int( val ) ) );
}

void sqc_plist_entry_dict::set_value_string( sqc_string const &entry, sqc_string const &val ) {
    set_value( entry, sqc_plist_entry_ptr( new sqc_plist_entry_string( val ) ) );
}

void sqc_plist_entry_dict::set_value( sqc_string const &entry, sqc_plist_entry_ptr val ) {
    vals[entry] = val;
}


//
// plist class
//
void sqc_plist::clear() {
    root_node.reset();
}

bool sqc_plist::parse( sqc_string const &data ) {
    root_node.reset();
    using namespace xml;
    
    xml_doc xml( data );
    if( !xml.is_valid() ) {
        return false;
    }
    
    xml_node_ptr    node( xml.get_root() );
    
    sqc_string  name( node->get_name() );
    
    if( name != "plist" ) {
        return false;
    }
    
    xml_node_ptr    node_root_dict = node->find( "dict" );
    if( !node_root_dict ) {
        return false;
    }
    
    sqc_plist_entry_ptr result( new sqc_plist_entry_dict() );
    if( !result->parse_xml( node_root_dict ) ) {
        return false;
    }
    
    root_node = result;
    
    return true;
}

bool sqc_plist::write( sqc_string &data ) {
    if( !root_node ) {
        return false;
    }
    xml::xml_doc    new_doc;
    xml::xml_node_ptr   node = new_doc.create_node( "plist", xml::xml_node_ptr() );
    node->set_attribute( "version", "1.0" );
    
    root_node->format_xml( node, new_doc );
    
    new_doc.write_xml( data );
    
    return true;
}

sqc_plist_entry_ptr sqc_plist::get_or_create_root() {
    if( !root_node ) {
        root_node.reset( new sqc_plist_entry_dict() );
    }
    
    return root_node;
}

sqc_plist_entry_ptr sqc_plist::get_root() const {
    return root_node;
}


END_NAMESPACE_SQC_PLIST

