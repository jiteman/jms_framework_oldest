#include "es_StatisticsUpdater.h"
#include "../data/statistics/ed_Summary.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace software {

class null_es_StatisticsUpdater :
	public es_StatisticsUpdater,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_es_StatisticsUpdater >
{

public:
	// virtuals es_StatisticsUpdater
	const ::jmsf::ConstantProxy< data::statistics::ed_Summary > &updateAndGetSummary() throw() {
		return _summaryCrtr;
	}

	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}

	void updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateResultVoiceFileAndServiceFilePair(
		const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_ServiceFile > > > & ) throw() // voiceFileAndServiceFilePair
	{}

	void updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}

	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_es_StatisticsUpdater() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_es_StatisticsUpdater >;
	static null_es_StatisticsUpdater *createInstance() throw() {
		return new null_es_StatisticsUpdater;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_es_StatisticsUpdater() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StatisticsUpdater > createClone() const throw() {
		return ::jmsf::Proxy< es_StatisticsUpdater >::createUnique( this );
	}

private:
	null_es_StatisticsUpdater( const null_es_StatisticsUpdater & ) throw() {} // other
	
	const null_es_StatisticsUpdater &operator =( const null_es_StatisticsUpdater &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_es_StatisticsUpdater::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::statistics::ed_Summary > _summaryCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_es_StatisticsUpdater :
	public es_StatisticsUpdater,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_es_StatisticsUpdater > {

public:
	// virtuals es_StatisticsUpdater
	const ::jmsf::ConstantProxy< data::statistics::ed_Summary > &updateAndGetSummary() throw() {
		return _summaryCrtr;
	}

	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateAppendedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}

	void updateAppendedToDecipherVoiceFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDecipheringVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateNotDecipheredVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateResultVoiceFileAndServiceFilePair(
		const ::jmsf::ConstantProxy< ::jmsf::Pair< ::jmsf::ConstantProxy< data::ed_VoiceFile >, ::jmsf::ConstantProxy< data::ed_ServiceFile > > > & ) throw() // voiceFileAndServiceFilePair
	{}

	void updateResultVoiceFile( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateResultServiceFile( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}

	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_VoiceFile > & ) throw() // voiceFile
	{}

	void updateDeletedFiles( const ::jmsf::ConstantProxy< data::ed_ServiceFile > & ) throw() // serviceFile
	{}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_es_StatisticsUpdater() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_es_StatisticsUpdater >;
	static exception_es_StatisticsUpdater *createInstance() throw() {
		return new exception_es_StatisticsUpdater;
	}

private:
	exception_es_StatisticsUpdater() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< es_StatisticsUpdater > createClone() const throw() {
		return ::jmsf::Proxy< es_StatisticsUpdater >::createUnique( this );
	}

private:
	exception_es_StatisticsUpdater( const exception_es_StatisticsUpdater & ) throw() {} // other

	const exception_es_StatisticsUpdater &operator =( const exception_es_StatisticsUpdater &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_es_StatisticsUpdater::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< data::statistics::ed_Summary > _summaryCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
es_StatisticsUpdater *es_StatisticsUpdater::getNull() throw() {
	return null_es_StatisticsUpdater::instance();
}

// static
es_StatisticsUpdater *es_StatisticsUpdater::getException() throw() {
	return exception_es_StatisticsUpdater::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace software
} // namespace externals
} // namespace mdm
} // namespace nppntt
