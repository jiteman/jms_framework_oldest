#pragma once

#include "jmsf/Singleton.hpp"

#include "observable_FileFilter.hxx"
#include "observer_FileFilter.hxx"

#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {
namespace file_filters {


class factory_FileFilters :
	public ::jmsf::Singleton< factory_FileFilters >
{

public:
	virtual ::jmsf::Proxy< observable_FileFilter > createObservableFileFilter() const throw() = 0;
	virtual ::jmsf::Proxy< observer_FileFilter >createObserverFileFilter( const ::jmsf::Proxy< observable_FileFilter > &observableFileFilter ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_FileFilters() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_FileFilters >;
	static factory_FileFilters *createInstance() throw();

protected:
	factory_FileFilters() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_FileFilters( const factory_FileFilters &other ) throw();
	const factory_FileFilters &operator =( const factory_FileFilters &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
