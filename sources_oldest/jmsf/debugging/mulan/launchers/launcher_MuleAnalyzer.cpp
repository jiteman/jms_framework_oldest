#include "jmsf/debugging/mulan/factory_MuleAnalyzer.h"
#include "jmsf/debugging/mulan/MuleAnalyzer.h"
#include "jmsf/debugging/MemoryLoggingSwitch.h"
#include "jmsf/osie/static_factory_OperatingSystemSpecial.h"
#include "jmsf/Proxies.hpp"

int main( const int /*argc*/, const char *const /*argv*/[] ) {
	::jmsf::debugging::MemoryLoggingSwitch::turnOff();
	::jmsf::osie::static_factory_OperatingSystemSpecial::initialize();
	::jmsf::Proxy< ::jmsf::debugging::mulan::MuleAnalyzer > muleAnalyzer = ::jmsf::debugging::mulan::factory_MuleAnalyzer::instance()->createMuleAnalyzer();
	muleAnalyzer->readCollectedData();
	muleAnalyzer->performAnalysis();
	muleAnalyzer->showResults();
}
