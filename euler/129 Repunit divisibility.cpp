#include <iostream>

int divides_repunit(long);
int gcd(int, int);

int main(){
	for(int i = 1000000 ;; i++){
		if(gcd(i, 10) != 1) continue;
		if(divides_repunit(i) > 1000000){
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b % a, a);
}

int divides_repunit(long n){ // returns the k for which n divides R(k)
	int rem = 1, k = 1;
	while(rem != 0){
		rem = (10 * rem + 1) % n;
		k++;
	}
	return k;
}