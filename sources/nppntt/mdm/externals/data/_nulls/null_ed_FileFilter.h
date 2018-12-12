#pragma once

#include "../ed_FileFilter.h"

#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/mtf/mtf_Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace nulls {


class null_ed_FileFilter :
	public ed_FileFilter,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::mtf::mtf_Singleton< null_ed_FileFilter >
{

public:
	// virtuals ed_FileFilter
	void renew( const ::jmsf::ConstantProxy< ed_FileFilter > &fileFilter ) throw( ::jmsf::Exception );
	::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception );
	::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw( ::jmsf::Exception );
	::jmsf::Boolean isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::mtf::mtf_Singleton< null_ed_FileFilter >;
	static null_ed_FileFilter *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_FileFilter > createClone() const throw();

private:
	null_ed_FileFilter( const null_ed_FileFilter &other ) throw();
	const null_ed_FileFilter &operator =( const null_ed_FileFilter &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
