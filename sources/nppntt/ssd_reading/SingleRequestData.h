#pragma once


#include "jmsf/Boolean.h"

#include "jmsf/types.h"


namespace jmsf {
	class Exception;
}


namespace nppntt {
namespace ssd_reading {


class VirtualFileTable;


class SingleRequestData {

	static const ::jmsf::natural_size DRIVE_NUMBER_SHIFT = 37;
	static const ::jmsf::natural_big DRIVE_NUMBER_MASK = 0xF;

	static const ::jmsf::natural_size NUMBER_OF_FILE_SHIFT = 27;
	static const ::jmsf::natural_big NUMBER_OF_FILE_MASK = 0x3FFF;

	static const ::jmsf::natural_size DATA_BLOCK_SHIFT = 0;
	static const ::jmsf::natural_big DATA_BLOCK_MASK = 0;
	static const ::jmsf::natural_size DATA_BLOCK_POINTER_SHIFT = 0;

	static const ::jmsf::natural_size DATA_POSITION_SHIFT = 2;
	static const ::jmsf::natural_big DATA_POSITION_MASK = 0x1FFFFF0;
	static const ::jmsf::natural_size DATA_POSITION_POINTER_SHIFT = 3;

	static const ::jmsf::natural_size XOR_CODE_SHIFT = 50;
	static const ::jmsf::natural_big XOR_CODE_MASK = 0x1FF;

	static const ::jmsf::natural_big QUANTITY_OF_FILES_PER_APLHA = 16384;

	static ::jmsf::natural_big LENGTH_ERASE_MASK;

public:
	static void setLenthEraseMask( ::jmsf::natural_big lengthEraseMask ) throw();
//	static void sort( std::vector< SingleRequestData > &singleRequestDataArray ) throw();

private:
	::jmsf::natural_size _ordinalNumberOfGroup;

	::jmsf::natural_big _actualIndexOfDrive;
	::jmsf::natural_big _indexOfFile;
	::jmsf::natural_big _dataPosition;
	::jmsf::natural_big _shiftedXorValueBitandNotXOR_CODE_MASK;
	::jmsf::natural_big _shiftedXorValueBitandXOR_CODE_MASK;

// 	size_natural _fileRange;
// 	big_natural _actualIndexOfDrive_old;
// 	big_natural _indexOfFile_old;
// 	big_natural _dataPosition_old;	
// 	big_natural _numberOfFile_old;

public:
	~SingleRequestData() throw();
	SingleRequestData() throw();
	SingleRequestData( ::jmsf::natural_size ordinalNumberOfGroup, ::jmsf::natural_big packedSingleRequestData, ::jmsf::natural_big alphaValue, ::jmsf::natural_big shiftedXorValue ) throw( ::jmsf::Exception );

public:
	::jmsf::natural_size getOrdinalNumberOfGroup() const throw();
	::jmsf::natural_size getActuaIndexOfDrive() const throw();
//	big_natural getNumberOfDrive() const throw();
	::jmsf::natural_size getIndexOfFile() const throw();
	::jmsf::natural_big getDataPosition() const throw();

	::jmsf::natural_big getCorrectedData( ::jmsf::natural_big packedSingleRequestData ) const throw();
	::jmsf::Boolean doesXorValuesMatch( ::jmsf::natural_big packedSingleRequestData ) const throw();

	::jmsf::Boolean operator <( const SingleRequestData &other ) const throw();

private:
//	SingleRequestData( const SingleRequestData & ) throw() {}
//	const SingleRequestData &operator =( const SingleRequestData & ) throw() { return *this; }

};


} // namespace
}
