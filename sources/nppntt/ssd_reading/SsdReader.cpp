#include "SsdReader.h"


//#include "remove/REMOVE_ReadingDistributor.h"
#include "realization_SsdReader.h"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


SsdReader::~SsdReader() throw() {
	delete _realizationementation;
}

SsdReader::SsdReader( __int64 p_lengthEraserMask ) throw() {
	const ::jmsf::natural_big lengthEraserMask = static_cast< ::jmsf::natural_big >( p_lengthEraserMask );
	_realizationementation = new realization_SsdReader( lengthEraserMask );
	_isAlreadyRunning = ::jmsf::False;
}

::jmsf::Boolean SsdReader::wasInitialized() const throw() {
	if ( _realizationementation == nullptr ) return ::jmsf::False;

	return _realizationementation->wasInitilazed();
}

void SsdReader::readData(
	__int64 p_destinationDataBufferSize,
	__int64 *const p_destinationDataBuffer,
	__int64 p_sourceDataBufferSize,
	const __int64 *const p_sourceRequestDataBuffer,
	const __int64 *const p_sourceAlphaValuesBuffer,
	const __int64 *const p_sourceXorValuesBuffer ) throw( std::exception )
{
	if ( _realizationementation == nullptr ) throw std::exception( "SSD Reader was not initialized." );

	if ( _isAlreadyRunning ) throw std::exception( "SSD Reader is already running." );

	_isAlreadyRunning = true;

	using namespace jmsf;

	const natural_big destinationDataBufferSize	= static_cast< natural_big >( p_destinationDataBufferSize );
	natural_big *destinationDataBuffer = reinterpret_cast< natural_big * >( p_destinationDataBuffer );
	const natural_big sourceDataBufferSize	= static_cast< natural_big >( p_sourceDataBufferSize );
	const natural_big *sourceRequestDataBuffer = reinterpret_cast< const natural_big *>( p_sourceRequestDataBuffer );
	const natural_big *sourceAlphaValuesBuffer = reinterpret_cast< const natural_big *>( p_sourceAlphaValuesBuffer );
	const natural_big *sourceXorValuesBuffer = reinterpret_cast< const natural_big *>( p_sourceXorValuesBuffer );

	_realizationementation->readData(
		destinationDataBufferSize,
		destinationDataBuffer,
		sourceDataBufferSize,
		sourceRequestDataBuffer, 
		sourceAlphaValuesBuffer,
		sourceXorValuesBuffer );

	_isAlreadyRunning = false;
}


} // namespace
}
