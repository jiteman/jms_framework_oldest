#include "null_MaskDm.h"
#include "../externals/data/statistics/ed_Summary.h"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


::jmsf::Boolean null_MaskDm::wasInitializedCorrectly() const throw() {
	return ::jmsf::False;
}

void null_MaskDm::continueDecipchering() throw()
{}

void null_MaskDm::stopDecipchering() throw()
{}

void null_MaskDm::changeFileAppenderFolders(
		const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy, ::jmsf::TextString > > & ) throw() // pathToFolderWithFilesContainer
{}

void null_MaskDm::updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > & ) throw() // filterData
{}

void null_MaskDm::setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > & ) throw() // timeLimitData
{}

const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > null_MaskDm::getStatistics() throw() {
	return ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary >();
}

void null_MaskDm::clearExpiredServiceFiles() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_MaskDm::~null_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_MaskDm *null_MaskDm::createInstance() throw() {
	return new null_MaskDm;
}

null_MaskDm::null_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< MaskDm > null_MaskDm::createClone() const throw() {
	return ::jmsf::Proxy< MaskDm >::createUnique( this );
}

null_MaskDm::null_MaskDm( const null_MaskDm & ) throw() // other
{}

const null_MaskDm &null_MaskDm::operator =( const null_MaskDm &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
