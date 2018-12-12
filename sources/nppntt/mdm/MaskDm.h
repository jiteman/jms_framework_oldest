#pragma once

#include "jmsf/Object.h"

#include "externals/others/DataTypes.hxx"
#include "externals/data/ed_FileFilter.hxx"
#include "externals/data/statistics/ed_Summary.hxx"
#include "jmsf/Container.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Pointers.hxx"

namespace nppntt {
namespace mdm {

class MaskDm :
	public virtual ::jmsf::Object
{

public:
	virtual ::jmsf::Boolean wasInitializedCorrectly() const throw() = 0;
	virtual void continueDecipchering() throw() = 0;
	virtual void stopDecipchering() throw() = 0;

	virtual void changeFileAppenderFolders( const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > &pathToFolderWithFilesContainer ) throw() = 0;

	virtual void updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw() = 0;
	virtual void setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) throw() = 0;
	virtual const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > &getStatistics() throw() = 0;

	virtual void clearExpiredServiceFiles() throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static MaskDm *getNull() throw();
	static MaskDm *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< MaskDm > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mdm
} // namespace nppntt
