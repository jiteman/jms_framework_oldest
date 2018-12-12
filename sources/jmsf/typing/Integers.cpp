#include "Integers.inl"


namespace jmsf {
namespace typing {


const Shortest_integer Shortest_integer_badmax = ~Shortest_integer();
const Shortest_integer Shortest_integer_nill;
const Shortest_integer Shortest_integer_one = Shortest_integer::create( 1 );
const Shortest_integer Shortest_integer_minus = Shortest_integer::create( -1 );

const Short_integer Short_integer_badmax = ~Short_integer();
const Short_integer Short_integer_nill;
const Short_integer Short_integer_one = Short_integer::create( 1 );
const Short_integer Short_integer_minus = Short_integer::create( -1 );

const Integer Integer_badmax = ~Integer();
const Integer Integer_nill;
const Integer Integer_one = Integer::create( 1 );
const Integer Integer_minus = Integer::create( -1 );

const Long_integer Long_integer_badmax = ~Long_integer();
const Long_integer Long_integer_nill;
const Long_integer Long_integer_one = Long_integer::create( 1 );
const Long_integer Long_integer_minus = Long_integer::create( -1 );

const Memory_diff Memory_diff_badmax = ~Memory_diff();
const Memory_diff Memory_diff_nill;
const Memory_diff Memory_diff_one = Memory_diff::create( 1 );
const Memory_diff Memory_diff_minus = Memory_diff::create( -1 );

const File_diff File_diff_badmax = ~File_diff();
const File_diff File_diff_nill;
const File_diff File_diff_one = File_diff::create( 1 );
const File_diff File_diff_minus = File_diff::create( -1 );


} // namespace typing
} // namespace jmsf
