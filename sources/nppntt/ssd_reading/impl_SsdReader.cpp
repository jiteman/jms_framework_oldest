#include "realization_SsdReader.h"

#include "Configuration.h"
#include "SingleRequestData.h"

#include "jmsf/osie/runup/HighResolutionStopwatch.h"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


// jms::boolean global_isDebugNeeded;
// ::jmsf::natural_size global_lastValidDataIndex;
// ::jmsf::natural_size global_lastValidDataSourceDataIndex;


const std::string realization_SsdReader::TAB = "\t";


realization_SsdReader::~realization_SsdReader() throw()
{}

realization_SsdReader::realization_SsdReader( const ::jmsf::natural_big lengthEraserMask ) throw()
	:
		_driveChannelArray( ::jmsf::Pointer< DriveChannelArray >::createNone() ),
		_logFile( ::jmsf::Pointer< std::ofstream >::createNone() )
{
	SingleRequestData::setLenthEraseMask( lengthEraserMask );	
	_isInitialized = false;

	try {
		Configuration::instance();
		_driveChannelArray = DriveChannelArray::create();		
		_isInitialized = true;
	} catch( const ::jmsf::Exception &catched ) {
		*getLogFile() << "realization_SsdReader::realization_SsdReader() - " << catched.getReason()->getCtext() << std::endl;
	} catch( const std::exception &catched ) {
		*getLogFile() << "realization_SsdReader::realization_SsdReader() - unexpected std exception" << catched.what() << std::endl;
	} catch( ... ) {
		*getLogFile() << "realization_SsdReader::realization_SsdReader() - unexpected unknown exception" << std::endl;
	}

	_operationCounter = 0;
	_stopwatch.restartTiming();
}

::jmsf::Boolean realization_SsdReader::wasInitilazed() const throw() {
	return _isInitialized;
}

void realization_SsdReader::readData( 
	::jmsf::natural_big destinationDataBufferSize,
	::jmsf::natural_big *const destinationDataBuffer,
	::jmsf::natural_big sourceDataBufferSize,
	const ::jmsf::natural_big *const sourceRequestDataBuffer,
	const ::jmsf::natural_big *const sourceAlphaValuesBuffer,
	const ::jmsf::natural_big *const sourceXorValuesBuffer ) throw()
{
	if ( _isInitialized.not() ) return;

	const float waitingDuration = static_cast< float >( _stopwatch.getSplitTimeInSeconds() );

	::jmsf::osie::runup::HighResolutionStopwatch wholeReadingStopwatch;
	wholeReadingStopwatch.restartTiming();

	*getLogFile() << _operationCounter << TAB << waitingDuration << TAB << sourceDataBufferSize << TAB;

	try {
		_stopwatch.restartTiming();
		_driveChannelArray->addAndDistibuteRequestData( sourceDataBufferSize, sourceRequestDataBuffer, sourceAlphaValuesBuffer, sourceXorValuesBuffer );
		const float distributionDuration = static_cast< float >( _stopwatch.getSplitTimeInSeconds() );

		_stopwatch.restartTiming();		
		_driveChannelArray->readDataAndPutItToTheBuffer( destinationDataBufferSize, destinationDataBuffer );
		const float readingDuration = static_cast< float >( _stopwatch.getSplitTimeInSeconds() );

		_stopwatch.restartTiming();

		const float wholeDuration = static_cast< float >( wholeReadingStopwatch.getSplitTimeInSeconds() );
		*getLogFile() << wholeDuration << TAB << distributionDuration << TAB << readingDuration << std::endl;		
	} catch ( std::exception &catched ) {
		*getLogFile() << catched.what() << std::endl;
	}

	_operationCounter += 1;

	_stopwatch.restartTiming();	
}

::jmsf::Pointer< std::ofstream > realization_SsdReader::getLogFile() throw() {
	if ( _logFile.isEmpty() ) {
		const std::string configurationName =
#if defined( _DEBUG )
			".debug";
#else
			".release";
#endif

		const ::jmsf::natural_size quantityOfDrives = Configuration::instance()->getDriveTable().getDriveIndices().size();
		const ::jmsf::natural_size quantityOfReadingChannels = Configuration::instance()->getQuantityOfReadingChannels();

		std::stringstream stringStream;
		stringStream << "__log.file." << std::setw( 2 ) << std::setfill( '0' ) << quantityOfDrives << "." << quantityOfReadingChannels << configurationName << ".txt";
		_logFile = ::jmsf::Pointer< std::ofstream >::createUnique( new std::ofstream( stringStream.str() ) );		
		*_logFile << "Number" << TAB << "Waiting" << TAB << "Quantity" << TAB << "Whole" << TAB << "Distribution" << TAB << "Reading" << TAB << "Getting" << std::endl;
	}

	return _logFile.getWeak();
}

realization_SsdReader::realization_SsdReader( const realization_SsdReader & ) throw() // other
	:
		_driveChannelArray( ::jmsf::Pointer< DriveChannelArray >::createNone() ),
		_logFile( ::jmsf::Pointer< std::ofstream >::createNone() )
{}

const realization_SsdReader &realization_SsdReader::operator =( const realization_SsdReader &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
