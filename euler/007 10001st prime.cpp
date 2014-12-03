#include <iostream>
#include "PrimeSieve.hpp"

using namespace std;

int main(void){
	PrimeSieve s(110000);
	std::cout << (s.nthPrime(10001)) << std::endl;
	return 0;
}