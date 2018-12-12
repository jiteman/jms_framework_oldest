#pragma once
//------------------


//#include <stdio.h>
//#include <string.h>

//#include "winspe.h"
//#include "my_assert.h"


namespace jmsf {
namespace typing {
namespace examples {


static const char * XMLVERSION = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

//--------------------------------------------------------------------------
class CharString {

public:
	CharString() {
		init( 20, 10 );
	}
	
	CharString( int siz, int siz_grow ) {
		init( siz, siz_grow );
	}
	
	CharString( const char *s ) {
		if ( s == NULL ) {
			init( 20, 10 );
		} else {
			init( ::strlen( s ), 10 );
			copy( s );
		}
	}
	
	CharString( const CharString &s ) {
		init( s.len, 10 );
		copy( s.pt_buf );
	}
	
	CharString( const char *fn, const char *mode); // load content of a text file fn
	
	~CharString();
	
	void grow( int new_size ); // increases the size of the allocated area
	
	void dump();
	
	void operator =( const CharString & );
	void operator =( const char * );
	void operator =( char );
	
	// built a temporary copy in str_buf the character string as parameter function to be compatible with const char * ex: strcpy (target, my-string);
	operator const char*();
	
	// comparators
	BOOL operator ==( const CharString &s ) {
		return ::strcmp( pt_buf, s.pt_buf ) == 0;
	}
	
	BOOL operator ==( const char *s ) {
		if ( s == NULL ) return false;

		return ::strcmp( pt_buf, s ) == 0;
	}
	
	BOOL operator !=( const CharString &s ) {
		return ::strcmp( pt_buf, s.pt_buf ) != 0;
	}

	BOOL operator !=( const char *s ) {
		return !operator ==( s );
	}
	
	BOOL operator >( const CharString &s ) {
		return ::strcmp( pt_buf, s.pt_buf ) > 0;
	}

	BOOL operator >( const char *s ) {
		if ( s == NULL ) return false;

		return ::strcmp( pt_buf, s ) > 0;
	}
	
	BOOL operator <( const CharString & s ) {
		return ::strcmp( pt_buf, s.pt_buf ) < 0;
	}
	
	BOOL operator <( const char *s ) {
		if ( s == NULL ) return false;
		
		return ::strcmp( pt_buf, s ) < 0;
	}
	
	BOOL operator >=( const CharString & s ) {
		return ::strcmp( pt_buf, s.pt_buf ) >= 0;
	}
	
	BOOL operator >=( const char *s ) {
		if ( s == NULL ) return false;

		return ::strcmp( pt_buf, s ) >= 0;
	}
	
	BOOL operator <=( const CharString &s ) {
		return ::strcmp( pt_buf, s.pt_buf ) <= 0;
	}

	BOOL operator <=( const char *s ) {
		if ( s == NULL ) return false;

		return ::strcmp( pt_buf, s ) <= 0;
	}
	
	// append
	void operator +=( char );
	void operator +=( const CharString & );
	void operator +=( const char * );
	
	// append the type of stream
	CharString&  operator << (const CharString&);
	CharString&  operator << (const char*);
	CharString&  operator << (char);

	CharString&  operator << (unsigned char x) {
		*this << ( unsigned int )x;
		return *this;
	}
	
	CharString&  operator << (int);
	CharString&  operator << (unsigned int);
	
	CharString&  operator << (short x) {
		*this << ( int )x;
		return *this;
	}
	
	CharString&  operator <<(unsigned short x) {
		*this << (unsigned int)x;
		return *this;
	}
	
	CharString&  operator << ( long x ) {
		*this << (int)x;
		return *this;
	}
	
	CharString&  operator << (unsigned long x) {
		*this << (unsigned int)x;
		return *this;
	}
	
	CharString&  operator << (float);
	
	// append the characters to reach a length desiree
	CharString&  fill(char c, int lg);
	
	// dump stream types	
	CharString&  operator >> (char*);
	CharString&  operator >> (char&);
	CharString&  operator >> (int&);
	CharString&  operator >> (long&);
	CharString&  operator >> (float&);

	CharString&  operator >> (short& x) {
		int i;
		*this >> i;
		
		if ( flags_read == 0 ) x = i;
		
		return *this;
	}
	
	CharString&  operator >> (unsigned int&);
	CharString&  operator >> (unsigned char& x) {
		unsigned i;
		*this >> i;
		
		if ( flags_read == 0 ) x = i;
		
		return *this;
	}
	
	CharString&  operator >> (unsigned short& x) {
		unsigned i;
		*this >> i;
		
		if ( flags_read == 0 ) x = i;
		
		return *this;
	}
	
	CharString&  operator >> (unsigned long& x) {
		unsigned i;
		*this >> i;
		
		if ( flags_read == 0 ) x = i;
		
		return *this;
	}
	
	// before emptying the terminator if it exists, otherwise all
	CharString&  getline(char* bufr, int size_buf, char terminator = '\n');
	
	// next read string between c1 and c2 excluded if ok, this contains the following c2, thus avoiding to trample
	CharString&  getsentence(char* bufr, int size_buf, char c1='<', char c2= '>');
	
	// read a character
	char item(int i) {
		my_assert ( i >= 0 && i < ( int )len );
		return pt_buf[ i ];
	}
	
	// read / write a character
	char &operator []( int i ) {
		return pt_buf[ i ];
	}
	
	// length of the string without the terminator
	int length() {
		return len;
	}
	
	// chain length with the terminator (depending ostrstream)
	int pcount() {
		return len + 1;
	}
	
	// test if string empty
	BOOL empty() {
		return len == 0;
	}
	
	// uppercase <-> lowercase
	void upcase();
	void downcase();
	
	// oter and white tab
	void remove_blanks();
	
	// of occurrence research
	int index( char c, int posdeb = 0 );
	int index( const char * , int posdeb = 0 );

	int index( const CharString &s, int posdeb = 0 ) {
		return index( s.pt_buf, posdeb );
	}
	
	BOOL contains( const char *s ) {
		return index( s, 0 ) >= 0;
	}
	
	BOOL contains( CharString &s ) {
		return index( s.pt_buf, 0 ) >= 0;
	}
	
	// extracting a substring
	CharString from( int pos ); // extraction from pos included
	CharString before( int pos ); // extraction before pos excluded
	CharString fromAndBefore( int posdeb, int posfin ); // extraction from pos included and excluded before pos / YB * 240903 * /
	
	CharString from( char c ) {
		return from( index( c ) );
	}
	
	CharString before( char c ) {
		return before( index( c ) );
	}
	
	CharString until( char c ) {
		return before( index( c ) + 1 );
	}
	
	// modification of the chain: delete, global substitution

  void         del(int posdeb, int len);   // deletion of text
  void         gsub(const char* s1, const char* s2, int nb_occur=50); // substitution of n occurrences (default max = 50) / * 300999 * YB /
  
// reading pointer character string

  const char*  chars()                     { return pt_buf; }        

// reading and tsunami of flags associated to the operator ">>"
    unsigned short flags()                 { return flags_read; }
    void           reset_flags()           { flags_read = 0; }


// split on selected separator (default = '').
// Destroy the pointer after use (if! = NULL) :: by charstring delete_pt (pt)
// makes the no words in nb_items

    CharString* split(short& nb_items, char sep = ' ');

    static void delete_pt(CharString* pt); // delete [] pt


//	Manipulation Functions stream or XML documents

	// get an XML element, return = offset for the following research, or 0 if not found
	int getXMLElement(const char * xmlElementName, CharString & xmlElement, int fromIndex=0);

	// get the contents of an XML element if the presence of the tag start and end
	bool getXMLElementValue(const char * xmlElementName, CharString & xmlElementValue, int fromIndex=0);

	// get the value of an attribute of an XML element
	bool getXMLAttributeValue(const char * xmlAttributeName, CharString & xmlAttributeValue, int fromIndex=0);

	// Counting occurrences nb XML Elements with or without content, with or without attribute
	int	 getNbXMLElement(const char * xmlElementName);

	// Encoding of an XML element
	void setXMLElement (const char * xmlElementName, const char * xmlElementValue);
	void setXMLElement (const char * xmlElementName, long xmlElementValue);

	// Encoding tag beginning of an XML element
	void setBeginXMLElement (const char * xmlElementName);

	// Encoding end tag of an XML element
	void setEndXMLElement (const char * xmlElementName);

// test flags
    BOOL    ok()                { return flags_read == 0; }
    BOOL    operator!()         { return flags_read != 0; }


protected:
     unsigned int       len;           // string length 
     unsigned int       sz;            // allocated space
     unsigned short     sz_grow;       // expansion grain
     unsigned short     flags_read;    // E_ErrRead flags after ">>" or getline
                                       // (tidal to each assignment "=")
     char*              pt_buf;

     void     init(int size, int size_grow); 
     void     copy(const char* s2);

enum E_ErrRead { read_char=1, read_int= 2, read_float= 4, read_chars= 8, 
				 open_file= 0x10, read_file= 0x20 };
 
friend CharString operator + (const CharString&, const CharString&);
friend CharString operator + (const CharString&, const char*);
friend CharString operator + (const char*, const CharString&);

};

//--------------------------------------------------------------------------

} // namespace examples
} // namespace typing
} // namespace jmsf
