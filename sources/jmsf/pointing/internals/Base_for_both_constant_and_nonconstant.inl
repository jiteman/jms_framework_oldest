#pragma once


#include "Base_for_both_constant_and_nonconstant.hpp"


#include "jmsf/validating/Exception.h"
#include "Reference_counters.h"

#include "jmsf/typing/Naturals.inl"
#include "jmsf/typing/Boolean.h"

#include "jmsf/validating/File_and_line.h"

#include "jmsf/memorying/Destructor.inl"


namespace jmsf {
namespace pointing {
namespace internals {


// statics
template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_None = typing::Shortest_natural::create( 128 );

template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_Empty = typing::Shortest_natural::create( 64 );

template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_Nonlinked = typing::Shortest_natural::create( 32 );

template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_Weak = typing::Shortest_natural::create( 16 );

template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_Unique = typing::Shortest_natural::create( 8 );

template< class A_type >
const typing::Shortest_natural Base_for_both_constant_and_nonconstant< A_type >::type_Shared = typing::Shortest_natural::create( 4 );
//~statics


template< class A_type >
typing::Boolean Base_for_both_constant_and_nonconstant< A_type >::is_empty() const {
	validate();
	return typing::Boolean::create( _object_memory_pointer.get_memory().get_address() == typename A_type::the_deleter::get_null_object_via_deleter().get_memory().get_address() );
}

template< class A_type >
typing::Boolean Base_for_both_constant_and_nonconstant< A_type >::is_not_empty() const {
	return is_empty().not();
}

template< class A_type >
typing::Memory_size Base_for_both_constant_and_nonconstant< A_type >::get_connectivity() const {
	validate();

	switch ( _type ) {
		case type_None:
		case type_Empty:
		case type_Nonlinked:
			return typing::Memory_size_nill;

		case type_Unique:
			return typing::Memory_size_one;

		case type_Weak:
		case type_Shared:
			return _reference_counters->get_connectivity();

		default:
			Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );
			return typing::Memory_size_badmax;
	}
}

template< class A_type >
memorying::Omp< typename A_type::the_type > &Base_for_both_constant_and_nonconstant< A_type >::get() {
	validate();
	return _object_memory_pointer;
}

template< class A_type >
const memorying::Omp< typename A_type::the_type > &Base_for_both_constant_and_nonconstant< A_type >::get() const {
	validate();
	return _object_memory_pointer;
}

template< class A_type >
memorying::Omp< typename A_type::the_type > Base_for_both_constant_and_nonconstant< A_type >::release() {
	validate();
	memorying::Omp< typename A_type::the_type > pointerToObject;

	if ( _type == type_None ) {
	} else if ( _type == type_Empty ) {
		pointerToObject = _object_memory_pointer; // NullObject
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
	} else if ( _type == type_Nonlinked ) {
		pointerToObject = _object_memory_pointer;
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		_type = type_Empty;
	} else if ( _type == type_Unique ) {
		pointerToObject = _object_memory_pointer;
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		_type = type_Empty;
	} else if ( _type == type_Weak ) {
		_reference_counters->decrease_weak();

		if ( _reference_counters->is_strong_nill() ) {
			if ( _reference_counters->is_weak_nill() ) {
				memorying::Destructor< Reference_counters >::destruct( _reference_counters );
			}
		}
			
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		_reference_counters = memorying::Omp< Reference_counters >();
		_type = type_Empty;
	} else if ( _type == type_Shared ) {
		_reference_counters->decrease_strong();

		if ( _reference_counters->is_strong_nill() ) {
			if ( _reference_counters->is_weak_nill() ) {
				memorying::Destructor< Reference_counters >::destruct( _reference_counters );
////				delete _reference_counters;
			}

			pointerToObject = _object_memory_pointer;
		}
			
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		_reference_counters = memorying::Omp< Reference_counters >();
		_type = type_Empty;
	} else {
		validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE, FILE_AND_LINE );
	}

	validate();
	return pointerToObject;
}

template< class A_type >
const memorying::Omp< typename A_type::the_type > Base_for_both_constant_and_nonconstant< A_type >::release() const {
	return const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->release();
}

template< class A_type >
void Base_for_both_constant_and_nonconstant< A_type >::empty() {
	const typing::Shortest_natural previousType = _type;
	const memorying::Omp< typename A_type::the_type > pointerToObject = release();

	if ( previousType == type_None || previousType == type_Empty || previousType == type_Nonlinked || previousType == type_Weak ) return;
	
	if ( previousType == type_Unique || previousType == type_Shared ) {
		typename A_type::the_deleter::delete_object( pointerToObject );
	} else {
		validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE, FILE_AND_LINE );
	}
}

template< class A_type >
void Base_for_both_constant_and_nonconstant< A_type >::empty() const {
	const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->empty();
}

template< class A_type >
void Base_for_both_constant_and_nonconstant< A_type >::set_from( const Base_for_both_constant_and_nonconstant< A_type > &other ) {
	validate();
	other.validate();

	const typing::Shortest_natural previousType = _type;
	_type = other._type;

	if ( other._type == type_None ) {
		if ( previousType == type_Empty || previousType == type_Weak || previousType == type_Unique || previousType == type_Shared ) {
			validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED, FILE_AND_LINE );
		}
			
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >();
		_reference_counters = memorying::Omp< Reference_counters >();
	} else if ( other._type == type_Empty ) {
		_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		_reference_counters = memorying::Omp< Reference_counters >();
	} else if ( other._type == type_Nonlinked ) {
		_object_memory_pointer = other._object_memory_pointer;
		_reference_counters = memorying::Omp< Reference_counters >();
	} else if ( other._type == type_Unique ) {
		_object_memory_pointer = other._object_memory_pointer;
		const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
		const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._type = type_Empty;
		_reference_counters = memorying::Omp< Reference_counters >();
	} else if ( other._type == type_Weak ) {
		if ( other._reference_counters.is_not_empty() ) {
			if ( other._reference_counters->is_strong_nill() ) {
				const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._reference_counters->decrease_weak();

				if ( other._reference_counters->is_weak_nill() ) {
					memorying::Destructor< Reference_counters >::destruct( other._reference_counters );
					const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._reference_counters = memorying::Omp< Reference_counters >();
					const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
					const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( other )._type = type_Empty;
				}

				_reference_counters = memorying::Omp< Reference_counters >();
				_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
				_type = type_Empty;
			} else {
				_reference_counters = other._reference_counters;
				_reference_counters->increase_weak();
				_object_memory_pointer = other._object_memory_pointer;
			}
		}
	} else if ( other._type == type_Shared ) {
		if ( other._reference_counters.is_not_empty() ) {
			_reference_counters = other._reference_counters;
			_reference_counters->increase_strong();
			_object_memory_pointer = other._object_memory_pointer;
		} else {
			validating::Should::never_be( other._reference_counters.is_empty(), FILE_AND_LINE );
		}
	} else {
		validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE, FILE_AND_LINE );
	}

	validate();
	other.validate();
}

template< class A_type >
void Base_for_both_constant_and_nonconstant< A_type >::set_from( const Base_for_both_constant_and_nonconstant< A_type > &other ) const {
	const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->setFrom( other );
}

template< class A_type >
Base_for_both_constant_and_nonconstant< A_type > Base_for_both_constant_and_nonconstant< A_type >::create_shared_from_this( const memorying::Womp< memorying::Allocator > &reference_counters_allocator ) const {
	validate();

	Base_for_both_constant_and_nonconstant< A_type > candidate_for_shared;

	switch ( _type ) {
		case type_None:
		case type_Empty:
		case type_Nonlinked:
			break;

		case type_Weak:
			candidate_for_shared = *this;

			if ( !_reference_counters->is_strong_nill() ) {
				_reference_counters->decrease_weak();
				_reference_counters->increase_strong();
				candidate_for_shared._type = type_Shared;
			}

			break;

		case type_Unique:
			{
				validating::Should::never_be( reference_counters_allocator.is_empty(), FILE_AND_LINE );					
				Base_for_both_constant_and_nonconstant< A_type > &nonconstant_this = const_cast< Base_for_both_constant_and_nonconstant< A_type > & >( *this );
				nonconstant_this._type = type_Shared;
				nonconstant_this._reference_counters = memorying::Constructor< Reference_counters >::construct( reference_counters_allocator );
			}

			candidate_for_shared = *this;
			break;

		case type_Shared:
			candidate_for_shared = *this;
			break;

		default:
			Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE );			
	}

	validate();
	return candidate_for_shared;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typing::Boolean Base_for_both_constant_and_nonconstant< A_type >::operator ==( const Base_for_both_constant_and_nonconstant &other ) const {
	validate();
	other.validate();
	return typing::Boolean::create( _object_memory_pointer == other._object_memory_pointer );
}

template< class A_type >
typing::Boolean Base_for_both_constant_and_nonconstant< A_type >::operator !=( const Base_for_both_constant_and_nonconstant &other ) const {
	return operator ==( other ).not();
}

template< class A_type >
typename A_type::the_type &Base_for_both_constant_and_nonconstant< A_type >::operator *() {
	validate();
	validating::Should::never_be( _object_memory_pointer.is_empty(), FILE_AND_LINE );
	return *_object_memory_pointer;
}

template< class A_type >
const typename A_type::the_type &Base_for_both_constant_and_nonconstant< A_type >::operator *() const {
	validate();
	validating::Should::never_be( _object_memory_pointer.is_empty(), FILE_AND_LINE );
	return *_object_memory_pointer;
}

template< class A_type >
typename A_type::the_type *Base_for_both_constant_and_nonconstant< A_type >::operator ->() {
	validate();
	validating::Should::never_be( _object_memory_pointer.is_empty(), FILE_AND_LINE );
	return _object_memory_pointer.take();
}

template< class A_type >
const typename A_type::the_type *Base_for_both_constant_and_nonconstant< A_type >::operator ->() const {
	validate();
	validating::Should::never_be( _object_memory_pointer.is_empty(), FILE_AND_LINE );
	return _object_memory_pointer.get();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
Base_for_both_constant_and_nonconstant< A_type >::~Base_for_both_constant_and_nonconstant() noexept {
	try {
		empty();
	} catch ( const validating::Exception & ) { // catchedException
		// add an exception information message box
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Base_for_both_constant_and_nonconstant< A_type >::Base_for_both_constant_and_nonconstant() {
	_type = type_Empty;
	_object_memory_pointer = typename A_type::the_type::get_null_object();
	_reference_counters = nullptr;
	validate();
}


template< class A_type >
Base_for_both_constant_and_nonconstant< A_type >::Base_for_both_constant_and_nonconstant( const typing::Shortest_natural type, const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		_object_memory_pointer( pointerToObject )
{
	validating::Should::never_be( _type == type_Shared, FILE_AND_LINE );
	_type = type;
	_reference_counters = memorying::Omp< Reference_counters >();

	if ( _type == type_None || _type == type_Empty || _type == type_Weak || _type == type_Nonlinked || _type == type_Unique ) {
		validate();
	} else {
		validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE, FILE_AND_LINE );
	}
}

template< class A_type >
Base_for_both_constant_and_nonconstant< A_type >::Base_for_both_constant_and_nonconstant( 
	const memorying::Womp< memorying::Allocator > &reference_counters_allocator,
	const memorying::Omp< typename A_type::the_type > &pointerToObject )
	:
		_object_memory_pointer( pointerToObject )
{
	_type = type_Shared;
	_reference_counters = memorying::Constructor< Reference_counters >::construct( reference_counters_allocator );
	_reference_counters->increase_strong();
	validate();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Base_for_both_constant_and_nonconstant< A_type >::Base_for_both_constant_and_nonconstant( const Base_for_both_constant_and_nonconstant< A_type > &other ) {
	_type = type_None;
	_object_memory_pointer = memorying::Omp< typename A_type::the_type >();
	_reference_counters = memorying::Omp< Reference_counters >();
	set_from( other );
}

template< class A_type >
const Base_for_both_constant_and_nonconstant< A_type > &Base_for_both_constant_and_nonconstant< A_type >::operator =( const Base_for_both_constant_and_nonconstant< A_type > &other ) {
	if ( _object_memory_pointer.get_memory().get_address() == other._object_memory_pointer.get_memory().get_address() ) return *this;

	empty();
	set_from( other );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
template< class A_type >
void Base_for_both_constant_and_nonconstant< A_type >::validate() const {
	if ( _type == type_None ) {
		validating::Should::always_be( _object_memory_pointer.is_not_empty(), FILE_AND_LINE );
		validating::Should::always_be( _reference_counters.is_not_empty(), FILE_AND_LINE );
	} else if ( _type == type_Empty ) {
		validating::Should::always_be( typing::Boolean::create( _object_memory_pointer.get_memory().get_address() == typename A_type::the_deleter::get_null_object_via_deleter().get_memory().get_address() ), FILE_AND_LINE );
		validating::Should::always_be( _reference_counters.is_not_empty(), FILE_AND_LINE );
	} else if ( _type == type_Nonlinked ) {
		validating::Should::always_be( _reference_counters.is_empty(), FILE_AND_LINE );
		validating::Should::never_be( _object_memory_pointer.is_empty(), FILE_AND_LINE );
	} else if ( _type == type_Weak ) {
		if ( _reference_counters.is_not_empty() ) {
			if ( _reference_counters->is_strong_nill() ) {
				const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->_reference_counters->decrease_weak();

				if ( _reference_counters->is_weak_nill() ) {
					memorying::Destructor< Reference_counters >::destruct( _reference_counters );
					const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->_reference_counters = memorying::Omp< Reference_counters >();
					const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->_object_memory_pointer = memorying::Omp< typename A_type::the_type >::create_from_weak( typename A_type::the_deleter::get_null_object_via_deleter() );
					const_cast< Base_for_both_constant_and_nonconstant< A_type > * >( this )->_type = type_Empty;
				}
			}				
		}
	} else if ( _type == type_Unique ) {
		validating::Should::always_be( _reference_counters.is_empty(), FILE_AND_LINE );
		validating::Should::never_be( typing::Boolean::create( _object_memory_pointer.get_memory().get_address() == typename A_type::the_deleter::get_null_object_via_deleter().get_memory().get_address() ), FILE_AND_LINE );
	} else if ( _type == type_Shared ) {
		validating::Should::always_be( _reference_counters.is_not_empty(), FILE_AND_LINE );
		validating::Should::never_be( typing::Boolean::create( _object_memory_pointer.get_memory().get_address() == typename A_type::the_deleter::get_null_object_via_deleter().get_memory().get_address() ), FILE_AND_LINE );
	} else {
		validating::Should::_never_reach_here( BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE, FILE_AND_LINE );
	}
}

// static
// template< class A_type >
// Automatic< osie::Mutex > &Base_for_both_constant_and_nonconstant< A_type >::takeStaticMutex() throw() {
// 	if ( static_baseForBothConstantAndNonconstant_Mutex.get() == nullptr ) {
// 		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->lock();
// 
// 		if ( static_baseForBothConstantAndNonconstant_Mutex.get() == nullptr ) {
// 			static_baseForBothConstantAndNonconstant_Mutex = osie::static_factory_OperatingSystemSpecial::createAutomaticMutex();
// 		}
// 
// 		osie::static_factory_OperatingSystemSpecial::takeOperatingSystemMutex()->unlock();
// 	}
// 
// 	return static_baseForBothConstantAndNonconstant_Mutex;
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
// template< class A_type >
// Automatic< osie::Mutex > Base_for_both_constant_and_nonconstant< A_type >::static_baseForBothConstantAndNonconstant_Mutex;

// static
template< class A_type >
const typing::internals::platform_character_type *const Base_for_both_constant_and_nonconstant< A_type >::BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE =
	"Base_for_both_constant_and_nonconstant< A_type > - Wrong type detected";

// static
template< class A_type >
const typing::internals::platform_character_type *const Base_for_both_constant_and_nonconstant< A_type >::BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED =
	"Base_for_both_constant_and_nonconstant< A_type > - Initialization order is violated";


} // namespace internals
} // namespace pointing
} // namespace jmsf
