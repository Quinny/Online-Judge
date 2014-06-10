#include <iostream>

using namespace std;


int main(void){
	int n=100000;
	int a[n];
	a[0]=0;
	a[1]=1;
	for(int i=0;i<n/2;i++){
		a[2*i]=a[i];
		a[2*i+1]=a[i]+a[i+1];
	}

	int c,ans;
	while(cin>>c,c!=0){
		for(int i=0;i<c;i+=2){
			ans=max(a[i],a[i+1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}


