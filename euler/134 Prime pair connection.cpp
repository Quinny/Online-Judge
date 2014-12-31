#include <iostream>
#include "PrimeSieve.hpp"

long min_s(unsigned long, unsigned long, unsigned long);

int main(){
	auto primes = pe::PrimeSieve<1000000 + 100>::make_vector();
	long m = 100;
	long ans = 0;
	for(int i = 2; i < primes.size() - 1; i++){
		if(primes[i] > 1000000) break;
		if(primes[i] > m) m *= 10;
		ans += min_s(primes[i], primes[i + 1], m);
	}
	std::cout << ans << std::endl;
	return 0;
}

long min_s(unsigned long p1, unsigned long p2, unsigned long m){
	int i = 0;
	while((p2 * i) % m != p1)
		i++;
	return p2 * i;
}