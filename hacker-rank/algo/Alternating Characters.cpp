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
	char prev = s[0];
	for(int i = 1; i < s.size(); i++){
		if(s[i] == prev) ans++;
		prev = s[i];
	}
	return ans;
}