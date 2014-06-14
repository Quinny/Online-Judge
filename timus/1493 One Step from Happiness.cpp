#include <iostream>

using namespace std;

bool isLucky(int n);

int main(void){
	int t;

	cin>>t;

	if(isLucky(t+1) || isLucky(t-1)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;

	return 0;
}

bool isLucky(int n){
	int a=0,b=0;

	for(int i=0;i<3;i++){
		a+=n%10;
		n/=10;
	}
	for(int i=0;i<3;i++){
		b+=n%10;
		n/=10;
	}

	return a==b;
}