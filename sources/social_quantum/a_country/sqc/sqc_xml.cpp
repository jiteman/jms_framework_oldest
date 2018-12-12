#include "sqc_xml.h"
#include <libxml/xpath.h>

NAMESPACE_SQC_XML

#define XML_CHECK_ASSERT_NODE( xx ) assert( node ); if( !node ) return (xx)
#define XML_CHECK_ASSERT_NODE_VOID assert( node ); if( !node ) return;
#define XML_CHECK_ASSERT_DOC( xx ) assert( doc ); if( !doc ) return (xx)
#define XML_CHECK_ASSERT_DOC_VOID assert( doc ); if( !doc ) return;


xml_node::xml_node( xmlNode *n ) {
    node = n;
}

xml_node::~xml_node() {
}

xml_string xml_node::get_name() const {
    xml_string  result;

    if( node && node->name ) {
        result = (const char*)node->name;
    }
    return result;
}

void xml_node::set_name( const char *name ) {
    XML_CHECK_ASSERT_NODE_VOID;
    
    xmlNodeSetName( node, (xmlChar*)name );
}

xml_string xml_node::get_value() const {
    xml_string  result;
    
    XML_CHECK_ASSERT_NODE( result );
    
    xmlChar *tempo = xmlNodeGetContent( node );
    if( tempo ) {
        result = (const char*) tempo;
    }
    xmlFree( tempo );
    
    return result;
    
}
void xml_node::set_value( const char *val ) {
    XML_CHECK_ASSERT_NODE_VOID;
    
    xmlNodeSetContent( node, (xmlChar*)val );
    
}


xml_string xml_node::get_attribute( const char *name ) const {
    xml_string  result;
    
    XML_CHECK_ASSERT_NODE( result );
    
    xmlAttr *attr = xmlHasProp( node, (const xmlChar *)name );
    if( !attr || !attr->children ) {
        return result;
    }
    
    char    *val = (char*)attr->children->content;
    
    if( !val ) {
        return result;
    }
    
    result = val;
    
    return result;
}

int xml_node::get_attribute_int( const char *name, int def ) const {
    XML_CHECK_ASSERT_NODE( 0 );
    
    xmlAttr *attr = xmlHasProp( node, (const xmlChar *)name );
    if( !attr || !attr->children ) {
        return def;
    }
    
    const char    *val = (const char*)attr->children->content;
    if( !val ) {
        return def;
    }
    return atoi( val );
}

bool xml_node::get_attribute_bool( const char *name ) const {
    XML_CHECK_ASSERT_NODE( false );
    
    xmlAttr *attr = xmlHasProp( node, (const xmlChar *)name );
    if( !attr || !attr->children ) {
        return 0;
    }
    
    const char    *val = (const char*)attr->children->content;
    if( !val ) {
        return 0;
    }
    return *val == 't';
}

void xml_node::set_attribute( const char *name, const char *val ) {
    XML_CHECK_ASSERT_NODE_VOID;
    xmlSetProp( node, (xmlChar const *)name, (xmlChar const *)val );
}


void xml_node::set_attribute( const char *name, xml_string const &val ) {
    set_attribute( name, val.c_str() );
}

void xml_node::set_attribute_int( const char *name, int val ) {
    char    sz[20] = "";
    sprintf( sz, "%d", val );
    set_attribute( name, sz );
}

void xml_node::set_attribute_bool( const char *name, bool val ) {
    set_attribute( name, val ? "true":"false" );
}


void xml_node::remove_attribute( const char *name ) {
    XML_CHECK_ASSERT_NODE_VOID;
    
    xmlUnsetProp( node, (xmlChar const *)name );
}

void xml_node::remove() {
    XML_CHECK_ASSERT_NODE_VOID;
    
    xmlUnlinkNode( node );
    xmlFreeNode( node );
    node = 0;
}

void xml_node::get_childs( xml_node_list &result ) const {
    XML_CHECK_ASSERT_NODE_VOID;
    
    for( xmlNode *child = node->children; child; child = child->next ) {
        if( child->type != XML_ELEMENT_NODE ) {
            continue;
        }
        result.push_back( xml_node_ptr( new xml_node( child ) ) );
    }
}

void xml_node::get_attributes( xml_strings &result ) const {
    XML_CHECK_ASSERT_NODE_VOID;
    
    for( xmlAttr* attribute = node->properties; attribute; attribute = attribute->next ) {
        char* value = (char*)xmlNodeListGetString( node->doc, attribute->children, 1 );
        const char* key = (const char*)attribute->name;
        result[key] = value;
        xmlFree(value); 
    }
}

xml_node_ptr xml_node::find( const char *name ) const {
    xml_node_ptr    result;
    
    XML_CHECK_ASSERT_NODE( result );
    
    for( xmlNode *child = node->children; child; child = child->next ) {
        if( child->type != XML_ELEMENT_NODE ) {
            continue;
        }
        if( !child->name ) {
            continue;
        }
        if( strcmp( (const char*)child->name, name ) ) {
            continue;
        }
        return xml_node_ptr( new xml_node( child ) );
    }
    
    return result;
}


xml_doc::xml_doc() {
    doc = xmlNewDoc(BAD_CAST "1.0");
    free_when_done = true;
}

xml_doc::xml_doc( xml_string const &data ) {
    doc = xmlParseMemory( &data[0], data.size() );
    free_when_done = true;
}

xml_doc::xml_doc( xmlDoc* d ) {
    doc = d;
    free_when_done = false;
}

xml_doc::~xml_doc() {
    if( free_when_done ) {
        if( doc ) {
            xmlFreeDoc( doc );
        }
    }
}

bool xml_doc::is_valid() const {
    return doc != 0;
}

void xml_doc::write_xml( xml_string &data ) {
    XML_CHECK_ASSERT_DOC_VOID;
    
    xmlChar *tempo = 0;
    int     size = 0;
    int format = 1;
    
    xmlIndentTreeOutput = 2;
    xmlDocDumpFormatMemory( doc, &tempo, &size, format );

    data.assign( (const char*)tempo, size );
    xmlFree( tempo );
}

xml_node_ptr xml_doc::get_root() const {
    xml_node_ptr    node;
    
    XML_CHECK_ASSERT_DOC( node );
    
    node.reset( new xml_node( xmlDocGetRootElement( doc ) ) );
    return node;
}

xml_node_ptr xml_doc::create_node( const char *name, xml_node_ptr parent ) {
    xml_node_ptr    node;
    XML_CHECK_ASSERT_DOC( node );
    
    xmlNode *child = 0;
    if( parent ) {
        child = xmlNewChild( parent->node, 0, BAD_CAST name, 0 );
    }
    else {
        child = xmlNewNode( 0, BAD_CAST name );
        xmlDocSetRootElement( doc, child );
    }
    
    node.reset( new xml_node( child ) );
    return node;
}

xml_node_ptr xml_doc::create_node( const char *name, const char *val, xml_node_ptr parent ) {
    xml_node_ptr    node;
    XML_CHECK_ASSERT_DOC( node );
    
    xmlNode *child = 0;
    if( parent ) {
        child = xmlNewTextChild( parent->node, 0, BAD_CAST name, BAD_CAST val );
    }
    else {
        child = xmlNewNode( 0, BAD_CAST name );
        xmlDocSetRootElement( doc, child );
    }
    
    node.reset( new xml_node( child ) );
    return node;
}

xml_node_ptr xml_doc::query_xpath_node( const char *path ) const {
    xml_node_ptr    node;
    XML_CHECK_ASSERT_DOC( node );

    xmlXPathContext *xctx = xmlXPathNewContext( doc );
    if( xctx ) {
        xmlXPathObject *xpath = xmlXPathEvalExpression( (xmlChar*)path, xctx );
        if( xpath ) {
            if( xpath->nodesetval && xpath->nodesetval->nodeTab ) {
                if( xpath->nodesetval->nodeNr ) {
                    node.reset( new xml_node( xpath->nodesetval->nodeTab[0] ) );
                }
            }
            xmlXPathFreeObject( xpath );
        }
        xmlXPathFreeContext( xctx );
    }
    return node;
}

void xml_doc::query_xpath( const char *path, xml_node_list &result ) const {
    XML_CHECK_ASSERT_DOC_VOID

    xmlXPathContext *xctx = xmlXPathNewContext( doc );
    if( xctx ) {
        xmlXPathObject *xpath = xmlXPathEvalExpression( (xmlChar*)path, xctx );
        if( xpath ) {
            if( xpath->nodesetval && xpath->nodesetval->nodeTab ) {
                for( int n = 0; n != xpath->nodesetval->nodeNr; ++n ) {
                    result.push_back( xml_node_ptr( new xml_node( xpath->nodesetval->nodeTab[n] ) ) );
                }
            }
            xmlXPathFreeObject( xpath );
        }
        xmlXPathFreeContext( xctx );
    }
}


END_NAMESPACE_SQC_XML
