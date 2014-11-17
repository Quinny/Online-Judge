#include <iostream>
#include <vector>
#include <algorithm>

int lastDigit(int, int);

int main(){
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++){
		int b, e;
		std::cin >> b >> e;
		std::cout << lastDigit(b, e) << std::endl;
	}
	return 0;
}

int lastDigit(int b, int e){
	if(e == 0)
		return 1;
	std::vector<int> cycle;
	int n = b;
	int c = 1;
	while(std::find(cycle.begin(), cycle.end(), n % 10) == cycle.end() && c < e){
		cycle.push_back(n % 10);
		n *= b;
		c++;
	}
	if(e == c)
		return n % 10;
	if(e % cycle.size() == 0)
		return cycle[cycle.size() - 1];
	return cycle[e % cycle.size() - 1];
}