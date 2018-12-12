#pragma once

#if defined( _DEBUG )
	// 'type cast' : unsafe conversion from 'FARPROC' to 't...'
	#pragma warning( disable: 4191 )
	
	// '=' : conversion from '...' to '...', signed/unsigned mismatch
	#pragma warning( disable: 4365 )

	// 'int' : forcing value to bool 'true' or 'false' (performance warning)
	#pragma warning( disable: 4800 )

	// '=' : conversion from 'const unsigned int' to 'WORD', possible loss of data
	#pragma warning( disable: 4242 )

	// '=' : conversion from 'const unsigned int' to 'WORD', possible loss of data
	#pragma warning( disable: 4244 )

	// 'strncpy': This function or variable may be unsafe. Consider using strncpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	#pragma warning( disable: 4996 )

	// enumerator '...' in switch of enum '...' is not handled
	#pragma warning( disable: 4062 )

	// '==' : signed/unsigned mismatch
	#pragma warning( disable: 4389 )

	// unreachable code
	#pragma warning( disable: 4702 )

	// '=' : conversion from 'size_t' to 'INT', possible loss of data
	#pragma warning( disable: 4267 )

	// : unreferenced inline function has been removed
	#pragma warning( disable: 4514 )

#endif
