#include <iostream>

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n, tmp;
		std::cin >> n;
		std::cin >> tmp;
		int max_con = tmp, current = tmp, max = tmp > 0 ? tmp : 0;
		for(int i = 1; i < n; i++){
			std::cin >> tmp;
			if(current < 0) current = tmp;
			else current += tmp;
			if(current > max_con) max_con = current;
			if(tmp > 0) max += tmp;
		}
		if(max_con < 0) std::cout << max_con << " " << max_con << std::endl;
		else std::cout << max_con << " " << max << std::endl;
	}
	return 0;
}