#include "Naturals.hin"


namespace jmsf {
namespace typeing {


const Memory_natural Memory_natural_badmax = ~Memory_natural();
const Memory_natural Memory_natural_nill;
const Memory_natural Memory_natural_one = Memory_natural::create( 1 );

const File_natural File_natural_badmax = ~File_natural();
const File_natural File_natural_nill;
const File_natural File_natural_one = File_natural::create( 1 );

const Shortest_natural Shortest_natural_badmax = ~Shortest_natural();
const Shortest_natural Shortest_natural_nill;
const Shortest_natural Shortest_natural_one = Shortest_natural::create( 1 );

const Shortest_natural_small Shortest_natural_small_badmax = ~Shortest_natural_small();
const Shortest_natural_small Shortest_natural_small_nill;
const Shortest_natural_small Shortest_natural_small_one = Shortest_natural_small::create( 1 );

const Short_natural Short_natural_badmax = ~Short_natural();
const Short_natural Short_natural_nill;
const Short_natural Short_natural_one = Short_natural::create( 1 );

const Short_natural_small Short_natural_small_badmax = ~Short_natural_small();
const Short_natural_small Short_natural_small_nill;
const Short_natural_small Short_natural_small_one = Short_natural_small::create( 1 );

const Natural Natural_badmax = ~Natural();
const Natural Natural_nill;
const Natural Natural_one = Natural::create( 1 );

const Natural_small Natural_small_badmax = ~Natural_small();
const Natural_small Natural_small_nill;
const Natural_small Natural_small_one = Natural_small::create( 1 );

const Long_natural Long_natural_badmax = ~Long_natural();
const Long_natural Long_natural_nill;
const Long_natural Long_natural_one = Long_natural::create( 1 );

const Long_natural_small Long_natural_small_badmax = ~Long_natural_small();
const Long_natural_small Long_natural_small_nill;
const Long_natural_small Long_natural_small_one = Long_natural_small::create( 1 );


} // namespace typeing
} // namespace jmsf


namespace jmsf {
namespace typeing {


Memory_natural create_address_from_pointer( const void *const memory_pointer ) noexcept {
	return typeing::Memory_natural::create( reinterpret_cast< typeing::memory_natural_value_type >( memory_pointer ) );
}


} // namespace typeing
} // namespace jmsf
