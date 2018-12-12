#include "ReadingChannelInformation.h"


#include "exceptions/exception_SsdReading.h"

#include "jmsf/factory_TextObject.h"


namespace nppntt {
namespace ssd_reading {


// static
const ::jmsf::char_type *ReadingChannelInformation::SUCCESSFUL_COMPLETION = "ReadingSubchannelInformation - successful completion";


void ReadingChannelInformation::registerSuccessfullyProcessedRequest() throw() {
	_quantityOfSuccessfullyProcessedRequests += 1;
}

void ReadingChannelInformation::registerNoFileFailure() throw() {
	_quantityOfNoFileFailures += 1;
}

void ReadingChannelInformation::registerUnsuccessfulCompletion( const std::string &reason ) throw() {
	_reasonOfUnsuccessfulCompletion = reason;
	_wasSuccessfullyCompleted = false;
}

::jmsf::natural_size ReadingChannelInformation::getQuantityOfReceivedRequests() const throw() {
	return _quantityOfReceivedRequests;
}

::jmsf::natural_size ReadingChannelInformation::getQuantityOfSuccessfullyProcessedRequests() const throw() {
	return _quantityOfSuccessfullyProcessedRequests;
}

::jmsf::natural_size ReadingChannelInformation::getQuantityOfNoFileFailuers() const throw() {
	return _quantityOfNoFileFailures;
}

::jmsf::Boolean ReadingChannelInformation::wasSuccessfullyCompleted() const throw() {
	return _wasSuccessfullyCompleted;
}

const std::string &ReadingChannelInformation::getReasonOfUnsuccessfulCompletion() const throw( ::jmsf::Exception ) {
	if ( _wasSuccessfullyCompleted ) {
		::jmsf::Proxy< ::jmsf::TextStream > textStream = ::jmsf::factory_TextObject::instance()->createTextStream();
		textStream->put( ::jmsf::CONSTANT_TEXT_STRING( "ReadingSubchannelInformation::getReasonOfUnsuccessfulCompletion() - was successfully completed" ) );
		throw exceptions::exception_SsdReading( textStream );		
	}

	return _reasonOfUnsuccessfulCompletion;
}

void ReadingChannelInformation::reset( ::jmsf::natural_size quantityOfReceivedRequests ) throw() {
	_quantityOfReceivedRequests = quantityOfReceivedRequests;
	_quantityOfSuccessfullyProcessedRequests = 0;
	_quantityOfNoFileFailures = 0;

	_wasSuccessfullyCompleted = true;
	_reasonOfUnsuccessfulCompletion = SUCCESSFUL_COMPLETION;
}

ReadingChannelInformation::~ReadingChannelInformation() throw()
{}

ReadingChannelInformation::ReadingChannelInformation() throw()
	: _reasonOfUnsuccessfulCompletion( SUCCESSFUL_COMPLETION )
{
	reset( 0 );
}


} // namespace
}
