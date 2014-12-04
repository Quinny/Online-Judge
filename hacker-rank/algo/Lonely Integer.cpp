#include <iostream>

int main(){
	int n, x, y;
	std::cin >> n;
	std::cin >> x;
	for(int i = 1; i < n; i++){
		std::cin >> y;
		x = x ^ y;
	}
	std::cout << x << std::endl;
	return 0;
}