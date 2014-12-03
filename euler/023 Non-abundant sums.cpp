#include <iostream>
#include <vector>
#include <map>

#define LIMIT 28123

bool isAbundant(int);

int main(void){
	std::vector<int> abundants;
	for(int i = 2;i <= LIMIT ; i++){
		if(isAbundant(i)) abundants.push_back(i);
	}

	std::map <int,bool> sums;
	for(int i=0;i<abundants.size();i++){
		for(int j=i;j<abundants.size();j++){
			if(abundants[i] + abundants[j] <= LIMIT)
				sums[ abundants[i] + abundants[j] ] = true;
			else
				break;
		}
	}

	int ans = 0;
	for(int i = 1;i <= LIMIT;i++){
		if(sums.find(i) == sums.end()) ans+=i;
	}

	std::cout << ans << std::endl;
	return 0;
}

bool isAbundant(int n){
	int sum = 1;
	for(int i = 2; i*i < n + 1; i++){
		if(n%i == 0){
			if (i != (n/i))
				sum+= i + (n/i);
			else
				sum+=i;
		}
	}
	return sum > n;
}