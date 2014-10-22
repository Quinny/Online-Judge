#include <iostream>

int main(void){
	int n = 200;
	int d []= {1, 2, 5, 10, 20, 50, 100, 200};
	int a[n+1];
	memset(a,0,sizeof(a));
	a[0] = 1;
	 
	for (int i = 0; i < 8; i++) {
	    for (int j = d[i]; j <= n; j++) {
	        a[j] += a[j - d[i]];
	    }
	}
	std::cout << a[n] << std::endl;
	return 0;
}