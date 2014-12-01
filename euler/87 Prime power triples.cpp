#include <iostream>
#include <vector>
#include <set>
#include "PrimeSieve.hpp"

int pow_2(int);
int pow_3(int);
int pow_4(int);

int main(){
	int cap = 50000000;
	PrimeSieve p(7071);
	std::vector<int> primes = p.to_vector();
	std::set<int> ans;
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

int pow_2(int x){
	return x * x;
}
int pow_3(int x){
	return x * pow_2(x);
}
int pow_4(int x){
	return x * pow_3(x);
}