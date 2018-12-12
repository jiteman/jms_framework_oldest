#include "Char_string.h"

namespace jmsf {
namespace typing {
namespace examples {


void CharString::delete_pt(CharString* pts) {
	delete[] pts;
}

//-------------------------------------------------------------------------

CharString::~CharString()  { 
//	if (pt_buf) 
	delete[] pt_buf; /*RA XTSce33189*/
}

//-------------------------------------------------------------------------

CharString::CharString(const char* fn, const char* mode) {
	if ( fn == NULL || mode == NULL ) {
		init( 20, 10 );
		return;
	}

	flags_read = 0;
//	FILE* f = fopen(fn, "rb");
	FILE* f = fopen(fn, mode);
	if (f!=NULL) {
		fseek(f,0,2); // eof
		int size = (int)ftell(f);
		if (size > 0) {
			rewind(f);
			init(size+1, 80);
			int nbr = fread(pt_buf, 1, size, f);
			if (nbr < 0)
				nbr = 0;
			pt_buf[nbr] = '\0';
			if (nbr < 0) {
				flags_read |= read_file;
			}
			len = nbr + 1; //strlen(pt_buf); //XTSce85068
		}
		else
			init(20,20);
		fclose(f);
		f = 0;
	}
	else {
		init(0, 80);
		flags_read |= open_file;
	}
}

//-------------------------------------------------------------------------

void CharString::dump() {
	printf("CharString: sz %d, sz_grow %d, len %d \n", sz, sz_grow, len);
} 

//-------------------------------------------------------------------------

void CharString::init(int size, int size_grow) { 
	len=0; 
	sz= size + 1;
	if (size_grow >= 8)
		sz_grow = size_grow;
	else
		sz_grow = 20;
	pt_buf= new char[sz];
	pt_buf[0] = '\0'; 
	flags_read = 0;
}

void CharString::copy(const char* s2) {
	if ( s2 == NULL ) return;

	len = strlen(s2); 
	my_assert(len < sz);
	strcpy(pt_buf, s2);
	flags_read = 0; 
}

CharString::operator const char*()  { 
	if (!pt_buf)
		init(8,8);
	return pt_buf;
}

void CharString::grow(int new_size) {
	if (pt_buf && new_size <= (int)sz)
		return;
	char* pt = new char[new_size];
	if (pt_buf) {
		strcpy(pt, pt_buf);
		delete [] pt_buf;	/*RA XTSce33189*/
	}
	else {
		sz_grow = 80;
		pt[0] = '\0';
	}
	pt_buf = pt;
	sz = new_size;
}

void CharString::operator =  (const CharString& s) {
	if (int(s.len + 1) > (int)sz) {
		if (pt_buf)
		delete [] pt_buf; /*RA XTSce33189*/
		init(s.len + 10, sz_grow);
	}
	copy(s.pt_buf);
}

void CharString::operator =  (const char* s) {
	if ( s == NULL ) return;

	int lg = strlen(s);
	if ((lg + 1) > (int)sz) {
		if (pt_buf)
		delete [] pt_buf; /*RA XTSce33189*/
		init(lg + 10, sz_grow);
	}
	copy(s);
}

void CharString::operator =  (char c) {
	if (!pt_buf)
	init(8,8);
	pt_buf[0] = c;
	pt_buf[1] = '\0';
	len = 1;
	flags_read = 0;
}


void CharString::operator +=  (char c) {
	if (int(len + 2) > (int)sz) 
	grow(len + sz_grow);
	pt_buf[len++] = c;
	pt_buf[len] = '\0';
}

void CharString::operator +=  (const CharString& s) {
	if (int(len + s.len + 2) > (int)sz) 
	grow(s.len + len + sz_grow);
	len += s.len;
	my_assert(pt_buf && s.pt_buf);
	strcat(pt_buf, s.pt_buf);
}

void CharString::operator +=  (const char* s) {
	if ( s == NULL ) return;

	int lg = strlen(s);
	if (int(len + lg + 2) > (int)sz) 
	grow(len + lg + sz_grow);
	len += lg;
	my_assert(pt_buf);
	strcat(pt_buf, s);
}

void CharString::upcase() {
	for (char* p = pt_buf; p < pt_buf + len; ++p) 
		if (*p >= 'a' && *p <= 'z')
            *p -= 'a' - 'A';
}



void CharString::downcase() {
	for (char* p = pt_buf; p < pt_buf + len; ++p) 
		if (*p >= 'A' && *p <= 'Z')
            *p += 'a' - 'A';
}


void CharString::remove_blanks() {
	if (pt_buf && len) {
		char* p;
		char* n;
		for (p = n = pt_buf; p < pt_buf + len; ++p) 
			if (*p != ' ' && *p != '\t')
				*n++ = *p;
		*n = '\0';
		len = n - pt_buf;
	}
}


int CharString::index(char c, int posdeb) {
	my_assert(posdeb >= 0);
	int   rep = -1;
	if (posdeb >= (int)len)
		return rep;
	char* p = strchr(pt_buf + posdeb, c);
	if (p) 
		rep = p - pt_buf;
	return rep;
}


int CharString::index(const char* s, int   posdeb) {
	if ( s == NULL ) return -1;

	my_assert(posdeb >= 0);
	int   rep = -1;
	if (posdeb >= (int)len)
		return rep;
	char* p = strstr(pt_buf + posdeb, s);
	if (p) 
		rep = p - pt_buf;
	return rep;
}




CharString CharString::from(int pos) {
	int x = (pos < 0)? 0 : pos;
	CharString srep;
	if (x < (int)len) {
		srep = &pt_buf[x];
	}
	return srep;
}

CharString CharString::before(int pos) {
	int x = (pos >= (int)len)? len : pos;
	CharString srep = pt_buf;
	if (x >= 0) {
/*YB 240903+*/
		srep.len = x;				
		srep.pt_buf[x] = '\0';
/*YB 240903-*/
	}
	return srep;
}

/*YB 240903+*/
CharString CharString::fromAndBefore(int posdeb, int posfin) {
	int xdeb = (posdeb < 0)? 0 : posdeb;
	int xfin = (posfin >= (int)len)? len : posfin;
	CharString srep;
	if (xfin > xdeb) {
		srep = &pt_buf[xdeb];
		srep.len = xfin-xdeb;
		srep.pt_buf[xfin-xdeb] = '\0';
	}
	return srep;
}
/*YB 240903-*/

void CharString::del(int posdeb, int lg) {
	if (lg <= 0 || posdeb < 0 || posdeb >= (int)len)
		return;
	char* pdeb = pt_buf + posdeb;
	char* pfin = pdeb + lg;
	pdeb[0] = '\0';
	if (pfin < pt_buf + len) {
		int lg2 = strlen(pfin);
		for (int i=0; i < lg2; i++)
			pdeb[i] = pfin[i];
		pdeb[lg2] = '\0';
	}
	len = strlen(pt_buf);
}


void CharString::gsub(const char* s1, const char* s2, int nb_occur) {/*YB 300999 */
	if ( s1 == NULL || s2 == NULL ) return;

	int i = 0;
	char* pt;
	char* tbi[50];
	int lg1 = strlen(s1);
	int lg2 = strlen(s2);
	if (nb_occur > 50) nb_occur = 50;/*YB 300999 */
	// pistage des occurences
	for (pt= pt_buf; pt < pt_buf + len, i < nb_occur; i++) {/*YB 300999 */
		tbi[i] = strstr(pt, s1);
		if (!tbi[i])
			break;
		pt = tbi[i] + lg1;
	}
	if (i == 0)
		return;
	int new_size = len + (i + 1) * (lg2 - lg1) + 10;
	if (new_size < (int)sz)
		new_size = sz;
	char* ptbuf = new char[new_size];
	char* p = ptbuf;
	pt= pt_buf;

	// each occurrence of change by s1 s2
	for (i=0; i < nb_occur && tbi[i]; i++) {
		while (pt < tbi[i]) 
            *p++ = *pt++;
		*p = '\0';
		strcat(p, s2);
		p += lg2;
		pt += lg1;
	}

	my_assert(p < ptbuf + new_size);
	*p = 0;
	if (pt < pt_buf + len)
		strcat(p, pt);
	len = strlen(ptbuf);
	sz = new_size;
	my_assert(len < sz);
	if (pt_buf)
		delete [] pt_buf; /*RA XTSce33189*/
	pt_buf = ptbuf;
}
  

//-----------------------------------------------------------------------


CharString&  CharString::operator << (const CharString& s) {
	*this += s;
	return *this;
}

CharString&  CharString::operator << (const char* s) {
	if ( s != NULL && strlen(s)) 
		*this += s;
	return *this;
}

CharString&  CharString::operator << (char c) {
	*this += c;
	return *this;     
}

CharString&  CharString::operator << (int x) {
	char buf[20];
	sprintf(buf, "%d", x); 
	*this += buf;
	return *this;
}

CharString&  CharString::operator << (unsigned int x) {
	char buf[20];
	sprintf(buf, "%u", x); 
	*this += buf;
	return *this;
}


CharString&  CharString::operator << (float f) {
	char buf[40];
	sprintf(buf, "%f", f);
	*this += buf;
	return *this;
}

CharString&  CharString::fill(char c, int lg) {
	while ((int)len < lg)
		*this += c;
	return *this;
}

//-----------------------------------------------------------------------


CharString&  CharString::operator >> (char* s) {
	if ( s == NULL ) return *this;

	int charstring_n = 0;
	sscanf(pt_buf, "%s%n", s, &charstring_n);
	if (charstring_n <= 0)
		flags_read |= read_chars;
	else
		del(0,charstring_n);
	return *this;
}

CharString&  CharString::operator >> (char& c) {
	int charstring_n = 0;
	sscanf(pt_buf, "%c%n", &c, &charstring_n);
	if (charstring_n <= 0)
		flags_read |= read_char;
	else
		del(0,charstring_n);
	return *this;     
}

CharString&  CharString::operator >> (int& x) {
	int charstring_n = 0;
	sscanf(pt_buf, "%d%n", &x, &charstring_n);
	if (charstring_n <= 0) 
		flags_read |= read_int;
	else
		del(0,charstring_n);
	return *this;
}

CharString&  CharString::operator >> (unsigned int& x) {
	int charstring_n = 0;
	sscanf(pt_buf, "%u%n", &x, &charstring_n);
	if (charstring_n <= 0) 
		flags_read |= read_int;
	else
		del(0,charstring_n);
	return *this;
}

CharString&  CharString::operator >> (long& x) {
	int charstring_n = 0;
	int i;
	sscanf(pt_buf, "%d%n", &i, &charstring_n);
	x = i;
	if (charstring_n <= 0)
		flags_read |= read_int;
	else
		del(0,charstring_n);
	return *this;
}


CharString&  CharString::operator >> (float& f) {
	int charstring_n = 0;
	sscanf(pt_buf, "%f%n", &f, &charstring_n);
	if (charstring_n <= 0)
		flags_read |= read_chars;
	else
		del(0,charstring_n);
	return *this;
}


CharString&  CharString::getline(char* buf, int size_buf, char terminator) {
	if ( buf == NULL ) return *this;

	if (len <= 0) {
		flags_read |= read_chars;
		buf[0] = '\0';
		return *this;
	}
	char* p = strchr(pt_buf, terminator);
	int lg;
	if (p)
		lg = p - pt_buf;
	else
		lg = len;
	pt_buf[lg] = '\0';
	strncpy(buf, pt_buf, size_buf);
	if (lg >= 0 && (unsigned)lg < len) {
		/* JMP 251199  
		memcpy(pt_buf, pt_buf + lg +1, len -lg);
		*/
		/*JMP 020300*/
		const char* pt_src = pt_buf + lg +1;
		for (Uint i=0; i< len -lg; i++)
			pt_buf[i] = pt_src[i];
		len = len - lg -1;
	}
	else {
		pt_buf[0] = '\0';
		len = 0;
	}
	return *this;
}


CharString&  CharString::getsentence(char* buf, int size_buf, char c1, char c2) {
	if ( buf == NULL ) return *this;

	buf[0] = '\0';
	int x1 = index(c1);
	int x2 = index(c2);
	if (x1>= 0 && x2 > x1) {
		CharString s1 = from(x1+1);
		x2 = s1.index(c2);
		*this = s1.from(x2+1);
		if (x2 < s1.length())
			s1[x2] = '\0';
		strncpy(buf, s1, size_buf);
	}
	else
		flags_read |= read_chars;
	return *this;
}

//--------------------------------------------------------------------------------

CharString* CharString::split(short& nb_itemsRes, char sep) { /*MARYOCTOBRE*/
	int i;
	unsigned short nb_items = 0;/*MARYOCTOBRE*/
	nb_itemsRes = 0;/*MARYOCTOBRE*/

	if (len == 0)
		return NULL;
	CharString s(*this);
	for (i=0; i< (int)len; i++) {
		if (s[i] == sep)
			nb_items++;
		if (i == (int)len-1)
			nb_items++;
	}

	if ( nb_items > 0 ) {
		/* JMP 251199 ++ */
		CharString* pts = new CharString[nb_items];
		for (i=0; i< (int)len; i++)
			if (pt_buf[i] == sep)
				pt_buf[i]= 0;
		char* pc = pt_buf; 
		for (i=0; i< nb_items && pc <= pt_buf+len; i++) {
			pts[i] = pc;
			pc += strlen(pc)+1;
		}
		for (i=0; i< (int)len; i++)
			if (pt_buf[i] == 0)
				pt_buf[i]= sep;
		/* JMP 251199 -- */
		nb_itemsRes = nb_items; /*MARYOCTOBRE*/
		return pts;
	} else {
		return NULL;
	}
}


//-------------------------------------------------------------------------------
//	Fonctions de manipulation de flux ou de document XML dans des CharString
//--------------------------------------------------------------------------------


//-----------------------------------------------------
// get d'un element XML avec contenu ou vide avec ou sans attribut
// retour
//		Result : >0 : offset pour recherche de l'elt suivant ou 0 pas trouve
//		xmlElement = element avec tag de debut et de fin
//----------------------------------------------------

int CharString::getXMLElement(const char * xmlElementName, CharString & xmlElement, int fromIndex) {
	if ( xmlElementName == NULL ) return -1;

	CharString startOfElt, endOfElt;
	startOfElt = "<";
	endOfElt = "</";
	startOfElt << xmlElementName;
	endOfElt   << xmlElementName << ">";

	int posdeb = -1;
	int posfin = -1;
	int lengthOfEnd=0;

	posdeb = index(startOfElt, fromIndex);	// posdeb = '<' du tag de debut

	if (posdeb >= 0) {
		posdeb += startOfElt.length();
		posfin = index('>', posdeb);	// recherche fin d'elt vide
		if ((posfin <= 0) || ((*this)[posfin-1] != '/'))	//posfin = '>' du tag de fin
			posfin = -1;

		if (posfin == -1) {	// sinon recherche tag de fin
			posfin = index(endOfElt, posdeb);		// posfin = '<' du tag de fin
			lengthOfEnd = strlen(endOfElt);
		}
		else
			lengthOfEnd = 1;
	}

	if (posfin > 0) {
		posfin+= lengthOfEnd;
		xmlElement = fromAndBefore(posdeb, posfin);
		return posfin;
	}
	return 0;
}

//-----------------------------------------------------
// Get du contenu d'un element XML
// retour
//		Result = true si presence du tag de debut et de fin
//		xmlElementValue = contenu
//----------------------------------------------------

bool CharString::getXMLElementValue(const char * xmlElementName, CharString & xmlElementValue, int fromIndex) {
	if ( xmlElementName == NULL ) return false;

	CharString startOfElt, endOfElt;
	startOfElt = "<";
	endOfElt = "</";
	startOfElt << xmlElementName;
	endOfElt   << xmlElementName << ">";

	int posdeb = -1;
	int posfin = -1;

	posdeb = index(startOfElt, fromIndex);
	if (posdeb >= 0) {
		posdeb = index('>', posdeb + startOfElt.length());
		if (posdeb >= 0) {
			posdeb++;								// posdeb = 1ier caractere apres le tag de debut
			posfin = index(endOfElt, posdeb);		// posfin = '<' du tag de fin
		}
	}

	if (posfin > 0) {
		xmlElementValue = fromAndBefore(posdeb, posfin);
		return true;
	}
	return false;
}

//-----------------------------------------------------
// Get de la valeur d'un attribut d'un element XML
// retour
//		Result = true si presence de l'attribut
//		xmlAttributValue = contenu
//----------------------------------------------------
bool CharString::getXMLAttributeValue(const char * xmlAttributeName, CharString & xmlAttributeValue, int fromIndex) {
	if ( xmlAttributeName == NULL ) return false;

	CharString attribute;
	attribute  = xmlAttributeName;
	attribute << "=\"";

	int posdeb = -1;
	int posfin = -1;

	posdeb = index(attribute, fromIndex);
	if (posdeb >= 0) {
		posdeb += attribute.length();
		posfin = index('\"', posdeb);
	}

	if (posfin > 0) {
		xmlAttributeValue = fromAndBefore(posdeb, posfin);
		return true;
	}
	return false;
}


//-----------------------------------------------------
// Comptage du nb occurences d'un element XML avec ou sans contenu, avec ou sans attribut
// retour
//		Result = nbOccurence
//----------------------------------------------------

int CharString::getNbXMLElement(const char * xmlElementName) {
	if ( xmlElementName == NULL ) return -1;

	CharString startOfElt, endOfElt;
	startOfElt = "<";
	endOfElt = "</";
	startOfElt << xmlElementName ;
	endOfElt   << xmlElementName << ">";

	int nbOccur = -1;
	int posdeb = 0;
	int posfin = 0;

	int lengthOfStart = startOfElt.length();
	int lengthOfEnd=0;

	do {
		nbOccur++;
		posdeb = index(startOfElt, posfin+lengthOfEnd);
		if (posdeb >= 0) {
			posdeb += lengthOfStart;
			// recherche fin d'elt vide
			posfin = index('>', posdeb);
			if ((posfin <= 0) || ((*this)[posfin-1] != '/'))
				posfin = -1;
			else
				lengthOfEnd = 1;
			
			if (posfin == -1) {//sinon recherche fin d'elt avec tag de fin
				posfin = index(endOfElt, posdeb);
				lengthOfEnd = endOfElt.length();
			}
				
		}
	} while ((posdeb >= 0) && (posfin > 0));

	return nbOccur;
}

//------------------------------------------
// Encodage d'un element XML
// entree:	nom de l'element xmlElementName
//			valeur de l'element xmlElementValue
//------------------------------------------
void CharString::setXMLElement (const char * xmlElementName, const char * xmlElementValue) {
	if ( xmlElementName != NULL && xmlElementValue != NULL ) {
		*this << "<" << xmlElementName << ">" << xmlElementValue << "</" << xmlElementName << ">";
	}
}

void CharString::setXMLElement (const char * xmlElementName, long xmlElementValue) {
	if ( xmlElement != NULL ) {
		*this << "<" << xmlElementName << ">" << xmlElementValue << "</" << xmlElementName << ">";
	}
}

//------------------------------------------
// Encodage de tag de debut d'un element XML
// entree:	nom de l'element xmlElementName
// resultat dans xmlElement
//------------------------------------------
void CharString::setBeginXMLElement (const char * xmlElementName) {
	if ( xmlElementName != NULL ) {
		*this << "<" << xmlElementName << ">";
	}
}

//------------------------------------------
// Encodage de tag de fin d'un element XML
// entree:	nom de l'element xmlElementName
// resultat dans xmlElement
//------------------------------------------
void CharString::setEndXMLElement (const char * xmlElementName) {
	if ( xmlElementName != NULL ) {
		*this << "</" << xmlElementName << ">";
	}
}


} // namespace examples
} // namespace typing
} // namespace jmsf