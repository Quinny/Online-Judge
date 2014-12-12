#include <iostream>

int main(){
	long long s1 = 0;
	for(int i = 1;i <= 100; i++) s1 += (i * i);
	long long s2 = ((100 * 101) / 2) * ((100 * 101) / 2);
	std::cout << s2 - s1 << std::endl;
	return 0;
}