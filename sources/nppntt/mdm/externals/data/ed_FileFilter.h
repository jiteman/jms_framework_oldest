#pragma once

#include "jmsf/mtf/Lockable.h"
#include "jmsf/Object.h"

#include "ed_VoiceFile.hxx"
#include "ed_ServiceFile.hxx"
#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class ed_FileFilter :
	public virtual ::jmsf::mtf::Lockable,
	public virtual ::jmsf::Object
{

public:
	virtual void renew( const ::jmsf::ConstantProxy< ed_FileFilter > &fileFilter ) throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::Boolean isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw( ::jmsf::Exception ) = 0;
	virtual const ::jmsf::Boolean isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception ) = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ed_FileFilter *getNull() throw();
	static ed_FileFilter *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ed_FileFilter > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
