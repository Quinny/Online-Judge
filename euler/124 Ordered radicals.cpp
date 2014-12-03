#include <iostream>
#include <vector>
#include <algorithm>
#include "PrimeSieve.hpp"

bool compare(std::pair<int, int> x, std::pair<int, int> y) {
	if(x.second == y.second)
		return x.first < y.first;
	return x.second < y.second;
}

int rad(int, std::vector<int> const&);

int main(){
	pe::PrimeSieve<int> p(100001);
	std::vector<int> primes = p.to_vector();
	std::vector <std::pair<int, int>> v;
	for(int i = 1; i <= 100000; i++)
		v.push_back(std::make_pair(i, rad(i, primes)));
	std::sort(v.begin(), v.end(), compare);
	std::cout << v[9999].first << std::endl;
	return 0;
}

int rad(int x, std::vector<int> const& primes){
	int ans = 1;
	int i = 0;
	while(x > 1){
		if(x % primes[i] == 0)
			ans *= primes[i];
		while(x % primes[i] == 0)
			x /= primes[i];
		i++;
	}
	return ans;
}