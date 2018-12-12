#pragma once


#include "jmsf/validating/Exception.hxx"
#include "jmsf/typing/Boolean.hxx"
#include "jmsf/memorying/Destructor.hxx"


#include "jmsf/jmsf.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace patterning {


class JMSF_DLL_INTERFACE Object {

public:	
	virtual typing::Boolean is_null() const noexept = 0;
	virtual typing::Boolean is_exception() const noexept = 0;	

	virtual void throw_if_exception() const = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// public:
// 	typing::Boolean isReal() const noexept;
// 	void _deleteThisIfReal() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	friend memorying::Destructor< Object >;
	virtual ~Object() noexept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace patterning
} // namespace jmsf
