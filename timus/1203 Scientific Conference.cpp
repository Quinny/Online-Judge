#include <iostream>
#include <algorithm>

using namespace std;

struct event{
	int start,end;

	bool operator < (event x) const{
		return end<x.end;
	}
}a[100000];



int main(void){
	int n;

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>a[i].start>>a[i].end;
	}

	sort(a,a+n);

	int last=0,ans=0;

	for(int i=0;i<n;i++){
		if(a[i].start>last){
			ans++;
			last=a[i].end;
		}
	}

	cout<<ans<<endl;
}