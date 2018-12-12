#pragma once

#include "jmsf/mtf/Runnable.h"
#include "jmsf/Object.h"

#include "jmsf/Proxies.hxx"

namespace nppntt {
namespace mdm {
namespace processing {

class ResultToStorageAppender :
	public virtual ::jmsf::mtf::Runnable,
	public virtual ::jmsf::Object
{

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ResultToStorageAppender *getNull() throw();
	static ResultToStorageAppender *getException() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	virtual ::jmsf::Proxy< ResultToStorageAppender > createClone() const throw() = 0;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace processing
} // namespace mdm
} // namespace nppntt
