#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	char w[101];
	cin>>w;
	int len=strlen(w);
	
	for(int i=len-1,tmp,off;i>=1;i--){
		off=i?w[i-1]:5;
		tmp=(w[i]-off)%26;
		if(tmp<0)tmp+=26;
		w[i]=tmp+'a';
	}
	
	if((w[0]-=5)<'a')w[0]+=26;
	
	for(int i=0;i<len;i++)
		cout<<w[i];
	cout<<endl;
	return 0;
}