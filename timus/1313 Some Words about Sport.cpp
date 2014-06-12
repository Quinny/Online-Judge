/*


Display an array diagonally from left to right

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int a[n][n];

	for(int i=0;i<n;i++){
		for(int x=0;x<n;x++){
			cin>>a[i][x];
		}
	}

	for(int i=0;i<=(n-1)*2;i++){
		for(int x=i;x>=0;x--){
			if(x<n && i-x<n){
				cout<<a[x][i-x]<<" ";
			}
			
			
		}
	}
	cout<<endl;

	return 0;
}