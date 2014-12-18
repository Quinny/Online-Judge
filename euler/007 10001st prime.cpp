#include <iostream>
#include "PrimeSieve.hpp"

int main(){
	pe::PrimeSieve<long> s(110000);
	std::cout << s.nth_prime(10001) << std::endl;
	return 0;
}