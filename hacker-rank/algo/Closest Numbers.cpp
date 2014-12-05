#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	int n, tmp;
	std::vector<int> v;
	std::cin >> n;
	while(n--){
		std::cin >> tmp;
		v.push_back(tmp);
	}
	std::sort(v.begin(), v.end());
	int min = v.back();
	for(int i = 0; i < v.size() - 1; i++)
		min = std::min(min, v[i + 1] - v[i]);
	for(int i = 0; i < v.size() - 1; i++){
		if(v[i + 1] - v[i] == min) std::cout << v[i] << " " << v[i + 1] << " ";
	}
	std::cout << std::endl;
	return 0;
}