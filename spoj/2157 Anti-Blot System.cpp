#include <iostream>
#include <string>

bool hasMachula(std::string);
int atoi(std::string);

int main(){
	std::string add1, add2, sum;
	char op;
	int n;
	std::cin >> n;
	while(n--){
		std::cin >> add1 >> op >> add2 >> op >> sum;
		if(hasMachula(add1)){
			int missing = atoi(sum) - atoi(add2);
			std::cout << missing << " + " << add2 << " = " << sum << std::endl; 
		}
		else if(hasMachula(add2)){
			int missing = atoi(sum) - atoi(add1);
			std::cout << add1 << " + " << missing << " = " << sum << std::endl; 
		}
		else{
			int missing = atoi(add1) + atoi(add2);
			std::cout << add1 << " + " << add2 << " = " << missing << std::endl; 
		}
	}
	return 0;
}

bool hasMachula(std::string s){
	for(char c:s)
		if(c == 'm') return true;
	return false;
}

int atoi(std::string s){
	int ans = 0;
	for(char c:s)
		ans = (ans * 10) + (c - '0');
	return ans;
}