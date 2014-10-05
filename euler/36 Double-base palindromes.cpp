#include <iostream>

#define MAX 1000000

bool isPalindrome(int);
bool isPalindromeBit(int);

int main(void){
	int ans=0;
	for(int i=0;i<MAX;i++){
		if(isPalindrome(i) && isPalindromeBit(i))
			ans+=i;
	}
	std::cout<<ans<<std::endl;
	return 0;
}


bool isPalindromeBit(int n){
	int tmp=n;
	int m=0;
	while(tmp>0){
		m<<=1;
		m = m | (tmp&1);
		tmp>>=1;
	}
	return n==m;
}

bool isPalindrome(int n){
	std::string s=std::to_string(n);
	int len=s.length();
	for(int i=0;i<len/2;i++){
		if(s[i] != s[len-i-1])
			return false;
	}
	return true;
}