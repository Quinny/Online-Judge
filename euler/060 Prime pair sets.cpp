#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <string>
#include "PrimeSieve.hpp"

long concat(long, long);
bool all_prime(long, long);
bool is_prime(long);
bool belongs(long, std::vector<int>&);

int main(){
	std::unordered_map<int, std::vector<int>> equiv_class;
	std::vector<unsigned long> primes = pe::PrimeSieve<30000>::make_vector();
	for(int i = 0; i < primes.size(); i++){
		int p1 = primes[i];
		equiv_class[p1].push_back(p1);
		for(int j = 0; j < primes.size(); j++){
			int p2 = primes[j];
			if(belongs(p2, equiv_class[p1])){
				equiv_class[p1].push_back(p2);
				if(equiv_class[p1].size() == 5){
					long ans = std::accumulate(equiv_class[p1].begin(), equiv_class[p1].end(), 0);
					std::cout << ans << std::endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

bool belongs(long x, std::vector<int>& v){
	for(auto i : v){
		if(!all_prime(i, x)) return false;
	}
	return true;
}

long concat(long x, long y){
	long p = 1;
	while(p < y)
		p *= 10;
	return x * p + y;
}

bool all_prime(long x, long y){
	return is_prime(concat(x, y)) && is_prime(concat(y, x));
}

bool is_prime(long n){
	if(n <= 3) return n > 1;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(long i = 5; i * i <= n; i += 6){
		if(n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}