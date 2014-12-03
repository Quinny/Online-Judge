#include <iostream>
#include "PrimeSieve.hpp"

bool is_perm(int, int);

int main(){
	PrimeSieve primes(10000);
	for(int i = 1000; i < primes.size(); i++){
		int len = primes[i];
		for(int x = 1; x < 3; x++){
			if(primes[i + (x * 3330)] && is_perm(i, i + (x * 3330))) len++;
			else break;
		}
		if(len == 3){
			std::cout << i << i + 3330 << i + (6660) << std::endl;
		}
	}
	return 0;
}

bool is_perm(int x, int y){
	int a[10];
	memset(a, 0, sizeof(a));
	int b[10];
	memset(b, 0, sizeof(b));
	while(x > 0){
		a[x % 10]++;
		x /= 10;
	}
	while(y > 0){
		b[y % 10]++;
		y /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}