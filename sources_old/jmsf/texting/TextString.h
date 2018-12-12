#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/pointing/ConstantProxy.hxx"
#include "jmsf/typing/Boolean.hxx"

#include "jmsf/pointing/Reference.hxx"
#include "jmsf/memorying/ObjectMemoryPointer.hxx"

#include "jmsf/typing/internals/internal_types.h"
#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_DLL_INTERFACE TextString :
	public virtual patterning::Object
{

public:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const typing::internals::platform_char *getCtext() const throw() = 0;
	virtual typing::Boolean isEqual( const pointing::ConstantProxy< TextString > &other ) const throw() = 0;	

public:
	static const pointing::Reference< TextString > &getNull() throw( validating::Exception );
	static void createNull( memorying::Allocator &anAllocator ) throw( validating::Exception );
	static void destroyNull() throw( validating::Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const pointing::ConstantProxy< TextString > TextString::createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace texting
} // namespace jmsf
