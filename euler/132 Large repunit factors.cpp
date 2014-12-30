// http://en.wikipedia.org/wiki/Repunit
// http://en.wikipedia.org/wiki/Modular_arithmetic
#include <iostream>
#include "PrimeSieve.hpp"

long big_mod(long, long, long);

int main(){
	long expon = 1000000000L;
	auto primes = pe::PrimeSieve<1000000>::make_vector();
	int found = 0, i = 0, ans = 0;
	while(found < 40){
		if(big_mod(10, expon, primes[i] * 9) == 1){
			found++;
			ans += primes[i];
		}
		i++;
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