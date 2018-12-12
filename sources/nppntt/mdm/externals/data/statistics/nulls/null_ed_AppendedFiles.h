#pragma once

#include "../ed_AppendedFiles.h"

#include "jmsf/mtf/mixin_nulls/mixin_null_Synchronizable.h"

#include "jmsf/mixin_nulls/mixin_null_Object.h"

#include "jmsf/Singleton.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace statistics {
namespace nulls {


class null_ed_AppendedFiles :
	public ed_AppendedFiles,
	public ::jmsf::mtf::mixin_nulls::mixin_null_Synchronizable,
	public ::jmsf::mixin_nulls::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_AppendedFiles >
{

public:
	// virtuals ed_AppendedFiles
	::jmsf::Pointer< FileAppenderStatisticsData > getOneselfData() throw( ::jmsf::Exception );
	const ::jmsf::ConstantPointer< FileAppenderStatisticsData > getData() const throw( ::jmsf::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_AppendedFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< null_ed_AppendedFiles >;
	static null_ed_AppendedFiles *createInstance() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_AppendedFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_AppendedFiles > createClone() const throw();

private:
	null_ed_AppendedFiles( const null_ed_AppendedFiles &other ) throw();
	const null_ed_AppendedFiles &operator =( const null_ed_AppendedFiles &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< FileAppenderStatisticsData > _appendedFilesData;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
}
}
}
