#pragma once

#if defined( _DEBUG )
	// 'type cast' : unsafe conversion from 'FARPROC' to 't...'
//	#pragma warning( disable: 4191 )
	
	// '=' : conversion from '...' to '...', signed/unsigned mismatch
	#pragma warning( disable: 4365 )

	// nonstandard extension used : nameless struct/union
	#pragma warning( disable: 4201 )

	// '=' : conversion from 'const unsigned int' to 'WORD', possible loss of data
//	#pragma warning( disable: 4242 )

	// '=' : conversion from 'const unsigned int' to 'WORD', possible loss of data
//	#pragma warning( disable: 4244 )

	// '...': This function or variable may be unsafe. Consider using ..._s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	#pragma warning( disable: 4996 )

#endif
