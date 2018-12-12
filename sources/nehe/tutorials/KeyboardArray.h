#pragma once


#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"


namespace nehe {


class KeyboardArray {

public:
	bool isPressed( ::jmsf::natural_size keyId ) const throw();
	bool wasPressed( ::jmsf::natural_size keyId ) const throw();

	::jmsf::natural_size popOldestKeyId();
	void clearBuffers();
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void setState( ::jmsf::natural keyId, bool keyState ) throw();
	void resetAllStates();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~KeyboardArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	KeyboardArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	KeyboardArray( const KeyboardArray &other ) throw();
	const KeyboardArray &operator =( const KeyboardArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	bool *_keyboardState;
	::std::list< ::jmsf::natural_size > _keyPressed;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const ::jmsf::natural_size QUANTITY_OF_KEYBOARD_KEYS;
	static const ::jmsf::natural_size QUANTITY_OF_KEYS_TO_KEEP;

};


} // namespace nehe
