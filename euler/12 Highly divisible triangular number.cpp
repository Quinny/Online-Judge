#include <iostream>

using namespace std;

int numDivsors(long long);

int main(void){

	int sum=1;
	for(int i=2;numDivsors(sum)<=500;sum+=i,i++);
	cout<<sum<<endl;

	return 0;
}

int numDivsors(long long n){
	int ans=0;
	for(int i=1;i*i<n;i++){
		if(n%i==0) ans+=2;
	}
	return ans;
}
