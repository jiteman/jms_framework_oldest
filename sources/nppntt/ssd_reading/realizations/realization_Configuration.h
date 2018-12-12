#pragma once

#include "../Configuration.h"
#include "jmsf/Pointers.hpp"
#include "jmsf/stdal/stdal_stl.h"

namespace nppntt {
namespace ssd_reading {
namespace realizations {

class realization_Configuration :
	public Configuration
{

public:
	// virtuals Configuration
	::jmsf::natural_size getQuantityOfReadingChannels() const throw();
	const DriveTable &getDriveTable() const throw();
	const VirtualFileTable &getVirtualFileTable() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Configuration() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Configuration;
	realization_Configuration() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_Configuration( const realization_Configuration &other ) throw();
	const realization_Configuration &operator =( const realization_Configuration &other ) throw( ::jmsf::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	static const stdal_stl::string readPath( std::ifstream &file ) throw( ::jmsf::Exception );

private:
	static stdal_stl::string PATH_TO_CONFIGURATION_FILES;
	static const stdal_stl::string CONFIGURATION_FILENAME;

	static const stdal_stl::string ABSOLUTE_VALUE;
	static const stdal_stl::string RELATIVE_VALUE;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::natural_size _quantityOfDriveChannels;
	::jmsf::natural_size _quantityOfFiles;
	::jmsf::natural_size _quantityOfReadingChannels;

	::jmsf::Pointer< DriveTable > _driveTable;
	::jmsf::Pointer< VirtualFileTable > _virtualFileTable;

};

} // namespace realizations
} // namespace ssd_reading
} // namespace nppntt
