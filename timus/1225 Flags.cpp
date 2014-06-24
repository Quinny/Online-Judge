#include <iostream>

using namespace std;


int main(void){
	unsigned long long int fib[46],n;
	cin>>n;
	fib[0]=0;fib[1]=1;
	for(int i=2;i<=n;i++) fib[i]=fib[i-1]+fib[i-2];

	
	cout<<(2*fib[n])<<endl;
}