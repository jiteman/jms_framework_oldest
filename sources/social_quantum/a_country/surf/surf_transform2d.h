#pragma once

#include "surf_matrix2.h"

#if !defined _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif

#include <math.h>

NAMESPACE_SURF
	
struct surf_transform {
    surf_matrix2x2 m;
    surf_point v;

    surf_transform()
		:
			m( surf_matrix2x2::identity() ),
			v( 0.0f, 0.0f )
	{}

    surf_transform( const surf_transform &other )
		:
			m( other.m ),
			v( other.v )
	{}

    surf_transform &operator =( const surf_transform &other ) {
        m = other.m;
        v = other.v;
        return *this;
    }

    void reset() {
        m = surf_matrix2x2::identity();
        v = surf_point( 0.0, 0.0 );
    }
		
    surf_transform& translate(const surf_point& pos) {
        v+=m*pos;
        return *this;
    }
    surf_transform& translate(surf_val x,surf_val y) {
        return translate(surf_point(x,y));
    }
	surf_transform translated(surf_val x,surf_val y) const {
		surf_transform res(*this);
		res.translate(x,y);
		return res;
	}
	surf_transform translated(const surf_point& pos) const {
		return surf_transform(*this).translate(pos);
	}
    surf_transform& rotate(surf_val _a) {
        surf_val a = surf_val(M_PI) * _a / 180.0f;
        surf_val c = ::cosf(a);
        surf_val s = ::sinf(a);
        m*=surf_matrix2x2(c,s,-s,c);
        return *this;
    }
	surf_transform rotated(surf_val a) const {
		surf_transform res(*this);
		return surf_transform(*this).rotate(a);
	}
    surf_transform& scale(surf_val s) {
        m*=surf_matrix2x2(s,0,0,s);
        return *this;
    }
	surf_transform scaled(surf_val s) const {
        return surf_transform(*this).scale(s);
    }
    surf_transform& scale(surf_val sx,surf_val sy) {
        m*=surf_matrix2x2(sx,0,0,sy);
        return *this;
    }
    surf_transform& scale(const surf_point& s) {
        m*=surf_matrix2x2(s.x,0,0,s.y);
        return *this;
    }
		
    surf_point transform(const surf_point& vert) const {
        return v + (m * vert);
    }
	inline void transform(surf_val x,surf_val y,surf_val& ox,surf_val& oy) const {
		ox = v.x+m.matrix[0*2+0]*x + m.matrix[1*2+0]*y;
		oy = v.y+m.matrix[0*2+1]*x + m.matrix[1*2+1]*y;
	}
};
	
END_NAMESPACE_SURF
