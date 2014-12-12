#include <iostream>

bool triple(int, int, int);

int main(){
	for(int i = 1; i < 1000; i++){
		for(int j = i + 1; j < 1000 - i; j++){
			int k = 1000 - i - j;
			if(triple(i, j, k)){
				std::cout << i * j * k << std::endl;
				return 0;
			}
		}
	}
	return 0;
}

bool triple(int a, int b, int c){
	return a * a + b * b == c * c;
}