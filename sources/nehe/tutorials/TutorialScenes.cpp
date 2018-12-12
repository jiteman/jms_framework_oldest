#include "TutorialScenes.h"


#include "realizing/realization_TutorialScenes.h"


namespace nehe {
namespace tutorials {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
TutorialScenes::~TutorialScenes() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
TutorialScenes *TutorialScenes::createInstance() throw() {
	return new realizations::realization_TutorialScenes;
}

TutorialScenes::TutorialScenes() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
TutorialScenes::TutorialScenes( const TutorialScenes & ) throw() // other
{}

const TutorialScenes &TutorialScenes::operator =( const TutorialScenes &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



} // namespace tutorials
} // namespace nehe
