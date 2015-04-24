#include <iostream>

bool palindrome(int);

int main(){
	int biggest = 0;
	for(int i= 999; i >= 100; i--){
		for(int j = 999; j >= 100; j--){
			if(palindrome(i * j)) biggest = std::max(biggest, i * j);
		}
	}
	std::cout << biggest << std::endl;

	return 0;
}

bool palindrome(int n){
	int tmp = n;
	int ans = 0;
	while(tmp > 0){
		ans = (ans * 10) + (tmp % 10);
		tmp /= 10;
	}
	return n == ans;
}
