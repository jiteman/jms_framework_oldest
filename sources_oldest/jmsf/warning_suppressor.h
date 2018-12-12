#pragma once


// inherits via dominance
#pragma warning( disable: 4250 )

// needs to have dll-interface to be used by clients of class
#pragma warning( disable: 4251 )

// alignment of a member was sensitive to packing
#pragma warning( disable: 4121 )

// 'this' : used in base member initializer list
#pragma warning( disable: 4355 )

// function not inlined
#pragma warning( disable : 4710 )


#if defined( _DEBUG )
	// unreferenced inline function has been removed
	#pragma warning( disable: 4514 )
	
#else if
	// function '' selected for automatic inline expansion
	#pragma warning( disable: 4711 )

	// unreferenced inline function has been removed
	#pragma warning( disable: 4514 )

	// storing 32-bit float result in memory, possible loss of performance
	#pragma warning( disable : 4738 )

	// unreachable code
	#pragma warning( disable: 4702 )

#endif
