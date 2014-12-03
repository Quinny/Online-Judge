#include <iostream>

int max_xor(int, int);

int main(){
	int a, b;
	std::cin >> a >> b;
	std::cout << max_xor(a, b) << std::endl;
	return 0;
}

int max_xor(int a, int b){
	int m = 0;
	for(int i = a; i <= b; i++){
		for(int j = a + 1; j <= b; j++){
			int tmp = i ^ j;
			m = m > tmp ? m : tmp;
		}
	}
	return m;
}