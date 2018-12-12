#include "ReferenceCounters.h"

#include "../Should.h"


namespace jmsf {
namespace base_pointing {


ReferenceCounters::~ReferenceCounters() throw( Exception ) {
	Should::alwaysBe( areNull() );
}

ReferenceCounters::ReferenceCounters() throw() {
	_strong = 0;
	_weak = 0;
}

Boolean ReferenceCounters::isStrongNull() const throw() {
	return _strong == 0;
}

Boolean ReferenceCounters::isWeakNull() const throw() {
	return _weak == 0;
}

Boolean ReferenceCounters::areNull() const throw() {
	return isStrongNull() && isWeakNull();
}

natural_size ReferenceCounters::getConnectivity() const throw() {
	return _strong;// + _weak;
}

void ReferenceCounters::increaseStrong() throw() {
	_strong += 1;
}

void ReferenceCounters::decreaseStrong() throw() {
	_strong -= 1;
}

void ReferenceCounters::increaseWeak() throw() {
	_weak += 1;
}

void ReferenceCounters::decreaseWeak() throw() {
	_weak -= 1;
}


} // namespace base_pointing
} // namespace jmsf
