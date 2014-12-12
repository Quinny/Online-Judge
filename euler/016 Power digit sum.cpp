#include <iostream>
#include "BigInteger.hpp"

int main(){
	BigInteger n(2);
	int ans = 0;
	for(int i = 0; i < 999; i++)
		n += n;
	for(int i = 0; i < n.length(); i++)
		ans += n[i];
	std::cout << ans << std::endl;
	return 0;
}