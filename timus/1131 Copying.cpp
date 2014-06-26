#include <iostream>

using namespace std;

int main(void){
	int n,k,ans=0,copied=1;
	cin>>n>>k;

	while(copied<k && copied*2<n){
		copied<<=1;
		ans++;
	}

	if((n-copied)%k==0)ans+=(n-copied)/k;
	else ans+=((n-copied)/k)+1;

	cout<<ans<<endl;

	return 0;
}