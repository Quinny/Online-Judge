#include <iostream>
#include "PrimeSieve.hpp"
#include <numeric>

#define MAX 2000000

int main(){
    auto primes = pe::PrimeSieve<MAX>::make_vector();
    std::cout <<
        std::accumulate(primes.begin(), primes.end(), 0L)
    << std::endl;
    return 0;
}
