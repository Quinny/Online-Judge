#include <iostream>

int divides_repunit(long);
int gcd(int, int);
bool is_prime(int);

int main(){
	int ans = 0, found = 0;
	for(int i = 2; found < 25; i++){
		if(gcd(i, 10) != 1 || is_prime(i)) continue;
		int k = divides_repunit(i);
		if((i - 1) % k == 0){
			ans += i;
			found++;
		}
	}
	std::cout << ans << std::endl;
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