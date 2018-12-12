#pragma once

#include "../factory_MaskDm.h"


namespace nppntt {
namespace mdm {
namespace realizations {


class realization_factory_MaskDm :
	public factory_MaskDm
{

public:
	// virtuals factory_MaskDm
	::jmsf::Proxy< MaskDm > createMaskDm() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_MaskDm;
	realization_factory_MaskDm() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_MaskDm( const realization_factory_MaskDm &other ) throw();
	const realization_factory_MaskDm &operator =( const realization_factory_MaskDm &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
