#include <iostream>
#include <string>

int dist(std::string);

int main(){
	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;
		std::cout << dist(s) << std::endl;
	}
	return 0;
}

int dist(std::string s){
	int ans = 0;
	for(int i = 0; i < s.size() / 2; i++)
		ans += std::abs(s[i] - s[s.size() - i - 1]);
	return ans;
}