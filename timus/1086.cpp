#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int);
int nthPrime(int);
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
		if(isPrime(count))n--;
	}
	return count;
}

bool isPrime(int x){
	for(int i=2;i<sqrt(x)+1;i++){
		if(x%i==0)return false;
	}
	return true;
}
