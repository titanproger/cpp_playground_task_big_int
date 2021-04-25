#include "catch.hpp"


#include <algorithm> 
#include <gmpxx.h>

#include "TBigInt.hpp"

TEST_CASE("Test init")
{
    TBigInt<64, uint64_t> x(0x0);
    REQUIRE( x.getInternal().size() == 1);

    TBigInt<65, uint64_t> x2(0x0); // for 65 bits we need 2 64bit items
    REQUIRE( x2.getInternal().size() == 2);

    TBigInt<63, uint64_t> x3(0x0);
    REQUIRE( x3.getInternal().size() == 1);
}


TEST_CASE("Test init zero")
{
    TBigInt<64, uint16_t> x;
    REQUIRE( x.getInternal()[0] == 0);
    REQUIRE( x.getInternal()[1] == 0);
    REQUIRE( x.getInternal()[2] == 0);
    REQUIRE( x.getInternal()[3] == 0);
}


TEST_CASE("Test init by hex")
{
    TBigInt<32, uint16_t> a1;    
    a1.doInitByHexArray( std::array<char, 8>{'1','2','3','4','5','6','7','8'} );

    REQUIRE( a1.getInternal()[0] == 0x5678);
    REQUIRE( a1.getInternal()[1] == 0x1234);

    //TBigInt<32, uint64_t> a2 = 12345678_XZ;            
    //REQUIRE( a2.getInternal()[0] == 0x12345678);    
}


TEST_CASE("Test init by literal")
{    
    //TBigInt<32, uint64_t> a2 = 12345678_XZ;            
    //REQUIRE( a2.getInternal()[0] == 0x12345678);    
}