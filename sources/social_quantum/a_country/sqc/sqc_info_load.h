#pragma once

#include "sqc_base.h"

NAMESPACE_SQC_INFO

bool load_hierarchy( sqc_string const &path, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, sqc_version_provider_ptr version_provider );

#if defined SQC_CONFIGURATOR
bool compare_binary_object_information( sqc_object_info_provider_ptr first_object_information_provider, sqc_object_info_provider_ptr second_object_information_provider );

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
bool load_objects( sqc_string const &path, sqc_object_info_provider_ptr class_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, const sqc_string &path_to_object_descriptions );
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
bool load_objects( sqc_string const &path, sqc_object_info_provider_ptr class_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider );
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION

bool write_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider );

#endif // #if defined SQC_CONFIGURATOR

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
bool read_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, const sqc_string &path_to_object_descriptions, sqc_version_provider_ptr version_provider );
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
bool read_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, sqc_version_provider_ptr version_provider );
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION

END_NAMESPACE_SQC_INFO
