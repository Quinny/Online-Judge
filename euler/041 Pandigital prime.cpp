#include <iostream>
#include "PrimeSieve.hpp"

int num_digits(int);
bool is_pandig(int);

int main(){
	pe::PrimeSieve<7654321> primes;
	for(int i = primes.size() - 1; i >= 0; i--){
		if(primes[i] && is_pandig(i)){
			std::cout << i << std::endl;
			return 0;
		}
	}
	return 0;
}

int num_digits(int n){
	int d = 0;
	while(n > 0){
		d++;
		n /= 10;
	}
	return d;
}

bool is_pandig(int n){
	int size = num_digits(n);
	int a[size + 1];
	memset(a, 0, sizeof(a));
	int c = 0;
	while(n > 0){
		if(n % 10 <= size && a[n % 10] == 0){
			a[n % 10]++;
			c++;
		}
		else
			return false;
		n /= 10;
	}
	return c == size;
}