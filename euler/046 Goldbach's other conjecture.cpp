#include <iostream>
#include "PrimeSieve.hpp"
#include <cmath>

#define LIMIT 100000

bool is_square(int);

int main(){
	pe::PrimeSieve<LIMIT> primes;
	for(int i = 1; i < LIMIT; i += 2){
		bool found = false;
		if(!primes[i]){
			for(int j = 0; j < primes.size() && !found; j++){
				if(primes[j] && is_square((i - j) / 2)){
					found = true;
					break;
				}
			}
		}
		if(!found && !primes[i]){
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}

bool is_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}
