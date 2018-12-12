#pragma once

#include "../ed_FileFilter.h"
#include "jmsf/mtf/mixins/mixin_Lockable.h"
#include "jmsf/mixins/mixin_Object.h"

#include "../../others/DataTypes.hxx"
#include "jmsf/osie/Mutex.hxx"
#include "jmsf/Pointers.hpp"

#include "realization_factory_ExternalData.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {

class realization_ed_FileFilter :
	public ed_FileFilter,
	public ::jmsf::mtf::mixins::mixin_Lockable,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals ed_FileFilter
	void renew( const ::jmsf::ConstantProxy< ed_FileFilter > &fileFilter ) throw( ::jmsf::Exception );
	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception );
	const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw( ::jmsf::Exception );
	const ::jmsf::Boolean isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend ::jmsf::DeleterForPointer< realization_ed_FileFilter >; // for downcasting
	// virtual
	~realization_ed_FileFilter() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ExternalData;
	realization_ed_FileFilter(
		::jmsf::Pointer< FilterData > fileFilterData,
		::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_FileFilter > createClone() const throw();

private:
	realization_ed_FileFilter( const realization_ed_FileFilter &other ) throw( ::jmsf::Exception );
	const realization_ed_FileFilter &operator =( const realization_ed_FileFilter &other ) throw( ::jmsf::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FilterData > _fileFilterData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
