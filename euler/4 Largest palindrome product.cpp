#include <iostream>

using namespace std;

bool isPalindrome(int);

int main(void){

	int biggest=0;

	for(int i=999;i>=100;i--){
		for(int j=999;j>=100;j--){
			if(isPalindrome(i*j) && (i*j) > biggest) biggest=i*j;
		}
	}

	cout<<biggest<<endl;

	return 0;
}


bool isPalindrome(int n){
	string s=to_string(n);
	int length=s.length();

	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[length-i-1]) return false;
	}
	return true;

}