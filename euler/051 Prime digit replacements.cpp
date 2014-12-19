#include <iostream>
#include "PrimeSieve.hpp"
#include <vector>

int family_size(int, pe::PrimeSieve<1000000>&);
std::vector<unsigned long> repeats(int);
std::vector<unsigned long> dig_vector(int);
int replace(std::vector<unsigned long>&, int, int);

int main(){
	pe::PrimeSieve<1000000> p;
	std::vector<unsigned long> primes = p.to_vector();
	for(auto i : primes){
		if(family_size(i, p) == 8){
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}

std::vector<unsigned long> dig_vector(int n){
	std::vector<unsigned long> v;
	while(n > 0){
		v.push_back(n % 10);
		n /= 10;
	}
	std::reverse(v.begin(), v.end());
	return v;
}

std::vector<unsigned long> repeats(int n){
	std::vector<unsigned long> r;
	int occurances[10];
	memset(occurances, 0, sizeof(occurances));
	while(n > 0){
		occurances[n % 10]++;
		n /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(occurances[i] > 1) r.push_back(i);
	}
	return r;
}

int replace(std::vector<unsigned long>& digits, int x, int y){
	if(digits[0] == x && y == 0) return 4; // not really super elegant, but leading zeros shouldnt count
	int n = 0;
	for(auto i : digits){
		if(i == x) n = (10 * n) + y;
		else n = (10 * n) + i;
	}
	return n;
}

int family_size(int n, pe::PrimeSieve<1000000>& primes){
	int s = 0;
	auto orig = dig_vector(n);
	auto rep = repeats(n);
	for(int i : rep){
		int tmp = 0;
		for(int j = 0; j <= 9; j++){
			int check = replace(orig, i, j);
			if(primes[check]) tmp++;
		}
		s = std::max(tmp, s);
	}
	return s;
}