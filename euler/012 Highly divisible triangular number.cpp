#include <iostream>

int divisors(long long);

int main(){
	int sum = 1;
	for(int i = 2; divisors(sum) <= 500; sum += i, i++);
	std::cout << sum << std::endl;
	return 0;
}

int divisors(long long n){
	int ans = 0;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0) ans+=2;
	}
	return ans;
}
