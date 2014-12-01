#include <iostream>
#include <vector>
#include <set>
#include "PrimeSieve.hpp"

long pow_2(long);
long pow_3(long);
long pow_4(long);

int main(){
	int cap = 50000000;
	PrimeSieve p(7072);
	std::vector<int> primes = p.to_vector();
	std::set<long> ans;
	for(auto i:primes){
 		for(auto j:primes){
			for(auto k:primes){
				long tmp = pow_2(i) + pow_3(j) + pow_4(k);
				if(tmp > cap) break;
				else ans.insert(tmp);
			}
		}
	}
	std::cout << ans.size() << std::endl;
	return 0;
}

long pow_2(long x){
	return x * x;
}
long pow_3(long x){
	return x * pow_2(x);
}
long pow_4(long x){
	return x * pow_3(x);
}