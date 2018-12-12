#pragma once


#include "../Bitwise.hpp"


namespace jmsf {
namespace assists {


template< typename integral_type >
integral_type extractBitField( const integral_type data, const size_t shift, const integral_type mask ) {	
	return ::jmsf::Bitwise< integral_type >( data >> static_cast< integral_type >( shift ) ).and( mask );
}

template< typename integral_type >
integral_type insertBitField( const integral_type data, const size_t shift ) {	
	return data << static_cast< integral_type >( shift );
}



} // namespace
}
