#include <iostream>
#include "PrimeSieve.hpp"

bool four_distinct(int, PrimeSieve&);

int main(){
	PrimeSieve primes(1000000);
	for(int i = 0; i < primes.size(); i++){
		if(four_distinct(i, primes)){
			if(four_distinct(i + 1, primes)){
				if(four_distinct(i + 2, primes)){
					if(four_distinct(i + 3, primes)){
						std::cout << i << std::endl;
						return 0;
					}
					else i += 4;
				}
				else i += 3;
			}
			else i += 2;
		}
	}
	return 0;
}

bool four_distinct(int x, PrimeSieve& primes){
	if(primes[x])
		return false;
	int d = primes.primeAfter(0);
	int c = 0;
	while(x > 1){
		if(x % d == 0){
			c++;
			if(c > 4) return false;
			while(x % d == 0)
				x /= d;
		}
		d = primes.primeAfter(d);
	}
	return c == 4;
}