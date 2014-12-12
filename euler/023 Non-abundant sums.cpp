#include <iostream>
#include <vector>
#include <set>
#define LIMIT 28123

bool abundant(int);

int main(void){
	std::vector<int> abundants;
	for(int i = 2;i <= LIMIT ; i++){
		if(abundant(i)) abundants.push_back(i);
	}
	std::set<int> sums;
	for(int i = 0; i < abundants.size(); i++){
		for(int j = i; j < abundants.size(); j++){
			if(abundants[i] + abundants[j] <= LIMIT)
				sums.insert(abundants[i] + abundants[j]);
			else
				break;
		}
	}
	int ans = 0;
	for(int i = 1;i <= LIMIT;i++){
		if(sums.find(i) == sums.end()) ans += i;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool abundant(int n){
	int sum = 1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			sum += i;
			if(i * i != n) sum += n / i; 
		}
	}
	return sum > n;
}