#include <iostream>

int main(){
	unsigned long long a, b, n, c;
	std::cin >> a >> b >> n;
	for(int i = 2; i < n; i++){
		c = (b * b) + a;
		a = b * b;
		b = c;
	}
	std::cout << c << std::endl;
	return 0;
}