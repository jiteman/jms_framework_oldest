#include "jmsf/researching/File_system.h"

#include "jmsf/stdal/stdal_stl.h"


const char HEADER_TERMINATOR = ':';
const char ENTRY_END_MARK = char( 0x0C );
const std::string EXTENSION = "tpl";


void showUsagePrompt() {
	std::cout << "Usage programName fileName outputFolder" << std::endl;
}

int main( const int quantityOfArguments, const char *arguments[] ) {
	if ( quantityOfArguments != 3 ) {
		showUsagePrompt();
		return -1;
	}

	const std::string fileName = arguments[ 1 ];
	const std::string folderName = arguments[ 2 ];

	if ( fileName.empty() ) {
		std::cout << "Empty filename" << std::endl;
		showUsagePrompt();
		return -1;
	}

	if ( folderName.empty() ) {
		std::cout << "Empty folder name" << std::endl;
		showUsagePrompt();
		return -1;
	}

	std::ifstream inputFile( fileName.c_str(), std::ios_base::binary );

	if ( !inputFile.is_open() ) {
		std::cout << "Can't open file: " << fileName << std::endl;
		return -1;
	}

	const size_t fileSize = jmsf::researching::File_system::get_size_of_file( fileName );

	if ( fileSize == jmsf::researching::File_system::WRONG_SIZE ) return -1;

	std::vector< char > fileVector( fileSize + 1 );

	if ( fileVector.size() - 1 == 0 ) {
		return -1;
	}

	std::cout << "Found file: " << fileName << ", with size: " << fileVector.size() << std::endl;

	if ( !inputFile.read( &fileVector[ 0 ], fileVector.size() - 1 ).good() ) {
		std::cout << "Can't read the whole file: " << fileName << std::endl;
		return -1;
	}

	inputFile.close();

	size_t entryCounter = 0;

	std::vector< char >::const_iterator beginCursor = fileVector.begin();

	std::vector< char >::const_iterator endCursor;
	{
		endCursor = std::find( beginCursor, std::vector< char >::const_iterator( fileVector.end() ), ENTRY_END_MARK );

		if ( endCursor != fileVector.end() ) {
			endCursor += 2;
		}
	}

	while ( beginCursor != fileVector.end() && endCursor != fileVector.end() ) {
		// read next entry
		std::vector< char > singleEntry( beginCursor, endCursor );

		// read header name
		std::string header;
		{
			std::vector< char >::const_iterator beginHeader;
			{
				beginHeader = ( ( beginHeader = std::find( singleEntry.begin(), singleEntry.end(), HEADER_TERMINATOR ) ) == singleEntry.end() ? beginHeader : beginHeader + 1 );
			}

			if ( beginHeader == singleEntry.end() ) {
				std::cout << "Can't find header beginning" << std::endl;
				return -1;
			}

			std::vector< char >::const_iterator endHeader;
			{
				endHeader = std::find( beginHeader, std::vector< char >::const_iterator( singleEntry.end() ), HEADER_TERMINATOR );
			}

			if ( endHeader == singleEntry.end() ) {
				std::cout << "Can't find header end" << std::endl;
			}

			header = std::string( beginHeader, endHeader );
		}

		
		// create file for entry
		std::stringstream entryNumber;
		{
			entryNumber << std::setw( 5 ) << std::setfill( '0' ) << entryCounter << " 000 ";
		}

		const std::string outputFilename = folderName + jmsf::researching::File_system::path_separator_constant + entryNumber.str() + header + jmsf::researching::File_system::extension_separator_constant + EXTENSION;
		std::ofstream outputFile( outputFilename.c_str(), std::ios_base::binary );

		if ( !outputFile.is_open() ) {
			std::cout << "Can't open output file: " << outputFilename << std::endl;
			return -1;
		}

		// save entry in file
		if ( !outputFile.write( &singleEntry[ 0 ], singleEntry.size() ).good() ) {
			std::cout << "Can't write single entry into file: " << outputFilename << std::endl;
		}

		beginCursor = endCursor;
		endCursor = std::find( beginCursor, std::vector< char >::const_iterator( fileVector.end() ), ENTRY_END_MARK );
		
		if ( endCursor != fileVector.end() ) {
			endCursor += 2;
		}

		entryCounter += 1;
	}

	return 0;
}

