/*


Your program should print to the output the only number Q. If such a number does not exist print −1.


*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void){
	long long n;
	string ans;
	cin>>n; //read in the number

	if(n==0)cout<<10<<endl;
	else if(n==1)cout<<1<<endl;
	else if(n<10) cout<<n<<endl;
	else{
		bool divide=true;
		while(divide && n!=1){
			divide=false;
			for(int i=9;i>=2;i--){
				if(n%i==0){
					divide=true;
					ans+=(char)(i+'0');
					n/=i;
					break;
				}
			}
		}
		reverse(ans.begin(),ans.end());
		if(divide)cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}


	return 0;
}
