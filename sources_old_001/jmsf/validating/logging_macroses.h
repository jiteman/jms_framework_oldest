#pragma once


#include "logging_flags.h"


#if defined( JMSF_LOG_MESSAGING_IS_ON ) || defined( JMSF_LOG_MESSAGING_PARANOIDAL_IS_ON ) || \
	defined( JMSF_LOG_ERROR_IS_ON ) || defined( JSMF_LOG_ERROR_PRELIMINARY_IS_ON ) || \
	defined( JMSF_LOG_INFORMING_IS_ON ) || defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )

	#include "Log.h"
	#include "type_name.h"

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_LOG_MESSAGING_IS_ON )
	// SenSEI: todonext - add configuration detection to encodebuba and use it here
	#define JMSF_LOG_MESSAGING_OUTPUT( message ) \
		::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ )

	#define JMSF_LOG_MESSAGING_OUTPUT_TYPED( message, type ) \
		::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ )

	#define JMSF_LOG_MESSAGING_CONDITIONAL_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_MESSAGING_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }

#else
	#define JMSF_LOG_MESSAGING_OUTPUT( message )
	#define JMSF_LOG_MESSAGING_OUTPUT_TYPED( message, type )
	#define JMSF_LOG_MESSAGING_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_LOG_MESSAGING_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


#if defined( JMSF_LOG_MESSAGING_PARANOIDAL_IS_ON )
	// SenSEI: todonext - add configuration detection to encodebuba and use it here
	#define JMSF_LOG_MESSAGING_PARANOIDAL_OUTPUT( message ) \
		::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ )

	#define JMSF_LOG_MESSAGING_PARANOIDAL_OUTPUT_TYPED( message, type ) \
		::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ )

	#define JMSF_LOG_MESSAGING_CONDITIONAL_PARANOIDAL_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_MESSAGING_CONDITIONAL_PARANOIDAL_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }

#else
	#define JMSF_LOG_MESSAGING_PARANOIDAL_OUTPUT( message )
	#define JMSF_LOG_MESSAGING_PARANOIDAL_OUTPUT_TYPED( message, type )
	#define JMSF_LOG_MESSAGING_CONDITIONAL_PARANOIDAL_OUTPUT( condition, message )
	#define JMSF_LOG_MESSAGING_CONDITIONAL_PARANOIDAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_LOG_ERROR_IS_ON )
	// SenSEI: todonext - add configuration detection to encodebuba and use it here
	#define JMSF_LOG_ERROR_OUTPUT( message ) \
		::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ )

	#define JMSF_LOG_ERROR_OUTPUT_TYPED( message, type ) \
		::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ )

	#define JMSF_LOG_ERROR_CONDITIONAL_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_ERROR_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }

#else
	#define JMSF_LOG_ERROR_OUTPUT( string )
	#define JMSF_LOG_ERROR_OUTPUT_TYPED( message, type )
	#define JMSF_LOG_ERROR_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_LOG_ERROR_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


#if defined( JSMF_LOG_ERROR_PRELIMINARY_IS_ON )

	#define JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_ERROR_PRELIMINARY_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }

#else
	#define JMSF_LOG_ERROR_PRELIMINARY_OUTPUT( condition, message )
	#define JMSF_LOG_ERROR_PRELIMINARY_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_LOG_INFORMING_IS_ON )
	// SenSEI: todonext - add configuration detection to encodebuba and use it here
	#define JMSF_LOG_INFORMING_OUTPUT( message ) \
		::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ )

	#define JMSF_LOG_INFORMING_OUTPUT_TYPED( message, type ) \
		::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ )

	#define JMSF_LOG_INFORMING_CONDITIONAL_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_INFORMING_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }
#else
	#define JMSF_LOG_INFORMING_OUTPUT( message )
	#define JMSF_LOG_INFORMING_OUTPUT_TYPED( message, type )
	#define JMSF_LOG_INFORMING_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_LOG_INFORMING_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


#if defined( JMSF_LOG_INFORMING_PARANOIDAL_IS_ON )
	// SenSEI: todonext - add configuration detection to encodebuba and use it here
	#define JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT( message ) \
		::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ )

	#define JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT_TYPED( message, type ) \
		::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ )

	#define JMSF_LOG_INFORMING_CONDITIONAL_PARANOIDAL_OUTPUT( condition, message ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), __FILE__, __LINE__ );  }

	#define JMSF_LOG_INFORMING_CONDITIONAL_PARANOIDAL_OUTPUT_TYPED( condition, message, type ) \
		if ( ( condition ) ) { ::jmsf::validating::Log::write( ( message ), ( type ), __FILE__, __LINE__ );  }

#else
	#define JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT( message )
	#define JMSF_LOG_INFORMING_PARANOIDAL_OUTPUT_TYPED( message, type )
	#define JMSF_LOG_INFORMING_CONDITIONAL_PARANOIDAL_OUTPUT( condition, message )
	#define JMSF_LOG_INFORMING_CONDITIONAL_PARANOIDAL_OUTPUT_TYPED( condition, message, type )

#endif
