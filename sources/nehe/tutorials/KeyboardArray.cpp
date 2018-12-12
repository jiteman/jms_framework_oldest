#include "KeyboardArray.h"


namespace nehe {

bool KeyboardArray::isPressed( const ::jmsf::natural_size keyId ) const throw() {
	if ( _keyboardState == nullptr ) return false;
	if ( keyId >= QUANTITY_OF_KEYBOARD_KEYS ) return false;

	return _keyboardState[ keyId ];
}

bool KeyboardArray::wasPressed( const ::jmsf::natural_size keyId ) const throw() {
	const std::list< ::jmsf::natural_size >::const_iterator keyIdIterator = std::find( _keyPressed.begin(), _keyPressed.end(), keyId );
	return keyIdIterator != _keyPressed.end();
}

::jmsf::natural_size KeyboardArray::popOldestKeyId() {
	if ( _keyPressed.empty() ) return 0;

	const ::jmsf::natural_size oldestKeyId = _keyPressed.back();
	_keyPressed.pop_back();
	return oldestKeyId;
}


void KeyboardArray::clearBuffers() {
	_keyPressed.clear();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void KeyboardArray::setState( const ::jmsf::natural keyId, const bool keyState ) throw() {
	if ( _keyboardState == nullptr ) return;
	if ( keyId >= QUANTITY_OF_KEYBOARD_KEYS ) return;

	if ( _keyboardState[ keyId ] == keyState ) return;

	_keyboardState[ keyId ] = keyState;

	if  ( keyState ) {
		if ( _keyPressed.size() == QUANTITY_OF_KEYS_TO_KEEP ) {
			_keyPressed.pop_back();
		}

		_keyPressed.push_front( keyId );
	}	
}

void KeyboardArray::resetAllStates() {
	if ( _keyboardState == nullptr ) return;

	bool *keyStateIterator = &_keyboardState[ 0 ];

	for ( ::jmsf::natural_size index = 0; index < QUANTITY_OF_KEYBOARD_KEYS; index += 1 ) {
		*( keyStateIterator++ ) = false;
	}
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
KeyboardArray::~KeyboardArray() throw() {
	delete[] _keyboardState;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
KeyboardArray::KeyboardArray() throw() {
	_keyboardState = new bool[ QUANTITY_OF_KEYBOARD_KEYS ];
	resetAllStates();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
KeyboardArray::KeyboardArray( const KeyboardArray & ) throw() { // other
}

const KeyboardArray &KeyboardArray::operator =( const KeyboardArray &other ) throw() {
	if ( &other != this ) {
		// copy
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const ::jmsf::natural_size KeyboardArray::QUANTITY_OF_KEYBOARD_KEYS = 256;

// static
const ::jmsf::natural_size KeyboardArray::QUANTITY_OF_KEYS_TO_KEEP = 32;

} // namespace nehe
