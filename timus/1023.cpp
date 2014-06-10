#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	int k,ans=0;
	cin>>k;
	for(int i=3;i<sqrt(k);i++){
		if(k%i==0){
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<k-1<<endl;
	return 0;
}
