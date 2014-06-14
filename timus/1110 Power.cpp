/*

You are given the whole numbers N, M and Y. 
Write a program that will find all whole numbers X in the interval [0, M − 1] such that XN mod M = Y.


*/

#include <iostream>

using namespace std;


int pow(int,int,int);

int main(void){
	int n,m,y;
	bool found=false;
	cin>>n>>m>>y;

	for(int x=0;x<m;x++){
		int tmp=pow(x,n,m);
		if(tmp%m==y){
			found=true;
			cout<<x<<" ";
		}
	}

	if(!found){
		cout<<"-1";
	}
	cout<<endl;

	return 0;
}


//the russian peasants method of finding x^n % m for large numbers
// http://mathforum.org/dr.math/faq/faq.peasant.html
int pow(int x,int n,int m){
	int c=x,d=n,r=1;
	while(d>0){
		if(d%2==1) r=(c*r)%m;
		d/=2;
		c=(c*c)%m;
	}
	return r;
}