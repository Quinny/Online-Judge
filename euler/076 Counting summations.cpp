#include <iostream>

int main(void){
	int n = 100;
	int a[n+1];
	memset(a,0,sizeof(a));
	a[0] = 1;
	for(int i = 1; i < n; i++){
		for(int j = i; j <= n; j++)
			a[j] += a[j - i];
	}
	std::cout << a[n] << std::endl;
	return 0;
}