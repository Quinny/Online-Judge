#include <iostream>

int count(int);

int main(){
	int t;
	std::cin >> t;
	for(int i = 0; i < t; i++){
		int n;
		std::cin >> n;
		std::cout << count(n) << std::endl;
	}
	return 0;
}

int count(int n){
	int tmp = n;
	int c = 0;
	while(tmp > 0){
		if(tmp % 10 != 0 && n % (tmp % 10) == 0)
			c++;
		tmp /= 10;
	}
	return c;
}