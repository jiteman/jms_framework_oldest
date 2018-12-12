#include "jmsf/researching/File_system.h"

#include "jmsf/stdal/stdal_stl.h"


const char HEADER_TERMINATOR = ':';
const char ENTRY_END_MARK = char( 0x0C );
const char PATH_ELEMENT_SEPARATOR = '/';
const char EXTENSION_SEPARATOR = '.';
const std::string EXTENSION = "tpl";


void showUsagePrompt() {
	std::cout << "Usage programName fileName inputFolder" << std::endl;
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

	// read all files in input directories recursively
	std::vector< const std::string > list_of_files;
	
	if (
		!jmsf::researching::File_system::create_list_of_files_and_directories(
			&list_of_files,
			nullptr,
			folderName,
			jmsf::researching::File_system::path_separator_constant ) ) return -1;

	// sort all of files

	std::ofstream outputFile( fileName, std::ios_base::binary );

	if ( !outputFile.is_open() ) {
		std::cout << "Can't open output file: " << fileName << std::endl;
		return -1;
	}

	for (
		std::vector< const std::string >::const_iterator fileIterator = list_of_files.begin();
		fileIterator != list_of_files.end();
		fileIterator += 1 )
	{
		std::ifstream inputFile( fileIterator->c_str(), std::ios_base::binary );

		if ( !inputFile.is_open() ) {
			std::cout << "Can't open input file: " << *fileIterator << std::endl;
			return -1;
		}

		const size_t fileSize = jmsf::researching::File_system::get_size_of_file( *fileIterator );

		if ( fileSize == 0 ) continue;			
		
		std::vector< char > fileContent( fileSize );
		inputFile.read( &fileContent[ 0 ], fileContent.size() );
		outputFile.write( &fileContent[ 0 ], fileContent.size() );
	}

	return 0;
}

