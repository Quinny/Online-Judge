#include <iostream>
#include "PrimeSieve.hpp"

int main(void){
	auto primes = pe::PrimeSieve<1000000>::make_vector();
	int n = 0;
	int mostDivides = 0;
	for(int i = 2; i < 1000000; i+=2){
		int cur = 0;
		for(auto j : primes){
			if(j * j > i) break;
			if(i % j == 0) cur++;
		}
		if(cur > mostDivides){
			mostDivides = cur;
			n = i;
		}
	}
	std::cout << n << std::endl;
	return 0;
}