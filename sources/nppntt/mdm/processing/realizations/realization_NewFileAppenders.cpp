#include "realization_NewFileAppenders.h"
#include "../../externals/others/abstractFileDescriptor.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/factory_ExternalData.h"
#include "../../externals/software/es_FileAppender.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Iterator.hpp"
#include "jmsf/Casts.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_NewFileAppenders::run() throw( ::jmsf::Exception ) {
	for (
		::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_FileAppender > > > fileAppenderIterator =
			_fileAppenderContainer->createForwardIterator();
		fileAppenderIterator->isNotDone();
		fileAppenderIterator->advance() )
	{
		::jmsf::Proxy< externals::software::es_FileAppender > fileAppender = fileAppenderIterator->takeContainie().getWeak();

		if ( fileAppender->takeVoiceFileDataQueue()->getIsObjectAvailableEvent()->isSet() ) {
			fileAppender->takeVoiceFileDataQueue()->takeMutex()->lock();

			if ( fileAppender->takeVoiceFileDataQueue()->isNotEmpty() ) {
				::jmsf::Pointer< FileDescriptorData > voiceFileData = fileAppender->takeVoiceFileDataQueue()->withdrawFirst();
				fileAppender->takeVoiceFileDataQueue()->takeMutex()->unlock();

				::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile =
					externals::data::factory_ExternalData::instance()->createVoiceFile( voiceFileData );

				_destinationVoiceFileQueue->takeMutex()->lock();
				_destinationVoiceFileQueue->appendBack( voiceFile );
				_destinationVoiceFileQueue->takeMutex()->unlock();

				break;
			} else {
				fileAppender->takeVoiceFileDataQueue()->takeMutex()->unlock();
			}
		}
		
		if ( fileAppender->takeServiceFileDataQueue()->takeIsObjectAvailableEvent()->isSet() ) {
			fileAppender->takeServiceFileDataQueue()->takeMutex()->lock();

			if ( fileAppender->takeServiceFileDataQueue()->isNotEmpty() ) {
				::jmsf::Pointer< FileDescriptorData > serviceFileData = fileAppender->takeServiceFileDataQueue()->withdrawFirst();
				fileAppender->takeServiceFileDataQueue()->takeMutex()->unlock();

				::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile =
					externals::data::factory_ExternalData::instance()->createServiceFile( serviceFileData );

				_destinationServiceFileQueue->takeMutex()->lock();
				_destinationServiceFileQueue->appendBack( serviceFile );
				_destinationServiceFileQueue->takeMutex()->unlock();
				break;
			} else {
				fileAppender->takeServiceFileDataQueue()->takeMutex()->unlock();
			}
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewFileAppenders::~realization_NewFileAppenders() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewFileAppenders::realization_NewFileAppenders(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_FileAppender > > > &fileAppenderContainer ) throw()
	:
		_destinationVoiceFileQueue( destinationVoiceFileQueue.getWeak() ),
		_destinationServiceFileQueue( destinationServiceFileQueue.getWeak() ),
		_fileAppenderContainer( fileAppenderContainer.getWeak() )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewFileAppenders > realization_NewFileAppenders::createClone() const throw() {
	return ::jmsf::Proxy< NewFileAppenders >::createUnique( new realization_NewFileAppenders( *this ) );
}

realization_NewFileAppenders::realization_NewFileAppenders( const realization_NewFileAppenders & ) throw() // other
{}

const realization_NewFileAppenders &realization_NewFileAppenders::operator =( const realization_NewFileAppenders &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
