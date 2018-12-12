#pragma once

#include "jmsf/osie/File.hxx"

#include "jmsf/Pointers.hpp"

#include "jmsf/types.h"
#include "jmsf/stdal/stdal_stl.h"

namespace nppntt {
namespace ssd_reading {

class VirtualFileTableElement {
	
	::jmsf::natural_size _indexOfDrive;
	::jmsf::Pointer< ::jmsf::osie::File > _file;
	::jmsf::natural_big _positionShift;
	::std::string _pathToFile;

public:
	~VirtualFileTableElement() throw();
	VirtualFileTableElement() throw();
	VirtualFileTableElement( ::jmsf::natural_big sizeOfCluster, const std::string &pathToFile, ::jmsf::natural_size indexOfDrive, ::jmsf::natural_big positionShift ) throw();

	::jmsf::natural_size getIndexOfDrive() const throw();
	::jmsf::Pointer< ::jmsf::osie::File > getFile() const throw();
	::jmsf::natural_big getPositionShift() const throw();

private:
//	VirtualFileTableElement( const VirtualFileTableElement & ) throw() {}
//	const VirtualFileTableElement &operator =( const VirtualFileTableElement & ) throw() { return *this; }

};

} // namespace
}
