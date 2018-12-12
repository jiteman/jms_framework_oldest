#pragma once

#include <fstream>
#include <iostream>
#include <exception>
#include <sstream>

#include <iomanip>
#include <set>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <deque>

#include <fstream>

#include <utility>

#if defined( JMSF_WINDOWS )
    #include <memory>
    #include <functional>
#else // _WIN32
    #include <tr1/memory>
    #include <tr1/functional>
#endif // _WIN32


#if !defined( JMSF_WINDOWS )
#include <sstl/sstl_defs.h>
#endif

#include <assert.h>


#define NAMESPACE_SQC    namespace sqc {
#define END_NAMESPACE_SQC   }
#define NAMESPACE_SQC_OBJECT    namespace sqc { namespace object {
#define END_NAMESPACE_SQC_OBJECT }}
#define NAMESPACE_SQC_INFO namespace sqc { namespace info {
#define END_NAMESPACE_SQC_INFO }}

#ifdef SQC_CONFIGURATOR

#ifndef SQC_ENABLE_OBJECTS
#define SQC_ENABLE_OBJECTS
#endif//SQC_ENABLE_OBJECTS
#define SQC_OBJECT_DISABLE_DRAWING
#define SQC_NEW_TRACK_API

#endif // #ifdef SQC_CONFIGURATOR


#ifdef SQC_ENABLE_OBJECTS
#else
#define USE_OWN_SPTR
#endif

NAMESPACE_SQC 

typedef unsigned char		sqc_byte;
typedef unsigned char		sqc_bool;
typedef int        			sqc_int;

typedef unsigned short      sqc_word;
typedef unsigned int        sqc_dword;
typedef unsigned long long  sqc_ddword;

typedef std::string			sqc_string;

typedef std::string			sqc_raw_data;
typedef std::stringstream	sqc_stringstream;

typedef size_t              sqc_size_t;

#define sqc_text( text ) text

typedef std::map<sqc_string, sqc_string>	sqc_string_map;
typedef std::list<sqc_string>				sqc_string_list;
typedef std::vector<sqc_string>             sqc_string_vector;
typedef std::ifstream sqc_ifstream;

typedef std::map< const sqc_string, const sqc_string > sqc_const_string_map;

template< class first_type, class second_type >
std::pair< first_type, second_type > sqc_make_pair( const first_type &first_object, const second_type &second_object ) {
	return std::make_pair( first_object, second_object );
}

struct sqc_point {
public:
    int x, y;
    
    sqc_point() : x( 0 ), y( 0 ) {
        
    }
    
    sqc_point( int xx, int yy ) : x( xx ), y( yy ) {
        
    }
    
    bool    operator == ( sqc_point const &o ) const {
        return x == o.x && y == o.y;
    }
    bool    operator != ( sqc_point const &o ) const {
        return !(*this == o );
    }
    
    template <class U>
    sqc_point const &operator += ( U const &o ) {
        x += o.x;
        y += o.y;
        return *this;
    }
    template <class U>
    sqc_point const &operator -= ( U const &o ) {
        x -= o.x;
        y -= o.y;
        return *this;
    }
    
    template <class U>
    sqc_point operator + ( const U &o ) const {
        sqc_point r( x + o.x, y + o.y );
        return r;
    }
    template <class U>
    sqc_point operator - ( const U &o ) const {
        sqc_point r( x - o.x, y - o.y );
        return r;
    }
    template <class V>
    sqc_point const &operator *= ( V const &v ) {
        x *= v;
        y *= v;
        return *this;
    }
    template <class V>
    sqc_point const &operator /= ( V const &v ) {
        x /= v;
        y /= v;
        return *this;
    }
};


struct sqc_size {
public:
    int cx, cy;
    sqc_size() : cx( 0 ), cy( 0 ) {
        
    }
    
    template <class U>
    sqc_size( const U &o ) : cx( o.cx ), cy ( o.cy ) {
    }
    
    sqc_size( int xx, int yy ) : cx( xx ), cy( yy ) {
        
    }
    
    template <class U>
    sqc_size const &operator = ( const U &o ) {
        cx = o.cx;
        cy = o.cy;
        return *this;
    }
    
    template <class U>
    bool    operator == ( U const &o ) const {
        return cx == o.cx && cy == o.cy;
    }
    
    template <class U>
    bool    operator != ( U const &o ) const {
        return !(*this == o );
    }
};

struct sqc_rect {
public:
    int x, y, cx, cy;
    sqc_rect() : x( 0 ), y( 0 ), cx( 0 ), cy( 0 ) {
        
    }
    
    sqc_rect( int xx, int yy, int cxx, int cyy ) : x( xx ), y( yy ), cx( cxx ), cy( cyy ) {
        
    }
    
    sqc_rect( sqc_point const &ofs, sqc_size const &s ) : x( ofs.x ), y( ofs.y ), cx( s.cx ), cy( s.cy ) {
        
    }
    
    bool    operator == ( sqc_rect const &o ) const {
        return cx == o.cx && cy == o.cy && x == o.x && y == o.y;
    }
    bool    operator != ( sqc_rect const &o ) const {
        return !(*this == o );
    }
    
    sqc_point   top_left() const {
        return sqc_point( x, y+cy );
    }
    sqc_point   bottom_left() const {
        return sqc_point( x, y );
    }
    sqc_point   top_right() const {
        return sqc_point( x+cx, y+cy );
    }
    sqc_point   bottom_right() const {
        return sqc_point( x+cx, y );
    }
    sqc_point   center() const {
        return sqc_point( x+cx/2, y+cy/2 );
    }
    
    void union_rect( sqc_rect const &o ) {
        int l = ( o.x < x ) ? o.x : x;
        int b = ( o.y < y ) ? o.y : y;
        int r = ( (o.x+o.cx) > (x+cx) ) ? (o.x+o.cx) : (x+cx);
        int t = ( (o.y+o.cy) > (y+cy) ) ? (o.y+o.cy) : (y+cy);
        
        x = l;
        y = b;
        cx = r - l;
        cy = t - b;
    }

    bool    point_in_rect( const sqc_point &point ) const {
        return x <= point.x && y <= point.y && x+cx > point.x && y + cy > point.y;
    }
    
    bool    rect_intersect_rect( const sqc_rect &rect ) const {
        if( x >= rect.x + rect.cx ) return false;
        if( x + cx <= rect.x ) return false;
        if( y >= rect.y + rect.cy ) return false;
        if( y + cy <= rect.y ) return false;
        
        return  true;
    }
};

template <class T> inline
bool string_to_point( sqc_string const &s, T &r ) {
    int w, h;
    
    if( sscanf(s.c_str(), "{%d, %d}", &w, &h ) != 2 ) {
        return false;
    }
    r.x = w;
    r.y = h;
    
    return true;
}

template <class T> inline
sqc_string point_to_string( const T &s ) {
    std::stringstream   r;
    r << "{" << s.x << ", " << s.y << "}";
    return r.str();
}

template <class T> inline
bool string_to_size( sqc_string const &s, T &r ) {
    int w, h;
    
    if( sscanf(s.c_str(), "{%d, %d}", &w, &h ) != 2 ) {
        return false;
    }
    r.cx = w;
    r.cy = h;
    
    return true;
}

template <class T> inline
sqc_string size_to_string( const T &s ) {
    std::stringstream   r;
    r << "{" << s.cx << ", " << s.cy << "}";
    return r.str();
}

template <class T> inline
bool string_to_rect( sqc_string const &s, T &r ) {
    int x, y, cx, cy;
    
    if( sscanf(s.c_str(), "{{%d, %d}, {%d, %d}}", &x, &y, &cx, &cy ) != 4 ) {
        return false;
    }
    r.x = x;
    r.y = y;
    r.cx = cx;
    r.cy = cy;
    
    return true;
}

template <class T> inline
sqc_string rect_to_string( const T &s ) {
    std::stringstream   r;
    r << "{{" << s.x << ", " << s.y << "}, {" << s.cx << ", " << s.cy << "}}";
    return r.str();
}

template <class T>
inline T string_to_val( const sqc_string &s )
{
    T result = T();
    std::istringstream ss(s);
    ss >> result;
    return result;
}

template <>
inline bool string_to_val<bool>( const sqc_string &s )
{
    bool result = false;
    std::istringstream ss(s);
    ss >> result;
    if( ss.fail() ) {
        ss.clear();
        ss >> std::boolalpha >> result;
    }
    return result;
}

template <class T>
inline sqc_string val_to_string( const T &v )
{
    std::ostringstream ss;
    ss << v;
    return ss.str();
}

template <>
inline sqc_string val_to_string<bool>( const bool &v )
{
    std::ostringstream ss;
    ss << std::boolalpha << v;
    return ss.str();
}

class sqc_noncopyable {
protected:
    sqc_noncopyable(){
    }
private:
    sqc_noncopyable( const sqc_noncopyable & );
    const sqc_noncopyable &operator =( const sqc_noncopyable & );
};


END_NAMESPACE_SQC

#ifdef USE_OWN_SPTR

template <class T>
class shared_ptr2 {
public:
    shared_ptr2()
    : next( 0 )
    , prev( 0 )
    , obj( 0 )
	{
    }
    
    shared_ptr2( T *o ) 
    : next( 0 )
    , prev( 0 )
    , obj( o ) 
    {
    }
	
	shared_ptr2( shared_ptr2<T> const &o ) 
    : next( 0 )
    , prev( 0 )
    , obj( 0 )
	{
		assign( o );
	}
    
    template <class Y>
	shared_ptr2( shared_ptr2<Y> const &o ) 
    : next( 0 )
    , prev( 0 )
    , obj( 0 )
	{
		assign( o );
	}
    
	~shared_ptr2() {
		clear();
	}
    
    
	shared_ptr2 &operator = ( shared_ptr2<T> const &o ) {
        assign( o );
        return *this;
    }
    
	template <class Y>
	shared_ptr2 &operator = ( shared_ptr2<Y> const &o ) {
        assign( o );
        return *this;
    }
    
	template <class Y>
    void assign( shared_ptr2<Y> const &o ) {
		clear();
        obj = (T*)o.obj;
        if( obj ) {
            next = (shared_ptr2<T>  *)o.next;
            prev = (shared_ptr2<T>  *)&o;
            o.next = (shared_ptr2<Y> *)this;
            if( next ) next->prev = this;
        }
        
	}
    
    void reset( T *o = 0 ) {
        clear();
        obj = o;
    }
    
    void clear() {
        if( next ) next->prev = prev;
        if( prev ) prev->next = next;
        
        if( next || prev ) {
            next = prev = 0;
        }
        else {
            if( obj ) {
                delete obj;
            }
        }
        obj = 0;
    }
    
    
    T *get() const {
        return obj;
    }
    
    T &operator *() const {
        return *obj;
    }
    
    
    T *operator->() const {
        return obj;
    }
    
    operator bool() const {
        return obj != 0;
    }
    
    T       *obj;
    mutable shared_ptr2<T>  *next;
    mutable shared_ptr2<T>  *prev;
};

template <class T, class Y> inline
shared_ptr2<T> static_pointer2_cast( shared_ptr2<Y> &ptr ) {
    shared_ptr2<T>  result;
    result.assign( ptr );
    return result;
}

#else


#define shared_ptr2 std::tr1::shared_ptr 
#define static_pointer2_cast std::tr1::static_pointer_cast

#endif //USE_OWN_SPTR



struct  cmp_psz {
    template <class T> 
    bool operator  ()( T p1, T p2 ) const {
        return strcmp( p1, p2 ) > 0;
    }
};


//profiler
//
// profiler-related
//
class sqc_profiler_entry {
public:
    sqc_profiler_entry( const char *f ) 
        : func( f )
    {
        next = get_head();
        get_head() = this;
    }
    
    static sqc_profiler_entry *&get_head() {
        static sqc_profiler_entry *head;
        return head;
    }
    
	const char          *func;
	sqc_profiler_entry	*next;
	long long           duration;
	long                count;
};

#if defined( JMSF_WINDOWS )
    #define BEGIN_PROFILED_AREA( funcname )

#else // _WIN32
class sqc_profiler_area {
public:
    sqc_profiler_area( sqc_profiler_entry &e ) : profiler_entry( e ) {
        sstl::get_current_time_mks(profiler_start);
    }
    ~sqc_profiler_area() {
        sstl::time_mks profiler_end = 0;
        sstl::get_current_time_mks(profiler_end );
        
        ++profiler_entry.count;
        sstl::time_mks duration = (profiler_end - profiler_start);
        profiler_entry.duration += duration;
        
        if( duration > 200000 ) {
            std::cout << "PROFILER: long operation -> " << profiler_entry.func << " takes " << duration / 1000 << " ms" << std::endl;
        }
    }
private:
    sstl::time_mks profiler_start;
    sqc_profiler_entry &profiler_entry;
};

#define BEGIN_PROFILED_AREA(funcname)		\
    static sqc_profiler_entry   profiler_entry( funcname );\
    sqc_profiler_area   profiler_area( profiler_entry );

#endif // _WIN32

#define END_PROFILED_AREA
