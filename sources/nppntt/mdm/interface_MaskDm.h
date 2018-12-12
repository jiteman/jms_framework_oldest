#pragma once

#include "jmsf/Proxies.hpp"
#include "jmsf/stdal/stdal_stl.h"

#include "externals/others/DataTypes.hxx"
#include "MaskDm.hxx"

#include "mdm.h"

namespace nppntt {
namespace mdm {


class NPPNTT_MDM_DLL_INTERFACE interface_MaskDm {

public:
	bool wasInitializedCorrectly() const throw();
    int startSystem() throw();
    int stopSystem() throw();

    int changeFilter( const FilterData *filter ) throw();
    int setDecipherTime( const _decipherTimeLimit *time ) throw();
    int getStatistics( GlobalStatisticsData *globalStatistics ) throw();
	int setFileAppenderFolders( const std::list< const std::string > &folderNameList ) throw();

	int clearExpiredServiceFiles() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~interface_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	interface_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	interface_MaskDm( const interface_MaskDm &other ) throw();
	const interface_MaskDm &operator =( const interface_MaskDm &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Proxy< MaskDm > _implementation;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
