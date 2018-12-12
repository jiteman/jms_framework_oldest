#pragma once

#include "DriveTable.h"
//#include "RequestDataFileReader.h"
#include "VirtualFileTable.h"
#include "jmsf/Exception.h"
#include "jmsf/Pointer.hpp"
#include "jmsf/stdal/stdal_stl.h"

namespace nppntt {
namespace ssd_reading {

class Configuration {

	static std::string PATH_TO_CONFIGURATION_FILES;
	static const std::string CONFIGURATION_FILENAME;

	static const std::string ABSOLUTE_VALUE;
	static const std::string RELATIVE_VALUE;

private:
	::jmsf::natural_size _quantityOfDriveChannels;
	::jmsf::natural_size _quantityOfFiles;
	::jmsf::natural_size _quantityOfReadingChannels;

	::jmsf::Pointer< DriveTable > _driveTable;
	::jmsf::Pointer< VirtualFileTable > _virtualFileTable;
//	::jmsf::UniquePointer< RequestDataFileReader > _requestDataFileReader;

public:
//	size_natural getQuantityOfDriveChannels() const throw();
	::jmsf::natural_size getQuantityOfReadingChannels() const throw();
	const DriveTable &getDriveTable() const throw();
	const VirtualFileTable &getVirtualFileTable() const throw();
//	RequestDataFileReader &getRequestDataFileReader() throw();

private:
	static const std::string readPath( std::ifstream &file ) throw( ::jmsf::Exception );

private:
	static ::jmsf::Pointer< Configuration > _instance;
	static ::jmsf::Proxy< ::jmsf::osie::Mutex > _synchronizer;

public:
	static Configuration *instance() throw( ::jmsf::Exception );	

private: friend class ::jmsf::Pointer< Configuration >;
	~Configuration() throw();

private:
	Configuration( const std::string &pathToConfigurationFile ) throw( ::jmsf::Exception );

private:
	Configuration( const Configuration &other ) throw();
	const Configuration &operator =( const Configuration &other ) throw();

};


} // namespace
}
