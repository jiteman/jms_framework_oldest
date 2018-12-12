#pragma once


#include "ListAgent.hxx"

#include "jmsf/pointing/Reference.hxx"
#include "jmsf/structing/noding/DoublyLinkedNode.hxx"
#include "jmsf/typing/Asd.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class ListAgent
{

private: friend traversing::ListTraverser< A_type >
	virtual pointing::Reference< noding::DoublyLinkedNode< A_type > > &takeBegin() throw() = 0;
	virtual pointing::Reference< noding::DoublyLinkedNode< A_type > > &takeEnd() throw() = 0;
	virtual typing::Asd &takeQuantity() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	virtual ~ListAgent() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};




} // namespace containing
} // namespace structing
} // namespace jmsf
