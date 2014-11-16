#include <iostream>
#include <vector>

void decode(std::string, int);

int main(){
	int n;
	std::string s;
	std::cin >> n;
	while(n != 0){
		std::cin >> s;
		decode(s, n);
		std::cin >> n;
	}
	return 0;
}

void decode(std::string s, int n){
	std::vector<std::string> v;
	for(int i = 0; i < s.size() / n; i++){
		std::string tmp;
		for(int j = 0; j < n; j++)
			tmp = tmp + s[(n * i) + j];
		if(i % 2 == 1)
			std::reverse(tmp.begin(), tmp.end());
		v.push_back(tmp);
	}
	for(int i = 0; i < n; i++){
		for(auto j:v)
			std::cout << j[i];
	}
	std::cout << std::endl;
}