#include <iostream>
#include "PrimeSieve.hpp"

std::vector<int> occurance_count(int n) {
    std::vector<int> v(10, 0);
    while (n > 0) {
        v[n % 10]++;
        n /= 10;
    }
    return v;
}

bool is_perm(int x, int y){
	auto v_x = occurance_count(x);
    auto v_y = occurance_count(y);
    return std::equal(v_x.begin(), v_x.end(), v_y.begin());
}

int main(){
	pe::PrimeSieve<10000> primes;
	for(int i = 1000; i < primes.size(); i++){
		int len = primes[i];
		for(int x = 1; x < 3; x++){
			if (primes[i + (x * 3330)] && is_perm(i, i + (x * 3330)))
                ++len;
			else
                break;
		}
		if(len == 3)
			std::cout << i << i + 3330 << i + (6660) << std::endl;
	}
	return 0;
}

