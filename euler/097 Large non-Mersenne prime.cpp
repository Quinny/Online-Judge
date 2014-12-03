#include <iostream>

int main(){
	long ans = 1;
	for(int i = 0; i < 7830457; i++)
		ans = (2 * ans) % 10000000000;
	std::cout << (((ans * 28433) + 1) % 10000000000) << std::endl;
	return 0;
}