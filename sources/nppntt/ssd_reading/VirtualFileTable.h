#pragma once


#include "VirtualFileTableElement.h"

#include "jmsf/Exception.h"

#include "jmsf/Pointer.hpp"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


class FileTable;


class VirtualFileTable {

	static const ::jmsf::natural_size MAX_AMOUNT_OF_VIRTUAL_FILES = 65536;

public:
	static ::jmsf::Pointer< VirtualFileTable > create( const std::string &listFilename ) throw( ::jmsf::Exception );

private:
	std::vector< VirtualFileTableElement > _elements;

private:
	friend class ::jmsf::Pointer< VirtualFileTable >;
	~VirtualFileTable() throw();

private:
	VirtualFileTable( std::ifstream &fileListFile ) throw();

public:
	const VirtualFileTableElement &getElement( ::jmsf::natural_size numberOfFile ) const throw( ::jmsf::Exception );
	::jmsf::natural_size getQuantity() const throw();
//	const std::vector< FileListElement > &getElements() const throw();

private:
	VirtualFileTable( const VirtualFileTable &other ) throw();
	const VirtualFileTable &operator =( const VirtualFileTable &other ) throw();

};


} // namespace
}
