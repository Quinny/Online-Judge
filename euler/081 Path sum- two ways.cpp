#include <stdio.h>
#define SIZE 80

int min(int,int);

int main(void){
	int a[SIZE][SIZE];
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++)
			scanf("%d%*c",&a[i][j]);
	}
	for(int i = SIZE - 2; i >= 0; i--){
		a[SIZE-1][i] += a[SIZE-1][i+1];
		a[i][SIZE-1] += a[i+1][SIZE-1];
	}
	for(int i = SIZE - 2; i >= 0; i--){
		for(int j = SIZE - 2; j >=0; j--)
			a[i][j] += min(a[i][j+1],a[i+1][j]);
	}
	printf("%d\n",a[0][0]);
	return 0;
}

int min(int x, int y){
	return x < y ? x : y;
}