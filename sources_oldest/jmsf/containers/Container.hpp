#pragma once

#include "jmsf/Object.h"
#include "jmsf/BaseTemplates.hpp"
#include "jmsf/Iterators.hxx"
#include "jmsf/Proxies.hxx"


namespace jmsf {
namespace containers {

template< class A_type >
class Container :
	public virtual Object,
	public ContainerBase< A_type >
{

public: // getters
	virtual const Boolean isEmpty() const throw() = 0;
	virtual const Boolean isNotEmpty() const throw() = 0;
	virtual natural_size getQuantityOfElements() const throw() = 0;

	virtual const A_type &getContainieAtBegin() const throw( Exception ) = 0;
	virtual A_type &takeContainieAtBegin() throw( Exception ) = 0;
	virtual const A_type &getContainieAtEnd() const throw( Exception ) = 0;
	virtual A_type &takeContainieAtEnd() throw( Exception ) = 0;
	virtual const A_type &getContainieAt( natural_size index ) const throw( Exception ) = 0;
	virtual A_type &takeContainieAt( natural_size index ) throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	virtual void appendToBegin( const A_type &object ) throw() = 0;
	virtual void appendToEnd( const A_type &object ) throw() = 0;
	virtual void insertAfter( natural_size index, const A_type &object ) throw( Exception ) = 0;
	virtual Proxy< Iterator< A_type > > insertAfter( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception ) = 0;
	virtual void insertBefore( natural_size index, const A_type &object ) throw() = 0;
	virtual Proxy< Iterator< A_type > > insertBefore( const Proxy< Iterator< A_type > > &anIterator, const A_type &object ) throw( Exception ) = 0;
		
	virtual A_type withdrawContainieAtBegin() throw( Exception ) = 0;
	virtual A_type withdrawLastContainieAtEnd() throw( Exception ) = 0;
	virtual A_type withdrawContainieAt( natural_size index ) throw( Exception ) = 0;

	virtual void eraseContainieAtBegin() throw( Exception ) = 0;
	virtual void eraseContainieAtEnd() throw( Exception ) = 0;
	virtual void eraseContainieAt( natural_size index ) = 0;

	virtual void clear() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	virtual Proxy< Iterator< A_type > > createIteratorAtBegin() throw() = 0;
	virtual Proxy< Iterator< A_type > > createIteratorAtEnd() throw() = 0;
	virtual Proxy< Iterator< A_type > > createIteratorAt( natural_size index ) throw( Exception ) = 0;

	virtual Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() = 0;
	virtual Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() = 0;
	virtual Proxy< ConstantIterator< A_type > > createConstantIteratorAt( natural_size index ) throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	virtual Proxy< Iterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception ) = 0;
	virtual Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception ) = 0;
	virtual Proxy< Iterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< Iterator< A_type > > &anIterator ) const throw( Exception ) = 0;
	virtual Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< ConstantIterator< A_type > > &anIterator ) const throw( Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static Container *getNull() throw();
	static Container *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	virtual Proxy< Container< A_type > > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containers
} // namespace jmsf


#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Iterators.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace containers {


template< class A_type >
class null_Container :
	public Container< A_type >,
	public mixins::mixin_null_Object,
	public Singleton< null_Container< A_type > >
{

public: // getters
	// virtuals Container< A_type >
	const Boolean isEmpty() const throw() { return True; }
	const Boolean isNotEmpty() const throw() { return False; }
	natural_size getQuantityOfElements() const throw() { return 0; }

	const A_type &getContainieAtBegin() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAtBegin() throw( Exception ) { return _referenceToReturn; }
	const A_type &getContainieAtEnd() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAtEnd() throw( Exception ) { return _referenceToReturn; }
	const A_type &getContainieAt( natural_size index ) const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAt( natural_size index ) throw( Exception ) { return _referenceToReturn; }
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Container< A_type >
	void appendToBegin( const A_type & ) throw() {} // object
	void appendToEnd( const A_type & ) throw() {} // object
	void insertAfter( natural_size , const A_type & ) throw( Exception ) {} // index, object
	Proxy< Iterator< A_type > > insertAfter( const Proxy< Iterator< A_type > > &, const A_type & ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator, object
	void insertBefore( natural_size , const A_type & ) throw() {} // index, object
	Proxy< Iterator< A_type > > insertBefore( const Proxy< Iterator< A_type > > &, const A_type & ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator, object
	
	A_type withdrawContainieAtBegin() throw( Exception ) { return A_type(); }
	A_type withdrawLastContainieAtEnd() throw( Exception ) { return A_type(); }
	A_type withdrawContainieAt( natural_size index ) throw( Exception ) { return A_type(); }

	void eraseContainieAtBegin() throw( Exception ) {}
	void eraseContainieAtEnd() throw( Exception ) {}
	void eraseContainieAt( natural_size  ) {} // index

	void clear() throw() {}
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container< A_type >
	Proxy< Iterator< A_type > > createIteratorAtBegin() throw() { return Proxy< Iterator< A_type > >(); }
	Proxy< Iterator< A_type > > createIteratorAtEnd() throw() { return Proxy< Iterator< A_type > >(); }
	Proxy< Iterator< A_type > > createIteratorAt( natural_size  ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // index

	Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() { return Proxy< ConstantIterator< A_type > >(); }
	Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() { return Proxy< ConstantIterator< A_type > >(); }
	Proxy< ConstantIterator< A_type > > createConstantIteratorAt( natural_size  ) throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // index
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Container< A_type >
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< Iterator< A_type > > & ) const throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< ConstantIterator< A_type > > & ) const throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // anIterator
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< Iterator< A_type > > & ) const throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< ConstantIterator< A_type > > & ) const throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // anIterator
	//~virtuals Container< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual Container< A_type >
	~null_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_Container >;
	static null_Container *createInstance() throw() {
		null_Container *nullContainer = new null_Container;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullContainer, MACROS_FILE_AND_LINE ) );
		return nullContainer;
	}

private:
	null_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual Container< A_type >
	Proxy< Container< A_type > > createClone() const throw() {
		return Proxy< Container< A_type > >::createUnique( this );
	}

private:
	null_Container( const null_Container & ) throw() {} // other

	const null_Container &operator =( const null_Container &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_Container::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_type >
class exception_Container :
	public Container< A_type >,
	public mixins::mixin_exception_Object,
	public Singleton< exception_Container< A_type > >
{

public: // getters
	// virtuals Container< A_type >
	const Boolean isEmpty() const throw() { return True; }
	const Boolean isNotEmpty() const throw() { return False; }
	natural_size getQuantityOfElements() const throw() { return 0; }

	const A_type &getContainieAtBegin() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAtBegin() throw( Exception ) { return _referenceToReturn; }
	const A_type &getContainieAtEnd() const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAtEnd() throw( Exception ) { return _referenceToReturn; }
	const A_type &getContainieAt( natural_size index ) const throw( Exception ) { return _referenceToReturn; }
	A_type &takeContainieAt( natural_size index ) throw( Exception ) { return _referenceToReturn; }
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // modifiers
	// virtuals Container< A_type >
	void appendToBegin( const A_type & ) throw() {} // object
	void appendToEnd( const A_type & ) throw() {} // object
	void insertAfter( natural_size , const A_type & ) throw( Exception ) {} // index, object
	Proxy< Iterator< A_type > > insertAfter( const Proxy< Iterator< A_type > > &, const A_type & ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator, object
	void insertBefore( natural_size , const A_type & ) throw() {} // index, object
	Proxy< Iterator< A_type > > insertBefore( const Proxy< Iterator< A_type > > &, const A_type & ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator, object
	
	A_type withdrawContainieAtBegin() throw( Exception ) { return A_type(); }
	A_type withdrawLastContainieAtEnd() throw( Exception ) { return A_type(); }
	A_type withdrawContainieAt( natural_size index ) throw( Exception ) { return A_type(); }

	void eraseContainieAtBegin() throw( Exception ) {}
	void eraseContainieAtEnd() throw( Exception ) {}
	void eraseContainieAt( natural_size  ) {} // index

	void clear() throw() {}
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container< A_type >
	Proxy< Iterator< A_type > > createIteratorAtBegin() throw() { return Proxy< Iterator< A_type > >(); }
	Proxy< Iterator< A_type > > createIteratorAtEnd() throw() { return Proxy< Iterator< A_type > >(); }
	Proxy< Iterator< A_type > > createIteratorAt( natural_size  ) throw( Exception ) { return Proxy< Iterator< A_type > >(); } // index

	Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw() { return Proxy< ConstantIterator< A_type > >(); }
	Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw() { return Proxy< ConstantIterator< A_type > >(); }
	Proxy< ConstantIterator< A_type > > createConstantIteratorAt( natural_size  ) throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // index
	//~virtuals Container< A_type >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // service
	// virtuals Container< A_type >
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< Iterator< A_type > > & ) const throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToBegin( const Proxy< ConstantIterator< A_type > > & ) const throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // anIterator
	Proxy< Iterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< Iterator< A_type > > & ) const throw( Exception ) { return Proxy< Iterator< A_type > >(); } // anIterator
	Proxy< ConstantIterator< A_type > > createIteratorOneStepMovedToEnd( const Proxy< ConstantIterator< A_type > > & ) const throw( Exception ) { return Proxy< ConstantIterator< A_type > >(); } // anIterator
	//~virtuals Container< A_type >

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual Container< A_type >
	~exception_Container() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_Container >;
	static exception_Container *createInstance() throw() {
		return
			debugging::static_ObjectCreationLogger< exception_Container< A_type > >::registerCreation(
				new exception_Container< A_type >, sizeof( exception_Container< A_type > ), MACROS_FILE_AND_LINE );
	}

private:
	exception_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual Container< A_type >
	Proxy< Container< A_type > > createClone() const throw() {
		return Proxy< Container< A_type > >::createUnique( this );
	}

private:
	exception_Container( const exception_Container & ) throw() {} // other

	const exception_Container &operator =( const exception_Container &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_Container::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _referenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
Container< A_type > *Container< A_type >::getNull() throw() {
	return null_Container< A_type >::instance();
}

// static
template< class A_type >
Container< A_type > *Container< A_type >::getException() throw() {
	return exception_Container< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace containers
} // namespace jmsf
