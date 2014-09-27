#include <iostream>

using namespace std;


string addBig(string,string);

int main(void){

	string n1,n2;

	cin>>n1;

	while(cin>>n2)
		n1=addBig(n1,n2);

	for(int i=0;i<10;i++)
		cout<<n1[i];

	cout<<endl;

	return 0;
}


string addBig(string n,string m){

	int length=n.length();

	if(length>m.length()){
		for(int i=0;i<=n.length()-m.length();i++)
			m="0"+m;
	}

	int carry=0;

	string ans="";

	for(int i=length-1;i>=0;i--){

		int val=(n[i]-'0')+(m[i]-'0')+carry;

		if(val>9){
			ans=to_string(val%10)+ans;
			carry=1;
		}
		else{
			ans=to_string(val)+ans;
			carry=0;
		}

	}

	if(carry)
		ans="1"+ans;

	return ans;

}