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
	int tmp=n;
	int ans=0;
	while(tmp>0){
		ans=(ans*10)+(tmp%10);
		tmp/=10;
	}
	return n == ans;
}