#include <iostream>
#include <cmath>

bool isPentagonal(long);

int main(void){
	int n = 144;
	long hex = 0;
	while(true){
		hex = n * (2 * n - 1);
		if(isPentagonal(hex)) break;
		n++;
	}
	std::cout << hex << std::endl;
}

bool isPentagonal(long n){
	double penTest = (sqrt(1 + 24 * n) + 1.0) / 6.0;
    return penTest == ((int)penTest);
}