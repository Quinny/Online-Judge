#include <iostream>

int fact(int);
int factDigits(int);

int main(){
	int ans = 0;
	for(int i = 3; i <= 40585; i++){
		if(i == factDigits(i)) ans += i;
	}
	std::cout << ans << std::endl;
	return 0;
}

int fact(int n){
	if(n == 0)
		return 1;
	int ans = n;
	for(int i = n - 1; i >= 2; i--)
		ans *= i;
	return ans;
}

int factDigits(int n){
	int ans = 0;
	while(n > 0){
		ans += fact(n%10);
		n /= 10;
	}
	return ans;
}
