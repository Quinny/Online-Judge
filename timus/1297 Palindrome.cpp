/*

http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html

*/

#include <iostream>
#include <string>

using namespace std;

int main(void){
	string s;
	cin>>s;
	char f=s[0];
	int n=s.size();
	int maxLen=0,start=0;
	bool dp[1001][1001];

	memset(dp,false,sizeof(dp)); //set everything to false

	for(int i=0;i<n;i++){
		dp[i][i]=true; //populate the diagonals with true
	}

	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			dp[i][i+1]=true; //find all of the length 2 palindromes
			if(2>maxLen){ 
				start=i;
				maxLen=2;
			}
		}
	}

	for(int len=3;len<=n;len++){ //start at length 3
		for(int i=0;i<n-len+1;i++){
			int j=len+i-1;
			if(s[i]==s[j] && dp[i+1][j-1]){ //if the characters are the same and the one between them are also the same then it must be a palindrome
				dp[i][j]=true;
				if(len>maxLen){ //length check because the question wanted the first example if there was more than 1
					start=i;
					maxLen=len;
				}
			}
		}
	}

	if(maxLen==0){ //if no palindromes were found return the first character
		cout<<f<<endl;
		return 0;
	}

	cout<<(s.substr(start,maxLen))<<endl;
}