#include <iostream>

#define LIMIT 10000

int sum_propers(int);

int main(void){
	int ans = 0;
	for(int i = 0; i <= LIMIT; i++){
		int sum1 = sum_propers(i);
		if(sum1 > i && sum1 < LIMIT){
			int sum2 = sum_propers(sum1);
			if(sum2 == i) ans += i + sum1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

int sum_propers(int n){
	int sum = 1;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			sum += i;
			if(i * i != n) sum += n / i;
		}
	}
	return sum;
}