#pragma once

#include "SsdReader_dll.h"

#include "jmsf/Boolean.h"


namespace jmsf {
	class Exception;
}


namespace nppntt {
namespace ssd_reading {


class realization_SsdReader;


class NPPNTT_SSD_READER_DLL_INTERFACE SsdReader {

	realization_SsdReader *_realizationementation;
	::jmsf::Boolean _isAlreadyRunning;

public:
	~SsdReader() throw();
	SsdReader( __int64 lengthEraserMask ) throw();

	::jmsf::Boolean wasInitialized() const throw();

	void readData(
		__int64 destinationDataBufferSize,
		__int64 *destinationDataBuffer,
		__int64 sourceDataBufferSize,
		const __int64 *sourceRequestDataBuffer,
		const __int64 *sourceAlphaValuesBuffer,
		const __int64 *sourceXorValuesBuffer ) throw( ::jmsf::Exception );

private:
	SsdReader( const SsdReader & ) throw() {}
	const SsdReader &operator =( const SsdReader & ) throw() { return *this; }

};


} // namespace
}
