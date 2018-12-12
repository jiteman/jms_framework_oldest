#pragma once

#include "DriveChannelArray.h"
#include "jmsF/osie/runup/HighResolutionStopwatch.h"
#include "jmsf/Pointer.hpp"

//Remove
#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


// extern jms::boolean global_isDebugNeeded;
// extern ::jmsf::natural_size global_lastValidDataIndex;
// extern ::jmsf::natural_size global_lastValidDataSourceDataIndex;


class realization_SsdReader {

	static const std::string TAB;

private:
	::jmsf::Boolean _isInitialized;
	::jmsf::osie::runup::HighResolutionStopwatch _stopwatch;
	::jmsf::Pointer< DriveChannelArray > _driveChannelArray;
	::jmsf::natural_big _operationCounter;
	::jmsf::Pointer< std::ofstream > _logFile;

public:
	~realization_SsdReader() throw();
	realization_SsdReader( ::jmsf::natural_big lengthEraserMask ) throw();

	::jmsf::Boolean wasInitilazed() const throw();

	void readData(
		::jmsf::natural_big destinationDataBufferSize,
		::jmsf::natural_big *destinationDataBuffer,
		::jmsf::natural_big sourceDataBufferSize,
		const ::jmsf::natural_big *sourceRequestDataBuffer,
		const ::jmsf::natural_big *sourceAlphaValuesBuffer,
		const ::jmsf::natural_big *sourceXorValuesBuffer ) throw();

private:
	::jmsf::Pointer< std::ofstream > getLogFile() throw();

private:
	realization_SsdReader( const realization_SsdReader &other ) throw();
	const realization_SsdReader &operator =( const realization_SsdReader &other ) throw();

};


} // namespace
}
