#include <iostream>

int main(){
	int n, m;
	long total = 0;
	std::cin >> n >> m;
	while(m--){
		long s, e, amount;
		std::cin >> s >> e >> amount;
		total += ((e - s) + 1) * amount;
	}
	std::cout << total / n << std::endl;
	return 0;
}