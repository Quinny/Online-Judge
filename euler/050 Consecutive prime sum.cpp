#include <iostream>
#include "PrimeSieve.hpp"

#define MAX 1000000

int main(void){
	pe::PrimeSieve<MAX> primes;
	int sum = 0;
	int terms = 0;
	int n = 0;
	int maxTerms = 0;
	for(int i=0;i<MAX;i++){
		for(int j=i;j<MAX;j++){
			if(primes[j]){
				sum+=j;
				terms++;
			}
			if(sum >= MAX) break;
			if(primes[sum]){
				if(terms > maxTerms){
					maxTerms = terms;
					n = sum;
				}
			}
		}
		sum = 0;
		terms = 0;
	}
	std::cout << n << std::endl;
}