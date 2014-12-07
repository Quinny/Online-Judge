#include <iostream>

int main(void){
	int n = 60000;
	long a[n+1];
	memset(a,0,sizeof(a));
	a[0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = i; j <= n; j++)
			a[j] = (a[j] + a[j - i]) % 1000000;
		if(a[i] % 1000000 == 0){
			std::cout << i << std::endl;
			return 0;
		}
	}
	return 0;
}