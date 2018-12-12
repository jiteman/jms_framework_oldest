#include "MuleAnalyzer.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace debugging {
namespace mulan {

class null_MuleAnalyzer :
	public MuleAnalyzer,
	public mixins::mixin_null_Object,
	public Singleton< null_MuleAnalyzer >
{

public:
	// virtuals MuleAnalyzer
	Boolean readCollectedData() throw() { return False; }
	void performAnalysis() throw() {}
	void showResults() const throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_MuleAnalyzer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< null_MuleAnalyzer >;
	static null_MuleAnalyzer *createInstance() throw() {
		null_MuleAnalyzer *nullMuleAnalyzer = new null_MuleAnalyzer;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullMuleAnalyzer, MACROS_FILE_AND_LINE ) );
		return nullMuleAnalyzer;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_MuleAnalyzer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MuleAnalyzer > createClone() const throw() {
		return Proxy< MuleAnalyzer >::createUnique( this );
	}

private:
	null_MuleAnalyzer( const null_MuleAnalyzer & ) throw() {} // other
	
	const null_MuleAnalyzer &operator =( const null_MuleAnalyzer &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "null_MuleAnalyzer::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_MuleAnalyzer :
	public MuleAnalyzer,
	public mixins::mixin_exception_Object,
	public Singleton< exception_MuleAnalyzer > {

public:
	// virtuals MuleAnalyzer
	Boolean readCollectedData() throw() { return False; }
	void performAnalysis() throw() {}
	void showResults() const throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_MuleAnalyzer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< exception_MuleAnalyzer >;
	static exception_MuleAnalyzer *createInstance() throw() {
		exception_MuleAnalyzer *exceptionMuleAnalyzer = new exception_MuleAnalyzer;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( exceptionMuleAnalyzer, MACROS_FILE_AND_LINE ) );
		return exceptionMuleAnalyzer;
	}

private:
	exception_MuleAnalyzer() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MuleAnalyzer > createClone() const throw() {
		return Proxy< MuleAnalyzer >::createUnique( this );
	}

private:
	exception_MuleAnalyzer( const exception_MuleAnalyzer & ) throw() {} // other

	const exception_MuleAnalyzer &operator =( const exception_MuleAnalyzer &other ) throw( Exception ) {
		if ( this == &other ) return *this;

		// copy
		Should::neverViolateCopyingProhibition( "exception_MuleAnalyzer::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
MuleAnalyzer *MuleAnalyzer::getNull() throw() {
	return null_MuleAnalyzer::instance();
}

// static
MuleAnalyzer *MuleAnalyzer::getException() throw() {
	return exception_MuleAnalyzer::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mulan
} // namespace debugging
} // namespace jmsf