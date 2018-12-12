#pragma once

#include "SingleRequestData.h"
#include "ReadingChannelInformation.h"
#include "ResultDataGroupCollection.h"

#include "jmsf/mtf/Runnable.h"

#include "jmsf/Pointer.hpp"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


class DataFilesToRead;


class ReadingChannel : public ::jmsf::mtf::Runnable {

	static const ::jmsf::natural_size QUANTITY_TO_READ = 16;
	static const ::jmsf::natural_size MAX_AMOUNT_OF_REQUESTS = 1536;

private:
	::jmsf::natural_size _numberOfReadingChannel;
	std::vector< SingleRequestData > _requestData;
//	::jmsf::Pointer< ReadingChannelInformation > _readingChannelInformation;

	::jmsf::Pointer< ResultDataGroupCollection > _resultDataGroupCollection;

public:
	void addSingleRequestData( const SingleRequestData &singleRequest ) throw();
	void clear() throw();
	::jmsf::natural_size getNumberOfReadingChannel() const throw();
//	const SingleRequestData &getLastAddedSingleRequestData() const throw( runup::Exception );
//	const ReadingChannelInformation &getInformation() const throw();

public:
	// virtuals
	void run() throw( ::jmsf::Exception );
	//~virtuals

public:
	static ::jmsf::Pointer< ReadingChannel > create( ::jmsf::natural_size numberOfReadingChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw();

private: friend class ::jmsf::Pointer< ReadingChannel >;
	// virtual
	~ReadingChannel() throw();

private:
	ReadingChannel( ::jmsf::natural_size numberOfReadingChannel, const ::jmsf::Pointer< ResultDataGroupCollection > &resultDataGroupCollection ) throw();

private:
	ReadingChannel( const ReadingChannel &ohter ) throw();
	const ReadingChannel &operator =( const ReadingChannel &other ) throw();

};


} // namespace
}
