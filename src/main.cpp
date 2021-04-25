// using namespace std;


// // Driver code
// int main()
// {                                      
//     cout << "Hello\n";            
//     return 0;
// }


#include <tuple>
#include <iostream>
#include <algorithm>
#include <array>
#include <utility>
#include <iomanip>
 
// debugging aid
template<typename T,std::size_t N>
void print_array(std::array<T, N> array)
{
    std::cout << "The sequence of size " << array.size() << ": ";

    std::cout << "0x";
    std::for_each(array.rbegin(), array.rend(), [](const T& element) {
        std::cout << std::setfill ('0') << std::setw(sizeof(T)*2) << std::hex << element;
    });        

    std::cout <<'\n';
}
 
#include <type_traits>
#include "TBigInt.hpp"
int main()
{
    TBigInt<64, uint16_t> big_int_a(0x8000);
    TBigInt<64, uint16_t> big_int_b(0x8000);

    print_array(big_int_a.getInternal() );
    print_array(big_int_b.getInternal() );

    TBigInt<64,uint16_t> big_int_c = big_int_a + big_int_b;

    print_array(big_int_c.getInternal() );
    //std::cout << big_int_c.getInternal()[0] << '\n';
             
    // TBigInt<32, uint16_t> a1;    
    // a1.doInitByHexArray( std::array<char, 8>{'1','2','3','4','5','6','7','8'} );
    // print_array(a1.getInternal() );


    auto a2  = BIG_INT_HEX( "123f555Ffffff45067", uint64_t) ;
    print_array(a2.getInternal() );    


    
}