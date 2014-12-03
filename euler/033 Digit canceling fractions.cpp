#include <iostream>

int gcd(int,int);
bool sameFraction(int,int,int,int);

int main(void){
	int num = 1, denom = 1;
	for(int i = 10; i < 100; i++){
		for(int j = i+1; j < 100; j++){
			int n1d1 = i/10;
			int n1d2 = i % 10;

			int n2d1 = j/10;
			int n2d2 = j % 10;
			if(i%10!=0 && j%10!=0){
				if(n1d1 == n2d1 && sameFraction(i,j,n1d2,n2d2)){
					num*=i;
					denom*=j;
				}
				if(n1d1 == n2d2 && sameFraction(i,j,n1d2,n2d1)){
					num*=i;
					denom*=j;
				}
				if(n1d2 == n2d1 && sameFraction(i,j,n1d1,n2d2)){
					num*=i;
					denom*=j;
				}
				if(n1d2 == n2d2 && sameFraction(i,j,n1d1,n2d1)){
					num*=i;
					denom*=j;
				}
			}
		}
	}
	std::cout << denom / num << std::endl;
	return 0;
}

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

bool sameFraction(int n1,int d1,int n2,int d2){
	if(n1 == 0 || d1 == 0 || n2 == 0 || d2 == 0) return false;
	int gcd1 = gcd(n1,d1);
	int gcd2 = gcd(n2,d2);

	return ( (n1/gcd1) == (n2/gcd2) ) && ( (d1/gcd1) == (d2/gcd2) );
}