#pragma once


#include "jmsf/osie/runup/MOVE_StepByStepRunnable.h"

#include "jmsf/Pointer.hpp"


namespace nppntt {
namespace ssd_reading {


class DriveChannel;


class ReadingChannelRequestDistributionLauncher : public ::jmsf::osie::runup::MOVE_StepByStepRunnable {

	::jmsf::Pointer< DriveChannel > _driveChannel;

public:
	// virtuals
	void run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception );
	//~virtuals

public:
	static ::jmsf::Pointer< ReadingChannelRequestDistributionLauncher > create( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private: friend class ::jmsf::Pointer< ReadingChannelRequestDistributionLauncher >;
	// virtual
	~ReadingChannelRequestDistributionLauncher() throw();

private:
	ReadingChannelRequestDistributionLauncher( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private:
	ReadingChannelRequestDistributionLauncher( const ReadingChannelRequestDistributionLauncher &other ) throw();
	const ReadingChannelRequestDistributionLauncher &operator =( const ReadingChannelRequestDistributionLauncher &other ) throw();

};


} // namespace
}
