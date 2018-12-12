#include "ed_FileFilter.h"
#include "jmsf/mtf/mixins/mixin_null_Lockable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class null_ed_FileFilter :
	public ed_FileFilter,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_FileFilter >
{

public:
	// virtuals ed_FileFilter
	void renew( const ::jmsf::ConstantProxy< ed_FileFilter > & ) throw( ::jmsf::Exception ) {} // fileFilter

	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw( ::jmsf::Exception ) { // serviceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_FileFilter >;
	static null_ed_FileFilter *createInstance() throw() {
		return new null_ed_FileFilter;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< ed_FileFilter >::createUnique( this );
	}

private:
	null_ed_FileFilter( const null_ed_FileFilter & ) throw() {} // other
	
	const null_ed_FileFilter &operator =( const null_ed_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_FileFilter :
	public ed_FileFilter,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_FileFilter > {

public:
	// virtuals ed_FileFilter
	void renew( const ::jmsf::ConstantProxy< ed_FileFilter > & ) throw( ::jmsf::Exception ) {} // fileFilter

	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw( ::jmsf::Exception ) { // serviceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw( ::jmsf::Exception ) { // voiceFile
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_FileFilter >;
	static exception_ed_FileFilter *createInstance() throw() {
		return new exception_ed_FileFilter;
	}

private:
	exception_ed_FileFilter() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_FileFilter > createClone() const throw() {
		return ::jmsf::Proxy< ed_FileFilter >::createUnique( this );
	}

private:
	exception_ed_FileFilter( const exception_ed_FileFilter & ) throw() {} // other

	const exception_ed_FileFilter &operator =( const exception_ed_FileFilter &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_FileFilter::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_FileFilter *ed_FileFilter::getNull() throw() {
	return null_ed_FileFilter::instance();
}

// static
ed_FileFilter *ed_FileFilter::getException() throw() {
	return exception_ed_FileFilter::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
