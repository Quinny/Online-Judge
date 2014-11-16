#include <iostream>

int trailingZeros(int);

int main(void){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int tmp;
		std::cin >> tmp;
		std::cout << trailingZeros(tmp) << std::endl;
	}
	return 0;
}

int trailingZeros(int n){
	int ans = 0;
	while(n > 0){
		ans += n / 5;
		n/=5;
	}
	return ans;
}