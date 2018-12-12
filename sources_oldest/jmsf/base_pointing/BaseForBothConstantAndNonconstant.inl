#pragma once


#include "BaseForBothConstantAndNonconstant.hpp"


#include "jmsf/Exception.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/osie/Mutex.h"
#include "jmsf/Automatic.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"
#include "jmsf/debugging/ObjectDeletionLogging.h"
#include "ReferenceCounters.h"
//#include "jmsf/debugging/MemoryUsingLogging.h"


namespace jmsf {
namespace base_pointing {


// statics
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_None = 128;
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_Empty = 64;
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_Nonlinked = 32;
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_Weak = 16;
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_Unique = 8;
const types::ShortestNatural BaseForBothConstantAndNonconstant< Indirector_type >::type_Shared = 4;
//~statics


template< class Indirector_type >
Boolean BaseForBothConstantAndNonconstant< Indirector_type >::isEmpty() const throw( Exception ) {
	validate();
	return _pointerToObject == Indirector_type::getNull();
//	return _type == type_None ? _pointerToObject == nullptr : _pointerToObject == Indirector_type::getNull();
}

template< class Indirector_type >
Boolean BaseForBothConstantAndNonconstant< Indirector_type >::isNotEmpty() const throw( Exception ) {
//	validate(); // in isEmpty();
	return isEmpty().not();
}

template< class Indirector_type >
natural_size BaseForBothConstantAndNonconstant< Indirector_type >::getConnectivity() const throw( Exception ) {
	validate();

	switch ( _type ) {
		case type_None:
		case type_Empty:
		case type_Nonlinked:
//		case type_Weak:
			return 0;

		case type_Unique:
			return 1;

		case type_Weak:
		case type_Shared:
			return _referenceCounters->getConnectivity();

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
			return 0;
	}
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::get() throw( Exception ) {
	validate();
	return _pointerToObject;
}

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::get() const throw( Exception ) {
	validate();
	return _pointerToObject;
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::release() throw( Exception ) {
	validate();
	Indirector_type::type_indirected *pointerToObject = nullptr;

	switch ( _type ) {
		case type_None:
			// A_type *pointerToObject = nullptr;
			break;
	
		case type_Empty:
			pointerToObject = _pointerToObject; // NullObject
			_pointerToObject = Indirector_type::getNull();
			break;

		case type_Nonlinked:
			pointerToObject = _pointerToObject;
			_pointerToObject = Indirector_type::getNull();
			_type = type_Empty;
			break;
	
		case type_Unique:
			pointerToObject = _pointerToObject;
			_pointerToObject = Indirector_type::getNull();
			_type = type_Empty;
			break;

		case type_Weak:
			takeStaticMutex()->lock();
			_referenceCounters->decreaseWeak();

			if ( _referenceCounters->isStrongNull() ) {
				if ( _referenceCounters->isWeakNull() ) {
					takeStaticMutex()->unlock();

					debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _referenceCounters, MACROS_FILE_AND_LINE ) );
					delete _referenceCounters;
				} else {
					takeStaticMutex()->unlock();
				}
			} else {
				takeStaticMutex()->unlock();				
			}
			
			_pointerToObject = Indirector_type::getNull();
			_referenceCounters = nullptr;
			_type = type_Empty;
			break;

		case type_Shared:
			takeStaticMutex()->lock();
			_referenceCounters->decreaseStrong();

			if ( _referenceCounters->isStrongNull() ) {
				if ( _referenceCounters->isWeakNull() ) {
					takeStaticMutex()->unlock();

					debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _referenceCounters, MACROS_FILE_AND_LINE ) );
					delete _referenceCounters;
				} else {
					takeStaticMutex()->unlock();
				}

				pointerToObject = _pointerToObject;
			} else {
				takeStaticMutex()->unlock();
				
			}
			
			_pointerToObject = Indirector_type::getNull();
			_referenceCounters = nullptr;
			_type = type_Empty;
			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
	}

	validate();
	return pointerToObject;
}

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::release() const throw( Exception ) {
	return const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->release();
}

template< class Indirector_type >
void BaseForBothConstantAndNonconstant< Indirector_type >::empty() throw( Exception ) {
	const natural_small previousType = _type;
	Indirector_type::type_indirected *pointerToObject = release();

	switch ( previousType ) {
		case type_None:
		case type_Empty:
		case type_Nonlinked:
		case type_Weak:
			break;

		case type_Unique:
		case type_Shared:
			Indirector_type::_deleteObject( pointerToObject );
			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );			
	}
}

template< class Indirector_type >
void BaseForBothConstantAndNonconstant< Indirector_type >::empty() const throw( Exception ) {
	const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->empty();
}

template< class Indirector_type >
void BaseForBothConstantAndNonconstant< Indirector_type >::setFrom( const BaseForBothConstantAndNonconstant< Indirector_type > &other ) throw( Exception ) {
	validate();
	other.validate();

	_type = other._type;

	switch ( other._type ) {
		case type_None:
			if ( _type == type_Empty || _type == type_Weak || _type == type_Unique || _type == type_Shared ) {
				Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED );
			}
			
			_pointerToObject = nullptr;
			_referenceCounters = nullptr;
			break;

		case type_Empty:
			_pointerToObject = Indirector_type::getNull();
			_referenceCounters = nullptr;
			break;

		case type_Nonlinked:
			_pointerToObject = other._pointerToObject;
			_referenceCounters = nullptr;
			break;
			
		case type_Unique:
			takeStaticMutex()->lock();
			_pointerToObject = other._pointerToObject;
			const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( other )._pointerToObject = Indirector_type::getNull();
			const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( other )._type = type_Empty;
			takeStaticMutex()->unlock();
			_referenceCounters = nullptr;
			break;

		case type_Weak:
			takeStaticMutex()->lock();

			if ( other._referenceCounters != nullptr ) {
				if ( other._referenceCounters->isStrongNull() ) {
					other._referenceCounters->decreaseWeak();

					if ( other._referenceCounters->isWeakNull() ) {
						delete other._referenceCounters;
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( other )._referenceCounters = nullptr;
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( other )._pointerToObject = Indirector_type::getNull();
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( other )._type = type_Empty;
					}

					takeStaticMutex()->unlock();
					_referenceCounters = nullptr;
					_pointerToObject = Indirector_type::getNull();
					_type = type_Empty;
				} else {
					_referenceCounters = other._referenceCounters;
					_referenceCounters->increaseWeak();
					takeStaticMutex()->unlock();
					_pointerToObject = other._pointerToObject;
				}
			} else {
				takeStaticMutex()->unlock();
			}

			break;

		case type_Shared:
			takeStaticMutex()->lock();

			if ( other._referenceCounters != nullptr ) {
				_referenceCounters = other._referenceCounters;
				_referenceCounters->increaseStrong();
				takeStaticMutex()->unlock();
				_pointerToObject = other._pointerToObject;
			} else {
				takeStaticMutex()->unlock();
				Should::neverBeNull( other._referenceCounters );
			}

			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
	}

	validate();
	other.validate();
}

template< class Indirector_type >
void BaseForBothConstantAndNonconstant< Indirector_type >::setFrom( const BaseForBothConstantAndNonconstant< Indirector_type > &other ) const throw( Exception ) {
	const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->setFrom( other );
}


template< class Indirector_type >
BaseForBothConstantAndNonconstant< Indirector_type > BaseForBothConstantAndNonconstant< Indirector_type >::createSharedFromThis() const throw( Exception ) {
	validate();

	BaseForBothConstantAndNonconstant< Indirector_type > candidateForShared;

	switch ( _type ) {
		case type_None:
		case type_Empty:
		case type_Nonlinked:
			break;

		case type_Weak:
			candidateForShared = *this;

			if ( !_referenceCounters->isStrongNull() ) {
				takeStaticMutex()->lock();

				if ( !_referenceCounters->isStrongNull() ) {
					_referenceCounters->decreaseWeak();
					_referenceCounters->increaseStrong();
					takeStaticMutex()->unlock();
					candidateForShared._type = type_Shared;
				} else {
					takeStaticMutex()->unlock();
				}				
			}

			break;

		case type_Unique:
			{
				BaseForBothConstantAndNonconstant< Indirector_type > &nonconstantThis = const_cast< BaseForBothConstantAndNonconstant< Indirector_type > & >( *this );
				nonconstantThis._type = type_Shared;
				nonconstantThis._referenceCounters = new ReferenceCounters;
				debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _referenceCounters, MACROS_FILE_AND_LINE ) );
				nonconstantThis._referenceCounters->increaseStrong();
			}
			candidateForShared = *this;
			break;

		case type_Shared:
			candidateForShared = *this;
			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );			
	}

	validate();
	return candidateForShared;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class Indirector_type >
Boolean BaseForBothConstantAndNonconstant< Indirector_type >::operator ==( const BaseForBothConstantAndNonconstant &other ) const throw( Exception ) {
	validate();
	other.validate();
	return _pointerToObject == other._pointerToObject;
}

template< class Indirector_type >
Boolean BaseForBothConstantAndNonconstant< Indirector_type >::operator !=( const BaseForBothConstantAndNonconstant &other ) const throw( Exception ) {
	return operator ==( other ).not();
}

template< class Indirector_type >
typename Indirector_type::type_indirected &BaseForBothConstantAndNonconstant< Indirector_type >::operator *() throw( Exception ) {
	validate();
	Should::neverBeNull( _pointerToObject );
	return *_pointerToObject;
}

template< class Indirector_type >
const typename Indirector_type::type_indirected &BaseForBothConstantAndNonconstant< Indirector_type >::operator *() const throw( Exception ) {
	validate();
	Should::neverBeNull( _pointerToObject );
	return *_pointerToObject;
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::operator ->() throw( Exception ) {
	validate();
	Should::neverBeNull( _pointerToObject );
	return _pointerToObject;
}

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForBothConstantAndNonconstant< Indirector_type >::operator ->() const throw( Exception ) {
	validate();
	Should::neverBeNull( _pointerToObject );
	return _pointerToObject;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class Indirector_type >
BaseForBothConstantAndNonconstant< Indirector_type >::~BaseForBothConstantAndNonconstant() throw() {
	try {
		empty();
	} catch ( const Exception & ) { // catchedException
		// add an exception information message box
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class Indirector_type >
BaseForBothConstantAndNonconstant< Indirector_type >::BaseForBothConstantAndNonconstant() throw( Exception ) {
	_type = type_Empty;
	_pointerToObject = Indirector_type::getNull();
	_referenceCounters = nullptr;
	validate();
}

template< class Indirector_type >
BaseForBothConstantAndNonconstant< Indirector_type >::BaseForBothConstantAndNonconstant( const natural_small type, const typename Indirector_type::type_indirected *const pointerToObject ) throw( Exception ) {
	_type = type;
	_pointerToObject = const_cast< Indirector_type::type_indirected * >( pointerToObject );
	_referenceCounters = nullptr;

	switch ( _type ) {
		case type_None:
		case type_Empty:
		case type_Weak:
		case type_Nonlinked:
		case type_Unique:
			break;

		case type_Shared:
			_referenceCounters = new ReferenceCounters;
			debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _referenceCounters, MACROS_FILE_AND_LINE ) );
			_referenceCounters->increaseStrong();
			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
	}

	validate();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class Indirector_type >
BaseForBothConstantAndNonconstant< Indirector_type >::BaseForBothConstantAndNonconstant( const BaseForBothConstantAndNonconstant< Indirector_type > &other ) throw( Exception ) {
	_type = type_None;
	_pointerToObject = nullptr;
	_referenceCounters = nullptr;
	setFrom( other );
}

template< class Indirector_type >
const BaseForBothConstantAndNonconstant< Indirector_type > &BaseForBothConstantAndNonconstant< Indirector_type >::operator =( const BaseForBothConstantAndNonconstant< Indirector_type > &other ) throw( Exception ) {
	if ( _pointerToObject == other._pointerToObject ) return *this;

	empty();
	setFrom( other );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class Indirector_type >
void BaseForBothConstantAndNonconstant< Indirector_type >::validate() const throw( Exception ) {
	switch ( _type ) {
		case type_None:
			Should::alwaysBeNull( _pointerToObject );
			Should::alwaysBeNull( _referenceCounters );
			break;
	
		case type_Empty:
			Should::alwaysBe( _pointerToObject == Indirector_type::getNull() );
			Should::alwaysBeNull( _referenceCounters );
			break;

		case type_Nonlinked:
			Should::alwaysBeNull( _referenceCounters );
			Should::neverBeNull( _pointerToObject );
			break;
			
		case type_Weak:
			if ( _referenceCounters != nullptr ) {
				if ( _referenceCounters->isStrongNull() ) {
					takeStaticMutex()->lock();
					_referenceCounters->decreaseWeak();

					if ( _referenceCounters->isWeakNull() ) {
						takeStaticMutex()->unlock();

						debugging::static_ObjectDeletionLogger::registerDeletion( debugging::createMulInformationForObjectDeletion( _referenceCounters, MACROS_FILE_AND_LINE ) );
						delete _referenceCounters;
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->_referenceCounters = nullptr;
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->_pointerToObject = Indirector_type::getNull();
						const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->_type = type_Empty;
					} else {
						takeStaticMutex()->unlock();
					}
				}				
			}

			break;

		case type_Unique:
			Should::alwaysBeNull( _referenceCounters );
			Should::neverBe( _pointerToObject == Indirector_type::getNull() );
			break;

		case type_Shared:
			Should::neverBeNull( _referenceCounters );
			Should::neverBe( _pointerToObject == Indirector_type::getNull() );
			break;

		default:
			Should::_neverReachHere( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
	}
}

// static
template< class A_type >
Automatic< osie::Mutex > &BaseForBothConstantAndNonconstant< A_type >::takeStaticMutex() throw() {
	if ( static_baseForBothConstantAndNonconstant_Mutex.get() == nullptr ) {
		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();

		if ( static_baseForBothConstantAndNonconstant_Mutex.get() == nullptr ) {
			static_baseForBothConstantAndNonconstant_Mutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
		}

		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
	}

	return static_baseForBothConstantAndNonconstant_Mutex;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class Indirector_type >
Automatic< osie::Mutex > BaseForBothConstantAndNonconstant< Indirector_type >::static_baseForBothConstantAndNonconstant_Mutex;

// static
template< class Indirector_type >
const char_type *const BaseForBothConstantAndNonconstant< Indirector_type >::BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE = "BaseForBothConstantAndNonconstant< A_type > - Wrong type detected";

// static
template< class Indirector_type >
const char_type *const BaseForBothConstantAndNonconstant< Indirector_type >::BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED = "BaseForBothConstantAndNonconstant< A_type > - Initialization order is violated";


} // namespace
}
