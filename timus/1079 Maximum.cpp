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
#include <algorithm>

using namespace std;


int main(void){
	int n=100000;
	int ans[n];
	int dp[n];
	dp[0]=0;ans[0]=0;
	dp[1]=1;ans[1]=1;

	for(int i=2;i<n;i++){
		if(i%2==1){
			dp[i]=dp[i/2]+dp[i/2+1];
			ans[i]=max(dp[i],ans[i-1]);
		}
		else{
			dp[i]=dp[i/2];
			ans[i]=ans[i-1];
		}
	}
	while(cin>>n,n!=0){
		cout<<ans[n]<<endl;
	}
}


