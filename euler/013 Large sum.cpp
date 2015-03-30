#include <iostream>
#include "BigInteger.hpp"

int main(){
	//std::string tmp, n2;
	//std::cin >> tmp;
	BigInteger n1, n2;
    std::cin >> n1;
	while(std::cin >> n2)
		n1 += n2;
	for(int i = 0; i < 10; i++)
		std::cout << n1[i];
	std::cout << std::endl;
	return 0;
}
