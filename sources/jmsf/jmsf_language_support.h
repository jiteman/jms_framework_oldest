#pragma once


#if !defined( noexept ) && defined( JMSF_NOEXEPT_SUPPORT )

#define noexept throw()

#endif
