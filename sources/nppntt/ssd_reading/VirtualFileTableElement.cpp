#include "VirtualFileTableElement.h"

namespace nppntt {
namespace ssd_reading {

VirtualFileTableElement::~VirtualFileTableElement() throw()
{}

VirtualFileTableElement::VirtualFileTableElement() throw()
	: _file( ::jmsf::Pointer< ::jmsf::osie::File >::createEmpty() )
{}

VirtualFileTableElement::VirtualFileTableElement( ::jmsf::natural_big sizeOfCluster, const std::string &pathToFile, ::jmsf::natural_size indexOfDrive, ::jmsf::natural_big positionShift ) throw()
	: _file( ::jmsf::osie::factory_OperatingSystem::instance()->getFileSystemControl()->createFile ::jmsf::osie::File::create( pathToFile, sizeOfCluster ) ), _pathToFile( pathToFile )
{
	_indexOfDrive = indexOfDrive;
	_positionShift = positionShift;
}

::jmsf::natural_size VirtualFileTableElement::getIndexOfDrive() const throw() {
	return _indexOfDrive;
}

::jmsf::Pointer< ::jmsf::osie::runup::FileWithoutBuffering > VirtualFileTableElement::getFile() const throw() {
	return _file.getWeak();
}

::jmsf::natural_big VirtualFileTableElement::getPositionShift() const throw() {
	return _positionShift;
}

} // namespace
}
