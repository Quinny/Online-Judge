#include <iostream>
#include <set>

bool is_letter(char);
char to_lower(char);

int main(){
	std::set <char> letters;
	char c;
	while(std::cin >> c){
		if(is_letter(c))
			letters.insert(to_lower(c));
	}
	if(letters.size() == 26)
		std::cout << "pangram" << std::endl;
	else
		std::cout << "not pangram" << std::endl;
	return 0;
}

bool is_letter(char c){
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char to_lower(char c){
	if(c >= 'a' && c <= 'z') return c;
	return c - ('A' - 'a');
}