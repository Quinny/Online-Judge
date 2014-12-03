#include <iostream>
#include "PrimeSieve.hpp"
#include <vector>

int ways(int, std::vector<int> const&);

int main(){
	pe::PrimeSieve<int> p(2000);
	std::vector<int> primes = p.to_vector();
	int i = 10;
	while(ways(i, primes) < 5000)
		i++;
	std::cout << i << std::endl;
	return 0;
}

int ways(int n, std::vector<int> const& primes){
	int a[n+1];
	memset(a,0,sizeof(a));
	a[0] = 1;
	for(int i = 0; i < primes.size(); i++){
		for(int j = primes[i]; j <= n; j++)
			a[j] += a[j - primes[i]];
	}
	return a[n];
}