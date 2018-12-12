#pragma once


#include "jmsf/stdal/stdal_stl.h"

#include "jmsf/jmsf_language_support.h"

#include "jmsf/researching/researching.h"


namespace jmsf {
namespace researching {


class JMSF_RESEARCHING_DLL_INTERFACE Operating_system {

public:
	static std::string generate_UUID() noexept;

};


} // namespace researching
} // namespace jmsf
