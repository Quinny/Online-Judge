#include <iostream>
#include <set>
#include "PrimeSieve.hpp"

bool hamming_100(std::vector<unsigned long>&, unsigned long);

int main(){
	long ans = 0;
	auto primes = pe::PrimeSieve<100>::make_vector();
	for(long i = 1; i < 1000000000; i++){
		if(hamming_100(primes, i)) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool hamming_100(std::vector<unsigned long>& primes, unsigned long n){
	
}