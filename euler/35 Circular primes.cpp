#include <iostream>
#include <algorithm>
#include <string>
#include "PrimeSieve.hpp"

#define MAX 1000000

bool checkRotate(int, PrimeSieve&);

int main(void){
	PrimeSieve primes(MAX);
	int ans = 0;
	for(int i = 0; i < MAX; i++){
		if(primes[i] && checkRotate(i,primes)) ans++;
	}
	std::cout << ans << std::endl;

	return 0;
}

bool checkRotate(int n, PrimeSieve& primes){
	std::string s = std::to_string(n);
	for(int i = 0; i < s.length(); i++){
		std::rotate(s.begin(),s.end()-1,s.end());
		if(!primes[stoi(s)]) return false;
	}
	return true;
}