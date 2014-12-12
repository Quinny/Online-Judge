#include <iostream>
#include "PrimeSieve.hpp"

int main(){
	pe::PrimeSieve<int> s(110000);
	std::cout << s.nth_prime(10001) << std::endl;
	return 0;
}