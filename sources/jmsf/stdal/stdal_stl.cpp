#include "stdal_stl.h"


namespace std {


JMSF_STDAL_DLL_INTERFACE const string toString( const string &someString ) throw() {
	return someString;
}

JMSF_STDAL_DLL_INTERFACE const string toString( const wstring &someWideString ) throw() {
	const wstring::const_iterator begin = someWideString.begin();
	const wstring::const_iterator end = someWideString.end();
	return string( begin, end );
}

JMSF_STDAL_DLL_INTERFACE const wstring toWideString( const string &someString ) throw() {
	const string::const_iterator begin = someString.begin();
	const string::const_iterator end = someString.end();
	return wstring( begin, end );
}

JMSF_STDAL_DLL_INTERFACE const wstring toWideString( const wstring &someWideString ) throw() {
	return someWideString;
}


#if defined( _UNICODE )
	wistream &_tcin = wcin;
	wostream &_tcout = wcout;
	wostream &_tcerr = wcerr;
	wostream &_tclog = wclog;

#else
	istream &_tcin = cin;
	ostream &_tcout = cout;
	ostream &_tcerr = cerr;
	ostream &_tclog = clog;

#endif

std::string &searchAndReplace( std::string &aString, const std::string &whatToReplace, const std::string &whatToReplaceTo ) throw() {
	size_t pos = 0;

	while ( ( pos = aString.find( whatToReplace, pos ) ) != std::string::npos ) {
		aString.replace( pos, whatToReplace.length(), whatToReplaceTo );
		pos += whatToReplaceTo.length();
	}

	return aString;
}

} // namespace
