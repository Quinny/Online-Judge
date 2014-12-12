#include <iostream>

int main(){
	int sum = 1;
	for(int i = 3; i <= 1001; i += 2){
		for(int j = 0; j < 4; j++)
			sum += (i * i) - (j * (i - 1));
	}
	std::cout << sum << std::endl;
	return 0;
}