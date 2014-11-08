#include <iostream>

int maxChar(std::string);
int ctoi(char);
int getRemainder(std::string,int);

int main(void){
	std::string s;
	std::cin >> s;
	int min = maxChar(s);
	if(min == 0){
		std::cout << "2" << std::endl;
		return 0;
	}
	for(int i = min + 1; i <= 36; i++){
		if(getRemainder(s,i) == 0){
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << "No solution." << std::endl;
	return 0;
}

int getRemainder(std::string s, int n){
	int c = 1;
	int r = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		r = (r + ctoi(s[i]) * c) % (n - 1);
		c = (c * n) % (n - 1);
	}
	return r;
}

int maxChar(std::string s){
	int max = 0;
	for(char c: s)
		max = ctoi(c) > max ? ctoi(c) : max;
	return max;
}


int ctoi(char c){
	if(c >= '0' && c <='9')
		return c - '0';
	else
		return c - 'A' + 10;
}