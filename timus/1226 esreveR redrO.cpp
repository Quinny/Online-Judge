#include <iostream>
#include <cctype>

using namespace std;


string reverse(string,int);

int main(void){
	string tmp="";

	while(cin>>tmp){

		char lastChar=tmp[tmp.size()-1];

		if(!isalnum(lastChar) && lastChar!='"'){
			tmp=reverse(tmp,tmp.size()-2);
		}
		else{
			tmp=reverse(tmp,tmp.size()-1);
		}

		cout<<tmp<<" ";
	}

	return 0;
}


string reverse(string s,int len){
	for(int i=0;i<(len/2)+1;i++){
		swap(s[i],s[len-i]);
	}
	return s;
}
