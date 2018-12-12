#pragma once


#include "jmsf/BaseTemplates.hpp"

#include "jmsf/Exception.hxx"
#include "jmsf/types/Boolean.hxx"
#include "jmsf/types/Natural.hxx"
#include "jmsf/types/ShortestNatural.hxx"

#include "jmsf/Automatic.hxx"
#include "jmsf/osie/Mutex.hxx"

#include "ReferenceCounters.hxx"

#include "jmsf/types/internals/internal_types.h"


namespace jmsf {
namespace base_pointing {


template< class Indirector_type >
class BaseForBothConstantAndNonconstant :
	public IndirectorBase< typename Indirector_type::type_indirected >
{

public:
	types::Boolean isEmpty() const throw( Exception );
	types::Boolean isNotEmpty() const throw( Exception );

	types::Natural getConnectivity() const throw( Exception );

	typename Indirector_type::type_indirected *get() throw( Exception );
	const typename Indirector_type::type_indirected *get() const throw( Exception );
	typename Indirector_type::type_indirected *release() throw( Exception );
	const typename Indirector_type::type_indirected *release() const throw( Exception );
	void empty() throw( Exception );
	void empty() const throw( Exception );

protected:
	void setFrom( const BaseForBothConstantAndNonconstant &other ) throw( Exception );
	void setFrom( const BaseForBothConstantAndNonconstant &other ) const throw( Exception );

protected:
	BaseForBothConstantAndNonconstant createSharedFromThis() const throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	types::Boolean operator ==( const BaseForBothConstantAndNonconstant &other ) const throw( Exception );
	types::Boolean operator !=( const BaseForBothConstantAndNonconstant &other ) const throw( Exception );

	typename Indirector_type::type_indirected &operator *() throw( Exception );
	const typename Indirector_type::type_indirected &operator *() const throw( Exception );
	typename Indirector_type::type_indirected *operator ->() throw( Exception );
	const typename Indirector_type::type_indirected *operator ->() const throw( Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~BaseForBothConstantAndNonconstant() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	BaseForBothConstantAndNonconstant() throw( Exception );
	BaseForBothConstantAndNonconstant( types::ShortestNatural type, const typename Indirector_type::type_indirected *pointerToObject ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	BaseForBothConstantAndNonconstant( const BaseForBothConstantAndNonconstant &other ) throw( Exception );

public:
	const BaseForBothConstantAndNonconstant &operator =( const BaseForBothConstantAndNonconstant &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	void validate() const throw( Exception );
	static Automatic< osie::Mutex > &takeStaticMutex() throw();

private:
	typename Indirector_type::type_indirected *_pointerToObject;
	ReferenceCounters *_referenceCounters;
	types::ShortestNatural _type;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	static const types::ShortestNatural type_None;
	static const types::ShortestNatural type_Empty;
	static const types::ShortestNatural type_Nonlinked;
	static const types::ShortestNatural type_Weak;
	static const types::ShortestNatural type_Unique;
	static const types::ShortestNatural type_Shared;
	

private:
	static Automatic< osie::Mutex > static_baseForBothConstantAndNonconstant_Mutex;

private:
	static const types::internals::platform_char *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_WRONG_TYPE;
	static const types::internals::platform_char *const BASE_FOR_BOTH_CONSTANT_AND_NONCONSTANT_INITIALIZATION_ORDER_IS_VIOLATED;

};

} // namespace
}
