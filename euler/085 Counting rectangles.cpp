#include <iostream>

#define FROM 2000000

int choose2(int);
int abs(int);

int main(void){
	int area = 0;
	int dist = FROM;
	for(int i = 1; i < 100; i++){
		for(int j = 1; j < 100; j++){
			int tmp = choose2(i + 1) * choose2(j + 1);
			if(abs(FROM - tmp) < dist){
				area = i * j;
				dist = abs(FROM - tmp);
			}
		}
	}
	std::cout << area << std::endl;
}

int abs(int n){
	return n >= 0 ? n : -1 * n;
}

int choose2(int n){
	return (n * (n - 1)) / 2;
}