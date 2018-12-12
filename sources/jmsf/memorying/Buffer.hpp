#pragma once


#include "Buffer.hxx"

#include "jmsf/typing/Natural.h"

#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace memorying {


template< class A_type >
class Buffer {

public:
	~Buffer() throw();
	
	Buffer( typing::Natural size, typing::Boolean need_to_clear = typing::False ) throw();
	Buffer( const Buffer &other ) throw();
	const Buffer &operator =( const Buffer &other ) throw();

	operator A_type *() throw();

	A_type *get() throw();
	const A_type *get() const throw();

	typing::Natural size() const throw();
	void limit() throw();
	void limit( typing::Natural sizeToLimit ) throw();
	void clear() throw();

private:
	typing::Boolean create() throw();
	typing::Boolean recreate() throw();
	void copy( const Buffer &source_buffer ) throw();

private:
	A_type *_buffer;
	typing::Natural _size;

};


} // namespace memorying
} // namespace jmsf
