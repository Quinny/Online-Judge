/*

You are given the whole numbers N, M and Y. 
Write a program that will find all whole numbers X in the interval [0, M − 1] such that XN mod M = Y.


*/

#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	int n,m,y;
	bool found=false;
	cin>>n>>m>>y;

	for(int x=0;x<m;x++){
		int tmp=pow(x,n);
		if(tmp%m==y){
			found=true;
			cout<<x<<" ";
		}
	}

	if(!found){
		cout<<"-1";
	}
	cout<<endl;
}
