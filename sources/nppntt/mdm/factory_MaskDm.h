#pragma once

#include "jmsf/Singleton.hpp"

#include "MaskDm.hxx"

#include "jmsf/Proxies.hxx"


namespace nppntt {
namespace mdm {


class factory_MaskDm :
	public ::jmsf::Singleton< factory_MaskDm >
{

public:
	virtual ::jmsf::Proxy< MaskDm > createMaskDm() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class ::jmsf::Singleton< factory_MaskDm >;
	static factory_MaskDm *createInstance() throw();

protected:
	factory_MaskDm() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_MaskDm( const factory_MaskDm &other ) throw();
	const factory_MaskDm &operator =( const factory_MaskDm &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
