/*

http://flickeringtubelight.net/blog/2006/08/a-diagonal-through-a-rectangular-grid-of-squares/

*/

#include <iostream>

using namespace std;

int gcd(int,int);

int main(void){
	int n,m;
	cin>>n>>m;
	n--;m--;
	cout<<(n+m-gcd(n,m))<<endl;
	
	return 0;
	
}

int gcd(int n,int m){
	if(m>n)swap(n,m); //just incase
	return m==0?n:gcd(m,n%m);
}