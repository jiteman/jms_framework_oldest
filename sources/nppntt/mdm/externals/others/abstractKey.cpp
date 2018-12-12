#include "abstractKey.h"


KeyData *createKey() {
    KeyData *key = new KeyData;
    key->R1 = 0; key->R2 = 0; key->R3 = 0;
	key->networkAndBaseStationId = ~( unsigned int ( 0 ) );
    return key;
}

void deleteKey( KeyData *key ) {
    delete key;
}

bool isSuitableFileDescriptorToKey( const FileDescriptorData *descriptor, const KeyData *key) {
	//return descriptor->baseStation == key->BsName;
	return descriptor->networkAndBaseStationId == key->networkAndBaseStationId;
}

bool areKeysEqual( const KeyData *firstKey, const KeyData *secondKey ) {
	return
		firstKey->networkAndBaseStationId == secondKey->networkAndBaseStationId &&
		firstKey->R1 == secondKey->R1 &&
		firstKey->R2 == secondKey->R2 &&
		firstKey->R3 == secondKey->R3;
}