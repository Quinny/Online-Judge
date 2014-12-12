#include <iostream>
#include "BigInteger.hpp"

int main(){
	BigInteger x("100");
	for(int i = 99; i >= 2; i--)
		x *= i;
	int ans = 0;
	for(char c:x)
		ans += c-'0';
	std::cout << ans << std::endl;
	return 0;
}