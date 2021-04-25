#pragma once

#include <cstdlib>
#include <stdint.h>
//#include <type_traits>

template <typename T = uint64_t>
constexpr auto GetLimbCountByBitCount(const std::size_t &bit_count) {
    std::size_t limb_size_bits = sizeof(T) * 8;    
    std::size_t remain = ( (bit_count % limb_size_bits) > 0) ? 1 : 0;            
    return ( bit_count / limb_size_bits ) +  remain;
}

template <std::size_t N, typename T = uint64_t>
class TBigInt {

public:
    TBigInt<N,T>() {
        m_buffer.fill(0);        
    }

    TBigInt<N,T>(const T &x ) {
        m_buffer.fill(0);
        m_buffer[0] = x;
    }

    template< std::size_t TLEN>
    TBigInt<N,T>(const char* ptr ) {
        doInitByString(ptr);
    }


    template <std::size_t TLEN>
    const TBigInt<N,T>& doInitByString(const char* ptr) {  
        std::array<char,TLEN> array;
        std::copy(ptr, ptr+TLEN, begin(array) );
        return doInitByHexArray(array);
    }

    template< std::size_t TLEN>
    const TBigInt<N,T>& doInitByHexArray(std::array<char, TLEN> digits ) {  
        m_buffer.fill(0);
        
        //const T ASCII_CODE_SYMBOL_ZERO = 48;
                
        const std::size_t LIMB_BIT_SIZE = sizeof(T)*8;        
        const std::size_t BITS_PER_SYMBOL = 4;
        
        std::size_t bit_count_assigned_to_current_limb = 0;
        T tmp = 0;
        int char_id = digits.size()-1;        
        std::size_t limb_id = 0;
        while(limb_id < m_buffer.size()) {        
            if(char_id >= 0) {
                char c = digits[char_id];
                T digit = (c >= 'A') ? (c >= 'a') ? (c - 'a' + 10) : (c - 'A' + 10) : (c - '0');
                tmp |= digit << bit_count_assigned_to_current_limb;
            }                                    
            bit_count_assigned_to_current_limb += BITS_PER_SYMBOL;
            char_id--;
            if(bit_count_assigned_to_current_limb >= LIMB_BIT_SIZE) {
                bit_count_assigned_to_current_limb = 0;
                this->m_buffer[limb_id] = tmp;
                tmp = 0;
                limb_id++;
            }            
        }
        return *this;
    }
            
    TBigInt<N,T> operator + (const TBigInt<N,T> &other) const {
        T carry {};
        TBigInt<N, T> result(0);

        for (auto i = 0U; i < other.m_buffer.size(); ++i) {
            T aa = m_buffer[i];
            T bb = other.m_buffer[i];
            T sum = aa + bb;
            T res = sum + carry;
            carry = (sum < aa) | (res < sum);
            result.m_buffer[i] = res;
        }        
        //if(carry) 
        // overflow!!!
        return result;
    }


    TBigInt<N,T> operator - (const TBigInt<N,T> &other) const {
        T carry {};
        TBigInt<N, T> result(0);

        for (auto i = 0U; i < other.m_buffer.size(); ++i) {
            T aa = m_buffer[i];
            T bb = other.m_buffer[i];
            T sub = aa - bb;
            T res = sub - carry;
            carry = (sub > aa) | (res > sub);
            result.m_buffer[i] = res;
        }        
        //if(carry) 
        // overflow!!!
        return result;
    }


    bool operator == (const TBigInt<N,T> &other) const {
        return std::equal(this->m_buffer.begin(), this->m_buffer.end(),
            other.m_buffer.begin(), other.m_buffer.end());
    }

    bool operator != (const TBigInt<N,T> &other) const {
        return !(*this == other);
    }

    const auto & getInternal() {
        return m_buffer;
    }

private:
    std::array<T, GetLimbCountByBitCount<T>(N)> m_buffer;
};


// template <char... Chars> constexpr auto operator"" _XZ() {
//     using T = uint64_t; 

//     constexpr std::size_t len = sizeof...(Chars);
//     constexpr std::size_t BITS_PER_SYMBOL = 4;
//     constexpr std::size_t BIT_COUNT = len * BITS_PER_SYMBOL;
//     std::array<char, len> digits{Chars...};
//     TBigInt<BIT_COUNT, T> v;
//     return v.doInitByHexArray(digits);   
// }

#define STRING_SIZE(X) ((sizeof(X) / sizeof(X[0])) - 1 ) 


static_assert( STRING_SIZE("123f555Ffffff45067") == 18 );
static_assert( (STRING_SIZE("123f555Ffffff45067") * 4) == 72 );
static_assert( STRING_SIZE("123") == 3 );
static_assert( STRING_SIZE("") == 0 );

#define BIG_INT_HEX( X , T) TBigInt< (STRING_SIZE(X) * 4) , T>().doInitByString<STRING_SIZE(X)>( X )
