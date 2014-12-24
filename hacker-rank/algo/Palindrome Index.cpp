#include <iostream>

int find_index(std::string);
bool palindrome(std::string s, int);

int main(){
	int t;
	std::cin >> t;
	while(t--){
		std::string s;
		std::cin >> s;
		std::cout << find_index(s) << std::endl;
	}
	return 0;
}

bool palindrome(std::string s, int e){
	s.erase(e, 1);
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] != s[len - i - 1]) return false;
	}
	return true;
}

int find_index(std::string s){
	int len = s.size();
	for(int i = 0; i < len; i++){
		if(s[i] != s[len - i - 1]){
			if(palindrome(s, i)) return i;
			else return len - i - 1;
		}
	}
	return -1;
}