#ifndef __SQC_PLIST_INCLUDED
#define __SQC_PLIST_INCLUDED

#include <sstream>
#include "sqc_xml.h"

#define NAMESPACE_SQC_PLIST namespace sqc { namespace plist {
#define END_NAMESPACE_SQC_PLIST }}


NAMESPACE_SQC_PLIST

class sqc_plist_entry;

typedef std::tr1::shared_ptr<sqc_plist_entry>   sqc_plist_entry_ptr;
typedef std::map<sqc_string, sqc_plist_entry_ptr>     sqc_plist_dict;
typedef sqc_plist_dict::const_iterator          sqc_plist_iterator;

class sqc_plist_entry {
public:
    virtual ~sqc_plist_entry()                                                  {}
    
    virtual bool parse_xml( xml::xml_node_ptr node )                            = 0;
    virtual bool format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml )      = 0;
    
    virtual bool get_value_bool( sqc_string const &entry ) const                {return false;}
    virtual int get_value_int( sqc_string const &entry ) const                  {return 0;}
    virtual sqc_string get_value_string( sqc_string const &entry ) const        {return sqc_string();}
    virtual sqc_plist_entry_ptr get_value( sqc_string const &entry ) const      {return sqc_plist_entry_ptr();}
    
    virtual void set_value_bool( sqc_string const &entry, bool val )            {}
    virtual void set_value_int( sqc_string const &entry, int val )              {}
    virtual void set_value_string( sqc_string const &entry, sqc_string const &val )    {}
    virtual void set_value( sqc_string const &entry, sqc_plist_entry_ptr )      {}
    
    virtual sqc_plist_iterator begin() const                                    {return get_static().begin();}
    virtual sqc_plist_iterator end() const                                      {return get_static().end();}
public:
    virtual bool get_value_bool() const                                         {return bool();}
    virtual int get_value_int() const                                           {return int();}
    virtual sqc_string get_value_string() const                           {return sqc_string();}
private:
    static sqc_plist_dict  &get_static() {
        static sqc_plist_dict d;
        return d;
    }
};

class sqc_plist_entry_bool : public sqc_plist_entry {
public:
    sqc_plist_entry_bool( bool v = bool() ) : val( v ) {
    }

    virtual bool get_value_bool() const {
        return val;
    }
    
    virtual bool parse_xml( xml::xml_node_ptr node ) {
        val = node->get_name() == "true";
        return true;
    }
    virtual bool format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml ) {
        xml::xml_node_ptr   node = xml.create_node( val ? "true" : "false", parent );
        return true;
    }
private:
    bool    val;
};

class sqc_plist_entry_int : public sqc_plist_entry {
public:
    sqc_plist_entry_int( int v = int() ) : val( v ) {
    }
    virtual int get_value_int() const {
        return val;
    }
    virtual bool parse_xml( xml::xml_node_ptr node ) {
        std::stringstream   s( node->get_value() );
        s >> val;
        return true;
    }
    virtual bool format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml ) {
        std::stringstream s;
        s << val;
        
        xml::xml_node_ptr   node = xml.create_node( "integer", parent );
        node->set_value( s.str().c_str() );
        
        return true;
    }
private:
    int    val;
};

class sqc_plist_entry_string : public sqc_plist_entry {
public:
    sqc_plist_entry_string() {
    }
    sqc_plist_entry_string( sqc_string const &s ) : val( s ) {
    }
    virtual sqc_string get_value_string() const {
        return val;
    }
    virtual bool parse_xml( xml::xml_node_ptr node ) {
        val = node->get_value();
        return true;
    }
    virtual bool format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml ) {
        xml::xml_node_ptr   node = xml.create_node( "string", parent );
        node->set_value( val.c_str() );
        
        return true;
    }
private:
    sqc_string val;
};


class sqc_plist_entry_dict : public sqc_plist_entry {
public:
    virtual bool parse_xml( xml::xml_node_ptr node );
    virtual bool format_xml( xml::xml_node_ptr parent, xml::xml_doc &xml );

    virtual bool get_value_bool( sqc_string const &entry ) const;
    virtual int get_value_int( sqc_string const &entry ) const;
    virtual sqc_string get_value_string( sqc_string const &entry ) const;
    virtual sqc_plist_entry_ptr get_value( sqc_string const &entry ) const;
    
    virtual void set_value_bool( sqc_string const &entry, bool val );
    virtual void set_value_int( sqc_string const &entry, int val );
    virtual void set_value_string( sqc_string const &entry, sqc_string const &val );
    virtual void set_value( sqc_string const &entry, sqc_plist_entry_ptr val );
    
    virtual sqc_plist_iterator begin() const    {return vals.begin();}
    virtual sqc_plist_iterator end() const      {return vals.end();}
private:
    sqc_plist_dict  vals;
};


//
// plist class
//
class sqc_plist {
public:
    sqc_plist() {}
    virtual ~sqc_plist() {}
    
    void clear();
    bool parse( sqc_string const &data );
    bool write( sqc_string &data );
    
    sqc_plist_entry_ptr get_root() const;
    sqc_plist_entry_ptr get_or_create_root();
private:
    sqc_plist_entry_ptr     root_node;
};


END_NAMESPACE_SQC_PLIST


#endif //__SQC_PLIST_INCLUDED