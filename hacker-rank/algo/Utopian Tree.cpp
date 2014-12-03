#include <iostream>

int height(int);

int main(){
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		std::cout << height(n) << std::endl;
	}
	return 0;
}

int height(int n){
	int h = 1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0) h *= 2;
		else h++;
	}
	return h;
}