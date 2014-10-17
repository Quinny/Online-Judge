#include <iostream>
#include "PrimeSieve.hpp"

#define MAX 1000000

int checkR(int, PrimeSieve&);
int checkL(int, PrimeSieve&);

int main(void){
	PrimeSieve primes(MAX);
	int ans = 0;
	for(int i=10;i<MAX;i++){
		if(primes[i] && checkR(i,primes) && checkL(i,primes))
			ans+=i;
	}

	std::cout<<ans<<std::endl;
	return 0;
}

int checkL(int n,PrimeSieve& primes){
	std::string s = std::to_string(n);
	while(s.length()>0){
		if(!primes[std::stoi(s)]) return false;
		s = s.substr(1);
	}
	return true;
}
int checkR(int n,PrimeSieve& primes){
	while(n>0){
		if(!primes[n]) return false;
		n/=10;
	}
	return true;
}