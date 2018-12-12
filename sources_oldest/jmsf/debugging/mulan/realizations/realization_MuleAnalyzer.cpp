#include "realization_MuleAnalyzer.h"
#include "MulanObjectCreationInformation.h"
#include "MulanObjectDeletionInformation.h"
#include "MulanArrayCreationInformation.h"
#include "MulanArrayDeletionInformation.h"
#include "jmsf/data_structures/Buffer.hpp"
// #include "jmsf/factory_TextObject.h"
// #include "jmsf/TextString.h"
#include "jmsf/Container.hpp"
#include "jmsf/Iterators.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Should.h"
#include "jmsf/stdal/stdal_stl.h"
#include "jmsf/osie/ms_windows/ms_windows_include.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

Boolean realization_MuleAnalyzer::readCollectedData() throw() {
	const natural_size maximumInputStringLineSize = 256;
	const char_type endOfLineCharacter = '\n';
	const char_type tabulationCharacter = '\t';
	data_structures::CharTypeBuffer inputStringBuffer( maximumInputStringLineSize, True );

	// read ObjectCreationInformationLog
	{
		std::ifstream objectCreationDataFile( "ObjectCreationLog.txt" );

		if ( objectCreationDataFile.is_open() ) {		
			// skip heading
			{		
				objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );
				inputStringBuffer.clear();
			}

			while ( Boolean( objectCreationDataFile.eof() ).not() ) {
				natural_size addressOfObject = 0;
				{
					objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectCreationDataFile.fail() ) break;

//					const std::string addressOfObjectString;
					std::stringstream stringStream;
					stringStream << inputStringBuffer;
					stringStream >> addressOfObject;
				}

				std::string nameOfClass;
				{
					objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectCreationDataFile.fail() ) break;

					nameOfClass = inputStringBuffer;
				}

				natural_size sizeOfObject = 0;
				{
					objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;
					stringStream >> sizeOfObject;
				}

				std::string pathToFile;
				{
					objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectCreationDataFile.fail() ) break;

					pathToFile = inputStringBuffer;
				}

				natural_size numberOfLine = 0;
				{
					objectCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );

					if ( objectCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;
					stringStream >> numberOfLine;
				}

				_objectCreationContainer->appendBack(
					Pointer< MulanObjectCreationInformation >::createUnique(
						new MulanObjectCreationInformation( addressOfObject, nameOfClass, sizeOfObject, pathToFile, numberOfLine ) ) );
			}
		}
	}

	// read ObjectDeletionInformationLog
	{
		std::ifstream objectDeletionDataFile( "ObjectDeletionLog.txt" );

		if ( objectDeletionDataFile.is_open() ) {		
			// skip heading
			{		
				objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );
				inputStringBuffer.clear();
			}

			while ( Boolean( objectDeletionDataFile.eof() ).not() ) {
				natural_size addressOfObject;
				{
					objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> addressOfObject;
				}

				std::string nameOfClass;
				{
					objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectDeletionDataFile.fail() ) break;

					nameOfClass = inputStringBuffer;
				}

				natural_size sizeOfObject;
				{
					objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> sizeOfObject;
				}

				std::string pathToFile;
				{
					objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( objectDeletionDataFile.fail() ) break;

					pathToFile = inputStringBuffer;
				}

				natural_size numberOfLine;
				{
					objectDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );

					if ( objectDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> numberOfLine;
				}

				_objectDeletionContainer->appendBack(
					Pointer< MulanObjectDeletionInformation >::createUnique(
						new MulanObjectDeletionInformation( addressOfObject, nameOfClass, sizeOfObject, pathToFile, numberOfLine ) ) );
			}
		}
	}

	// read ArrayCreationInformationLog
	{
		std::ifstream arrayCreationDataFile( "ArrayCreationLog.txt" );

		if ( arrayCreationDataFile.is_open() ) {		
			// skip heading
			{		
				arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );
				inputStringBuffer.clear();
			}

			while ( Boolean( arrayCreationDataFile.eof() ).not() ) {
				natural_size addressOfObject;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> addressOfObject;
				}

				std::string nameOfClass;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					nameOfClass = inputStringBuffer;
				}

				natural_size sizeOfObject;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> sizeOfObject;
				}

				natural_size quantityOfObjects;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> quantityOfObjects;
				}

				std::string pathToFile;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					pathToFile = inputStringBuffer;
				}

				natural_size numberOfLine;
				{
					arrayCreationDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );

					if ( arrayCreationDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> numberOfLine;
				}

				_arrayCreationContainer->appendBack(
					Pointer< MulanArrayCreationInformation >::createUnique(
						new MulanArrayCreationInformation( addressOfObject, nameOfClass, sizeOfObject, quantityOfObjects, pathToFile, numberOfLine ) ) );
			}
		}
	}

	// read ArrayDeletionInformationLog
	{
		std::ifstream arrayDeletionDataFile( "ArrayDeletionLog.txt" );

		if ( arrayDeletionDataFile.is_open() ) {		
			// skip heading
			{		
				arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );
				inputStringBuffer.clear();
			}

			while ( Boolean( arrayDeletionDataFile.eof() ).not() ) {
				natural_size addressOfObject;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> addressOfObject;
				}

				std::string nameOfClass;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					nameOfClass = inputStringBuffer;
				}

				natural_size sizeOfObject;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> sizeOfObject;
				}

				natural_size quantityOfObjects;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> quantityOfObjects;
				}

				std::string pathToFile;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, tabulationCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					pathToFile = inputStringBuffer;
				}

				natural_size numberOfLine;
				{
					arrayDeletionDataFile.getline( inputStringBuffer, maximumInputStringLineSize - 1, endOfLineCharacter );

					if ( arrayDeletionDataFile.fail() ) break;

					std::stringstream stringStream;
					stringStream << inputStringBuffer;		
					stringStream >> numberOfLine;
				}

				_arrayDeletionContainer->appendBack(
					Pointer< MulanArrayDeletionInformation >::createUnique(
						new MulanArrayDeletionInformation( addressOfObject, nameOfClass, sizeOfObject, quantityOfObjects, pathToFile, numberOfLine ) ) );
			}
		}
	}
	return False;
}

void realization_MuleAnalyzer::performAnalysis() throw() {
	// perform object analysis
	{		
		for (
			Proxy< Iterator< Pointer< MulanObjectCreationInformation > > > creationIterator = _objectCreationContainer->createForwardIterator();
			creationIterator->isNotDone();
			creationIterator->advance() )
		{
			const natural_size addressOfCreatedObject = creationIterator->getContainie()->getAddressOfObject();

			for (
				Proxy< Iterator< Pointer< MulanObjectDeletionInformation > > > deletionIterator = _objectDeletionContainer->createForwardIterator();
				deletionIterator->isNotDone();
				deletionIterator->advance() )
			{
				if ( deletionIterator->getContainie()->getAddressOfObject() == addressOfCreatedObject ) {
					creationIterator->erase();
					deletionIterator->erase();
					break;
				}
			}
		}
	}

	// perform array analysis
	{		
		for (
			Proxy< Iterator< Pointer< MulanArrayCreationInformation > > > creationIterator = _arrayCreationContainer->createForwardIterator();
			creationIterator->isNotDone();
			creationIterator->advance() )
		{
			const natural_size addressOfCreatedArray = creationIterator->getContainie()->getAddressOfObject();

			for (
				Proxy< Iterator< Pointer< MulanArrayDeletionInformation > > > deletionIterator = _arrayDeletionContainer->createForwardIterator();
				deletionIterator->isNotDone();
				deletionIterator->advance() )
			{
				if ( deletionIterator->getContainie()->getAddressOfObject() == addressOfCreatedArray ) {
					creationIterator->erase();
					deletionIterator->erase();
					break;
				}
			}
		}
	}
}

void realization_MuleAnalyzer::showResults() const throw() {
	::OutputDebugStringA( "Memory Using Leak Analyzer - " );

	if ( _objectCreationContainer->isEmpty().and( _arrayCreationContainer->isEmpty() ) ) {
		::OutputDebugStringA( "No memory leak detected\n" );
	} else {
		::OutputDebugStringA( "Memory leak(s) detected:\n" );
	}

	// show results for objects
	{
		natural_size objectLeakCounter = 0;

		for (
			Proxy< ConstantIterator< Pointer< MulanObjectCreationInformation > > > creationIterator = _objectCreationContainer->createConstantForwardIterator();
			creationIterator->isNotDone();
			creationIterator->advance() )
		{
			std::stringstream stringStream;
			stringStream << objectLeakCounter << "> ";
			stringStream << creationIterator->getContainie()->getPathToFile() << "( " << creationIterator->getContainie()->getNumberOfLine() << " ) : ";
			stringStream << std::setbase( 16 ) << std::setw( sizeof( natural_size ) * 2 ) << std::setfill( '0' ) << creationIterator->getContainie()->getAddressOfObject() << "; ";
			stringStream << creationIterator->getContainie()->getNameOfClass() << "; size is ";
			stringStream << std::setbase( 10 ) << creationIterator->getContainie()->getSizeOfObject() << std::endl;
			::OutputDebugStringA( stringStream.str().c_str() );
			objectLeakCounter += 1;
		}
	}
	
	// show results for arrays
	{
		natural_size arrayLeakCounter = 0;

		for (
			Proxy< ConstantIterator< Pointer< MulanArrayCreationInformation > > > creationIterator = _arrayCreationContainer->createConstantForwardIterator();
			creationIterator->isNotDone();
			creationIterator->advance() )
		{
			std::stringstream stringStream;
			stringStream << arrayLeakCounter << "> ";		
			stringStream << creationIterator->getContainie()->getPathToFile() << "( " << creationIterator->getContainie()->getNumberOfLine() << " ) : ";
			stringStream << std::setbase( 16 ) << std::setw( sizeof( natural_size ) * 2 ) << std::setfill( '0' ) << creationIterator->getContainie()->getAddressOfObject() << "; ";
			stringStream << creationIterator->getContainie()->getNameOfClass() << "; size is ";
			stringStream << std::setbase( 10 ) << creationIterator->getContainie()->getSizeOfObject() << "; quantity is ";
			stringStream << creationIterator->getContainie()->getSizeOfObject() << std::endl;
			::OutputDebugStringA( stringStream.str().c_str() );
			arrayLeakCounter += 1;
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_MuleAnalyzer::~realization_MuleAnalyzer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_MuleAnalyzer::realization_MuleAnalyzer(
	const Proxy< Container< Pointer< MulanObjectCreationInformation > > > &objectCreationContainer,
	const Proxy< Container< Pointer< MulanObjectDeletionInformation > > > &objectDeletionContainer,
	const Proxy< Container< Pointer< MulanArrayCreationInformation > > > &arrayCreationContainer,
	const Proxy< Container< Pointer< MulanArrayDeletionInformation > > > &arrayDeletionContainer ) throw()
	:
		_objectCreationContainer( objectCreationContainer ),
		_objectDeletionContainer( objectDeletionContainer ),
		_arrayCreationContainer( arrayCreationContainer ),
		_arrayDeletionContainer( arrayDeletionContainer )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Proxy< MuleAnalyzer > realization_MuleAnalyzer::createClone() const throw() {
	return Proxy< MuleAnalyzer >::createUnique( new realization_MuleAnalyzer( *this ) );
}

realization_MuleAnalyzer::realization_MuleAnalyzer( const realization_MuleAnalyzer & ) throw() // other
{}

const realization_MuleAnalyzer &realization_MuleAnalyzer::operator =( const realization_MuleAnalyzer &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	Should::neverViolateCopyingProhibition( "realization_MuleAnalyzer::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf