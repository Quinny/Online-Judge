#include <iostream>

int reverse(int);

int main(void){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int c, d;
		std::cin >> c >> d;
		std::cout << reverse(reverse(c) + reverse(d)) << std::endl;
	}
	return 0;
}

int reverse(int n){
	int m = 0;
	while(n > 0){
		m = (10 * m) + (n % 10);
		n/=10;
	}
	return m;
}