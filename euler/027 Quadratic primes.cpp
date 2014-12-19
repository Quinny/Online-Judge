#include <iostream>
#include "PrimeSieve.hpp"
#define MAX 2000000

int consec_primes(int, int, pe::PrimeSieve<MAX>&);

int main(){
	pe::PrimeSieve<MAX> primes;
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

int consec_primes(int a, int b, pe::PrimeSieve<MAX>& p){
	long n = 0;
	long c = 0;
	while(((n * n) + (a * n) + b) > 0 && p[(n * n) + (a * n) + b]){
		c++;
		n++;
	}
	return c;
}