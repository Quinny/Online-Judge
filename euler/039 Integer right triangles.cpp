#include <iostream>
#define MAX 1000

int solutionsFor(int);
bool isTriple(int,int,int);

int main(void){
	int max = 0;
	int p = 0;
	for(int i = 3; i <= MAX; i++){
		int tmp = solutionsFor(i);
		if(tmp > max){
			max = tmp;
			p = i;
		}
	}
	std::cout << p << std::endl;
	return 0;
}

bool isTriple(int a,int b,int c){
	return (a*a)+(b*b)==(c*c);
}

int solutionsFor(int p){
	int ans = 0;
	for(int i = 1; i < p; i++){
		for(int j = i + 1; j < p - i; j++){
			int k = p - i - j;
			if(isTriple(i, j, k)) ans++;
		}
	}
	return ans;
}