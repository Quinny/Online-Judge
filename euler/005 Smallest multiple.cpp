#include <iostream>

bool valid(int);

int main(){
	int i = 2520;
	while(!valid(i))
		i += 20;
	std::cout << i << std::endl;
	return 0;
}

bool valid(int n){
	for(int i = 2; i <= 20; i++){
		if(n % i != 0) return false;
	}
	return true;
}