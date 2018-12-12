#pragma once

#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/researching/researching.h"

#include "jmsf/jmsf_language_support.h"

namespace jmsf {
namespace researching {


class JMSF_RESEARCHING_DLL_INTERFACE File_system {

public:
	static const size_t WRONG_SIZE = size_t( -1 );
	static const std::string path_separator_constant;
	static const std::string backward_path_separator_constant;
	static const std::string extension_separator_constant;
	static const std::string current_directory_name_constant;
	static const std::string parent_directory_name_constant;
	static const std::string any_filename_constant;
	static const std::string any_filename_here_constant;

public:
	static bool create_list_of_files_and_directories(
		std::vector< const std::string > *output_files,
		std::vector< const std::string > *output_directories,
		const std::string &a_path,
		const std::string &path_separator ) noexept;

	static bool create_directory_listing(
		std::vector< const std::string > *output_files,
		std::vector< const std::string > *output_directories,
		const std::string &a_path,
		const bool add_full_path_to_filenames,
		const bool add_full_path_to_directory_names,
		const std::string &path_separator ) noexept;

	static size_t get_size_of_file( const std::string &a_path ) noexept;

	static bool separate_name_extension_and_path(
		std::string *output_path,
		std::string *output_name,
		std::string *output_extension,
		const std::string &full_path,
		const std::string &path_separator ) noexept;

	static std::string replace_all(
		const std::string &replace_from,
		const std::string &replace_to,
		const std::string &replace_what ) noexept;

};


} // namespace researching
} // namespace jmsf
