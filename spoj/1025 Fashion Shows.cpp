#include <iostream>
#include <algorithm>

int main(){
	int c;
	std::cin >> c;
	for(int i = 0; i < c; i++){
		int n;
		std::cin >> n;
		int men[n];
		int women[n];
		for(int i = 0; i < n; i++)
			std::cin >> men[i];
		for(int i = 0; i < n; i++)
			std::cin >> women[i];
		std::sort(men, men + n);
		std::sort(women, women + n);
		int ans = 0;
		for(int i = n - 1; i >= 0; i--)
			ans += men[i] * women[i];
		std::cout << ans << std::endl;
	}
	return 0;
}