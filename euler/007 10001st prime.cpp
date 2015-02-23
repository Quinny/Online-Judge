#include <iostream>
#include "PrimeSieve.hpp"

int main(){
	auto v = pe::PrimeSieve<110000>::make_vector();
	std::cout << v[10001] << std::endl;
	return 0;
}
