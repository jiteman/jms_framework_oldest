#ifndef __SQC_XML_INCLUDED
#define __SQC_XML_INCLUDED

#include <libxml/parser.h>
#include <list>
#include <map>
#include "sqc_defs.h"


#define NAMESPACE_SQC_XML  namespace sqc { namespace xml {
#define END_NAMESPACE_SQC_XML }}


NAMESPACE_SQC_XML

class xml_node;
class xml_doc;

typedef std::string xml_string;
typedef shared_ptr2<xml_node>  xml_node_ptr;
typedef std::list<xml_node_ptr> xml_node_list;
typedef std::map<xml_string, xml_string>    xml_strings;

class xml_node : public sqc_noncopyable {
public:
    xml_node( xmlNode *n );
    virtual ~xml_node();
    
    xml_string  get_name() const;
    void        set_name( const char *name );
    
    xml_string  get_value() const;
    void        set_value( const char *val );
    
    xml_string  get_attribute( const char *name ) const;
    int         get_attribute_int( const char *name, int def = 0 ) const;
    bool        get_attribute_bool( const char *name ) const;
    void        set_attribute( const char *name, xml_string const &val );
    void        set_attribute( const char *name, const char *val );
    void        set_attribute_int( const char *name, int val );
    void        set_attribute_bool( const char *name, bool val );
    
    void        remove_attribute( const char *name );
    void        remove();
    
    void        get_childs( xml_node_list &result ) const;
    void        get_attributes( xml_strings &result ) const;
    
    xml_node_ptr    find( const char *name ) const;
protected:
    friend class xml_doc;
    mutable xmlNode *node;
};

class xml_doc: public sqc_noncopyable {
public:
    xml_doc();
    xml_doc( xml_string const &data );
    xml_doc( xmlDoc* d );
    
    virtual ~xml_doc();
    
    void    write_xml( xml_string &data );
    bool    is_valid() const;
    
    xml_node_ptr    get_root() const;
    xml_node_ptr    create_node( const char *name, xml_node_ptr parent );
    xml_node_ptr    create_node( const char *name, const char *val, xml_node_ptr parent );

    xml_node_ptr    query_xpath_node( const char *path ) const;
    void            query_xpath( const char *path, xml_node_list &result ) const;

protected:
    bool free_when_done;
    mutable xmlDoc  *doc;
};


END_NAMESPACE_SQC_XML

#endif //__SQC_XML_INCLUDED
