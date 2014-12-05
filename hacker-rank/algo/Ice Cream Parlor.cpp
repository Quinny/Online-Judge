#include <iostream>
#include <map>

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n, m;
		std::map<int, int> c;
		std::cin >> m >> n;
		for(int i = 0; i < n; i++){
			int x;
			std::cin >> x;
			if(c.find(x) != c.end())
				std::cout << c[x] << " " << i + 1 << std::endl;
			else c[m - x] = i + 1;
		}
	}
	return 0;
}