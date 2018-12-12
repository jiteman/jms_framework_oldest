#include "File_system.h"

#include "nullptr_checking_assignment.inl"

#include "temporary_windows_include.h"


namespace jmsf {
namespace researching {


// statics
const std::string File_system::path_separator_constant = "/";
const std::string File_system::backward_path_separator_constant = "\\";
const std::string File_system::extension_separator_constant = ".";
const std::string File_system::current_directory_name_constant = ".";
const std::string File_system::parent_directory_name_constant = "..";
const std::string File_system::any_filename_constant = "*";
const std::string File_system::any_filename_here_constant = File_system::path_separator_constant + File_system::any_filename_constant;
//~statics

// static
bool File_system::create_list_of_files_and_directories(
	std::vector< const std::string > *output_files,
	std::vector< const std::string > *output_directories,
	const std::string &a_path,
	const std::string &path_separator ) noexept
{
	if ( output_files == nullptr && output_directories == nullptr ) return false;

	std::vector< const std::string > list_of_directories;

	if ( !create_directory_listing( output_files, &list_of_directories, a_path, true, true, path_separator ) ) return false;

	for (
		std::vector< const std::string >::const_iterator directory_iterator = list_of_directories.begin();
		directory_iterator != list_of_directories.end();
		directory_iterator += 1 ) 
	{
		if ( output_directories != nullptr ) {
			output_directories->push_back( *directory_iterator );
		}

		if ( !create_list_of_files_and_directories( output_files, output_directories, *directory_iterator, path_separator ) ) return false;
	}

	return true;
}

bool File_system::create_directory_listing(
	std::vector< const std::string > *output_files,
	std::vector< const std::string > *output_directories,
	const std::string &a_path,
	const bool add_full_path_to_filenames,
	const bool add_full_path_to_directory_names,
	const std::string &path_separator ) noexept
{
	if ( output_files == nullptr && output_directories == nullptr ) return false;

	HANDLE file_entry_handle_of_windows;
	WIN32_FIND_DATAA file_entry_data_of_windows;

	if ( ( file_entry_handle_of_windows = ::FindFirstFileA( ( a_path + any_filename_here_constant ).c_str(), &file_entry_data_of_windows ) ) == INVALID_HANDLE_VALUE ) {
		return false;
	}

	do {
		const std::string file_entry_name = file_entry_data_of_windows.cFileName;
		const bool is_this_a_directory = ( file_entry_data_of_windows.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ) != 0;

		if ( file_entry_name == current_directory_name_constant || file_entry_name == parent_directory_name_constant ) continue;

		if ( is_this_a_directory && output_directories != nullptr ) {
			output_directories->push_back( add_full_path_to_directory_names ? a_path + path_separator + file_entry_name : file_entry_name );
		} else if ( output_files != nullptr ) {
			output_files->push_back( add_full_path_to_filenames ? a_path + path_separator + file_entry_name : file_entry_name );
		}
	} while ( ::FindNextFileA( file_entry_handle_of_windows, &file_entry_data_of_windows ) );

	::FindClose( file_entry_handle_of_windows );
	return true;
}

// static
size_t File_system::get_size_of_file( const std::string &a_path ) noexept {
	std::fstream input_file( a_path );

	if ( !input_file.is_open() ) return WRONG_SIZE;

	if ( !input_file.seekg( 0, std::ios_base::end ).good() ) return WRONG_SIZE;

	const std::streamoff size_of_file = input_file.tellg();
	return static_cast< size_t >( size_of_file );
}

// static
bool File_system::separate_name_extension_and_path(
	std::string *output_path,
	std::string *output_name,
	std::string *output_extension,
	const std::string &input_full_path,
	const std::string &path_separator ) noexept
{
	if ( input_full_path.empty() || output_name == nullptr && output_extension == nullptr && output_path == nullptr ) return false;

	std::string a_path = input_full_path;

	// detaching extension
	const size_t position_of_last_period = a_path.find_last_of( extension_separator_constant );
	
	if ( position_of_last_period == std::string::npos ) {
		Nullptr_checking_assignment( output_extension, std::string() );
	} else {
		Nullptr_checking_assignment( output_extension, std::string( a_path, position_of_last_period + 1 ) );
		a_path = std::string( a_path, 0, position_of_last_period );
	}

	// detaching filename (or last directory name)
	const size_t position_of_last_separator = a_path.find_last_of( path_separator );
	std::string detached_name;

	if ( position_of_last_separator == std::string::npos ) {
		Nullptr_checking_assignment( output_name, a_path );
		a_path = std::string();
	} else {
		Nullptr_checking_assignment( output_name, std::string( a_path, position_of_last_separator + 1 ) );
		a_path = std::string( a_path, 0, position_of_last_separator );
	}

	// storing detached path
	Nullptr_checking_assignment( output_path, a_path );
	return true;
}



// static
std::string File_system::replace_all(
	const std::string &replace_from,
	const std::string &replace_to,
	const std::string &replace_what ) noexept
{
	size_t find_position = 0;

	std::string replaced_what = replace_what;

	while ( ( find_position = replaced_what.find( replace_from, find_position ) ) != std::string::npos ) {
		replaced_what.replace( find_position, replace_to.length(), replace_to );
	}

	return replaced_what;
}

// void GetDirectories(std::vector<string> &out, const string &aPath)
// {
// #ifdef WIN32
//     HANDLE dir;
//     WIN32_FIND_DATA file_data;
// 
//     if ((dir = FindFirstFile((aPath + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
//     	return; /* No files found */
// 
//     do {
//     	const string file_name = file_data.cFileName;
//     	const string full_file_name = aPath + "/" + file_name;
//     	const bool is_directory = (file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
// 
//     	if (file_name[0] == '.')
//     		continue;
// 
//     	if (!is_directory)
//     		continue;
// 
//     	out.push_back(full_file_name);
//     } while (FindNextFile(dir, &file_data));
// 
//     FindClose(dir);
// #else
//     DIR *dir;
//     class dirent *ent;
//     class stat st;
// 
//     dir = opendir(aPath);
//     while ((ent = readdir(dir)) != NULL) {
//     	const string file_name = ent->d_name;
//     	const string full_file_name = aPath + "/" + file_name;
// 
//     	if (file_name[0] == '.')
//     		continue;
// 
//     	if (stat(full_file_name.c_str(), &st) == -1)
//     		continue;
// 
//     	const bool is_directory = (st.st_mode & S_IFDIR) != 0;
// 
//     	if (!is_directory)
//     		continue;
// 
//     	out.push_back(full_file_name);
//     }
//     closedir(dir);
// #endif
// } // GetFilesInDirectory


} // namespace researching
} // namespace jmsf
