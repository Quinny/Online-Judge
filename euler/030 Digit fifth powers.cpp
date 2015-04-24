#include <iostream>
#define MAX 500000

bool valid(int);
int pow_5(int);

int main(){
	int ans = 0;
	for(int i = 2; i < MAX; i++){
		if(valid(i))
			ans += i;
	}
	std::cout << ans << std::endl;
	return 0;
}

int pow_5(int x){
	return x * x * x * x * x;
}

bool valid(int n){
	int sum = 0;
	int tmp = n;
	while(tmp > 0){
		sum += pow_5(tmp % 10);
		tmp /= 10;
	}
	return sum == n;
}
