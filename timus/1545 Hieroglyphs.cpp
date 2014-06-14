#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;

	char s[n][3];
	char t;

	for(int i=0;i<n;i++)
		cin>>s[i];

	cin>>t;

	for(int i=0;i<n;i++){
		if(t==s[i][0]) cout<<s[i]<<endl;
	}

	return 0;

}