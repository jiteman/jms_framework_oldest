#pragma once


#include "jmsf/Boolean.h"

#include "jmsf/types.h"

#include "jmsf/stdal/stdal_stl.h"


namespace nppntt {
namespace ssd_reading {


class ResultDataGroup {

	static const ::jmsf::natural_size RESULT_RESERVE_SIZE = 1024;

private:
	std::vector< ::jmsf::natural_big > _resultData;	

public:
	~ResultDataGroup() throw();
	ResultDataGroup() throw();

	void addSingleResultData( ::jmsf::natural_big singleResultData ) throw();
	const std::vector< ::jmsf::natural_big > &getResultData() const throw();

	::jmsf::Boolean isEmpty() const throw();

	void clear() throw();

//	jms::boolean operator <( const ResultDataGroup &other ) const throw();

private:
//	ResultDataGroup( const ResultDataGroup & ) throw() {}
//	const ResultDataGroup &operator =( const ResultDataGroup & ) throw() { return *this; }

};


} // namespace
}
