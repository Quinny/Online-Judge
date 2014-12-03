#include <iostream>
#include "PrimeSieve.hpp"

using namespace std;

int main(void){
	pe::PrimeSieve<int> s(110000);
	std::cout << (s.nth_prime(10001)) << std::endl;
	return 0;
}