#include <iostream>

bool matches(long);

int main(){
	long n = 1000000000;
	while(!matches(n * n))
		n += 1;
	std::cout << n << std::endl;
	return 0;
}

bool matches(long n){
	if(n % 10 != 0) return false;
	n /= 100;
	for(int i = 9; i >= 1; i--){
		if(n % 10 != i) return false;
		n /= 100;
	}
	return true;
}