#include <iostream>

// thanks to this guy http://www.alpertron.com.ar/QUAD.HTM

int main(){
	long end = 1000000000000L;
	long n = 21;
	long b = 15;
	while(n < end){
		long nb = 3 * b + 2 * n - 2;
		long nn = 4 * b + 3 * n - 3;
		b = nb;
		n = nn;
	}
	std::cout << b << std::endl;
	return 0;
}