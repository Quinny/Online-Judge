#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string);

int main(void){
	string s,ans;
	int len=0;
	cin>>s;
	if(isPalindrome(s)){
		cout<<s<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		for(int x=0;x<s.size();x++){
			string tmp=s.substr(i,x);
			if(isPalindrome(tmp) && tmp.size()>len){
				len=tmp.size();
				ans=tmp;
			}
		}
	}
	cout<<ans<<endl;

}

bool isPalindrome(string s){
	string s2;
	for(int i=s.size()-1;i>=0;i--) s2+=s[i];

	return s2==s;;
}