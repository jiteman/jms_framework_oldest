#pragma once

#include "ResultDataGroup.h"

#include "jmsf/stdal/stdal_stl.h"


namespace jmsf {
	template< class > class Pointer;
}


namespace nppntt {	
namespace ssd_reading {


class ResultDataGroupCollection {

public:
	static ::jmsf::Pointer< ResultDataGroupCollection > create() throw();

private:
	std::vector< ResultDataGroup > _resultDataGroups;

private:
	friend class ::jmsf::Pointer< ResultDataGroupCollection >;
	~ResultDataGroupCollection() throw();

private:	
	ResultDataGroupCollection() throw();

public:
	void resizeIfNeeded( ::jmsf::natural_size requiredSize ) throw();
	ResultDataGroup &getResultDataGroup( ::jmsf::natural_size resultDataGroupIndex ) throw( std::out_of_range );	
	void clear() throw();

	const std::vector< ResultDataGroup > &getResultDataGroups() const throw();

private:
	ResultDataGroupCollection( const ResultDataGroupCollection & ) throw() {}
	const ResultDataGroupCollection &operator =( const ResultDataGroupCollection & ) throw() { return *this; }

};


} // namespace
}
