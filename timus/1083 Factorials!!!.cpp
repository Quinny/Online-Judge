#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	long long n,ans=1,lastNum;
	char k[20];

	cin>>n;
	cin>>k;

	int m=strlen(k);
	if(m>=n){
		cout<<n<<endl;
		return 0;
	}

	if (n%m>0) lastNum=(n%m); //determine the last number in the sequence
	else lastNum=m;

	for(int i=0;n-(m*i)>=lastNum;i++)
		ans*=n-(m*i);

	cout<<ans<<endl;
	
	return 0;
}