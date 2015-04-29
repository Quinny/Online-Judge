#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <string>
#include "PrimeSieve.hpp"

long concat(long, long);
bool all_prime(long, long);
bool is_prime(long);
bool belongs(long, std::vector<int> const&);

int main(){
	std::unordered_map<int, std::vector<int>> equiv_class;
	std::vector<unsigned long> primes = pe::PrimeSieve<30000>::make_vector();
    for (auto i : primes) {
		equiv_class[i].push_back(i);
        for (auto j : primes) {
			if(belongs(j, equiv_class[i])){
				equiv_class[i].push_back(j);
				if(equiv_class[i].size() == 5) {
					long ans = std::accumulate(equiv_class[i].begin(),
                                               equiv_class[i].end(), 0);
					std::cout << ans << std::endl;
					return 0;
				}
			}
		}
	}
	return 0;
}

bool belongs(long x, std::vector<int> const& v) {
	for(auto i : v){
		if(!all_prime(i, x))
            return false;
	}
	return true;
}

long concat(long x, long y) {
	long p = 1;
	while(p < y)
		p *= 10;
	return x * p + y;
}

bool all_prime(long x, long y) {
	return is_prime(concat(x, y)) && is_prime(concat(y, x));
}

bool is_prime(long n) {
	if(n <= 3) return n > 1;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(long i = 5; i * i <= n; i += 6){
		if(n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}
