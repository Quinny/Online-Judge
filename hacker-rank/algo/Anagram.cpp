#include <iostream>
#include <string.h> //memset

int distance(std::string);

int main(){
	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;
		std::cout << distance(s) << std::endl;
	}
	return 0;
}

int distance(std::string s){
	if(s.size() % 2 == 1) return -1;
	int occurances[26];
	memset(occurances, 0, sizeof(occurances));
	for(int i = 0; i < s.size(); i++){
		if(i < s.size() / 2) occurances[s[i] - 'a']++;
		else occurances[s[i] - 'a']--;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++){
		if(occurances[i] > 0) ans += occurances[i];
	}
	return ans;
}