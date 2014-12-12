#include <iostream>
#include "PrimeSieve.hpp"

#define MAX 2000000

int main(){
	pe::PrimeSieve<int> s(MAX);
	unsigned long long ans = 0;
	for(int i = 0; i <= MAX; i++){
		if(s[i]) ans += i;
	}
	std::cout << ans << std::endl;
	return 0;
}