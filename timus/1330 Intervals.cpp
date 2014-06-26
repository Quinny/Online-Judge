#include <iostream>

using namespace std;

int main(void){
	int n;
	cin>>n;
	int a[n];
	int sums[n];

	cin>>sums[0];

	for(int i=1,tmp;i<n;i++){
		cin>>tmp;
		sums[i]=tmp+sums[i-1];
	}

	cin>>n;

	for(int i=0,s1,s2;i<n;i++){
		cin>>s1>>s2;
		s1--;s2--;
		if(s1==0) cout<<sums[s2]<<endl;
		else cout<<(sums[s2]-sums[s1-1])<<endl;
	}

	return 0;
}