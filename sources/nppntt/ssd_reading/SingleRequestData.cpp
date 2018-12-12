#include "SingleRequestData.h"


#include "Configuration.h"

#include "jmsf/osie/runup/MOVE_BitFields.hpp"
#include "jmsf/osie/runup/MOVE_IntegralLog2.hpp"

#include "jmsf/Bitwise.hpp"


namespace nppntt {
namespace ssd_reading {


::jmsf::natural_big SingleRequestData::LENGTH_ERASE_MASK = 0;


void SingleRequestData::setLenthEraseMask( const ::jmsf::natural_big lengthEraseMask ) throw() {
	LENGTH_ERASE_MASK = lengthEraseMask;
}

SingleRequestData::~SingleRequestData() throw()
{}

SingleRequestData::SingleRequestData() throw() {
	_ordinalNumberOfGroup = ~::jmsf::natural_size( 0 );
	_actualIndexOfDrive = 0;
	_indexOfFile = 0;
	_dataPosition = 0;
	_shiftedXorValueBitandNotXOR_CODE_MASK = 0;
	_shiftedXorValueBitandXOR_CODE_MASK = 0;
}

SingleRequestData::SingleRequestData( const ::jmsf::natural_size ordinalNumberOfGroup, const ::jmsf::natural_big packedSingleRequestData, const ::jmsf::natural_big alphaValue, const ::jmsf::natural_big shiftedXorValue ) throw( ::jmsf::Exception ) {
	_ordinalNumberOfGroup = ordinalNumberOfGroup;
	
	{
		const ::jmsf::natural_big fileRange = ::jmsf::osie::runup::integralLog2( static_cast< ::jmsf::natural_big >( ::jmsf::Bitwise< ::jmsf::natural_big >( alphaValue >> 8 ).and( 0xf ) ) ); // third hexadecimal digit (digit number 2)
		_indexOfFile = QUANTITY_OF_FILES_PER_APLHA * fileRange + ::jmsf::osie::runup::extractBitField( packedSingleRequestData, NUMBER_OF_FILE_SHIFT, NUMBER_OF_FILE_MASK );
	}

	_dataPosition =
		( ::jmsf::osie::runup::extractBitField( packedSingleRequestData, DATA_BLOCK_SHIFT, DATA_BLOCK_MASK ) << DATA_BLOCK_POINTER_SHIFT ) +
		( ::jmsf::osie::runup::extractBitField( packedSingleRequestData, DATA_POSITION_SHIFT, DATA_POSITION_MASK ) << DATA_POSITION_POINTER_SHIFT );

	//_actualIndexOfDrive = runup::extractBitField( packedSingleRequestData, FILE_NUMBER_SHIFT, FILE_NUMBER_MASK ) >> 11; // / 2048
	const VirtualFileTable &virtualFileTable = Configuration::instance()->getVirtualFileTable();

	_actualIndexOfDrive = _indexOfFile < virtualFileTable.getQuantity() ? virtualFileTable.getElement( static_cast< ::jmsf::natural_size >( _indexOfFile ) ).getIndexOfDrive() : ~::jmsf::natural_size( 0 );

	_shiftedXorValueBitandXOR_CODE_MASK = ::jmsf::Bitwise< ::jmsf::natural_big >( shiftedXorValue ).and( XOR_CODE_MASK );
	_shiftedXorValueBitandNotXOR_CODE_MASK = ::jmsf::Bitwise< ::jmsf::natural_big >( shiftedXorValue ).and( ~XOR_CODE_MASK );

// 	_actualIndexOfDrive_old = runup::extractBitField( packedSingleRequestData, size_natural( 27 ), big_natural( 0x3FFF ) ) >> 11; // / 2048
// 	{
// 		_fileRange = runup::integralLog2( alphaValue >> 8 bitand 0xf ); // third hexadecimal digit (digit number 2)
// 		_indexOfFile_old = 16384 * _fileRange + runup::extractBitField( packedSingleRequestData, size_natural( 27 ), big_natural( 0x3FFF ) );
// 		_numberOfFile_old = runup::extractBitField( packedSingleRequestData, size_natural( 27 ), big_natural( 0x3FFF ) );
// 	}
// 	
// 	_dataPosition_old = runup::extractBitField( packedSingleRequestData, size_natural( 2 ), big_natural( 0x1FFFFF0 ) ) << 3;
}

::jmsf::natural_size SingleRequestData::getOrdinalNumberOfGroup() const throw() {
	return _ordinalNumberOfGroup;
}

::jmsf::natural_size SingleRequestData::getActuaIndexOfDrive() const throw() {
	return static_cast< ::jmsf::natural_size >( _actualIndexOfDrive );
}

// big_natural SingleRequestData::getNumberOfDrive() const throw() {	
// 	return runup::extractBitField( _packedSingleRequestData, DRIVE_NUMBER_SHIFT, DRIVE_NUMBER_MASK );
// }

::jmsf::natural_size SingleRequestData::getIndexOfFile() const throw() {
	return static_cast< ::jmsf::natural_size >( _indexOfFile );
}

::jmsf::natural_big SingleRequestData::getDataPosition() const throw() {
	return _dataPosition;
}

::jmsf::natural_big SingleRequestData::getCorrectedData( const ::jmsf::natural_big packedSingleRequestData ) const throw() {
	return ::jmsf::Bitwise< ::jmsf::natural_big >( packedSingleRequestData ).and( LENGTH_ERASE_MASK ).or( _shiftedXorValueBitandNotXOR_CODE_MASK );
}

::jmsf::Boolean SingleRequestData::doesXorValuesMatch( const ::jmsf::natural_big packedSingleRequestData ) const throw() {
	return ( _shiftedXorValueBitandXOR_CODE_MASK ) == ::jmsf::osie::runup::extractBitField( packedSingleRequestData, XOR_CODE_SHIFT, XOR_CODE_MASK );
}

::jmsf::Boolean SingleRequestData::operator <( const SingleRequestData &other ) const throw() {
	if ( getIndexOfFile() < other.getIndexOfFile() ) {
		return true;
	} else if ( getIndexOfFile() > other.getIndexOfFile() ) {
		return false;
	}

	if ( getDataPosition() < other.getDataPosition() ) {
		return true;
	} else if ( getDataPosition() > other.getDataPosition() ) {
		return false;
	}

	return false;
}


} // namespace
}
