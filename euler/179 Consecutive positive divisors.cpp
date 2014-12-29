#include <iostream>

int main(){
	const long LIMIT = 10000000;
	int* divisors = new int[LIMIT + 1];
	memset(divisors, 0, LIMIT + 1);
	for(int i = 2; i <= LIMIT / 2; i++){
		for(int j = 2; i * j < LIMIT; j++){
			divisors[i * j]++;
		}
	}
	
	long ans = 0;
	for(int i = 2; i < LIMIT; i++){
		if(divisors[i] == divisors[i + 1]) ans++;
	}
	std::cout << ans << std::endl;
	delete[] divisors;
	return 0;
}