#pragma once


#include "jmsf/patterning/Object.h"

#include "TextString.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/pointing/Reference.hxx"

#include "jmsf/typing/Integer.hxx"
#include "jmsf/typing/LongInteger.hxx"
#include "jmsf/typing/Natural.hxx"
#include "jmsf/typing/LongNatural.hxx"
#include "jmsf/typing/ShortReal.hxx"
#include "jmsf/typing/Real.hxx"
#include "jmsf/memorying/Allocator.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_DLL_INTERFACE TextStream :
	public virtual patterning::Object
{

public:
	virtual pointing::Proxy< TextStream > put( const pointing::ConstantProxy< TextString > &textString ) throw() = 0;
	virtual pointing::Proxy< TextStream > putInteger( typing::Integer value ) throw() = 0;
	virtual pointing::Proxy< TextStream > putInteger( typing::LongInteger value ) throw() = 0;
	virtual pointing::Proxy< TextStream > putNatural( typing::Natural value ) throw() = 0;
	virtual pointing::Proxy< TextStream > putNatural( typing::LongNatural value ) throw() = 0;
	virtual pointing::Proxy< TextStream > putReal( const typing::ShortReal &value ) throw() = 0;
	virtual pointing::Proxy< TextStream > putReal( const typing::Real &value ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual const pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator ) const throw() = 0;
	virtual pointing::Proxy< TextStream > setDecimalBase() throw() = 0;
	virtual pointing::Proxy< TextStream > setHexadecimalBase() throw() = 0;
	virtual pointing::Proxy< TextStream > setWidth( typing::Natural width ) throw() = 0;
	virtual pointing::Proxy< TextStream > setFill( const pointing::ConstantProxy< TextString > &fill ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static const pointing::Reference< TextStream > &getNull() throw( validating::Exception );
	static void createNull( memorying::Allocator &anAllocator ) throw( validating::Exception );
	static void destroyNull() throw( validating::Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual pointing::Proxy< TextStream > TextStream::createClone( memorying::Allocator &anAllocator ) const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf
