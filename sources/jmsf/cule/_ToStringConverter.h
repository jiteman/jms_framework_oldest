#pragma once


#include <string>
#include <sstream>
#include <stdlib.h>


namespace jmsf {
namespace cule {
namespace to_remove {


class ToStringConverter {

public:
	ToStringConverter() {}

	template< typename A_type >
	const std::_tstring toString( const A_type *pointer ) {
		std::_tostringstream stringStream;
		stringStream << reinterpret_cast< const void * >( pointer );
		return stringStream.str();
	}

	template< typename A_type >
	const std::_tstring toString( const A_type &value ) {
		return value->toString();
	}

	template<>
	const std::_tstring toString< std::wstring >( const std::wstring &string ) {
		return std::_toString( string );
	}

	template<>
	const std::_tstring toString< std::string >( const std::string &string ) {
		return std::_toString( string );
	}

	template<>
	const std::_tstring toString< bool >( const bool &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< char >( const char &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< unsigned char >( const unsigned char &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< wchar_t >( const wchar_t &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}	

	template<>
	const std::_tstring toString< short >( const short &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< unsigned short >( const unsigned short &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< int >( const int &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< unsigned int >( const unsigned int &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< long >( const long &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< unsigned long >( const unsigned long &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< float >( const float &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

	template<>
	const std::_tstring toString< double >( const double &value ) {
		std::_tostringstream stringStream;
		stringStream << value;
		return stringStream.str();
	}

private:
	ToStringConverter( const ToStringConverter & ) {}
	const ToStringConverter &operator =( const ToStringConverter & ) { return *this; }

};


} // namespace
}
}
