#pragma once


#include "../SceneDrawer.h"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_factory_SceneDrawer.hxx"


namespace nehe {
namespace tutorials {


namespace realizations {

class realization_Scene01Drawer :
	public SceneDrawer,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals SceneDrawer
	bool isInitialized() const throw();
	bool prepare() const throw();
	bool draw() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Scene01Drawer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_SceneDrawer;
	realization_Scene01Drawer() throw( jmsf::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< SceneDrawer > createClone() const throw();

private:
	realization_Scene01Drawer( const realization_Scene01Drawer &other ) throw();
	const realization_Scene01Drawer &operator =( const realization_Scene01Drawer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	bool _isInitialized;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace realizations



} // namespace tutorials
} // namespace nehe
