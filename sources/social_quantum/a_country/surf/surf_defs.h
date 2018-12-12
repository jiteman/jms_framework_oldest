#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <functional>
#include <list>
//
//
//
#define NAMESPACE_SURF  namespace surf {
#define END_NAMESPACE_SURF }



NAMESPACE_SURF

typedef unsigned char  surf_byte;
typedef unsigned short surf_word;
typedef unsigned long  surf_dword;
typedef unsigned long long surf_ddword;

//typedef std::basic_string<surf_byte, std::char_traits<surf_byte>, std::allocator<surf_byte> > surf_raw_data;
typedef std::vector<surf_byte> surf_raw_data;

typedef float surf_val;
typedef std::string surf_string;

typedef std::tr1::function<void()> surf_callback;

enum surf_orientation {
    orientation_portrait,
    orientation_landscape,
    orientation_portrait_inv,
    orientation_landscape_inv,
};


//#pragma pack(push,1)

template< class > struct surf_size_t;

template <class T>
struct surf_point_t {
    T    x, y;
    
    surf_point_t() : x( 0 ), y ( 0 ) 
    {}
    
    surf_point_t( T xx, T yy ) : x (xx), y ( yy )
    {}
    
    surf_point_t operator +( const surf_point_t &o ) const {
        return surf_point_t( x + o.x, y + o.y );
    }
    
    const surf_point_t &operator +=( const surf_point_t &o ) {
        x += o.x;
        y += o.y;
        return *this;
    }
    
    surf_point_t operator +( const surf_size_t< T > &other_size ) const {
        surf_point_t result = *this;
        return result += other_size;
    }
    
    surf_point_t &operator +=( const surf_size_t< T > &other_size ) {
        x += other_size.cx;
        y += other_size.cy;
        return *this;
    }
    
    surf_point_t operator -( const surf_point_t &o ) const {
        return surf_point_t( x - o.x, y - o.y );
    }

    const surf_point_t &operator -=( const surf_point_t &o ) {
        x -= o.x;
        y -= o.y;
        return *this;
    }
    
    surf_point_t const &operator /= ( T val ) {
        x/=val;
        y/=val;
        return *this;
    }
    
    surf_point_t const &operator *= ( T val ) {
        x*=val;
        y*=val;
        return *this;
    }
    surf_point_t operator / ( T val ) const {
        surf_point_t    result( *this );
        result /= val;
        return result;
    }
    
    surf_point_t operator * ( T val ) const {
        surf_point_t    result( *this );
        result *= val;
        return result;
    }
    
	surf_val length() const {
		return sqrt(x*x+y*y);
	}
	
	surf_point_t& normalize() {
		surf_val iLen = 1.0/length();
		x*=iLen;
		y*=iLen;
		return *this;
	}
};

template <class T>
struct surf_size_t {
    surf_size_t() : cx( 0 ), cy( 0 ) {
    }
    surf_size_t( const surf_size_t &o ) : cx( o.cx ), cy( o.cy ) {
    }
    surf_size_t( T cxx, T cyy ) : cx( cxx ), cy( cyy ) {
    }
    
    surf_size_t operator +( const surf_size_t &other ) const {
        return surf_size_t( cx + other.cx, cy + other.cy );
    }
    
    surf_size_t &operator +=( const surf_size_t &other ) {
        cx += other.cx;
        cy += other.cy;
        return *this;
    }
    
    surf_size_t operator *( const surf_size_t &scale ) const {
        return surf_size_t( cx * scale.cx, cy *scale.cy );
    }
    
    surf_size_t &operator *=( const surf_size_t &scale ) {
        cx *= scale.cx;
        cy *= scale.cy;
        return *this;
    }
    
    T    cx, cy;
};

template <class T>
struct surf_rect_t {
    surf_rect_t() : x( 0 ), y( 0 ), cx( 0 ), cy( 0 ) 
    {
    }
    template <class Y>
    surf_rect_t( surf_rect_t<Y> const &o ) : x( o.x ), y( o.y ), cx( o.cx ), cy( o.cy ) 
    {
    }
    template <class Y>
    explicit surf_rect_t( surf_size_t<Y> const &s ) : x( 0 ), y( 0 ), cx( s.cx ), cy( s.cy ) 
    {
    }
    template <class Y>
    explicit surf_rect_t( surf_point_t<Y> const &p ) : x( p.x ), y( p.y ), cx( 0 ), cy( 0 ) 
    {
    }
    template <class Y>
    surf_rect_t( surf_point_t<Y> const &p1, surf_point_t<Y> const &p2 ) : x( p1.x ), y( p1.y ), cx( p2.x-p1.x ), cy( p2.y-p1.y ) 
    {
    }
    template <class Y>
    surf_rect_t( surf_point_t<Y> const &p, surf_size_t<Y> const &s ) : x( p.x ), y( p.y ), cx( s.cx ), cy( s.cy ) 
    {
    }

    surf_rect_t( T xx, T yy, T cxx, T cyy )
        : x( xx ), y( yy ), cx( cxx ), cy( cyy )
    {
    }
    
    bool    point_in_rect( const surf_point_t<T> &point ) const {
        return x <= point.x && y <= point.y && x+cx > point.x && y + cy > point.y;
    }
    
    template <class Y>
    bool is_intercepted( const surf_rect_t<Y> &rect ) const {
        if( left() > rect.right() ) return false;
        if( bottom() > rect.top() ) return false;
        if( right() < rect.left() ) return false;
        if( top() < rect.bottom() ) return false;
        return true;
    }
    
    T left() const {
        return x;
    }
    T bottom() const {
        return y;
    }
    T right() const {
        return x+cx;
    }
    T top() const {
        return y+cy;
    }
    
    surf_size_t<T> size() const {
        return surf_size_t<T>( cx, cy );
    }
    
    surf_point_t<T> bottom_left() const {
        return surf_point_t<T>( x, y );
    }
	surf_point_t<T> bottom_right() const {
        return surf_point_t<T>( x+cx, y );
    }
    surf_point_t<T> top_left() const {
        return surf_point_t<T>( x, y+cy );
    }
	surf_point_t<T> top_right() const {
        return surf_point_t<T>( x+cx, y+cy );
    }
    surf_point_t<T> center() const {
        return surf_point_t<T>( x+cx/2, y+cy/2 );
    }
	    
    surf_rect_t operator + (surf_point_t<T> const &point ) const {
        surf_rect_t   result( *this );
        result+=point;
        return result;
    }

    surf_rect_t operator +( const surf_rect_t &delta_rect ) const {
        surf_rect_t result = *this;        
        return result += delta_rect;
    }
    
    surf_rect_t operator +( const surf_size_t< T > &delta_size ) const {
        surf_rect_t result = *this;        
        return result += delta_size;
    }
    
    surf_rect_t operator - (surf_point_t<T> const &point ) const {
        surf_rect_t   result( *this );
        result-=point;
        return result;
    }
    
    surf_rect_t &operator += (surf_point_t<T> const &point ) {
        x += point.x;
        y += point.y;
        return *this;
    }
    
    surf_rect_t &operator +=( const surf_rect_t &delta_rect ) {
        x += delta_rect.x;
        y += delta_rect.y;
        cx += delta_rect.cx;
        cy += delta_rect.cy;
        return *this;
    }
    
    surf_rect_t &operator +=( const surf_size_t< T > &delta_size ) {
        cx += delta_size.cx;
        cy += delta_size.cy;
        return *this;
    }
    
    surf_rect_t &operator -= (surf_point_t<T> const &point ) {
        x -= point.x;
        y -= point.y;
        return *this;
    }
	
	/// scale rect
	surf_rect_t &operator *= ( T val ) {
		x*=val;
		y*=val;
		cx*=val;
		cy*=val;
		return *this;
	}
	surf_rect_t operator * ( T val ) {
		surf_rect_t res(*this);
		res*=val;
		return res;
	}

    void union_rect( surf_rect_t const &o ) {
        T l = ( o.x < x ) ? o.x : x;
        T b = ( o.y < y ) ? o.y : y;
        T r = ( (o.x+o.cx) > (x+cx) ) ? (o.x+o.cx) : (x+cx);
        T t = ( (o.y+o.cy) > (y+cy) ) ? (o.y+o.cy) : (y+cy);
        
        x = l;
        y = b;
        cx = r - l;
        cy = t - b;
    }
	
    
    T    x, y, cx, cy;
};

typedef surf_point_t<surf_val> surf_point;
typedef surf_size_t<surf_val> surf_size;
typedef surf_rect_t<surf_val> surf_rect;

typedef surf_point_t<int> surf_npoint;
typedef surf_size_t<int> surf_nsize;
typedef surf_rect_t<int> surf_nrect;


struct surf_color {
	explicit surf_color(surf_dword v, surf_val a = 1)
	: r( hc(v,16) ), g( hc(v, 8) ), b( hc(v, 0) ), a( a )
    {
    	
    }
    surf_color() : r( 0 ), g( 0 ), b( 0 ), a( 1 ) {
    }
    surf_color( surf_color const &o ) : r( o.r ), g( o.g ), b( o.b ), a( o.a ) {
    }
    surf_color( surf_val rr, surf_val gg, surf_val bb, surf_val aa ) : r( rr ), g( gg ), b( bb ), a( aa ) {
    }

    surf_val    r, g, b, a;
	
	/// operators
	surf_color operator * ( surf_val k ) const {
		return surf_color( r*k, g*k, b*k, a*k );
	}
	surf_color operator * ( const surf_color& clr ) const {
		return surf_color( r*clr.r, g*clr.g, b*clr.b, a*clr.a );
	}
	surf_color operator + ( const surf_color& clr ) const {
		return surf_color( r+clr.r, g+clr.g, b+clr.b, a+clr.a );
	}
	static surf_val hc(surf_dword v, surf_dword shift ) 
	{
        surf_dword p = v;
        p = (v >> shift) & 0x0000FF;
        return p / 255.0;
    }
};

class surf_byte_color : public surf_color {
public:
    surf_byte_color( surf_byte rr, surf_byte gg, surf_byte bb, surf_byte aa ) : surf_color( rr/255., gg/255., bb/255., aa/255. ) {
    }
};


//
class surf_object {
public:
    surf_object() {
    }
    virtual ~surf_object() {
    }
private:
    // non-copyable
    surf_object( const surf_object & );
    surf_object const &operator=( surf_object const & );
};

//#pragma pack(pop)

//
// log
//
#if defined(__ANDROID__) && defined(SURF_USE_DEVICE_LOGS)
END_NAMESPACE_SURF

#include <android/log.h>
#include <sstream>

NAMESPACE_SURF

static const char SQC_LOG_TAG[] = "SQC";

class surf_log_entry {
public:
    explicit surf_log_entry( android_LogPriority proirity )
    : m_proirity( proirity ) {
		m_stream << "  SURF | ";
    }
    
    ~surf_log_entry() {
        m_stream << std::endl;
        __android_log_print( m_proirity, SQC_LOG_TAG, m_stream.str().c_str() );
        
    }
    
    std::ostream &get_stream() {
        return m_stream;
    }
    
private:
    android_LogPriority  m_proirity;
    std::stringstream    m_stream;
};

enum surf_log_level {
    log_level_fatal = ANDROID_LOG_FATAL,
    log_level_error = ANDROID_LOG_ERROR,
    log_level_warning = ANDROID_LOG_WARN,
    log_level_info = ANDROID_LOG_INFO,
    log_level_verbose = ANDROID_LOG_VERBOSE,
};

#define surf_log( level )   if( int(level) >= int(log_level_verbose) ) surf_log_entry(android_LogPriority(level)).get_stream()

#else

enum surf_log_level {
    log_level_fatal = 0,
    log_level_error,
    log_level_warning,
    log_level_info,
    log_level_verbose,
};

class surf_log_entry {
public:
    surf_log_entry() {
        std::cout << "SURF    |";
    }
    
    ~surf_log_entry() {
        std::cout << std::endl;
    }
    
    std::ostream &get_stream() {
        return std::cout;
    }
};
#define surf_log( level )   if( level < ::surf::log_level_verbose ) surf_log_entry().get_stream()

#endif

#define surf_endl()         ""
#define surf_verbose()      surf_log( log_level_verbose ) << "VERBOSE |"
#define surf_info()         surf_log( log_level_info )    << "INFO    |"
#define surf_warning()      surf_log( log_level_warning ) << "WARNING |"
#define surf_error()        surf_log( log_level_error )   << "ERROR   |"
#define surf_fatal()        surf_log( log_level_fatal )   << "FATAL   |"


template <class T> inline
std::ostream &operator << ( std::ostream &o, surf_point_t<T> const &p ) {
    return o << "{" << p.x << ", " << p.y << "}";
}

template <class T> inline
std::ostream &operator << ( std::ostream &o, surf_size_t<T> const &s ) {
    return o << "{" << s.cx << ", " << s.cy << "}";
}

template <class T> inline
std::ostream &operator << ( std::ostream &o, surf_rect_t<T> const &r ) {
    return o << "{" << r.bottom_left() << ", " << r.size() << "}";
}


enum surf_draw_string_flag {
    draw_string_alignment_left            = (0 << 0),
    draw_string_alignment_center          = (1 << 0),
    draw_string_alignment_right           = (2 << 0),
    draw_string_alignment_justify         = (3 << 0),
    draw_string_alignment_mask            = (3 << 0),

    draw_string_valignment_top            = (0 << 2),
    draw_string_valignment_bottom         = (1 << 2),
    draw_string_valignment_center         = (2 << 2),
    draw_string_valignment_mask           = (3 << 2),

    draw_string_single_line               = (0 << 4),
    draw_string_multi_line                = (1 << 4),
    draw_string_lines_mask                = (3 << 4),

    draw_string_draw_shadow_disabled      = (0 << 6),
    draw_string_draw_shadow_enabled       = (1 << 6),
    draw_string_draw_shadow_mask          = (1 << 6),

    draw_string_adjust_font_size_disabled = (0 << 7),
    draw_string_adjust_font_size_enabled  = (1 << 7),
    draw_string_adjust_font_size_mask     = (1 << 7),

    draw_string_truncation_tail           = (0 << 8),
    draw_string_truncation_head           = (1 << 8),
    draw_string_truncation_middle         = (2 << 8),
	draw_string_truncation_disabled       = (3 << 8),
    draw_string_truncation_mask           = (3 << 8)
};

typedef surf_dword surf_draw_string_flags;


enum surf_draw_image_flag {
    tile_flag_none = 0,
    tile_flag_horz = 1,
    tile_flag_vert = 2,
    tile_flag_both = 3,
    
    draw_image_rotated = 4,
    draw_image_mirrored = 8,
    draw_image_v_mirrored = 16,
};

typedef unsigned surf_draw_image_flags;

inline
surf_draw_image_flags make_tile_flag( bool h, bool v ) {
    surf_draw_image_flags r = tile_flag_none;
    if( h ) r |= tile_flag_horz;
    if( v ) r |= tile_flag_vert;
    
    return ( r );
}


END_NAMESPACE_SURF

#ifdef __GNUC__
#define SURF_DEPRECATED( description ) __attribute__((deprecated))
#else
#define SURF_DEPRECATED( description )
#endif


#include "surf_gl.h"
