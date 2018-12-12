#pragma once


#include "jmsf/Boolean.h"

#include "jmsf/types.h"

#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
	class Exception;
}


namespace nppntt {
namespace ssd_reading {


class ReadingChannelInformation {

	static const ::jmsf::char_type *SUCCESSFUL_COMPLETION;

private:
	::jmsf::natural_size _quantityOfReceivedRequests;
	::jmsf::natural_size _quantityOfSuccessfullyProcessedRequests;
	::jmsf::natural_size _quantityOfNoFileFailures;

	::jmsf::Boolean _wasSuccessfullyCompleted;
	std::string _reasonOfUnsuccessfulCompletion;

public:
	void registerSuccessfullyProcessedRequest() throw();
	void registerNoFileFailure() throw();
	void registerUnsuccessfulCompletion( const std::string &reason ) throw();
	::jmsf::natural_size getQuantityOfReceivedRequests() const throw();
	::jmsf::natural_size getQuantityOfSuccessfullyProcessedRequests() const throw();
	::jmsf::natural_size getQuantityOfNoFileFailuers() const throw();
	::jmsf::Boolean wasSuccessfullyCompleted() const throw();
	const std::string &getReasonOfUnsuccessfulCompletion() const throw( ::jmsf::Exception );
	void reset( ::jmsf::natural_size quantityOfReceivedRequests ) throw();

public:
	~ReadingChannelInformation() throw();
	ReadingChannelInformation() throw();

private:
	ReadingChannelInformation( const ReadingChannelInformation & ) throw() {}
	const ReadingChannelInformation &operator =( const ReadingChannelInformation & ) throw() { return *this; }

};


} // namespace
}
