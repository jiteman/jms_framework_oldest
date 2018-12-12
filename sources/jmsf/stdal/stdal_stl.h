#pragma once

#include "stdal_dll.h"


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4018 )  // signed/unsigned mismatch
#pragma warning( disable: 4100 )  // unreferenced formal parameter
#pragma warning( disable: 4245 )  // conversion from 'type1' to 'type2', signed/unsigned mismatch
#pragma warning( disable: 4512 )  // 'class' : assignment operator could not be generated
//#pragma warning( disable: 4663 )  // C++ language change: to explicitly specialize class template 'vector'
#pragma warning( disable: 4710 )  // 'function' : function not inlined
#pragma warning( disable: 4786 )  // identifier was truncated to 'number' characters in the debug information

// BUG: C4786 Warning Is Not Disabled with #pragma Warning
// STATUS: Microsoft has confirmed this to be a bug in the Microsoft product. This warning can be ignored.
// This occured only in the <map> container.

#include <map>

#pragma warning( pop )


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4018 )  // signed/unsigned mismatch
#pragma warning( disable: 4100 )  // unreferenced formal parameter
#pragma warning( disable: 4245 )  // conversion from 'type1' to 'type2', signed/unsigned mismatch
//#pragma warning( disable: 4663 )  // C++ language change: to explicitly specialize class template 'vector'
#pragma warning( disable: 4702 )  // unreachable code
#pragma warning( disable: 4710 )  // 'function' : function not inlined
#pragma warning( disable: 4786 )  // identifier was truncated to 'number' characters in the debug information

#include <vector>

#pragma warning( pop )


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4100 )  // unreferenced formal parameter
//#pragma warning( disable: 4284 )  // return type for 'identifier::operator ->' is not a UDT or reference to a UDT. Will produce errors if applied using infix notation
#pragma warning( disable: 4710 )  // 'function' : function not inlined
#pragma warning( disable: 4786 )  // identifier was truncated to 'number' characters in the debug information

#include <list>

#pragma warning( pop )


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4018)  // signed/unsigned mismatch
#pragma warning( disable: 4100)  // unreferenced formal parameter
#pragma warning( disable: 4146)  // unary minus operator applied to unsigned type, result still unsigned
#pragma warning( disable: 4244)  // 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning( disable: 4245)  // conversion from 'type1' to 'type2', signed/unsigned mismatch
#pragma warning( disable: 4511)  // 'class' : copy constructor could not be generated
#pragma warning( disable: 4512)  // 'class' : assignment operator could not be generated
//#pragma warning( disable: 4663)  // C++ language change: to explicitly specialize class template 'vector'
#pragma warning( disable: 4710)  // 'function' : function not inlined
#pragma warning( disable: 4786)  // identifier was truncated to 'number' characters in the debug information

#include <string>

#pragma warning( pop )

#pragma warning( disable: 4514)  // unreferenced inline/local function has been removed
#pragma warning( disable: 4710)  // 'function' : function not inlined
#pragma warning( disable: 4786)  // identifier was truncated to 'number' characters in the debug information


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4097)  // typedef-name 'identifier1' used as synonym for class-name 'identifier2'
#pragma warning( disable: 4127)  // conditional expression is constant

#include <sstream>
#include <fstream>

#pragma warning( pop )


// The STL library provides a type called auto_ptr for managing pointers.  
// This template class acts as a stack variable for dynamically allocated 
// memory.  When the variable goes out of scope, its destructor gets called.  
// In its de-structor, it calls delete on the contained pointer, making sure 
// that the memory is returned to the heap.

#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4018)  // signed/unsigned mismatch
#pragma warning( disable: 4100)  // unreferenced formal parameter
#pragma warning( disable: 4245)  // conversion from 'type1' to 'type2', signed/unsigned mismatch
#pragma warning( disable: 4710)  // 'function' : function not inlined
#pragma warning( disable: 4786)  // identifier was truncated to 'number' characters in the debug information

#include <memory>

#pragma warning( pop )


#pragma warning( push )

#include <yvals.h>              // warning numbers get enabled in yvals.h 

#pragma warning( disable: 4018)  // signed/unsigned mismatch
#pragma warning( disable: 4100)  // unreferenced formal parameter
#pragma warning( disable: 4245)  // conversion from 'type1' to 'type2', signed/unsigned mismatch
#pragma warning( disable: 4710)  // 'function' : function not inlined
#pragma warning( disable: 4786)  // identifier was truncated to 'number' characters in the debug information

#include <stack>

#pragma warning( pop )


#include <iostream>

#include <iomanip>

#include <algorithm>


namespace std {


JMSF_STDAL_DLL_INTERFACE const string toString( const string &someString ) throw();
JMSF_STDAL_DLL_INTERFACE const string toString( const wstring &someWideString ) throw();
JMSF_STDAL_DLL_INTERFACE const wstring toWideString( const string &someString ) throw();
JMSF_STDAL_DLL_INTERFACE const wstring toWideString( const wstring &someWideString ) throw();


#if defined( _UNICODE )
	typedef wstring				_tstring;
	typedef wostream			_tostream;
	typedef wistream			_tistream;
	typedef wstringstream		_tstringstream;
	typedef wistringstream		_tistringstream;
	typedef wostringstream		_tostringstream;
	typedef wfstream			_tfstream;
	typedef wofstream			_tofstream;
	typedef wifstream			_tifstream;

	template< class An_object_type >
	inline const wstring _toString( const An_object_type &someString ) {
		return toWideString( someString );
	}

	#define _tfputc( _tfputc_parameter_x, _tfputc_parameter_y )		fputwc( ( _tfputc_parameter_x ), ( _tfputc_parameter_y ) )
	#define _tfputs( _tfputs_parameter_x, _tfputs_parameter_y )		fputws( ( _tfputs_parameter_x ), ( _tfputs_parameter_y ) )

	JMSF_STDAL_DLL_INTERFACE extern wistream &_tcin;
	JMSF_STDAL_DLL_INTERFACE extern wostream &_tcout;
	JMSF_STDAL_DLL_INTERFACE extern wostream &_tcerr;
	JMSF_STDAL_DLL_INTERFACE extern wostream &_tclog;
	
#else
	typedef string				_tstring;
	typedef ostream				_tostream;
	typedef istream				_tistream;
	typedef stringstream		_tstringstream;
	typedef istringstream		_tistringstream;
	typedef ostringstream		_tostringstream;
	typedef fstream				_tfstream;
	typedef ofstream			_tofstream;
	typedef ifstream			_tifstream;


	template< class An_object_type >
	inline const string _toString( const An_object_type &someString ) {
		return toString( someString );
	}

	#define _tfputc( _tfputc_parameter_x, _tfputc_parameter_y )		fputc( ( _tfputc_parameter_x ), ( _tfputc_parameter_y ) )
	#define _tfputs( _tfputs_parameter_x, _tfputs_parameter_y )		fputs( ( _tfputs_parameter_x ), ( _tfputs_parameter_y ) )

	JMSF_STDAL_DLL_INTERFACE extern istream &_tcin;
	JMSF_STDAL_DLL_INTERFACE extern ostream &_tcout;
	JMSF_STDAL_DLL_INTERFACE extern ostream &_tcerr;	
	JMSF_STDAL_DLL_INTERFACE extern ostream &_tclog;	

#endif

JMSF_STDAL_DLL_INTERFACE std::string &searchAndReplace( std::string &aString, const std::string &whatToReplace, const std::string &whatToReplaceTo ) throw();

} // namespace


#if defined( _UNICODE )	
	typedef wchar_t		_tchar;
	#define _t( _t_paramter_x )		L ## _t_paramter_x
#else
	typedef char		_tchar;
	#define _t( _t_paramter_x )		_t_paramter_x
#endif

namespace stdal_stl {
	using namespace std;
}
