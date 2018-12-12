#include "Naturals.inl"


namespace jmsf {
namespace typing {


const Shortest_natural Shortest_natural_badmax = ~Shortest_natural();
const Shortest_natural Shortest_natural_nill;
const Shortest_natural Shortest_natural_one = Shortest_natural::create( 1 );

const Short_natural Short_natural_badmax = ~Short_natural();
const Short_natural Short_natural_nill;
const Short_natural Short_natural_one = Short_natural::create( 1 );

const Natural Natural_badmax = ~Natural();
const Natural Natural_nill;
const Natural Natural_one = Natural::create( 1 );

const Long_natural Long_natural_badmax = ~Long_natural();
const Long_natural Long_natural_nill;
const Long_natural Long_natural_one = Long_natural::create( 1 );

const Memory_size Memory_size_badmax = ~Memory_size();
const Memory_size Memory_size_nill;
const Memory_size Memory_size_one = Memory_size::create( 1 );

const File_size File_size_badmax = ~File_size();
const File_size File_size_nill;
const File_size File_size_one = File_size::create( 1 );


Memory_size create_address_from_pointer( const void *const memory_pointer ) noexept {
	return typing::Memory_size::create( reinterpret_cast< typing::memory_size_value_type >( memory_pointer ) );
}


} // namespace typing
} // namespace jmsf
