/*

algorithm learned from: http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
Modified for this solution

*/


#include <iostream>

using namespace std;

int kadane(int[],int n);

int main(void){
	int n;
	cin>>n;
	int a[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>a[i][j];
	}

	int maxSum=INT_MIN;
	int left,right,sum,tmp[n];


	for(left=0;left<n;left++){
		memset(tmp,0,sizeof(tmp));
		for(right=left;right<n;right++){
			for(int i=0;i<n;i++)
				tmp[i]+=a[i][right]; //calculate the sum between the current left and right columns for every row i


			/*

			Find the maximum sum between the left and right columns using kadanes method

			*/
			sum=kadane(tmp,n);

			if(sum>maxSum){ //if the sum is greater than the current max
				maxSum=sum; //update the current mac
			}
		}
	}

	cout<<maxSum<<endl;

	return 0;
}

/*

Kadanes method for finding the maximum sub array contained within a 1D array

*/

int kadane(int a[],int n){
	int currentSum=a[0],maxSum=a[0];
	for(int i=1;i<n;i++){
		if(currentSum<0){
			currentSum=a[i];
		}
		else{
			currentSum+=a[i];
		}
		if(currentSum>maxSum){
			maxSum=currentSum;
		}
	}
	return maxSum;
}