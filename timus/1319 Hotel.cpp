/*

Display an array diagonally from right to left 

*/


#include <iostream>

using namespace std;

int main(void){

	int n,j=1;
	cin>>n;
	int a[n][n];

	for(int i=0;i<=(n-1)*2;i++){ //used the same technique as 1313 but switched the rows and columns
		for(int x=i;x>=0;x--){
			if(x<n && i-x<n){
				a[i-x][x]=j++;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int x=n-1;x>=0;x--){ //read it backwards
			cout<<a[i][x]<<" ";
		}
		cout<<endl;
	}

	return 0;
}