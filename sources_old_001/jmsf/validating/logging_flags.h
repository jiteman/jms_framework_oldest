#pragma once


// Informing about

// regural messaging
#define JMSF_LOG_MESSAGING_IS_ON

// detailed messaging
//#define JMSF_LOG_MESSAGING_PARANOIDAL_IS_ON


// Informing about errors

// unconditional messaging before throwing an exception (is almost always on)
#define JMSF_LOG_ERROR_IS_ON

// conditional messaging before throwing an exception
#define JSMF_LOG_ERROR_PRELIMINARY_IS_ON


// Informing about strange or suspicious situations, those not errors

// inform messaging (tracing)
#define JMSF_LOG_INFORMING_IS_ON

// detailed inform messaging (detailed tracing)
#define JMSF_LOG_INFORMING_PARANOIDAL_IS_ON


// unconditonal - means that should called regardless of expression value to get trace of Line_and_file with
// JMSF_LOG_INFORMING_PARANOIDAL_IS_ON defined
// another purpose - is release optimization with this undefined
#define JMSF_VALIDATING_SHOULD_IS_UNCONDITIONAL
