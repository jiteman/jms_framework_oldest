#include "realization_es_StatisticsUpdater.h"
#include "../../others/abstractStatistics.h"
#include "../../data/statistics/ed_Summary.h"
#include "../../data/statistics/ed_AppendedFiles.h"
#include "../../data/statistics/ed_DecipheringFiles.h"
#include "../../data/statistics/ed_StoredFiles.h"
#include "../../data/statistics/ed_DeletedFiles.h"
#include "../../data/ed_VoiceFile.h"
#include "../../data/ed_ServiceFile.h"
#include "../es_Decipher.h"
#include "jmsf/Pair.hpp"
#include "jmsf/PointersAndProxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace realizations {


const ::jmsf::ConstantProxy< data::statistics::ed_Summary > &realization_es_StatisticsUpdater::updateAndGetSummary() throw() {
	_decipheringFiles->takeMutex()->lock();
	::updateDecipherNowDecipherFilePercent(
		_decipheringFiles->takeData().get(),
		static_cast< ::jmsf::natural >( _decipher->getCurrentlyDecipheringVoiceFileProgress() ) );

	_appendingFiles->takeMutex()->lock();	
	_storageFiles->takeMutex()->lock();
	_deletedFiles->takeMutex()->lock();

	::updateGlobalStatistics(
		_summary->takeData().get(),
		_appendingFiles->takeData().get(),
		_decipheringFiles->takeData().get(),
		_storageFiles->takeData().get(),
		_deletedFiles->takeData().get() );
	
	_decipheringFiles->takeMutex()->unlock();
	_storageFiles->takeMutex()->unlock();
	_appendingFiles->takeMutex()->unlock();
	_deletedFiles->takeMutex()->unlock();
	return _constantSummary;
}

void realization_es_StatisticsUpdater::updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
 	_appendingFiles->takeMutex()->lock();
 	::updateAppenderStatistics( _appendingFiles->takeData().get(), *( const_cast< FileDescriptorData * >( voiceFile->getData().get() ) ) ); // REFACTOR - back to const reference
 	_appendingFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() {
 	_appendingFiles->takeMutex()->lock();
 	::updateAppenderStatistics( _appendingFiles->takeData().get(), *( const_cast< FileDescriptorData * >( serviceFile->getData().get() ) ) ); // REFACTOR - back to const reference
 	_appendingFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
 	_decipheringFiles->takeMutex()->lock();
 	::updateDecipherQueue( _decipheringFiles->takeData().get(), *voiceFile->getData() );
 	_decipheringFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
 	_decipheringFiles->takeMutex()->lock();
 	::updateDecipherNowDecipherFile( _decipheringFiles->takeData().get(), *voiceFile->getData() );
 	_decipheringFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
 	_decipheringFiles->takeMutex()->lock();
 	::updateDecipherOKFiles( _decipheringFiles->takeData().get(), *voiceFile->getData() );
 	_decipheringFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
 	_decipheringFiles->takeMutex()->lock();
 	::updateDecipherBADFiles( _decipheringFiles->takeData().get(), *voiceFile->getData() );
 	_decipheringFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateResultVoiceFileAndServiceFilePair( const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_ServiceFile > > > &voiceFileAndServiceFilePair ) throw() {
	_storageFiles->takeMutex()->lock();
	::updateDataBaseStatisticts( _storageFiles->takeData().get(), *( const_cast< FileDescriptorData * >( voiceFileAndServiceFilePair->getFirst()->getData().get() ) ) );
	::updateDataBaseStatisticts( _storageFiles->takeData().get(), *( const_cast< FileDescriptorData * >( voiceFileAndServiceFilePair->getSecond()->getData().get() ) ) );
	_storageFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
	_storageFiles->takeMutex()->lock();
	::updateDataBaseStatisticts( _storageFiles->takeData().get(), *( const_cast< FileDescriptorData * >( voiceFile->getData().get() ) ) );
	_storageFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() {
	_storageFiles->takeMutex()->lock();
	::updateDataBaseStatisticts( _storageFiles->takeData().get(), *( const_cast< FileDescriptorData * >( serviceFile->getData().get() ) ) );
	_storageFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > &voiceFile ) throw() {
	// C4i
// 	_decipheringFiles->lock();
// 	::updateDecipherBADFiles( _decipheringFiles->getOneselfData().get(), *voiceFile->getData(), voiceFile->isDeletedFromDecipher() );
// 	_decipheringFiles->unlock();
	if( voiceFile->isDeletedFromDecipher() ) {
		_decipheringFiles->takeMutex()->lock();
	 	::updateDecipherBADFiles( _decipheringFiles->takeData().get(), *voiceFile->getData(), voiceFile->isDeletedFromDecipher() );
	 	_decipheringFiles->takeMutex()->unlock();
	}

	_deletedFiles->takeMutex()->lock();
	::updateDeleteFiles( _deletedFiles->takeData().get(), *voiceFile->getData() );	
	_deletedFiles->takeMutex()->unlock();
}

void realization_es_StatisticsUpdater::updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > &serviceFile ) throw() {
	_deletedFiles->takeMutex()->lock();
	::updateDeleteFiles( _deletedFiles->takeData().get(), *serviceFile->getData() );
	_deletedFiles->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_es_StatisticsUpdater::~realization_es_StatisticsUpdater() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_es_StatisticsUpdater::realization_es_StatisticsUpdater(
	::jmsf::Proxy< data::statistics::ed_Summary > summary,
	::jmsf::Proxy< data::statistics::ed_AppendedFiles > appendingFiles,
	::jmsf::Proxy< data::statistics::ed_DecipheringFiles > decipheringFiles,
	::jmsf::Proxy< data::statistics::ed_StoredFiles > storageFiles,
	::jmsf::Proxy< data::statistics::ed_DeletedFiles > deletedFiles,
	const ::jmsf::ConstantProxy< es_Decipher > &decipher ) throw()
	:
		_summary( summary ),
		_appendingFiles( appendingFiles ),
		_decipheringFiles( decipheringFiles ),
		_storageFiles( storageFiles ),
		_deletedFiles( deletedFiles ),
		_decipher( decipher )
{
	_constantSummary = _summary.getWeakConstant();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_StatisticsUpdater > realization_es_StatisticsUpdater::createClone() const throw() {
	return ::jmsf::Proxy< es_StatisticsUpdater >::createUnique( new realization_es_StatisticsUpdater( *this ) );
}

realization_es_StatisticsUpdater::realization_es_StatisticsUpdater( const realization_es_StatisticsUpdater & ) throw() // other
{}

const realization_es_StatisticsUpdater &realization_es_StatisticsUpdater::operator =( const realization_es_StatisticsUpdater &other ) throw() {
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
}
