#include "ReadingChannel.h"


#include "VirtualFileTable.h"
#include "Configuration.h"

#include "jmsf/osie/runup/exceptions/exception_RunnableException.h"

#include "jmsf/exceptions/exception_UnexpectedStlException.h"

#include "jmsf/factory_TextObject.h"


namespace nppntt {
namespace ssd_reading {


void ReadingChannel::addSingleRequestData( const SingleRequestData &singleRequest ) throw() {
	_requestData.push_back( singleRequest );
}

void ReadingChannel::clear() throw() {
	_requestData.clear();
	clearExceptionInformation();
}

::jmsf::natural_size ReadingChannel::getNumberOfReadingChannel() const throw() {
	return _numberOfReadingChannel;
}

// const SingleRequestData &ReadingChannel::getLastAddedSingleRequestData() const throw( runup::Exception ) {
// 	if ( _requestData.empty() ) {
// 		throw runup::Exception( "ReadingChannel::getLastAddedSingleRequestData() - nothing is added" );
// 	}
// 
// 	return _requestData.back();
// }

// const ReadingChannelInformation &ReadingChannel::getInformation() const throw() {
// 	return *_readingChannelInformation;
// }

void ReadingChannel::run() throw( ::jmsf::Exception ) {
	std::vector< ::jmsf::natural_big > readedData;

	const VirtualFileTable &virtualFileTable = Configuration::instance()->getVirtualFileTable();

	for ( std::vector< SingleRequestData >::const_iterator requestDataIterator = _requestData.begin(); requestDataIterator != _requestData.end(); ++requestDataIterator ) {
		const SingleRequestData &singleRequest = *requestDataIterator;

		try {
			const VirtualFileTableElement &virtualFileTableElement = virtualFileTable.getElement( singleRequest.getIndexOfFile() );
			::jmsf::Pointer< ::jmsf::osie::runup::FileWithoutBuffering > dataFile = virtualFileTableElement.getFile();
			const ::jmsf::natural_big positionShift = virtualFileTableElement.getPositionShift();

			if ( dataFile->isOpen() ) {
				readedData.clear();
				readedData = dataFile->read< ::jmsf::natural_big >( QUANTITY_TO_READ, static_cast< ::jmsf::integer_big >( positionShift + singleRequest.getDataPosition() ) / sizeof( ::jmsf::integer_big ) );

				if ( readedData.empty() ) {
					::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
					textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "ReadingSubchannel::run() - no data is readed." ) );
					throw ::jmsf::osie::runup::exceptions::exception_RunnableException( textStream );
				}

				if ( readedData.size() != QUANTITY_TO_READ ) {
					::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
					textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "ReadingSubchannel::run() - reduced amount of data is readed." ) );
					throw ::jmsf::osie::runup::exceptions::exception_RunnableException( textStream );
				}

				ResultDataGroup &resultDataGroup = _resultDataGroupCollection->getResultDataGroup( singleRequest.getOrdinalNumberOfGroup() );

				for ( std::vector< ::jmsf::natural_big >::const_iterator bigNaturalIterator = readedData.begin(); bigNaturalIterator != readedData.end(); ++bigNaturalIterator ) {

					if ( *bigNaturalIterator == 0 ) continue;					

					if ( singleRequest.doesXorValuesMatch( *bigNaturalIterator ).not() ) continue;					

					resultDataGroup.addSingleResultData( singleRequest.getCorrectedData( *bigNaturalIterator ) );
				}
			}
		} catch ( const ::jmsf::osie::runup::exceptions::exception_FileException &catchedFileException ) {			
			throw ::jmsf::osie::runup::exceptions::exception_RunnableException( catchedFileException.getReason()->createClone() );
		} catch ( const ::jmsf::osie::runup::exceptions::exception_RunnableException & ) {			
			throw;
		} catch ( ... ) {
			::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
			textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "ReadingSubchannel::run() - unexpected exception" ) );
			throw ::jmsf::exceptions::exception_UnexpectedStlException( textStream );
		}
	}
}


// static
::jmsf::Pointer< ReadingChannel > ReadingChannel::create( const ::jmsf::natural_size numberOfReadingChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw() {
	return ::jmsf::Pointer< ReadingChannel >::createUnique( new ReadingChannel( numberOfReadingChannel, resultDataGroupCollection ) );
}


ReadingChannel::~ReadingChannel() throw()
{}

ReadingChannel::ReadingChannel( const ::jmsf::natural_size numberOfReadingChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw()
	:
		_resultDataGroupCollection( resultDataGroupCollection )
//		_readingChannelInformation( ::jmsf::Pointer< ReadingChannelInformation >::createUnique() )
{		
	_numberOfReadingChannel = numberOfReadingChannel;
	_requestData.reserve( MAX_AMOUNT_OF_REQUESTS );
}

ReadingChannel::ReadingChannel( const ReadingChannel & ) throw() // ohter
	: _resultDataGroupCollection( ::jmsf::Pointer< ResultDataGroupCollection >::createNone() )
{}

const ReadingChannel &ReadingChannel::operator =( const ReadingChannel &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}


} // namespace
}
