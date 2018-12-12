#pragma once


#include "SingleRequestData.h"

#include "jmsf/osie/runup/MOVE_StepByStepRunnable.h"

#include "jmsf/Pointer.hpp"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


class DriveChannel;


class DriveChannelRequestDistributor : public ::jmsf::osie::runup::MOVE_StepByStepRunnable {

	static const std::vector< SingleRequestData > *_requestDataSeries;

public:
	static void setRequestDataSeries( const std::vector< SingleRequestData > &requestDataSeries ) throw();

private:
	::jmsf::Pointer< DriveChannel > _driveChannel;

public:
	// virtuals
	void run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception );
	//~virtuals

public:
	static ::jmsf::Pointer< DriveChannelRequestDistributor > create( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private: friend class ::jmsf::Pointer< DriveChannelRequestDistributor >;
	// virtual
	~DriveChannelRequestDistributor() throw();

private:
	DriveChannelRequestDistributor( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private:
	DriveChannelRequestDistributor( const DriveChannelRequestDistributor &other ) throw();
	const DriveChannelRequestDistributor &operator =( const DriveChannelRequestDistributor &other ) throw();

};


} // namespace
}
