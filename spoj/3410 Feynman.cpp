#include <iostream>

int main(){
	int cache[101] = {0};
	cache[0] = 0;
	for(int i = 1; i <= 100; i++)
		cache[i] = (i * i) + cache[i  - 1];
	int n;
	std::cin >> n;
	while(n != 0){
		std::cout << cache[n] << std::endl;
		std::cin >> n;
	}
	return 0;
}