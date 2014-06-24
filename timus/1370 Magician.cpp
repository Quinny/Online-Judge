#include <iostream>

using namespace std;

int main(void){
	int n,m;
	cin>>n>>m;
	m%=n;
	int a[n];

	for(int i=0;i<n;i++)
		cin>>a[i];


	for(int i=0;i<10;i++){
		cout<<a[m];
		m=(m+1)%n;
	}
	
	cout<<endl;

	return 0;
}