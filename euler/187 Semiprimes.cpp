#include <iostream>
#include "PrimeSieve.hpp"
#define LIMIT 100000000

int main(){
	std::vector<long> primes = pe::PrimeSieve<long>::make_vector(50000000);
	long ans = 0;
	for(int i = 0; i < primes.size(); i++){
		if(primes[i] < 10000) ans++;
		for(int j = i + 1; j < primes.size(); j++){
			if(primes[i] * primes[j] < LIMIT) ans++;
			else break;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}