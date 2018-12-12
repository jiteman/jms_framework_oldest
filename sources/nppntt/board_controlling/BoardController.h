#pragma once


#include "PrefixToRegisterConveyor.h"

#include "jmsf/UniquePointer.hpp"


namespace nppntt {	
namespace board_controlling {


class BoardController {

public:
	void appendPrefix( ::jmsf::UniquePointer< data_Prefix > prefix ) throw();
	::jmsf::UniquePointer< data_Register > getRegister() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::UniquePointer< BoardController >;
	~BoardController() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::UniquePointer< BoardController > create() throw();

private:
	BoardController() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::UniquePointer< BoardController > createClone() const throw();

private:
	BoardController( const BoardController &other ) throw();
	const BoardController &operator =( const BoardController &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Unique< PrefixToRegisterConveyor > _prefixToRegisterConveyor;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
