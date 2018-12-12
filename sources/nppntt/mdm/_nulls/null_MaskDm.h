#pragma once

#include "../MaskDm.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace nulls {


class null_MaskDm :
	public MaskDm,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_MaskDm >
{

public:
	// virtuals MaskDm
	::jmsf::Boolean wasInitializedCorrectly() const throw();
	void continueDecipchering() throw();
	void stopDecipchering() throw();

	void changeFileAppenderFolders(
		const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy, ::jmsf::TextString > > &pathToFolderWithFilesContainer ) throw();

	void updateFileFilter( const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw();
	void setDecipheringTimeLimit( const ::jmsf::ConstantPointer< _decipherTimeLimit > &timeLimitData ) throw();
	const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > getStatistics() throw();

	void clearExpiredServiceFiles() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_MaskDm >;
	static null_MaskDm *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< MaskDm > createClone() const throw();

private:
	null_MaskDm( const null_MaskDm &other ) throw();
	const null_MaskDm &operator =( const null_MaskDm &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
