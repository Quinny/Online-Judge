#include <iostream>

bool is_prime(int);

int main(void){
	double nPrimes = 0;
	double total = 1;
	for(int i = 3 ;; i += 2){
		for(int j = 0;j < 4; j++){
			total++;
			int diag = (i * i) - (j * (i - 1));
			if(is_prime(diag)) nPrimes++;
		}
		if(nPrimes / total < 0.1){
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}

bool is_prime(int n){
	if(n <= 3) return n > 1;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(int i = 5; i * i <= n; i += 6){
		if(n % i == 0 || n % ( i + 2) == 0) return false;
	}
	return true;
}