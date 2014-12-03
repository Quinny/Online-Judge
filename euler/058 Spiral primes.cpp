#include <iostream>
#include "PrimeSieve.hpp"
#define MAX 20000000

bool is_prime(int);

int main(void){
	pe::PrimeSieve<long> primes(20000000);
	double nPrimes = 0;
	double total = 1;
	int max = 0;
	for(int i = 3 ;; i += 2){
		for(int j = 0;j < 4; j++){
			total++;
			int diag = (i * i) - (j * (i - 1));
			max = max > diag ? max : diag;
			if(diag < MAX){
				if(primes[diag]) nPrimes++;
			}
			else{
				if(is_prime(diag)) nPrimes++;
			}

		}
		if(nPrimes / total < 0.1){
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}

bool is_prime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}