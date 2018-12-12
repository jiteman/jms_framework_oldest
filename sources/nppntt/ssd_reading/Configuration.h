#pragma once

#include "jmsf/Singleton.hpp"
#include "jmsf/DeleterForPointer.hxx"
#include "DriveTable.hxx"
#include "VirtualFileTable.hxx"

namespace nppntt {
namespace ssd_reading {

class Configuration :
	public ::jmsf::Singleton< Configuration >
{

public:
	virtual ::jmsf::natural_size getQuantityOfReadingChannels() const throw() = 0;
	virtual const DriveTable &getDriveTable() const throw() = 0;
	virtual const VirtualFileTable &getVirtualFileTable() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend ::jmsf::DeleterForPointer< Configuration >;
	~Configuration() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< Configuration >;
	static Configuration *createInstance() throw();

protected:
	Configuration() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Configuration( const Configuration &other ) throw();
	const Configuration &operator =( const Configuration &other ) throw( ::jmsf::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ssd_reading
} // namespace nppntt
