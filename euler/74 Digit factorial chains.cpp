#include <iostream>
#include <set>
#include <unordered_map>

int chain_length(int, std::unordered_map<int, int>&);
int fact_dig(int);
int fact(int);

int main(){
	int ans = 0;
	std::unordered_map<int, int> cache;
	for(int i = 1; i < 1000000; i++){
		if(chain_length(i, cache) == 60)
			ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

int fact_dig(int n){
	int ans = 0;
	while(n > 0){
		ans += fact(n % 10);
		n /= 10;
	}
	return ans;
}

int fact(int n){
	if(n == 0) return 1;
	int ans = n;
	for(int i = 2; i < n; i++)
		ans *= i;
	return ans;
}

int chain_length(int n, std::unordered_map<int, int>& cache){
	std::set<int> chain;
	chain.insert(n);
	int m = fact_dig(n);
	while(chain.find(m) == chain.end()){
		if(cache.find(m) != cache.end())
			return chain.size() + cache[m];
		chain.insert(m);
		m = fact_dig(m);
	}
	cache[n] = chain.size();
	return chain.size();
}