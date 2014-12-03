#include <iostream>
#include "PrimeSieve.hpp"

int main(void){
	pe::PrimeSieve<int> primes(1000000);
	int n = 0;
	int mostDivides = 0;
	for(int i = 2; i < primes.size(); i+=2){
		int cur = 0;
		for(int j = 0; j*j < i; j++){
			if(primes[j] && i % j == 0) cur++;
		}
		if(cur > mostDivides){
			mostDivides = cur;
			n = i;
		}
	}
	std::cout << n << std::endl;
	return 0;
}