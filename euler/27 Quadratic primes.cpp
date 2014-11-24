#include <iostream>
#include "PrimeSieve.hpp"

int consec_primes(int, int, PrimeSieve&);

int main(){
	PrimeSieve primes(2000000);
	int max = 0, prod = 0;
	for(int a = -1000; a < 1000; a++){
		for(int b = -1000; b < 1000; b++){
			int tmp = consec_primes(a, b, primes);
			if(tmp > max){
				max = tmp;
				prod = a * b;
			}
		}
	}
	std::cout << prod << std::endl;
	return 0;
}

int consec_primes(int a, int b, PrimeSieve& p){
	int n = 0;
	int c = 0;
	while(p[(n * n) + (a * n) + b]){
		c++;
		n++;
	}
	return c;
}