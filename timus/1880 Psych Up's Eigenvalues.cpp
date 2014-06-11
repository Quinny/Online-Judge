/*

The input data consist of three blocks two lines each. 
The first line of each block contains the number n of a player's eigenvalues (1 ≤ n ≤ 4 000). 
In the second line you are given n distinct integers in ascending order, which are the eigenvalues. 
All the eigenvalues are positive integers not exceeding 109.

*/


#include <iostream>

using namespace std;

int main(void){
	int n1,n2,n3;
	
	cin>>n1;
	int a[n1];

	for(int i=0;i<n1;i++)
		cin>>a[i];

	cin>>n2;
	int b[n2];

	for(int i=0;i<n2;i++)
		cin>>b[i];

	cin>>n3;
	int c[n3];

	for(int i=0;i<n3;i++)
		cin>>c[i];

	int ans=0;
	for(int i=0,j=0,k=0;i<n1;i++){
		while(j<n2 && b[j]<a[i])j++;
		while(k<n3 && c[k]<a[i])k++;

		if(b[j]==a[i] && c[k]==a[i]) ans++;
	}

	cout<<ans<<endl;

	return 0;

}