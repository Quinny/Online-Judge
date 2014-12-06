#include <iostream>
#include <algorithm>
#define LIMIT 10000000

bool is_perm(int, int);

int main(){
	int* phi = new int[LIMIT + 1]; // regular array seg faults for whatever reason
	for(int i = 0; i <= LIMIT; i++)
		phi[i] = i;
	for(int i = 2; i <= LIMIT; i++){
		if(phi[i] == i){
			for(int j = i; j <= LIMIT; j+=i)
				phi[j] = phi[j] / i * (i - 1);
		}
	}
	double min = LIMIT;
	int n = 0;
	for(int i = 2; i <= LIMIT; i++){
		if(is_perm(i, phi[i]) && i / (double)phi[i] < min){
			min = i / (double)phi[i];
			n = i;
		}
	}
	free(phi);
	std::cout << n << std::endl;
	return 0;
}

bool is_perm(int x, int y){
	int occurances_x[10];
	int occurances_y[10];
	memset(occurances_x, 0, sizeof(occurances_x));
	memset(occurances_y, 0, sizeof(occurances_y));
	while(x > 0){
		occurances_x[x % 10]++;
		x /= 10;
	}
	while(y > 0){
		occurances_y[y % 10]++;
		y /= 10;
	}
	for(int i = 0; i < 10; i++){
		if(occurances_x[i] != occurances_y[i]) return false;
	}
	return true;
}