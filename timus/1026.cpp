#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(void){
	int n,b;
	string tmp;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cin>>tmp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b;
		cout<<a[b-1]<<endl;
	}
	return 0;
}
