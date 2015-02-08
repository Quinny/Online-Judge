// http://en.wikipedia.org/wiki/Repunit
// http://en.wikipedia.org/wiki/Modular_arithmetic
#include <iostream>
#include "PrimeSieve.hpp"

long big_mod(long, long, long);

int main(){
    auto primes = pe::PrimeSieve<100000>::make_vector();
    long ans = 0;
    for(auto i : primes) {
        long expon = 10;
        bool found = false;
        for(int j = 0; j < 18; j++) { // fine tuned upper-bound baby
            if(big_mod(10, expon, i * 9) == 1){
                found  = true;
                break;
            }
            expon *= 10;
        }
        if(!found)
            ans += i;
    }
    std::cout << ans << std::endl;
    return 0;
}

long big_mod(long x, long y, long m){ // Computes x ^ y % m
    long res = 1;
    while(y > 0){
        if(y % 2 == 1){
            res = (res * x) % m;
        }
        y /= 2;
        x = (x * x) % m;
    }
    return res;
}
