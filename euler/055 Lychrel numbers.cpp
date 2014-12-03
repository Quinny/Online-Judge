#include <iostream>

#define MAX 10000

int reverse(int);
bool isLychrel(int);

int main(void){
	int ans = 0;
	for(int i = 0; i < MAX; i++){
		if(isLychrel(i)) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool isLychrel(int n){
	int rev = reverse(n);
	bool found = false;
	for(int i = 0; i < 50; i++){
		int tmp = reverse(n + rev);
		if(n + rev ==  tmp){
			std::cout << tmp << std::endl;
			found = true;
			break;
		}
		n = n + rev;
		rev = tmp;
	}
	return found;
}

int reverse(int n){
	int ans = 0;
	while(n > 0){
		ans = (10*ans) + (n%10);
		n/=10;
	}
	return ans;
}