/*
Consider the sequence of numbers ai, i = 0, 1, 2, …, which satisfies the following requirements:
a0 = 0
a1 = 1
a2i = ai
a2i+1 = ai + ai+1
for every i = 1, 2, 3, … .

Write a program which for a given value of n finds the largest number among the numbers a0, a1, …, an.

(1 ≤ n ≤ 99 999)

*/


#include <iostream>

using namespace std;


int main(void){
	int n=100000; //the maxiumum value of n
	int a[n]; 
	a[0]=0; //initial values 
	a[1]=1;
	for(int i=0;i<n/2;i++){
		a[2*i]=a[i]; //follow the pattern provided and fill in the sequence
		a[2*i+1]=a[i]+a[i+1];
	}

	int c,ans;
	while(cin>>c,c!=0){
		for(int i=0;i<c;i+=2){
			ans=max(a[i],a[i+1]); //go through the first c values keeping track of the largest one
		}
		cout<<ans<<endl;
	}
	return 0;
}


