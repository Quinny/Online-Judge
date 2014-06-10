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
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cout<<nthPrime(a)<<endl;
	}
	return 0;
}

int nthPrime(int n){
	int count=0;
	while(n!=0){
		count++;
		if(isPrime(count))n--; //everytime a prime number is found subtract 1 from n
	}
	return count;
}

bool isPrime(int x){
	for(int i=2;i<sqrt(x)+1;i++){
		if(x%i==0)return false;
	}

	return true;
}
