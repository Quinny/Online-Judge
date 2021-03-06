#include <iostream>
#include "BigInteger.hpp"

int main(){
	int term = 1;
	BigInteger n1(0), n2(1), cur;
	while(cur.length() != 1000){
		term++;
		cur = n1 + n2;
		n1 = n2;
		n2 = cur;
	}
	std::cout << term << std::endl;
	return 0;
}
