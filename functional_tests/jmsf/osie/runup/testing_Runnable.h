#pragma once

#include "jmsf/osie/runup/mixins/mixin_Runnable.h"
#include "jmsf/Pointer.hxx"


namespace jmsf {
namespace osie {
namespace runup {


class testing_Runnable : public mixins::mixin_Runnable {

public:
	void run() throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend class ::jmsf::Pointer< testing_Runnable >;
	~testing_Runnable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::Pointer< testing_Runnable > create() throw();

private:
	testing_Runnable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Pointer< testing_Runnable > createClone() const throw();

private:
	testing_Runnable( const testing_Runnable &other ) throw();
	const testing_Runnable &operator =( const testing_Runnable &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
