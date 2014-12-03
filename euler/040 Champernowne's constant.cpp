#include <iostream>
#include <vector>

int numDigits(int);
int index(int);
int nthDigit(int,int);

int main(void){
	int ans=1;
	for(int i=1;i<=1000000;i*=10)
		ans*=index(i);
	std::cout << ans << std::endl;
}

int nthDigit(int d, int n){
	std::vector<int> v;
	while(d > 0){
		v.push_back(d%10);
		d/=10;
	}
	std::reverse(v.begin(),v.end());
	return v[n-1];
}

int index(int d){
	int i = 1;
	while( d > numDigits(i) ){
		d-=numDigits(i);
		i++;
	}
	return nthDigit(i,d);
}

int numDigits(int n){
	int c=0;
	while(n>0){
		c++;
		n/=10;
	}
	return c;
}