#include <iostream>

int largest_prime(long);

int main(){
	std::cout << largest_prime(600851475143) << std::endl;
	return 0;
}

int largest_prime(long n){
	int prime = 2;
	int largest = 0;
	while(n != 1){
		if(n % prime == 0){
			if(prime > largest) largest = prime;
			prime = 2;
			n /= largest;
		}
		else prime++;
	}
	return largest;
}