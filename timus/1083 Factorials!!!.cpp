#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	long long n,ans;
	char k[20];

	cin>>n;
	cin>>k;

	int m=strlen(k);
	if(m>n){
		cout<<n<<endl;
		return 0;
	}

	if (n%m>0) ans=(n%m);
	else ans=m;

	for(int i=0;n-(m*i)>1;i++)
		ans*=n-(m*i);

	cout<<ans<<endl;
	
	return 0;
}