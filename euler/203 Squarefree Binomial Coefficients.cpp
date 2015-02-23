#include <iostream>
#include <set>
#include <vector>
#include "PrimeSieve.hpp"

std::set<long> unique_row(int);
bool square_free(long, std::vector<unsigned long>&);

int main(){
	long ans = 0;
	auto primes = pe::PrimeSieve<11243247>::make_vector();
	std::set<long> all_rows;
	for(int i = 0; i < 51; i++){
		auto s = unique_row(i);
		for(auto e : s)
			all_rows.insert(e);
	}
	for(auto e : all_rows){
		if(square_free(e, primes)) ans += e;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool square_free(long n, std::vector<unsigned long>& primes){
	int i = 0;
	while(primes[i] * primes[i] <= n){
		if(n % (primes[i] * primes[i]) == 0) return false;
		i++;
	}
	return true;
}

std::set<long> unique_row(int n){
	std::vector<long> row {1};
	std::set<long> uniques;
	for(int i = 0; i < n; i++){
		row.push_back(row[i] * (n - i) / (i + 1));
		uniques.insert(row[i]);
	}
	return uniques;
}
