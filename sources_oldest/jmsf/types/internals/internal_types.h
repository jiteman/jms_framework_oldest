#pragma once


//#include "warning_suppressor.h"

//#define nullptr 0

#include "jmsf/jmsf.h"


namespace jmsf {
namespace types {
namespace internals {


typedef		signed char			platform_signed_char;
typedef		unsigned char		platform_unsigned_char;
typedef		char				platform_char;
typedef		signed short int	platform_signed_short_int;
typedef		unsigned short int	platform_unsigned_short_int;
//typedef		short int			platform_short_int;
typedef		signed int			platform_signed_int;
typedef		unsigned int		platform_unsigned_int;
//typedef		int					platform_integer;


typedef		bool				platform_boolean;

typedef		char				platform_template_type;


#define JMSF_COMPILER_TYPE 1
#define JMSF_COMPILER_TYPE_IS_MICROSOFT_CPP_COMPILER 1

#if JMSF_COMPILER_TYPE == JMSF_COMPILER_TYPE_IS_MICROSOFT_CPP_COMPILER
	typedef		signed __int64		platform_signed_long_int;
	typedef		unsigned __int64	platform_unsigned_long_int;
	typedef		__int64				platform_long_int;
#else
	typedef		signed long long	platform_signed_long_int;
	typedef		unsigned long long	platform_unsigned_long_int;
	typedef		long long			platform_long_int;
#endif


// size_t
#if defined( JMSF_64 )
 	typedef		platform_signed_long_int		platform_memory_diff;
 	typedef		platform_unsigned_long_int		platform_memory_size;
#elif defined( JMSF_32 )
	typedef		platform_signed_int				platform_memory_diff;
 	typedef		platform_unsigned_int			platform_memory_size;
#else
	#error types.h - neither of JMSF_32 or JMSF_64 is defined
#endif


typedef		platform_signed_long_int	platform_file_diff;
typedef		platform_unsigned_long_int	platform_file_size;



// typedef int_8 integer_small;
// typedef uint_8 natural_small;
// typedef int_16 integer_short;
// typedef uint_16 natural_short;
// typedef int_32 integer;
// typedef uint_32 natural;
// typedef int_3264 integer_size;
// typedef uint_3264 natural_size; // size_t
// typedef int_64 integer_big;
// typedef uint_64 natural_big;
// typedef int_64 integer_file_size;
// typedef uint_64 natural_file_size;

typedef		float		platform_short_real;
typedef		double		platform_real;


} // namespace internals


const internals::platform_unsigned_char CHAR_BIT_SIZE = 8;
const internals::platform_unsigned_char MAXIMUM_BIT_SIZE = CHAR_BIT_SIZE * sizeof( internals::platform_unsigned_long_int );
const internals::platform_real REAL_DEFAULT_ACCURACY = 0.000000000000001;
const internals::platform_short_real SHORT_REAL_DEFAULT_ACCURACY = 0.000001f;


} // namespace types


JMSF_DLL_INTERFACE types::internals::platform_boolean logicalXor( types::internals::platform_boolean first, types::internals::platform_boolean second ) throw();


} // namespace jmsf
