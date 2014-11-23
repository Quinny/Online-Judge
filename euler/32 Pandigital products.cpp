#include <iostream>
#include <set>
#include <numeric>

bool is_pandigital(int, int);
void occurances(int, int[]);

int main(){
	std::set<int> products;
	for(int i = 2; i <= 100; i++){
		for(int j = 100; j <= 9999; j++){
			if(is_pandigital(i, j)) products.insert(i * j);
		}
	}
	std::cout << std::accumulate(products.begin(), products.end(), 0) << std::endl;
	return 0;
}

void occurances(int x, int a[]){
	while(x > 0){
		a[x % 10]++;
		x /= 10;
	}
}

bool is_pandigital(int x, int y){
	int a[10];
	memset(a, 0, sizeof(a));
	occurances(x, a);
	occurances(y, a);
	occurances(x * y, a);
	if(a[0] > 0) return false;
	for(int i = 1; i < 10; i++){
		if(a[i] != 1) return false;
	}
	return true;
}