#pragma once

#include "../Container.hpp"
#include "../mixins/mixin_Object.h"

#include "realization_factory_Container.hxx"

namespace jmsf {
namespace containers {
namespace realizations {


template< class A_type >
class realization_ContainerArray :
	public Container< A_type >,
	public mixins::mixin_Object
{

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // getters
	// virtuals Container
	const Boolean isEmpty() const throw();
	const Boolean isNotEmpty() const throw();
	natural_size getQuantityOfElements() const throw();

	const A_type &getContainieAtBegin() const throw( Exception );
	A_type &takeContainieAtBegin() throw( Exception );
	const A_type &getContainieAtEnd() const throw( Exception );
	A_type &takeContainieAtEnd() throw( Exception );
	const A_type &getContainieAt( natural_size index ) const throw( Exception );
	A_type &takeContainieAt( natural_size index ) throw( Exception );
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Container
	void appendToBegin( const A_type &object ) throw();
	void appendToEnd( const A_type &object ) throw();
	void insertAfter( natural_size index, const A_type &object ) throw( Exception );
	Proxy< Iterator< A_type > > insertAfter( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception );
	void insertBefore( natural_size index, const A_type &object ) throw();
	Proxy< Iterator< A_type > > insertBefore( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception );
	
	A_type withdrawContainieAtBegin() throw( Exception );
	A_type withdrawLastContainieAtEnd() throw( Exception );
	A_type withdrawContainieAt( natural_size index ) throw( Exception );

	void eraseContainieAtBegin() throw( Exception );
	void eraseContainieAtEnd() throw( Exception );
	void eraseContainieAt( natural_size index );

	void clear() throw();
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // iterator operations
	Proxy< Iterator< A_type > > insertAfter( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception );
	Proxy< Iterator< A_type > > insertBefore( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception );
	Proxy< Iterator< A_type > > withdrawContainieAt( A_type &outObject, const Proxy< Iterator< A_type > > anIterator ) throw( Exception );
	Proxy< Iterator< A_type > > eraseContainieAt( const Proxy< Iterator< A_type > > &anIterator ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container
	Proxy< Iterator< A_type > > createFrontIterator() throw();
	Proxy< Iterator< A_type > > createBackIterator() throw();
	Proxy< Iterator< A_type > > createIteratorAt( natural_size index ) throw( Exception );

	Proxy< ConstantIterator< A_type > > createConstantFrontIterator() throw();
	Proxy< ConstantIterator< A_type > > createConstantBackIterator() throw();
	Proxy< ConstantIterator< A_type > > createConstantIteratorAt( natural_size index ) throw( Exception );
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Container< A_type >
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception );
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception );
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception );
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception );
	//~virtuals Container< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~realization_ContainerArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_ContainerArray( natural_size initialSizeOfBuffer = 0, natural_size deltaSizeOfBuffer = 0 ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_ContainerArray( const realization_ContainerArray &other ) throw();
	const realization_ContainerArray &operator =( const realization_ContainerArray &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void moveContainiesUp( natural_size startIndex, natural_size endIndex ) throw();
	void moveContainiesDown( natural_size startIndex, natural_size endIndex ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type *_bufferOfObjects;
	natural_size _sizeOfBuffer;
	natural_size _sizeOfArray;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const natural_size _deltaSizeOfBuffer;

private:
	static const natural_size MINIMAL_DELTA_SIZE_OF_BUFFER = 16;
	static const natural_size NULL_INDEX = ~natural_size( 0 );
};


} // namespace realizations
} // namespace containers
} // namespace jmsf


#include "jmsf/exceptions/exception_BadContainerDereferencing.h"
#include "jmsf/debugging/ArrayCreationLogging.h"
#include "jmsf/debugging/ArrayDeletionLogging.h"


namespace jmsf {
namespace containers {
namespace realizations {


template< class A_type >
const Boolean realization_ContainerArray< A_type >::isEmpty() const throw() {
	return _sizeOfArray == 0;
}

template< class A_type >
const Boolean realization_ContainerArray< A_type >::isNotEmpty() const throw() {
	return _sizeOfArray != 0;
}

template< class A_type >
natural_size realization_ContainerArray< A_type >::getQuantityOfObjects() const throw() {
	return _sizeOfArray;
}

template< A_type >
const A_type &realization_ContainerArray< A_type >::getContainieAtBegin() const throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::getFirstContainie()" ) );
	}

	return *_bufferOfObjects;
}

template< A_type >
A_type &realization_ContainerArray< A_type >::takeContainieAtBegin() throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::takeFirstContainie()" ) );
	}

	return *_bufferOfObjects;
}

template< A_type >
const A_type &realization_ContainerArray< A_type >::getContainieAtEnd() const throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::getLastContainie()" ) );
	}

	return *( _bufferOfObjects + _sizeOfArray - 1 );
}

template< A_type >
A_type &realization_ContainerArray< A_type >::takeContainieAtEnd() throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::takeLastContainie()" ) );
	}

	return *( _bufferOfObjects + _sizeOfArray - 1 );
}

template< A_type >
const A_type &realization_ContainerArray< A_type >::getContainieAt( const natural_size index ) const throw( Exception ) {
	if ( _sizeOfArray <= index ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::getContainieAt( " ) )->putNatural( index )->put( CONSTANT_TEXT_STRING( " ) with size of array: " ) );
		textStream->putNatural( _sizeOfArray );
		throw exceptions::exception_BadContainerDereferencing( textStream );
	}

	return *( _bufferOfObjects + index );
}

template< A_type >
A_type &realization_ContainerArray< A_type >::takeContainieAt( const natural_size index ) throw( Exception ) {
	if ( _sizeOfArray <= index ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::takeContainieAt< A_type >::takeAt( " ) )->putNatural( index )->put( CONSTANT_TEXT_STRING( " ) with size of array: " ) );
		textStream->putNatural( _sizeOfArray );
		throw exceptions::exception_BadContainerDereferencing( textStream );
	}

	return *( _bufferOfObjects + index );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
void realization_ContainerArray< A_type >::appendToBegin( const A_type &object ) throw() {
	if ( _sizeOfBuffer < _sizeOfArray + 1 ) {
		const natural_size sizeOfNewBuffer = _sizeOfBuffer + ( _deltaSizeOfBuffer != 0 ? _deltaSizeOfBuffer : ( _sizeOfBuffer > 1 ? _sizeOfBuffer / 2 : 1 ) );
		A_type *newBufferOfObjects = new A_type[ sizeOfNewBuffer ];
		debugging::static_ArrayCreationLogger::registerCreation( debugging::createMulInformationForArrayCreation( newBufferOfObjects, sizeOfNewBuffer, MACROS_FILE_AND_LINE ) );

		{
			A_type *pointerToOldBuffer = _bufferOfObjects;
			A_type *pointerToNewBuffer = newBufferOfObjects + 1;

			for ( natural_size existingObjectCounter = 0; existingObjectCounter < _sizeOfArray; existingObjectCounter += 1 ) {
				*pointerToNewBuffer++ = *pointerToOldBuffer++;
			}
		}

		if ( _bufferOfObjects != nullptr ) {
			debugging::static_ArrayDeletionLogger::registerDeletion( debugging::createMulInformationForArrayDeletion( _bufferOfObjects, _sizeOfBuffer, MACROS_FILE_AND_LINE ) );
			delete[] _bufferOfObjects;
		}

		_bufferOfObjects = newBufferOfObjects;
		_sizeOfBuffer = sizeOfNewBuffer;
	} else {
		{
			A_type *pointerToBuffer = _bufferOfObjects + _sizeOfArray;

			for ( natural_size existingObjectCounter = _sizeOfArray; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
				*pointerToBuffer = *( pointerToBuffer - 1 );
				pointerToBuffer -= 1;
			}
		}
	}

	*_bufferOfObjects = object;
	_sizeOfArray += 1;
}

template< class A_type >
void realization_ContainerArray< A_type >::appendBack( const A_type &object ) throw() {
	if ( _sizeOfBuffer < _sizeOfArray + 1 ) {
		const natural_size sizeOfNewBuffer = _sizeOfBuffer + ( _deltaSizeOfBuffer != 0 ? _deltaSizeOfBuffer : ( _sizeOfBuffer > 1 ? _sizeOfBuffer / 2 : 1 ) );
		A_type *newBufferOfObjects = new A_type[ sizeOfNewBuffer ];
		debugging::static_ArrayCreationLogger::registerCreation( debugging::createMulInformationForArrayCreation( newBufferOfObjects, sizeOfNewBuffer, MACROS_FILE_AND_LINE ) );

		{
			A_type *pointerToOldBuffer = _bufferOfObjects;
			A_type *pointerToNewBuffer = newBufferOfObjects;

			for ( natural_size existingObjectCounter = 0; existingObjectCounter < _sizeOfArray; existingObjectCounter += 1 ) {
				*pointerToNewBuffer++ = *pointerToOldBuffer++;
			}
		}

		if ( _bufferOfObjects != nullptr ) {
			debugging::static_ArrayDeletionLogger::registerDeletion( debugging::createMulInformationForArrayDeletion( _bufferOfObjects, _sizeOfBuffer, MACROS_FILE_AND_LINE ) );
			delete[] _bufferOfObjects;
		}

		_bufferOfObjects = newBufferOfObjects;
		_sizeOfBuffer = sizeOfNewBuffer;
	}

	*( _bufferOfObjects + _sizeOfArray ) = object;
	_sizeOfArray += 1;
}

template< A_type >
void realization_ContainerArray< A_type >::insertAfter( const natural_size index, const A_type &object ) throw( Exception ) {
	if ( index == _sizeOfArray - 1 ) {
		appendBack( object );
		return;
	}

	if ( index >= _sizeOfArray ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::insertAfter( " ) )->putNatural( index )->put( CONSTANT_TEXT_STRING( " ) with size of array: " ) );
		textStream->putNatural( _sizeOfArray );
		throw exceptions::exception_BadContainerDereferencing( textStream );
	}

	if ( _sizeOfBuffer < _sizeOfArray + 1 ) { // the place is exhausted
		// create new buffer of increased size
		const natural_size sizeOfNewBuffer = _sizeOfBuffer + ( _deltaSizeOfBuffer != 0 ? _deltaSizeOfBuffer : ( _sizeOfBuffer > 1 ? _sizeOfBuffer / 2 : 1 ) );
		A_type *newBufferOfObjects = new A_type[ sizeOfNewBuffer ];
		debugging::static_ArrayCreationLogger::registerCreation( debugging::createMulInformationForArrayCreation( newBufferOfObjects, sizeOfNewBuffer, MACROS_FILE_AND_LINE ) );

		// copy data whithin the indexed data into new buffer as is
		A_type *pointerToOldBuffer = _bufferOfObjects;
		A_type *pointerToNewBuffer = newBufferOfObjects;

		for ( natural_size existingObjectCounter = index + 1; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToNewBuffer++ = *pointerToOldBuffer++;
		}

		pointerToNewBuffer += 1; // skip to hold a place for new object

		// copy the rest data (after the indexed data) with one step shift into new buffer
		for ( natural_size existingObjectCounter = _sizeOfArray - index - 1; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToNewBuffer++ = *pointerToOldBuffer++;
		}
	} else { // there's enough of place
		// copy data after the indexed data into snew buffer
		A_type *pointerToBuffer = _bufferOfObjects + _sizeOfArray;

		for ( natural_size existingObjectCounter = _sizeOfArray - index - 1; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToBuffer = *( pointerToBuffer - 1 );
			pointerToBuffer -= 1;
		}
	}

	// copy new object into the appropriate position
	*( _bufferOfObjects + index ) = object;
	_sizeOfArray += 1;
}

template< A_type >
Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::insertAfter( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception ) {
	try {
		const Proxy< Iterator 
	} catch ( ... ) {

	}
}

template< A_type >
void realization_ContainerArray< A_type >::insertBefore( const natural_size index, const A_type &object ) throw() {
	if ( index == 0 ) {
		appendFront( object );
	}

	if ( index >= _sizeOfArray ) {
		Proxy< TextStream > textStream = factory_TextObject::instance()->createTextStream();
		textStream->put( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::insertBefore( " ) )->putNatural( index )->put( CONSTANT_TEXT_STRING( " ) with size of array: " ) );
		textStream->putNatural( _sizeOfArray );
		throw exceptions::exception_BadContainerDereferencing( textStream );
	}

	if ( _sizeOfBuffer < _sizeOfArray + 1 ) { // the place is exhausted
		// create new buffer of increased size
		const natural_size sizeOfNewBuffer = _sizeOfBuffer + ( _deltaSizeOfBuffer != 0 ? _deltaSizeOfBuffer : ( _sizeOfBuffer > 1 ? _sizeOfBuffer / 2 : 1 ) );
		A_type *newBufferOfObjects = new A_type[ sizeOfNewBuffer ];
		debugging::static_ArrayCreationLogger::registerCreation( debugging::createMulInformationForArrayCreation( newBufferOfObjects, sizeOfNewBuffer, MACROS_FILE_AND_LINE ) );

		// copy data before index into new buffer as is
		A_type *pointerToOldBuffer = _bufferOfObjects;
		A_type *pointerToNewBuffer = newBufferOfObjects;

		for ( natural_size existingObjectCounter = index; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToNewBuffer++ = *pointerToOldBuffer++;
		}

		pointerToNewBuffer += 1; // skip to hold a place for new object

		// copy the rest data (within the indexed data) with one step shift into new buffer
		for ( natural_size existingObjectCounter = _sizeOfArray - index; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToNewBuffer++ = *pointerToOldBuffer++;
		}
	} else { // there's enough of place
		// copy data after the indexed data into new buffer
		A_type *pointerToBuffer = _bufferOfObjects + _sizeOfArray;

		for ( natural_size existingObjectCounter = _sizeOfArray - index; existingObjectCounter != 0; existingObjectCounter -= 1 ) {
			*pointerToBuffer = *( pointerToBuffer - 1 );
			pointerToBuffer -= 1;
		}
	}

	// copy new object into the appropriate position
	*( _bufferOfObjects + index ) = object;
	_sizeOfArray += 1;
}

template< A_type >
Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::insertBefore( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception ) {

}

template< A_type >
void realization_ContainerArray< A_type >::clear() throw() {
	A_type *pointerToBuffer = _bufferOfObjects;

	for ( natural_size objectCounter = 0; objectCounter < _sizeOfArray; objectCounter += 1 ) {
		*pointerToBuffer++ = A_type();
	}

	_sizeOfArray = 0;
}

template< class A_type >
A_type realization_ContainerArray< A_type >::withdrawFirstContainie() throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::withdrawFirst()" ) );
	}

	A_type oldFirstObject = getFirst();
	_sizeOfArray -= 1;

	if ( isNotEmpty() ) {
		A_type *pointerToBuffer = _bufferOfObjects;

		for ( natural_size existingObjectCounter = 0; existingObjectCounter < _sizeOfArray; existingObjectCounter += 1 ) {
			*pointerToBuffer = *( pointerToBuffer + 1 );
			pointerToBuffer += 1;
		}
	}

	*( _bufferOfObjects + _sizeOfArray ) = A_type();
	return oldFirstObject;
}

template< class A_type >
A_type realization_ContainerArray< A_type >::withdrawLastContainie() throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::withdrawLast()" ) );
	}

	A_type oldLastObject = getLast();
	_sizeOfArray -= 1;
	*( _bufferOfObjects + _sizeOfArray ) = A_type();
	return oldLastObject;
}

template< class A_type >
A_type realization_ContainerArray< A_type >::withdrawContainieAt( const natural_size index ) throw( Exception ) {
	if ( isEmpty() ) {
		throw exceptions::exception_BadContainerDereferencing( CONSTANT_TEXT_STRING( "realization_ContainerArray< A_type >::withdrawFirst()" ) );
	}

// 	A_type oldFirstObject = getFirst();
// 	_sizeOfArray -= 1;
// 
// 	if ( isNotEmpty() ) {
// 		A_type *pointerToBuffer = _bufferOfObjects;
// 
// 		for ( natural_size existingObjectCounter = 0; existingObjectCounter < _sizeOfArray; existingObjectCounter += 1 ) {
// 			*pointerToBuffer = *( pointerToBuffer + 1 );
// 			pointerToBuffer += 1;
// 		}
// 	}
// 
// 	*( _bufferOfObjects + _sizeOfArray ) = A_type();
// 	return oldFirstObject;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::createIteratorOneStepMovedToBegin( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception ) {
	
}

template< A_type >
Proxy< ConstantIterator< A_type > > realization_ContainerArray< A_type >::createIteratorOneStepMovedToBegin( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception ) {
	
}

template< A_type >
Proxy< Iterator< A_type > > realization_ContainerArray< A_type >::createIteratorOneStepMovedToEnd( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception ) {
	
}

template< A_type >
Proxy< ConstantIterator< A_type > > realization_ContainerArray< A_type >::createIteratorOneStepMovedToEnd( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception ) {
	
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ContainerArray< A_type >::~realization_ContainerArray() throw() {
	if ( _bufferOfObjects != nullptr ) {
		debugging::static_ArrayDeletionLogger::registerDeletion( debugging::createMulInformationForArrayDeletion( _bufferOfObjects, _sizeOfBuffer, MACROS_FILE_AND_LINE ) );
		delete[] _bufferOfObjects;
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerArray< A_type >::realization_ContainerArray( const natural_size initialSizeOfBuffer, const natural_size deltaSizeOfBuffer ) throw()
	:
		_deltaSizeOfBuffer( deltaSizeOfBuffer )
{
	_sizeOfArray = 0;
	_sizeOfBuffer = initialSizeOfBuffer;
	_bufferOfObjects = _sizeOfBuffer == 0 ? nullptr : new A_type[ _sizeOfBuffer ];

	if ( _bufferOfObjects != nullptr ) {
		debugging::static_ArrayCreationLogger::registerCreation( debugging::createMulInformationForArrayCreation( _bufferOfObjects, _sizeOfBuffer, MACROS_FILE_AND_LINE ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ContainerArray< A_type >::realization_ContainerArray( const realization_ContainerArray< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ContainerArray< A_type > &realization_ContainerArray< A_type >::operator =( const realization_ContainerArray< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< A_type >
void realization_ContainerArray< A_type >::moveContainiesUp( const natural_size startIndex, const natural_size endIndex ) throw() {
	
}

template< A_type >
void realization_ContainerArray< A_type >::moveContainiesDown( const natural_size startIndex, const natural_size endIndex ) throw() {
	
}


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizations
} // namespace containers
} // namespace jmsf
