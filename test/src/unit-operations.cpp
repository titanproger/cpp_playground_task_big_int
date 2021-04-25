#include "catch.hpp"

#include <algorithm> 
#include <gmpxx.h>

#include "TBigInt.hpp"


TEST_CASE("Test sum")
{
    TBigInt<64, uint16_t> a1(0x8000);
    REQUIRE( a1.getInternal()[0] == 0x8000);
    REQUIRE( a1.getInternal()[1] == 0);
    REQUIRE( a1.getInternal()[2] == 0);
    REQUIRE( a1.getInternal()[3] == 0);

    TBigInt<64, uint16_t> b1(0x8000);
    REQUIRE( b1.getInternal()[0] == 0x8000);
    REQUIRE( b1.getInternal()[1] == 0);
    REQUIRE( b1.getInternal()[2] == 0);
    REQUIRE( b1.getInternal()[3] == 0);

    auto c1 = a1+b1;

    REQUIRE( c1.getInternal()[0] == 0x0);
    REQUIRE( c1.getInternal()[1] == 0x1);
    REQUIRE( c1.getInternal()[2] == 0);
    REQUIRE( c1.getInternal()[3] == 0);
}



TEST_CASE("Test sub negative")
{
    TBigInt<64, uint16_t> a1(0x8000);    
    TBigInt<64, uint16_t> b1(0x8001);    

    auto c1 = a1-b1;

    REQUIRE( c1.getInternal()[0] == 0xFFFF);
    REQUIRE( c1.getInternal()[1] == 0xFFFF);
    REQUIRE( c1.getInternal()[2] == 0xFFFF);
    REQUIRE( c1.getInternal()[3] == 0xFFFF);
}


TEST_CASE("Test sub")
{
    TBigInt<64, uint16_t> a1(0x8000);    
    TBigInt<64, uint16_t> b1(0x8001);    

    auto c1 = a1-b1;

    REQUIRE( c1.getInternal()[0] == 0xFFFF);
    REQUIRE( c1.getInternal()[1] == 0xFFFF);
    REQUIRE( c1.getInternal()[2] == 0xFFFF);
    REQUIRE( c1.getInternal()[3] == 0xFFFF);
}

TEST_CASE("Test operator == ")
{
    auto a1  = BIG_INT_HEX( "123f555Ffffff450", uint64_t) ;    
    TBigInt<64, uint64_t> b1(0x123f555Ffffff450);           
    REQUIRE( a1 == b1);    


    auto a2  = BIG_INT_HEX( "343f555Ffffff450", uint64_t) ;    
    TBigInt<64, uint64_t> b2(0x123f555Ffffff450);           
    REQUIRE( a2 != b2);        
}

TEST_CASE("Test big number")
{

    auto a1  =    BIG_INT_HEX( "2A6D8D4FE71D173FDD017F8A26482A6DCFAB0324D0F123E1A", uint64_t) ; //16645280007602915857002215848267653012067642669348936629786
    auto b1  =    BIG_INT_HEX( "0000000000000000000000002DA24EC2A8C6070604BD2FF32", uint64_t) ; // 225968693762456443473416617778

    auto c1 = a1 + b1;
    REQUIRE( c1 == BIG_INT_HEX( "2A6D8D4FE71D173FDD017F8A53EA793078710A2AD5AE53D4C", uint64_t) ); 
    

}

 

