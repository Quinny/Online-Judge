#include <iostream>

#define LIMIT 1000000000

long reverse(long);
bool allOdd(long);

int main(void){
	int ans = 0;
	for(int i = 1; i <= LIMIT; i++){
		if(i % 10 !=0 && allOdd(i + reverse(i))) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool allOdd(long n){
	while(n > 0){
		if(n % 2 == 0) return false;
		n/=10;
	}
	return true;
}

long reverse(long n){
	long m = 0;
	while(n > 0){
		m = (10 * m) + (n % 10);
		n/=10;
	}
	return m;
}