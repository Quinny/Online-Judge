#include <iostream>
#include "../euler/BigInteger.hpp"

int main(void){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int c;
		std::cin >> c;
		BigInteger x(c + 1);
		while(x != x.reverse()) x = x + 1;
		std::cout << x.toString() << std::endl;
	}
	return 0;
}