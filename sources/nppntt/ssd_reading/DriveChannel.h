#pragma once

#include "ReadingChannel.h"
#include "SingleRequestData.h"
#include "jmsf/mtf/Runnable.h"
//#include "jmsf/osie/RunnableArray.h"
#include "jmsf/Pointers.hpp"
#include "jmsf/stdal/stdal_stl.h"


// namespace jmsf {
// 	namespace osie {
// 		namespace runup {
// 			class Log;
// 		}
// 	}
// }

namespace nppntt {
namespace ssd_reading {


class DataFilesToRead;


class DriveChannel : public ::jmsf::mtf::Runnable {

	static const ::jmsf::natural_size MAX_AMOUNT_OF_REQUESTS = 128;

private:
	::jmsf::natural_size _numberOfDriveChannel;
//	::jmsf::Pointer< ::jmsf::osie::runup::RunnableArray< ReadingChannel > > _readingChannels;
	std::list< SingleRequestData > _requests;

public:
	::jmsf::natural_size getIndexOfDrive() const throw();
	::jmsf::natural_size getQuantityOfAddedData() const throw();
	void addSingleRequest( const SingleRequestData &request ) throw();
	void distributeAddedData() throw();
	void writeToLog( ::jmsf::osie::runup::Log &log ) const throw();
	void clear() throw();

	const std::vector< ::jmsf::Pointer< ReadingChannel > > &getReadingChannels() const throw();

public:
	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

public:
	static ::jmsf::Pointer< DriveChannel > create( ::jmsf::natural_size numberOfDriveChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw();

private: friend class ::jmsf::Pointer< DriveChannel >;
	// virtual
	~DriveChannel() throw();

private:
	DriveChannel( ::jmsf::natural_size numberOfDriveChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw();

private:
	DriveChannel( const DriveChannel &other ) throw();
	const DriveChannel &operator =( const DriveChannel &other ) throw();

};


} // namespace
}
