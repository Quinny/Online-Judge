#include <iostream>

using namespace std;

int main(void){

	int n,currentSum,maxSum;
	cin>>n;
	cin>>currentSum;

	maxSum=currentSum;

	for(int i=1,tmp;i<n;i++){
		cin>>tmp;
		if(currentSum<0){
			currentSum=tmp;
		}
		else{
			currentSum+=tmp;
		}
		if(currentSum>maxSum){
			maxSum=currentSum;
		}
	}

	if(maxSum<0){
		cout<<0<<endl;
		return 0;
	}
	else{
		cout<<maxSum<<endl;
		return 0;
	}
}