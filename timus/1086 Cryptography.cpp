/*

First line contains a positive integer k. Then k positive integers follow (one in each line). The numbers don't exceed 15000.

For each number n you should output the n-th by order prime number. Each number should be in its line.

*/

#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int); //given an integer, this function will return true if it is prime, and false otherwise
int nthPrime(int); //given an integer n, this function will find the nth prime number

int main(void){
	int ans[15000];
	ans[0]=2;
	int n,a,sz=1;
	for(int i=3;sz<15000;i+=2){
		if(isPrime(i)){
			ans[sz]=i;
			sz++;
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cout<<(ans[a-1])<<endl;
	}
	return 0;
}

bool isPrime(int x){
	for(int i=2;i<sqrt(x)+1;i++){
		if(x%i==0)return false;
	}

	return true;
}
