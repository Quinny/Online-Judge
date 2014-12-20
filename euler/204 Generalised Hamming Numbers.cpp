#include <iostream>
#include "PrimeSieve.hpp"
#define MAX 1000000001

int main(){
	auto primes = pe::PrimeSieve<100>::make_vector();
	bool* h_nums = new bool[1000000001];
	h_nums[1] = true;
	long ans = 1;
	for(long i = 0; i < MAX; i++){
		if(h_nums[i]){
			for(auto j : primes){
				if(i * j <= MAX && !h_nums[i * j]){
					ans++;
					h_nums[i * j] = true;
				}
			}
		}
	}
	std::cout << ans << std::endl;
	delete[] h_nums;
	return 0;
}