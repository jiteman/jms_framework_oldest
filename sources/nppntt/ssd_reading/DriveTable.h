#pragma once

// #include "jmsf/osie/runup/FileWithoutBuffering.h"
#include "jmsf/Exception.h"

#include "jmsf/Pointer.hpp"

#include "jmsf/stdal/stdal_stl.h"

namespace nppntt {
namespace ssd_reading {

class DriveTable {

	static const ::jmsf::natural_size MAX_QUANTITY_OF_DRIVES = 32;

private:
	std::vector< const ::jmsf::natural_size > _driveIndices;
	::jmsf::natural_size _sizeOfCluster;

public:	
	const std::vector< const ::jmsf::natural_size > &getDriveIndices() const throw();
	::jmsf::natural_size getSizeOfCluster() const throw();
	
public:
	static ::jmsf::Pointer< DriveTable > create( const std::string &pathToFileConfigurationFile ) throw( ::jmsf::Exception );

private: friend class ::jmsf::Pointer< DriveTable >;
	~DriveTable() throw();

private:
	DriveTable( const std::string &pathToFileConfigurationFile ) throw( ::jmsf::Exception );

private:
	DriveTable( const DriveTable &other );
	const DriveTable &operator =( const DriveTable &other );

};

} // namespace
}
