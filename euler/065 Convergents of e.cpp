#include <iostream>
#include <vector>
#include "BigInteger.hpp"

std::pair<BigInteger, BigInteger> add_frac(BigInteger, BigInteger, BigInteger, BigInteger);
int sum_digits(BigInteger);

int main(){
	std::vector<int> a;
	std::pair<BigInteger, BigInteger> f;
	a.push_back(2);
	int term = 100;
	for(int i = 2; a.size() < term; i += 2){
		a.push_back(1);
		a.push_back(i);
		a.push_back(1);
	}
	f.first = 1;
	f.second = a[term - 1];
	for(int i = term - 2; i >= 0; i--){
		f = add_frac(f.first, f.second, a[i], 1);
		std::swap(f.first, f.second);
	}
	std::cout << sum_digits(f.second) << std::endl;
	return 0;
}

int sum_digits(BigInteger n){
	long ans = 0;
	for(int i = 0; i < n.size(); i++)
		ans += n[i];
	return ans;
}

std::pair<BigInteger, BigInteger> add_frac(BigInteger a, BigInteger b, BigInteger c, BigInteger d){
	std::pair<BigInteger, BigInteger> ans;
	ans.first = (a * d + b * c);
	ans.second = (b * d);
	return ans;
}