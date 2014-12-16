#include <iostream>
#define LIMIT 10000000

int divisors(int);

int main(){
	int ans = 0;
	int last = divisors(2);
	for(int i = 3; i < LIMIT; i++){
		int cur = divisors(i);
		if(cur == last) ans++;
		last = cur;
	}
	std::cout << ans << std::endl;
	return 0;
}

int divisors(int n){
	int ans = 2;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			ans++;
			if(i * i != n) ans++;
		}
	}
	return ans;
}