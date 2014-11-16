#include <iostream>

int main(void){
	int n = 0;
	std::cin >> n;
	while(n != 42){
		std::cout << n << std::endl;
		std::cin >> n;
	}
	return 0;
}