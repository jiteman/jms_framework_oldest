#pragma once


#include "jmsf/osie/runup/MOVE_StepByStepRunnable.h"

#include "jmsf/Pointer.hpp"


namespace nppntt {
namespace ssd_reading {


class DriveChannel;


class RequestClearer : public ::jmsf::osie::runup::MOVE_StepByStepRunnable {
	
	::jmsf::Pointer< DriveChannel > _driveChannel;

public:
	// virtuals
	void run() throw( ::jmsf::osie::runup::MOVE_RunnableException, ::jmsf::Exception );
	//~virtuals

public:
	static ::jmsf::Pointer< RequestClearer > create( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private: friend class ::jmsf::Pointer< RequestClearer >;
	// virtual
	~RequestClearer() throw();

private:
	RequestClearer( const ::jmsf::Pointer< DriveChannel > &driveChannel ) throw();

private:
	RequestClearer( const RequestClearer &other ) throw();
	const RequestClearer &operator =( const RequestClearer &other ) throw();

};


} // namespace
}
