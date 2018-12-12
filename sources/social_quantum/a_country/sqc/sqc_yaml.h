#ifndef SQC_YAML_INCLUDED
#define SQC_YAML_INCLUDED

#include "sqc_defs.h"
#include "yaml.h"

#define NAMESPACE_SQC_YAML  namespace sqc { namespace yaml {
#define END_NAMESPACE_SQC_YAML }}

NAMESPACE_SQC_YAML


/////////////////// NEW!
class sqc_yaml_node;

struct cmp_sz {
    template <class T>
    bool operator () ( T psz1, T psz2 ) {
        return strcmp( psz1, psz2 ) > 0;
    }
};

//typedef shared_ptr2<sqc_yaml_node>     sqc_yaml_node_ptr;
typedef sqc_yaml_node *sqc_yaml_node_ptr;
typedef std::map<const char *, sqc_yaml_node_ptr, cmp_sz> sqc_yaml_node_map;
typedef sqc_yaml_node_map::const_iterator       sqc_yaml_node_iterator;

typedef std::list<sqc_yaml_node_ptr>            sqc_yaml_node_list;

enum sqc_yaml_node_type {
    node_type_unknown,
    node_type_scalar,
    node_type_sequence,
    node_type_mapping,
};

sqc_yaml_node_ptr sqc_create_yaml_node( yaml_node_t *node, yaml_document_t *doc, sqc_yaml_node_list &free_list );


template <class T> inline
T convert_value( const char *val ) {
    if( !val ) {
        return T();
    }
    return val;
}

template <> inline
int convert_value<int>( const char *val ) {
    if( !val ) {
        return 0;
    }
    return atoi( val );
}

template <> inline
char convert_value<char>( const char *val ) {
    if( !val ) {
        return 0;
    }
    return (char)atoi( val );
}

template <> inline
float convert_value<float>( const char *val ) {
    if( !val ) {
        return 0;
    }
    return (char)atof( val );
}

template <> inline
bool convert_value<bool>( const char *val ) {
    if( !val ) {
        return 0;
    }
    return val[0] == 't';
}

class sqc_yaml_node {
public:
    sqc_yaml_node( yaml_node_t *n, yaml_document_t *d, sqc_yaml_node_list &fl ) : node( n ), doc( d ), free_list( fl ) {
    }

	virtual ~sqc_yaml_node() {}
    
    template <class T>
    T get_value_as() {
        return convert_value<T>( get_value_raw() );
    }
    
    virtual const char *get_value_raw() {
        return 0;
    }
    
    virtual size_t  size() {
        return 0;
    }
    virtual sqc_yaml_node_ptr   get_child( int idx ) {
        return sqc_yaml_node_ptr();
    }
    
    virtual sqc_yaml_node_iterator  begin() {
        return fake_map().end();
    }
    virtual sqc_yaml_node_iterator  end() {
        return fake_map().end();
    }
    
    virtual sqc_yaml_node_ptr find( const char *entry ) {
        return sqc_yaml_node_ptr();
    }
            
    virtual sqc_yaml_node_type get_type() const = 0;
    
    static sqc_yaml_node_map &fake_map() {
        static sqc_yaml_node_map    empty;
        return empty;
    }
protected:    
    yaml_document_t *doc;
    yaml_node_t     *node;
    sqc_yaml_node_list  &free_list;
};


class sqc_yaml_node_scalar : public sqc_yaml_node {
public:
    sqc_yaml_node_scalar( yaml_node_t *n, yaml_document_t *d, sqc_yaml_node_list &fl ) : sqc_yaml_node( n, d, fl ) {
    }
    
    virtual const char *get_value_raw() {
        assert( node->type == YAML_SCALAR_NODE );
        return (const char*)node->data.scalar.value;
    }
    virtual sqc_yaml_node_type get_type() const {
        return node_type_scalar;
    }
};

class sqc_yaml_node_sequence : public sqc_yaml_node {
public:
    sqc_yaml_node_sequence( yaml_node_t *n, yaml_document_t *d, sqc_yaml_node_list &fl ) : sqc_yaml_node( n, d, fl ) {
    }
    
    virtual size_t  size() {
        assert( node->type == YAML_SEQUENCE_NODE );
        
        return (node->data.sequence.items.top - node->data.sequence.items.start);
    }
    
    virtual sqc_yaml_node_ptr   get_child( int idx ) {
        assert( node->type == YAML_SEQUENCE_NODE );
        
        yaml_node_t *child = yaml_document_get_node( doc, node->data.sequence.items.start[idx] );
        sqc_yaml_node_ptr   new_node = sqc_create_yaml_node( child, doc, free_list );
        return new_node;
    }
    
    virtual sqc_yaml_node_type get_type() const {
        return node_type_sequence;
    }
};

class sqc_yaml_node_mapping : public sqc_yaml_node {
public:
    sqc_yaml_node_mapping( yaml_node_t *n, yaml_document_t *d, sqc_yaml_node_list &fl ) 
    : sqc_yaml_node( n, d, fl ) 
    , initialized( false ) 
    {
    }
    
    void ensure_load() {
        if( initialized ) {
            return;
        }
        initialized = true;
        
        load_mapping( node, node_map );
    }
    
    void load_mapping( yaml_node_t *from, sqc_yaml_node_map &result ) {
        assert( from->type == YAML_MAPPING_NODE );
        
        //
        // load and cache the entries
        //
        for( size_t idx = 0; idx != (from->data.mapping.pairs.top - from->data.mapping.pairs.start); ++idx ) {
            
            yaml_node_t *key = yaml_document_get_node( doc, from->data.mapping.pairs.start[idx].key );
            yaml_node_t *child = yaml_document_get_node( doc, from->data.mapping.pairs.start[idx].value );
            
            assert( key );
            assert( key->type == YAML_SCALAR_NODE );
            
            const char *entry = (const char *)key->data.scalar.value;
            
            
            //if( !strcmp( entry, "<<:" ) ) {
            if( !strcmp( entry, "<<" ) ) {
                // inheritence
                if( child->type == YAML_MAPPING_NODE ) {
                    // mapping inheritence
                    load_mapping( child, result );
                }
                else if( child->type == YAML_SEQUENCE_NODE ) {
                    // array of mapping inheritence
                    for( size_t idx1 = 0; idx1 != (child->data.sequence.items.top - child->data.sequence.items.start); ++idx1 ) {
                        yaml_node_t *childchild = yaml_document_get_node( doc, child->data.sequence.items.start[idx1] );
                        
                        assert( childchild->type == YAML_MAPPING_NODE );
                        if( childchild->type == YAML_MAPPING_NODE ) {
                            sqc_yaml_node_map   tempo;
                            load_mapping( childchild, tempo );
                            
                            for( sqc_yaml_node_iterator i = tempo.begin(); i != tempo.end(); ++i ) {
                                if( result.find( i->first ) != result.end() ) {
                                    continue;
                                }
                                result[i->first] = i->second;
                            }
                        }
                    }
                }
            }
            else {
                sqc_yaml_node_ptr   new_node = sqc_create_yaml_node( child, doc, free_list );
                result[entry] = new_node;
            }
        }
    }
    
    virtual sqc_yaml_node_iterator  begin() {
        ensure_load();
        return node_map.begin();
    }
    
    virtual sqc_yaml_node_iterator  end() {
        ensure_load();
        return node_map.end();
    }
    
    virtual size_t  size() {
        ensure_load();
        return node_map.size();
    }
    
    
    virtual sqc_yaml_node_ptr find( const char *entry ) {
        ensure_load();
        sqc_yaml_node_iterator  i = node_map.find( entry );
        if( i == node_map.end() ) {
            return sqc_yaml_node_ptr();
        }
        
        return i->second;
    }
    
    virtual sqc_yaml_node_type get_type() const {
        return node_type_mapping;
    }
private:
    bool                initialized;
    sqc_yaml_node_map   node_map;
};

inline 
sqc_yaml_node_ptr sqc_create_yaml_node( yaml_node_t *node, yaml_document_t *doc, sqc_yaml_node_list &free_list ) {
    sqc_yaml_node_ptr   ptr;
    
    if( node->type == YAML_SCALAR_NODE )    ptr = new sqc_yaml_node_scalar( node, doc, free_list );
    else if( node->type == YAML_SEQUENCE_NODE )    ptr = new sqc_yaml_node_sequence( node, doc, free_list );
    else if( node->type == YAML_MAPPING_NODE )     ptr = new sqc_yaml_node_mapping( node, doc, free_list );
    else return 0;
    
    free_list.push_back( ptr );
    return ptr;
}


class sqc_yaml_doc {
public:
    sqc_yaml_doc() {
        memset( &document, 0, sizeof( document ) );
    }
    
    ~sqc_yaml_doc() {
        for( sqc_yaml_node_list::iterator i = free_list.begin(); i!=free_list.end(); ++i ) {
            delete *i;
        }
        yaml_document_delete( &document );
    }
    
    bool parse( const char *filename ) {
        FILE    *file = 0;
        yaml_parser_t parser;
        
        file = fopen( filename, "rb");
        if( !file ) {
            return false;
        }
        std::cout<<filename<<std::endl;
        yaml_parser_initialize(&parser);
        yaml_parser_set_input_file(&parser, file);
        
        bool success = yaml_parser_load( &parser, &document );
        
        yaml_parser_delete(&parser);
        fclose( file );
        
        if( !success ) {
            return false;
        }
        
        yaml_node_t *node = yaml_document_get_root_node( &document );
        if( !node ) {
            return false;
        }
        
        root_node = sqc_create_yaml_node( node, &document, free_list );
        return true;
    }
    
    bool parse( const char *ptr, size_t cb ) {
        yaml_parser_t parser;
        
        yaml_parser_initialize(&parser);
        yaml_parser_set_input_string(&parser, (const unsigned char*)ptr, cb);
        
        bool success = yaml_parser_load( &parser, &document );
        
        yaml_parser_delete(&parser);
        
        if( !success ) {
            return false;
        }
        
        yaml_node_t *node = yaml_document_get_root_node( &document );
        if( !node ) {
            return false;
        }
        
        root_node = sqc_create_yaml_node( node, &document, free_list );
        return true;
    }
    
    sqc_yaml_node_ptr   get_root() {
        return root_node;
    }
protected:
    yaml_document_t     document;
    sqc_yaml_node_ptr   root_node;
    sqc_yaml_node_list  free_list;
};


inline
void print_node( sqc_yaml_node_ptr node, std::ostream &result, int level = 0 ) {
    sqc_yaml_node_type    type = node->get_type();
    
    if( type == node_type_scalar ) {
        std::string s = convert_value<sqc_string>( node->get_value_raw() );
        result << s;
    }
    else if( type == node_type_sequence ) {
        std::string fill;
        fill.resize( level*2 );
        std::fill( fill.begin(), fill.end(), ' ' );
        
        result << std::endl;
        for( size_t idx = 0; idx != node->size(); ++idx ) {
            sqc_yaml_node_ptr   child( node->get_child( idx ) );
            
            result << fill << "- ";
            print_node( child, result, level+1 );
            result << std::endl;
        }
    }
    else if( type == node_type_mapping ) {
        std::string fill;
        fill.resize( level*2 );
        std::fill( fill.begin(), fill.end(), ' ' );
        
        result << std::endl;
        
        for( sqc_yaml_node_iterator i = node->begin(); i != node->end(); ++i ) {
            sqc_string const &key = i->first;
            sqc_yaml_node_ptr   child = i->second;
            
            result << fill << key << ": ";
            print_node( child, result, level+1 );
            result << std::endl;
        }
    }
}

//
//
// helpers
//
//
inline
sqc_string &get_language_suffix() {
    static sqc_string   suffix = "en";
    return suffix;
}


template <class T> inline
T get_yaml_val( sqc_yaml_node_ptr node, const char *entry ) {
    sqc_yaml_node_ptr   child = node->find( entry );
    if( !child ) {
        return T();
    }
    
    return convert_value<T>( child->get_value_raw() );
}


template <class T> inline
T get_yaml_val_localized( sqc_yaml_node_ptr node, const char *entry ) {
    const size_t len = strlen( entry );
    {
#if defined( JMSF_WINDOWS )
        std::vector< char > new_entry( len + 4 );
        strcpy( &new_entry[ 0 ], entry );
        strcat( &new_entry[ 0 ], ".");
        strcat( &new_entry[ 0 ], get_language_suffix().c_str() );
        return get_yaml_val<T>( node, &new_entry[ 0 ] );
#else // #ifdef _WIN32
        char    new_entry[len+4];
        strcpy( new_entry, entry );
        strcat( new_entry, ".");
        strcat( new_entry, get_language_suffix().c_str() );
        return get_yaml_val<T>( node, new_entry );
#endif // #ifdef _WIN32
    }
}

template <class T> inline
void get_yaml_vals( sqc_yaml_node_ptr node, const char *entry, T &result ) {
    typedef typename T::value_type value_type;
    
    result.clear();
    
    sqc_yaml_node_ptr   child = node->find( entry );
    if( !child ) {
        return;
    }
    
    if( child->get_type() != node_type_sequence ) {
        return;
    }
    
    for( int n = 0; n != child->size(); ++n ) {
        sqc_yaml_node_ptr   entry = child->get_child( n );
        result.push_back( convert_value<value_type>( entry->get_value_raw() ) );
    }
}

template <class T> inline
void get_yaml_vals( sqc_yaml_node_ptr node, const char *entry, std::map<sqc_string, T> &result ) {
    result.clear();
    
    sqc_yaml_node_ptr   child = node->find( entry );
    if( !child ) {
        return;
    }
    
    if( child->get_type() != node_type_mapping ) {
        return;
    }
    
    for( sqc_yaml_node_iterator i = child->begin(); i != child->end(); ++i ) {
        result[i->first] = convert_value<T>( i->second->get_value_raw() );
    }
}


inline 
int get_yaml_length( sqc_yaml_node_ptr node, const char *entry ) {
    
    const char  *val = get_yaml_val<const char*>( node, entry );
    if( !val ) {
        return 0;
    }
    
    size_t  len = strlen( val );
    if( !len ) {
        return 0;
    }
    
    int mul = 1000 * 3600;
    
    if( val[len-1] == 's' ) {
        mul = 1000;
    }
    
    float v = atof( val )*mul;
//    assert( v );
    return v;
}


END_NAMESPACE_SQC_YAML

#endif //SQC_BASE_INCLUDED