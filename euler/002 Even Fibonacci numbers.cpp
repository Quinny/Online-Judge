#include <iostream>

int main(){
	int n1 = 0, n2 = 1, cur = 0, ans = 0;
	while(cur < 4000000){
		cur = n1 + n2;
		n1 = n2;
		n2 = cur;
		if(cur % 2 == 0) ans += cur;
	}
	std::cout << ans << std::endl;
	return 0;
}
