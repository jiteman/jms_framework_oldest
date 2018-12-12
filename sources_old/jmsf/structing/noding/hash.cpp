Containers and iterators

hash

#define _HASH_SEED (size_t)0xdeadbeef

size_t hash_value( const _Kty& _Keyval ) {
	// hash _Keyval to size_t value one-to-one
	return static_cast< size_t >( _Keyval ^ _HASH_SEED );
}

size_t _Hash_value( _InIt _Begin, _InIt _End ) {
	// hash range of elements
	size_t _Val = 2166136261U;

	while ( _Begin != _End ) {
		_Val = 16777619U * _Val ^ static_cast< size_t >( *_Begin++ );
	}
	
	return _Val;
}

class ldiv_t {
	
public:
	ldiv_t( long numer, long denom );
	
public:
	long quot;
	long rem;
	
};

ldiv_t::ldiv_t( const long numer, const long denom ) {
	quot = numer / denom;
	rem = numer % denom;
}

size_t operator ()( const _Kty &_Keyval ) const {
	// hash _Keyval to size_t value by pseudorandomizing transform
	const long _Quot = static_cast< long >( hash_value( _Keyval ) & LONG_MAX );
	ldiv_t _Qrem( _Quot, 127773 );
	_Qrem.rem = 16807 * _Qrem.rem - 2836 * _Qrem.quot;
	
	if ( _Qrem.rem < 0 ) {
		_Qrem.rem += LONG_MAX;
	}
	
	return static_cast< size_t >( _Qrem.rem );
}