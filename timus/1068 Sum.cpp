/*


Your task is to find the sum of all integer numbers lying between 1 and N inclusive.


*/

#include <iostream>

using namespace std;

int main(void){
	int n,ans;
	cin>>n; //read in n

	ans=n>0?n*(n+1)/2:1+n*(1-n)/2; //use the sum of an arithmetic series equation to find the sum

	cout<<ans<<endl; //output the sum

	return 0;
}
