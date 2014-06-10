#include <iostream>

using namespace std;

int main(void){
	int x,y,t;
	cin>>x;
	int a[x];
	for(int i=0;i<x;i++)
		cin>>a[i];

	cin>>y;
	for(int i=0;i<y;i++){
		cin>>t;
		for(int c=0;c<x;c++){
			if(t+a[c]==10000){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
