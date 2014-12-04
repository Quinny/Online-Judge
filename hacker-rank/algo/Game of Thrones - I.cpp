#include <iostream>

bool poss_palindrome(std::string);

int main(){
	std::string s;
	std::cin >> s;
	if(poss_palindrome(s)) std::cout << "YES";
	else std::cout << "NO";
	std::cout << std::endl;
	return 0;
}


bool poss_palindrome(std::string s){
	int occurances[26];
	memset(occurances, 0, sizeof(occurances));
	for(auto i : s)
		occurances[i - 'a']++;
	int o = 0;
	for(int i = 0; i < 26; i++){
		if(occurances[i] % 2 == 1) o++;
		if(o > 1) return false;
	}
	return true;
}