#pragma once


#include "flyweight_factory_Functor.hxx"

#include "jmsf/patterning/Singleton.inl"

#include "Functor.hxx"
#include "ConstantFunctor.hxx"


namespace jmsf {
namespace assisting {


template< class A_type >
class flyweight_factory_Functor :
	public patterning::Singleton< flyweight_factory_Functor< A_type > >
{

public:
	virtual pointing::Proxy< Functor< A_type > > createFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() ) throw() = 0;
	virtual const pointing::ConstantProxy< ConstantFunctor< A_type > > createConstantFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() const ) throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< flyweight_factory_Functor >;
	static flyweight_factory_Functor *createInstance() throw();

protected:
	flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	flyweight_factory_Functor( const flyweight_factory_Functor &other ) throw();
	const flyweight_factory_Functor &operator =( const flyweight_factory_Functor &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
