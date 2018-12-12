#include "jmsf/researching/File_system.h"
#include "jmsf/researching/Operating_system.h"

#include "jmsf/stdal/stdal_stl.h"


const std::string project_extension_constant = "vcxproj";
const std::string filters_extension_constant = "filters";

const std::string tabulation_constant = "  ";

const std::string output_file_header_constant = "<?xml version=\"1.0\" encoding=\"utf-8\"?>";
const std::string project_open_tag_constant = "<Project DefaultTargets=\"Build\" ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">";
const std::string filters_project_open_tag_constant = "<Project ToolsVersion=\"4.0\"\nxmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">";
const std::string output_file_close_tag_constant = "</Project>";

const std::string open_tag_end_constant = "\">";
const std::string open_tag_close_constant = "\" />";

const std::string item_group_open_tag_constant = "<ItemGroup>";
const std::string item_group_close_tag_constant = "</ItemGroup>";

const std::string filters_open_tag_constant = "<Filter>";
const std::string filters_include_open_tag_start_constant = "<Filter Include=\"";
const std::string filters_close_tag_constant = "</Filter>";

const std::string unique_identifier_open_tag_constant = "<UniqueIdentifier>{";
const std::string unique_identifier_close_tag_constant = "}</UniqueIdentifier>";

const std::string include_include_open_tag_start_constant = "<ClInclude Include=\"";
const std::string include_include_close_tag_constant = "</ClInclude>";

const std::string compile_include_open_tag_start_constant = "<ClCompile Include=\"";
const std::string compile_include_close_tag_constant = "</ClCompile>";

const std::string none_include_open_tag_start_constant = "<None Include=\"";
const std::string none_include_close_tag_constant = "</None>";

std::vector< const std::string > extensions_for_include;
std::vector< const std::string > extensions_for_source;
std::vector< const std::string > extensions_for_none;


class File_data {

public:
	File_data( const std::string &a_path, const std::string &a_name, const std::string &an_extension ) noexept
		:
			_path( a_path ),
			_name( a_name ),
			_extension( an_extension )
	{}

	const std::string &get_path() const noexept { return _path; }
	const std::string &get_name() const noexept { return _name; }
	const std::string &get_extension() const noexept { return _extension; }

private:
	std::string _path;
	std::string _name;
	std::string _extension;

};


void showUsagePrompt() {
	std::cout << "Usage: Main_source_tree output_filename input_directory root_source additional_directory_list" << std::endl;
}

template< class Input_iterator, class Iterator_to_find >
Input_iterator multi_find( const Input_iterator &first_iterator, const Input_iterator &last_iterator, const Iterator_to_find &first_iterator_to_find, const Iterator_to_find &last_iterator_to_find ) {
	Iterator_to_find iterator_to_find = first_iterator_to_find;

	while ( first_iterator_to_find != last_iterator_to_find ) {
		Input_iterator find_iterator = std::find( first_iterator, last_iterator, *iterator_to_find );

		if ( find_iterator != last_iterator ) return find_iterator;

		iterator_to_find += 1;
	}
	
	return last_iterator;
}

void initialize_extension_lists() {
	extensions_for_include.push_back( "h" );
	extensions_for_include.push_back( "hxx" );
	extensions_for_include.push_back( "hpp" );
	extensions_for_include.push_back( "hh" );

	extensions_for_source.push_back( "c" );
	extensions_for_source.push_back( "cxx" );
	extensions_for_source.push_back( "cpp" );
	extensions_for_source.push_back( "cc" );

	extensions_for_none.push_back( "inl" );
	extensions_for_none.push_back( "inc" );
}

class Command_line_parameters {

public:
	Command_line_parameters() noexept {}

	Command_line_parameters(
		const std::string &file_base_name,
		const std::string &starting_directory_name,
		const std::string &starting_directory_parent_path,
		const std::string &middle_directory_list_filename ) noexept
		:
			_file_base_name( file_base_name ),
			_starting_directory_name( starting_directory_name ),
			_starting_directory_parent_path( starting_directory_parent_path ),
			_middle_directory_list_filename( middle_directory_list_filename )
	{}

	const std::string &get_file_base_name() const noexept { return _file_base_name; }
	const std::string &get_starting_directory_name() const noexept { return _starting_directory_name; }
	const std::string &get_starting_directory_parent_path() const noexept { return _starting_directory_parent_path; }
	const std::string &get_middle_directory_list_filename() const noexept { return _middle_directory_list_filename; }

private:
	std::string _file_base_name;
	std::string _starting_directory_name;
	std::string _starting_directory_parent_path;
	std::string _middle_directory_list_filename;
};

bool parse_command_line_parameters(
	Command_line_parameters *output_command_line_values,
	const int quantity_of_arguments,
	const char *arguments[] )
{
	if ( output_command_line_values == nullptr ) {
		std::cout << "Empty first argument of function: bool parse_command_line_parameters( ... )" << std::endl;
		return false;
	}

	if ( quantity_of_arguments < 4 ) {
		std::cout << "Too few arguments" << std::endl;
		return false;
	}

	const std::string file_base_name = arguments[ 1 ];
	const std::string starting_directory_name = arguments[ 2 ];
	const std::string starting_directory_parent_path = arguments[ 3 ];
	const std::string middle_directory_list_filename = quantity_of_arguments == 5 ? arguments[ 4 ] : std::string();

	if ( file_base_name.empty() ) {
		std::cout << "Empty file base name" << std::endl;
		return false;
	}

	if ( starting_directory_name.empty() ) {
		std::cout << "Empty starting directory name" << std::endl;
		return false;
	}

	if ( starting_directory_parent_path.empty() ) { 
		std::cout << "Empty starting directory parent path" << std::endl;
		return false;
	}

	*output_command_line_values =
		Command_line_parameters(
			file_base_name,
			starting_directory_name,
			jmsf::researching::File_system::replace_all(
				jmsf::researching::File_system::path_separator_constant,
				jmsf::researching::File_system::backward_path_separator_constant,
				starting_directory_parent_path ),
			middle_directory_list_filename );

	return true;
}

void read_middle_directory_list( std::vector< const std::string > *output_middle_directory_list, const std::string &middle_directory_list_filename ) {
	if ( output_middle_directory_list == nullptr || middle_directory_list_filename.empty() ) return;

	std::ifstream middle_directory_list_file( middle_directory_list_filename.c_str() );

	if ( !middle_directory_list_file.is_open() ) {
		std::cout << "Can't open additional directory list file: " << middle_directory_list_filename << std::endl;
		return;
	}

	const size_t getline_buffer_size = 512;
	char getline_buffer[ getline_buffer_size ];

	do {
		getline_buffer[ 0 ] = '\0';
		middle_directory_list_file.getline( &getline_buffer[ 0 ], getline_buffer_size );

		if ( getline_buffer[ 0 ] != '\0' ) {
			output_middle_directory_list->push_back( std::string( getline_buffer ) );
		}
	} while ( middle_directory_list_file.good() );
}

bool read_files_and_directories(
	std::vector< const std::string > *output_files,
	std::vector< const std::string > *output_directories,
	const std::vector< const std::string > &middle_directories,
	const std::string &starting_directory_name )
{
	if ( output_files == nullptr && output_directories == nullptr ) {
		std::cout << "Both first and second parameters of \"bool read_files_and_directories( ... )\" are empty" << std::endl;
		return false;
	}

	std::vector< const std::string > vector_of_files;
	std::vector< const std::string > vector_of_directories;

	if (
		!jmsf::researching::File_system::create_list_of_files_and_directories(
			&vector_of_files,
			&vector_of_directories,
			starting_directory_name, 
			jmsf::researching::File_system::backward_path_separator_constant ) )
	{
		std::cout << "Can't read directory: " << starting_directory_name << std::endl;
		return false;
	}

	const std::string middle_path = middle_directories.empty() ? std::string() : middle_directories.back();

	if ( output_directories != nullptr ) {
		for (
			std::vector< const std::string >::const_iterator middle_directory_iterator = middle_directories.begin();
			middle_directory_iterator != middle_directories.end();
			middle_directory_iterator += 1 )
		{
			output_directories->push_back( *middle_directory_iterator );
		}

		output_directories->push_back( ( middle_path.empty() ? std::string() : middle_path + jmsf::researching::File_system::backward_path_separator_constant ) + starting_directory_name );

		for (
			std::vector< const std::string >::const_iterator directory_iterator = vector_of_directories.begin();
			directory_iterator != vector_of_directories.end();
			directory_iterator += 1 )
		{
			output_directories->push_back( ( middle_path.empty() ? std::string() : middle_path + jmsf::researching::File_system::backward_path_separator_constant ) + *directory_iterator );
		}
	}

	if ( output_files != nullptr ) {
		for (
			std::vector< const std::string >::const_iterator file_iterator = vector_of_files.begin();
			file_iterator != vector_of_files.end();
			file_iterator += 1 )
		{
			output_files->push_back( ( middle_path.empty() ? std::string() : middle_path + jmsf::researching::File_system::backward_path_separator_constant ) + *file_iterator );
		}
	}

	return true;
}

bool log_files_and_directories(
	const std::string &file_base_name,
	const std::vector< const std::string > &files,
	const std::vector< const std::string > &directories )
{
	const std::string directory_list_filename = file_base_name + ".directories.txt";
	const std::string file_list_filename = file_base_name + ".files.txt";

	{
		std::ofstream directory_list_file( directory_list_filename.c_str() );

		if ( !directory_list_file.is_open() ) {
			std::cout << "Can't create project file: " << directory_list_filename << std::endl;
			return false;
		}

		for (
			std::vector< const std::string >::const_iterator directory_iterator = directories.begin();
			directory_iterator != directories.end();
			directory_iterator += 1 )
		{
			directory_list_file << *directory_iterator << std::endl;
		}
	}

	{
		std::ofstream file_list_file( file_list_filename.c_str() );

		if ( !file_list_file.is_open() ) {
			std::cout << "Can't create filters file: " << file_list_filename << std::endl;
			return false;
		}

		for (
			std::vector< const std::string >::const_iterator file_iterator = files.begin();
			file_iterator != files.end();
			file_iterator += 1 )
		{
			file_list_file << *file_iterator << std::endl;
		}
	}

	return true;
}

void sort_files_by_extension(
	std::list< const File_data > *output_headers,
	std::list< const File_data > *output_sources,
	std::list< const File_data > *output_none,
	std::list< const File_data > *output_ubsent,
	const std::vector< const std::string > &files )
{
	initialize_extension_lists();

	for (
		std::vector< const std::string >::const_iterator file_iterator = files.begin();
		file_iterator != files.end();
		file_iterator += 1 )
	{
		std::string the_path;
		std::string the_name;
		std::string the_extension;

		jmsf::researching::File_system::separate_name_extension_and_path(
			&the_path,
			&the_name,
			&the_extension,
			*file_iterator,
			jmsf::researching::File_system::backward_path_separator_constant );

		if ( the_extension.empty() || std::find( extensions_for_include.begin(), extensions_for_include.end(), the_extension ) != extensions_for_include.end() ) {
			if ( output_headers != nullptr ) {
				output_headers->push_back( File_data( the_path, the_name, the_extension ) );
			}
		} else if ( std::find( extensions_for_source.begin(), extensions_for_source.end(), the_extension ) != extensions_for_source.end() ) {
			if ( output_sources != nullptr ) {
				output_sources->push_back( File_data( the_path, the_name, the_extension ) );
			}
		} else if ( std::find( extensions_for_none.begin(), extensions_for_none.end(), the_extension ) != extensions_for_none.end() ) {
			if ( output_none != nullptr ) {
				output_none->push_back( File_data( the_path, the_name, the_extension ) );
			}
		} else {
			if ( output_ubsent != nullptr ) {
				output_ubsent->push_back( File_data( the_path, the_name, the_extension ) );
			}
		}
	}
}

void create_project_file_group(
	std::ofstream *output_project_file,
	const Command_line_parameters &command_line_values,
	const std::list< const File_data > &files,
	const std::string &open_tag_start_constant )
{
	if ( output_project_file == nullptr ) return;

	*output_project_file << tabulation_constant;
	*output_project_file << item_group_open_tag_constant << std::endl;

	for (
		std::list< const File_data >::const_iterator file_data_iterator = files.begin();
		file_data_iterator != files.end();
		++file_data_iterator )
	{
		*output_project_file << tabulation_constant + tabulation_constant;
		*output_project_file << open_tag_start_constant;
		*output_project_file << command_line_values.get_starting_directory_parent_path() << jmsf::researching::File_system::backward_path_separator_constant;
		*output_project_file << file_data_iterator->get_path() << jmsf::researching::File_system::backward_path_separator_constant;
		*output_project_file << file_data_iterator->get_name() << jmsf::researching::File_system::extension_separator_constant;
		*output_project_file << file_data_iterator->get_extension();
		*output_project_file << open_tag_close_constant << std::endl;
	}

	*output_project_file << tabulation_constant;
	*output_project_file << item_group_close_tag_constant << std::endl;
}

bool create_project_file(
	const Command_line_parameters &command_line_values,
	const std::list< const File_data > &header_files,
	const std::list< const File_data > &source_files,
	const std::list< const File_data > &none_files )
{
	const std::string project_filename = command_line_values.get_file_base_name() + jmsf::researching::File_system::extension_separator_constant + project_extension_constant;
	std::ofstream project_file( project_filename.c_str() );

	if ( !project_file.is_open() ) {
		std::cout << "Can't open project file: " << project_filename << std::endl;
		return false;
	}

	project_file << output_file_header_constant << std::endl;
	project_file << project_open_tag_constant << std::endl;

	create_project_file_group( &project_file, command_line_values, header_files, include_include_open_tag_start_constant );
	create_project_file_group( &project_file, command_line_values, source_files, compile_include_open_tag_start_constant );
	create_project_file_group( &project_file, command_line_values, none_files, none_include_open_tag_start_constant );

	project_file << output_file_close_tag_constant << std::endl;

	return true;
}

void create_filters_directory_group(
	std::ofstream *output_filters_file,
	const std::vector< const std::string > &directories )
{
	if ( output_filters_file == nullptr ) return;

	*output_filters_file << tabulation_constant;
	*output_filters_file << item_group_open_tag_constant << std::endl;


	for (
		std::vector< const std::string >::const_iterator directory_iterator = directories.begin();
		directory_iterator != directories.end();
		directory_iterator += 1 )
	{
		*output_filters_file << tabulation_constant + tabulation_constant;
		*output_filters_file << filters_include_open_tag_start_constant;
		*output_filters_file << *directory_iterator;
		*output_filters_file << open_tag_end_constant << std::endl;

		*output_filters_file << tabulation_constant + tabulation_constant + tabulation_constant;
		*output_filters_file << unique_identifier_open_tag_constant;
		*output_filters_file << jmsf::researching::Operating_system::generate_UUID();
		*output_filters_file << unique_identifier_close_tag_constant << std::endl;

		*output_filters_file << tabulation_constant + tabulation_constant;
		*output_filters_file << filters_close_tag_constant << std::endl;
	}

	*output_filters_file << tabulation_constant;
	*output_filters_file << item_group_close_tag_constant << std::endl;
}

void create_filters_file_group(
	std::ofstream *output_filters_file,
	const Command_line_parameters &command_line_values,
	const std::vector< const std::string > &directories,
	const std::list< const File_data > &files,
	const std::string &inlcude_open_tag_start_constant,
	const std::string &include_close_tag_constant )
{
	if ( output_filters_file == nullptr ) return;

	*output_filters_file << tabulation_constant;
	*output_filters_file << item_group_open_tag_constant << std::endl;

	for (
		std::vector< const std::string >::const_iterator directory_iterator = directories.begin();
		directory_iterator != directories.end();
		directory_iterator += 1 )
	{
		for (
			std::list< const File_data >::const_iterator file_data_iterator = files.begin();
			file_data_iterator != files.end();
			++file_data_iterator )
		{
			if ( file_data_iterator->get_path() == *directory_iterator ) {
				*output_filters_file << tabulation_constant + tabulation_constant;
				*output_filters_file << inlcude_open_tag_start_constant;

				*output_filters_file << command_line_values.get_starting_directory_parent_path() << jmsf::researching::File_system::backward_path_separator_constant;
				*output_filters_file << file_data_iterator->get_path() << jmsf::researching::File_system::backward_path_separator_constant;
				*output_filters_file << file_data_iterator->get_name() << jmsf::researching::File_system::extension_separator_constant;
				*output_filters_file << file_data_iterator->get_extension();
				*output_filters_file << open_tag_end_constant << std::endl;

				*output_filters_file << tabulation_constant + tabulation_constant + tabulation_constant;
				*output_filters_file << filters_open_tag_constant;
				*output_filters_file << *directory_iterator;
				*output_filters_file << filters_close_tag_constant << std::endl;

				*output_filters_file << tabulation_constant + tabulation_constant;
				*output_filters_file << include_close_tag_constant << std::endl;
			}
		}
	}

	*output_filters_file << tabulation_constant;
	*output_filters_file << item_group_close_tag_constant << std::endl;
}

bool create_filters_file(
	const Command_line_parameters &command_line_values,
	const std::vector< const std::string > &directories,
	const std::list< const File_data > &header_files,
	const std::list< const File_data > &source_files,
	const std::list< const File_data > &none_files )
{
	const std::string filters_filename =
		command_line_values.get_file_base_name() + jmsf::researching::File_system::extension_separator_constant +
		project_extension_constant + jmsf::researching::File_system::extension_separator_constant +
		filters_extension_constant;

	std::ofstream filters_file( filters_filename.c_str() );

	if ( !filters_file.is_open() ) {
		std::cout << "Can't open filters file: " << filters_filename << std::endl;
		return false;
	}

	filters_file << output_file_header_constant << std::endl;
	filters_file << filters_project_open_tag_constant << std::endl;

	create_filters_directory_group( &filters_file, directories );

	create_filters_file_group( &filters_file, command_line_values, directories, header_files, include_include_open_tag_start_constant, include_include_close_tag_constant );
	create_filters_file_group( &filters_file, command_line_values, directories, source_files, compile_include_open_tag_start_constant, compile_include_close_tag_constant );
	create_filters_file_group( &filters_file, command_line_values, directories, none_files, none_include_open_tag_start_constant, none_include_close_tag_constant );

	filters_file << output_file_close_tag_constant << std::endl;

	return true;
}

int main( const int quantity_of_arguments, const char *arguments[] ) {
	Command_line_parameters command_line_values;

	if ( !parse_command_line_parameters( &command_line_values, quantity_of_arguments, arguments ) ) {
		showUsagePrompt();
		return -1;
	}
	
	// create list of files and
	std::vector< const std::string > vector_of_middle_directories;
	read_middle_directory_list( &vector_of_middle_directories, command_line_values.get_middle_directory_list_filename() );

	std::vector< const std::string > vector_of_files;
	std::vector< const std::string > vector_of_directories;

	if ( !read_files_and_directories( &vector_of_files, &vector_of_directories, vector_of_middle_directories, command_line_values.get_starting_directory_name() ) ) {
		return -1;
	}

	if ( !log_files_and_directories( command_line_values.get_file_base_name(), vector_of_files, vector_of_directories ) ) {
		return -1;
	}

	std::list< const File_data > list_of_header_file_data;
	std::list< const File_data > list_of_source_file_data;
	std::list< const File_data > list_of_none_file_data;
	std::list< const File_data > list_of_ubsent_file_data;	

	sort_files_by_extension( &list_of_header_file_data, &list_of_source_file_data, &list_of_none_file_data, &list_of_ubsent_file_data, vector_of_files );

	if ( !create_project_file( command_line_values, list_of_header_file_data, list_of_source_file_data, list_of_none_file_data ) ) {
		std::cout << "Can't create project file" << std::endl;
		return -1;
	}

	if ( !create_filters_file( command_line_values, vector_of_directories, list_of_header_file_data, list_of_source_file_data, list_of_none_file_data ) ) {
		std::cout << "Can't create filters file" << std::endl;
		return -1;
	}

	const std::string ubsent_extension_filename = command_line_values.get_file_base_name() + jmsf::researching::File_system::extension_separator_constant + "ubsent.txt";
	std::ofstream ubsent_extension_file( ubsent_extension_filename.c_str() );

	if ( ubsent_extension_file.is_open() ) {
		for (
			std::list< const File_data >::const_iterator file_data_iterator = list_of_ubsent_file_data.begin();
			file_data_iterator != list_of_ubsent_file_data.end();
			++file_data_iterator )
		{
			ubsent_extension_file << command_line_values.get_starting_directory_parent_path() << jmsf::researching::File_system::backward_path_separator_constant;
			ubsent_extension_file << file_data_iterator->get_path() << jmsf::researching::File_system::backward_path_separator_constant;
			ubsent_extension_file << file_data_iterator->get_name() << jmsf::researching::File_system::extension_separator_constant;
			ubsent_extension_file << file_data_iterator->get_extension() << std::endl;			
		}
	}	

	return 0;
}

