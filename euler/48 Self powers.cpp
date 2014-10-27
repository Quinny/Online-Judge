#include <iostream>

int main(void){
	long ans = 0;
	long trim = 10000000000;
	for(int i = 1; i <= 1000; i++){
		long tmp = i;
		for(int j = 1; j < i; j++){
			tmp *= i;
			tmp %= trim;
		}
		ans += tmp;
		ans %= trim;
	}
	std::cout << ans << std::endl;
	return 0;
}