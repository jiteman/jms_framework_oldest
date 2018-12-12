#pragma once

#include "jmsf/Boolean.h"
#include "jmsf/Proxies.hpp"

#include "jmsf/TextStream.hxx"
#include "jmsf/Pointers.hxx"


namespace jmsf {
namespace mtf {
namespace exceptions {


class RunnableExceptionInformation {

public:
	Boolean wasException() const throw();
	const ConstantProxy< TextString > getExceptionMessageText() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend DeleterForPointer< RunnableExceptionInformation >;
	~RunnableExceptionInformation() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Pointer< RunnableExceptionInformation > create( const ConstantProxy< TextString > &message ) throw();
	static Pointer< RunnableExceptionInformation > create( const Proxy< TextStream > &message ) throw();

private:
	RunnableExceptionInformation() throw();
	RunnableExceptionInformation( const ConstantProxy< TextString > &message ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Pointer< RunnableExceptionInformation > createClone() const throw();

private:
	RunnableExceptionInformation( const RunnableExceptionInformation &other ) throw();
	const RunnableExceptionInformation &operator =( const RunnableExceptionInformation &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	ConstantProxy< TextString > _exceptionMessageText;
	Boolean _wasException;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static const char_type *NO_EXCEPTION_INFORMATION_MESSAGE;
	static const char_type *UNKNOWN_EXCEPTION_INFORMATION_MESSAGE;

};


} // namespace
}
}
